begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   openedlist.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OPENEDLIST_H
end_ifndef
begin_define
DECL|macro|OPENEDLIST_H
define|#
directive|define
name|OPENEDLIST_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_include
include|#
directive|include
file|"tr.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|OpenedList
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::OpenedList
argument_list|)
name|public
label|:
enum|enum
name|Style
block|{
name|Bullet
block|,
name|Tag
block|,
name|Value
block|,
name|Numeric
block|,
name|UpperAlpha
block|,
name|LowerAlpha
block|,
name|UpperRoman
block|,
name|LowerRoman
block|}
enum|;
name|OpenedList
argument_list|()
operator|:
name|sty
argument_list|(
name|Bullet
argument_list|)
operator|,
name|ini
argument_list|(
literal|1
argument_list|)
operator|,
name|nex
argument_list|(
literal|0
argument_list|)
block|{ }
name|OpenedList
argument_list|(
argument|Style style
argument_list|)
expr_stmt|;
name|OpenedList
argument_list|(
specifier|const
name|Location
operator|&
name|location
argument_list|,
specifier|const
name|QString
operator|&
name|hint
argument_list|)
expr_stmt|;
name|void
name|next
parameter_list|()
block|{
name|nex
operator|++
expr_stmt|;
block|}
name|bool
name|isStarted
argument_list|()
specifier|const
block|{
return|return
name|nex
operator|>=
name|ini
return|;
block|}
name|Style
name|style
argument_list|()
specifier|const
block|{
return|return
name|sty
return|;
block|}
name|QString
name|styleString
argument_list|()
specifier|const
expr_stmt|;
name|int
name|number
argument_list|()
specifier|const
block|{
return|return
name|nex
return|;
block|}
name|QString
name|numberString
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|prefix
argument_list|()
specifier|const
block|{
return|return
name|pref
return|;
block|}
name|QString
name|suffix
argument_list|()
specifier|const
block|{
return|return
name|suff
return|;
block|}
name|private
label|:
specifier|static
name|QString
name|toAlpha
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
specifier|static
name|int
name|fromAlpha
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
specifier|static
name|QString
name|toRoman
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
specifier|static
name|int
name|fromRoman
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|Style
name|sty
decl_stmt|;
name|int
name|ini
decl_stmt|;
name|int
name|nex
decl_stmt|;
name|QString
name|pref
decl_stmt|;
name|QString
name|suff
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
