begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   quoter.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUOTER_H
end_ifndef
begin_define
DECL|macro|QUOTER_H
define|#
directive|define
name|QUOTER_H
end_define
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Quoter
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::Quoter
argument_list|)
name|public
label|:
name|Quoter
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|quoteFromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|userFriendlyFileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|plainCode
parameter_list|,
specifier|const
name|QString
modifier|&
name|markedCode
parameter_list|)
function_decl|;
name|QString
name|quoteLine
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|command
parameter_list|,
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|QString
name|quoteTo
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|command
parameter_list|,
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|QString
name|quoteUntil
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|command
parameter_list|,
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|QString
name|quoteSnippet
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|identifier
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|splitLines
parameter_list|(
specifier|const
name|QString
modifier|&
name|line
parameter_list|)
function_decl|;
name|private
label|:
name|QString
name|getLine
parameter_list|(
name|int
name|unindent
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|failedAtEnd
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|command
parameter_list|)
function_decl|;
name|bool
name|match
parameter_list|(
specifier|const
name|Location
modifier|&
name|docLocation
parameter_list|,
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|,
specifier|const
name|QString
modifier|&
name|line
parameter_list|)
function_decl|;
name|QString
name|commentForCode
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|removeSpecialLines
parameter_list|(
specifier|const
name|QString
modifier|&
name|line
parameter_list|,
specifier|const
name|QString
modifier|&
name|comment
parameter_list|,
name|int
name|unindent
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|silent
decl_stmt|;
name|bool
name|validRegExp
decl_stmt|;
name|QStringList
name|plainLines
decl_stmt|;
name|QStringList
name|markedLines
decl_stmt|;
name|Location
name|codeLocation
decl_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|commentHash
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
