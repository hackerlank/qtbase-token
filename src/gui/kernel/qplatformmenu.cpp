begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2014 Martin Graesslin<mgraesslin@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformmenu.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|createMenuItem
name|QPlatformMenuItem
modifier|*
name|QPlatformMenu
operator|::
name|createMenuItem
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformMenuItem
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createSubMenu
name|QPlatformMenu
modifier|*
name|QPlatformMenu
operator|::
name|createSubMenu
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformMenu
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
