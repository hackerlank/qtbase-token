begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDYNAMICDOCKWIDGET_H
end_ifndef
begin_define
DECL|macro|QDYNAMICDOCKWIDGET_H
define|#
directive|define
name|QDYNAMICDOCKWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
DECL|variable|QDockAreaLayout
name|class
name|QDockAreaLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDockWidgetPrivate
name|class
name|QDockWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|QMainWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionDockWidget
name|class
name|QStyleOptionDockWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDockWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|DockWidgetFeatures
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool floating READ isFloating WRITE setFloating
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|DockWidgetFeatures features READ features WRITE setFeatures NOTIFY featuresChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::DockWidgetAreas allowedAreas READ allowedAreas                WRITE setAllowedAreas NOTIFY allowedAreasChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString windowTitle READ windowTitle WRITE setWindowTitle DESIGNABLE true
argument_list|)
name|public
operator|:
name|explicit
name|QDockWidget
argument_list|(
argument|const QString&title
argument_list|,
argument|QWidget *parent = Q_NULLPTR
argument_list|,
argument|Qt::WindowFlags flags = Qt::WindowFlags()
argument_list|)
block|;
name|explicit
name|QDockWidget
argument_list|(
argument|QWidget *parent = Q_NULLPTR
argument_list|,
argument|Qt::WindowFlags flags = Qt::WindowFlags()
argument_list|)
block|;
operator|~
name|QDockWidget
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|void
name|setWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;      enum
name|DockWidgetFeature
block|{
name|DockWidgetClosable
operator|=
literal|0x01
block|,
name|DockWidgetMovable
operator|=
literal|0x02
block|,
name|DockWidgetFloatable
operator|=
literal|0x04
block|,
name|DockWidgetVerticalTitleBar
operator|=
literal|0x08
block|,
name|DockWidgetFeatureMask
operator|=
literal|0x0f
block|,
name|AllDockWidgetFeatures
operator|=
name|DockWidgetClosable
operator||
name|DockWidgetMovable
operator||
name|DockWidgetFloatable
block|,
comment|// ### Qt 6: remove
name|NoDockWidgetFeatures
operator|=
literal|0x00
block|,
name|Reserved
operator|=
literal|0xff
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|DockWidgetFeatures
argument_list|,
argument|DockWidgetFeature
argument_list|)
name|void
name|setFeatures
argument_list|(
argument|DockWidgetFeatures features
argument_list|)
block|;
name|DockWidgetFeatures
name|features
argument_list|()
specifier|const
block|;
name|void
name|setFloating
argument_list|(
argument|bool floating
argument_list|)
block|;
specifier|inline
name|bool
name|isFloating
argument_list|()
specifier|const
block|{
return|return
name|isWindow
argument_list|()
return|;
block|}
name|void
name|setAllowedAreas
argument_list|(
argument|Qt::DockWidgetAreas areas
argument_list|)
block|;
name|Qt
operator|::
name|DockWidgetAreas
name|allowedAreas
argument_list|()
specifier|const
block|;
name|void
name|setTitleBarWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|titleBarWidget
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|isAreaAllowed
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|)
specifier|const
block|{
return|return
operator|(
name|allowedAreas
argument_list|()
operator|&
name|area
operator|)
operator|==
name|area
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|QAction
operator|*
name|toggleViewAction
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|featuresChanged
argument_list|(
argument|QDockWidget::DockWidgetFeatures features
argument_list|)
block|;
name|void
name|topLevelChanged
argument_list|(
argument|bool topLevel
argument_list|)
block|;
name|void
name|allowedAreasChanged
argument_list|(
argument|Qt::DockWidgetAreas allowedAreas
argument_list|)
block|;
name|void
name|visibilityChanged
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|dockLocationChanged
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|)
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|closeEvent
argument_list|(
argument|QCloseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|event
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionDockWidget *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDockWidget
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDockWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_toggleView(bool)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_toggleTopLevel()
argument_list|)
name|friend
name|class
name|QDockAreaLayout
block|;
name|friend
name|class
name|QDockWidgetItem
block|;
name|friend
name|class
name|QMainWindowLayout
block|;
name|friend
name|class
name|QDockWidgetLayout
block|;
name|friend
name|class
name|QDockAreaLayoutInfo
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDockWidget::DockWidgetFeatures
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DOCKWIDGET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDYNAMICDOCKWIDGET_H
end_comment
end_unit
