begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSINTROSPECTION_P_H
end_ifndef
begin_define
DECL|macro|QDBUSINTROSPECTION_P_H
define|#
directive|define
name|QDBUSINTROSPECTION_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|"qdbusmacros.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_DBUS_EXPORT
name|QDBusIntrospection
block|{
name|public
label|:
comment|// forward declarations
struct_decl|struct
name|Argument
struct_decl|;
struct_decl|struct
name|Method
struct_decl|;
struct_decl|struct
name|Signal
struct_decl|;
struct_decl|struct
name|Property
struct_decl|;
struct_decl|struct
name|Interface
struct_decl|;
struct_decl|struct
name|Object
struct_decl|;
struct_decl|struct
name|ObjectTree
struct_decl|;
comment|// typedefs
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|Annotations
expr_stmt|;
typedef|typedef
name|QVector
operator|<
name|Argument
operator|>
name|Arguments
expr_stmt|;
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|Method
operator|>
name|Methods
expr_stmt|;
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|Signal
operator|>
name|Signals
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|Property
operator|>
name|Properties
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QSharedDataPointer
operator|<
name|Interface
operator|>
expr|>
name|Interfaces
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QSharedDataPointer
operator|<
name|ObjectTree
operator|>
expr|>
name|Objects
expr_stmt|;
name|public
label|:
comment|// the structs
struct|struct
name|Argument
block|{
name|QString
name|type
decl_stmt|;
name|QString
name|name
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Argument
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|name
operator|==
name|other
operator|.
name|name
operator|&&
name|type
operator|==
name|other
operator|.
name|type
return|;
block|}
block|}
struct|;
struct|struct
name|Method
block|{
name|QString
name|name
decl_stmt|;
name|Arguments
name|inputArgs
decl_stmt|;
name|Arguments
name|outputArgs
decl_stmt|;
name|Annotations
name|annotations
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Method
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|name
operator|==
name|other
operator|.
name|name
operator|&&
name|annotations
operator|==
name|other
operator|.
name|annotations
operator|&&
name|inputArgs
operator|==
name|other
operator|.
name|inputArgs
operator|&&
name|outputArgs
operator|==
name|other
operator|.
name|outputArgs
return|;
block|}
block|}
struct|;
struct|struct
name|Signal
block|{
name|QString
name|name
decl_stmt|;
name|Arguments
name|outputArgs
decl_stmt|;
name|Annotations
name|annotations
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Signal
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|name
operator|==
name|other
operator|.
name|name
operator|&&
name|annotations
operator|==
name|other
operator|.
name|annotations
operator|&&
name|outputArgs
operator|==
name|other
operator|.
name|outputArgs
return|;
block|}
block|}
struct|;
struct|struct
name|Property
block|{
enum|enum
name|Access
block|{
name|Read
block|,
name|Write
block|,
name|ReadWrite
block|}
enum|;
name|QString
name|name
decl_stmt|;
name|QString
name|type
decl_stmt|;
name|Access
name|access
decl_stmt|;
name|Annotations
name|annotations
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Property
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|access
operator|==
name|other
operator|.
name|access
operator|&&
name|name
operator|==
name|other
operator|.
name|name
operator|&&
name|annotations
operator|==
name|other
operator|.
name|annotations
operator|&&
name|type
operator|==
name|other
operator|.
name|type
return|;
block|}
block|}
struct|;
name|struct
name|Interface
range|:
name|public
name|QSharedData
block|{
name|QString
name|name
block|;
name|QString
name|introspection
block|;
name|Annotations
name|annotations
block|;
name|Methods
name|methods
block|;
name|Signals
name|signals_
block|;
name|Properties
name|properties
block|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Interface
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|name
operator|.
name|isEmpty
argument_list|()
operator|&&
name|name
operator|==
name|other
operator|.
name|name
return|;
block|}
expr|}
block|;      struct
name|Object
operator|:
name|public
name|QSharedData
block|{
name|QString
name|service
block|;
name|QString
name|path
block|;
name|QStringList
name|interfaces
block|;
name|QStringList
name|childObjects
block|;     }
block|;
name|public
operator|:
specifier|static
name|Interface
name|parseInterface
argument_list|(
specifier|const
name|QString
operator|&
name|xml
argument_list|)
block|;
specifier|static
name|Interfaces
name|parseInterfaces
argument_list|(
specifier|const
name|QString
operator|&
name|xml
argument_list|)
block|;
specifier|static
name|Object
name|parseObject
argument_list|(
specifier|const
name|QString
operator|&
name|xml
argument_list|,
specifier|const
name|QString
operator|&
name|service
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|path
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|private
operator|:
name|QDBusIntrospection
argument_list|()
block|; }
decl_stmt|;
name|QT_END_NAMESPACE
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
end_unit
