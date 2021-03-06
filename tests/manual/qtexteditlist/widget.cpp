begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"widget.h"
end_include
begin_include
include|#
directive|include
file|"ui_widget.h"
end_include
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|ui
argument_list|(
operator|new
name|Ui
operator|::
name|Widget
argument_list|)
block|{
name|ui
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// Changing font size and indent values to verify fix for QTBUG-5111.
name|connect
argument_list|(
name|ui
operator|->
name|spinBoxFontPointSize
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setFontPointSize
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|->
name|spinBoxIndentWidth
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setIndentWidth
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|textCursor
operator|=
operator|new
name|QTextCursor
argument_list|(
name|ui
operator|->
name|textEdit
operator|->
name|document
argument_list|()
argument_list|)
expr_stmt|;
comment|// Initialize text list with different formats and layouts
name|QTextListFormat
name|listFormat
decl_stmt|;
comment|// disc
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDisc
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"disc one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\ndisc two"
argument_list|)
expr_stmt|;
comment|// 1., 2.
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDecimal
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"decimal one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\ndecimal two"
argument_list|)
expr_stmt|;
comment|// a., b.
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"lower alpha one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\nlower alpha two"
argument_list|)
expr_stmt|;
comment|// A., B.
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListUpperAlpha
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"upper alpha one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\nupper alpha two"
argument_list|)
expr_stmt|;
comment|// Indent 1
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDisc
argument_list|)
expr_stmt|;
name|listFormat
operator|.
name|setIndent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"indent 1 one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\nindent 2 two"
argument_list|)
expr_stmt|;
comment|// Indent 2
name|listFormat
operator|.
name|setIndent
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"indent 2 one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\nindent 2 two"
argument_list|)
expr_stmt|;
comment|// Indent 3
name|listFormat
operator|.
name|setIndent
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"indent 3 one"
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\nindent 3 two"
argument_list|)
expr_stmt|;
comment|// right to left: disc
name|listFormat
operator|.
name|setIndent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListDisc
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
name|QChar
argument_list|(
literal|0x05d0
argument_list|)
argument_list|)
expr_stmt|;
comment|// use Hebrew aleph to create a right-to-left layout
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\n"
operator|+
name|QString
argument_list|(
name|QChar
argument_list|(
literal|0x05d0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// right to left: 1., 2.
name|listFormat
operator|.
name|setStyle
argument_list|(
name|QTextListFormat
operator|::
name|ListLowerAlpha
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertList
argument_list|(
name|listFormat
argument_list|)
expr_stmt|;
name|textCursor
operator|->
name|insertText
argument_list|(
name|QChar
argument_list|(
literal|0x05d0
argument_list|)
argument_list|)
expr_stmt|;
comment|// use Hebrew aleph to create a right-to-left layout
name|textCursor
operator|->
name|insertText
argument_list|(
literal|"\n"
operator|+
name|QString
argument_list|(
name|QChar
argument_list|(
literal|0x05d0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|setFontPointSize
argument_list|(
name|font
operator|.
name|pointSize
argument_list|()
argument_list|)
expr_stmt|;
name|ui
operator|->
name|textEdit
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|setIndentWidth
argument_list|(
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|ui
operator|->
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|indentWidth
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setFontPointSize
name|void
name|Widget
operator|::
name|setFontPointSize
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|ui
operator|->
name|textEdit
operator|->
name|selectAll
argument_list|()
expr_stmt|;
name|ui
operator|->
name|textEdit
operator|->
name|setFontPointSize
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setIndentWidth
name|void
name|Widget
operator|::
name|setIndentWidth
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|ui
operator|->
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|setIndentWidth
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~Widget
name|Widget
operator|::
name|~
name|Widget
parameter_list|()
block|{
operator|delete
name|ui
expr_stmt|;
operator|delete
name|textCursor
expr_stmt|;
block|}
end_destructor
end_unit
