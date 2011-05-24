begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROGRESSBAR_H
end_ifndef
begin_define
DECL|macro|QPROGRESSBAR_H
define|#
directive|define
name|QPROGRESSBAR_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSBAR
name|class
name|QProgressBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionProgressBar
name|class
name|QStyleOptionProgressBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QProgressBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Direction
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int minimum READ minimum WRITE setMinimum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maximum READ maximum WRITE setMaximum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int value READ value WRITE setValue NOTIFY valueChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool textVisible READ isTextVisible WRITE setTextVisible
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Orientation orientation READ orientation WRITE setOrientation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool invertedAppearance READ invertedAppearance WRITE setInvertedAppearance
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Direction textDirection READ textDirection WRITE setTextDirection
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString format READ format WRITE setFormat
argument_list|)
name|public
operator|:
expr|enum
name|Direction
block|{
name|TopToBottom
block|,
name|BottomToTop
block|}
block|;
name|explicit
name|QProgressBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|minimum
argument_list|()
specifier|const
block|;
name|int
name|maximum
argument_list|()
specifier|const
block|;
name|int
name|value
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|text
argument_list|()
specifier|const
block|;
name|void
name|setTextVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|isTextVisible
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|setInvertedAppearance
argument_list|(
argument|bool invert
argument_list|)
block|;
name|bool
name|invertedAppearance
argument_list|()
block|;
comment|//### Qt5 make const
name|bool
name|invertedAppearance
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QProgressBar
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|invertedAppearance
argument_list|()
return|;
block|}
name|void
name|setTextDirection
argument_list|(
argument|QProgressBar::Direction textDirection
argument_list|)
block|;
name|QProgressBar
operator|::
name|Direction
name|textDirection
argument_list|()
block|;
comment|//### Qt5 make const
name|QProgressBar
operator|::
name|Direction
name|textDirection
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QProgressBar
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|textDirection
argument_list|()
return|;
block|}
name|void
name|setFormat
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
block|;
name|QString
name|format
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|reset
argument_list|()
block|;
name|void
name|setRange
argument_list|(
argument|int minimum
argument_list|,
argument|int maximum
argument_list|)
block|;
name|void
name|setMinimum
argument_list|(
argument|int minimum
argument_list|)
block|;
name|void
name|setMaximum
argument_list|(
argument|int maximum
argument_list|)
block|;
name|void
name|setValue
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|valueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionProgressBar *option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QProgressBar
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QProgressBar
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROGRESSBAR
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
comment|// QPROGRESSBAR_H
end_comment
end_unit
