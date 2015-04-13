begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDOCTAGFILES_H
end_ifndef
begin_define
DECL|macro|QDOCTAGFILES_H
define|#
directive|define
name|QDOCTAGFILES_H
end_define
begin_include
include|#
directive|include
file|"qxmlstream.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Aggregate
name|class
name|Aggregate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
begin_decl_stmt
name|class
name|QDocTagFiles
block|{
name|friend
name|class
name|QDocDatabase
decl_stmt|;
name|private
label|:
specifier|static
name|QDocTagFiles
modifier|*
name|qdocTagFiles
parameter_list|()
function_decl|;
specifier|static
name|void
name|destroyQDocTagFiles
parameter_list|()
function_decl|;
name|QDocTagFiles
argument_list|()
expr_stmt|;
operator|~
name|QDocTagFiles
argument_list|()
expr_stmt|;
name|void
name|generateTagFileCompounds
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Aggregate
modifier|*
name|inner
parameter_list|)
function_decl|;
name|void
name|generateTagFileMembers
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Aggregate
modifier|*
name|inner
parameter_list|)
function_decl|;
name|void
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
function_decl|;
name|private
label|:
specifier|static
name|QDocTagFiles
modifier|*
name|qdocTagFiles_
decl_stmt|;
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|Generator
modifier|*
name|gen_
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
