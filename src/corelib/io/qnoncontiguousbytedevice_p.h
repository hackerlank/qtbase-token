begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNONCONTIGUOUSBYTEDEVICE_H
end_ifndef
begin_define
DECL|macro|QNONCONTIGUOUSBYTEDEVICE_H
define|#
directive|define
name|QNONCONTIGUOUSBYTEDEVICE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of a number of Qt sources files.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QNonContiguousByteDevice
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 amount
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|atEnd
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|reset
argument_list|()
operator|=
literal|0
block|;
name|void
name|disableReset
argument_list|()
block|;
name|bool
name|isResetDisabled
argument_list|()
block|{
return|return
name|resetDisabled
return|;
block|}
name|virtual
name|qint64
name|size
argument_list|()
operator|=
literal|0
block|;
name|virtual
operator|~
name|QNonContiguousByteDevice
argument_list|()
block|;
name|protected
operator|:
name|QNonContiguousByteDevice
argument_list|()
block|;
name|bool
name|resetDisabled
block|;
name|Q_SIGNALS
operator|:
name|void
name|readyRead
argument_list|()
block|;
name|void
name|readProgress
argument_list|(
argument|qint64 current
argument_list|,
argument|qint64 total
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QNonContiguousByteDeviceFactory
block|{
name|public
label|:
specifier|static
name|QNonContiguousByteDevice
modifier|*
name|create
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
specifier|static
name|QNonContiguousByteDevice
modifier|*
name|create
parameter_list|(
name|QByteArray
modifier|*
name|byteArray
parameter_list|)
function_decl|;
specifier|static
name|QNonContiguousByteDevice
modifier|*
name|create
argument_list|(
name|QSharedPointer
operator|<
name|QRingBuffer
operator|>
name|ringBuffer
argument_list|)
decl_stmt|;
specifier|static
name|QIODevice
modifier|*
name|wrap
parameter_list|(
name|QNonContiguousByteDevice
modifier|*
name|byteDevice
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// the actual implementations
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|QNonContiguousByteDeviceByteArrayImpl
range|:
name|public
name|QNonContiguousByteDevice
block|{
name|public
operator|:
name|QNonContiguousByteDeviceByteArrayImpl
argument_list|(
name|QByteArray
operator|*
name|ba
argument_list|)
block|;
operator|~
name|QNonContiguousByteDeviceByteArrayImpl
argument_list|()
block|;
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
block|;
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 amount
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
block|;
name|bool
name|reset
argument_list|()
block|;
name|qint64
name|size
argument_list|()
block|;
name|protected
operator|:
name|QByteArray
operator|*
name|byteArray
block|;
name|qint64
name|currentPosition
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNonContiguousByteDeviceRingBufferImpl
range|:
name|public
name|QNonContiguousByteDevice
block|{
name|public
operator|:
name|QNonContiguousByteDeviceRingBufferImpl
argument_list|(
name|QSharedPointer
operator|<
name|QRingBuffer
operator|>
name|rb
argument_list|)
block|;
operator|~
name|QNonContiguousByteDeviceRingBufferImpl
argument_list|()
block|;
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
block|;
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 amount
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
block|;
name|bool
name|reset
argument_list|()
block|;
name|qint64
name|size
argument_list|()
block|;
name|protected
operator|:
name|QSharedPointer
operator|<
name|QRingBuffer
operator|>
name|ringBuffer
block|;
name|qint64
name|currentPosition
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNonContiguousByteDeviceIoDeviceImpl
range|:
name|public
name|QNonContiguousByteDevice
block|{
name|Q_OBJECT
name|public
operator|:
name|QNonContiguousByteDeviceIoDeviceImpl
argument_list|(
name|QIODevice
operator|*
name|d
argument_list|)
block|;
operator|~
name|QNonContiguousByteDeviceIoDeviceImpl
argument_list|()
block|;
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
block|;
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 amount
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
block|;
name|bool
name|reset
argument_list|()
block|;
name|qint64
name|size
argument_list|()
block|;
name|protected
operator|:
name|QIODevice
operator|*
name|device
block|;
name|QByteArray
operator|*
name|currentReadBuffer
block|;
name|qint64
name|currentReadBufferSize
block|;
name|qint64
name|currentReadBufferAmount
block|;
name|qint64
name|currentReadBufferPosition
block|;
name|qint64
name|totalAdvancements
block|;
name|bool
name|eof
block|;
name|qint64
name|initialPosition
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNonContiguousByteDeviceBufferImpl
range|:
name|public
name|QNonContiguousByteDevice
block|{
name|Q_OBJECT
name|public
operator|:
name|QNonContiguousByteDeviceBufferImpl
argument_list|(
name|QBuffer
operator|*
name|b
argument_list|)
block|;
operator|~
name|QNonContiguousByteDeviceBufferImpl
argument_list|()
block|;
specifier|const
name|char
operator|*
name|readPointer
argument_list|(
argument|qint64 maximumLength
argument_list|,
argument|qint64&len
argument_list|)
block|;
name|bool
name|advanceReadPointer
argument_list|(
argument|qint64 amount
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
block|;
name|bool
name|reset
argument_list|()
block|;
name|qint64
name|size
argument_list|()
block|;
name|protected
operator|:
name|QBuffer
operator|*
name|buffer
block|;
name|QByteArray
name|byteArray
block|;
name|QNonContiguousByteDeviceByteArrayImpl
operator|*
name|arrayImpl
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ... and the reverse thing
end_comment
begin_decl_stmt
name|class
name|QByteDeviceWrappingIoDevice
range|:
name|public
name|QIODevice
block|{
name|public
operator|:
name|QByteDeviceWrappingIoDevice
argument_list|(
name|QNonContiguousByteDevice
operator|*
name|bd
argument_list|)
block|;
operator|~
name|QByteDeviceWrappingIoDevice
argument_list|()
block|;
name|virtual
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|reset
argument_list|()
block|;
name|virtual
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|qint64
name|readData
argument_list|(
argument|char * data
argument_list|,
argument|qint64 maxSize
argument_list|)
block|;
name|virtual
name|qint64
name|writeData
argument_list|(
argument|const char * data
argument_list|,
argument|qint64 maxSize
argument_list|)
block|;
name|QNonContiguousByteDevice
operator|*
name|byteDevice
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
