begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmouselinuxtp_qws.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MOUSE_LINUXTP
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsystem_qws.h"
end_include
begin_include
include|#
directive|include
file|"qsocketnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_qws.h"
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
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
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
file|<termios.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_QWS_IPAQ
argument_list|)
end_if
begin_define
DECL|macro|QT_QWS_IPAQ_RAW
define|#
directive|define
name|QT_QWS_IPAQ_RAW
end_define
begin_define
DECL|macro|QT_QWS_SCREEN_COORDINATES
define|#
directive|define
name|QT_QWS_SCREEN_COORDINATES
end_define
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pressure
name|unsigned
name|short
name|pressure
decl_stmt|;
DECL|member|x
name|unsigned
name|short
name|x
decl_stmt|;
DECL|member|y
name|unsigned
name|short
name|y
decl_stmt|;
DECL|member|pad
name|unsigned
name|short
name|pad
decl_stmt|;
DECL|typedef|TS_EVENT
block|}
name|TS_EVENT
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|QT_QWS_EBX
argument_list|)
end_elif
begin_define
define|#
directive|define
name|QT_QWS_EBX_RAW
end_define
begin_define
define|#
directive|define
name|QT_QWS_SCREEN_COORDINATES
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_SHARP
end_ifndef
begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|pressure
decl_stmt|;
name|unsigned
name|short
name|x
decl_stmt|;
name|unsigned
name|short
name|y
decl_stmt|;
name|unsigned
name|short
name|pad
decl_stmt|;
block|}
name|TS_EVENT
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|y
decl_stmt|;
name|long
name|x
decl_stmt|;
name|long
name|pressure
decl_stmt|;
name|long
name|long
name|millisecs
decl_stmt|;
block|}
name|TS_EVENT
typedef|;
end_typedef
begin_define
define|#
directive|define
name|QT_QWS_TP_SAMPLE_SIZE
value|10
end_define
begin_define
define|#
directive|define
name|QT_QWS_TP_MINIMUM_SAMPLES
value|4
end_define
begin_define
define|#
directive|define
name|QT_QWS_TP_PRESSURE_THRESHOLD
value|500
end_define
begin_define
define|#
directive|define
name|QT_QWS_TP_MOVE_LIMIT
value|50
end_define
begin_define
define|#
directive|define
name|QT_QWS_TP_JITTER_LIMIT
value|2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// not IPAQ, not SHARP
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|pressure
decl_stmt|;
name|unsigned
name|short
name|x
decl_stmt|;
name|unsigned
name|short
name|y
decl_stmt|;
name|unsigned
name|short
name|pad
decl_stmt|;
block|}
name|TS_EVENT
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_TP_SAMPLE_SIZE
end_ifndef
begin_define
DECL|macro|QT_QWS_TP_SAMPLE_SIZE
define|#
directive|define
name|QT_QWS_TP_SAMPLE_SIZE
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_TP_MINIMUM_SAMPLES
end_ifndef
begin_define
DECL|macro|QT_QWS_TP_MINIMUM_SAMPLES
define|#
directive|define
name|QT_QWS_TP_MINIMUM_SAMPLES
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_TP_PRESSURE_THRESHOLD
end_ifndef
begin_define
DECL|macro|QT_QWS_TP_PRESSURE_THRESHOLD
define|#
directive|define
name|QT_QWS_TP_PRESSURE_THRESHOLD
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_TP_MOVE_LIMIT
end_ifndef
begin_define
DECL|macro|QT_QWS_TP_MOVE_LIMIT
define|#
directive|define
name|QT_QWS_TP_MOVE_LIMIT
value|100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_TP_JITTER_LIMIT
end_ifndef
begin_define
DECL|macro|QT_QWS_TP_JITTER_LIMIT
define|#
directive|define
name|QT_QWS_TP_JITTER_LIMIT
value|2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QWSLinuxTPMouseHandlerPrivate
class|class
name|QWSLinuxTPMouseHandlerPrivate
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|QWSLinuxTPMouseHandlerPrivate
parameter_list|(
name|QWSLinuxTPMouseHandler
modifier|*
name|h
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
constructor_decl|;
name|~
name|QWSLinuxTPMouseHandlerPrivate
parameter_list|()
destructor_decl|;
name|void
name|suspend
parameter_list|()
function_decl|;
name|void
name|resume
parameter_list|()
function_decl|;
private|private:
DECL|member|mouseBufSize
specifier|static
specifier|const
name|int
name|mouseBufSize
init|=
literal|2048
decl_stmt|;
DECL|member|mouseFD
name|int
name|mouseFD
decl_stmt|;
DECL|member|oldmouse
name|QPoint
name|oldmouse
decl_stmt|;
DECL|member|oldTotalMousePos
name|QPoint
name|oldTotalMousePos
decl_stmt|;
DECL|member|waspressed
name|bool
name|waspressed
decl_stmt|;
DECL|member|samples
name|QPolygon
name|samples
decl_stmt|;
DECL|member|currSample
name|int
name|currSample
decl_stmt|;
DECL|member|lastSample
name|int
name|lastSample
decl_stmt|;
DECL|member|numSamples
name|int
name|numSamples
decl_stmt|;
DECL|member|skipCount
name|int
name|skipCount
decl_stmt|;
DECL|member|mouseIdx
name|int
name|mouseIdx
decl_stmt|;
DECL|member|mouseBuf
name|uchar
name|mouseBuf
index|[
name|mouseBufSize
index|]
decl_stmt|;
DECL|member|handler
name|QWSLinuxTPMouseHandler
modifier|*
name|handler
decl_stmt|;
DECL|member|mouseNotifier
name|QSocketNotifier
modifier|*
name|mouseNotifier
decl_stmt|;
private|private
name|slots
private|:
name|void
name|readMouseData
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWSLinuxTPMouseHandler
name|QWSLinuxTPMouseHandler
operator|::
name|QWSLinuxTPMouseHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|driver
parameter_list|,
specifier|const
name|QString
modifier|&
name|device
parameter_list|)
member_init_list|:
name|QWSCalibratedMouseHandler
argument_list|(
name|driver
argument_list|,
name|device
argument_list|)
block|{
name|d
operator|=
operator|new
name|QWSLinuxTPMouseHandlerPrivate
argument_list|(
name|this
argument_list|,
name|device
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWSLinuxTPMouseHandler
name|QWSLinuxTPMouseHandler
operator|::
name|~
name|QWSLinuxTPMouseHandler
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|suspend
name|void
name|QWSLinuxTPMouseHandler
operator|::
name|suspend
parameter_list|()
block|{
name|d
operator|->
name|suspend
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resume
name|void
name|QWSLinuxTPMouseHandler
operator|::
name|resume
parameter_list|()
block|{
name|d
operator|->
name|resume
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWSLinuxTPMouseHandlerPrivate
name|QWSLinuxTPMouseHandlerPrivate
operator|::
name|QWSLinuxTPMouseHandlerPrivate
parameter_list|(
name|QWSLinuxTPMouseHandler
modifier|*
name|h
parameter_list|,
specifier|const
name|QString
modifier|&
name|device
parameter_list|)
member_init_list|:
name|samples
argument_list|(
name|QT_QWS_TP_SAMPLE_SIZE
argument_list|)
member_init_list|,
name|currSample
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lastSample
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|numSamples
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|skipCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|handler
argument_list|(
name|h
argument_list|)
block|{
name|QString
name|mousedev
decl_stmt|;
if|if
condition|(
name|device
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_QWS_IPAQ
argument_list|)
ifdef|#
directive|ifdef
name|QT_QWS_IPAQ_RAW
name|mousedev
operator|=
name|QLatin1String
argument_list|(
literal|"/dev/h3600_tsraw"
argument_list|)
expr_stmt|;
else|#
directive|else
name|mousedev
operator|=
name|QLatin1String
argument_list|(
literal|"/dev/h3600_ts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|mousedev
operator|=
name|QLatin1String
argument_list|(
literal|"/dev/ts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|mousedev
operator|=
name|device
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|mouseFD
operator|=
name|QT_OPEN
argument_list|(
name|mousedev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDONLY
operator||
name|O_NDELAY
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot open %s (%s)"
argument_list|,
name|qPrintable
argument_list|(
name|mousedev
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|waspressed
operator|=
literal|false
expr_stmt|;
name|mouseIdx
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWSLinuxTPMouseHandlerPrivate
name|QWSLinuxTPMouseHandlerPrivate
operator|::
name|~
name|QWSLinuxTPMouseHandlerPrivate
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
DECL|function|suspend
name|void
name|QWSLinuxTPMouseHandlerPrivate
operator|::
name|suspend
parameter_list|()
block|{
if|if
condition|(
name|mouseNotifier
condition|)
name|mouseNotifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resume
name|void
name|QWSLinuxTPMouseHandlerPrivate
operator|::
name|resume
parameter_list|()
block|{
name|mouseIdx
operator|=
literal|0
expr_stmt|;
name|currSample
operator|=
literal|0
expr_stmt|;
name|lastSample
operator|=
literal|0
expr_stmt|;
name|numSamples
operator|=
literal|0
expr_stmt|;
name|skipCount
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mouseNotifier
condition|)
name|mouseNotifier
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readMouseData
name|void
name|QWSLinuxTPMouseHandlerPrivate
operator|::
name|readMouseData
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qt_screen
condition|)
return|return;
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
operator|&&
name|mouseIdx
operator|<
name|mouseBufSize
condition|)
do|;
comment|//qDebug("readMouseData()");
name|TS_EVENT
modifier|*
name|data
decl_stmt|;
name|int
name|idx
init|=
literal|0
decl_stmt|;
comment|// perhaps we shouldn't be reading EVERY SAMPLE.
while|while
condition|(
name|mouseIdx
operator|-
name|idx
operator|>=
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|TS_EVENT
argument_list|)
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
name|data
operator|=
operator|(
name|TS_EVENT
operator|*
operator|)
name|mb
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|pressure
operator|>=
name|QT_QWS_TP_PRESSURE_THRESHOLD
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QWS_SHARP
name|samples
index|[
name|currSample
index|]
operator|=
name|QPoint
argument_list|(
literal|1000
operator|-
name|data
operator|->
name|x
argument_list|,
name|data
operator|->
name|y
argument_list|)
expr_stmt|;
else|#
directive|else
name|samples
index|[
name|currSample
index|]
operator|=
name|QPoint
argument_list|(
name|data
operator|->
name|x
argument_list|,
name|data
operator|->
name|y
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|numSamples
operator|++
expr_stmt|;
if|if
condition|(
name|numSamples
operator|>=
name|QT_QWS_TP_MINIMUM_SAMPLES
condition|)
block|{
name|int
name|sampleCount
init|=
name|qMin
argument_list|(
name|numSamples
operator|+
literal|1
argument_list|,
name|samples
operator|.
name|count
argument_list|()
argument_list|)
decl_stmt|;
comment|// average the rest
name|QPoint
name|mousePos
init|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QPoint
name|totalMousePos
init|=
name|oldTotalMousePos
decl_stmt|;
name|totalMousePos
operator|+=
name|samples
index|[
name|currSample
index|]
expr_stmt|;
if|if
condition|(
name|numSamples
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|totalMousePos
operator|-=
name|samples
index|[
name|lastSample
index|]
expr_stmt|;
name|mousePos
operator|=
name|totalMousePos
operator|/
operator|(
name|sampleCount
operator|-
literal|1
operator|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_QWS_SCREEN_COORDINATES
argument_list|)
name|mousePos
operator|=
name|handler
operator|->
name|transform
argument_list|(
name|mousePos
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|waspressed
condition|)
name|oldmouse
operator|=
name|mousePos
expr_stmt|;
name|QPoint
name|dp
init|=
name|mousePos
operator|-
name|oldmouse
decl_stmt|;
name|int
name|dxSqr
init|=
name|dp
operator|.
name|x
argument_list|()
operator|*
name|dp
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|dySqr
init|=
name|dp
operator|.
name|y
argument_list|()
operator|*
name|dp
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
name|dxSqr
operator|+
name|dySqr
operator|<
operator|(
name|QT_QWS_TP_MOVE_LIMIT
operator|*
name|QT_QWS_TP_MOVE_LIMIT
operator|)
condition|)
block|{
if|if
condition|(
name|waspressed
condition|)
block|{
if|if
condition|(
operator|(
name|dxSqr
operator|+
name|dySqr
operator|>
operator|(
name|QT_QWS_TP_JITTER_LIMIT
operator|*
name|QT_QWS_TP_JITTER_LIMIT
operator|)
operator|)
operator|||
name|skipCount
operator|>
literal|2
condition|)
block|{
name|handler
operator|->
name|mouseChanged
argument_list|(
name|mousePos
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|oldmouse
operator|=
name|mousePos
expr_stmt|;
name|skipCount
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|skipCount
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
name|handler
operator|->
name|mouseChanged
argument_list|(
name|mousePos
argument_list|,
name|Qt
operator|::
name|LeftButton
argument_list|)
expr_stmt|;
name|oldmouse
operator|=
name|mousePos
expr_stmt|;
name|waspressed
operator|=
literal|true
expr_stmt|;
block|}
comment|// save recuring information
name|currSample
operator|++
expr_stmt|;
if|if
condition|(
name|numSamples
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|lastSample
operator|++
expr_stmt|;
name|oldTotalMousePos
operator|=
name|totalMousePos
expr_stmt|;
block|}
else|else
block|{
name|numSamples
operator|--
expr_stmt|;
comment|// don't use this sample, it was bad.
block|}
block|}
else|else
block|{
comment|// build up the average
name|oldTotalMousePos
operator|+=
name|samples
index|[
name|currSample
index|]
expr_stmt|;
name|currSample
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|currSample
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|currSample
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|lastSample
operator|>=
name|samples
operator|.
name|count
argument_list|()
condition|)
name|lastSample
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|currSample
operator|=
literal|0
expr_stmt|;
name|lastSample
operator|=
literal|0
expr_stmt|;
name|numSamples
operator|=
literal|0
expr_stmt|;
name|skipCount
operator|=
literal|0
expr_stmt|;
name|oldTotalMousePos
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|waspressed
condition|)
block|{
name|handler
operator|->
name|mouseChanged
argument_list|(
name|oldmouse
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|oldmouse
operator|=
name|QPoint
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
name|waspressed
operator|=
literal|false
expr_stmt|;
block|}
block|}
name|idx
operator|+=
sizeof|sizeof
argument_list|(
name|TS_EVENT
argument_list|)
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qmouselinuxtp_qws.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_QWS_MOUSE_LINUXTP
end_comment
end_unit
