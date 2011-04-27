begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCRASHHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QCRASHHANDLER_P_H
define|#
directive|define
name|QCRASHHANDLER_P_H
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
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CRASHHANDLER
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QtCrashHandler
typedef|typedef
name|void
function_decl|(
modifier|*
name|QtCrashHandler
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSegfaultHandler
block|{
name|friend
name|void
name|qt_signal_handler
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|static
name|QtCrashHandler
name|callback
decl_stmt|;
name|public
label|:
specifier|static
name|void
name|initialize
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|inline
specifier|static
name|void
name|installCrashHandler
parameter_list|(
name|QtCrashHandler
name|h
parameter_list|)
block|{
name|callback
operator|=
name|h
expr_stmt|;
block|}
specifier|inline
specifier|static
name|QtCrashHandler
name|crashHandler
parameter_list|()
block|{
return|return
name|callback
return|;
block|}
name|private
label|:
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
comment|// QT_NO_CRASHHANDLER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCRASHHANDLER_P_H
end_comment
end_unit
