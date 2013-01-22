begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBUTTONGROUP_H
end_ifndef
begin_define
DECL|macro|QBUTTONGROUP_H
define|#
directive|define
name|QBUTTONGROUP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_BUTTONGROUP
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractButtonPrivate
name|class
name|QAbstractButtonPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QButtonGroupPrivate
name|class
name|QButtonGroupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QButtonGroup
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool exclusive READ exclusive WRITE setExclusive
argument_list|)
name|public
operator|:
name|explicit
name|QButtonGroup
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QButtonGroup
argument_list|()
block|;
name|void
name|setExclusive
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|exclusive
argument_list|()
specifier|const
block|;
name|void
name|addButton
argument_list|(
argument|QAbstractButton *
argument_list|,
argument|int id = -
literal|1
argument_list|)
block|;
name|void
name|removeButton
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
block|;
name|QList
operator|<
name|QAbstractButton
operator|*
operator|>
name|buttons
argument_list|()
specifier|const
block|;
name|QAbstractButton
operator|*
name|checkedButton
argument_list|()
specifier|const
block|;
comment|// no setter on purpose!
name|QAbstractButton
operator|*
name|button
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|void
name|setId
argument_list|(
argument|QAbstractButton *button
argument_list|,
argument|int id
argument_list|)
block|;
name|int
name|id
argument_list|(
argument|QAbstractButton *button
argument_list|)
specifier|const
block|;
name|int
name|checkedId
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|buttonClicked
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
block|;
name|void
name|buttonClicked
argument_list|(
name|int
argument_list|)
block|;
name|void
name|buttonPressed
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
block|;
name|void
name|buttonPressed
argument_list|(
name|int
argument_list|)
block|;
name|void
name|buttonReleased
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
block|;
name|void
name|buttonReleased
argument_list|(
name|int
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QButtonGroup
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QButtonGroup
argument_list|)
name|friend
name|class
name|QAbstractButton
block|;
name|friend
name|class
name|QAbstractButtonPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BUTTONGROUP
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
comment|// QBUTTONGROUP_H
end_comment
end_unit
