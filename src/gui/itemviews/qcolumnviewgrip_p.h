begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLUMNVIEWGRIP_P_H
end_ifndef
begin_define
DECL|macro|QCOLUMNVIEWGRIP_P_H
define|#
directive|define
name|QCOLUMNVIEWGRIP_P_H
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
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QCOLUMNVIEW
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QColumnViewGripPrivate
name|class
name|QColumnViewGripPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QColumnViewGrip
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_SIGNALS
operator|:
name|void
name|gripMoved
argument_list|(
argument|int offset
argument_list|)
block|;
name|public
operator|:
name|explicit
name|QColumnViewGrip
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QColumnViewGrip
argument_list|()
block|;
name|int
name|moveGrip
argument_list|(
argument|int offset
argument_list|)
block|;
name|protected
operator|:
name|QColumnViewGrip
argument_list|(
argument|QColumnViewGripPrivate&
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WFlags f =
literal|0
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QColumnViewGrip
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QColumnViewGrip
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QColumnViewGripPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QColumnViewGrip
argument_list|)
name|public
operator|:
name|QColumnViewGripPrivate
argument_list|()
block|;
operator|~
name|QColumnViewGripPrivate
argument_list|()
block|{}
name|int
name|originalXLocation
block|; }
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
comment|// QT_NO_QCOLUMNVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QCOLUMNVIEWGRIP_P_H
end_comment
end_unit
