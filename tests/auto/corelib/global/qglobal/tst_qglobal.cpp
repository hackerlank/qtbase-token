begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtypetraits.h>
end_include
begin_class
DECL|class|tst_QGlobal
class|class
name|tst_QGlobal
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qIsNull
parameter_list|()
function_decl|;
name|void
name|for_each
parameter_list|()
function_decl|;
name|void
name|qassert
parameter_list|()
function_decl|;
name|void
name|qtry
parameter_list|()
function_decl|;
name|void
name|checkptr
parameter_list|()
function_decl|;
name|void
name|qstaticassert
parameter_list|()
function_decl|;
name|void
name|qConstructorFunction
parameter_list|()
function_decl|;
name|void
name|isEnum
parameter_list|()
function_decl|;
name|void
name|qAlignOf
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|qIsNull
name|void
name|tst_QGlobal
operator|::
name|qIsNull
parameter_list|()
block|{
name|double
name|d
init|=
literal|0.0
decl_stmt|;
name|float
name|f
init|=
literal|0.0f
decl_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|+=
literal|0.000000001
expr_stmt|;
name|f
operator|+=
literal|0.0000001f
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|::
name|qIsNull
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|::
name|qIsNull
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|=
operator|-
literal|0.0
expr_stmt|;
name|f
operator|=
operator|-
literal|0.0f
expr_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|::
name|qIsNull
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|for_each
name|void
name|tst_QGlobal
operator|::
name|for_each
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|0
operator|<<
literal|1
operator|<<
literal|2
operator|<<
literal|3
operator|<<
literal|4
operator|<<
literal|5
expr_stmt|;
name|int
name|counter
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|int
name|i
decl|,
name|list
control|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
name|counter
operator|++
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|counter
argument_list|,
name|list
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
comment|// do it again, to make sure we don't have any for-scoping
comment|// problems with older compilers
name|counter
operator|=
literal|0
expr_stmt|;
foreach|foreach
control|(
name|int
name|i
decl|,
name|list
control|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
name|counter
operator|++
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|counter
argument_list|,
name|list
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qassert
name|void
name|tst_QGlobal
operator|::
name|qassert
parameter_list|()
block|{
name|bool
name|passed
init|=
literal|false
decl_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|passed
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"tst_QGlobal"
argument_list|,
literal|"qassert"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|passed
operator|=
literal|true
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
else|else
name|passed
operator|=
literal|true
expr_stmt|;
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
name|passed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
literal|false
condition|)
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"tst_QGlobal"
argument_list|,
literal|"qassert"
argument_list|)
expr_stmt|;
else|else
name|passed
operator|=
literal|true
expr_stmt|;
name|QVERIFY
argument_list|(
name|passed
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qtry
name|void
name|tst_QGlobal
operator|::
name|qtry
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|QT_TRY
block|{
name|i
operator|=
literal|1
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|i
operator|=
literal|7
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_NO_EXCEPTIONS
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|7
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// check propper if/else scoping
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|true
condition|)
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|2
expr_stmt|;
block|}
block|}
else|else
block|{
name|i
operator|=
literal|8
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
name|i
operator|=
literal|42
expr_stmt|;
block|}
else|else
block|{
name|QT_TRY
block|{
name|i
operator|=
literal|2
expr_stmt|;
name|QT_THROW
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|int
argument_list|)
block|{
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|i
operator|=
literal|4
expr_stmt|;
block|}
block|}
name|QCOMPARE
argument_list|(
name|i
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkptr
name|void
name|tst_QGlobal
operator|::
name|checkptr
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|QCOMPARE
argument_list|(
name|q_check_ptr
argument_list|(
operator|&
name|i
argument_list|)
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|c
init|=
literal|"hello"
decl_stmt|;
name|QCOMPARE
argument_list|(
name|q_check_ptr
argument_list|(
name|c
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Check Q_STATIC_ASSERT, It should compile
end_comment
begin_comment
comment|// note that, we are not able to test Q_STATIC_ASSERT(false), to do it manually someone has
end_comment
begin_comment
comment|// to replace expressions (in the asserts) one by one to false, and check if it breaks build.
end_comment
begin_class
DECL|class|MyTrue
class|class
name|MyTrue
block|{
public|public:
DECL|function|MyTrue
name|MyTrue
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
literal|false
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
literal|true
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
operator|!
literal|false
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
DECL|function|~MyTrue
name|~
name|MyTrue
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
literal|false
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
literal|true
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
operator|!
literal|false
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
name|Q_STATIC_ASSERT
argument_list|(
literal|true
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!
literal|false
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
literal|true
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|!
literal|false
argument_list|,
literal|""
argument_list|)
empty_stmt|;
block|}
class|;
end_class
begin_struct
DECL|struct|MyExpresion
struct|struct
name|MyExpresion
block|{
DECL|function|foo
name|void
name|foo
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
sizeof|sizeof
argument_list|(
name|MyTrue
argument_list|)
operator|>
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
private|private:
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|sizeof(MyTrue)>
literal|0
argument_list|,
literal|""
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|TypeDef
struct|struct
name|TypeDef
block|{
DECL|typedef|T
typedef|typedef
name|int
name|T
typedef|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(T)
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|sizeof(T)
argument_list|,
literal|""
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
template|template
parameter_list|<
name|typename
name|T1
parameter_list|,
name|typename
name|T2
parameter_list|>
struct|struct
DECL|struct|Template
name|Template
block|{
DECL|member|True
specifier|static
specifier|const
name|bool
name|True
init|=
literal|true
decl_stmt|;
DECL|typedef|DependentType
typedef|typedef
typename|typename
name|T1
operator|::
name|T
name|DependentType
typedef|;
name|Q_STATIC_ASSERT
parameter_list|(
name|True
parameter_list|)
constructor_decl|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!True
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|sizeof(DependentType)
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!sizeof(DependentType)
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|True
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|!!True
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|sizeof(DependentType)
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|!!sizeof(DependentType)
argument_list|,
literal|""
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|MyTemplate
struct|struct
name|MyTemplate
block|{
DECL|member|Value
specifier|static
specifier|const
name|bool
name|Value
init|=
name|Template
argument_list|<
name|TypeDef
argument_list|,
name|int
argument_list|>
operator|::
name|True
decl_stmt|;
name|Q_STATIC_ASSERT
parameter_list|(
name|Value
parameter_list|)
constructor_decl|;
name|Q_STATIC_ASSERT
argument_list|(
argument|!!Value
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|Value
argument_list|,
literal|""
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
argument|!!Value
argument_list|,
literal|""
argument_list|)
empty_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qstaticassert
name|void
name|tst_QGlobal
operator|::
name|qstaticassert
parameter_list|()
block|{
comment|// Force compilation of these classes
name|MyTrue
name|tmp1
decl_stmt|;
name|MyExpresion
name|tmp2
decl_stmt|;
name|MyTemplate
name|tmp3
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp1
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp2
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|tmp3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// if the test compiles it has passed.
block|}
end_function
begin_decl_stmt
DECL|variable|qConstructorFunctionValue
specifier|static
name|int
name|qConstructorFunctionValue
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qConstructorFunctionCtor
specifier|static
name|void
name|qConstructorFunctionCtor
parameter_list|()
block|{
name|qConstructorFunctionValue
operator|=
literal|123
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|qConstructorFunctionCtor
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
name|qConstructorFunctionCtor
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|qConstructorFunction
name|void
name|tst_QGlobal
operator|::
name|qConstructorFunction
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|qConstructorFunctionValue
argument_list|,
literal|123
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|isEnum_A
struct|struct
name|isEnum_A
block|{
DECL|member|n_
name|int
name|n_
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
DECL|enum|isEnum_B_Byte
DECL|enumerator|isEnum_B_Byte_x
enum|enum
name|isEnum_B_Byte
block|{
name|isEnum_B_Byte_x
init|=
literal|63
block|}
enum|;
end_enum
begin_enum
DECL|enum|isEnum_B_Short
DECL|enumerator|isEnum_B_Short_x
enum|enum
name|isEnum_B_Short
block|{
name|isEnum_B_Short_x
init|=
literal|1024
block|}
enum|;
end_enum
begin_enum
DECL|enum|isEnum_B_Int
DECL|enumerator|isEnum_B_Int_x
enum|enum
name|isEnum_B_Int
block|{
name|isEnum_B_Int_x
init|=
literal|1
operator|<<
literal|20
block|}
enum|;
end_enum
begin_union
DECL|union|isEnum_C
union|union
name|isEnum_C
block|{
block|}
union|;
end_union
begin_class
DECL|class|isEnum_D
class|class
name|isEnum_D
block|{
public|public:
name|operator
name|int
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|isEnum_E
class|class
name|isEnum_E
block|{
private|private:
name|operator
name|int
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|isEnum_F
class|class
name|isEnum_F
block|{
public|public:
DECL|enum|AnEnum
enum|enum
name|AnEnum
block|{}
enum|;
block|}
class|;
end_class
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CLASS_ENUM
argument_list|)
end_if
begin_enum
DECL|class|isEnum_G
enum|enum class
name|isEnum_G
enum|:
name|qint64
block|{}
enum|;
end_enum
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|isEnum
name|void
name|tst_QGlobal
operator|::
name|isEnum
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
DECL|macro|IS_ENUM_TRUE
define|#
directive|define
name|IS_ENUM_TRUE
parameter_list|(
name|x
parameter_list|)
value|(Q_IS_ENUM(x) == true)
DECL|macro|IS_ENUM_FALSE
define|#
directive|define
name|IS_ENUM_FALSE
parameter_list|(
name|x
parameter_list|)
value|(Q_IS_ENUM(x) == false)
else|#
directive|else
define|#
directive|define
name|IS_ENUM_TRUE
parameter_list|(
name|x
parameter_list|)
value|(Q_IS_ENUM(x) == true&& QtPrivate::is_enum<x>::value == true)
define|#
directive|define
name|IS_ENUM_FALSE
parameter_list|(
name|x
parameter_list|)
value|(Q_IS_ENUM(x) == false&& QtPrivate::is_enum<x>::value == false)
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
name|isEnum_B_Byte
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
name|isEnum_B_Byte
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|volatile
name|isEnum_B_Byte
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
specifier|volatile
name|isEnum_B_Byte
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
name|isEnum_B_Short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
name|isEnum_B_Short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|volatile
name|isEnum_B_Short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
specifier|volatile
name|isEnum_B_Short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
name|isEnum_B_Int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
name|isEnum_B_Int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|volatile
name|isEnum_B_Int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
specifier|volatile
name|isEnum_B_Int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
name|isEnum_F
operator|::
name|AnEnum
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
name|isEnum_F
operator|::
name|AnEnum
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|volatile
name|isEnum_F
operator|::
name|AnEnum
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_TRUE
argument_list|(
specifier|const
specifier|volatile
name|isEnum_F
operator|::
name|AnEnum
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|void
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_B_Byte
operator|&
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_B_Byte
index|[
literal|1
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
specifier|const
name|isEnum_B_Byte
index|[
literal|1
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_B_Byte
index|[]
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_A
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_A
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
specifier|const
name|isEnum_A
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_C
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_D
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|isEnum_E
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|void
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
argument|int isEnum_A::*
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|void
argument_list|(
name|isEnum_A
operator|::
modifier|*
argument_list|)
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|size_t
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|bool
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
argument|unsigned char
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
argument|unsigned short
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
argument|unsigned int
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|long
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
argument|unsigned long
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|qint8
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|quint8
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|qint16
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|quint16
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|qint32
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|qint64
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|quint64
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_UNICODE_STRINGS
argument_list|)
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|char16_t
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|IS_ENUM_FALSE
argument_list|(
name|char32_t
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CLASS_ENUM
argument_list|)
comment|// Strongly type class enums are not handled by the
comment|// fallback type traits implementation. Any compiler
comment|// supported by Qt that supports C++0x class enums
comment|// should also support the __is_enum intrinsic.
name|QVERIFY
argument_list|(
name|Q_IS_ENUM
argument_list|(
name|isEnum_G
argument_list|)
operator|==
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
DECL|macro|IS_ENUM_TRUE
undef|#
directive|undef
name|IS_ENUM_TRUE
DECL|macro|IS_ENUM_FALSE
undef|#
directive|undef
name|IS_ENUM_FALSE
block|}
end_function
begin_struct
DECL|struct|Empty
struct|struct
name|Empty
block|{
block|}
struct|;
end_struct
begin_struct
DECL|struct|AlignmentInStruct
DECL|member|dummy
template|template
parameter_list|<
name|class
name|T
parameter_list|>
struct|struct
name|AlignmentInStruct
block|{
name|T
name|dummy
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|fun
typedef|typedef
name|int
function_decl|(
modifier|*
name|fun
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_typedef
DECL|typedef|memFun
typedef|typedef
name|int
function_decl|(
name|Empty
operator|::
modifier|*
name|memFun
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_define
DECL|macro|TEST_AlignOf
define|#
directive|define
name|TEST_AlignOf
parameter_list|(
name|type
parameter_list|,
name|alignment
parameter_list|)
define|\
value|do {                                                                    \         TEST_AlignOf_impl(type, alignment);                                 \                                                                             \         TEST_AlignOf_impl(type&, alignment);                               \         TEST_AlignOf_RValueRef(type&&, alignment);                         \                                                                             \         TEST_AlignOf_impl(type [5], alignment);                             \         TEST_AlignOf_impl(type (&) [5], alignment);                         \                                                                             \         TEST_AlignOf_impl(AlignmentInStruct<type>, alignment);              \                                                                             \
comment|/* Some internal sanity validation, just for fun */
value|\         TEST_AlignOf_impl(AlignmentInStruct<type [5]>, alignment);          \         TEST_AlignOf_impl(AlignmentInStruct<type&>, Q_ALIGNOF(void *));    \         TEST_AlignOf_impl(AlignmentInStruct<type (&) [5]>,                  \                 Q_ALIGNOF(void *));                                         \         TEST_AlignOf_RValueRef(AlignmentInStruct<type&&>,                  \                 Q_ALIGNOF(void *));                                         \     } while (false)
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_define
DECL|macro|TEST_AlignOf_RValueRef
define|#
directive|define
name|TEST_AlignOf_RValueRef
parameter_list|(
name|type
parameter_list|,
name|alignment
parameter_list|)
define|\
value|TEST_AlignOf_impl(type, alignment)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|TEST_AlignOf_RValueRef
define|#
directive|define
name|TEST_AlignOf_RValueRef
parameter_list|(
name|type
parameter_list|,
name|alignment
parameter_list|)
value|do {} while (false)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|TEST_AlignOf_impl
define|#
directive|define
name|TEST_AlignOf_impl
parameter_list|(
name|type
parameter_list|,
name|alignment
parameter_list|)
define|\
value|do { \         QCOMPARE(Q_ALIGNOF(type), size_t(alignment)); \
comment|/* Compare to native operator for compilers that support it,            otherwise...  erm... check consistency! :-) */
value|\         QCOMPARE(QT_EMULATED_ALIGNOF(type), Q_ALIGNOF(type)); \     } while (false)
end_define
begin_comment
comment|/**/
end_comment
begin_function
DECL|function|qAlignOf
name|void
name|tst_QGlobal
operator|::
name|qAlignOf
parameter_list|()
block|{
comment|// Built-in types, except 64-bit integers and double
name|TEST_AlignOf
argument_list|(
name|char
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
argument|signed char
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|TEST_AlignOf
argument_list|(
argument|unsigned char
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|TEST_AlignOf
argument_list|(
name|qint8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|quint8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|qint16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|quint16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|qint32
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|quint32
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|void
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|// Depends on platform and compiler, disabling test for now
comment|// TEST_AlignOf(long double, 16);
comment|// Empty struct
name|TEST_AlignOf
argument_list|(
name|Empty
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// Function pointers
name|TEST_AlignOf
argument_list|(
name|fun
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf
argument_list|(
name|memFun
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|// 64-bit integers and double
name|TEST_AlignOf_impl
argument_list|(
name|qint64
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|quint64
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|double
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|qint64
operator|&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|quint64
operator|&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|double
operator|&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_RValueRef
argument_list|(
name|qint64
operator|&&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_RValueRef
argument_list|(
name|quint64
operator|&&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|TEST_AlignOf_RValueRef
argument_list|(
name|double
operator|&&
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// 32-bit x86 ABI idiosyncrasies
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_X86_32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|TEST_AlignOf_impl
argument_list|(
name|AlignmentInStruct
argument_list|<
name|qint64
argument_list|>
argument_list|,
literal|4
argument_list|)
expr_stmt|;
else|#
directive|else
name|TEST_AlignOf_impl
argument_list|(
name|AlignmentInStruct
argument_list|<
name|qint64
argument_list|>
argument_list|,
literal|8
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|TEST_AlignOf_impl
argument_list|(
name|AlignmentInStruct
argument_list|<
name|quint64
argument_list|>
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|AlignmentInStruct
argument_list|<
name|qint64
argument_list|>
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|AlignmentInStruct
argument_list|<
name|double
argument_list|>
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|AlignmentInStruct
argument_list|<
name|qint64
argument_list|>
argument_list|)
argument_list|)
expr_stmt|;
comment|// 32-bit x86 ABI, Clang disagrees with gcc
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_PROCESSOR_X86_32
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
name|TEST_AlignOf_impl
argument_list|(
name|qint64
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|qint64
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|TEST_AlignOf_impl
argument_list|(
name|qint64
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|AlignmentInStruct
argument_list|<
name|qint64
argument_list|>
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|TEST_AlignOf_impl
argument_list|(
name|qint64
argument_list|(
operator|&
argument_list|)
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|qint64
index|[
literal|5
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|quint64
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|quint64
index|[
literal|5
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|quint64
argument_list|(
operator|&
argument_list|)
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|quint64
index|[
literal|5
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|double
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|double
index|[
literal|5
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_AlignOf_impl
argument_list|(
name|double
argument_list|(
operator|&
argument_list|)
index|[
literal|5
index|]
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|double
index|[
literal|5
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_undef
DECL|macro|TEST_AlignOf
undef|#
directive|undef
name|TEST_AlignOf
end_undef
begin_undef
DECL|macro|TEST_AlignOf_RValueRef
undef|#
directive|undef
name|TEST_AlignOf_RValueRef
end_undef
begin_undef
DECL|macro|TEST_AlignOf_impl
undef|#
directive|undef
name|TEST_AlignOf_impl
end_undef
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGlobal
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qglobal.moc"
end_include
end_unit
