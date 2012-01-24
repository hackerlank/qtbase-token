begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSPINBOX_H
end_ifndef
begin_define
DECL|macro|QSPINBOX_H
define|#
directive|define
name|QSPINBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractspinbox.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
DECL|variable|QSpinBoxPrivate
name|class
name|QSpinBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QSpinBox
range|:
name|public
name|QAbstractSpinBox
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString suffix READ suffix WRITE setSuffix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString prefix READ prefix WRITE setPrefix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString cleanText READ cleanText
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
argument|int singleStep READ singleStep WRITE setSingleStep
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int value READ value WRITE setValue NOTIFY valueChanged USER true
argument_list|)
name|public
operator|:
name|explicit
name|QSpinBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|int
name|value
argument_list|()
specifier|const
block|;
name|QString
name|prefix
argument_list|()
specifier|const
block|;
name|void
name|setPrefix
argument_list|(
specifier|const
name|QString
operator|&
name|prefix
argument_list|)
block|;
name|QString
name|suffix
argument_list|()
specifier|const
block|;
name|void
name|setSuffix
argument_list|(
specifier|const
name|QString
operator|&
name|suffix
argument_list|)
block|;
name|QString
name|cleanText
argument_list|()
specifier|const
block|;
name|int
name|singleStep
argument_list|()
specifier|const
block|;
name|void
name|setSingleStep
argument_list|(
argument|int val
argument_list|)
block|;
name|int
name|minimum
argument_list|()
specifier|const
block|;
name|void
name|setMinimum
argument_list|(
argument|int min
argument_list|)
block|;
name|int
name|maximum
argument_list|()
specifier|const
block|;
name|void
name|setMaximum
argument_list|(
argument|int max
argument_list|)
block|;
name|void
name|setRange
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&input
argument_list|,
argument|int&pos
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|valueFromText
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|textFromValue
argument_list|(
argument|int val
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|fixup
argument_list|(
argument|QString&str
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setValue
argument_list|(
argument|int val
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|valueChanged
argument_list|(
name|int
argument_list|)
block|;
name|void
name|valueChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSpinBox
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSpinBox
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDoubleSpinBoxPrivate
name|class
name|QDoubleSpinBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDoubleSpinBox
range|:
name|public
name|QAbstractSpinBox
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString prefix READ prefix WRITE setPrefix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString suffix READ suffix WRITE setSuffix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString cleanText READ cleanText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int decimals READ decimals WRITE setDecimals
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double minimum READ minimum WRITE setMinimum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double maximum READ maximum WRITE setMaximum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double singleStep READ singleStep WRITE setSingleStep
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double value READ value WRITE setValue NOTIFY valueChanged USER true
argument_list|)
name|public
operator|:
name|explicit
name|QDoubleSpinBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|double
name|value
argument_list|()
specifier|const
block|;
name|QString
name|prefix
argument_list|()
specifier|const
block|;
name|void
name|setPrefix
argument_list|(
specifier|const
name|QString
operator|&
name|prefix
argument_list|)
block|;
name|QString
name|suffix
argument_list|()
specifier|const
block|;
name|void
name|setSuffix
argument_list|(
specifier|const
name|QString
operator|&
name|suffix
argument_list|)
block|;
name|QString
name|cleanText
argument_list|()
specifier|const
block|;
name|double
name|singleStep
argument_list|()
specifier|const
block|;
name|void
name|setSingleStep
argument_list|(
argument|double val
argument_list|)
block|;
name|double
name|minimum
argument_list|()
specifier|const
block|;
name|void
name|setMinimum
argument_list|(
argument|double min
argument_list|)
block|;
name|double
name|maximum
argument_list|()
specifier|const
block|;
name|void
name|setMaximum
argument_list|(
argument|double max
argument_list|)
block|;
name|void
name|setRange
argument_list|(
argument|double min
argument_list|,
argument|double max
argument_list|)
block|;
name|int
name|decimals
argument_list|()
specifier|const
block|;
name|void
name|setDecimals
argument_list|(
argument|int prec
argument_list|)
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&input
argument_list|,
argument|int&pos
argument_list|)
specifier|const
block|;
name|virtual
name|double
name|valueFromText
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|textFromValue
argument_list|(
argument|double val
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|fixup
argument_list|(
argument|QString&str
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setValue
argument_list|(
argument|double val
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|valueChanged
argument_list|(
name|double
argument_list|)
block|;
name|void
name|valueChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDoubleSpinBox
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDoubleSpinBox
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SPINBOX
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
comment|// QSPINBOX_H
end_comment
end_unit
