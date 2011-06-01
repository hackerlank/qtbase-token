begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtconcurrentrun.h>
end_include
begin_comment
comment|// #include<qtconcurrentcreatefunctor.h>
end_comment
begin_include
include|#
directive|include
file|<qfuture.h>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"../qfuture/versioncheck.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT_TEST
end_ifndef
begin_using
using|using
namespace|namespace
name|QtConcurrent
namespace|;
end_using
begin_class
DECL|class|tst_QtConcurrentRun
class|class
name|tst_QtConcurrentRun
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|runLightFunction
parameter_list|()
function_decl|;
name|void
name|runHeavyFunction
parameter_list|()
function_decl|;
name|void
name|returnValue
parameter_list|()
function_decl|;
name|void
name|functionObject
parameter_list|()
function_decl|;
name|void
name|memberFunctions
parameter_list|()
function_decl|;
name|void
name|implicitConvertibleTypes
parameter_list|()
function_decl|;
name|void
name|runWaitLoop
parameter_list|()
function_decl|;
name|void
name|recursive
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|exceptions
parameter_list|()
function_decl|;
endif|#
directive|endif
if|#
directive|if
literal|0
private|void createFunctor();
endif|#
directive|endif
name|void
name|functor
parameter_list|()
function_decl|;
name|void
name|lambda
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_if
if|#
directive|if
literal|0
end_if
begin_define
define|#
directive|define
name|F
parameter_list|(
name|X
parameter_list|)
value|createFunctor(X)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|F
define|#
directive|define
name|F
parameter_list|(
name|X
parameter_list|)
value|X
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtConcurrentRun
argument_list|)
end_macro
begin_function
DECL|function|light
name|void
name|light
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"in function"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"done function"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|heavy
name|void
name|heavy
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"in function"
argument_list|)
expr_stmt|;
name|QString
name|str
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
literal|1000000
condition|;
operator|++
name|i
control|)
name|str
operator|.
name|append
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"done function"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runLightFunction
name|void
name|tst_QtConcurrentRun
operator|::
name|runLightFunction
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"starting function"
argument_list|)
expr_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
init|=
name|run
argument_list|(
name|F
argument_list|(
name|light
argument_list|)
argument_list|)
decl_stmt|;
name|qDebug
argument_list|(
literal|"waiting"
argument_list|)
expr_stmt|;
name|future
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|qDebug
argument_list|(
literal|"done"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runHeavyFunction
name|void
name|tst_QtConcurrentRun
operator|::
name|runHeavyFunction
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"starting function"
argument_list|)
expr_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|future
init|=
name|run
argument_list|(
name|F
argument_list|(
name|heavy
argument_list|)
argument_list|)
decl_stmt|;
name|qDebug
argument_list|(
literal|"waiting"
argument_list|)
expr_stmt|;
name|future
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|qDebug
argument_list|(
literal|"done"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|returnInt0
name|int
name|returnInt0
parameter_list|()
block|{
return|return
literal|10
return|;
block|}
end_function
begin_function
DECL|function|returnInt1
name|int
name|returnInt1
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function
begin_class
DECL|class|A
class|class
name|A
block|{
public|public:
DECL|function|member0
name|int
name|member0
parameter_list|()
block|{
return|return
literal|10
return|;
block|}
DECL|function|member1
name|int
name|member1
parameter_list|(
name|int
name|in
parameter_list|)
block|{
return|return
name|in
return|;
block|}
DECL|typedef|result_type
typedef|typedef
name|int
name|result_type
typedef|;
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|()
block|{
return|return
literal|10
return|;
block|}
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|(
name|int
name|in
parameter_list|)
block|{
return|return
name|in
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|AConst
class|class
name|AConst
block|{
public|public:
DECL|function|member0
name|int
name|member0
parameter_list|()
specifier|const
block|{
return|return
literal|10
return|;
block|}
DECL|function|member1
name|int
name|member1
parameter_list|(
name|int
name|in
parameter_list|)
specifier|const
block|{
return|return
name|in
return|;
block|}
DECL|typedef|result_type
typedef|typedef
name|int
name|result_type
typedef|;
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|()
specifier|const
block|{
return|return
literal|10
return|;
block|}
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|(
name|int
name|in
parameter_list|)
specifier|const
block|{
return|return
name|in
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|returnValue
name|void
name|tst_QtConcurrentRun
operator|::
name|returnValue
parameter_list|()
block|{
name|QFuture
argument_list|<
name|int
argument_list|>
name|f
decl_stmt|;
name|f
operator|=
name|run
argument_list|(
name|F
argument_list|(
name|returnInt0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|A
name|a
decl_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|a
argument_list|,
name|F
argument_list|(
operator|&
name|A
operator|::
name|member0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|a
argument_list|,
name|F
argument_list|(
operator|&
name|A
operator|::
name|member1
argument_list|)
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|a
argument_list|,
name|F
argument_list|(
operator|&
name|A
operator|::
name|member0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|a
argument_list|,
name|F
argument_list|(
operator|&
name|A
operator|::
name|member1
argument_list|)
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|a
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|a
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
specifier|const
name|AConst
name|aConst
init|=
name|AConst
argument_list|()
decl_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|aConst
argument_list|,
operator|&
name|AConst
operator|::
name|member0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|aConst
argument_list|,
name|F
argument_list|(
operator|&
name|AConst
operator|::
name|member1
argument_list|)
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|aConst
argument_list|,
name|F
argument_list|(
operator|&
name|AConst
operator|::
name|member0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|aConst
argument_list|,
name|F
argument_list|(
operator|&
name|AConst
operator|::
name|member1
argument_list|)
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|aConst
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|aConst
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|aConst
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
operator|&
name|aConst
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|result
argument_list|()
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|TestClass
struct|struct
name|TestClass
block|{
DECL|function|foo
name|void
name|foo
parameter_list|()
block|{ }
DECL|typedef|result_type
typedef|typedef
name|void
name|result_type
typedef|;
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|()
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|)
block|{ }
DECL|function|fooInt
name|void
name|fooInt
parameter_list|(
name|int
parameter_list|)
block|{ }
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|TestConstClass
struct|struct
name|TestConstClass
block|{
DECL|function|foo
name|void
name|foo
parameter_list|()
specifier|const
block|{ }
DECL|typedef|result_type
typedef|typedef
name|void
name|result_type
typedef|;
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|()
specifier|const
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{ }
DECL|function|fooInt
name|void
name|fooInt
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{ }
empty_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|functionObject
name|void
name|tst_QtConcurrentRun
operator|::
name|functionObject
parameter_list|()
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|f
decl_stmt|;
name|TestClass
name|c
decl_stmt|;
name|f
operator|=
name|run
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|F
argument_list|(
operator|&
name|c
argument_list|)
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|c
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|F
argument_list|(
operator|&
name|c
argument_list|)
argument_list|,
literal|10
argument_list|)
expr_stmt|;
specifier|const
name|TestConstClass
name|cc
init|=
name|TestConstClass
argument_list|()
decl_stmt|;
name|f
operator|=
name|run
argument_list|(
name|cc
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|F
argument_list|(
operator|&
name|cc
argument_list|)
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|cc
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|f
operator|=
name|run
argument_list|(
name|F
argument_list|(
operator|&
name|cc
argument_list|)
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|memberFunctions
name|void
name|tst_QtConcurrentRun
operator|::
name|memberFunctions
parameter_list|()
block|{
name|TestClass
name|c
decl_stmt|;
name|run
argument_list|(
name|c
argument_list|,
name|F
argument_list|(
operator|&
name|TestClass
operator|::
name|foo
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
operator|&
name|c
argument_list|,
name|F
argument_list|(
operator|&
name|TestClass
operator|::
name|foo
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|c
argument_list|,
name|F
argument_list|(
operator|&
name|TestClass
operator|::
name|fooInt
argument_list|)
argument_list|,
literal|10
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
operator|&
name|c
argument_list|,
name|F
argument_list|(
operator|&
name|TestClass
operator|::
name|fooInt
argument_list|)
argument_list|,
literal|10
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
specifier|const
name|TestConstClass
name|cc
init|=
name|TestConstClass
argument_list|()
decl_stmt|;
name|run
argument_list|(
name|cc
argument_list|,
name|F
argument_list|(
operator|&
name|TestConstClass
operator|::
name|foo
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
operator|&
name|cc
argument_list|,
name|F
argument_list|(
operator|&
name|TestConstClass
operator|::
name|foo
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|cc
argument_list|,
name|F
argument_list|(
operator|&
name|TestConstClass
operator|::
name|fooInt
argument_list|)
argument_list|,
literal|10
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
operator|&
name|cc
argument_list|,
name|F
argument_list|(
operator|&
name|TestConstClass
operator|::
name|fooInt
argument_list|)
argument_list|,
literal|10
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doubleFunction
name|void
name|doubleFunction
parameter_list|(
name|double
parameter_list|)
block|{  }
end_function
begin_function
DECL|function|stringConstRefFunction
name|void
name|stringConstRefFunction
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{  }
end_function
begin_function
DECL|function|stringRefFunction
name|void
name|stringRefFunction
parameter_list|(
name|QString
modifier|&
parameter_list|)
block|{  }
end_function
begin_function
DECL|function|stringFunction
name|void
name|stringFunction
parameter_list|(
name|QString
parameter_list|)
block|{  }
end_function
begin_function
DECL|function|stringIntFunction
name|void
name|stringIntFunction
parameter_list|(
name|QString
parameter_list|)
block|{  }
end_function
begin_function
DECL|function|implicitConvertibleTypes
name|void
name|tst_QtConcurrentRun
operator|::
name|implicitConvertibleTypes
parameter_list|()
block|{
name|double
name|d
decl_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|doubleFunction
argument_list|)
argument_list|,
name|d
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|int
name|i
decl_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|doubleFunction
argument_list|)
argument_list|,
name|d
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|doubleFunction
argument_list|)
argument_list|,
name|i
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|doubleFunction
argument_list|)
argument_list|,
literal|10
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|stringFunction
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|stringConstRefFunction
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QString
name|string
decl_stmt|;
name|run
argument_list|(
name|F
argument_list|(
name|stringRefFunction
argument_list|)
argument_list|,
name|string
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fn
name|void
name|fn
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|runWaitLoop
name|void
name|tst_QtConcurrentRun
operator|::
name|runWaitLoop
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000
condition|;
operator|++
name|i
control|)
name|run
argument_list|(
name|fn
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|count
name|QAtomicInt
name|count
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|recursiveRun
name|void
name|recursiveRun
parameter_list|(
name|int
name|level
parameter_list|)
block|{
name|count
operator|.
name|ref
argument_list|()
expr_stmt|;
if|if
condition|(
operator|--
name|level
operator|>
literal|0
condition|)
block|{
name|QFuture
argument_list|<
name|void
argument_list|>
name|f1
init|=
name|run
argument_list|(
name|recursiveRun
argument_list|,
name|level
argument_list|)
decl_stmt|;
name|QFuture
argument_list|<
name|void
argument_list|>
name|f2
init|=
name|run
argument_list|(
name|recursiveRun
argument_list|,
name|level
argument_list|)
decl_stmt|;
name|f1
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|f2
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|recursiveResult
name|int
name|recursiveResult
parameter_list|(
name|int
name|level
parameter_list|)
block|{
name|count
operator|.
name|ref
argument_list|()
expr_stmt|;
if|if
condition|(
operator|--
name|level
operator|>
literal|0
condition|)
block|{
name|QFuture
argument_list|<
name|int
argument_list|>
name|f1
init|=
name|run
argument_list|(
name|recursiveResult
argument_list|,
name|level
argument_list|)
decl_stmt|;
name|QFuture
argument_list|<
name|int
argument_list|>
name|f2
init|=
name|run
argument_list|(
name|recursiveResult
argument_list|,
name|level
argument_list|)
decl_stmt|;
return|return
name|f1
operator|.
name|result
argument_list|()
operator|+
name|f2
operator|.
name|result
argument_list|()
return|;
block|}
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|recursive
name|void
name|tst_QtConcurrentRun
operator|::
name|recursive
parameter_list|()
block|{
name|int
name|levels
init|=
literal|15
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
name|QThread
operator|::
name|idealThreadCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|count
operator|=
literal|0
expr_stmt|;
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|setMaxThreadCount
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|recursiveRun
argument_list|(
name|levels
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|count
argument_list|,
operator|(
name|int
operator|)
name|pow
argument_list|(
literal|2.0
argument_list|,
name|levels
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QThread
operator|::
name|idealThreadCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|count
operator|=
literal|0
expr_stmt|;
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
operator|->
name|setMaxThreadCount
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|recursiveResult
argument_list|(
name|levels
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|count
argument_list|,
operator|(
name|int
operator|)
name|pow
argument_list|(
literal|2.0
argument_list|,
name|levels
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|e
name|int
name|e
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|vfn0
name|void
name|vfn0
parameter_list|()
block|{
operator|++
name|e
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fn0
name|int
name|fn0
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|vfn1
name|void
name|vfn1
parameter_list|(
name|double
parameter_list|)
block|{
operator|++
name|e
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fn1
name|int
name|fn1
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|vfn2
name|void
name|vfn2
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
block|{
operator|++
name|e
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fn2
name|int
name|fn2
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_function
DECL|function|throwFunction
name|void
name|throwFunction
parameter_list|()
block|{
throw|throw
name|QtConcurrent
operator|::
name|Exception
argument_list|()
throw|;
block|}
end_function
begin_function
DECL|function|throwFunctionReturn
name|int
name|throwFunctionReturn
parameter_list|()
block|{
throw|throw
name|QtConcurrent
operator|::
name|Exception
argument_list|()
throw|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|exceptions
name|void
name|tst_QtConcurrentRun
operator|::
name|exceptions
parameter_list|()
block|{
name|bool
name|caught
init|=
literal|false
decl_stmt|;
try|try
block|{
name|QtConcurrent
operator|::
name|run
argument_list|(
name|throwFunction
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
modifier|&
name|e
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|caught
condition|)
name|QFAIL
argument_list|(
literal|"did not get exception"
argument_list|)
expr_stmt|;
name|caught
operator|=
literal|false
expr_stmt|;
try|try
block|{
name|QtConcurrent
operator|::
name|run
argument_list|(
name|throwFunctionReturn
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
modifier|&
name|e
parameter_list|)
block|{
name|caught
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|caught
condition|)
name|QFAIL
argument_list|(
literal|"did not get exception"
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
unit|void tst_QtConcurrentRun::createFunctor() {     e = 0;     ::QtConcurrent::createFunctor(vfn0)();     e += QtConcurrent::createFunctor(fn0)();     ::QtConcurrent::createFunctor(vfn1)(1);
comment|// implicit conversions should work
end_comment
begin_comment
unit|e += QtConcurrent::createFunctor(fn1)(2);     ::QtConcurrent::createFunctor(vfn2)(1.0,&e);     e += QtConcurrent::createFunctor(fn2)(2,&e);     QCOMPARE(e, 6);       e = 0;     TestClass c;
comment|//    ::QtConcurrent::createFunctor(c,&TestClass::foo)();
end_comment
begin_comment
unit|::QtConcurrent::createFunctor(&c,&TestClass::foo)();
comment|//    ::QtConcurrent::createFunctor(c,&TestClass::fooInt)(10);
end_comment
begin_comment
unit|::QtConcurrent::createFunctor(&c,&TestClass::fooInt)(10);      const TestConstClass cc = TestConstClass();
comment|/*     ::QtConcurrent::createFunctor(cc,&TestConstClass::foo)();     ::QtConcurrent::createFunctor(&cc,&TestConstClass::foo)();     ::QtConcurrent::createFunctor(cc,&TestConstClass::fooInt(10);     ::QtConcurrent::createFunctor(&cc,&TestConstClass::fooInt)(10); */
end_comment
begin_endif
unit|qDebug()<< e; }
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|Functor
struct|struct
name|Functor
block|{
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|()
block|{
return|return
literal|42
return|;
block|}
DECL|function|operator ()
name|double
name|operator
name|()
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
return|return
name|a
operator|/
name|b
return|;
block|}
DECL|function|operator ()
name|int
name|operator
name|()
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|/
name|b
return|;
block|}
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|)
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{ }
DECL|function|operator ()
name|void
name|operator
name|()
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{ }
block|}
struct|;
end_struct
begin_function
DECL|function|functor
name|void
name|tst_QtConcurrentRun
operator|::
name|functor
parameter_list|()
block|{
comment|//this test functor without result_type,  decltype need to be supported by the compiler
ifndef|#
directive|ifndef
name|Q_COMPILER_DECLTYPE
name|QSKIP
argument_list|(
literal|"Compiler do not suport decltype"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|Functor
name|f
decl_stmt|;
block|{
name|QFuture
argument_list|<
name|int
argument_list|>
name|fut
init|=
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fut
operator|.
name|result
argument_list|()
argument_list|,
literal|42
argument_list|)
expr_stmt|;
block|}
block|{
name|QFuture
argument_list|<
name|double
argument_list|>
name|fut
init|=
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|8.5
argument_list|,
literal|1.8
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fut
operator|.
name|result
argument_list|()
argument_list|,
operator|(
literal|8.5
operator|/
literal|1.8
operator|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QFuture
argument_list|<
name|int
argument_list|>
name|fut
init|=
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|19
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fut
operator|.
name|result
argument_list|()
argument_list|,
name|int
argument_list|(
literal|19
operator|/
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|1
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|QtConcurrent
operator|::
name|run
argument_list|(
name|f
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|lambda
name|void
name|tst_QtConcurrentRun
operator|::
name|lambda
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_COMPILER_LAMBDA
name|QSKIP
argument_list|(
literal|"Compiler do not suport lambda"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|QtConcurrent
operator|::
name|run
argument_list|(
capture|[]
parameter_list|()
block|{
return|return
literal|45
return|;
block|}
argument_list|)
operator|.
name|result
argument_list|()
argument_list|,
literal|45
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QtConcurrent
operator|::
name|run
argument_list|(
capture|[]
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|15
return|;
block|}
argument_list|,
literal|12
argument_list|)
operator|.
name|result
argument_list|()
argument_list|,
literal|12
operator|+
literal|15
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QtConcurrent
operator|::
name|run
argument_list|(
capture|[]
parameter_list|(
name|int
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
argument_list|,
literal|12
argument_list|,
literal|15
argument_list|)
operator|.
name|result
argument_list|()
argument_list|,
name|double
argument_list|(
literal|12
operator|+
literal|15
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QtConcurrent
operator|::
name|run
argument_list|(
capture|[]
parameter_list|(
name|int
name|a
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
operator|.
name|result
argument_list|()
argument_list|,
literal|1
operator|+
literal|5
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
block|{
name|QString
name|str
argument_list|{
literal|"Hello World Foo"
argument_list|}
decl_stmt|;
name|QFuture
argument_list|<
name|QStringList
argument_list|>
name|f1
init|=
name|QtConcurrent
operator|::
name|run
argument_list|(
capture|[
modifier|&
capture|]
parameter_list|()
block|{
return|return
name|str
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
return|;
block|}
argument_list|)
decl_stmt|;
name|auto
name|r
init|=
name|f1
operator|.
name|result
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QStringList
argument_list|(
block|{
literal|"Hello"
block|,
literal|"World"
block|,
literal|"Foo"
block|}
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function
begin_include
include|#
directive|include
file|"tst_qtconcurrentrun.moc"
end_include
begin_else
else|#
directive|else
end_else
begin_macro
name|QTEST_NOOP_MAIN
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
