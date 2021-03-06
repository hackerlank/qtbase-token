begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsanchorlayout.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicslinearlayout.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicswidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsview.h>
end_include
begin_class
DECL|class|tst_QGraphicsAnchorLayout
class|class
name|tst_QGraphicsAnchorLayout
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QGraphicsAnchorLayout
name|tst_QGraphicsAnchorLayout
parameter_list|()
block|{}
DECL|function|~tst_QGraphicsAnchorLayout
name|~
name|tst_QGraphicsAnchorLayout
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|hard_complex_data
parameter_list|()
function_decl|;
name|void
name|hard_complex
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorSizeHints_data
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorSizeHints
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorSetGeometry_data
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorSetGeometry
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorNested_data
parameter_list|()
function_decl|;
name|void
name|linearVsAnchorNested
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|RectWidget
class|class
name|RectWidget
super|:
specifier|public
name|QGraphicsWidget
block|{
public|public:
DECL|function|RectWidget
name|RectWidget
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|paint
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundRect
argument_list|(
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
name|rect
argument_list|()
operator|.
name|bottomLeft
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|topRight
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|createItem
specifier|static
name|QGraphicsWidget
modifier|*
name|createItem
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|minimum
init|=
name|QSizeF
argument_list|(
literal|100.0
argument_list|,
literal|100.0
argument_list|)
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|preferred
init|=
name|QSize
argument_list|(
literal|150.0
argument_list|,
literal|100.0
argument_list|)
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|maximum
init|=
name|QSizeF
argument_list|(
literal|200.0
argument_list|,
literal|100.0
argument_list|)
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
init|=
name|QString
argument_list|()
parameter_list|)
block|{
name|QGraphicsWidget
modifier|*
name|w
init|=
operator|new
name|RectWidget
decl_stmt|;
name|w
operator|->
name|setMinimumSize
argument_list|(
name|minimum
argument_list|)
expr_stmt|;
name|w
operator|->
name|setPreferredSize
argument_list|(
name|preferred
argument_list|)
expr_stmt|;
name|w
operator|->
name|setMaximumSize
argument_list|(
name|maximum
argument_list|)
expr_stmt|;
name|w
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|setAnchor
specifier|static
name|void
name|setAnchor
parameter_list|(
name|QGraphicsAnchorLayout
modifier|*
name|l
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|firstItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|firstEdge
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|secondItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|secondEdge
parameter_list|,
name|qreal
name|spacing
parameter_list|)
block|{
name|QGraphicsAnchor
modifier|*
name|anchor
init|=
name|l
operator|->
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|firstEdge
argument_list|,
name|secondItem
argument_list|,
name|secondEdge
argument_list|)
decl_stmt|;
name|anchor
operator|->
name|setSpacing
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hard_complex_data
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|hard_complex_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"whichSizeHint"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"minimumSizeHint"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"preferredSizeHint"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"maximumSizeHint"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
expr_stmt|;
comment|// Add it as a reference to see how much overhead the body of effectiveSizeHint takes.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"noSizeHint"
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hard_complex
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|hard_complex
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|whichSizeHint
argument_list|)
expr_stmt|;
comment|// Test for "hard" complex case, taken from wiki
comment|// https://cwiki.nokia.com/S60QTUI/AnchorLayoutComplexCases
name|QSizeF
name|min
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSizeF
name|pref
argument_list|(
literal|50
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSizeF
name|max
argument_list|(
literal|100
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|a
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"a"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|b
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"b"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|c
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"c"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|d
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"d"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|e
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"e"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|f
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"f"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|g
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"g"
argument_list|)
decl_stmt|;
name|QGraphicsAnchorLayout
modifier|*
name|l
init|=
operator|new
name|QGraphicsAnchorLayout
decl_stmt|;
name|l
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//<!-- Trunk -->
name|setAnchor
argument_list|(
name|l
argument_list|,
name|l
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|l
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|//<!-- Above trunk -->
name|setAnchor
argument_list|(
name|l
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|//<!-- Below trunk -->
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorHorizontalCenter
argument_list|,
name|g
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|g
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|AnchorHorizontalCenter
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|//<!-- vertical is simpler -->
name|setAnchor
argument_list|(
name|l
argument_list|,
name|l
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|e
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|g
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|l
argument_list|,
name|g
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|l
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// It won't query the size hint if it already has a size set.
comment|// If only one of the sizes is unset it will query sizeHint only of for that hint type.
name|l
operator|->
name|setMinimumSize
argument_list|(
literal|60
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|l
operator|->
name|setPreferredSize
argument_list|(
literal|220
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|l
operator|->
name|setMaximumSize
argument_list|(
literal|240
argument_list|,
literal|40
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|whichSizeHint
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
name|l
operator|->
name|setMinimumSize
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PreferredSize
case|:
name|l
operator|->
name|setPreferredSize
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
name|l
operator|->
name|setMaximumSize
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|QSizeF
name|sizeHint
decl_stmt|;
comment|// warm up instruction cache
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|l
operator|->
name|effectiveSizeHint
argument_list|(
operator|(
name|Qt
operator|::
name|SizeHint
operator|)
name|whichSizeHint
argument_list|)
expr_stmt|;
comment|// ...then measure...
name|QBENCHMARK
block|{
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|l
operator|->
name|effectiveSizeHint
argument_list|(
operator|(
name|Qt
operator|::
name|SizeHint
operator|)
name|whichSizeHint
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createLayouts
specifier|static
name|QGraphicsLayout
modifier|*
name|createLayouts
parameter_list|(
name|int
name|whichLayout
parameter_list|)
block|{
name|QSizeF
name|min
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSizeF
name|pref
argument_list|(
literal|50
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSizeF
name|max
argument_list|(
literal|100
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|a
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"a"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|b
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"b"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|c
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"c"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|d
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"d"
argument_list|)
decl_stmt|;
name|QGraphicsLayout
modifier|*
name|l
decl_stmt|;
if|if
condition|(
name|whichLayout
operator|==
literal|0
condition|)
block|{
name|l
operator|=
operator|new
name|QGraphicsLinearLayout
expr_stmt|;
name|QGraphicsLinearLayout
modifier|*
name|linear
init|=
cast|static_cast
argument_list|<
name|QGraphicsLinearLayout
operator|*
argument_list|>
argument_list|(
name|l
argument_list|)
decl_stmt|;
name|linear
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|linear
operator|->
name|addItem
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|linear
operator|->
name|addItem
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|linear
operator|->
name|addItem
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|linear
operator|->
name|addItem
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|l
operator|=
operator|new
name|QGraphicsAnchorLayout
expr_stmt|;
name|QGraphicsAnchorLayout
modifier|*
name|anchor
init|=
cast|static_cast
argument_list|<
name|QGraphicsAnchorLayout
operator|*
argument_list|>
argument_list|(
name|l
argument_list|)
decl_stmt|;
name|anchor
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Horizontal
name|setAnchor
argument_list|(
name|anchor
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|anchor
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|anchor
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|anchor
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setAnchor
argument_list|(
name|anchor
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Vertical
name|anchor
operator|->
name|addAnchors
argument_list|(
name|anchor
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchors
argument_list|(
name|anchor
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchors
argument_list|(
name|anchor
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchors
argument_list|(
name|anchor
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
block|}
return|return
name|l
return|;
block|}
end_function
begin_function
DECL|function|linearVsAnchorSizeHints_data
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorSizeHints_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"whichLayout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"whichSizeHint"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsLinearLayout::minimum"
argument_list|)
operator|<<
literal|0
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsLinearLayout::preferred"
argument_list|)
operator|<<
literal|0
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsLinearLayout::maximum"
argument_list|)
operator|<<
literal|0
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsLinearLayout::noSizeHint"
argument_list|)
operator|<<
literal|0
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsAnchorLayout::minimum"
argument_list|)
operator|<<
literal|1
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsAnchorLayout::preferred"
argument_list|)
operator|<<
literal|1
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsAnchorLayout::maximum"
argument_list|)
operator|<<
literal|1
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsAnchorLayout::noSizeHint"
argument_list|)
operator|<<
literal|1
operator|<<
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|linearVsAnchorSizeHints
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorSizeHints
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|whichSizeHint
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|whichLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayout
modifier|*
name|l
init|=
name|createLayouts
argument_list|(
name|whichLayout
argument_list|)
decl_stmt|;
name|QSizeF
name|sizeHint
decl_stmt|;
comment|// warm up instruction cache
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|l
operator|->
name|effectiveSizeHint
argument_list|(
operator|(
name|Qt
operator|::
name|SizeHint
operator|)
name|whichSizeHint
argument_list|)
expr_stmt|;
comment|// ...then measure...
name|QBENCHMARK
block|{
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|l
operator|->
name|effectiveSizeHint
argument_list|(
operator|(
name|Qt
operator|::
name|SizeHint
operator|)
name|whichSizeHint
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|linearVsAnchorSetGeometry_data
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorSetGeometry_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"whichLayout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsLinearLayout"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QGraphicsAnchorLayout"
argument_list|)
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|linearVsAnchorSetGeometry
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorSetGeometry
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|whichLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayout
modifier|*
name|l
init|=
name|createLayouts
argument_list|(
name|whichLayout
argument_list|)
decl_stmt|;
name|QRectF
name|sizeHint
decl_stmt|;
name|qreal
name|maxWidth
decl_stmt|;
name|qreal
name|increment
decl_stmt|;
comment|// warm up instruction cache
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|.
name|setSize
argument_list|(
name|l
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MinimumSize
argument_list|)
argument_list|)
expr_stmt|;
name|maxWidth
operator|=
name|l
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|MaximumSize
argument_list|)
operator|.
name|width
argument_list|()
expr_stmt|;
name|increment
operator|=
operator|(
name|maxWidth
operator|-
name|sizeHint
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|100
expr_stmt|;
name|l
operator|->
name|setGeometry
argument_list|(
name|sizeHint
argument_list|)
expr_stmt|;
comment|// ...then measure...
name|QBENCHMARK
block|{
name|l
operator|->
name|invalidate
argument_list|()
expr_stmt|;
for|for
control|(
name|qreal
name|width
init|=
name|sizeHint
operator|.
name|width
argument_list|()
init|;
name|width
operator|<=
name|maxWidth
condition|;
name|width
operator|+=
name|increment
control|)
block|{
name|sizeHint
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|l
operator|->
name|setGeometry
argument_list|(
name|sizeHint
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|linearVsAnchorNested_data
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorNested_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"whichLayout"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LinearLayout"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"AnchorLayout setup with null-anchors knot"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"AnchorLayout setup easy to simplificate"
argument_list|)
operator|<<
literal|2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|linearVsAnchorNested
name|void
name|tst_QGraphicsAnchorLayout
operator|::
name|linearVsAnchorNested
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|whichLayout
argument_list|)
expr_stmt|;
name|QSizeF
name|min
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSizeF
name|pref
argument_list|(
literal|80
argument_list|,
literal|80
argument_list|)
decl_stmt|;
name|QSizeF
name|max
argument_list|(
literal|150
argument_list|,
literal|150
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|a
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"a"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|b
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"b"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|c
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"c"
argument_list|)
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|d
init|=
name|createItem
argument_list|(
name|min
argument_list|,
name|pref
argument_list|,
name|max
argument_list|,
literal|"d"
argument_list|)
decl_stmt|;
name|QGraphicsLayout
modifier|*
name|layout
decl_stmt|;
if|if
condition|(
name|whichLayout
operator|==
literal|0
condition|)
block|{
name|QGraphicsLinearLayout
modifier|*
name|linear1
init|=
operator|new
name|QGraphicsLinearLayout
decl_stmt|;
name|QGraphicsLinearLayout
modifier|*
name|linear2
init|=
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|QGraphicsLinearLayout
modifier|*
name|linear3
init|=
operator|new
name|QGraphicsLinearLayout
decl_stmt|;
name|linear1
operator|->
name|addItem
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|linear1
operator|->
name|addItem
argument_list|(
name|linear2
argument_list|)
expr_stmt|;
name|linear2
operator|->
name|addItem
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|linear2
operator|->
name|addItem
argument_list|(
name|linear3
argument_list|)
expr_stmt|;
name|linear3
operator|->
name|addItem
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|linear3
operator|->
name|addItem
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|layout
operator|=
name|linear1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|whichLayout
operator|==
literal|1
condition|)
block|{
name|QGraphicsAnchorLayout
modifier|*
name|anchor
init|=
operator|new
name|QGraphicsAnchorLayout
decl_stmt|;
comment|// A
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|)
expr_stmt|;
comment|// B
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|)
expr_stmt|;
comment|// C
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|c
argument_list|,
name|Qt
operator|::
name|TopRightCorner
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|c
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|BottomLeftCorner
argument_list|)
expr_stmt|;
comment|// D
name|anchor
operator|->
name|addCornerAnchors
argument_list|(
name|d
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
expr_stmt|;
name|layout
operator|=
name|anchor
expr_stmt|;
block|}
else|else
block|{
name|QGraphicsAnchorLayout
modifier|*
name|anchor
init|=
operator|new
name|QGraphicsAnchorLayout
decl_stmt|;
comment|// A
name|anchor
operator|->
name|addAnchor
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchors
argument_list|(
name|a
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|b
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|)
expr_stmt|;
comment|// B
name|anchor
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|)
expr_stmt|;
comment|// C
name|anchor
operator|->
name|addAnchor
argument_list|(
name|c
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|d
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|c
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|)
expr_stmt|;
comment|// D
name|anchor
operator|->
name|addAnchor
argument_list|(
name|d
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|)
expr_stmt|;
name|anchor
operator|->
name|addAnchor
argument_list|(
name|d
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|anchor
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|)
expr_stmt|;
name|layout
operator|=
name|anchor
expr_stmt|;
block|}
name|QSizeF
name|sizeHint
decl_stmt|;
comment|// warm up instruction cache
name|layout
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|layout
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
comment|// ...then measure...
name|QBENCHMARK
block|{
comment|// To ensure that all sizeHints caches are invalidated in
comment|// the LinearLayout setup, we must call updateGeometry on the
comment|// children. If we didn't, only the top level layout would be
comment|// re-calculated.
cast|static_cast
argument_list|<
name|QGraphicsLayoutItem
operator|*
argument_list|>
argument_list|(
name|a
argument_list|)
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
cast|static_cast
argument_list|<
name|QGraphicsLayoutItem
operator|*
argument_list|>
argument_list|(
name|b
argument_list|)
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
cast|static_cast
argument_list|<
name|QGraphicsLayoutItem
operator|*
argument_list|>
argument_list|(
name|c
argument_list|)
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
cast|static_cast
argument_list|<
name|QGraphicsLayoutItem
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
name|layout
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|sizeHint
operator|=
name|layout
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsAnchorLayout
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicsanchorlayout.moc"
end_include
end_unit
