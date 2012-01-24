begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_define
DECL|macro|AUTOTEST
define|#
directive|define
name|AUTOTEST
end_define
begin_include
include|#
directive|include
file|"../main.cpp"
end_include
begin_class
DECL|class|tst_LexGen
class|class
name|tst_LexGen
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|nfa_singleInput
parameter_list|()
function_decl|;
name|void
name|nfa_alternating
parameter_list|()
function_decl|;
name|void
name|nfa_concatenating
parameter_list|()
function_decl|;
name|void
name|nfa_optional
parameter_list|()
function_decl|;
name|void
name|nfa_toDFA_data
parameter_list|()
function_decl|;
name|void
name|nfa_toDFA
parameter_list|()
function_decl|;
name|void
name|lexgen_data
parameter_list|()
function_decl|;
name|void
name|lexgen
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|nfa_singleInput
name|void
name|tst_LexGen
operator|::
name|nfa_singleInput
parameter_list|()
block|{
name|NFA
name|nfa
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|initialState
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|contains
argument_list|(
literal|'a'
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
literal|'a'
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
literal|'a'
argument_list|)
argument_list|,
name|nfa
operator|.
name|finalState
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|transitions
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nfa_alternating
name|void
name|tst_LexGen
operator|::
name|nfa_alternating
parameter_list|()
block|{
name|NFA
name|a
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|NFA
name|b
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'b'
argument_list|)
decl_stmt|;
name|NFA
name|nfa
init|=
name|NFA
operator|::
name|createAlternatingNFA
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
specifier|const
name|int
name|initialA
init|=
literal|1
decl_stmt|;
specifier|const
name|int
name|finalA
init|=
literal|2
decl_stmt|;
specifier|const
name|int
name|initialB
init|=
literal|3
decl_stmt|;
specifier|const
name|int
name|finalB
init|=
literal|4
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|count
argument_list|()
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|initialState
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|initialTransitions
init|=
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|initialTransitions
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|initialTransitions
operator|.
name|contains
argument_list|(
name|initialA
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|initialTransitions
operator|.
name|contains
argument_list|(
name|initialB
argument_list|)
argument_list|)
expr_stmt|;
comment|// no need to test the individual a and b NFAs, the other
comment|// autotest already takes care of that. Just check whether
comment|// the epsilon transitions to the final state exist.
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|Epsilon
argument_list|)
argument_list|,
name|nfa
operator|.
name|finalState
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalB
argument_list|)
operator|.
name|transitions
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalB
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalB
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|Epsilon
argument_list|)
argument_list|,
name|nfa
operator|.
name|finalState
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nfa_concatenating
name|void
name|tst_LexGen
operator|::
name|nfa_concatenating
parameter_list|()
block|{
name|NFA
name|a
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|NFA
name|b
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'b'
argument_list|)
decl_stmt|;
name|NFA
name|nfa
init|=
name|NFA
operator|::
name|createConcatenatingNFA
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
specifier|const
name|int
name|initialA
init|=
literal|1
decl_stmt|;
specifier|const
name|int
name|finalA
init|=
literal|2
decl_stmt|;
specifier|const
name|int
name|initialB
init|=
literal|3
decl_stmt|;
specifier|const
name|int
name|finalB
init|=
literal|4
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|count
argument_list|()
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|initialState
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|Epsilon
argument_list|)
argument_list|,
name|initialA
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|Epsilon
argument_list|)
argument_list|,
name|initialB
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalB
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalB
argument_list|)
operator|.
name|transitions
operator|.
name|value
argument_list|(
name|Epsilon
argument_list|)
argument_list|,
name|nfa
operator|.
name|finalState
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nfa_optional
name|void
name|tst_LexGen
operator|::
name|nfa_optional
parameter_list|()
block|{
name|NFA
name|a
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|NFA
name|nfa
init|=
name|NFA
operator|::
name|createOptionalNFA
argument_list|(
name|a
argument_list|)
decl_stmt|;
specifier|const
name|int
name|initialA
init|=
literal|1
decl_stmt|;
specifier|const
name|int
name|finalA
init|=
literal|2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|initialState
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|initialTransitions
init|=
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|initialTransitions
operator|.
name|contains
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|initialTransitions
operator|.
name|contains
argument_list|(
name|initialA
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|finalEpsilonATransitions
init|=
name|nfa
operator|.
name|states
operator|.
name|at
argument_list|(
name|finalA
argument_list|)
operator|.
name|transitions
operator|.
name|values
argument_list|(
name|Epsilon
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|finalEpsilonATransitions
operator|.
name|contains
argument_list|(
name|initialA
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|finalEpsilonATransitions
operator|.
name|contains
argument_list|(
name|nfa
operator|.
name|finalState
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|NFA
name|Q_DECLARE_METATYPE
argument_list|(
name|NFA
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|DFA
name|Q_DECLARE_METATYPE
argument_list|(
name|DFA
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|nfa_toDFA_data
name|void
name|tst_LexGen
operator|::
name|nfa_toDFA_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|NFA
argument_list|>
argument_list|(
literal|"nfa"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|DFA
argument_list|>
argument_list|(
literal|"expectedDFA"
argument_list|)
expr_stmt|;
name|NFA
name|a
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'a'
argument_list|)
decl_stmt|;
name|NFA
name|b
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'b'
argument_list|)
decl_stmt|;
name|NFA
name|c
init|=
name|NFA
operator|::
name|createSingleInputNFA
argument_list|(
literal|'c'
argument_list|)
decl_stmt|;
name|NFA
name|nfa
decl_stmt|;
name|DFA
name|dfa
decl_stmt|;
name|dfa
operator|.
name|clear
argument_list|()
expr_stmt|;
name|dfa
operator|.
name|resize
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|dfa
index|[
literal|0
index|]
operator|.
name|transitions
operator|.
name|insert
argument_list|(
literal|'a'
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dfa
index|[
literal|1
index|]
operator|.
name|transitions
operator|.
name|insert
argument_list|(
literal|'b'
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|nfa
operator|=
name|NFA
operator|::
name|createConcatenatingNFA
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple concat"
argument_list|)
operator|<<
name|nfa
operator|<<
name|dfa
expr_stmt|;
name|dfa
operator|.
name|clear
argument_list|()
expr_stmt|;
name|dfa
operator|.
name|resize
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|dfa
index|[
literal|0
index|]
operator|.
name|transitions
operator|.
name|insert
argument_list|(
literal|'a'
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dfa
index|[
literal|0
index|]
operator|.
name|transitions
operator|.
name|insert
argument_list|(
literal|'b'
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|nfa
operator|=
name|NFA
operator|::
name|createAlternatingNFA
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple alternate"
argument_list|)
operator|<<
name|nfa
operator|<<
name|dfa
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nfa_toDFA
name|void
name|tst_LexGen
operator|::
name|nfa_toDFA
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|NFA
argument_list|,
name|nfa
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|DFA
argument_list|,
name|expectedDFA
argument_list|)
expr_stmt|;
name|DFA
name|dfa
init|=
name|nfa
operator|.
name|toDFA
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|dfa
operator|.
name|count
argument_list|()
argument_list|,
name|expectedDFA
operator|.
name|count
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
name|dfa
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|dfa
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|transitions
operator|!=
name|expectedDFA
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|transitions
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"DFAs differ in state"
operator|<<
name|i
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"NFA:"
expr_stmt|;
name|nfa
operator|.
name|debug
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Actual DFA:"
expr_stmt|;
name|dfa
operator|.
name|debug
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Expected DFA:"
expr_stmt|;
name|expectedDFA
operator|.
name|debug
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|lexgen_data
name|void
name|tst_LexGen
operator|::
name|lexgen_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"ruleFile"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expectedOutput"
argument_list|)
expr_stmt|;
name|QDir
name|d
argument_list|(
name|QString
argument_list|(
name|SRCDIR
argument_list|)
argument_list|)
decl_stmt|;
name|d
operator|.
name|cd
argument_list|(
literal|"testdata"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|test
decl|,
name|d
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|Dirs
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
control|)
block|{
name|QString
name|dir
init|=
name|d
operator|.
name|absoluteFilePath
argument_list|(
name|test
argument_list|)
operator|+
literal|'/'
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|test
argument_list|)
argument_list|)
operator|<<
name|dir
operator|+
literal|"rules.lexgen"
operator|<<
name|dir
operator|+
literal|"input"
operator|<<
name|dir
operator|+
literal|"output"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lexgen
name|void
name|tst_LexGen
operator|::
name|lexgen
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|ruleFile
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expectedOutput
argument_list|)
expr_stmt|;
name|Config
name|conf
decl_stmt|;
name|QVERIFY
argument_list|(
name|loadConfig
argument_list|(
name|ruleFile
argument_list|,
operator|&
name|conf
argument_list|)
argument_list|)
expr_stmt|;
name|DFA
name|dfa
init|=
name|generateMachine
argument_list|(
name|conf
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|dfa
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|conf
operator|.
name|debug
operator|=
literal|true
expr_stmt|;
name|QFile
name|f
argument_list|(
name|input
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|input
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|f
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|input
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
condition|)
name|input
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//    machine.debug();
name|bool
name|ok
init|=
literal|false
decl_stmt|;
name|QList
argument_list|<
name|Symbol
argument_list|>
name|symbols
init|=
name|tokenize
argument_list|(
name|dfa
argument_list|,
name|input
argument_list|,
operator|&
name|conf
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|f
operator|.
name|setFileName
argument_list|(
name|expectedOutput
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|lines
decl_stmt|;
while|while
condition|(
operator|!
name|f
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|f
operator|.
name|readLine
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
condition|)
name|line
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|lines
operator|<<
name|line
expr_stmt|;
block|}
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
comment|//    dfa.debug();
name|QCOMPARE
argument_list|(
name|lines
operator|.
name|count
argument_list|()
argument_list|,
name|symbols
operator|.
name|count
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
name|lines
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QStringList
name|l
init|=
name|lines
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|split
argument_list|(
name|QChar
operator|::
name|fromLatin1
argument_list|(
literal|'|'
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|l
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QString
name|expectedToken
init|=
name|l
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QString
name|expectedLexem
init|=
name|l
operator|.
name|at
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|symbols
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|token
argument_list|,
name|expectedToken
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|symbols
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|lexem
argument_list|,
name|expectedLexem
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_LexGen
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_lexgen.moc"
end_include
end_unit
