begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QCORE_MAC_P_H
define|#
directive|define
name|QCORE_MAC_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
begin_ifndef
ifndef|#
directive|ifndef
name|__IMAGECAPTURE__
end_ifndef
begin_define
DECL|macro|__IMAGECAPTURE__
define|#
directive|define
name|__IMAGECAPTURE__
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_include
include|#
directive|include
file|<Foundation/Foundation.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OBJC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NAMESPACE
argument_list|)
end_if
begin_define
DECL|macro|QT_NAMESPACE_ALIAS_OBJC_CLASS
define|#
directive|define
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|__KLASS__
parameter_list|)
value|@compatibility_alias __KLASS__ QT_MANGLE_NAMESPACE(__KLASS__)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_NAMESPACE_ALIAS_OBJC_CLASS
define|#
directive|define
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|__KLASS__
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*     Helper class that automates refernce counting for CFtypes.     After constructing the QCFType object, it can be copied like a     value-based type.      Note that you must own the object you are wrapping.     This is typically the case if you get the object from a Core     Foundation function with the word "Create" or "Copy" in it. If     you got the object from a "Get" function, either retain it or use     constructFromGet(). One exception to this rule is the     HIThemeGet*Shape functions, which in reality are "Copy" functions. */
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Q_CORE_EXPORT
name|QCFType
block|{
name|public
operator|:
specifier|inline
name|QCFType
argument_list|(
specifier|const
name|T
operator|&
name|t
operator|=
literal|0
argument_list|)
operator|:
name|type
argument_list|(
argument|t
argument_list|)
block|{}
specifier|inline
name|QCFType
argument_list|(
specifier|const
name|QCFType
operator|&
name|helper
argument_list|)
operator|:
name|type
argument_list|(
argument|helper.type
argument_list|)
block|{
if|if
condition|(
name|type
condition|)
name|CFRetain
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
specifier|inline
operator|~
name|QCFType
argument_list|()
block|{
if|if
condition|(
name|type
condition|)
name|CFRelease
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|operator
name|T
parameter_list|()
block|{
return|return
name|type
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QCFType
name|operator
init|=
operator|(
specifier|const
name|QCFType
operator|&
name|helper
operator|)
block|{
if|if
condition|(
name|helper
operator|.
name|type
condition|)
name|CFRetain
argument_list|(
name|helper
operator|.
name|type
argument_list|)
expr_stmt|;
name|CFTypeRef
name|type2
operator|=
name|type
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|type
operator|=
name|helper
operator|.
name|type
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|type2
condition|)
name|CFRelease
argument_list|(
name|type2
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_function
unit|}     inline
name|T
modifier|*
name|operator
function|&()
block|{
return|return
operator|&
name|type
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|X
operator|>
name|X
name|as
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|X
operator|>
operator|(
name|type
operator|)
return|;
block|}
end_expr_stmt
begin_function
specifier|static
name|QCFType
name|constructFromGet
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
name|CFRetain
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
name|QCFType
operator|<
name|T
operator|>
operator|(
name|t
operator|)
return|;
block|}
end_function
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|T
name|type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QCFString
range|:
name|public
name|QCFType
operator|<
name|CFStringRef
operator|>
block|{
name|public
operator|:
specifier|inline
name|QCFString
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
literal|0
operator|)
block|,
name|string
argument_list|(
argument|str
argument_list|)
block|{}
specifier|inline
name|QCFString
argument_list|(
argument|const CFStringRef cfstr =
literal|0
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
name|cfstr
operator|)
block|{}
specifier|inline
name|QCFString
argument_list|(
specifier|const
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|&
name|other
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
name|other
operator|)
block|{}
name|operator
name|QString
argument_list|()
specifier|const
block|;
name|operator
name|CFStringRef
argument_list|()
specifier|const
block|;
specifier|static
name|QString
name|toQString
argument_list|(
argument|CFStringRef cfstr
argument_list|)
block|;
specifier|static
name|CFStringRef
name|toCFStringRef
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
block|;
ifdef|#
directive|ifdef
name|__OBJC__
specifier|static
name|QString
name|toQString
argument_list|(
specifier|const
name|NSString
operator|*
name|nsstr
argument_list|)
block|;
specifier|static
name|NSString
operator|*
name|toNSString
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|QString
name|string
block|; }
decl_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|major
DECL|member|minor
DECL|member|patch
name|int
name|major
decl_stmt|,
name|minor
decl_stmt|,
name|patch
decl_stmt|;
block|}
DECL|typedef|QAppleOperatingSystemVersion
name|QAppleOperatingSystemVersion
typedef|;
end_typedef
begin_function_decl
name|QAppleOperatingSystemVersion
name|qt_apple_os_version
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCORE_MAC_P_H
end_comment
end_unit
