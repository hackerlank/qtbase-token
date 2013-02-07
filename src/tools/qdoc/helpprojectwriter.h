begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HELPPROJECTWRITER_H
end_ifndef
begin_define
DECL|macro|HELPPROJECTWRITER_H
define|#
directive|define
name|HELPPROJECTWRITER_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qxmlstream.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Generator
name|class
name|Generator
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringNodePair
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
specifier|const
name|Node
operator|*
operator|>
name|QStringNodePair
expr_stmt|;
end_typedef
begin_struct
DECL|struct|SubProject
struct|struct
name|SubProject
block|{
DECL|member|title
name|QString
name|title
decl_stmt|;
DECL|member|indexTitle
name|QString
name|indexTitle
decl_stmt|;
DECL|member|Type
DECL|member|selectors
name|QHash
operator|<
name|Node
operator|::
name|Type
operator|,
name|QSet
operator|<
name|DocNode
operator|::
name|SubType
operator|>
expr|>
name|selectors
expr_stmt|;
DECL|member|sortPages
name|bool
name|sortPages
decl_stmt|;
DECL|member|type
name|QString
name|type
decl_stmt|;
DECL|member|QString
DECL|member|nodes
name|QHash
operator|<
name|QString
operator|,
specifier|const
name|Node
operator|*
operator|>
name|nodes
expr_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|HelpProject
struct|struct
name|HelpProject
block|{
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|helpNamespace
name|QString
name|helpNamespace
decl_stmt|;
DECL|member|virtualFolder
name|QString
name|virtualFolder
decl_stmt|;
DECL|member|fileName
name|QString
name|fileName
decl_stmt|;
DECL|member|indexRoot
name|QString
name|indexRoot
decl_stmt|;
DECL|member|indexTitle
name|QString
name|indexTitle
decl_stmt|;
DECL|member|keywords
name|QList
operator|<
name|QStringList
operator|>
name|keywords
expr_stmt|;
DECL|member|files
name|QSet
operator|<
name|QString
operator|>
name|files
expr_stmt|;
DECL|member|extraFiles
name|QSet
operator|<
name|QString
operator|>
name|extraFiles
expr_stmt|;
DECL|member|filterAttributes
name|QSet
operator|<
name|QString
operator|>
name|filterAttributes
expr_stmt|;
DECL|member|QString
DECL|member|customFilters
name|QHash
operator|<
name|QString
operator|,
name|QSet
operator|<
name|QString
operator|>
expr|>
name|customFilters
expr_stmt|;
DECL|member|excluded
name|QSet
operator|<
name|QString
operator|>
name|excluded
expr_stmt|;
DECL|member|QString
DECL|member|subprojects
name|QMap
operator|<
name|QString
operator|,
name|SubProject
operator|>
name|subprojects
expr_stmt|;
DECL|member|Node
DECL|member|memberStatus
name|QHash
operator|<
specifier|const
name|Node
operator|*
operator|,
name|QSet
operator|<
name|Node
operator|::
name|Status
operator|>
expr|>
name|memberStatus
expr_stmt|;
DECL|member|includeIndexNodes
name|bool
name|includeIndexNodes
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|HelpProjectWriter
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::HelpProjectWriter
argument_list|)
name|public
label|:
name|HelpProjectWriter
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|,
specifier|const
name|QString
operator|&
name|defaultFileName
argument_list|,
name|Generator
operator|*
name|g
argument_list|)
expr_stmt|;
name|void
name|addExtraFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|addExtraFiles
argument_list|(
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|files
argument_list|)
decl_stmt|;
name|void
name|generate
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|generateProject
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|)
function_decl|;
name|void
name|generateSections
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|bool
name|generateSection
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|QStringList
name|keywordDetails
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeHashFile
parameter_list|(
name|QFile
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|writeNode
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|readSelectors
parameter_list|(
name|SubProject
modifier|&
name|subproject
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|selectors
parameter_list|)
function_decl|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|Generator
modifier|*
name|gen_
decl_stmt|;
name|QString
name|outputDir
decl_stmt|;
name|QList
operator|<
name|HelpProject
operator|>
name|projects
expr_stmt|;
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
