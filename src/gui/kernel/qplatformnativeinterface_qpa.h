begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMNATIVEINTERFACE_QPA_H
end_ifndef
begin_define
DECL|macro|QPLATFORMNATIVEINTERFACE_QPA_H
define|#
directive|define
name|QPLATFORMNATIVEINTERFACE_QPA_H
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
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBackingStore
name|class
name|QBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformNativeInterface
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
name|void
operator|*
name|nativeResourceForIntegration
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|)
block|;
name|virtual
name|void
operator|*
name|nativeResourceForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|virtual
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|virtual
name|void
operator|*
name|nativeResourceForBackingStore
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QBackingStore
operator|*
name|backingStore
argument_list|)
block|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|NativeResourceForIntegrationFunction
function_decl|)
parameter_list|()
function_decl|;
end_decl_stmt
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|NativeResourceForContextFunction
function_decl|)
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|NativeResourceForWindowFunction
function_decl|)
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|NativeResourceForBackingStoreFunction
function_decl|)
parameter_list|(
name|QBackingStore
modifier|*
name|backingStore
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|virtual
name|NativeResourceForIntegrationFunction
name|nativeResourceFunctionForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|NativeResourceForContextFunction
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|NativeResourceForWindowFunction
name|nativeResourceFunctionForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|NativeResourceForBackingStoreFunction
name|nativeResourceFunctionForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QVariantMap
name|windowProperties
argument_list|(
name|QPlatformWindow
operator|*
name|window
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QVariant
name|windowProperty
argument_list|(
name|QPlatformWindow
operator|*
name|window
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QVariant
name|windowProperty
argument_list|(
name|QPlatformWindow
operator|*
name|window
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QVariant
operator|&
name|defaultValue
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|setWindowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|EventFilter
function_decl|)
parameter_list|(
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|virtual
name|EventFilter
name|setEventFilter
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|EventFilter
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|windowPropertyChanged
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|propertyName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMNATIVEINTERFACE_QPA_H
end_comment
end_unit
