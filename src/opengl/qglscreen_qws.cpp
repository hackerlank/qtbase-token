begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGLScreen>
end_include
begin_include
include|#
directive|include
file|<QGLContext>
end_include
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_include
include|#
directive|include
file|"private/qglwindowsurface_qws_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGLScreenPrivate
class|class
name|QGLScreenPrivate
block|{
public|public:
DECL|member|options
name|QGLScreen
operator|::
name|Options
name|options
decl_stmt|;
DECL|member|functions
name|QGLScreenSurfaceFunctions
modifier|*
name|functions
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!   \internal   \preliminary   \class QGLScreen    \brief This class encapsulates an OpenGL screen driver. */
end_comment
begin_constructor
DECL|function|QGLScreen
name|QGLScreen
operator|::
name|QGLScreen
parameter_list|(
name|int
name|displayId
parameter_list|)
member_init_list|:
name|QScreen
argument_list|(
name|displayId
argument_list|,
name|GLClass
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QGLScreenPrivate
argument_list|)
block|{
name|d_ptr
operator|->
name|options
operator|=
name|NoOptions
expr_stmt|;
name|d_ptr
operator|->
name|functions
operator|=
operator|new
name|QGLScreenSurfaceFunctions
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGLScreen
name|QGLScreen
operator|::
name|~
name|QGLScreen
parameter_list|()
block|{
operator|delete
name|d_ptr
operator|->
name|functions
expr_stmt|;
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \since 4.3     \obsolete      Initializes the \a context and sets up the QGLWindowSurface of the     QWidget of \a context based on the parameters of \a context and     based on its own requirements.  The format() of \a context needs     to be updated with the actual parameters of the OpenGLES drawable     that was set up.      \a shareContext is used in the same way as for QGLContext. It is     the context with which \a context shares display lists and texture     ids etc. The window surface must be set up so that this sharing     works.      Returns true in case of success and false if it is not possible to     create the necessary OpenGLES drawable/context.      Since 4.4.2, this function will be not be called if options()     indicates that a native window or pixmap drawable can be created     via the functions in the surfaceFunctions() object.      This function is obsolete in Qt 4.5 and higher.  Use surfaceFunctions()     instead.      \sa options(), surfaceFunctions() */
end_comment
begin_function
name|bool
DECL|function|chooseContext
name|QGLScreen
operator|::
name|chooseContext
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|shareContext
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QGLScreen::Option     This enum defines options that can be set on QGLScreen instances.      \value NoOptions There are no special options on the screen.  This is the default.     \value NativeWindows Native windows can be created with QGLScreenSurfaceFunctions::createNativeWindow().     \value NativePixmaps Native pixmaps can be created with QGLScreenSurfaceFunctions::createNativePixmap().     \value NativeImages Native images can be created with QGLScreenSurfaceFunctions::createNativeImage().     \value Overlays The screen supports GL overlays. */
end_comment
begin_comment
comment|/*!     \since 4.4.2      Returns the options associated with this QGLScreen.      \sa setOptions() */
end_comment
begin_function
DECL|function|options
name|QGLScreen
operator|::
name|Options
name|QGLScreen
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|options
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4.2      Sets the options associated with this QGLScreen to \a value.      \sa options() */
end_comment
begin_function
DECL|function|setOptions
name|void
name|QGLScreen
operator|::
name|setOptions
parameter_list|(
name|QGLScreen
operator|::
name|Options
name|value
parameter_list|)
block|{
name|d_ptr
operator|->
name|options
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4.2      Returns the surface functions object for this QGLScreen.      \sa setSurfaceFunctions() */
end_comment
begin_function
DECL|function|surfaceFunctions
name|QGLScreenSurfaceFunctions
modifier|*
name|QGLScreen
operator|::
name|surfaceFunctions
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|functions
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4.2      Sets the surface functions object for this QGLScreen to \a functions.     The QGLScreen will take over ownership of \a functions and delete     it when the QGLScreen is deleted.      \sa setSurfaceFunctions() */
end_comment
begin_function
DECL|function|setSurfaceFunctions
name|void
name|QGLScreen
operator|::
name|setSurfaceFunctions
parameter_list|(
name|QGLScreenSurfaceFunctions
modifier|*
name|functions
parameter_list|)
block|{
if|if
condition|(
name|functions
operator|&&
name|functions
operator|!=
name|d_ptr
operator|->
name|functions
condition|)
block|{
operator|delete
name|d_ptr
operator|->
name|functions
expr_stmt|;
name|d_ptr
operator|->
name|functions
operator|=
name|functions
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal     \preliminary     \class QGLScreenSurfaceFunctions     \brief The QGLScreenSurfaceFunctions class encapsulates the functions for creating native windows and pixmaps for OpenGL ES. */
end_comment
begin_comment
comment|/*!     \since 4.4.2      Creates a native OpenGLES drawable for the surface of \a widget and     returns it in \a native.  Returns true if the OpenGLES drawable could     be created, or false if windows are not supported.      This function will be called if the NativeWindows option is set on     the screen.      \sa createNativePixmap(), createNativeImage(), QGLScreen::options() */
end_comment
begin_function
DECL|function|createNativeWindow
name|bool
name|QGLScreenSurfaceFunctions
operator|::
name|createNativeWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|EGLNativeWindowType
modifier|*
name|native
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|native
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4.2      Creates a native OpenGLES drawable for directly rendering into     \a pixmap and returns it in \a native.  Returns true if the OpenGLES     drawable could be created, or false if direct rendering into pixmaps     is not supported.      This function will be called if the NativePixmaps option is set on     the screen.      \sa createNativeWindow(), createNativeImage(), QGLScreen::options() */
end_comment
begin_function
DECL|function|createNativePixmap
name|bool
name|QGLScreenSurfaceFunctions
operator|::
name|createNativePixmap
parameter_list|(
name|QPixmap
modifier|*
name|pixmap
parameter_list|,
name|EGLNativePixmapType
modifier|*
name|native
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|native
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4.2      Creates a native OpenGLES drawable for directly rendering into     \a image and returns it in \a native.  Returns true if the OpenGLES     drawable could be created, or false if direct rendering into images     is not supported.      This function will be called if the NativeImages option is set on     the screen.      \sa createNativeWindow(), createNativePixmap(), QGLScreen::options() */
end_comment
begin_function
DECL|function|createNativeImage
name|bool
name|QGLScreenSurfaceFunctions
operator|::
name|createNativeImage
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|,
name|EGLNativePixmapType
modifier|*
name|native
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|native
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
