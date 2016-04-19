begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QPalette>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QPlainTextEdit>
end_include
begin_include
include|#
directive|include
file|<QStyle>
end_include
begin_include
include|#
directive|include
file|<QTabWidget>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_comment
comment|// Format enumeration value and strip off the class name
end_comment
begin_comment
comment|// added by QDebug: "QStyle::StandardPixmap(SP_Icon)" -> "SP_Icon".
end_comment
begin_function
template|template
parameter_list|<
name|typename
name|Enum
parameter_list|>
DECL|function|formatEnumValue
specifier|static
specifier|inline
name|QString
name|formatEnumValue
parameter_list|(
name|Enum
name|value
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QDebug
argument_list|(
operator|&
name|result
argument_list|)
operator|<<
name|value
expr_stmt|;
name|int
name|index
init|=
name|result
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'('
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|>
literal|0
condition|)
block|{
comment|// "QStyle::StandardPixmap(..)".
name|result
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|index
operator|+
literal|1
argument_list|)
expr_stmt|;
name|index
operator|=
name|result
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|>
literal|0
condition|)
name|result
operator|.
name|truncate
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|pixmapDescription
specifier|static
name|QString
name|pixmapDescription
parameter_list|(
name|QStyle
operator|::
name|StandardPixmap
name|sp
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|QString
name|description
init|=
name|formatEnumValue
argument_list|(
name|sp
argument_list|)
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|description
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|'('
operator|<<
name|int
argument_list|(
name|sp
argument_list|)
operator|<<
literal|") "
expr_stmt|;
if|if
condition|(
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|str
operator|<<
literal|"(null)"
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|qreal
name|dpr
init|=
name|pixmap
operator|.
name|devicePixelRatioF
argument_list|()
decl_stmt|;
name|str
operator|<<
literal|' '
operator|<<
name|pixmap
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|pixmap
operator|.
name|height
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|dpr
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
condition|)
name|str
operator|<<
literal|" DPR="
operator|<<
name|dpr
expr_stmt|;
block|}
return|return
name|description
return|;
block|}
end_function
begin_comment
comment|// Display pixmaps returned by QStyle::standardPixmap() in a grid.
end_comment
begin_function
DECL|function|createStandardPixmapPage
specifier|static
name|QWidget
modifier|*
name|createStandardPixmapPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QWidget
modifier|*
name|result
init|=
operator|new
name|QWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QGridLayout
modifier|*
name|grid
init|=
operator|new
name|QGridLayout
argument_list|(
name|result
argument_list|)
decl_stmt|;
name|int
name|row
init|=
literal|0
decl_stmt|;
name|int
name|column
init|=
literal|0
decl_stmt|;
specifier|const
name|int
name|maxColumns
init|=
literal|6
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|int
argument_list|(
name|QStyle
operator|::
name|SP_LineEditClearButton
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QStyle
operator|::
name|StandardPixmap
name|sp
init|=
cast|static_cast
argument_list|<
name|QStyle
operator|::
name|StandardPixmap
argument_list|>
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QPixmap
name|pixmap
init|=
name|result
operator|->
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|sp
argument_list|,
name|Q_NULLPTR
argument_list|,
name|result
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|descriptionLabel
init|=
operator|new
name|QLabel
argument_list|(
name|pixmapDescription
argument_list|(
name|sp
argument_list|,
name|pixmap
argument_list|)
argument_list|)
decl_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|descriptionLabel
argument_list|,
name|row
argument_list|,
name|column
operator|++
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|displayLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|displayLabel
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|displayLabel
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Box
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|displayLabel
argument_list|,
name|row
argument_list|,
name|column
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
name|column
operator|>=
name|maxColumns
condition|)
block|{
operator|++
name|row
expr_stmt|;
name|column
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|// Display values returned by QStyle::pixelMetric().
end_comment
begin_function
DECL|function|createMetricsPage
specifier|static
name|QWidget
modifier|*
name|createMetricsPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QPlainTextEdit
modifier|*
name|result
init|=
operator|new
name|QPlainTextEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QString
name|text
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|text
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|int
argument_list|(
name|QStyle
operator|::
name|PM_HeaderDefaultSectionSizeVertical
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QStyle
operator|::
name|PixelMetric
name|m
init|=
cast|static_cast
argument_list|<
name|QStyle
operator|::
name|PixelMetric
argument_list|>
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|str
operator|<<
name|formatEnumValue
argument_list|(
name|m
argument_list|)
operator|<<
literal|'('
operator|<<
name|int
argument_list|(
name|m
argument_list|)
operator|<<
literal|")="
operator|<<
name|result
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|m
argument_list|,
name|Q_NULLPTR
argument_list|,
name|result
argument_list|)
operator|<<
literal|'\n'
expr_stmt|;
block|}
name|result
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|// Display values returned by QStyle::styleHint()
end_comment
begin_function
DECL|function|createHintsPage
specifier|static
name|QWidget
modifier|*
name|createHintsPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QPlainTextEdit
modifier|*
name|result
init|=
operator|new
name|QPlainTextEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QString
name|text
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|text
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|int
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuDontStartSloppyOnLeave
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QStyle
operator|::
name|StyleHint
name|h
init|=
cast|static_cast
argument_list|<
name|QStyle
operator|::
name|StyleHint
argument_list|>
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|str
operator|<<
name|formatEnumValue
argument_list|(
name|h
argument_list|)
operator|<<
literal|'('
operator|<<
name|int
argument_list|(
name|h
argument_list|)
operator|<<
literal|")="
operator|<<
name|result
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|h
argument_list|,
name|Q_NULLPTR
argument_list|,
name|result
argument_list|)
operator|<<
literal|'\n'
expr_stmt|;
block|}
name|result
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|// Display palette colors
end_comment
begin_function
DECL|function|createColorsPage
specifier|static
name|QWidget
modifier|*
name|createColorsPage
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QWidget
modifier|*
name|result
init|=
operator|new
name|QWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QGridLayout
modifier|*
name|grid
init|=
operator|new
name|QGridLayout
decl_stmt|;
specifier|const
name|QPalette
name|palette
init|=
name|QGuiApplication
operator|::
name|palette
argument_list|()
decl_stmt|;
name|int
name|row
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
name|int
argument_list|(
name|QPalette
operator|::
name|NColorRoles
argument_list|)
condition|;
operator|++
name|r
control|)
block|{
specifier|const
name|QPalette
operator|::
name|ColorRole
name|role
init|=
cast|static_cast
argument_list|<
name|QPalette
operator|::
name|ColorRole
argument_list|>
argument_list|(
name|r
argument_list|)
decl_stmt|;
specifier|const
name|QColor
name|color
init|=
name|palette
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Active
argument_list|,
name|role
argument_list|)
decl_stmt|;
if|if
condition|(
name|color
operator|.
name|isValid
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|description
init|=
name|formatEnumValue
argument_list|(
name|role
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'('
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|r
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|") "
argument_list|)
operator|+
name|color
operator|.
name|name
argument_list|(
name|QColor
operator|::
name|HexArgb
argument_list|)
decl_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|description
argument_list|)
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|displayLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|QPixmap
name|pixmap
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
decl_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|displayLabel
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|displayLabel
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Box
argument_list|)
expr_stmt|;
name|grid
operator|->
name|addWidget
argument_list|(
name|displayLabel
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|++
name|row
expr_stmt|;
block|}
block|}
name|QHBoxLayout
modifier|*
name|hBox
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|hBox
operator|->
name|addLayout
argument_list|(
name|grid
argument_list|)
expr_stmt|;
name|hBox
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QVBoxLayout
modifier|*
name|vBox
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|result
argument_list|)
decl_stmt|;
name|vBox
operator|->
name|addLayout
argument_list|(
name|hBox
argument_list|)
expr_stmt|;
name|vBox
operator|->
name|addStretch
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
name|void
name|updateDescription
parameter_list|()
function_decl|;
private|private:
DECL|member|m_tabWidget
name|QTabWidget
modifier|*
name|m_tabWidget
decl_stmt|;
DECL|member|m_descriptionLabel
name|QLabel
modifier|*
name|m_descriptionLabel
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
member_init_list|:
name|m_tabWidget
argument_list|(
operator|new
name|QTabWidget
argument_list|)
member_init_list|,
name|m_descriptionLabel
argument_list|(
operator|new
name|QLabel
argument_list|)
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"&File"
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|a
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Quit"
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
decl_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_Q
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|central
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|central
argument_list|)
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|m_descriptionLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|m_tabWidget
argument_list|)
expr_stmt|;
name|m_tabWidget
operator|->
name|addTab
argument_list|(
name|createStandardPixmapPage
argument_list|(
name|m_tabWidget
argument_list|)
argument_list|,
literal|"Standard Pixmaps"
argument_list|)
expr_stmt|;
name|m_tabWidget
operator|->
name|addTab
argument_list|(
name|createHintsPage
argument_list|(
name|m_tabWidget
argument_list|)
argument_list|,
literal|"Hints"
argument_list|)
expr_stmt|;
name|m_tabWidget
operator|->
name|addTab
argument_list|(
name|createMetricsPage
argument_list|(
name|m_tabWidget
argument_list|)
argument_list|,
literal|"Pixel Metrics"
argument_list|)
expr_stmt|;
name|m_tabWidget
operator|->
name|addTab
argument_list|(
name|createColorsPage
argument_list|(
name|m_tabWidget
argument_list|)
argument_list|,
literal|"Colors"
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|central
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QLatin1String
argument_list|(
literal|"Style Tester (Qt"
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|", "
argument_list|)
operator|+
name|style
argument_list|()
operator|->
name|objectName
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|updateDescription
name|void
name|MainWindow
operator|::
name|updateDescription
parameter_list|()
block|{
name|QString
name|text
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|text
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"Qt "
operator|<<
name|QT_VERSION_STR
operator|<<
literal|", platform: "
operator|<<
name|QGuiApplication
operator|::
name|platformName
argument_list|()
operator|<<
literal|", Style: \""
operator|<<
name|style
argument_list|()
operator|->
name|objectName
argument_list|()
operator|<<
literal|"\", DPR="
operator|<<
name|devicePixelRatioF
argument_list|()
operator|<<
literal|' '
operator|<<
name|logicalDpiX
argument_list|()
operator|<<
literal|','
operator|<<
name|logicalDpiY
argument_list|()
operator|<<
literal|"DPI"
expr_stmt|;
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|w
init|=
name|windowHandle
argument_list|()
condition|)
name|str
operator|<<
literal|", Screen: \""
operator|<<
name|w
operator|->
name|screen
argument_list|()
operator|->
name|name
argument_list|()
operator|<<
literal|'"'
expr_stmt|;
name|m_descriptionLabel
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
operator|::
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseHighDpiPixmaps
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MainWindow
name|mw
decl_stmt|;
name|mw
operator|.
name|show
argument_list|()
expr_stmt|;
name|mw
operator|.
name|updateDescription
argument_list|()
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|mw
operator|.
name|windowHandle
argument_list|()
argument_list|,
operator|&
name|QWindow
operator|::
name|screenChanged
argument_list|,
operator|&
name|mw
argument_list|,
operator|&
name|MainWindow
operator|::
name|updateDescription
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
