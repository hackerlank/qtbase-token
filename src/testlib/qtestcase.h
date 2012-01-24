begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTCASE_H
end_ifndef
begin_define
DECL|macro|QTESTCASE_H
define|#
directive|define
name|QTESTCASE_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|macro|QVERIFY
define|#
directive|define
name|QVERIFY
parameter_list|(
name|statement
parameter_list|)
define|\
value|do {\     if (!QTest::qVerify((statement), #statement, "", __FILE__, __LINE__))\         return;\ } while (0)
DECL|macro|QFAIL
define|#
directive|define
name|QFAIL
parameter_list|(
name|message
parameter_list|)
define|\
value|do {\     QTest::qFail(message, __FILE__, __LINE__);\     return;\ } while (0)
DECL|macro|QVERIFY2
define|#
directive|define
name|QVERIFY2
parameter_list|(
name|statement
parameter_list|,
name|description
parameter_list|)
define|\
value|do {\     if (statement) {\         if (!QTest::qVerify(true, #statement, (description), __FILE__, __LINE__))\             return;\     } else {\         if (!QTest::qVerify(false, #statement, (description), __FILE__, __LINE__))\             return;\     }\ } while (0)
DECL|macro|QCOMPARE
define|#
directive|define
name|QCOMPARE
parameter_list|(
name|actual
parameter_list|,
name|expected
parameter_list|)
define|\
value|do {\     if (!QTest::qCompare(actual, expected, #actual, #expected, __FILE__, __LINE__))\         return;\ } while (0)
comment|// Will try to wait for the expression to become true while allowing event processing
DECL|macro|QTRY_VERIFY_WITH_TIMEOUT
define|#
directive|define
name|QTRY_VERIFY_WITH_TIMEOUT
parameter_list|(
name|__expr
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|do { \     const int __step = 50; \     const int __timeoutValue = __timeout; \     if (!(__expr)) { \         QTest::qWait(0); \     } \     for (int __i = 0; __i< __timeoutValue&& !(__expr); __i+=__step) { \         QTest::qWait(__step); \     } \     QVERIFY(__expr); \ } while (0)
DECL|macro|QTRY_VERIFY
define|#
directive|define
name|QTRY_VERIFY
parameter_list|(
name|__expr
parameter_list|)
value|QTRY_VERIFY_WITH_TIMEOUT(__expr, 5000)
comment|// Will try to wait for the comparison to become successful while allowing event processing
DECL|macro|QTRY_COMPARE_WITH_TIMEOUT
define|#
directive|define
name|QTRY_COMPARE_WITH_TIMEOUT
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|do { \     const int __step = 50; \     const int __timeoutValue = __timeout; \     if ((__expr) != (__expected)) { \         QTest::qWait(0); \     } \     for (int __i = 0; __i< __timeoutValue&& ((__expr) != (__expected)); __i+=__step) { \         QTest::qWait(__step); \     } \     QCOMPARE(__expr, __expected); \ } while (0)
DECL|macro|QTRY_COMPARE
define|#
directive|define
name|QTRY_COMPARE
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|)
value|QTRY_COMPARE_WITH_TIMEOUT(__expr, __expected, 5000)
ifdef|#
directive|ifdef
name|Q_CC_MSVC
DECL|macro|QSKIP
define|#
directive|define
name|QSKIP
parameter_list|(
name|statement
parameter_list|)
define|\
value|do {\     QTest::qSkip(statement, __FILE__, __LINE__);\     return;\ } while (0)
else|#
directive|else
define|#
directive|define
name|QSKIP
parameter_list|(
name|statement
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {\     if (strcmp(#__VA_ARGS__, "") != 0)\         QTest::qFail("The two argument version of QSKIP is no longer available. "\                      "Please update this test by removing the second argument in each QSKIP.", __FILE__, __LINE__);\     QTest::qSkip(statement, __FILE__, __LINE__);\     return;\ } while (0)
endif|#
directive|endif
DECL|macro|QEXPECT_FAIL
define|#
directive|define
name|QEXPECT_FAIL
parameter_list|(
name|dataIndex
parameter_list|,
name|comment
parameter_list|,
name|mode
parameter_list|)
define|\
value|do {\     if (!QTest::qExpectFail(dataIndex, comment, QTest::mode, __FILE__, __LINE__))\         return;\ } while (0)
DECL|macro|QFETCH
define|#
directive|define
name|QFETCH
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|type name = *static_cast<type *>(QTest::qData(#name, ::qMetaTypeId<type>()))
DECL|macro|QFETCH_GLOBAL
define|#
directive|define
name|QFETCH_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|type name = *static_cast<type *>(QTest::qGlobalData(#name, ::qMetaTypeId<type>()))
DECL|macro|QTEST
define|#
directive|define
name|QTEST
parameter_list|(
name|actual
parameter_list|,
name|testElement
parameter_list|)
define|\
value|do {\     if (!QTest::qTest(actual, testElement, #actual, #testElement, __FILE__, __LINE__))\         return;\ } while (0)
DECL|macro|QWARN
define|#
directive|define
name|QWARN
parameter_list|(
name|msg
parameter_list|)
define|\
value|QTest::qWarn(msg, __FILE__, __LINE__)
ifdef|#
directive|ifdef
name|QT_TESTCASE_BUILDDIR
DECL|macro|QFINDTESTDATA
define|#
directive|define
name|QFINDTESTDATA
parameter_list|(
name|basepath
parameter_list|)
define|\
value|QTest::qFindTestData(basepath, __FILE__, __LINE__, QT_TESTCASE_BUILDDIR)
else|#
directive|else
define|#
directive|define
name|QFINDTESTDATA
parameter_list|(
name|basepath
parameter_list|)
define|\
value|QTest::qFindTestData(basepath, __FILE__, __LINE__)
endif|#
directive|endif
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTestData
name|class
name|QTestData
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QTEST_COMPARE_DECL
define|#
directive|define
name|QTEST_COMPARE_DECL
parameter_list|(
name|KLASS
parameter_list|)
define|\
value|template<> Q_TESTLIB_EXPORT char *toString<KLASS>(const KLASS&);
end_define
begin_decl_stmt
name|namespace
name|QTest
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const T&
argument_list|)
block|{
return|return
literal|0
return|;
block|}
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toHexRepresentation
parameter_list|(
specifier|const
name|char
modifier|*
name|ba
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toString
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toString
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|int
name|qExec
parameter_list|(
name|QObject
modifier|*
name|testObject
parameter_list|,
name|int
name|argc
init|=
literal|0
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|int
name|qExec
parameter_list|(
name|QObject
modifier|*
name|testObject
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|qVerify
parameter_list|(
name|bool
name|statement
parameter_list|,
specifier|const
name|char
modifier|*
name|statementStr
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qFail
parameter_list|(
specifier|const
name|char
modifier|*
name|statementStr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qSkip
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|qExpectFail
parameter_list|(
specifier|const
name|char
modifier|*
name|dataIndex
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|,
name|TestFailMode
name|mode
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qWarn
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|ignoreMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|QString
name|qFindTestData
parameter_list|(
specifier|const
name|char
modifier|*
name|basepath
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|builddir
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|QString
name|qFindTestData
parameter_list|(
specifier|const
name|QString
modifier|&
name|basepath
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|builddir
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qData
parameter_list|(
specifier|const
name|char
modifier|*
name|tagName
parameter_list|,
name|int
name|typeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qGlobalData
parameter_list|(
specifier|const
name|char
modifier|*
name|tagName
parameter_list|,
name|int
name|typeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qElementData
parameter_list|(
specifier|const
name|char
modifier|*
name|elementName
parameter_list|,
name|int
name|metaTypeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|QObject
modifier|*
name|testObject
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
specifier|const
name|char
modifier|*
name|currentTestFunction
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
specifier|const
name|char
modifier|*
name|currentDataTag
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|currentTestFailed
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
name|Qt
operator|::
name|Key
name|asciiToKey
argument_list|(
argument|char ascii
argument_list|)
expr_stmt|;
name|Q_TESTLIB_EXPORT
name|char
name|keyToAscii
argument_list|(
name|Qt
operator|::
name|Key
name|key
argument_list|)
decl_stmt|;
name|Q_TESTLIB_EXPORT
name|bool
name|compare_helper
parameter_list|(
name|bool
name|success
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|compare_helper
parameter_list|(
name|bool
name|success
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|val1
parameter_list|,
name|char
modifier|*
name|val2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qSleep
parameter_list|(
name|int
name|ms
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|addColumnInternal
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|addColumn
argument_list|(
argument|const char *name
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
name|addColumnInternal
argument_list|(
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|name
argument_list|)
block|;     }
name|Q_TESTLIB_EXPORT
name|QTestData
operator|&
name|newRow
argument_list|(
specifier|const
name|char
operator|*
name|dataTag
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T const&t1
argument_list|,
argument|T const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
operator|(
name|t1
operator|==
name|t2
operator|)
operator|?
name|compare_helper
argument_list|(
name|true
argument_list|,
literal|"COMPARE()"
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
operator|:
name|compare_helper
argument_list|(
name|false
argument_list|,
literal|"Compared values are not the same"
argument_list|,
name|toString
operator|<
name|T
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|toString
operator|<
name|T
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
name|Q_TESTLIB_EXPORT
name|bool
name|qCompare
operator|<
name|float
operator|>
operator|(
name|float
specifier|const
operator|&
name|t1
operator|,
name|float
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
expr_stmt|;
name|template
operator|<
operator|>
name|Q_TESTLIB_EXPORT
name|bool
name|qCompare
operator|<
name|double
operator|>
operator|(
name|double
specifier|const
operator|&
name|t1
operator|,
name|double
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
expr_stmt|;
specifier|inline
name|bool
name|compare_ptr_helper
parameter_list|(
specifier|const
name|void
modifier|*
name|t1
parameter_list|,
specifier|const
name|void
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
operator|(
name|t1
operator|==
name|t2
operator|)
condition|?
name|compare_helper
argument_list|(
name|true
argument_list|,
literal|"COMPARE()"
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
else|:
name|compare_helper
argument_list|(
name|false
argument_list|,
literal|"Compared pointers are not the same"
argument_list|,
name|toString
argument_list|(
name|t1
argument_list|)
argument_list|,
name|toString
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|Q_TESTLIB_EXPORT
name|bool
name|compare_string_helper
parameter_list|(
specifier|const
name|char
modifier|*
name|t1
parameter_list|,
specifier|const
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|qdoc
name|QTEST_COMPARE_DECL
argument_list|(
argument|short
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|ushort
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|int
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|uint
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|long
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|ulong
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|qint64
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|quint64
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|float
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|double
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|char
argument_list|)
name|QTEST_COMPARE_DECL
argument_list|(
argument|bool
argument_list|)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QTEST_NO_SPECIALIZATIONS
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|bool
name|qCompare
argument_list|(
name|T1
specifier|const
operator|&
argument_list|,
name|T2
specifier|const
operator|&
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_COORD_TYPE
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|QT_ARCH_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_FPU
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_WINDOWSCE
argument_list|)
operator|)
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|qreal
operator|,
name|float
operator|>
operator|(
name|qreal
specifier|const
operator|&
name|t1
operator|,
name|float
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|qCompare
operator|<
name|qreal
operator|>
operator|(
name|t1
operator|,
name|qreal
argument_list|(
name|t2
argument_list|)
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|float
operator|,
name|qreal
operator|>
operator|(
name|float
specifier|const
operator|&
name|t1
operator|,
name|qreal
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|qCompare
operator|<
name|qreal
operator|>
operator|(
name|qreal
argument_list|(
name|t1
argument_list|)
operator|,
name|t2
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|QT_COORD_TYPE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_FPU
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_WINDOWSCE
argument_list|)
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|qreal
operator|,
name|double
operator|>
operator|(
name|qreal
specifier|const
operator|&
name|t1
operator|,
name|double
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|qCompare
operator|<
name|float
operator|>
operator|(
name|float
argument_list|(
name|t1
argument_list|)
operator|,
name|float
argument_list|(
name|t2
argument_list|)
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|double
operator|,
name|qreal
operator|>
operator|(
name|double
specifier|const
operator|&
name|t1
operator|,
name|qreal
specifier|const
operator|&
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|qCompare
operator|<
name|float
operator|>
operator|(
name|float
argument_list|(
name|t1
argument_list|)
operator|,
name|float
argument_list|(
name|t2
argument_list|)
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
endif|#
directive|endif
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|const T *t1
argument_list|,
argument|const T *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T *t1
argument_list|,
argument|T *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|const T1 *t1
argument_list|,
argument|const T2 *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|static_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T1 *t1
argument_list|,
argument|T2 *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|const_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|static_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|const_cast
operator|<
specifier|const
name|T2
operator|*
operator|>
operator|(
name|t2
operator|)
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|char
operator|>
operator|(
specifier|const
name|char
operator|*
name|t1
operator|,
specifier|const
name|char
operator|*
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
operator|<
name|char
operator|>
operator|(
name|char
operator|*
name|t1
operator|,
name|char
operator|*
name|t2
operator|,
specifier|const
name|char
operator|*
name|actual
operator|,
specifier|const
name|char
operator|*
name|expected
operator|,
specifier|const
name|char
operator|*
name|file
operator|,
name|int
name|line
operator|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
else|#
directive|else
comment|/* QTEST_NO_SPECIALIZATIONS */
specifier|inline
name|bool
name|qCompare
parameter_list|(
specifier|const
name|char
modifier|*
name|t1
parameter_list|,
specifier|const
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|char
modifier|*
name|t1
parameter_list|,
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|/* The next two specializations are for MSVC that shows problems with implicit        conversions      */
ifndef|#
directive|ifndef
name|QTEST_NO_SPECIALIZATIONS
name|template
operator|<
operator|>
endif|#
directive|endif
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|char *t1
argument_list|,
argument|const char *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|QTEST_NO_SPECIALIZATIONS
name|template
operator|<
operator|>
endif|#
directive|endif
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|const char *t1
argument_list|,
argument|char *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
comment|// NokiaX86 and RVCT do not like implicitly comparing bool with int
ifndef|#
directive|ifndef
name|QTEST_NO_SPECIALIZATIONS
name|template
operator|<
operator|>
endif|#
directive|endif
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|bool const&t1
argument_list|,
argument|int const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
operator|<
name|int
operator|>
operator|(
name|int
argument_list|(
name|t1
argument_list|)
operator|,
name|t2
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|qTest
argument_list|(
argument|const T& actual
argument_list|,
argument|const char *elementName
argument_list|,
argument|const char *actualStr
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|actual
argument_list|,
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|QTest
operator|::
name|qElementData
argument_list|(
name|elementName
argument_list|,
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
operator|)
argument_list|,
name|actualStr
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_undef
DECL|macro|QTEST_COMPARE_DECL
undef|#
directive|undef
name|QTEST_COMPARE_DECL
end_undef
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
