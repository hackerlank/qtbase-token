begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSPINBOX_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSPINBOX_H
define|#
directive|define
name|QABSTRACTSPINBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvalidator.h>
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
name|QT_NO_SPINBOX
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSpinBoxPrivate
name|class
name|QAbstractSpinBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionSpinBox
name|class
name|QStyleOptionSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAbstractSpinBox
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|ButtonSymbols
argument_list|)
name|Q_ENUMS
argument_list|(
argument|CorrectionMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wrapping READ wrapping WRITE setWrapping
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool frame READ hasFrame WRITE setFrame
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ButtonSymbols buttonSymbols READ buttonSymbols WRITE setButtonSymbols
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString specialValueText READ specialValueText WRITE setSpecialValueText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool accelerated READ isAccelerated WRITE setAccelerated
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|CorrectionMode correctionMode READ correctionMode WRITE setCorrectionMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool acceptableInput READ hasAcceptableInput
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool keyboardTracking READ keyboardTracking WRITE setKeyboardTracking
argument_list|)
name|public
operator|:
name|explicit
name|QAbstractSpinBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAbstractSpinBox
argument_list|()
block|;      enum
name|StepEnabledFlag
block|{
name|StepNone
operator|=
literal|0x00
block|,
name|StepUpEnabled
operator|=
literal|0x01
block|,
name|StepDownEnabled
operator|=
literal|0x02
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|StepEnabled
argument_list|,
name|StepEnabledFlag
argument_list|)
expr|enum
name|ButtonSymbols
block|{
name|UpDownArrows
block|,
name|PlusMinus
block|,
name|NoButtons
block|}
block|;
name|ButtonSymbols
name|buttonSymbols
argument_list|()
specifier|const
block|;
name|void
name|setButtonSymbols
argument_list|(
argument|ButtonSymbols bs
argument_list|)
block|;      enum
name|CorrectionMode
block|{
name|CorrectToPreviousValue
block|,
name|CorrectToNearestValue
block|}
block|;
name|void
name|setCorrectionMode
argument_list|(
argument|CorrectionMode cm
argument_list|)
block|;
name|CorrectionMode
name|correctionMode
argument_list|()
specifier|const
block|;
name|bool
name|hasAcceptableInput
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|()
specifier|const
block|;
name|QString
name|specialValueText
argument_list|()
specifier|const
block|;
name|void
name|setSpecialValueText
argument_list|(
specifier|const
name|QString
operator|&
name|txt
argument_list|)
block|;
name|bool
name|wrapping
argument_list|()
specifier|const
block|;
name|void
name|setWrapping
argument_list|(
argument|bool w
argument_list|)
block|;
name|void
name|setReadOnly
argument_list|(
argument|bool r
argument_list|)
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setKeyboardTracking
argument_list|(
argument|bool kt
argument_list|)
block|;
name|bool
name|keyboardTracking
argument_list|()
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
argument|Qt::Alignment flag
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|setFrame
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|hasFrame
argument_list|()
specifier|const
block|;
name|void
name|setAccelerated
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|isAccelerated
argument_list|()
specifier|const
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
name|void
name|interpretText
argument_list|()
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery
argument_list|)
specifier|const
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
name|void
name|fixup
argument_list|(
argument|QString&input
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|stepBy
argument_list|(
argument|int steps
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|stepUp
argument_list|()
block|;
name|void
name|stepDown
argument_list|()
block|;
name|void
name|selectAll
argument_list|()
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
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
name|void
name|mouseReleaseEvent
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
name|timerEvent
argument_list|(
name|QTimerEvent
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
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionSpinBox *option
argument_list|)
specifier|const
block|;
name|QLineEdit
operator|*
name|lineEdit
argument_list|()
specifier|const
block|;
name|void
name|setLineEdit
argument_list|(
name|QLineEdit
operator|*
name|edit
argument_list|)
block|;
name|virtual
name|StepEnabled
name|stepEnabled
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|editingFinished
argument_list|()
block|;
name|protected
operator|:
name|QAbstractSpinBox
argument_list|(
name|QAbstractSpinBoxPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_editorTextChanged(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_editorCursorPositionChanged(int, int)
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractSpinBox
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractSpinBox
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAbstractSpinBox::StepEnabled
argument_list|)
end_macro
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
comment|// QABSTRACTSPINBOX_H
end_comment
end_unit
