begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformintegration_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformFontDatabase>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformClipboard>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|grabWindow
name|QPixmap
name|QPlatformIntegration
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|height
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Factory function for the eventloop integration interface.      Default implementation returns 0, which causes the eventloop to run in a single thread mode.      \sa QPlatformEventLoopIntegration */
end_comment
begin_function
DECL|function|createEventLoopIntegration
name|QPlatformEventLoopIntegration
modifier|*
name|QPlatformIntegration
operator|::
name|createEventLoopIntegration
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Accessor for the platform integrations fontdatabase.      Default implementation returns a default QPlatformFontDatabase.      \sa QPlatformFontDatabase */
end_comment
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QPlatformIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
specifier|static
name|QPlatformFontDatabase
modifier|*
name|db
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|db
condition|)
block|{
name|db
operator|=
operator|new
name|QPlatformFontDatabase
expr_stmt|;
block|}
return|return
name|db
return|;
block|}
end_function
begin_comment
comment|/*!     Accessor for the platform integrations clipboard.      Default implementation returns a default QPlatformClipboard.      \sa QPlatformClipboard  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QPlatformIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
specifier|static
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|clipboard
condition|)
block|{
name|clipboard
operator|=
operator|new
name|QPlatformClipboard
expr_stmt|;
block|}
return|return
name|clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QPlatformIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformIntegration     \since 4.8     \internal     \preliminary     \ingroup qpa     \brief The QPlatformIntegration class is the entry for WindowSystem specific functionality.      QPlatformIntegration is the single entry point for windowsystem specific functionality when     using the QPA platform. It has factory functions for creating platform specific pixmaps and     windows. The class also controls the font subsystem.      QPlatformIntegration is a singelton class which gets instansiated in the QApplication     constructor. The QPlatformIntegration instance do not have ownership of objects it creates in     functions where the name starts with create. However, functions which don't have a name     starting with create acts as assessors to member variables.      It is not trivial to create or build a platform plugin outside of the Qt source tree. Therefor     the recommended approach for making new platform plugin is to copy an existing plugin inside     the QTSRCTREE/src/plugins/platform and develop the plugin inside the source tree.      The minimal platformintegration is the smallest platform integration it is possible to make,     which makes it an ideal starting point for new plugins. For a slightly more advanced plugin,     consider reviewing the directfb plugin, or the testlite plugin. */
end_comment
begin_comment
comment|/*!     \fn QPixmapData *createPixmapData(QPixmapData::PixelType type) const      Factory function for QPixmapData. PixelType can be either PixmapType or BitmapType.     \sa QPixmapData */
end_comment
begin_comment
comment|/*!     \fn QPlatformWindow *createPlatformWindow(QWidget *widget, WId winId = 0) const      Factory function for QPlatformWindow. The widget parameter is a pointer to the top level     widget(tlw) which the QPlatformWindow is suppose to be created for. The WId handle is actually     never used, but there for future reference. Its purpose is if it is going to be possible to     create QPlatformWindows on existing WId.      All tlw has to have a QPlatformWindow, and it will be created when the QPlatformWindow is set     to be visible for the first time. If the tlw's window flags are changed, or if the tlw's     QPlatformWindowFormat is changed, then the tlw's QPlatformWindow is deleted and a new one is     created.      \sa QPlatformWindow, QPlatformWindowFormat     \sa createWindowSurface(QWidget *widget, WId winId) const */
end_comment
begin_comment
comment|/*!     \fn QWindowSurface *createWindowSurface(QWidget *widget, WId winId) const      Factory function for QWindowSurface. The QWidget parameter is a pointer to the     top level widget(tlw) the window surface is created for. A QPlatformWindow is always created     before the QWindowSurface for tlw where the widget also requires a WindowSurface. It is     possible to create top level QWidgets without a QWindowSurface by specifying     QPlatformWindowFormat::setWindowSurface(false) for the tlw QPlatformWindowFormat.      \sa QWindowSurface     \sa createPlatformWindow(QWidget *widget, WId winId = 0) const */
end_comment
begin_comment
comment|/*!     \fn void moveToScreen(QWidget *window, int screen)      This function is called when a QWidget is displayed on screen, or the QWidget is to be     displayed on a new screen. The QWidget parameter is a pointer to the top level widget and     the int parameter is the index to the screen in QList<QPlatformScreen *> screens() const.      Default implementation does nothing.      \sa screens() const */
end_comment
begin_comment
comment|/*!     \fn QList<QPlatformScreen *> screens() const      Accessor function to a list of all the screens on the current system. The screen with the     index == 0 is the default/main screen. */
end_comment
begin_comment
comment|/*!     \fn bool isVirtualDesktop()      Returns if the current windowing system configuration defines all the screens to be one     desktop(virtual desktop), or if each screen is a desktop of its own.      Default implementation returns false. */
end_comment
begin_comment
comment|/*!     \fn QPixmap grabWindow(WId window, int x, int y, int width, int height) const      This function is called when Qt needs to be able to grab the content of a window.      Returnes the content of the window specified with the WId handle within the boundaries of     QRect(x,y,width,height). */
end_comment
begin_function
DECL|function|hasCapability
name|bool
name|QPlatformIntegration
operator|::
name|hasCapability
parameter_list|(
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
