begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDESKTOPWIDGET_H
end_ifndef
begin_define
DECL|macro|QDESKTOPWIDGET_H
define|#
directive|define
name|QDESKTOPWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QApplication
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDesktopWidgetPrivate
name|class
name|QDesktopWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDesktopWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool virtualDesktop READ isVirtualDesktop
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int screenCount READ screenCount NOTIFY screenCountChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int primaryScreen READ primaryScreen
argument_list|)
name|public
operator|:
name|QDesktopWidget
argument_list|()
block|;
operator|~
name|QDesktopWidget
argument_list|()
block|;
name|bool
name|isVirtualDesktop
argument_list|()
specifier|const
block|;
name|int
name|numScreens
argument_list|()
specifier|const
block|;
name|int
name|screenCount
argument_list|()
specifier|const
block|;
name|int
name|primaryScreen
argument_list|()
specifier|const
block|;
name|int
name|screenNumber
argument_list|(
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|screenNumber
argument_list|(
argument|const QPoint&
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|screen
argument_list|(
argument|int screen = -
literal|1
argument_list|)
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|screenGeometry
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|screenGeometry
argument_list|(
name|screenNumber
argument_list|(
name|point
argument_list|)
argument_list|)
return|;
block|}
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|availableGeometry
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|availableGeometry
argument_list|(
name|screenNumber
argument_list|(
name|point
argument_list|)
argument_list|)
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|resized
argument_list|(
name|int
argument_list|)
block|;
name|void
name|workAreaResized
argument_list|(
name|int
argument_list|)
block|;
name|void
name|screenCountChanged
argument_list|(
name|int
argument_list|)
block|;
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDesktopWidget
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDesktopWidget
argument_list|)
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QApplicationPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|screenCount
specifier|inline
name|int
name|QDesktopWidget
operator|::
name|screenCount
argument_list|()
specifier|const
block|{
return|return
name|numScreens
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDESKTOPWIDGET_H
end_comment
end_unit
