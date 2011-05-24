begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine.h"
end_include
begin_include
include|#
directive|include
file|"qsignaltransition.h"
end_include
begin_comment
comment|// Will try to wait for the condition while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_COMPARE
define|#
directive|define
name|QTRY_COMPARE
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|)
define|\
value|do { \         const int __step = 50; \         const int __timeout = 5000; \         if ((__expr) != (__expected)) { \             QTest::qWait(0); \         } \         for (int __i = 0; __i< __timeout&& ((__expr) != (__expected)); __i+=__step) { \             QTest::qWait(__step); \         } \         QCOMPARE(__expr, __expected); \     } while(0)
end_define
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QState
class|class
name|tst_QState
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QState
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QState
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
if|#
directive|if
literal|0
private|void test();
endif|#
directive|endif
name|void
name|assignProperty
parameter_list|()
function_decl|;
name|void
name|assignPropertyTwice
parameter_list|()
function_decl|;
name|void
name|historyInitialState
parameter_list|()
function_decl|;
name|void
name|transitions
parameter_list|()
function_decl|;
private|private:
DECL|member|functionCalled
name|bool
name|functionCalled
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QState
name|tst_QState
operator|::
name|tst_QState
parameter_list|()
member_init_list|:
name|functionCalled
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QState
name|tst_QState
operator|::
name|~
name|tst_QState
parameter_list|()
block|{ }
end_destructor
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|void tst_QState::test() {     QStateMachine machine;     QState *s1 = new QState(&machine);      QCOMPARE(s1->machine(),&machine);     QCOMPARE(s1->parentState(),&machine);     QCOMPARE(s1->initialState(), (QState*)0);     QVERIFY(s1->childStates().isEmpty());     QVERIFY(s1->transitions().isEmpty());      QCOMPARE(s1->isFinal(), false);     s1->setFinal(true);     QCOMPARE(s1->isFinal(), true);     s1->setFinal(false);     QCOMPARE(s1->isFinal(), false);      QCOMPARE(s1->isParallel(), false);     s1->setParallel(true);     QCOMPARE(s1->isParallel(), true);     s1->setParallel(false);     QCOMPARE(s1->isParallel(), false);      QCOMPARE(s1->isAtomic(), true);     QCOMPARE(s1->isCompound(), false);     QCOMPARE(s1->isComplex(), false);      QState *s11 = new QState(s1);     QCOMPARE(s11->parentState(), s1);     QCOMPARE(s11->isAtomic(), true);     QCOMPARE(s11->isCompound(), false);     QCOMPARE(s11->isComplex(), false);     QCOMPARE(s11->machine(), s1->machine());     QVERIFY(s11->isDescendantOf(s1));      QCOMPARE(s1->initialState(), (QState*)0);     QCOMPARE(s1->childStates().size(), 1);     QCOMPARE(s1->childStates().at(0), s11);      QCOMPARE(s1->isAtomic(), false);     QCOMPARE(s1->isCompound(), true);     QCOMPARE(s1->isComplex(), true);      s1->setParallel(true);     QCOMPARE(s1->isAtomic(), false);     QCOMPARE(s1->isCompound(), false);     QCOMPARE(s1->isComplex(), true);      QState *s12 = new QState(s1);     QCOMPARE(s12->parentState(), s1);     QCOMPARE(s12->isAtomic(), true);     QCOMPARE(s12->isCompound(), false);     QCOMPARE(s12->isComplex(), false);     QCOMPARE(s12->machine(), s1->machine());     QVERIFY(s12->isDescendantOf(s1));     QVERIFY(!s12->isDescendantOf(s11));      QCOMPARE(s1->initialState(), (QState*)0);     QCOMPARE(s1->childStates().size(), 2);     QCOMPARE(s1->childStates().at(0), s11);     QCOMPARE(s1->childStates().at(1), s12);      QCOMPARE(s1->isAtomic(), false);     QCOMPARE(s1->isCompound(), false);     QCOMPARE(s1->isComplex(), true);      s1->setParallel(false);     QCOMPARE(s1->isAtomic(), false);     QCOMPARE(s1->isCompound(), true);     QCOMPARE(s1->isComplex(), true);      s1->setInitialState(s11);     QCOMPARE(s1->initialState(), s11);      s1->setInitialState(0);     QCOMPARE(s1->initialState(), (QState*)0);      s1->setInitialState(s12);     QCOMPARE(s1->initialState(), s12);      QState *s13 = new QState();     s1->setInitialState(s13);     QCOMPARE(s13->parentState(), s1);     QCOMPARE(s1->childStates().size(), 3);     QCOMPARE(s1->childStates().at(0), s11);     QCOMPARE(s1->childStates().at(1), s12);     QCOMPARE(s1->childStates().at(2), s13);     QVERIFY(s13->isDescendantOf(s1));      QVERIFY(s12->childStates().isEmpty());      QState *s121 = new QState(s12);     QCOMPARE(s121->parentState(), s12);     QCOMPARE(s121->isAtomic(), true);     QCOMPARE(s121->isCompound(), false);     QCOMPARE(s121->isComplex(), false);     QCOMPARE(s121->machine(), s12->machine());     QVERIFY(s121->isDescendantOf(s12));     QVERIFY(s121->isDescendantOf(s1));     QVERIFY(!s121->isDescendantOf(s11));      QCOMPARE(s12->childStates().size(), 1);     QCOMPARE(s12->childStates().at(0), (QState*)s121);      QCOMPARE(s1->childStates().size(), 3);     QCOMPARE(s1->childStates().at(0), s11);     QCOMPARE(s1->childStates().at(1), s12);     QCOMPARE(s1->childStates().at(2), s13);      s11->addTransition(s12);     QCOMPARE(s11->transitions().size(), 1);     QCOMPARE(s11->transitions().at(0)->sourceState(), s11);     QCOMPARE(s11->transitions().at(0)->targetStates().size(), 1);     QCOMPARE(s11->transitions().at(0)->targetStates().at(0), s12);     QCOMPARE(s11->transitions().at(0)->eventType(), QEvent::None);      QState *s14 = new QState();     s12->addTransition(QList<QState*>()<< s13<< s14);     QCOMPARE(s12->transitions().size(), 1);     QCOMPARE(s12->transitions().at(0)->sourceState(), s12);     QCOMPARE(s12->transitions().at(0)->targetStates().size(), 2);     QCOMPARE(s12->transitions().at(0)->targetStates().at(0), s13);     QCOMPARE(s12->transitions().at(0)->targetStates().at(1), s14);     QCOMPARE(s12->transitions().at(0)->eventType(), QEvent::None);      s13->addTransition(this, SIGNAL(destroyed()), s14);     QCOMPARE(s13->transitions().size(), 1);     QCOMPARE(s13->transitions().at(0)->sourceState(), s13);     QCOMPARE(s13->transitions().at(0)->targetStates().size(), 1);     QCOMPARE(s13->transitions().at(0)->targetStates().at(0), s14);     QCOMPARE(s13->transitions().at(0)->eventType(), QEvent::Signal);     QVERIFY(qobject_cast<QSignalTransition*>(s13->transitions().at(0)) != 0);      delete s13->transitions().at(0);     QCOMPARE(s13->transitions().size(), 0);      s12->addTransition(this, SIGNAL(destroyed()), s11);     QCOMPARE(s12->transitions().size(), 2); }
endif|#
directive|endif
end_endif
begin_class
DECL|class|TestClass
class|class
name|TestClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|TestClass
name|TestClass
parameter_list|()
member_init_list|:
name|called
argument_list|(
literal|false
argument_list|)
block|{}
DECL|member|called
name|bool
name|called
decl_stmt|;
public|public
name|slots
public|:
DECL|function|slot
name|void
name|slot
parameter_list|()
block|{
name|called
operator|=
literal|true
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|assignProperty
name|void
name|tst_QState
operator|::
name|assignProperty
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QObject
modifier|*
name|object
init|=
operator|new
name|QObject
argument_list|()
decl_stmt|;
name|object
operator|->
name|setProperty
argument_list|(
literal|"fooBar"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|->
name|property
argument_list|(
literal|"fooBar"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|assignPropertyTwice
name|void
name|tst_QState
operator|::
name|assignPropertyTwice
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QObject
modifier|*
name|object
init|=
operator|new
name|QObject
argument_list|()
decl_stmt|;
name|object
operator|->
name|setProperty
argument_list|(
literal|"fooBar"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|->
name|property
argument_list|(
literal|"fooBar"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|EventTestTransition
class|class
name|EventTestTransition
super|:
specifier|public
name|QAbstractTransition
block|{
public|public:
DECL|function|EventTestTransition
name|EventTestTransition
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|QState
modifier|*
name|targetState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|()
member_init_list|,
name|m_type
argument_list|(
name|type
argument_list|)
block|{
name|setTargetState
argument_list|(
name|targetState
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|eventTest
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|e
operator|->
name|type
argument_list|()
operator|==
name|m_type
return|;
block|}
DECL|function|onTransition
name|void
name|onTransition
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{}
private|private:
DECL|member|m_type
name|QEvent
operator|::
name|Type
name|m_type
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|historyInitialState
name|void
name|tst_QState
operator|::
name|historyInitialState
parameter_list|()
block|{
name|QStateMachine
name|machine
decl_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s2
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QHistoryState
modifier|*
name|h1
init|=
operator|new
name|QHistoryState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|s2
operator|->
name|setInitialState
argument_list|(
name|h1
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|h1
operator|->
name|setDefaultState
argument_list|(
name|s3
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s4
init|=
operator|new
name|QState
argument_list|(
name|s2
argument_list|)
decl_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|User
argument_list|,
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|s2
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|User
argument_list|,
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|s3
operator|->
name|addTransition
argument_list|(
operator|new
name|EventTestTransition
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|,
name|s4
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s3
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s3
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s4
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|postEvent
argument_list|(
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|machine
operator|.
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|s4
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transitions
name|void
name|tst_QState
operator|::
name|transitions
parameter_list|()
block|{
name|QState
name|s1
decl_stmt|;
name|QState
name|s2
decl_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t1
init|=
name|s1
operator|.
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s2
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|s1
operator|.
name|removeTransition
argument_list|(
name|t1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|s1
operator|.
name|addTransition
argument_list|(
name|t1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t1
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t2
init|=
operator|new
name|QEventTransition
argument_list|(
operator|&
name|s1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|contains
argument_list|(
name|t1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|s1
operator|.
name|transitions
argument_list|()
operator|.
name|contains
argument_list|(
name|t2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Transitions from child states should not be reported.
name|QState
modifier|*
name|s21
init|=
operator|new
name|QState
argument_list|(
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QAbstractTransition
modifier|*
name|t3
init|=
name|s21
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|s2
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|s2
operator|.
name|transitions
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s21
operator|->
name|transitions
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s21
operator|->
name|transitions
argument_list|()
operator|.
name|first
argument_list|()
argument_list|,
name|t3
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QState
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstate.moc"
end_include
end_unit
