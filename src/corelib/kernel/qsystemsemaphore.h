begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMSEMAPHORE_H
end_ifndef
begin_define
DECL|macro|QSYSTEMSEMAPHORE_H
define|#
directive|define
name|QSYSTEMSEMAPHORE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|class
name|QSystemSemaphorePrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QSystemSemaphore
decl_stmt|{  public:     enum AccessMode
block|{
name|Open
operator|,
name|Create
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|SystemSemaphoreError
block|{
name|NoError
block|,
name|PermissionDenied
block|,
name|KeyError
block|,
name|AlreadyExists
block|,
name|NotFound
block|,
name|OutOfResources
block|,
name|UnknownError
block|}
enum|;
end_enum
begin_macro
name|QSystemSemaphore
argument_list|(
argument|const QString&key
argument_list|,
argument|int initialValue =
literal|0
argument_list|,
argument|AccessMode mode = Open
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QSystemSemaphore
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|int
name|initialValue
init|=
literal|0
parameter_list|,
name|AccessMode
name|mode
init|=
name|Open
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|key
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|acquire
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|release
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|SystemSemaphoreError
name|error
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QSystemSemaphore
argument_list|)
end_macro
begin_expr_stmt
name|QScopedPointer
operator|<
name|QSystemSemaphorePrivate
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMSEMAPHORE_H
end_comment
end_unit
