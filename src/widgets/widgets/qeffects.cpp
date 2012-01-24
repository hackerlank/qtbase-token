begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EFFECTS
end_ifndef
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qeffects_p.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qpointer.h"
end_include
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*   Internal class QAlphaWidget.    The QAlphaWidget is shown while the animation lasts   and displays the pixmap resulting from the alpha blending. */
end_comment
begin_class
DECL|class|QAlphaWidget
class|class
name|QAlphaWidget
super|:
specifier|public
name|QWidget
super|,
specifier|private
name|QEffects
block|{
name|Q_OBJECT
public|public:
name|QAlphaWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|QAlphaWidget
parameter_list|()
destructor_decl|;
name|void
name|run
parameter_list|(
name|int
name|time
parameter_list|)
function_decl|;
protected|protected:
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
parameter_list|)
function_decl|;
name|void
name|alphaBlend
parameter_list|()
function_decl|;
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
protected|protected
name|slots
protected|:
name|void
name|render
parameter_list|()
function_decl|;
private|private:
DECL|member|pm
name|QPixmap
name|pm
decl_stmt|;
DECL|member|alpha
name|double
name|alpha
decl_stmt|;
DECL|member|backImage
name|QImage
name|backImage
decl_stmt|;
DECL|member|frontImage
name|QImage
name|frontImage
decl_stmt|;
DECL|member|mixedImage
name|QImage
name|mixedImage
decl_stmt|;
DECL|member|widget
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|widget
decl_stmt|;
DECL|member|duration
name|int
name|duration
decl_stmt|;
DECL|member|elapsed
name|int
name|elapsed
decl_stmt|;
DECL|member|showWidget
name|bool
name|showWidget
decl_stmt|;
DECL|member|anim
name|QTimer
name|anim
decl_stmt|;
DECL|member|checkTime
name|QElapsedTimer
name|checkTime
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|q_blend
specifier|static
name|QAlphaWidget
modifier|*
name|q_blend
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*   Constructs a QAlphaWidget. */
end_comment
begin_constructor
DECL|function|QAlphaWidget
name|QAlphaWidget
operator|::
name|QAlphaWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screen
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenNumber
argument_list|(
name|w
argument_list|)
argument_list|)
argument_list|,
name|f
argument_list|)
block|{
ifndef|#
directive|ifndef
name|Q_WS_WIN
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|=
name|w
expr_stmt|;
name|alpha
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAlphaWidget
name|QAlphaWidget
operator|::
name|~
name|QAlphaWidget
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
comment|// Restore user-defined opacity value
if|if
condition|(
name|widget
condition|)
name|widget
operator|->
name|setWindowOpacity
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_comment
comment|/*   \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QAlphaWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   Starts the alphablending animation.   The animation will take about \a time ms */
end_comment
begin_function
DECL|function|run
name|void
name|QAlphaWidget
operator|::
name|run
parameter_list|(
name|int
name|time
parameter_list|)
block|{
name|duration
operator|=
name|time
expr_stmt|;
if|if
condition|(
name|duration
operator|<
literal|0
condition|)
name|duration
operator|=
literal|150
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|elapsed
operator|=
literal|0
expr_stmt|;
name|checkTime
operator|.
name|start
argument_list|()
expr_stmt|;
name|showWidget
operator|=
literal|true
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setWindowOpacity
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
name|connect
argument_list|(
operator|&
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|render
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|.
name|start
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
comment|//This is roughly equivalent to calling setVisible(true) without actually showing the widget
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Hidden
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|widget
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|widget
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|frontImage
operator|=
name|QPixmap
operator|::
name|grabWidget
argument_list|(
name|widget
argument_list|)
operator|.
name|toImage
argument_list|()
expr_stmt|;
name|backImage
operator|=
name|QPixmap
operator|::
name|grabWindow
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|winId
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|toImage
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|backImage
operator|.
name|isNull
argument_list|()
operator|&&
name|checkTime
operator|.
name|elapsed
argument_list|()
operator|<
name|duration
operator|/
literal|2
condition|)
block|{
name|mixedImage
operator|=
name|backImage
operator|.
name|copy
argument_list|()
expr_stmt|;
name|pm
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|mixedImage
argument_list|)
expr_stmt|;
name|show
argument_list|()
expr_stmt|;
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|render
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|.
name|start
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|duration
operator|=
literal|0
expr_stmt|;
name|render
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*   \reimp */
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|QAlphaWidget
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Move
case|:
if|if
condition|(
name|o
operator|!=
name|widget
condition|)
break|break;
name|move
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Hide
case|:
case|case
name|QEvent
operator|::
name|Close
case|:
if|if
condition|(
name|o
operator|!=
name|widget
condition|)
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
name|showWidget
operator|=
literal|false
expr_stmt|;
name|render
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
block|{
name|QKeyEvent
modifier|*
name|ke
init|=
operator|(
name|QKeyEvent
operator|*
operator|)
name|e
decl_stmt|;
if|if
condition|(
name|ke
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
condition|)
block|{
name|showWidget
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|duration
operator|=
literal|0
expr_stmt|;
block|}
name|render
argument_list|()
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|eventFilter
argument_list|(
name|o
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*   \reimp */
end_comment
begin_function
DECL|function|closeEvent
name|void
name|QAlphaWidget
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|e
parameter_list|)
block|{
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|q_blend
condition|)
return|return;
name|showWidget
operator|=
literal|false
expr_stmt|;
name|render
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|closeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   Render alphablending for the time elapsed.    Show the blended widget and free all allocated source   if the blending is finished. */
end_comment
begin_function
DECL|function|render
name|void
name|QAlphaWidget
operator|::
name|render
parameter_list|()
block|{
name|int
name|tempel
init|=
name|checkTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|elapsed
operator|>=
name|tempel
condition|)
name|elapsed
operator|++
expr_stmt|;
else|else
name|elapsed
operator|=
name|tempel
expr_stmt|;
if|if
condition|(
name|duration
operator|!=
literal|0
condition|)
name|alpha
operator|=
name|tempel
operator|/
name|double
argument_list|(
name|duration
argument_list|)
expr_stmt|;
else|else
name|alpha
operator|=
literal|1
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
name|alpha
operator|>=
literal|1
operator|||
operator|!
name|showWidget
condition|)
block|{
name|anim
operator|.
name|stop
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setWindowOpacity
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|q_blend
operator|=
literal|0
expr_stmt|;
name|deleteLater
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|widget
operator|->
name|setWindowOpacity
argument_list|(
name|alpha
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
if|if
condition|(
name|alpha
operator|>=
literal|1
operator|||
operator|!
name|showWidget
condition|)
block|{
name|anim
operator|.
name|stop
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
condition|)
block|{
if|if
condition|(
operator|!
name|showWidget
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setFocus
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// Q_WS_WIN
name|widget
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|//Since we are faking the visibility of the widget
comment|//we need to unset the hidden state on it before calling show
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Hidden
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
name|lower
argument_list|()
expr_stmt|;
block|}
block|}
name|q_blend
operator|=
literal|0
expr_stmt|;
name|deleteLater
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|alphaBlend
argument_list|()
expr_stmt|;
name|pm
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|mixedImage
argument_list|)
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|// defined(Q_OS_WIN)&& !defined(Q_OS_WINCE)
block|}
end_function
begin_comment
comment|/*   Calculate an alphablended image. */
end_comment
begin_function
DECL|function|alphaBlend
name|void
name|QAlphaWidget
operator|::
name|alphaBlend
parameter_list|()
block|{
specifier|const
name|int
name|a
init|=
name|qRound
argument_list|(
name|alpha
operator|*
literal|256
argument_list|)
decl_stmt|;
specifier|const
name|int
name|ia
init|=
literal|256
operator|-
name|a
decl_stmt|;
specifier|const
name|int
name|sw
init|=
name|frontImage
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|sh
init|=
name|frontImage
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|bpl
init|=
name|frontImage
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|frontImage
operator|.
name|depth
argument_list|()
condition|)
block|{
case|case
literal|32
case|:
block|{
name|uchar
modifier|*
name|mixed_data
init|=
name|mixedImage
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|back_data
init|=
name|backImage
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|front_data
init|=
name|frontImage
operator|.
name|bits
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|sy
init|=
literal|0
init|;
name|sy
operator|<
name|sh
condition|;
name|sy
operator|++
control|)
block|{
name|quint32
modifier|*
name|mixed
init|=
operator|(
name|quint32
operator|*
operator|)
name|mixed_data
decl_stmt|;
specifier|const
name|quint32
modifier|*
name|back
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|back_data
decl_stmt|;
specifier|const
name|quint32
modifier|*
name|front
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|front_data
decl_stmt|;
for|for
control|(
name|int
name|sx
init|=
literal|0
init|;
name|sx
operator|<
name|sw
condition|;
name|sx
operator|++
control|)
block|{
name|quint32
name|bp
init|=
name|back
index|[
name|sx
index|]
decl_stmt|;
name|quint32
name|fp
init|=
name|front
index|[
name|sx
index|]
decl_stmt|;
name|mixed
index|[
name|sx
index|]
operator|=
name|qRgb
argument_list|(
operator|(
name|qRed
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qRed
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|qGreen
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qGreen
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|qBlue
argument_list|(
name|bp
argument_list|)
operator|*
name|ia
operator|+
name|qBlue
argument_list|(
name|fp
argument_list|)
operator|*
name|a
operator|)
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
name|mixed_data
operator|+=
name|bpl
expr_stmt|;
name|back_data
operator|+=
name|bpl
expr_stmt|;
name|front_data
operator|+=
name|bpl
expr_stmt|;
block|}
block|}
default|default:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*   Internal class QRollEffect    The QRollEffect widget is shown while the animation lasts   and displays a scrolling pixmap. */
end_comment
begin_class
DECL|class|QRollEffect
class|class
name|QRollEffect
super|:
specifier|public
name|QWidget
super|,
specifier|private
name|QEffects
block|{
name|Q_OBJECT
public|public:
name|QRollEffect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|,
name|DirFlags
name|orient
parameter_list|)
constructor_decl|;
name|void
name|run
parameter_list|(
name|int
name|time
parameter_list|)
function_decl|;
protected|protected:
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
name|void
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|scroll
parameter_list|()
function_decl|;
private|private:
DECL|member|widget
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|widget
decl_stmt|;
DECL|member|currentHeight
name|int
name|currentHeight
decl_stmt|;
DECL|member|currentWidth
name|int
name|currentWidth
decl_stmt|;
DECL|member|totalHeight
name|int
name|totalHeight
decl_stmt|;
DECL|member|totalWidth
name|int
name|totalWidth
decl_stmt|;
DECL|member|duration
name|int
name|duration
decl_stmt|;
DECL|member|elapsed
name|int
name|elapsed
decl_stmt|;
DECL|member|done
name|bool
name|done
decl_stmt|;
DECL|member|showWidget
name|bool
name|showWidget
decl_stmt|;
DECL|member|orientation
name|int
name|orientation
decl_stmt|;
DECL|member|anim
name|QTimer
name|anim
decl_stmt|;
DECL|member|checkTime
name|QElapsedTimer
name|checkTime
decl_stmt|;
DECL|member|pm
name|QPixmap
name|pm
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|q_roll
specifier|static
name|QRollEffect
modifier|*
name|q_roll
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*   Construct a QRollEffect widget. */
end_comment
begin_constructor
DECL|function|QRollEffect
name|QRollEffect
operator|::
name|QRollEffect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|,
name|DirFlags
name|orient
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|,
name|f
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|orient
argument_list|)
block|{
ifndef|#
directive|ifndef
name|Q_WS_WIN
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|widget
operator|=
name|w
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Resized
argument_list|)
condition|)
block|{
name|totalWidth
operator|=
name|widget
operator|->
name|width
argument_list|()
expr_stmt|;
name|totalHeight
operator|=
name|widget
operator|->
name|height
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|totalWidth
operator|=
name|widget
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
expr_stmt|;
name|totalHeight
operator|=
name|widget
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
name|currentHeight
operator|=
name|totalHeight
expr_stmt|;
name|currentWidth
operator|=
name|totalWidth
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
operator|(
name|RightScroll
operator||
name|LeftScroll
operator|)
condition|)
name|currentWidth
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
operator|(
name|DownScroll
operator||
name|UpScroll
operator|)
condition|)
name|currentHeight
operator|=
literal|0
expr_stmt|;
name|pm
operator|=
name|QPixmap
operator|::
name|grabWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*   \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QRollEffect
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|int
name|x
init|=
name|orientation
operator|&
name|RightScroll
condition|?
name|qMin
argument_list|(
literal|0
argument_list|,
name|currentWidth
operator|-
name|totalWidth
argument_list|)
else|:
literal|0
decl_stmt|;
name|int
name|y
init|=
name|orientation
operator|&
name|DownScroll
condition|?
name|qMin
argument_list|(
literal|0
argument_list|,
name|currentHeight
operator|-
name|totalHeight
argument_list|)
else|:
literal|0
decl_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   \reimp */
end_comment
begin_function
DECL|function|closeEvent
name|void
name|QRollEffect
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|e
parameter_list|)
block|{
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
name|done
condition|)
return|return;
name|showWidget
operator|=
literal|false
expr_stmt|;
name|done
operator|=
literal|true
expr_stmt|;
name|scroll
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|closeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   Start the animation.    The animation will take about \a time ms, or is   calculated if \a time is negative */
end_comment
begin_function
DECL|function|run
name|void
name|QRollEffect
operator|::
name|run
parameter_list|(
name|int
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|duration
operator|=
name|time
expr_stmt|;
name|elapsed
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|duration
operator|<
literal|0
condition|)
block|{
name|int
name|dist
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|orientation
operator|&
operator|(
name|RightScroll
operator||
name|LeftScroll
operator|)
condition|)
name|dist
operator|+=
name|totalWidth
operator|-
name|currentWidth
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
operator|(
name|DownScroll
operator||
name|UpScroll
operator|)
condition|)
name|dist
operator|+=
name|totalHeight
operator|-
name|currentHeight
expr_stmt|;
name|duration
operator|=
name|qMin
argument_list|(
name|qMax
argument_list|(
name|dist
operator|/
literal|3
argument_list|,
literal|50
argument_list|)
argument_list|,
literal|120
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
operator|&
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|scroll
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|qMin
argument_list|(
name|currentWidth
argument_list|,
name|totalWidth
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|currentHeight
argument_list|,
name|totalHeight
argument_list|)
argument_list|)
expr_stmt|;
comment|//This is roughly equivalent to calling setVisible(true) without actually showing the widget
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Hidden
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|show
argument_list|()
expr_stmt|;
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|showWidget
operator|=
literal|true
expr_stmt|;
name|done
operator|=
literal|false
expr_stmt|;
name|anim
operator|.
name|start
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|checkTime
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   Roll according to the time elapsed. */
end_comment
begin_function
DECL|function|scroll
name|void
name|QRollEffect
operator|::
name|scroll
parameter_list|()
block|{
if|if
condition|(
operator|!
name|done
operator|&&
name|widget
condition|)
block|{
name|int
name|tempel
init|=
name|checkTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
if|if
condition|(
name|elapsed
operator|>=
name|tempel
condition|)
name|elapsed
operator|++
expr_stmt|;
else|else
name|elapsed
operator|=
name|tempel
expr_stmt|;
if|if
condition|(
name|currentWidth
operator|!=
name|totalWidth
condition|)
block|{
name|currentWidth
operator|=
name|totalWidth
operator|*
operator|(
name|elapsed
operator|/
name|duration
operator|)
operator|+
operator|(
literal|2
operator|*
name|totalWidth
operator|*
operator|(
name|elapsed
operator|%
name|duration
operator|)
operator|+
name|duration
operator|)
operator|/
operator|(
literal|2
operator|*
name|duration
operator|)
expr_stmt|;
comment|// equiv. to int((totalWidth*elapsed) / duration + 0.5)
name|done
operator|=
operator|(
name|currentWidth
operator|>=
name|totalWidth
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|currentHeight
operator|!=
name|totalHeight
condition|)
block|{
name|currentHeight
operator|=
name|totalHeight
operator|*
operator|(
name|elapsed
operator|/
name|duration
operator|)
operator|+
operator|(
literal|2
operator|*
name|totalHeight
operator|*
operator|(
name|elapsed
operator|%
name|duration
operator|)
operator|+
name|duration
operator|)
operator|/
operator|(
literal|2
operator|*
name|duration
operator|)
expr_stmt|;
comment|// equiv. to int((totalHeight*elapsed) / duration + 0.5)
name|done
operator|=
operator|(
name|currentHeight
operator|>=
name|totalHeight
operator|)
expr_stmt|;
block|}
name|done
operator|=
operator|(
name|currentHeight
operator|>=
name|totalHeight
operator|)
operator|&&
operator|(
name|currentWidth
operator|>=
name|totalWidth
operator|)
expr_stmt|;
name|int
name|w
init|=
name|totalWidth
decl_stmt|;
name|int
name|h
init|=
name|totalHeight
decl_stmt|;
name|int
name|x
init|=
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
name|orientation
operator|&
name|RightScroll
operator|||
name|orientation
operator|&
name|LeftScroll
condition|)
name|w
operator|=
name|qMin
argument_list|(
name|currentWidth
argument_list|,
name|totalWidth
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
name|DownScroll
operator|||
name|orientation
operator|&
name|UpScroll
condition|)
name|h
operator|=
name|qMin
argument_list|(
name|currentHeight
argument_list|,
name|totalHeight
argument_list|)
expr_stmt|;
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
name|UpScroll
condition|)
name|y
operator|=
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|qMax
argument_list|(
literal|0
argument_list|,
name|totalHeight
operator|-
name|currentHeight
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
name|LeftScroll
condition|)
name|x
operator|=
name|widget
operator|->
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|qMax
argument_list|(
literal|0
argument_list|,
name|totalWidth
operator|-
name|currentWidth
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|&
name|UpScroll
operator|||
name|orientation
operator|&
name|LeftScroll
condition|)
name|move
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|done
condition|)
block|{
name|anim
operator|.
name|stop
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
condition|)
block|{
if|if
condition|(
operator|!
name|showWidget
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setFocus
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|widget
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|//Since we are faking the visibility of the widget
comment|//we need to unset the hidden state on it before calling show
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Hidden
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
name|lower
argument_list|()
expr_stmt|;
block|}
block|}
name|q_roll
operator|=
literal|0
expr_stmt|;
name|deleteLater
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Scroll widget \a w in \a time ms. \a orient may be 1 (vertical), 2     (horizontal) or 3 (diagonal). */
end_comment
begin_function
DECL|function|qScrollEffect
name|void
name|qScrollEffect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QEffects
operator|::
name|DirFlags
name|orient
parameter_list|,
name|int
name|time
parameter_list|)
block|{
if|if
condition|(
name|q_roll
condition|)
block|{
name|q_roll
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|q_roll
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|w
condition|)
return|return;
name|QApplication
operator|::
name|sendPostedEvents
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|Move
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|sendPostedEvents
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|Resize
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|Qt
operator|::
name|ToolTip
decl_stmt|;
comment|// those can be popups - they would steal the focus, but are disabled
name|q_roll
operator|=
operator|new
name|QRollEffect
argument_list|(
name|w
argument_list|,
name|flags
argument_list|,
name|orient
argument_list|)
expr_stmt|;
name|q_roll
operator|->
name|run
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Fade in widget \a w in \a time ms. */
end_comment
begin_function
DECL|function|qFadeEffect
name|void
name|qFadeEffect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|int
name|time
parameter_list|)
block|{
if|if
condition|(
name|q_blend
condition|)
block|{
name|q_blend
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|q_blend
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|w
condition|)
return|return;
name|QApplication
operator|::
name|sendPostedEvents
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|Move
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|sendPostedEvents
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|Resize
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|Qt
operator|::
name|ToolTip
decl_stmt|;
comment|// those can be popups - they would steal the focus, but are disabled
name|q_blend
operator|=
operator|new
name|QAlphaWidget
argument_list|(
name|w
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|q_blend
operator|->
name|run
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|/*   Delete this after timeout */
end_comment
begin_include
include|#
directive|include
file|"qeffects.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_EFFECTS
end_comment
end_unit
