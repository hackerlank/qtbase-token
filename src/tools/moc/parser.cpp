begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"parser.h"
end_include
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|USE_LEXEM_STORE
DECL|member|lexemStore
name|Symbol
operator|::
name|LexemStore
name|Symbol
operator|::
name|lexemStore
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|error_msg
specifier|static
specifier|const
name|char
modifier|*
name|error_msg
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_define
DECL|macro|ErrorFormatString
define|#
directive|define
name|ErrorFormatString
value|"%s(%d): "
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ErrorFormatString
define|#
directive|define
name|ErrorFormatString
value|"%s:%d: "
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|error
name|void
name|Parser
operator|::
name|error
parameter_list|(
name|int
name|rollback
parameter_list|)
block|{
name|index
operator|-=
name|rollback
expr_stmt|;
name|error
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|Parser
operator|::
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|msg
operator|||
name|error_msg
condition|)
name|qWarning
argument_list|(
name|ErrorFormatString
literal|"Error: %s"
argument_list|,
name|currentFilenames
operator|.
name|top
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|symbol
argument_list|()
operator|.
name|lineNum
argument_list|,
name|msg
condition|?
name|msg
else|:
name|error_msg
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
name|ErrorFormatString
literal|"Parse error at \"%s\""
argument_list|,
name|currentFilenames
operator|.
name|top
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|symbol
argument_list|()
operator|.
name|lineNum
argument_list|,
name|symbol
argument_list|()
operator|.
name|lexem
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|warning
name|void
name|Parser
operator|::
name|warning
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|displayWarnings
operator|&&
name|msg
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|ErrorFormatString
literal|"Warning: %s\n"
argument_list|,
name|currentFilenames
operator|.
name|top
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|qMax
argument_list|(
literal|0
argument_list|,
name|index
operator|>
literal|0
condition|?
name|symbol
argument_list|()
operator|.
name|lineNum
else|:
literal|0
argument_list|)
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|note
name|void
name|Parser
operator|::
name|note
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|displayNotes
operator|&&
name|msg
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|ErrorFormatString
literal|"Note: %s\n"
argument_list|,
name|currentFilenames
operator|.
name|top
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|qMax
argument_list|(
literal|0
argument_list|,
name|index
operator|>
literal|0
condition|?
name|symbol
argument_list|()
operator|.
name|lineNum
else|:
literal|0
argument_list|)
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
