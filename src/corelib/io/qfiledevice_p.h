begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDEVICE_P_H
end_ifndef
begin_define
DECL|macro|QFILEDEVICE_P_H
define|#
directive|define
name|QFILEDEVICE_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"private/qiodevice_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractFileEngine
name|class
name|QAbstractFileEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFSFileEngine
name|class
name|QFSFileEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDevicePrivate
range|:
name|public
name|QIODevicePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileDevice
argument_list|)
name|protected
operator|:
name|QFileDevicePrivate
argument_list|()
block|;
operator|~
name|QFileDevicePrivate
argument_list|()
block|;
name|virtual
name|QAbstractFileEngine
operator|*
name|engine
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|ensureFlushed
argument_list|()
specifier|const
block|;
name|bool
name|putCharHelper
argument_list|(
argument|char c
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setError
argument_list|(
argument|QFileDevice::FileError err
argument_list|)
block|;
name|void
name|setError
argument_list|(
argument|QFileDevice::FileError err
argument_list|,
argument|const QString&errorString
argument_list|)
block|;
name|void
name|setError
argument_list|(
argument|QFileDevice::FileError err
argument_list|,
argument|int errNum
argument_list|)
block|;
name|mutable
name|QAbstractFileEngine
operator|*
name|fileEngine
block|;
name|mutable
name|qint64
name|cachedSize
block|;
name|QFileDevice
operator|::
name|FileHandleFlags
name|handleFlags
block|;
name|QFileDevice
operator|::
name|FileError
name|error
block|;
name|bool
name|lastWasWrite
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|ensureFlushed
specifier|inline
name|bool
name|QFileDevicePrivate
operator|::
name|ensureFlushed
argument_list|()
specifier|const
block|{
comment|// This function ensures that the write buffer has been flushed (const
comment|// because certain const functions need to call it.
if|if
condition|(
name|lastWasWrite
condition|)
block|{
name|const_cast
operator|<
name|QFileDevicePrivate
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|lastWasWrite
operator|=
name|false
expr_stmt|;
if|if
condition|(
operator|!
name|const_cast
operator|<
name|QFileDevice
operator|*
operator|>
operator|(
name|q_func
argument_list|()
operator|)
operator|->
name|flush
argument_list|()
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDEVICE_P_H
end_comment
end_unit
