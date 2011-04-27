begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIZEPOLICY_H
end_ifndef
begin_define
DECL|macro|QSIZEPOLICY_H
define|#
directive|define
name|QSIZEPOLICY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QVariant
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QSizePolicy
decl_stmt|{     Q_GADGET     Q_ENUMS(Policy
end_function
begin_label
unit|)
name|private
label|:
end_label
begin_enum
enum|enum
name|SizePolicyMasks
block|{
name|HSize
init|=
literal|4
block|,
name|HMask
init|=
literal|0x0f
block|,
name|VMask
init|=
name|HMask
operator|<<
name|HSize
block|,
name|CTShift
init|=
literal|9
block|,
name|CTSize
init|=
literal|5
block|,
name|CTMask
init|=
operator|(
operator|(
literal|0x1
operator|<<
name|CTSize
operator|)
operator|-
literal|1
operator|)
operator|<<
name|CTShift
block|,
name|WFHShift
init|=
name|CTShift
operator|+
name|CTSize
block|,
name|UnusedShift
init|=
name|WFHShift
operator|+
literal|1
block|,
name|UnusedSize
init|=
literal|1
block|}
enum|;
end_enum
begin_label
name|public
label|:
end_label
begin_enum
enum|enum
name|PolicyFlag
block|{
name|GrowFlag
init|=
literal|1
block|,
name|ExpandFlag
init|=
literal|2
block|,
name|ShrinkFlag
init|=
literal|4
block|,
name|IgnoreFlag
init|=
literal|8
block|}
enum|;
end_enum
begin_enum
enum|enum
name|Policy
block|{
name|Fixed
init|=
literal|0
block|,
name|Minimum
init|=
name|GrowFlag
block|,
name|Maximum
init|=
name|ShrinkFlag
block|,
name|Preferred
init|=
name|GrowFlag
operator||
name|ShrinkFlag
block|,
name|MinimumExpanding
init|=
name|GrowFlag
operator||
name|ExpandFlag
block|,
name|Expanding
init|=
name|GrowFlag
operator||
name|ShrinkFlag
operator||
name|ExpandFlag
block|,
name|Ignored
init|=
name|ShrinkFlag
operator||
name|GrowFlag
operator||
name|IgnoreFlag
block|}
enum|;
end_enum
begin_enum
enum|enum
name|ControlType
block|{
name|DefaultType
init|=
literal|0x00000001
block|,
name|ButtonBox
init|=
literal|0x00000002
block|,
name|CheckBox
init|=
literal|0x00000004
block|,
name|ComboBox
init|=
literal|0x00000008
block|,
name|Frame
init|=
literal|0x00000010
block|,
name|GroupBox
init|=
literal|0x00000020
block|,
name|Label
init|=
literal|0x00000040
block|,
name|Line
init|=
literal|0x00000080
block|,
name|LineEdit
init|=
literal|0x00000100
block|,
name|PushButton
init|=
literal|0x00000200
block|,
name|RadioButton
init|=
literal|0x00000400
block|,
name|Slider
init|=
literal|0x00000800
block|,
name|SpinBox
init|=
literal|0x00001000
block|,
name|TabWidget
init|=
literal|0x00002000
block|,
name|ToolButton
init|=
literal|0x00004000
block|}
enum|;
end_enum
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|ControlTypes
argument_list|,
argument|ControlType
argument_list|)
end_macro
begin_expr_stmt
name|QSizePolicy
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// ### Qt 5: merge these two constructors (with type == DefaultType)
name|QSizePolicy
argument_list|(
argument|Policy horizontal
argument_list|,
argument|Policy vertical
argument_list|)
operator|:
name|data
argument_list|(
argument|horizontal | (vertical<< HSize)
argument_list|)
block|{ }
name|QSizePolicy
argument_list|(
argument|Policy horizontal
argument_list|,
argument|Policy vertical
argument_list|,
argument|ControlType type
argument_list|)
operator|:
name|data
argument_list|(
argument|horizontal | (vertical<< HSize)
argument_list|)
block|{
name|setControlType
argument_list|(
name|type
argument_list|)
block|; }
name|Policy
name|horizontalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|data
operator|&
name|HMask
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Policy
name|verticalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
operator|(
name|data
operator|&
name|VMask
operator|)
operator|>>
name|HSize
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|ControlType
name|controlType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
name|void
name|setHorizontalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|data
operator|=
operator|(
name|data
operator|&
operator|~
name|HMask
operator|)
operator||
name|d
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setVerticalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|data
operator|=
operator|(
name|data
operator|&
operator|~
operator|(
name|HMask
operator|<<
name|HSize
operator|)
operator|)
operator||
operator|(
name|d
operator|<<
name|HSize
operator|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|setControlType
parameter_list|(
name|ControlType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|{
name|Qt
operator|::
name|Orientations
name|result
block|;
if|if
condition|(
name|verticalPolicy
argument_list|()
operator|&
name|ExpandFlag
condition|)
name|result
operator||=
name|Qt
operator|::
name|Vertical
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|horizontalPolicy
argument_list|()
operator|&
name|ExpandFlag
condition|)
name|result
operator||=
name|Qt
operator|::
name|Horizontal
expr_stmt|;
end_if
begin_return
return|return
name|result
return|;
end_return
begin_macro
unit|}      void
name|setHeightForWidth
argument_list|(
argument|bool b
argument_list|)
end_macro
begin_block
block|{
name|data
operator|=
name|b
condition|?
operator|(
name|data
operator||
operator|(
literal|1
operator|<<
literal|2
operator|*
name|HSize
operator|)
operator|)
else|:
operator|(
name|data
operator|&
operator|~
operator|(
literal|1
operator|<<
literal|2
operator|*
name|HSize
operator|)
operator|)
expr_stmt|;
block|}
end_block
begin_expr_stmt
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|{
return|return
name|data
operator|&
operator|(
literal|1
operator|<<
literal|2
operator|*
name|HSize
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setWidthForHeight
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|data
operator|=
name|b
condition|?
operator|(
name|data
operator||
operator|(
literal|1
operator|<<
operator|(
name|WFHShift
operator|)
operator|)
operator|)
else|:
operator|(
name|data
operator|&
operator|~
operator|(
literal|1
operator|<<
operator|(
name|WFHShift
operator|)
operator|)
operator|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|hasWidthForHeight
argument_list|()
specifier|const
block|{
return|return
name|data
operator|&
operator|(
literal|1
operator|<<
operator|(
name|WFHShift
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|==
name|s
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|!=
name|s
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// implemented in qabstractlayout.cpp
end_comment
begin_expr_stmt
name|int
name|horizontalStretch
argument_list|()
specifier|const
block|{
return|return
name|data
operator|>>
literal|24
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|verticalStretch
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
operator|>>
literal|16
operator|)
operator|&
literal|0xff
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setHorizontalStretch
parameter_list|(
name|uchar
name|stretchFactor
parameter_list|)
block|{
name|data
operator|=
operator|(
name|data
operator|&
literal|0x00ffffff
operator|)
operator||
operator|(
name|uint
argument_list|(
name|stretchFactor
argument_list|)
operator|<<
literal|24
operator|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setVerticalStretch
parameter_list|(
name|uchar
name|stretchFactor
parameter_list|)
block|{
name|data
operator|=
operator|(
name|data
operator|&
literal|0xff00ffff
operator|)
operator||
operator|(
name|uint
argument_list|(
name|stretchFactor
argument_list|)
operator|<<
literal|16
operator|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|transpose
parameter_list|()
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_typedef
typedef|typedef
name|Policy
name|SizeType
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|qdoc
end_ifndef
begin_typedef
typedef|typedef
name|Qt
operator|::
name|Orientations
name|ExpandData
expr_stmt|;
end_typedef
begin_enum
enum|enum
block|{
name|NoDirection
init|=
literal|0
block|,
name|Horizontally
init|=
literal|1
block|,
name|Vertically
init|=
literal|2
block|,
name|BothDirections
init|=
name|Horizontally
operator||
name|Vertically
block|}
enum|;
end_enum
begin_else
else|#
directive|else
end_else
begin_enum
enum|enum
name|ExpandData
block|{
name|NoDirection
init|=
literal|0x0
block|,
name|Horizontally
init|=
literal|0x1
block|,
name|Vertically
init|=
literal|0x2
block|,
name|BothDirections
init|=
literal|0x3
block|}
enum|;
end_enum
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// qdoc
end_comment
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|mayShrinkHorizontally
argument_list|()
specifier|const
block|{
return|return
name|horizontalPolicy
argument_list|()
operator|&
name|ShrinkFlag
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|mayShrinkVertically
argument_list|()
specifier|const
block|{
return|return
name|verticalPolicy
argument_list|()
operator|&
name|ShrinkFlag
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|mayGrowHorizontally
argument_list|()
specifier|const
block|{
return|return
name|horizontalPolicy
argument_list|()
operator|&
name|GrowFlag
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|mayGrowVertically
argument_list|()
specifier|const
block|{
return|return
name|verticalPolicy
argument_list|()
operator|&
name|GrowFlag
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|Qt
operator|::
name|Orientations
name|expanding
argument_list|()
specifier|const
block|{
return|return
name|expandingDirections
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
name|QT3_SUPPORT_CONSTRUCTOR
end_macro
begin_macro
name|QSizePolicy
argument_list|(
argument|Policy hor
argument_list|,
argument|Policy ver
argument_list|,
argument|bool hfw
argument_list|)
end_macro
begin_macro
unit|:
name|data
argument_list|(
argument|hor | (ver<<HSize) | (hfw ? (
literal|1U
argument|<<
literal|2
argument|*HSize) :
literal|0
argument|)
argument_list|)
end_macro
begin_block
block|{ }
end_block
begin_macro
name|QT3_SUPPORT_CONSTRUCTOR
end_macro
begin_macro
name|QSizePolicy
argument_list|(
argument|Policy hor
argument_list|,
argument|Policy ver
argument_list|,
argument|uchar hors
argument_list|,
argument|uchar vers
argument_list|,
argument|bool hfw = false
argument_list|)
end_macro
begin_macro
unit|:
name|data
argument_list|(
argument|hor | (ver<<HSize) | (hfw ? (
literal|1U
argument|<<
literal|2
argument|*HSize) :
literal|0
argument|)
argument_list|)
end_macro
begin_block
block|{
name|setHorizontalStretch
argument_list|(
name|hors
argument_list|)
expr_stmt|;
name|setVerticalStretch
argument_list|(
name|vers
argument_list|)
expr_stmt|;
block|}
end_block
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|Policy
name|horData
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|data
operator|&
name|HMask
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|Policy
name|verData
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
operator|(
name|data
operator|&
name|VMask
operator|)
operator|>>
name|HSize
operator|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setHorData
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|setHorizontalPolicy
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setVerData
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|setVerticalPolicy
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|uint
name|horStretch
argument_list|()
specifier|const
block|{
return|return
name|horizontalStretch
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|uint
name|verStretch
argument_list|()
specifier|const
block|{
return|return
name|verticalStretch
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setHorStretch
parameter_list|(
name|uchar
name|sf
parameter_list|)
block|{
name|setHorizontalStretch
argument_list|(
name|sf
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setVerStretch
parameter_list|(
name|uchar
name|sf
parameter_list|)
block|{
name|setVerticalStretch
argument_list|(
name|sf
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QSizePolicy
argument_list|(
argument|int i
argument_list|)
end_macro
begin_macro
unit|:
name|data
argument_list|(
argument|i
argument_list|)
end_macro
begin_block
block|{ }
end_block
begin_decl_stmt
name|quint32
name|data
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  Qt5: Use bit flags instead, keep it here for improved readability for now.     We can maybe change it for Qt4, but we'd have to be careful, since the behaviour     is implementation defined. It usually varies between little- and big-endian compilers, but     it might also not vary.     quint32 horzPolicy : 4;     quint32 vertPolicy : 4;     quint32 hfw : 1;     quint32 ctype : 5;     quint32 wfh : 1;     quint32 padding : 1;   // we cannot use the highest bit     quint32 verStretch : 8;     quint32 horStretch : 8; */
end_comment
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSizePolicy::ControlTypes
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|// implemented in qlayout.cpp
end_comment
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|transpose
specifier|inline
name|void
name|QSizePolicy
operator|::
name|transpose
argument_list|()
block|{
name|Policy
name|hData
operator|=
name|horizontalPolicy
argument_list|()
block|;
name|Policy
name|vData
operator|=
name|verticalPolicy
argument_list|()
block|;
name|uchar
name|hStretch
operator|=
name|uchar
argument_list|(
name|horizontalStretch
argument_list|()
argument_list|)
block|;
name|uchar
name|vStretch
operator|=
name|uchar
argument_list|(
name|verticalStretch
argument_list|()
argument_list|)
block|;
name|setHorizontalPolicy
argument_list|(
name|vData
argument_list|)
block|;
name|setVerticalPolicy
argument_list|(
name|hData
argument_list|)
block|;
name|setHorizontalStretch
argument_list|(
name|vStretch
argument_list|)
block|;
name|setVerticalStretch
argument_list|(
name|hStretch
argument_list|)
block|; }
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIZEPOLICY_H
end_comment
end_unit
