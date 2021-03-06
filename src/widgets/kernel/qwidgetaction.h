begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETACTION_H
end_ifndef
begin_define
DECL|macro|QWIDGETACTION_H
define|#
directive|define
name|QWIDGETACTION_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaction.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACTION
DECL|variable|QWidgetActionPrivate
name|class
name|QWidgetActionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWidgetAction
range|:
name|public
name|QAction
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWidgetAction
argument_list|)
name|public
operator|:
name|explicit
name|QWidgetAction
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|QWidgetAction
argument_list|()
block|;
name|void
name|setDefaultWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QWidget
operator|*
name|defaultWidget
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|requestWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|releaseWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|eventFilter
argument_list|(
argument|QObject *
argument_list|,
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QWidget
operator|*
name|createWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|virtual
name|void
name|deleteWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|createdWidgets
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWidgetAction
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_widgetDestroyed(QObject *)
argument_list|)
name|friend
name|class
name|QToolBar
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWIDGETACTION_H
end_comment
end_unit
