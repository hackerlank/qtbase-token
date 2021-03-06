begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|"qwindowsgdiintegration.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \group qt-lighthouse-win     \title Qt Lighthouse plugin for Windows      \brief Class documentation of the  Qt Lighthouse plugin for Windows.      \section1 Supported Parameters      The following parameters can be passed on to the -platform argument     of QGuiApplication:      \list     \li \c fontengine=native Indicates that native font engine should be used (default)     \li \c fontengine=freetype Indicates that freetype font engine should be used     \li \c gl=gdi Indicates that ARB Open GL functionality should not be used     \endlist      \section1 Tips      \list     \li The environment variable \c QT_QPA_VERBOSE controls        the debug level. It takes the form        \c{<keyword1>:<level1>,<keyword2>:<level2>}, where        keyword is one of \c integration, \c windows, \c backingstore and        \c fonts. Level is an integer 0..9.     \endlist     \internal  */
end_comment
begin_comment
comment|/*!     \class QWindowsIntegrationPlugin     \brief Plugin.     \internal     \ingroup qt-lighthouse-win  */
end_comment
begin_comment
comment|/*!     \namespace QtWindows      \brief Namespace for enumerations, etc.     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_comment
comment|/*!     \enum QtWindows::WindowsEventType      \brief Enumerations for WM_XX events.      With flags that should help to structure the code.      \internal     \ingroup qt-lighthouse-win */
end_comment
begin_class
DECL|class|QWindowsIntegrationPlugin
class|class
name|QWindowsIntegrationPlugin
super|:
specifier|public
name|QPlatformIntegrationPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
name|QPlatformIntegrationFactoryInterface_iid
name|FILE
literal|"windows.json"
argument_list|)
decl|public
range|:
name|QPlatformIntegration
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|,
name|int
operator|&
argument_list|,
name|char
operator|*
operator|*
argument_list|)
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QWindowsIntegrationPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|system
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|,
name|int
modifier|&
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|system
operator|.
name|compare
argument_list|(
name|system
argument_list|,
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|new
name|QWindowsGdiIntegration
argument_list|(
name|paramList
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
