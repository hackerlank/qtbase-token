begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLCDNUMBER_H
end_ifndef
begin_define
DECL|macro|QLCDNUMBER_H
define|#
directive|define
name|QLCDNUMBER_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbitarray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LCDNUMBER
DECL|variable|QLCDNumberPrivate
name|class
name|QLCDNumberPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QLCDNumber
range|:
name|public
name|QFrame
comment|// LCD number widget
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Mode SegmentStyle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool smallDecimalPoint READ smallDecimalPoint WRITE setSmallDecimalPoint
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int numDigits READ digitCount WRITE setDigitCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int digitCount READ digitCount WRITE setDigitCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Mode mode READ mode WRITE setMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SegmentStyle segmentStyle READ segmentStyle WRITE setSegmentStyle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double value READ value WRITE display
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int intValue READ intValue WRITE display
argument_list|)
name|public
operator|:
name|explicit
name|QLCDNumber
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QLCDNumber
argument_list|(
argument|uint numDigits
argument_list|,
argument|QWidget* parent =
literal|0
argument_list|)
block|;
operator|~
name|QLCDNumber
argument_list|()
block|;      enum
name|Mode
block|{
name|Hex
block|,
name|Dec
block|,
name|Oct
block|,
name|Bin
block|}
block|;     enum
name|SegmentStyle
block|{
name|Outline
block|,
name|Filled
block|,
name|Flat
block|}
block|;
name|bool
name|smallDecimalPoint
argument_list|()
specifier|const
block|;
name|int
name|digitCount
argument_list|()
specifier|const
block|;
name|void
name|setDigitCount
argument_list|(
argument|int nDigits
argument_list|)
block|;
name|bool
name|checkOverflow
argument_list|(
argument|double num
argument_list|)
specifier|const
block|;
name|bool
name|checkOverflow
argument_list|(
argument|int num
argument_list|)
specifier|const
block|;
name|Mode
name|mode
argument_list|()
specifier|const
block|;
name|void
name|setMode
argument_list|(
name|Mode
argument_list|)
block|;
name|SegmentStyle
name|segmentStyle
argument_list|()
specifier|const
block|;
name|void
name|setSegmentStyle
argument_list|(
name|SegmentStyle
argument_list|)
block|;
name|double
name|value
argument_list|()
specifier|const
block|;
name|int
name|intValue
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|display
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
block|;
name|void
name|display
argument_list|(
argument|int num
argument_list|)
block|;
name|void
name|display
argument_list|(
argument|double num
argument_list|)
block|;
name|void
name|setHexMode
argument_list|()
block|;
name|void
name|setDecMode
argument_list|()
block|;
name|void
name|setOctMode
argument_list|()
block|;
name|void
name|setBinMode
argument_list|()
block|;
name|void
name|setSmallDecimalPoint
argument_list|(
name|bool
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|overflow
argument_list|()
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
name|public
operator|:
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QLCDNumber
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLCDNumber
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LCDNUMBER
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
comment|// QLCDNUMBER_H
end_comment
end_unit
