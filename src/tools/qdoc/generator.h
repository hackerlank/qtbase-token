begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GENERATOR_H
end_ifndef
begin_define
DECL|macro|GENERATOR_H
define|#
directive|define
name|GENERATOR_H
end_define
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|"config.h"
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QString
DECL|typedef|NodeMultiMap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|Node
operator|*
operator|>
name|NodeMultiMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|Node
DECL|typedef|ParentMaps
typedef|typedef
name|QMap
operator|<
name|Node
operator|*
operator|,
name|NodeMultiMap
operator|>
name|ParentMaps
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|Config
name|class
name|Config
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CodeMarker
name|class
name|CodeMarker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Location
name|class
name|Location
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Generator
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::Generator
argument_list|)
name|public
label|:
enum|enum
name|QDocPass
block|{
name|Neither
block|,
name|Prepare
block|,
name|Generate
block|}
enum|;
enum|enum
name|ListType
block|{
name|Generic
block|,
name|Obsolete
block|}
enum|;
name|Generator
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Generator
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|canHandleFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
block|{
return|return
name|format
operator|==
name|this
operator|->
name|format
argument_list|()
return|;
block|}
name|virtual
name|QString
name|format
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|generateDocs
parameter_list|()
function_decl|;
name|virtual
name|void
name|initializeGenerator
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
name|virtual
name|void
name|terminateGenerator
parameter_list|()
function_decl|;
name|QString
name|fullDocumentLocation
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|bool
name|useSubdir
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|Config
modifier|*
name|config
parameter_list|()
block|{
return|return
name|config_
return|;
block|}
specifier|static
name|Generator
modifier|*
name|currentGenerator
parameter_list|()
block|{
return|return
name|currentGenerator_
return|;
block|}
specifier|static
name|Generator
modifier|*
name|generatorForFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
specifier|static
name|void
name|initialize
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|QString
modifier|&
name|outputDir
parameter_list|()
block|{
return|return
name|outDir_
return|;
block|}
specifier|static
specifier|const
name|QString
modifier|&
name|outputSubdir
parameter_list|()
block|{
return|return
name|outSubdir_
return|;
block|}
specifier|static
name|void
name|terminate
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|QStringList
modifier|&
name|outputFileNames
parameter_list|()
block|{
return|return
name|outFileNames_
return|;
block|}
specifier|static
name|void
name|writeOutFileNames
parameter_list|()
function_decl|;
specifier|static
name|void
name|augmentImageDirs
argument_list|(
name|QSet
operator|<
name|QString
operator|>
operator|&
name|moreImageDirs
argument_list|)
decl_stmt|;
specifier|static
name|void
name|debug
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
specifier|static
name|void
name|startDebugging
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
specifier|static
name|void
name|stopDebugging
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
specifier|static
name|bool
name|debugging
parameter_list|()
block|{
return|return
name|debugging_
return|;
block|}
specifier|static
name|bool
name|noLinkErrors
parameter_list|()
block|{
return|return
name|noLinkErrors_
return|;
block|}
specifier|static
name|bool
name|autolinkErrors
parameter_list|()
block|{
return|return
name|autolinkErrors_
return|;
block|}
specifier|static
name|void
name|setQDocPass
parameter_list|(
name|QDocPass
name|t
parameter_list|)
block|{
name|qdocPass_
operator|=
name|t
expr_stmt|;
block|}
specifier|static
name|bool
name|preparing
parameter_list|()
block|{
return|return
operator|(
name|qdocPass_
operator|==
name|Prepare
operator|)
return|;
block|}
specifier|static
name|bool
name|generating
parameter_list|()
block|{
return|return
operator|(
name|qdocPass_
operator|==
name|Generate
operator|)
return|;
block|}
specifier|static
name|bool
name|singleExec
parameter_list|()
block|{
return|return
name|qdocSingleExec_
return|;
block|}
specifier|static
name|bool
name|writeQaPages
parameter_list|()
block|{
return|return
name|qdocWriteQaPages_
return|;
block|}
specifier|static
name|void
name|setSingleExec
parameter_list|()
block|{
name|qdocSingleExec_
operator|=
name|true
expr_stmt|;
block|}
specifier|static
name|void
name|setWriteQaPages
parameter_list|()
block|{
name|qdocWriteQaPages_
operator|=
name|true
expr_stmt|;
block|}
specifier|static
name|QString
name|defaultModuleName
parameter_list|()
block|{
return|return
name|project_
return|;
block|}
specifier|static
name|void
name|resetUseOutputSubdirs
parameter_list|()
block|{
name|useOutputSubdirs_
operator|=
name|false
expr_stmt|;
block|}
specifier|static
name|bool
name|useOutputSubdirs
parameter_list|()
block|{
return|return
name|useOutputSubdirs_
return|;
block|}
name|protected
label|:
name|virtual
name|void
name|beginSubPage
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|virtual
name|void
name|endSubPage
parameter_list|()
function_decl|;
name|virtual
name|QString
name|fileBase
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|fileExtension
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|generateQAPage
parameter_list|()
block|{ }
name|virtual
name|void
name|generateAlsoList
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|int
name|generateAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateBody
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateClassLikeNode
parameter_list|(
name|InnerNode
modifier|*
name|inner
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateQmlTypePage
parameter_list|(
name|QmlClassNode
modifier|*
parameter_list|,
name|CodeMarker
modifier|*
parameter_list|)
block|{ }
name|virtual
name|void
name|generateQmlBasicTypePage
parameter_list|(
name|QmlBasicTypeNode
modifier|*
parameter_list|,
name|CodeMarker
modifier|*
parameter_list|)
block|{ }
name|virtual
name|void
name|generateDocNode
parameter_list|(
name|DocNode
modifier|*
name|dn
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateCollectionNode
parameter_list|(
name|CollectionNode
modifier|*
name|cn
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateInheritedBy
parameter_list|(
specifier|const
name|ClassNode
modifier|*
name|classe
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateInherits
parameter_list|(
specifier|const
name|ClassNode
modifier|*
name|classe
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateInnerNode
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateMaintainerList
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateQmlInheritedBy
parameter_list|(
specifier|const
name|QmlClassNode
modifier|*
name|qcn
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateQmlInherits
parameter_list|(
name|QmlClassNode
modifier|*
name|qcn
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|bool
name|generateQmlText
parameter_list|(
specifier|const
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|,
specifier|const
name|QString
modifier|&
name|qmlName
parameter_list|)
function_decl|;
name|virtual
name|bool
name|generateText
parameter_list|(
specifier|const
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|virtual
name|QString
name|imageFileName
parameter_list|(
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileBase
parameter_list|)
function_decl|;
name|virtual
name|int
name|skipAtoms
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
name|Atom
operator|::
name|Type
name|type
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|typeString
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
specifier|static
name|bool
name|matchAhead
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
name|Atom
operator|::
name|Type
name|expectedAtomType
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|outputPrefix
parameter_list|(
specifier|const
name|QString
modifier|&
name|nodeType
parameter_list|)
function_decl|;
specifier|static
name|void
name|singularPlural
parameter_list|(
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|NodeList
modifier|&
name|nodes
parameter_list|)
function_decl|;
specifier|static
name|void
name|supplementAlsoList
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|QList
operator|<
name|Text
operator|>
operator|&
name|alsoList
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|trimmedTrailing
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
function_decl|;
specifier|static
name|QString
name|sinceTitles
index|[]
decl_stmt|;
name|void
name|initializeTextOutput
parameter_list|()
function_decl|;
name|QString
name|fileName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
operator|&
name|formattingLeftMap
argument_list|()
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
operator|&
name|formattingRightMap
argument_list|()
expr_stmt|;
specifier|const
name|Atom
modifier|*
name|generateAtomList
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|,
name|bool
name|generate
parameter_list|,
name|int
modifier|&
name|numGeneratedAtoms
parameter_list|)
function_decl|;
name|void
name|generateExampleFiles
parameter_list|(
specifier|const
name|DocNode
modifier|*
name|dn
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|void
name|generateFileList
argument_list|(
specifier|const
name|DocNode
operator|*
name|dn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
name|Node
operator|::
name|SubType
name|subtype
argument_list|,
specifier|const
name|QString
operator|&
name|tag
argument_list|)
decl_stmt|;
name|void
name|generateSince
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|void
name|generateStatus
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|void
name|generateThreadSafeness
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|QString
name|getMetadataElement
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|inner
parameter_list|,
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
function_decl|;
name|QStringList
name|getMetadataElements
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|inner
parameter_list|,
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
function_decl|;
name|QString
name|indent
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|QString
modifier|&
name|markedCode
parameter_list|)
function_decl|;
name|QTextStream
modifier|&
name|out
parameter_list|()
function_decl|;
name|QString
name|outFileName
parameter_list|()
function_decl|;
name|bool
name|parseArg
parameter_list|(
specifier|const
name|QString
modifier|&
name|src
parameter_list|,
specifier|const
name|QString
modifier|&
name|tag
parameter_list|,
name|int
modifier|*
name|pos
parameter_list|,
name|int
name|n
parameter_list|,
name|QStringRef
modifier|*
name|contents
parameter_list|,
name|QStringRef
modifier|*
name|par1
init|=
literal|0
parameter_list|,
name|bool
name|debug
init|=
name|false
parameter_list|)
function_decl|;
name|QString
name|plainCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|markedCode
parameter_list|)
function_decl|;
name|void
name|setImageFileExtensions
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|extensions
parameter_list|)
function_decl|;
name|void
name|unknownAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|)
function_decl|;
name|void
name|appendSortedQmlNames
parameter_list|(
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|Node
modifier|*
name|base
parameter_list|,
specifier|const
name|NodeList
modifier|&
name|subs
parameter_list|)
function_decl|;
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|editionGroupMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|editionModuleMap
expr_stmt|;
name|QString
name|naturalLanguage
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|QTextCodec
modifier|*
name|outputCodec
decl_stmt|;
name|QString
name|outputEncoding
decl_stmt|;
endif|#
directive|endif
name|QString
name|tagFile_
decl_stmt|;
name|QStack
operator|<
name|QTextStream
operator|*
operator|>
name|outStreamStack
expr_stmt|;
name|void
name|appendFullName
parameter_list|(
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|Node
modifier|*
name|apparentNode
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
specifier|const
name|Node
modifier|*
name|actualNode
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|appendFullName
parameter_list|(
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|Node
modifier|*
name|apparentNode
parameter_list|,
specifier|const
name|QString
modifier|&
name|fullName
parameter_list|,
specifier|const
name|Node
modifier|*
name|actualNode
parameter_list|)
function_decl|;
name|void
name|appendFullNames
parameter_list|(
name|Text
modifier|&
name|text
parameter_list|,
specifier|const
name|NodeList
modifier|&
name|nodes
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
function_decl|;
name|void
name|appendSortedNames
argument_list|(
name|Text
operator|&
name|text
argument_list|,
specifier|const
name|ClassNode
operator|*
name|classe
argument_list|,
specifier|const
name|QList
operator|<
name|RelatedClass
operator|>
operator|&
name|classes
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|Generator
modifier|*
name|currentGenerator_
decl_stmt|;
specifier|static
name|QStringList
name|exampleDirs
decl_stmt|;
specifier|static
name|QStringList
name|exampleImgExts
decl_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
expr|>
name|fmtLeftMaps
expr_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
expr|>
name|fmtRightMaps
expr_stmt|;
specifier|static
name|QList
operator|<
name|Generator
operator|*
operator|>
name|generators
expr_stmt|;
specifier|static
name|QStringList
name|imageDirs
decl_stmt|;
specifier|static
name|QStringList
name|imageFiles
decl_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|imgFileExts
expr_stmt|;
specifier|static
name|QString
name|project_
decl_stmt|;
specifier|static
name|QString
name|outDir_
decl_stmt|;
specifier|static
name|QString
name|outSubdir_
decl_stmt|;
specifier|static
name|QStringList
name|outFileNames_
decl_stmt|;
specifier|static
name|QSet
operator|<
name|QString
operator|>
name|outputFormats
expr_stmt|;
specifier|static
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|outputPrefixes
expr_stmt|;
specifier|static
name|QStringList
name|scriptDirs
decl_stmt|;
specifier|static
name|QStringList
name|scriptFiles
decl_stmt|;
specifier|static
name|QStringList
name|styleDirs
decl_stmt|;
specifier|static
name|QStringList
name|styleFiles
decl_stmt|;
specifier|static
name|bool
name|debugging_
decl_stmt|;
specifier|static
name|bool
name|noLinkErrors_
decl_stmt|;
specifier|static
name|bool
name|autolinkErrors_
decl_stmt|;
specifier|static
name|bool
name|redirectDocumentationToDevNull_
decl_stmt|;
specifier|static
name|QDocPass
name|qdocPass_
decl_stmt|;
specifier|static
name|bool
name|qdocSingleExec_
decl_stmt|;
specifier|static
name|bool
name|qdocWriteQaPages_
decl_stmt|;
specifier|static
name|bool
name|useOutputSubdirs_
decl_stmt|;
name|void
name|generateReimplementedFrom
parameter_list|(
specifier|const
name|FunctionNode
modifier|*
name|func
parameter_list|,
name|CodeMarker
modifier|*
name|marker
parameter_list|)
function_decl|;
name|QString
name|amp
decl_stmt|;
name|QString
name|gt
decl_stmt|;
name|QString
name|lt
decl_stmt|;
name|QString
name|quot
decl_stmt|;
name|QRegExp
name|tag
decl_stmt|;
name|protected
label|:
specifier|const
name|Config
modifier|*
name|config_
decl_stmt|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|bool
name|inLink_
decl_stmt|;
name|bool
name|inContents_
decl_stmt|;
name|bool
name|inSectionHeading_
decl_stmt|;
name|bool
name|inTableHeader_
decl_stmt|;
name|bool
name|threeColumnEnumValueTable_
decl_stmt|;
name|bool
name|showInternal_
decl_stmt|;
name|bool
name|singleExec_
decl_stmt|;
name|int
name|numTableRows_
decl_stmt|;
name|QString
name|link_
decl_stmt|;
name|QString
name|sectionNumber_
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
