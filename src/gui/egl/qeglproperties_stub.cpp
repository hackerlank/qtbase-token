begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"qeglproperties_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglcontext_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|noegl
specifier|static
name|void
name|noegl
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|)
block|{
name|qWarning
argument_list|()
operator|<<
name|fn
operator|<<
literal|" called, but Qt configured without EGL"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_define
DECL|macro|NOEGL
define|#
directive|define
name|NOEGL
value|noegl(__FUNCTION__);
end_define
begin_comment
comment|// Initialize a property block.
end_comment
begin_constructor
DECL|function|QEglProperties
name|QEglProperties
operator|::
name|QEglProperties
parameter_list|()
block|{
name|NOEGL
block|}
end_constructor
begin_constructor
DECL|function|QEglProperties
name|QEglProperties
operator|::
name|QEglProperties
parameter_list|(
name|EGLConfig
name|cfg
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|cfg
argument_list|)
name|NOEGL
block|}
end_constructor
begin_comment
comment|// Fetch the current value associated with a property.
end_comment
begin_function
DECL|function|value
name|int
name|QEglProperties
operator|::
name|value
parameter_list|(
name|int
name|name
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|name
argument_list|)
name|NOEGL
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|// Set the value associated with a property, replacing an existing
end_comment
begin_comment
comment|// value if there is one.
end_comment
begin_function
DECL|function|setValue
name|void
name|QEglProperties
operator|::
name|setValue
parameter_list|(
name|int
name|name
parameter_list|,
name|int
name|value
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|name
argument_list|)
name|Q_UNUSED
argument_list|(
argument|value
argument_list|)
name|NOEGL
block|}
end_function
begin_comment
comment|// Remove a property value.  Returns false if the property is not present.
end_comment
begin_function
DECL|function|removeValue
name|bool
name|QEglProperties
operator|::
name|removeValue
parameter_list|(
name|int
name|name
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|name
argument_list|)
name|NOEGL
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setDeviceType
name|void
name|QEglProperties
operator|::
name|setDeviceType
parameter_list|(
name|int
name|devType
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|devType
argument_list|)
name|NOEGL
block|}
end_function
begin_comment
comment|// Sets the red, green, blue, and alpha sizes based on a pixel format.
end_comment
begin_comment
comment|// Normally used to match a configuration request to the screen format.
end_comment
begin_function
DECL|function|setPixelFormat
name|void
name|QEglProperties
operator|::
name|setPixelFormat
parameter_list|(
name|QImage
operator|::
name|Format
name|pixelFormat
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|pixelFormat
argument_list|)
name|NOEGL
block|}
end_function
begin_function
DECL|function|setRenderableType
name|void
name|QEglProperties
operator|::
name|setRenderableType
parameter_list|(
name|QEgl
operator|::
name|API
name|api
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|api
argument_list|)
expr_stmt|;
name|NOEGL
block|}
end_function
begin_comment
comment|// Reduce the complexity of a configuration request to ask for less
end_comment
begin_comment
comment|// because the previous request did not result in success.  Returns
end_comment
begin_comment
comment|// true if the complexity was reduced, or false if no further
end_comment
begin_comment
comment|// reductions in complexity are possible.
end_comment
begin_function
DECL|function|reduceConfiguration
name|bool
name|QEglProperties
operator|::
name|reduceConfiguration
parameter_list|()
block|{
name|NOEGL
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// Convert a property list to a string suitable for debug output.
end_comment
begin_function
DECL|function|toString
name|QString
name|QEglProperties
operator|::
name|toString
parameter_list|()
specifier|const
block|{
name|NOEGL
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setPaintDeviceFormat
name|void
name|QEglProperties
operator|::
name|setPaintDeviceFormat
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|dev
argument_list|)
name|NOEGL
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
