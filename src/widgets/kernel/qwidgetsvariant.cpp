begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qsizepolicy.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"private/qvariant_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qmetatype_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
namespace|namespace
block|{
DECL|function|construct
specifier|static
name|void
name|construct
parameter_list|(
name|QVariant
operator|::
name|Private
modifier|*
name|x
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
parameter_list|)
block|{
switch|switch
condition|(
name|x
operator|->
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
name|v_construct
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|x
argument_list|,
name|copy
argument_list|)
expr_stmt|;
break|break;
default|default:
name|qWarning
argument_list|(
literal|"Trying to construct an instance of an invalid type, type id: %i"
argument_list|,
name|x
operator|->
name|type
argument_list|)
expr_stmt|;
name|x
operator|->
name|type
operator|=
name|QVariant
operator|::
name|Invalid
expr_stmt|;
return|return;
block|}
name|x
operator|->
name|is_null
operator|=
operator|!
name|copy
expr_stmt|;
block|}
DECL|function|clear
specifier|static
name|void
name|clear
parameter_list|(
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|)
block|{
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
name|v_clear
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|type
operator|=
name|QVariant
operator|::
name|Invalid
expr_stmt|;
name|d
operator|->
name|is_null
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|is_shared
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|isNull
specifier|static
name|bool
name|isNull
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|compare
specifier|static
name|bool
name|compare
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|a
parameter_list|,
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|b
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|a
operator|->
name|type
operator|==
name|b
operator|->
name|type
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|a
operator|->
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
return|return
operator|*
name|v_cast
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|a
argument_list|)
operator|==
operator|*
name|v_cast
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|b
argument_list|)
return|;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|convert
specifier|static
name|bool
name|convert
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|result
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|result
argument_list|)
expr_stmt|;
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|false
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
DECL|function|streamDebug
specifier|static
name|void
name|streamDebug
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|v
parameter_list|)
block|{
name|QVariant
operator|::
name|Private
modifier|*
name|d
init|=
cast|const_cast
argument_list|<
name|QVariant
operator|::
name|Private
operator|*
argument_list|>
argument_list|(
operator|&
name|v
operator|.
name|data_ptr
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
operator|*
name|v_cast
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
break|break;
default|default:
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QMetaType::Type("
operator|<<
name|d
operator|->
name|type
operator|<<
literal|')'
expr_stmt|;
block|}
block|}
endif|#
directive|endif
DECL|member|widgets_handler
specifier|static
specifier|const
name|QVariant
operator|::
name|Handler
name|widgets_handler
init|=
block|{
name|construct
block|,
name|clear
block|,
name|isNull
block|,
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
literal|0
block|,
literal|0
block|,
endif|#
directive|endif
name|compare
block|,
name|convert
block|,
literal|0
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
name|streamDebug
else|#
directive|else
literal|0
endif|#
directive|endif
block|}
decl_stmt|;
DECL|macro|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
define|#
directive|define
name|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
parameter_list|(
name|MetaTypeName
parameter_list|,
name|MetaTypeId
parameter_list|,
name|RealName
parameter_list|)
define|\
value|QT_METATYPE_INTERFACE_INIT(RealName),
DECL|member|qVariantWidgetsHelper
specifier|static
specifier|const
name|QMetaTypeInterface
name|qVariantWidgetsHelper
index|[]
init|=
block|{
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
argument_list|)
block|}
decl_stmt|;
DECL|macro|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
undef|#
directive|undef
name|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_decl_stmt
specifier|extern
name|Q_CORE_EXPORT
specifier|const
name|QMetaTypeInterface
modifier|*
name|qMetaTypeWidgetsHelper
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qRegisterWidgetsVariant
name|void
name|qRegisterWidgetsVariant
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
expr_stmt|;
name|qMetaTypeWidgetsHelper
operator|=
name|qVariantWidgetsHelper
expr_stmt|;
name|QVariantPrivate
operator|::
name|registerHandler
argument_list|(
name|QModulesPrivate
operator|::
name|Widgets
argument_list|,
operator|&
name|widgets_handler
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
argument|qRegisterWidgetsVariant
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
