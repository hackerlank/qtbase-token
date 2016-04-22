begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TABLETWIDGET_H
end_ifndef
begin_define
DECL|macro|TABLETWIDGET_H
define|#
directive|define
name|TABLETWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QTabletEvent>
end_include
begin_comment
comment|// a widget showing the information of the last tablet event
end_comment
begin_decl_stmt
name|class
name|TabletWidget
range|:
name|public
name|QWidget
block|{
name|public
operator|:
name|TabletWidget
argument_list|(
argument|bool mouseToo
argument_list|)
block|;
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
name|QEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|tabletEvent
argument_list|(
name|QTabletEvent
operator|*
name|event
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
specifier|const
name|char
operator|*
name|buttonToString
argument_list|(
argument|Qt::MouseButton b
argument_list|)
block|;
name|QString
name|buttonsToString
argument_list|(
argument|Qt::MouseButtons bs
argument_list|)
block|;
name|private
operator|:
name|void
name|resetAttributes
argument_list|()
block|{
name|mType
operator|=
name|mDev
operator|=
name|mPointerType
operator|=
name|mXT
operator|=
name|mYT
operator|=
name|mZ
operator|=
literal|0
block|;
name|mPress
operator|=
name|mTangential
operator|=
name|mRot
operator|=
literal|0.0
block|;
name|mPos
operator|=
name|mGPos
operator|=
name|QPoint
argument_list|()
block|;
name|mHiResGlobalPos
operator|=
name|QPointF
argument_list|()
block|;
name|mUnique
operator|=
literal|0
block|;     }
name|int
name|mType
block|;
name|QPoint
name|mPos
block|,
name|mGPos
block|;
name|QPointF
name|mHiResGlobalPos
block|;
name|int
name|mDev
block|,
name|mPointerType
block|,
name|mXT
block|,
name|mYT
block|,
name|mZ
block|;
name|Qt
operator|::
name|MouseButton
name|mButton
block|;
name|Qt
operator|::
name|MouseButtons
name|mButtons
block|;
name|qreal
name|mPress
block|,
name|mTangential
block|,
name|mRot
block|;
name|qint64
name|mUnique
block|;
name|bool
name|mMouseToo
block|;
name|ulong
name|mTimestamp
block|;
name|int
name|mWheelEventCount
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TABLETWIDGET_H
end_comment
end_unit
