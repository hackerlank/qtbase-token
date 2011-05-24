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
file|"tokenizers/basic/basic.h"
end_include
begin_include
include|#
directive|include
file|"tokenizers/basicNamespace/basicNamespace.h"
end_include
begin_include
include|#
directive|include
file|"tokenizers/boilerplate/boilerplate.h"
end_include
begin_include
include|#
directive|include
file|"tokenizers/noToString/noToString.h"
end_include
begin_comment
comment|/*!  \class tst_QTokenAutomaton  \internal  \brief Tests the QTokenAutomaton generator.  TODO:     - Verify high Unicode codepoints     - Verify that signatures are static.  */
end_comment
begin_class
DECL|class|tst_QTokenAutomaton
class|class
name|tst_QTokenAutomaton
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|tokenizerBasic
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|tokenizerBasic
name|void
name|tst_QTokenAutomaton
operator|::
name|tokenizerBasic
parameter_list|()
specifier|const
block|{
typedef|typedef
name|QPair
argument_list|<
name|Basic
operator|::
name|Token
argument_list|,
name|QString
argument_list|>
name|TokenPair
typedef|;
typedef|typedef
name|QList
argument_list|<
name|TokenPair
argument_list|>
name|TokenPairList
typedef|;
comment|/* Tokenizer basic. */
block|{
comment|/* All the tokens matching tokens. */
block|{
name|TokenPairList
name|tokens
decl_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|_
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"abc"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|_111
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"def"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|wobbly
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"ghi"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|FFFF
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"FFFF"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|FFFG
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"FFFG"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|FFGG
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"FFGG"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|FFGF
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"FFGF"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|FFLM
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"FFLM"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|AReallyLongTokenIFreakinMeanItUKnowUKnowKnow
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"aReallyLongTokenIFreakinMeanItUKnowUKnowKnow"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|WeHaveDashes
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"we-have-dashes"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|Basic
operator|::
name|WeHaveDashes2
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"we-have-dashes-"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/* toToken(). */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|tokens
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TokenPair
modifier|&
name|at
init|=
name|tokens
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|/* QString. */
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toToken
argument_list|(
name|at
operator|.
name|second
argument_list|)
argument_list|,
name|at
operator|.
name|first
argument_list|)
expr_stmt|;
comment|/* const QChar *, int. */
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toToken
argument_list|(
name|at
operator|.
name|second
operator|.
name|constData
argument_list|()
argument_list|,
name|at
operator|.
name|second
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|at
operator|.
name|first
argument_list|)
expr_stmt|;
comment|/* QStringRef. */
specifier|const
name|QStringRef
name|ref
argument_list|(
operator|&
name|at
operator|.
name|second
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toToken
argument_list|(
name|ref
argument_list|)
argument_list|,
name|at
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
comment|/* toString(). */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|tokens
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TokenPair
modifier|&
name|at
init|=
name|tokens
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toString
argument_list|(
name|at
operator|.
name|first
argument_list|)
argument_list|,
name|at
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Tokens that we don't recognize. */
block|{
name|QStringList
name|tokens
decl_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"NO-MATCH"
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"NoKeyword"
argument_list|)
argument_list|)
expr_stmt|;
name|tokens
operator|.
name|append
argument_list|(
name|QString
argument_list|()
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
name|tokens
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toToken
argument_list|(
name|tokens
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|,
name|Basic
operator|::
name|NoKeyword
argument_list|)
expr_stmt|;
block|}
comment|/* Weird values for toToken(). */
block|{
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toString
argument_list|(
name|Basic
operator|::
name|Token
argument_list|(
literal|5000
argument_list|)
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Basic
operator|::
name|toString
argument_list|(
name|Basic
operator|::
name|NoKeyword
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTokenAutomaton
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtokenautomaton.moc"
end_include
end_unit
