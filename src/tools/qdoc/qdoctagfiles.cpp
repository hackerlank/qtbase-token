begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"qdoctagfiles.h"
end_include
begin_include
include|#
directive|include
file|"qdocdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qdom.h"
end_include
begin_include
include|#
directive|include
file|"atom.h"
end_include
begin_include
include|#
directive|include
file|"doc.h"
end_include
begin_include
include|#
directive|include
file|"htmlgenerator.h"
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QDocTagFiles    This class handles the generation of the qdoc tag file.  */
DECL|member|qdocTagFiles_
name|QDocTagFiles
modifier|*
name|QDocTagFiles
operator|::
name|qdocTagFiles_
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   Constructs the singleton. \a qdb is the pointer to the   qdoc database that is used when reading and writing the   index files.  */
end_comment
begin_constructor
DECL|function|QDocTagFiles
name|QDocTagFiles
operator|::
name|QDocTagFiles
parameter_list|()
block|{
name|qdb_
operator|=
name|QDocDatabase
operator|::
name|qdocDB
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys the singleton QDocTagFiles.  */
end_comment
begin_destructor
DECL|function|~QDocTagFiles
name|QDocTagFiles
operator|::
name|~
name|QDocTagFiles
parameter_list|()
block|{
name|qdb_
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Creates the singleton. Allows only one instance of the class   to be created. Returns a pointer to the singleton.  */
end_comment
begin_function
DECL|function|qdocTagFiles
name|QDocTagFiles
modifier|*
name|QDocTagFiles
operator|::
name|qdocTagFiles
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qdocTagFiles_
condition|)
name|qdocTagFiles_
operator|=
operator|new
name|QDocTagFiles
expr_stmt|;
return|return
name|qdocTagFiles_
return|;
block|}
end_function
begin_comment
comment|/*!   Destroys the singleton.  */
end_comment
begin_function
DECL|function|destroyQDocTagFiles
name|void
name|QDocTagFiles
operator|::
name|destroyQDocTagFiles
parameter_list|()
block|{
if|if
condition|(
name|qdocTagFiles_
condition|)
block|{
operator|delete
name|qdocTagFiles_
expr_stmt|;
name|qdocTagFiles_
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Generate the tag file section with the given \a writer for the \a node   specified, returning true if an element was written; otherwise returns   false.  */
end_comment
begin_function
DECL|function|generateTagFileCompounds
name|void
name|QDocTagFiles
operator|::
name|generateTagFileCompounds
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|InnerNode
modifier|*
name|inner
parameter_list|)
block|{
foreach|foreach
control|(
specifier|const
name|Node
modifier|*
name|node
decl|,
name|inner
operator|->
name|childNodes
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|node
operator|->
name|url
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QString
name|kind
decl_stmt|;
switch|switch
condition|(
name|node
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Namespace
case|:
name|kind
operator|=
literal|"namespace"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Class
case|:
name|kind
operator|=
literal|"class"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Enum
case|:
case|case
name|Node
operator|::
name|Typedef
case|:
case|case
name|Node
operator|::
name|Property
case|:
case|case
name|Node
operator|::
name|Function
case|:
case|case
name|Node
operator|::
name|Variable
case|:
default|default:
continue|continue;
block|}
name|QString
name|access
decl_stmt|;
switch|switch
condition|(
name|node
operator|->
name|access
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Public
case|:
name|access
operator|=
literal|"public"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Protected
case|:
name|access
operator|=
literal|"protected"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Private
case|:
default|default:
continue|continue;
block|}
name|QString
name|objName
init|=
name|node
operator|->
name|name
argument_list|()
decl_stmt|;
comment|// Special case: only the root node should have an empty name.
if|if
condition|(
name|objName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|node
operator|!=
name|qdb_
operator|->
name|treeRoot
argument_list|()
condition|)
continue|continue;
comment|// *** Write the starting tag for the element here. ***
name|writer
operator|.
name|writeStartElement
argument_list|(
literal|"compound"
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"kind"
argument_list|,
name|kind
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|Class
condition|)
block|{
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|node
operator|->
name|fullDocumentName
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"filename"
argument_list|,
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|,
name|Generator
operator|::
name|useOutputSubdirs
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Classes contain information about their base classes.
specifier|const
name|ClassNode
modifier|*
name|classNode
init|=
cast|static_cast
argument_list|<
specifier|const
name|ClassNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|RelatedClass
argument_list|>
name|bases
init|=
name|classNode
operator|->
name|baseClasses
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|RelatedClass
modifier|&
name|related
decl|,
name|bases
control|)
block|{
name|ClassNode
modifier|*
name|n
init|=
name|related
operator|.
name|node_
decl_stmt|;
if|if
condition|(
name|n
condition|)
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"base"
argument_list|,
name|n
operator|->
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Recurse to write all members.
name|generateTagFileMembers
argument_list|(
name|writer
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|InnerNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// Recurse to write all compounds.
name|generateTagFileCompounds
argument_list|(
name|writer
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|InnerNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|node
operator|->
name|fullDocumentName
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"filename"
argument_list|,
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|,
name|Generator
operator|::
name|useOutputSubdirs
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Recurse to write all members.
name|generateTagFileMembers
argument_list|(
name|writer
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|InnerNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// Recurse to write all compounds.
name|generateTagFileCompounds
argument_list|(
name|writer
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|InnerNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!   Writes all the members of the \a inner node with the \a writer.   The node represents a C++ class, namespace, etc.  */
end_comment
begin_function
DECL|function|generateTagFileMembers
name|void
name|QDocTagFiles
operator|::
name|generateTagFileMembers
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|InnerNode
modifier|*
name|inner
parameter_list|)
block|{
foreach|foreach
control|(
specifier|const
name|Node
modifier|*
name|node
decl|,
name|inner
operator|->
name|childNodes
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|node
operator|->
name|url
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QString
name|nodeName
decl_stmt|;
name|QString
name|kind
decl_stmt|;
switch|switch
condition|(
name|node
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Enum
case|:
name|nodeName
operator|=
literal|"member"
expr_stmt|;
name|kind
operator|=
literal|"enum"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Typedef
case|:
name|nodeName
operator|=
literal|"member"
expr_stmt|;
name|kind
operator|=
literal|"typedef"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Property
case|:
name|nodeName
operator|=
literal|"member"
expr_stmt|;
name|kind
operator|=
literal|"property"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Function
case|:
name|nodeName
operator|=
literal|"member"
expr_stmt|;
name|kind
operator|=
literal|"function"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Namespace
case|:
name|nodeName
operator|=
literal|"namespace"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Class
case|:
name|nodeName
operator|=
literal|"class"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Variable
case|:
default|default:
continue|continue;
block|}
name|QString
name|access
decl_stmt|;
switch|switch
condition|(
name|node
operator|->
name|access
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Public
case|:
name|access
operator|=
literal|"public"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Protected
case|:
name|access
operator|=
literal|"protected"
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Private
case|:
default|default:
continue|continue;
block|}
name|QString
name|objName
init|=
name|node
operator|->
name|name
argument_list|()
decl_stmt|;
comment|// Special case: only the root node should have an empty name.
if|if
condition|(
name|objName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|node
operator|!=
name|qdb_
operator|->
name|treeRoot
argument_list|()
condition|)
continue|continue;
comment|// *** Write the starting tag for the element here. ***
name|writer
operator|.
name|writeStartElement
argument_list|(
name|nodeName
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|kind
operator|.
name|isEmpty
argument_list|()
condition|)
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"kind"
argument_list|,
name|kind
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|node
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|Node
operator|::
name|Class
case|:
name|writer
operator|.
name|writeCharacters
argument_list|(
name|node
operator|->
name|fullDocumentName
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Namespace
case|:
name|writer
operator|.
name|writeCharacters
argument_list|(
name|node
operator|->
name|fullDocumentName
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
break|break;
case|case
name|Node
operator|::
name|Function
case|:
block|{
comment|/*                   Function nodes contain information about                   the type of function being described.                 */
specifier|const
name|FunctionNode
modifier|*
name|functionNode
init|=
cast|static_cast
argument_list|<
specifier|const
name|FunctionNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"protection"
argument_list|,
name|access
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|functionNode
operator|->
name|virtualness
argument_list|()
condition|)
block|{
case|case
name|FunctionNode
operator|::
name|NonVirtual
case|:
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"virtualness"
argument_list|,
literal|"non"
argument_list|)
expr_stmt|;
break|break;
case|case
name|FunctionNode
operator|::
name|ImpureVirtual
case|:
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"virtualness"
argument_list|,
literal|"virtual"
argument_list|)
expr_stmt|;
break|break;
case|case
name|FunctionNode
operator|::
name|PureVirtual
case|:
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"virtual"
argument_list|,
literal|"pure"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"static"
argument_list|,
name|functionNode
operator|->
name|isStatic
argument_list|()
condition|?
literal|"yes"
else|:
literal|"no"
argument_list|)
expr_stmt|;
if|if
condition|(
name|functionNode
operator|->
name|virtualness
argument_list|()
operator|==
name|FunctionNode
operator|::
name|NonVirtual
condition|)
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"type"
argument_list|,
name|functionNode
operator|->
name|returnType
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"type"
argument_list|,
literal|"virtual "
operator|+
name|functionNode
operator|->
name|returnType
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|objName
argument_list|)
expr_stmt|;
name|QStringList
name|pieces
init|=
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|,
name|Generator
operator|::
name|useOutputSubdirs
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchorfile"
argument_list|,
name|pieces
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchor"
argument_list|,
name|pieces
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|QString
name|signature
init|=
name|functionNode
operator|->
name|signature
argument_list|()
decl_stmt|;
name|signature
operator|=
name|signature
operator|.
name|mid
argument_list|(
name|signature
operator|.
name|indexOf
argument_list|(
name|QChar
argument_list|(
literal|'('
argument_list|)
argument_list|)
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
if|if
condition|(
name|functionNode
operator|->
name|isConst
argument_list|()
condition|)
name|signature
operator|+=
literal|" const"
expr_stmt|;
if|if
condition|(
name|functionNode
operator|->
name|virtualness
argument_list|()
operator|==
name|FunctionNode
operator|::
name|PureVirtual
condition|)
name|signature
operator|+=
literal|" = 0"
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"arglist"
argument_list|,
name|signature
argument_list|)
expr_stmt|;
block|}
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// member
break|break;
case|case
name|Node
operator|::
name|Property
case|:
block|{
specifier|const
name|PropertyNode
modifier|*
name|propertyNode
init|=
cast|static_cast
argument_list|<
specifier|const
name|PropertyNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"type"
argument_list|,
name|propertyNode
operator|->
name|dataType
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|objName
argument_list|)
expr_stmt|;
name|QStringList
name|pieces
init|=
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|,
name|Generator
operator|::
name|useOutputSubdirs
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchorfile"
argument_list|,
name|pieces
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchor"
argument_list|,
name|pieces
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"arglist"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// member
break|break;
case|case
name|Node
operator|::
name|Enum
case|:
block|{
specifier|const
name|EnumNode
modifier|*
name|enumNode
init|=
cast|static_cast
argument_list|<
specifier|const
name|EnumNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|objName
argument_list|)
expr_stmt|;
name|QStringList
name|pieces
init|=
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchor"
argument_list|,
name|pieces
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"arglist"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// member
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|enumNode
operator|->
name|items
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|EnumItem
name|item
init|=
name|enumNode
operator|->
name|items
argument_list|()
operator|.
name|value
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeStartElement
argument_list|(
literal|"member"
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"name"
argument_list|,
name|item
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchor"
argument_list|,
name|pieces
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"arglist"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// member
block|}
block|}
break|break;
case|case
name|Node
operator|::
name|Typedef
case|:
block|{
specifier|const
name|TypedefNode
modifier|*
name|typedefNode
init|=
cast|static_cast
argument_list|<
specifier|const
name|TypedefNode
operator|*
argument_list|>
argument_list|(
name|node
argument_list|)
decl_stmt|;
if|if
condition|(
name|typedefNode
operator|->
name|associatedEnum
argument_list|()
condition|)
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"type"
argument_list|,
name|typedefNode
operator|->
name|associatedEnum
argument_list|()
operator|->
name|fullDocumentName
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|writer
operator|.
name|writeAttribute
argument_list|(
literal|"type"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"name"
argument_list|,
name|objName
argument_list|)
expr_stmt|;
name|QStringList
name|pieces
init|=
name|gen_
operator|->
name|fullDocumentLocation
argument_list|(
name|node
argument_list|,
name|Generator
operator|::
name|useOutputSubdirs
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
argument_list|)
decl_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchorfile"
argument_list|,
name|pieces
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"anchor"
argument_list|,
name|pieces
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeTextElement
argument_list|(
literal|"arglist"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// member
break|break;
case|case
name|Node
operator|::
name|Variable
case|:
default|default:
break|break;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!   Writes a tag file named \a fileName.  */
end_comment
begin_function
DECL|function|generateTagFile
name|void
name|QDocTagFiles
operator|::
name|generateTagFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|Generator
modifier|*
name|g
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
return|return ;
name|gen_
operator|=
name|g
expr_stmt|;
name|QXmlStreamWriter
name|writer
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|writer
operator|.
name|setAutoFormatting
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeStartDocument
argument_list|()
expr_stmt|;
name|writer
operator|.
name|writeStartElement
argument_list|(
literal|"tagfile"
argument_list|)
expr_stmt|;
name|generateTagFileCompounds
argument_list|(
name|writer
argument_list|,
name|qdb_
operator|->
name|treeRoot
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|writeEndElement
argument_list|()
expr_stmt|;
comment|// tagfile
name|writer
operator|.
name|writeEndDocument
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
