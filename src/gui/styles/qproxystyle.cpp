begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<private/qproxystyle_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"qproxystyle.h"
end_include
begin_include
include|#
directive|include
file|"qstylefactory.h"
end_include
begin_include
include|#
directive|include
file|<private/qstyle_p.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_PROXY
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_PLUGIN
argument_list|)
end_if
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QProxyStyle      \brief The QProxyStyle class is a convenience class that simplifies     dynamically overriding QStyle elements.      \since 4.6      A QProxyStyle wraps a QStyle (usually the default system style) for the     purpose of dynamically overriding painting or other specific style behavior.      The following example shows how to override the shortcut underline     behavior on any platform:      \snippet doc/src/snippets/code/src_gui_qproxystyle.cpp 1      Warning: The \l {QCommonStyle} {common styles} provided by Qt will     respect this hint, because they call QStyle::proxy(), but there is     no guarantee that QStyle::proxy() will be called for user defined     or system controlled styles. It would not work on a Mac, for     example, where menus are handled by the operating system.      \sa QStyle */
DECL|function|ensureBaseStyle
name|void
name|QProxyStylePrivate
operator|::
name|ensureBaseStyle
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
if|if
condition|(
name|baseStyle
condition|)
return|return;
if|if
condition|(
operator|!
name|baseStyle
operator|&&
operator|!
name|QApplicationPrivate
operator|::
name|styleOverride
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|baseStyle
operator|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|QApplicationPrivate
operator|::
name|styleOverride
argument_list|)
expr_stmt|;
if|if
condition|(
name|baseStyle
condition|)
block|{
comment|// If baseStyle is an instance of the same proxyStyle
comment|// we destroy it and fall back to the desktop style
if|if
condition|(
name|qstrcmp
argument_list|(
name|baseStyle
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
name|q
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|delete
name|baseStyle
expr_stmt|;
name|baseStyle
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|baseStyle
condition|)
comment|// Use application desktop style
name|baseStyle
operator|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|QApplicationPrivate
operator|::
name|desktopStyleKey
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|baseStyle
condition|)
comment|// Fallback to windows style
name|baseStyle
operator|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
argument_list|)
expr_stmt|;
name|baseStyle
operator|->
name|setProxy
argument_list|(
cast|const_cast
argument_list|<
name|QProxyStyle
operator|*
argument_list|>
argument_list|(
name|q
argument_list|)
argument_list|)
expr_stmt|;
name|baseStyle
operator|->
name|setParent
argument_list|(
cast|const_cast
argument_list|<
name|QProxyStyle
operator|*
argument_list|>
argument_list|(
name|q
argument_list|)
argument_list|)
expr_stmt|;
comment|// Take ownership
block|}
end_function
begin_comment
comment|/*!   Constructs a QProxyStyle object for overriding behavior in \a style   or in the current application \l{QStyle}{style} if \a style is 0   (default). Normally \a style is 0, because you want to override   behavior in the system style.    Ownership of \a style is transferred to QProxyStyle. */
end_comment
begin_constructor
DECL|function|QProxyStyle
name|QProxyStyle
operator|::
name|QProxyStyle
parameter_list|(
name|QStyle
modifier|*
name|style
parameter_list|)
member_init_list|:
name|QCommonStyle
argument_list|(
operator|*
operator|new
name|QProxyStylePrivate
argument_list|()
argument_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
if|if
condition|(
name|style
condition|)
block|{
name|style
operator|->
name|setProxy
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|style
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// Take ownership
name|d
operator|->
name|baseStyle
operator|=
name|style
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QProxyStyle object. */
end_comment
begin_destructor
DECL|function|~QProxyStyle
name|QProxyStyle
operator|::
name|~
name|QProxyStyle
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the proxy base style object. If no base style     is set on the proxy style, QProxyStyle will create     an instance of the application style instead.      \sa setBaseStyle(), QStyle */
end_comment
begin_function
DECL|function|baseStyle
name|QStyle
modifier|*
name|QProxyStyle
operator|::
name|baseStyle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the base style that should be proxied.      Ownership of \a style is transferred to QProxyStyle.      If style is zero, a desktop-dependant style will be     assigned automatically. */
end_comment
begin_function
DECL|function|setBaseStyle
name|void
name|QProxyStyle
operator|::
name|setBaseStyle
parameter_list|(
name|QStyle
modifier|*
name|style
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|baseStyle
operator|&&
name|d
operator|->
name|baseStyle
operator|->
name|parent
argument_list|()
operator|==
name|this
condition|)
name|d
operator|->
name|baseStyle
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|=
name|style
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|baseStyle
condition|)
block|{
name|d
operator|->
name|baseStyle
operator|->
name|setProxy
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|drawPrimitive
name|void
name|QProxyStyle
operator|::
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|drawPrimitive
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp  */
end_comment
begin_function
DECL|function|drawControl
name|void
name|QProxyStyle
operator|::
name|drawControl
parameter_list|(
name|ControlElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|drawControl
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|drawComplexControl
name|void
name|QProxyStyle
operator|::
name|drawComplexControl
parameter_list|(
name|ComplexControl
name|control
parameter_list|,
specifier|const
name|QStyleOptionComplex
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|drawComplexControl
argument_list|(
name|control
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|drawItemText
name|void
name|QProxyStyle
operator|::
name|drawItemText
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|enabled
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QPalette
operator|::
name|ColorRole
name|textRole
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|drawItemText
argument_list|(
name|painter
argument_list|,
name|rect
argument_list|,
name|flags
argument_list|,
name|pal
argument_list|,
name|enabled
argument_list|,
name|text
argument_list|,
name|textRole
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|drawItemPixmap
name|void
name|QProxyStyle
operator|::
name|drawItemPixmap
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|alignment
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|drawItemPixmap
argument_list|(
name|painter
argument_list|,
name|rect
argument_list|,
name|alignment
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|sizeFromContents
name|QSize
name|QProxyStyle
operator|::
name|sizeFromContents
parameter_list|(
name|ContentsType
name|type
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|sizeFromContents
argument_list|(
name|type
argument_list|,
name|option
argument_list|,
name|size
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|subElementRect
name|QRect
name|QProxyStyle
operator|::
name|subElementRect
parameter_list|(
name|SubElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|subElementRect
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|subControlRect
name|QRect
name|QProxyStyle
operator|::
name|subControlRect
parameter_list|(
name|ComplexControl
name|cc
parameter_list|,
specifier|const
name|QStyleOptionComplex
modifier|*
name|option
parameter_list|,
name|SubControl
name|sc
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|subControlRect
argument_list|(
name|cc
argument_list|,
name|option
argument_list|,
name|sc
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|itemTextRect
name|QRect
name|QProxyStyle
operator|::
name|itemTextRect
parameter_list|(
specifier|const
name|QFontMetrics
modifier|&
name|fm
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
name|bool
name|enabled
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|itemTextRect
argument_list|(
name|fm
argument_list|,
name|r
argument_list|,
name|flags
argument_list|,
name|enabled
argument_list|,
name|text
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|itemPixmapRect
name|QRect
name|QProxyStyle
operator|::
name|itemPixmapRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|itemPixmapRect
argument_list|(
name|r
argument_list|,
name|flags
argument_list|,
name|pixmap
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|hitTestComplexControl
name|QStyle
operator|::
name|SubControl
name|QProxyStyle
operator|::
name|hitTestComplexControl
parameter_list|(
name|ComplexControl
name|control
parameter_list|,
specifier|const
name|QStyleOptionComplex
modifier|*
name|option
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|hitTestComplexControl
argument_list|(
name|control
argument_list|,
name|option
argument_list|,
name|pos
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|styleHint
name|int
name|QProxyStyle
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QStyleHintReturn
modifier|*
name|returnData
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|styleHint
argument_list|(
name|hint
argument_list|,
name|option
argument_list|,
name|widget
argument_list|,
name|returnData
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|pixelMetric
name|int
name|QProxyStyle
operator|::
name|pixelMetric
parameter_list|(
name|PixelMetric
name|metric
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|standardPixmap
name|QPixmap
name|QProxyStyle
operator|::
name|standardPixmap
parameter_list|(
name|StandardPixmap
name|standardPixmap
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|standardPixmap
argument_list|(
name|standardPixmap
argument_list|,
name|opt
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|generatedIconPixmap
name|QPixmap
name|QProxyStyle
operator|::
name|generatedIconPixmap
parameter_list|(
name|QIcon
operator|::
name|Mode
name|iconMode
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|generatedIconPixmap
argument_list|(
name|iconMode
argument_list|,
name|pixmap
argument_list|,
name|opt
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|standardPalette
name|QPalette
name|QProxyStyle
operator|::
name|standardPalette
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|standardPalette
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|polish
name|void
name|QProxyStyle
operator|::
name|polish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|polish
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|polish
name|void
name|QProxyStyle
operator|::
name|polish
parameter_list|(
name|QPalette
modifier|&
name|pal
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|polish
argument_list|(
name|pal
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|polish
name|void
name|QProxyStyle
operator|::
name|polish
parameter_list|(
name|QApplication
modifier|*
name|app
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|polish
argument_list|(
name|app
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|unpolish
name|void
name|QProxyStyle
operator|::
name|unpolish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|unpolish
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|unpolish
name|void
name|QProxyStyle
operator|::
name|unpolish
parameter_list|(
name|QApplication
modifier|*
name|app
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
name|d
operator|->
name|baseStyle
operator|->
name|unpolish
argument_list|(
name|app
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp  */
end_comment
begin_function
DECL|function|event
name|bool
name|QProxyStyle
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns an icon for the given \a standardIcon.    Reimplement this slot to provide your own icons in a QStyle   subclass. The \a option argument can be used to pass extra   information required to find the appropriate icon. The \a widget   argument is optional and can also be used to help find the icon.    \note Because of binary compatibility constraints, standardIcon()   introduced in Qt 4.1 is not virtual. Therefore it must dynamically   detect and call \e this slot.  This default implementation simply   calls standardIcon() with the given parameters.    \sa standardIcon()  */
end_comment
begin_function
DECL|function|standardIconImplementation
name|QIcon
name|QProxyStyle
operator|::
name|standardIconImplementation
parameter_list|(
name|StandardPixmap
name|standardIcon
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|standardIcon
argument_list|(
name|standardIcon
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   This slot is called by layoutSpacing() to determine the spacing that   should be used between \a control1 and \a control2 in a layout. \a   orientation specifies whether the controls are laid out side by side   or stacked vertically. The \a option parameter can be used to pass   extra information about the parent widget.  The \a widget parameter   is optional and can also be used if \a option is 0.    The default implementation returns -1.    \sa layoutSpacing(), combinedLayoutSpacing()  */
end_comment
begin_function
DECL|function|layoutSpacingImplementation
name|int
name|QProxyStyle
operator|::
name|layoutSpacingImplementation
parameter_list|(
name|QSizePolicy
operator|::
name|ControlType
name|control1
parameter_list|,
name|QSizePolicy
operator|::
name|ControlType
name|control2
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProxyStyle
argument_list|)
expr_stmt|;
name|d
operator|->
name|ensureBaseStyle
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|baseStyle
operator|->
name|layoutSpacing
argument_list|(
name|control1
argument_list|,
name|control2
argument_list|,
name|orientation
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_PROXY
end_comment
end_unit
