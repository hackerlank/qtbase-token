begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPESWITCHER_P_H
end_ifndef
begin_define
DECL|macro|QMETATYPESWITCHER_P_H
define|#
directive|define
name|QMETATYPESWITCHER_P_H
end_define
begin_include
include|#
directive|include
file|"qmetatype.h"
end_include
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMetaTypeSwitcher
block|{
name|public
label|:
typedef|typedef
name|void
modifier|*
name|UnknownType
typedef|;
name|template
operator|<
name|class
name|ReturnType
operator|,
name|class
name|DelegateObject
operator|>
specifier|static
name|ReturnType
name|switcher
argument_list|(
argument|DelegateObject&logic
argument_list|,
argument|int type
argument_list|,
argument|const void *data
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|QT_METATYPE_SWICHER_CASE_PRIMITIVE
define|#
directive|define
name|QT_METATYPE_SWICHER_CASE_PRIMITIVE
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|case QMetaType::TypeName: return logic.delegate(static_cast<const Name *>(data));
end_define
begin_define
DECL|macro|QT_METATYPE_SWICHER_CASE_PRIMITIVE_POINTER
define|#
directive|define
name|QT_METATYPE_SWICHER_CASE_PRIMITIVE_POINTER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|case QMetaType::TypeName: return logic.delegate(static_cast< Name * const *>(data));
end_define
begin_define
DECL|macro|QT_METATYPE_SWICHER_CASE_POINTER
define|#
directive|define
name|QT_METATYPE_SWICHER_CASE_POINTER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|case QMetaType::TypeName: return logic.delegate(static_cast< QT_PREPEND_NAMESPACE(Name) * const *>(data));
end_define
begin_define
DECL|macro|QT_METATYPE_SWICHER_CASE_QCLASS
define|#
directive|define
name|QT_METATYPE_SWICHER_CASE_QCLASS
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|case QMetaType::TypeName: return logic.delegate(static_cast<const QT_PREPEND_NAMESPACE(Name) *>(data));
end_define
begin_expr_stmt
DECL|variable|ReturnType
name|template
operator|<
name|class
name|ReturnType
operator|,
name|class
name|DelegateObject
operator|>
DECL|function|switcher
name|ReturnType
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|(
argument|DelegateObject&logic
argument_list|,
argument|int type
argument_list|,
argument|const void *data
argument_list|)
block|{
switch|switch
condition|(
name|QMetaType
operator|::
name|Type
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|QT_FOR_EACH_STATIC_PRIMITIVE_TYPE
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_PRIMITIVE
argument_list|)
name|QT_FOR_EACH_STATIC_PRIMITIVE_POINTER
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_PRIMITIVE_POINTER
argument_list|)
name|QT_FOR_EACH_STATIC_CORE_POINTER
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_POINTER
argument_list|)
name|QT_FOR_EACH_STATIC_CORE_CLASS
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_QCLASS
argument_list|)
name|QT_FOR_EACH_STATIC_CORE_TEMPLATE
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_QCLASS
argument_list|)
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_QCLASS
argument_list|)
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_METATYPE_SWICHER_CASE_QCLASS
argument_list|)
default|default:
return|return
name|logic
operator|.
name|delegate
argument_list|(
name|static_cast
operator|<
specifier|const
name|UnknownType
operator|*
operator|>
operator|(
name|data
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_undef
DECL|macro|QT_METATYPE_SWICHER_CASE_PRIMITIVE
unit|}
undef|#
directive|undef
name|QT_METATYPE_SWICHER_CASE_PRIMITIVE
end_undef
begin_undef
DECL|macro|QT_METATYPE_SWICHER_CASE_PRIMITIVE_POINTER
undef|#
directive|undef
name|QT_METATYPE_SWICHER_CASE_PRIMITIVE_POINTER
end_undef
begin_undef
DECL|macro|QT_METATYPE_SWICHER_CASE_QCLASS
undef|#
directive|undef
name|QT_METATYPE_SWICHER_CASE_QCLASS
end_undef
begin_undef
DECL|macro|QT_METATYPE_SWICHER_CASE_POINTER
undef|#
directive|undef
name|QT_METATYPE_SWICHER_CASE_POINTER
end_undef
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPESWITCHER_P_H
end_comment
end_unit
