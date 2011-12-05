begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qtextboundaryfinder.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_class
DECL|class|tst_QTextBoundaryFinder
class|class
name|tst_QTextBoundaryFinder
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|graphemeBoundaries
parameter_list|()
function_decl|;
name|void
name|wordBoundaries
parameter_list|()
function_decl|;
name|void
name|sentenceBoundaries
parameter_list|()
function_decl|;
name|void
name|isAtWordStart
parameter_list|()
function_decl|;
name|void
name|fastConstructor
parameter_list|()
function_decl|;
name|void
name|isAtBoundaryLine
parameter_list|()
function_decl|;
name|void
name|toNextBoundary_data
parameter_list|()
function_decl|;
name|void
name|toNextBoundary
parameter_list|()
function_decl|;
name|void
name|toPreviousBoundary_data
parameter_list|()
function_decl|;
name|void
name|toPreviousBoundary
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QTextBoundaryFinder
operator|::
name|init
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_IRIX
comment|// chdir into the top-level data dir, then refer to our testdata using relative paths
name|QString
name|testdata_dir
init|=
name|QFileInfo
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"data"
argument_list|)
argument_list|)
operator|.
name|absolutePath
argument_list|()
decl_stmt|;
name|QVERIFY2
argument_list|(
name|QDir
operator|::
name|setCurrent
argument_list|(
name|testdata_dir
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
literal|"Could not chdir to "
operator|+
name|testdata_dir
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|graphemeBoundaries
name|void
name|tst_QTextBoundaryFinder
operator|::
name|graphemeBoundaries
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"data/GraphemeBreakTest.txt"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|int
name|lines
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
name|lines
operator|++
expr_stmt|;
name|QString
name|test
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|line
argument_list|)
decl_stmt|;
name|int
name|hash
init|=
name|test
operator|.
name|indexOf
argument_list|(
literal|'#'
argument_list|)
decl_stmt|;
if|if
condition|(
name|hash
operator|>
literal|0
condition|)
name|test
operator|=
name|test
operator|.
name|left
argument_list|(
name|hash
argument_list|)
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|simplified
argument_list|()
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|breakPositions
decl_stmt|;
name|QString
name|testString
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|int
name|strPos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xf7
condition|)
name|breakPositions
operator|.
name|append
argument_list|(
name|strPos
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xd7
argument_list|)
expr_stmt|;
operator|++
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
operator|-
literal|4
argument_list|)
expr_stmt|;
name|QString
name|hex
init|=
name|test
operator|.
name|mid
argument_list|(
name|pos
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
literal|true
decl_stmt|;
name|testString
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|hex
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|pos
operator|+=
literal|4
expr_stmt|;
block|}
operator|++
name|strPos
expr_stmt|;
block|}
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Grapheme
argument_list|,
name|testString
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
operator|<
name|breakPositions
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|toNextBoundary
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|testString
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|finder
operator|.
name|setPosition
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|contains
argument_list|(
name|i
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
name|QCOMPARE
argument_list|(
name|lines
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|// to see it actually found the file and all.
block|}
end_function
begin_function
DECL|function|wordBoundaries
name|void
name|tst_QTextBoundaryFinder
operator|::
name|wordBoundaries
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"data/WordBreakTest.txt"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
name|QString
name|test
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|line
argument_list|)
decl_stmt|;
name|int
name|hash
init|=
name|test
operator|.
name|indexOf
argument_list|(
literal|'#'
argument_list|)
decl_stmt|;
if|if
condition|(
name|hash
operator|>
literal|0
condition|)
name|test
operator|=
name|test
operator|.
name|left
argument_list|(
name|hash
argument_list|)
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|simplified
argument_list|()
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|breakPositions
decl_stmt|;
name|QString
name|testString
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|int
name|strPos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xf7
condition|)
name|breakPositions
operator|.
name|append
argument_list|(
name|strPos
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xd7
argument_list|)
expr_stmt|;
operator|++
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
operator|-
literal|4
argument_list|)
expr_stmt|;
name|QString
name|hex
init|=
name|test
operator|.
name|mid
argument_list|(
name|pos
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
literal|true
decl_stmt|;
name|testString
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|hex
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|pos
operator|+=
literal|4
expr_stmt|;
block|}
operator|++
name|strPos
expr_stmt|;
block|}
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Word
argument_list|,
name|testString
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
operator|<
name|breakPositions
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|toNextBoundary
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|testString
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|finder
operator|.
name|setPosition
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|contains
argument_list|(
name|i
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|sentenceBoundaries
name|void
name|tst_QTextBoundaryFinder
operator|::
name|sentenceBoundaries
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"data/SentenceBreakTest.txt"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
name|QString
name|test
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|line
argument_list|)
decl_stmt|;
name|int
name|hash
init|=
name|test
operator|.
name|indexOf
argument_list|(
literal|'#'
argument_list|)
decl_stmt|;
if|if
condition|(
name|hash
operator|>
literal|0
condition|)
name|test
operator|=
name|test
operator|.
name|left
argument_list|(
name|hash
argument_list|)
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|simplified
argument_list|()
expr_stmt|;
name|test
operator|=
name|test
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|breakPositions
decl_stmt|;
name|QString
name|testString
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|int
name|strPos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xf7
condition|)
name|breakPositions
operator|.
name|append
argument_list|(
name|strPos
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
name|test
operator|.
name|at
argument_list|(
name|pos
argument_list|)
operator|.
name|unicode
argument_list|()
operator|==
literal|0xd7
argument_list|)
expr_stmt|;
operator|++
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|pos
operator|<
name|test
operator|.
name|length
argument_list|()
operator|-
literal|4
argument_list|)
expr_stmt|;
name|QString
name|hex
init|=
name|test
operator|.
name|mid
argument_list|(
name|pos
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
literal|true
decl_stmt|;
name|testString
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
name|hex
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|pos
operator|+=
literal|4
expr_stmt|;
block|}
operator|++
name|strPos
expr_stmt|;
block|}
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Sentence
argument_list|,
name|testString
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
operator|<
name|breakPositions
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|toNextBoundary
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|testString
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|finder
operator|.
name|setPosition
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|,
name|breakPositions
operator|.
name|contains
argument_list|(
name|i
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|isAtWordStart
name|void
name|tst_QTextBoundaryFinder
operator|::
name|isAtWordStart
parameter_list|()
block|{
name|QString
name|txt
argument_list|(
literal|"The quick brown fox jumped over $the lazy. dog  I win!"
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|start
decl_stmt|,
name|end
decl_stmt|;
name|start
operator|<<
literal|0
operator|<<
literal|4
operator|<<
literal|10
operator|<<
literal|16
operator|<<
literal|20
operator|<<
literal|27
operator|<<
literal|32
operator|<<
literal|33
operator|<<
literal|37
operator|<<
literal|41
operator|<<
literal|43
operator|<<
literal|48
operator|<<
literal|50
operator|<<
literal|53
expr_stmt|;
name|end
operator|<<
literal|3
operator|<<
literal|9
operator|<<
literal|15
operator|<<
literal|19
operator|<<
literal|26
operator|<<
literal|31
operator|<<
literal|33
operator|<<
literal|36
operator|<<
literal|41
operator|<<
literal|42
operator|<<
literal|46
operator|<<
literal|49
operator|<<
literal|53
operator|<<
literal|54
expr_stmt|;
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Word
argument_list|,
name|txt
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
operator|<
name|txt
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|finder
operator|.
name|setPosition
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QTextBoundaryFinder
operator|::
name|BoundaryReasons
name|r
init|=
name|finder
operator|.
name|boundaryReasons
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|r
operator|&
name|QTextBoundaryFinder
operator|::
name|StartWord
operator|)
operator|!=
literal|0
argument_list|,
name|start
operator|.
name|contains
argument_list|(
name|i
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|r
operator|&
name|QTextBoundaryFinder
operator|::
name|EndWord
operator|)
operator|!=
literal|0
argument_list|,
name|end
operator|.
name|contains
argument_list|(
name|i
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fastConstructor
name|void
name|tst_QTextBoundaryFinder
operator|::
name|fastConstructor
parameter_list|()
block|{
name|QString
name|text
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Word
argument_list|,
name|text
operator|.
name|constData
argument_list|()
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
comment|/*buffer*/
literal|0
argument_list|,
comment|/*buffer size*/
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|boundaryReasons
argument_list|()
operator|==
name|QTextBoundaryFinder
operator|::
name|StartWord
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|boundaryReasons
argument_list|()
operator|==
name|QTextBoundaryFinder
operator|::
name|EndWord
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|boundaryReasons
argument_list|()
operator|==
name|QTextBoundaryFinder
operator|::
name|StartWord
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|boundaryReasons
argument_list|()
operator|==
name|QTextBoundaryFinder
operator|::
name|EndWord
argument_list|)
expr_stmt|;
name|finder
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|boundaryReasons
argument_list|()
operator|==
name|QTextBoundaryFinder
operator|::
name|NotAtBoundary
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|finder
operator|.
name|position
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isAtBoundaryLine
name|void
name|tst_QTextBoundaryFinder
operator|::
name|isAtBoundaryLine
parameter_list|()
block|{
comment|// idx       0       1       2       3       4       5      6
comment|// break?    -       -       -       -       +       -      +
name|QChar
name|s
index|[]
init|=
block|{
literal|0x0061
block|,
literal|0x00AD
block|,
literal|0x0062
block|,
literal|0x0009
block|,
literal|0x0063
block|,
literal|0x0064
block|}
decl_stmt|;
name|QString
name|text
argument_list|(
name|s
argument_list|,
sizeof|sizeof
argument_list|(
name|s
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|s
index|[
literal|0
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|QTextBoundaryFinder
name|finder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Line
argument_list|,
name|text
operator|.
name|constData
argument_list|()
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
comment|/*buffer*/
literal|0
argument_list|,
comment|/*buffer size*/
literal|0
argument_list|)
decl_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
name|finder
operator|.
name|setPosition
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finder
operator|.
name|isAtBoundary
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QList<int>
argument_list|)
end_macro
begin_function
DECL|function|toNextBoundary_data
name|void
name|tst_QTextBoundaryFinder
operator|::
name|toNextBoundary_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"boundaries"
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|boundaries
decl_stmt|;
name|boundaries
operator|<<
literal|0
operator|<<
literal|3
operator|<<
literal|4
operator|<<
literal|7
operator|<<
literal|8
operator|<<
literal|11
operator|<<
literal|12
operator|<<
literal|13
operator|<<
literal|16
operator|<<
literal|17
operator|<<
literal|20
operator|<<
literal|21
operator|<<
literal|24
operator|<<
literal|25
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Word
argument_list|)
expr|\
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|0
operator|<<
literal|13
operator|<<
literal|25
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Sentence
argument_list|)
expr|\
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|0
operator|<<
literal|4
operator|<<
literal|8
operator|<<
literal|13
operator|<<
literal|17
operator|<<
literal|21
operator|<<
literal|25
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Line
argument_list|)
expr|\
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|0
operator|<<
literal|5
operator|<<
literal|9
operator|<<
literal|15
operator|<<
literal|17
operator|<<
literal|21
operator|<<
literal|28
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Diga-nos qualÃ© a sua opiniÃ£o"
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Line
argument_list|)
operator|<<
name|boundaries
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toNextBoundary
name|void
name|tst_QTextBoundaryFinder
operator|::
name|toNextBoundary
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|boundaries
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|foundBoundaries
decl_stmt|;
name|QTextBoundaryFinder
name|boundaryFinder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|BoundaryType
argument_list|(
name|type
argument_list|)
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|boundaryFinder
operator|.
name|toStart
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|next
init|=
literal|0
init|;
name|next
operator|!=
operator|-
literal|1
condition|;
name|next
operator|=
name|boundaryFinder
operator|.
name|toNextBoundary
argument_list|()
control|)
name|foundBoundaries
operator|<<
name|next
expr_stmt|;
name|QCOMPARE
argument_list|(
name|boundaries
argument_list|,
name|foundBoundaries
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toPreviousBoundary_data
name|void
name|tst_QTextBoundaryFinder
operator|::
name|toPreviousBoundary_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"boundaries"
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|boundaries
decl_stmt|;
name|boundaries
operator|<<
literal|25
operator|<<
literal|24
operator|<<
literal|21
operator|<<
literal|20
operator|<<
literal|17
operator|<<
literal|16
operator|<<
literal|13
operator|<<
literal|12
operator|<<
literal|11
operator|<<
literal|8
operator|<<
literal|7
operator|<<
literal|4
operator|<<
literal|3
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Word
argument_list|)
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|25
operator|<<
literal|13
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Sentence
argument_list|)
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|25
operator|<<
literal|21
operator|<<
literal|17
operator|<<
literal|13
operator|<<
literal|8
operator|<<
literal|4
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Aaa bbb ccc. Ddd eee fff."
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Line
argument_list|)
operator|<<
name|boundaries
expr_stmt|;
name|boundaries
operator|.
name|clear
argument_list|()
expr_stmt|;
name|boundaries
operator|<<
literal|28
operator|<<
literal|21
operator|<<
literal|17
operator|<<
literal|15
operator|<<
literal|9
operator|<<
literal|5
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Line"
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Diga-nos qualÃ© a sua opiniÃ£o"
argument_list|)
operator|<<
name|int
argument_list|(
name|QTextBoundaryFinder
operator|::
name|Line
argument_list|)
operator|<<
name|boundaries
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toPreviousBoundary
name|void
name|tst_QTextBoundaryFinder
operator|::
name|toPreviousBoundary
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|boundaries
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|foundBoundaries
decl_stmt|;
name|QTextBoundaryFinder
name|boundaryFinder
argument_list|(
name|QTextBoundaryFinder
operator|::
name|BoundaryType
argument_list|(
name|type
argument_list|)
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|boundaryFinder
operator|.
name|toEnd
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|previous
init|=
name|boundaryFinder
operator|.
name|position
argument_list|()
init|;
name|previous
operator|!=
operator|-
literal|1
condition|;
name|previous
operator|=
name|boundaryFinder
operator|.
name|toPreviousBoundary
argument_list|()
control|)
block|{
name|foundBoundaries
operator|<<
name|previous
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|boundaries
argument_list|,
name|foundBoundaries
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTextBoundaryFinder
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtextboundaryfinder.moc"
end_include
end_unit
