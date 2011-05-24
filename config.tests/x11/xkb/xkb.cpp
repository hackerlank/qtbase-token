begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/XKBlib.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|Display
modifier|*
name|display
init|=
literal|0
decl_stmt|;
name|int
name|opcode
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|xkbEventBase
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|xkbErrorBase
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|xkblibMajor
init|=
name|XkbMajorVersion
decl_stmt|;
name|int
name|xkblibMinor
init|=
name|XkbMinorVersion
decl_stmt|;
name|XkbQueryExtension
argument_list|(
name|display
argument_list|,
operator|&
name|opcode
argument_list|,
operator|&
name|xkbEventBase
argument_list|,
operator|&
name|xkbErrorBase
argument_list|,
operator|&
name|xkblibMajor
argument_list|,
operator|&
name|xkblibMinor
argument_list|)
expr_stmt|;
name|int
name|keycode
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|state
init|=
literal|0
decl_stmt|;
name|KeySym
name|keySym
decl_stmt|;
name|unsigned
name|int
name|consumedModifiers
decl_stmt|;
name|XkbLookupKeySym
argument_list|(
name|display
argument_list|,
name|keycode
argument_list|,
name|state
argument_list|,
operator|&
name|consumedModifiers
argument_list|,
operator|&
name|keySym
argument_list|)
expr_stmt|;
name|XkbDescPtr
name|xkbDesc
init|=
name|XkbGetMap
argument_list|(
name|display
argument_list|,
name|XkbAllClientInfoMask
argument_list|,
name|XkbUseCoreKbd
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|XkbKeyGroupsWidth
argument_list|(
name|xkbDesc
argument_list|,
name|keycode
argument_list|)
decl_stmt|;
name|keySym
operator|=
name|XkbKeySym
argument_list|(
name|xkbDesc
argument_list|,
name|keycode
argument_list|,
name|w
operator|-
literal|1
argument_list|)
expr_stmt|;
name|XkbFreeClientMap
argument_list|(
name|xkbDesc
argument_list|,
name|XkbAllClientInfoMask
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|state
operator|=
name|XkbPCF_GrabsUseXKBStateMask
expr_stmt|;
operator|(
name|void
operator|)
name|XkbSetPerClientControls
argument_list|(
name|display
argument_list|,
name|state
argument_list|,
operator|&
name|state
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
