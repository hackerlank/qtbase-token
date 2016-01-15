begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSPENDINGCALL_H
end_ifndef
begin_define
DECL|macro|QDBUSPENDINGCALL_H
define|#
directive|define
name|QDBUSPENDINGCALL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
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
begin_include
include|#
directive|include
file|<QtDBus/qdbusmessage.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusConnection
name|class
name|QDBusConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusError
name|class
name|QDBusError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallWatcher
name|class
name|QDBusPendingCallWatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallPrivate
name|class
name|QDBusPendingCallPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusPendingCall
block|{
name|public
label|:
name|QDBusPendingCall
argument_list|(
specifier|const
name|QDBusPendingCall
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDBusPendingCall
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QDBusPendingCall
modifier|&
name|operator
init|=
operator|(
name|QDBusPendingCall
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
name|QDBusPendingCall
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusPendingCall
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QDBusPendingCall
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
ifndef|#
directive|ifndef
name|Q_QDOC
comment|// pretend that they aren't here
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
name|void
name|waitForFinished
parameter_list|()
function_decl|;
name|bool
name|isError
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QDBusError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|QDBusMessage
name|reply
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
specifier|static
name|QDBusPendingCall
name|fromError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|)
function_decl|;
specifier|static
name|QDBusPendingCall
name|fromCompletedCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
name|protected
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QDBusPendingCallPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDBusPendingCallPrivate
decl_stmt|;
name|friend
name|class
name|QDBusPendingCallWatcher
decl_stmt|;
name|friend
name|class
name|QDBusConnection
decl_stmt|;
name|QDBusPendingCall
argument_list|(
name|QDBusPendingCallPrivate
operator|*
name|dd
argument_list|)
expr_stmt|;
name|private
label|:
name|QDBusPendingCall
argument_list|()
expr_stmt|;
comment|// not defined
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QDBusPendingCall
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QDBusPendingCallWatcherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_DBUS_EXPORT
name|QDBusPendingCallWatcher
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QDBusPendingCall
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QDBusPendingCallWatcher
argument_list|(
specifier|const
name|QDBusPendingCall
operator|&
name|call
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
decl_stmt|;
operator|~
name|QDBusPendingCallWatcher
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_QDOC
comment|// trick qdoc into thinking this method is here
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|void
name|waitForFinished
parameter_list|()
function_decl|;
comment|// non-virtual override
name|Q_SIGNALS
label|:
name|void
name|finished
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|self
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDBusPendingCallWatcher
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_finished()
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
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
end_unit
