begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QPlatformIntegrationPlugin>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \group qt-lighthouse-win     \title Qt Lighthouse plugin for Windows      \brief Class documentation of the  Qt Lighthouse plugin for Windows.      \section1 Supported parameters      The following parameters can be passed on to the -platform argument     of QGuiApplication:      \list     \li \c fontengine=native Indicates that native font engine should be used (default)     \li \c fontengine=freetype Indicates that freetype font engine should be used     \li \c gl=gdi Indicates that ARB Open GL functionality should not be used     \endlist      \section1 Tips      \list     \li The environment variable \c QT_LIGHTHOUSE_WINDOWS_VERBOSE controls        the debug level. It takes the form        \c{<keyword1>:<level1>,<keyword2>:<level2>}, where        keyword is one of \c integration, \c windows, \c backingstore and        \c fonts. Level is an integer 0..9.     \endlist  */
end_comment
begin_comment
comment|/*!     \class QWindowsIntegrationPlugin     \brief Plugin.     \ingroup qt-lighthouse-win  */
end_comment
begin_comment
comment|/*!     \namespace QtWindows      \brief Namespace for enumerations, etc.     \ingroup qt-lighthouse-win */
end_comment
begin_comment
comment|/*!     \enum QtWindows::WindowsEventType      \brief Enumerations for WM_XX events.      With flags that should help to structure the code.      \ingroup qt-lighthouse-win */
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
literal|"org.qt-project.Qt.QPlatformIntegrationFactoryInterface"
name|FILE
literal|"windows.json"
argument_list|)
decl|public
range|:
name|QStringList
name|keys
argument_list|()
specifier|const
decl_stmt|;
name|QPlatformIntegration
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|keys
name|QStringList
name|QWindowsIntegrationPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QStringLiteral
argument_list|(
literal|"windows"
argument_list|)
argument_list|)
return|;
block|}
end_function
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
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
if|if
condition|(
name|system
operator|.
name|compare
argument_list|(
name|system
argument_list|,
name|QStringLiteral
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
name|QWindowsIntegration
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
