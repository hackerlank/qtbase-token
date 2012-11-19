begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformnativeinterface.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformNativeInterface     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformNativeInterface class provides an abstraction for retrieving native     resource handles.  */
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QPlatformNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForScreen
name|void
modifier|*
name|QPlatformNativeInterface
operator|::
name|nativeResourceForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QPlatformNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QPlatformNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForBackingStore
name|void
modifier|*
name|QPlatformNativeInterface
operator|::
name|nativeResourceForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QBackingStore
modifier|*
name|backingStore
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|backingStore
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForIntegration
name|QPlatformNativeInterface
operator|::
name|NativeResourceForIntegrationFunction
name|QPlatformNativeInterface
operator|::
name|nativeResourceFunctionForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QPlatformNativeInterface
operator|::
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForWindow
name|QPlatformNativeInterface
operator|::
name|NativeResourceForWindowFunction
name|QPlatformNativeInterface
operator|::
name|nativeResourceFunctionForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForBackingStore
name|QPlatformNativeInterface
operator|::
name|NativeResourceForBackingStoreFunction
name|QPlatformNativeInterface
operator|::
name|nativeResourceFunctionForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Contains generic window properties that the platform may utilize. */
end_comment
begin_function
DECL|function|windowProperties
name|QVariantMap
name|QPlatformNativeInterface
operator|::
name|windowProperties
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|window
argument_list|)
return|return
name|QVariantMap
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a window property with \a name.      If the property does not exist, returns a default-constructed value. */
end_comment
begin_function
DECL|function|windowProperty
name|QVariant
name|QPlatformNativeInterface
operator|::
name|windowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a window property with \a name. If the value does not exist, defaultValue is returned. */
end_comment
begin_function
DECL|function|windowProperty
name|QVariant
name|QPlatformNativeInterface
operator|::
name|windowProperty
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
name|defaultValue
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|defaultValue
argument_list|)
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets a window property with \a name to \a value. */
end_comment
begin_function
DECL|function|setWindowProperty
name|void
name|QPlatformNativeInterface
operator|::
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
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
