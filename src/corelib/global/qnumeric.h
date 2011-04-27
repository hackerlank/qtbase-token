begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNUMERIC_H
end_ifndef
begin_define
DECL|macro|QNUMERIC_H
define|#
directive|define
name|QNUMERIC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|Q_CORE_EXPORT
name|bool
name|qIsInf
argument_list|(
name|double
name|d
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
DECL|variable|qIsNaN
name|Q_CORE_EXPORT
name|bool
name|qIsNaN
parameter_list|(
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|qIsFinite
parameter_list|(
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|qIsInf
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|qIsNaN
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|qIsFinite
parameter_list|(
name|float
name|f
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|double
name|qSNaN
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|double
name|qQNaN
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|double
name|qInf
parameter_list|()
function_decl|;
end_function_decl
begin_define
DECL|macro|Q_INFINITY
define|#
directive|define
name|Q_INFINITY
value|(QT_PREPEND_NAMESPACE(qInf)())
end_define
begin_define
DECL|macro|Q_SNAN
define|#
directive|define
name|Q_SNAN
value|(QT_PREPEND_NAMESPACE(qSNaN)())
end_define
begin_define
DECL|macro|Q_QNAN
define|#
directive|define
name|Q_QNAN
value|(QT_PREPEND_NAMESPACE(qQNaN)())
end_define
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNUMERIC_H
end_comment
end_unit
