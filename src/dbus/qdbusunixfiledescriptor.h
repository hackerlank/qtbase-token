begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSUNIXFILEDESCRIPTOR_H
end_ifndef
begin_define
DECL|macro|QDBUSUNIXFILEDESCRIPTOR_H
define|#
directive|define
name|QDBUSUNIXFILEDESCRIPTOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_include
include|#
directive|include
file|<utility>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusUnixFileDescriptorPrivate
name|class
name|QDBusUnixFileDescriptorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusUnixFileDescriptor
block|{
name|public
label|:
name|QDBusUnixFileDescriptor
argument_list|()
expr_stmt|;
name|explicit
name|QDBusUnixFileDescriptor
parameter_list|(
name|int
name|fileDescriptor
parameter_list|)
function_decl|;
name|QDBusUnixFileDescriptor
argument_list|(
specifier|const
name|QDBusUnixFileDescriptor
operator|&
name|other
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_RVALUE_REFS
argument_list|)
name|QDBusUnixFileDescriptor
modifier|&
name|operator
init|=
operator|(
name|QDBusUnixFileDescriptor
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QDBusUnixFileDescriptor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusUnixFileDescriptor
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QDBusUnixFileDescriptor
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDBusUnixFileDescriptor
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|fileDescriptor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFileDescriptor
parameter_list|(
name|int
name|fileDescriptor
parameter_list|)
function_decl|;
name|void
name|giveFileDescriptor
parameter_list|(
name|int
name|fileDescriptor
parameter_list|)
function_decl|;
name|int
name|takeFileDescriptor
parameter_list|()
function_decl|;
specifier|static
name|bool
name|isSupported
parameter_list|()
function_decl|;
name|protected
label|:
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QDBusUnixFileDescriptorPrivate
operator|>
name|Data
expr_stmt|;
name|Data
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QDBusUnixFileDescriptor
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusUnixFileDescriptor
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDBUSUNIXFILEDESCRIPTOR_H
end_comment
end_unit
