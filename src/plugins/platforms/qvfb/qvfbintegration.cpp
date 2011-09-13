begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_include
include|#
directive|include
file|<qvfbhdr.h>
end_include
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|"qvfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qvfbwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|"qgenericunixfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qgenericunixeventdispatcher.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QVFbScreenKeyboardHandler
class|class
name|QVFbScreenKeyboardHandler
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|QVFbScreenKeyboardHandler
parameter_list|(
name|int
name|displayId
parameter_list|)
constructor_decl|;
name|~
name|QVFbScreenKeyboardHandler
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|readKeyboardData
parameter_list|()
function_decl|;
private|private:
DECL|member|kbdFD
name|int
name|kbdFD
decl_stmt|;
DECL|member|kbdIdx
name|int
name|kbdIdx
decl_stmt|;
DECL|member|kbdBufferLen
name|int
name|kbdBufferLen
decl_stmt|;
DECL|member|kbdBuffer
name|unsigned
name|char
modifier|*
name|kbdBuffer
decl_stmt|;
DECL|member|keyNotifier
name|QSocketNotifier
modifier|*
name|keyNotifier
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QVFbScreenKeyboardHandler
name|QVFbScreenKeyboardHandler
operator|::
name|QVFbScreenKeyboardHandler
parameter_list|(
name|int
name|displayId
parameter_list|)
block|{
specifier|const
name|QString
name|keyboardDev
init|=
name|QT_VFB_KEYBOARD_PIPE
argument_list|(
name|displayId
argument_list|)
decl_stmt|;
name|kbdFD
operator|=
operator|-
literal|1
expr_stmt|;
name|kbdIdx
operator|=
literal|0
expr_stmt|;
name|kbdBufferLen
operator|=
sizeof|sizeof
argument_list|(
name|QVFbKeyData
argument_list|)
operator|*
literal|5
expr_stmt|;
name|kbdBuffer
operator|=
operator|new
name|unsigned
name|char
index|[
name|kbdBufferLen
index|]
expr_stmt|;
name|kbdFD
operator|=
name|QT_OPEN
argument_list|(
name|keyboardDev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|kbdFD
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"QVFbScreenKeyboardHandler"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"QVFbScreenKeyboardHandler: Unable to open device %s"
argument_list|,
name|qPrintable
argument_list|(
name|keyboardDev
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Clear pending input
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
while|while
condition|(
name|QT_READ
argument_list|(
name|kbdFD
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|)
operator|>
literal|0
condition|)
block|{ }
name|keyNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|kbdFD
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|keyNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readKeyboardData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QVFbScreenKeyboardHandler
name|QVFbScreenKeyboardHandler
operator|::
name|~
name|QVFbScreenKeyboardHandler
parameter_list|()
block|{
if|if
condition|(
name|kbdFD
operator|>=
literal|0
condition|)
name|QT_CLOSE
argument_list|(
name|kbdFD
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|kbdBuffer
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|readKeyboardData
name|void
name|QVFbScreenKeyboardHandler
operator|::
name|readKeyboardData
parameter_list|()
block|{
name|int
name|n
decl_stmt|;
do|do
block|{
name|n
operator|=
name|QT_READ
argument_list|(
name|kbdFD
argument_list|,
name|kbdBuffer
operator|+
name|kbdIdx
argument_list|,
name|kbdBufferLen
operator|-
name|kbdIdx
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|kbdIdx
operator|+=
name|n
expr_stmt|;
block|}
do|while
condition|(
name|n
operator|>
literal|0
condition|)
do|;
name|int
name|idx
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|kbdIdx
operator|-
name|idx
operator|>=
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|QVFbKeyData
argument_list|)
condition|)
block|{
name|QVFbKeyData
modifier|*
name|kd
init|=
operator|(
name|QVFbKeyData
operator|*
operator|)
operator|(
name|kbdBuffer
operator|+
name|idx
operator|)
decl_stmt|;
if|if
condition|(
name|kd
operator|->
name|unicode
operator|==
literal|0
operator|&&
name|kd
operator|->
name|keycode
operator|==
literal|0
operator|&&
name|kd
operator|->
name|modifiers
operator|==
literal|0
operator|&&
name|kd
operator|->
name|press
condition|)
block|{
comment|// magic exit key
name|qWarning
argument_list|(
literal|"Instructed to quit by Virtual Keyboard"
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
comment|//QWSServer::processKeyEvent(kd->unicode ? kd->unicode : 0xffff, kd->keycode, kd->modifiers, kd->press, kd->repeat);
name|QEvent
operator|::
name|Type
name|type
init|=
name|kd
operator|->
name|press
condition|?
name|QEvent
operator|::
name|KeyPress
else|:
name|QEvent
operator|::
name|KeyRelease
decl_stmt|;
name|QString
name|text
decl_stmt|;
if|if
condition|(
name|kd
operator|->
name|unicode
operator|&&
name|kd
operator|->
name|unicode
operator|!=
literal|0xffff
condition|)
name|text
operator|+=
name|QChar
argument_list|(
name|kd
operator|->
name|unicode
argument_list|)
expr_stmt|;
comment|//        qDebug()<< "readKeyboardData"<< type<< hex<< kd->keycode<< kd->modifiers<< text;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
literal|0
argument_list|,
name|type
argument_list|,
name|kd
operator|->
name|keycode
argument_list|,
name|kd
operator|->
name|modifiers
argument_list|,
name|text
argument_list|,
name|kd
operator|->
name|repeat
argument_list|,
name|int
argument_list|(
name|text
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|idx
operator|+=
sizeof|sizeof
argument_list|(
name|QVFbKeyData
argument_list|)
expr_stmt|;
block|}
name|int
name|surplus
init|=
name|kbdIdx
operator|-
name|idx
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|surplus
condition|;
name|i
operator|++
control|)
name|kbdBuffer
index|[
name|i
index|]
operator|=
name|kbdBuffer
index|[
name|idx
operator|+
name|i
index|]
expr_stmt|;
name|kbdIdx
operator|=
name|surplus
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QVFbScreenMouseHandler
class|class
name|QVFbScreenMouseHandler
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|QVFbScreenMouseHandler
parameter_list|(
name|int
name|displayId
parameter_list|)
constructor_decl|;
name|~
name|QVFbScreenMouseHandler
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|readMouseData
parameter_list|()
function_decl|;
private|private:
DECL|member|mouseFD
name|int
name|mouseFD
decl_stmt|;
DECL|member|mouseIdx
name|int
name|mouseIdx
decl_stmt|;
DECL|enumerator|mouseBufSize
enum|enum
block|{
name|mouseBufSize
init|=
literal|128
block|}
enum|;
DECL|member|mouseBuf
name|uchar
name|mouseBuf
index|[
name|mouseBufSize
index|]
decl_stmt|;
DECL|member|mouseNotifier
name|QSocketNotifier
modifier|*
name|mouseNotifier
decl_stmt|;
DECL|member|oldButtonState
name|int
name|oldButtonState
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QVFbScreenMouseHandler
name|QVFbScreenMouseHandler
operator|::
name|QVFbScreenMouseHandler
parameter_list|(
name|int
name|displayId
parameter_list|)
block|{
name|QString
name|mouseDev
init|=
name|QT_VFB_MOUSE_PIPE
argument_list|(
name|displayId
argument_list|)
decl_stmt|;
name|mouseFD
operator|=
name|QT_OPEN
argument_list|(
name|mouseDev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|mouseFD
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"QVFbMouseHandler::QVFbMouseHandler"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"QVFbMouseHander: Unable to open device %s"
argument_list|,
name|qPrintable
argument_list|(
name|mouseDev
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Clear pending input
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
while|while
condition|(
name|QT_READ
argument_list|(
name|mouseFD
argument_list|,
name|buf
argument_list|,
literal|1
argument_list|)
operator|>
literal|0
condition|)
block|{ }
name|mouseIdx
operator|=
literal|0
expr_stmt|;
name|oldButtonState
operator|=
literal|0
expr_stmt|;
name|mouseNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|mouseFD
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mouseNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readMouseData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QVFbScreenMouseHandler
name|QVFbScreenMouseHandler
operator|::
name|~
name|QVFbScreenMouseHandler
parameter_list|()
block|{
if|if
condition|(
name|mouseFD
operator|>=
literal|0
condition|)
name|QT_CLOSE
argument_list|(
name|mouseFD
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|readMouseData
name|void
name|QVFbScreenMouseHandler
operator|::
name|readMouseData
parameter_list|()
block|{
name|int
name|n
decl_stmt|;
do|do
block|{
name|n
operator|=
name|QT_READ
argument_list|(
name|mouseFD
argument_list|,
name|mouseBuf
operator|+
name|mouseIdx
argument_list|,
name|mouseBufSize
operator|-
name|mouseIdx
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|mouseIdx
operator|+=
name|n
expr_stmt|;
block|}
do|while
condition|(
name|n
operator|>
literal|0
condition|)
do|;
name|int
name|idx
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|int
name|packetsize
init|=
sizeof|sizeof
argument_list|(
name|QPoint
argument_list|)
operator|+
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
decl_stmt|;
while|while
condition|(
name|mouseIdx
operator|-
name|idx
operator|>=
name|packetsize
condition|)
block|{
name|uchar
modifier|*
name|mb
init|=
name|mouseBuf
operator|+
name|idx
decl_stmt|;
name|QPoint
name|mousePos
init|=
operator|*
cast|reinterpret_cast
argument_list|<
name|QPoint
operator|*
argument_list|>
argument_list|(
name|mb
argument_list|)
decl_stmt|;
name|mb
operator|+=
sizeof|sizeof
argument_list|(
name|QPoint
argument_list|)
expr_stmt|;
name|int
name|bstate
init|=
operator|*
cast|reinterpret_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
name|mb
argument_list|)
decl_stmt|;
name|mb
operator|+=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
expr_stmt|;
comment|//int wheel = *reinterpret_cast<int *>(mb);
name|int
name|button
init|=
name|bstate
operator|^
name|oldButtonState
decl_stmt|;
name|QEvent
operator|::
name|Type
name|type
init|=
name|QEvent
operator|::
name|MouseMove
decl_stmt|;
if|if
condition|(
name|button
condition|)
block|{
name|type
operator|=
operator|(
name|button
operator|&
name|bstate
operator|)
condition|?
name|QEvent
operator|::
name|MouseButtonPress
else|:
name|QEvent
operator|::
name|MouseButtonRelease
expr_stmt|;
block|}
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|mousePos
argument_list|,
name|mousePos
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|(
name|bstate
argument_list|)
argument_list|)
expr_stmt|;
comment|//        qDebug()<< "readMouseData"<< mousePos<< button<< bstate<< oldButtonState<< type;
name|oldButtonState
operator|=
name|bstate
expr_stmt|;
name|idx
operator|+=
name|packetsize
expr_stmt|;
block|}
name|int
name|surplus
init|=
name|mouseIdx
operator|-
name|idx
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|surplus
condition|;
name|i
operator|++
control|)
name|mouseBuf
index|[
name|i
index|]
operator|=
name|mouseBuf
index|[
name|idx
operator|+
name|i
index|]
expr_stmt|;
name|mouseIdx
operator|=
name|surplus
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QVFbScreenPrivate
class|class
name|QVFbScreenPrivate
block|{
public|public:
DECL|function|QVFbScreenPrivate
name|QVFbScreenPrivate
parameter_list|(
name|int
name|id
parameter_list|)
member_init_list|:
name|shmrgn
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|hdr
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mouseHandler
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|keyboardHandler
argument_list|(
literal|0
argument_list|)
block|{
name|displayId
operator|=
name|id
expr_stmt|;
name|connect
argument_list|(
name|displayId
argument_list|)
expr_stmt|;
block|}
DECL|function|~QVFbScreenPrivate
name|~
name|QVFbScreenPrivate
parameter_list|()
block|{
name|disconnect
argument_list|()
expr_stmt|;
block|}
name|void
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
function_decl|;
name|bool
name|connect
parameter_list|(
name|int
name|displayId
parameter_list|)
function_decl|;
name|void
name|disconnect
parameter_list|()
function_decl|;
DECL|function|screenImage
name|QImage
modifier|*
name|screenImage
parameter_list|()
block|{
return|return
operator|&
name|img
return|;
block|}
DECL|function|screenSize
name|QSize
name|screenSize
parameter_list|()
block|{
return|return
name|img
operator|.
name|size
argument_list|()
return|;
block|}
DECL|function|depth
name|int
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|img
operator|.
name|depth
argument_list|()
return|;
block|}
DECL|function|format
name|QImage
operator|::
name|Format
name|format
parameter_list|()
specifier|const
block|{
return|return
name|img
operator|.
name|format
argument_list|()
return|;
block|}
private|private:
DECL|member|shmrgn
name|unsigned
name|char
modifier|*
name|shmrgn
decl_stmt|;
DECL|member|hdr
name|QVFbHeader
modifier|*
name|hdr
decl_stmt|;
DECL|member|data
name|uchar
modifier|*
name|data
decl_stmt|;
DECL|member|mouseHandler
name|QVFbScreenMouseHandler
modifier|*
name|mouseHandler
decl_stmt|;
DECL|member|keyboardHandler
name|QVFbScreenKeyboardHandler
modifier|*
name|keyboardHandler
decl_stmt|;
DECL|member|displayId
name|int
name|displayId
decl_stmt|;
DECL|member|img
name|QImage
name|img
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|setDirty
name|void
name|QVFbScreenPrivate
operator|::
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
name|hdr
operator|->
name|dirty
operator|=
literal|true
expr_stmt|;
name|hdr
operator|->
name|update
operator|=
name|hdr
operator|->
name|update
operator|.
name|united
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connect
name|bool
name|QVFbScreenPrivate
operator|::
name|connect
parameter_list|(
name|int
name|displayId
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QVFbScreenPrivate::connect"
operator|<<
name|displayId
expr_stmt|;
name|key_t
name|key
init|=
name|ftok
argument_list|(
name|QT_VFB_MOUSE_PIPE
argument_list|(
name|displayId
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|,
literal|'b'
argument_list|)
decl_stmt|;
if|if
condition|(
name|key
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
name|int
name|shmId
init|=
name|shmget
argument_list|(
name|key
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|shmId
operator|!=
operator|-
literal|1
condition|)
name|shmrgn
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|shmat
argument_list|(
name|shmId
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|long
operator|)
name|shmrgn
operator|==
operator|-
literal|1
operator|||
name|shmrgn
operator|==
literal|0
condition|)
block|{
name|qDebug
argument_list|(
literal|"No shmrgn %ld"
argument_list|,
operator|(
name|long
operator|)
name|shmrgn
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|hdr
operator|=
operator|(
name|QVFbHeader
operator|*
operator|)
name|shmrgn
expr_stmt|;
name|data
operator|=
name|shmrgn
operator|+
name|hdr
operator|->
name|dataoffset
expr_stmt|;
name|int
name|w
init|=
name|hdr
operator|->
name|width
decl_stmt|;
name|int
name|h
init|=
name|hdr
operator|->
name|height
decl_stmt|;
name|int
name|d
init|=
name|hdr
operator|->
name|depth
decl_stmt|;
name|int
name|lstep
init|=
name|hdr
operator|->
name|linestep
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|QImage
operator|::
name|Format_Invalid
decl_stmt|;
if|if
condition|(
name|d
operator|==
literal|32
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
elseif|else
if|if
condition|(
name|d
operator|==
literal|16
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_Invalid
condition|)
block|{
name|img
operator|=
name|QImage
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|img
operator|=
name|QImage
argument_list|(
name|data
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|lstep
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"connected %dx%d %d bpp"
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|mouseHandler
operator|=
operator|new
name|QVFbScreenMouseHandler
argument_list|(
name|displayId
argument_list|)
expr_stmt|;
name|keyboardHandler
operator|=
operator|new
name|QVFbScreenKeyboardHandler
argument_list|(
name|displayId
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|disconnect
name|void
name|QVFbScreenPrivate
operator|::
name|disconnect
parameter_list|()
block|{
if|if
condition|(
operator|(
name|long
operator|)
name|shmrgn
operator|!=
operator|-
literal|1
operator|&&
name|shmrgn
condition|)
block|{
name|shmdt
argument_list|(
operator|(
name|char
operator|*
operator|)
name|shmrgn
argument_list|)
expr_stmt|;
name|shmrgn
operator|=
literal|0
expr_stmt|;
block|}
operator|delete
name|mouseHandler
expr_stmt|;
name|mouseHandler
operator|=
literal|0
expr_stmt|;
operator|delete
name|keyboardHandler
expr_stmt|;
name|keyboardHandler
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QVFbScreen
name|QVFbScreen
operator|::
name|QVFbScreen
parameter_list|(
name|int
name|id
parameter_list|)
block|{
name|d_ptr
operator|=
operator|new
name|QVFbScreenPrivate
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QVFbScreen
name|QVFbScreen
operator|::
name|~
name|QVFbScreen
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setDirty
name|void
name|QVFbScreen
operator|::
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|d_ptr
operator|->
name|setDirty
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QVFbScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|d_ptr
operator|->
name|screenSize
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QVFbScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|depth
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QVFbScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|format
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSize
name|QVFbScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|d_ptr
operator|->
name|screenSize
argument_list|()
operator|*
literal|254
operator|)
operator|/
literal|720
return|;
block|}
end_function
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|int QVFbScreen::linestep() const {     return d_ptr->screenImage() ? d_ptr->screenImage()->bytesPerLine() : 0; }  uchar *QVFbScreen::base() const {     return d_ptr->screenImage() ? d_ptr->screenImage()->bits() : 0; }
endif|#
directive|endif
end_endif
begin_function
DECL|function|screenImage
name|QImage
modifier|*
name|QVFbScreen
operator|::
name|screenImage
parameter_list|()
block|{
return|return
name|d_ptr
operator|->
name|screenImage
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QVFbIntegration
name|QVFbIntegration
operator|::
name|QVFbIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|()
argument_list|)
block|{
name|int
name|displayId
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|paramList
operator|.
name|length
argument_list|()
operator|>
literal|0
condition|)
name|displayId
operator|=
name|paramList
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|mPrimaryScreen
operator|=
operator|new
name|QVFbScreen
argument_list|(
name|displayId
argument_list|)
expr_stmt|;
name|mScreens
operator|.
name|append
argument_list|(
name|mPrimaryScreen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QVFbIntegration
operator|::
name|createPlatformPixmap
parameter_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createWindowSurface
name|QWindowSurface
modifier|*
name|QVFbIntegration
operator|::
name|createWindowSurface
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|WId
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QVFbWindowSurface
argument_list|(
name|mPrimaryScreen
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QVFbIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|WId
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QVFbWindow
argument_list|(
name|mPrimaryScreen
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QVFbIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QVFbIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|mFontDb
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qvfbintegration.moc"
end_include
end_unit
