begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformservices.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformServices     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformServices provides the backend for desktop-related functionality. */
DECL|function|QPlatformServices
name|QPlatformServices
operator|::
name|QPlatformServices
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|openUrl
name|bool
name|QPlatformServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support QPlatformServices::openUrl() for '%s'."
argument_list|,
name|qPrintable
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QPlatformServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support QPlatformServices::openDocument() for '%s'."
argument_list|,
name|qPrintable
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!  * \brief QPlatformServices::desktopEnvironment returns the active desktop environment.  *  * On Unix this function returns the uppercase desktop environment name, such as  * KDE, GNOME, UNITY, XFCE, LXDE etc. or UNKNOWN if none was detected.  * The primary way to detect the desktop environment is the environment variable  * XDG_CURRENT_DESKTOP.  */
end_comment
begin_function
DECL|function|desktopEnvironment
name|QByteArray
name|QPlatformServices
operator|::
name|desktopEnvironment
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
literal|"UNKNOWN"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
