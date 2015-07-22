begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDOCINDEXFILES_H
end_ifndef
begin_define
DECL|macro|QDOCINDEXFILES_H
define|#
directive|define
name|QDOCINDEXFILES_H
end_define
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Atom
name|class
name|Atom
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Generator
name|class
name|Generator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXmlStreamWriter
name|class
name|QXmlStreamWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDocIndexFiles
block|{
name|friend
name|class
name|QDocDatabase
decl_stmt|;
name|private
label|:
specifier|static
name|QDocIndexFiles
modifier|*
name|qdocIndexFiles
parameter_list|()
function_decl|;
specifier|static
name|void
name|destroyQDocIndexFiles
parameter_list|()
function_decl|;
name|QDocIndexFiles
argument_list|()
expr_stmt|;
operator|~
name|QDocIndexFiles
argument_list|()
expr_stmt|;
name|void
name|readIndexes
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|indexFiles
parameter_list|)
function_decl|;
name|void
name|generateIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|url
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|Generator
modifier|*
name|g
parameter_list|,
name|bool
name|generateInternalNodes
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|readIndexFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|readIndexSection
parameter_list|(
name|QXmlStreamReader
modifier|&
name|reader
parameter_list|,
name|Node
modifier|*
name|current
parameter_list|,
specifier|const
name|QString
modifier|&
name|indexUrl
parameter_list|)
function_decl|;
name|void
name|resolveIndex
parameter_list|()
function_decl|;
name|bool
name|generateIndexSection
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|,
name|bool
name|generateInternalNodes
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|generateIndexSections
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|,
name|bool
name|generateInternalNodes
init|=
name|false
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|QDocIndexFiles
modifier|*
name|qdocIndexFiles_
decl_stmt|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|Generator
modifier|*
name|gen_
decl_stmt|;
name|QString
name|project_
decl_stmt|;
name|QVector
operator|<
name|QPair
operator|<
name|ClassNode
operator|*
operator|,
name|QString
operator|>
expr|>
name|basesList_
expr_stmt|;
name|QVector
operator|<
name|QPair
operator|<
name|FunctionNode
operator|*
operator|,
name|QString
operator|>
expr|>
name|relatedList_
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
