begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMOTIFSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QMOTIFSTYLE_P_H
define|#
directive|define
name|QMOTIFSTYLE_P_H
end_define
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qprogressbar.h>
end_include
begin_include
include|#
directive|include
file|"qmotifstyle.h"
end_include
begin_include
include|#
directive|include
file|"qcommonstyle_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists for the convenience
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
comment|// file may change from version to version without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
comment|// Private class
name|class
name|QMotifStylePrivate
range|:
name|public
name|QCommonStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMotifStyle
argument_list|)
name|public
operator|:
name|QMotifStylePrivate
argument_list|()
block|;
name|public
operator|:
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSBAR
name|QList
operator|<
name|QProgressBar
operator|*
operator|>
name|bars
block|;
name|int
name|animationFps
block|;
name|int
name|animateTimer
block|;
name|QTime
name|startTime
block|;
name|int
name|animateStep
block|;
endif|#
directive|endif
comment|// QT_NO_PROGRESSBAR
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QMOTIFSTYLE_P_H
end_comment
end_unit
