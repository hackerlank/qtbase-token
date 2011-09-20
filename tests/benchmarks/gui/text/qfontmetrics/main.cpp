begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<QFontMetrics>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_comment
comment|//this test benchmarks the once-off (per font configuration) cost
end_comment
begin_comment
comment|//associated with using QFontMetrics
end_comment
begin_class
DECL|class|tst_QFontMetrics
class|class
name|tst_QFontMetrics
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QFontMetrics
name|tst_QFontMetrics
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|fontmetrics_create
parameter_list|()
function_decl|;
name|void
name|fontmetrics_create_once_loaded
parameter_list|()
function_decl|;
name|void
name|fontmetrics_height
parameter_list|()
function_decl|;
name|void
name|fontmetrics_height_once_loaded
parameter_list|()
function_decl|;
private|private:
name|void
name|testQFontMetrics
parameter_list|(
specifier|const
name|QFontMetrics
modifier|&
name|fm
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testQFontMetrics
name|void
name|tst_QFontMetrics
operator|::
name|testQFontMetrics
parameter_list|(
specifier|const
name|QFontMetrics
modifier|&
name|fm
parameter_list|)
block|{
name|int
name|fontHeight
init|=
name|fm
operator|.
name|height
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|fontmetrics_create
name|void
name|tst_QFontMetrics
operator|::
name|fontmetrics_create
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QFont
name|boldfont
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
decl_stmt|;
name|boldfont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldfont
operator|.
name|setPointSize
argument_list|(
name|boldfont
operator|.
name|pointSize
argument_list|()
operator|*
literal|1.5
argument_list|)
expr_stmt|;
name|QFontMetrics
name|bfm
argument_list|(
name|boldfont
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontmetrics_create_once_loaded
name|void
name|tst_QFontMetrics
operator|::
name|fontmetrics_create_once_loaded
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QFont
name|boldfont
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
decl_stmt|;
name|boldfont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldfont
operator|.
name|setPointSize
argument_list|(
name|boldfont
operator|.
name|pointSize
argument_list|()
operator|*
literal|1.5
argument_list|)
expr_stmt|;
name|QFontMetrics
name|bfm
argument_list|(
name|boldfont
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontmetrics_height
name|void
name|tst_QFontMetrics
operator|::
name|fontmetrics_height
parameter_list|()
block|{
name|QFont
name|boldfont
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
decl_stmt|;
name|boldfont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldfont
operator|.
name|setPointSize
argument_list|(
name|boldfont
operator|.
name|pointSize
argument_list|()
operator|*
literal|1.5
argument_list|)
expr_stmt|;
name|QFontMetrics
name|bfm
argument_list|(
name|boldfont
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|testQFontMetrics
argument_list|(
name|bfm
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontmetrics_height_once_loaded
name|void
name|tst_QFontMetrics
operator|::
name|fontmetrics_height_once_loaded
parameter_list|()
block|{
name|QFont
name|boldfont
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
decl_stmt|;
name|boldfont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|boldfont
operator|.
name|setPointSize
argument_list|(
name|boldfont
operator|.
name|pointSize
argument_list|()
operator|*
literal|1.5
argument_list|)
expr_stmt|;
name|QFontMetrics
name|bfm
argument_list|(
name|boldfont
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|testQFontMetrics
argument_list|(
name|bfm
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFontMetrics
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
