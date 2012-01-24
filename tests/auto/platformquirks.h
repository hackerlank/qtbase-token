begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PLATFORMQUIRKS_H
end_ifndef
begin_define
DECL|macro|PLATFORMQUIRKS_H
define|#
directive|define
name|PLATFORMQUIRKS_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|PlatformQuirks
struct|struct
name|PlatformQuirks
block|{
comment|/* Some windowing systems automatically maximize apps on startup (e.g. Maemo)        "Normal" fixed-sized windows do not work, the WM ignores their size settings.     */
DECL|function|isAutoMaximizing
specifier|static
specifier|inline
name|bool
name|isAutoMaximizing
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
return|return
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_MEEGO_COMPOSITOR
return|;
else|#
directive|else
return|return
name|false
return|;
endif|#
directive|endif
block|}
DECL|function|haveMouseCursor
specifier|static
specifier|inline
name|bool
name|haveMouseCursor
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
return|return
name|X11
operator|->
name|desktopEnvironment
operator|!=
name|DE_MEEGO_COMPOSITOR
return|;
else|#
directive|else
return|return
name|true
return|;
endif|#
directive|endif
block|}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
end_unit
