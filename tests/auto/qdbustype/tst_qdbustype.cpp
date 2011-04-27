begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtDBus/private/qdbusutil_p.h>
end_include
begin_include
include|#
directive|include
file|<dbus/dbus.h>
end_include
begin_class
DECL|class|tst_QDBusType
class|class
name|tst_QDBusType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|isValidFixedType_data
parameter_list|()
function_decl|;
name|void
name|isValidFixedType
parameter_list|()
function_decl|;
name|void
name|isValidBasicType_data
parameter_list|()
function_decl|;
name|void
name|isValidBasicType
parameter_list|()
function_decl|;
name|void
name|isValidSingleSignature_data
parameter_list|()
function_decl|;
name|void
name|isValidSingleSignature
parameter_list|()
function_decl|;
name|void
name|isValidArray_data
parameter_list|()
function_decl|;
name|void
name|isValidArray
parameter_list|()
function_decl|;
name|void
name|isValidSignature_data
parameter_list|()
function_decl|;
name|void
name|isValidSignature
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_enum
DECL|enumerator|Invalid
DECL|enumerator|Valid
enum|enum
block|{
name|Invalid
init|=
literal|false
block|,
name|Valid
init|=
literal|true
block|}
enum|;
end_enum
begin_function
DECL|function|addColumns
specifier|static
name|void
name|addColumns
parameter_list|()
block|{
comment|// All tests use these two columns only
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"result"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isValid"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ---- type adds ---
end_comment
begin_function
DECL|function|addFixedTypes
specifier|static
name|void
name|addFixedTypes
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"bool"
argument_list|)
operator|<<
name|DBUS_TYPE_BOOLEAN_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"byte"
argument_list|)
operator|<<
name|DBUS_TYPE_BYTE_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int16"
argument_list|)
operator|<<
name|DBUS_TYPE_INT16_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"uint16"
argument_list|)
operator|<<
name|DBUS_TYPE_UINT16_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int32"
argument_list|)
operator|<<
name|DBUS_TYPE_INT32_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"uint32"
argument_list|)
operator|<<
name|DBUS_TYPE_UINT32_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int64"
argument_list|)
operator|<<
name|DBUS_TYPE_INT64_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"uint64"
argument_list|)
operator|<<
name|DBUS_TYPE_UINT64_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"double"
argument_list|)
operator|<<
name|DBUS_TYPE_DOUBLE_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
ifdef|#
directive|ifdef
name|DBUS_TYPE_UNIX_FD_AS_STRING
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unixfd"
argument_list|)
operator|<<
name|DBUS_TYPE_UNIX_FD_AS_STRING
operator|<<
literal|true
operator|<<
literal|true
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|addInvalidSingleLetterTypes
specifier|static
name|void
name|addInvalidSingleLetterTypes
parameter_list|()
block|{
name|QChar
name|nulString
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"nul"
argument_list|)
operator|<<
name|QString
argument_list|(
name|nulString
argument_list|,
literal|1
argument_list|)
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"tilde"
argument_list|)
operator|<<
literal|"~"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-begin"
argument_list|)
operator|<<
literal|"("
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-end"
argument_list|)
operator|<<
literal|")"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-entry-begin"
argument_list|)
operator|<<
literal|"{"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-entry-end"
argument_list|)
operator|<<
literal|"}"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"array-no-element"
argument_list|)
operator|<<
literal|"a"
operator|<<
literal|false
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addBasicTypes
specifier|static
name|void
name|addBasicTypes
parameter_list|(
name|bool
name|basicsAreValid
parameter_list|)
block|{
name|addFixedTypes
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"string"
argument_list|)
operator|<<
name|DBUS_TYPE_STRING_AS_STRING
operator|<<
name|basicsAreValid
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"object-path"
argument_list|)
operator|<<
name|DBUS_TYPE_OBJECT_PATH_AS_STRING
operator|<<
name|basicsAreValid
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"signature"
argument_list|)
operator|<<
name|DBUS_TYPE_SIGNATURE_AS_STRING
operator|<<
name|basicsAreValid
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addVariant
specifier|static
name|void
name|addVariant
parameter_list|(
name|bool
name|variantIsValid
parameter_list|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"variant"
argument_list|)
operator|<<
literal|"v"
operator|<<
name|variantIsValid
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addSingleSignatures
specifier|static
name|void
name|addSingleSignatures
parameter_list|()
block|{
name|addBasicTypes
argument_list|(
name|Valid
argument_list|)
expr_stmt|;
name|addVariant
argument_list|(
name|Valid
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-1"
argument_list|)
operator|<<
literal|"(y)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-2"
argument_list|)
operator|<<
literal|"(yy)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-3"
argument_list|)
operator|<<
literal|"(yyv)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-1"
argument_list|)
operator|<<
literal|"((y))"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-2"
argument_list|)
operator|<<
literal|"((yy))"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-3"
argument_list|)
operator|<<
literal|"(y(y))"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-4"
argument_list|)
operator|<<
literal|"((y)y)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-5"
argument_list|)
operator|<<
literal|"(y(y)y)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-6"
argument_list|)
operator|<<
literal|"((y)(y))"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"array-1"
argument_list|)
operator|<<
literal|"as"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-array-1"
argument_list|)
operator|<<
literal|"(as)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-array-2"
argument_list|)
operator|<<
literal|"(yas)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-array-3"
argument_list|)
operator|<<
literal|"(asy)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-array-4"
argument_list|)
operator|<<
literal|"(yasy)"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-1"
argument_list|)
operator|<<
literal|"a{sy}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-2"
argument_list|)
operator|<<
literal|"a{sv}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-struct-1"
argument_list|)
operator|<<
literal|"a{s(y)}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-struct-2"
argument_list|)
operator|<<
literal|"a{s(yyyy)}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-struct-array"
argument_list|)
operator|<<
literal|"a{s(ay)}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-array"
argument_list|)
operator|<<
literal|"a{sas}"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-array-struct"
argument_list|)
operator|<<
literal|"a{sa(y)}"
operator|<<
literal|true
expr_stmt|;
name|addInvalidSingleLetterTypes
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"naked-dict-empty"
argument_list|)
operator|<<
literal|"{}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"naked-dict-missing-value"
argument_list|)
operator|<<
literal|"{i}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-empty"
argument_list|)
operator|<<
literal|"a{}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-missing-value"
argument_list|)
operator|<<
literal|"a{i}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-non-basic-key"
argument_list|)
operator|<<
literal|"a{vi}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-struct-key"
argument_list|)
operator|<<
literal|"a{(y)y}"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-missing-close"
argument_list|)
operator|<<
literal|"a{sv"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-mismatched-close"
argument_list|)
operator|<<
literal|"a{sv)"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"dict-missing-value-close"
argument_list|)
operator|<<
literal|"a{s"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty-struct"
argument_list|)
operator|<<
literal|"()"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-missing-close"
argument_list|)
operator|<<
literal|"(s"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-missing-close-1"
argument_list|)
operator|<<
literal|"((s)"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-nested-missing-close-2"
argument_list|)
operator|<<
literal|"((s"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"struct-ending-array-no-element"
argument_list|)
operator|<<
literal|"(a)"
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addNakedDictEntry
specifier|static
name|void
name|addNakedDictEntry
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"naked-dict-entry"
argument_list|)
operator|<<
literal|"{sv}"
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|// ---- tests ----
end_comment
begin_function
DECL|function|isValidFixedType_data
name|void
name|tst_QDBusType
operator|::
name|isValidFixedType_data
parameter_list|()
block|{
name|addColumns
argument_list|()
expr_stmt|;
name|addFixedTypes
argument_list|()
expr_stmt|;
name|addBasicTypes
argument_list|(
name|Invalid
argument_list|)
expr_stmt|;
name|addVariant
argument_list|(
name|Invalid
argument_list|)
expr_stmt|;
name|addInvalidSingleLetterTypes
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidFixedType
name|void
name|tst_QDBusType
operator|::
name|isValidFixedType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|data
operator|.
name|length
argument_list|()
operator|==
literal|1
argument_list|,
literal|"tst_QDBusType"
argument_list|,
literal|"Test is malformed, this function must test only one-letter types"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|isValid
operator|||
operator|(
operator|!
name|isValid
operator|&&
operator|!
name|result
operator|)
argument_list|)
expr_stmt|;
name|int
name|type
init|=
name|data
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
decl_stmt|;
if|if
condition|(
name|isValid
condition|)
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_type_is_fixed
argument_list|(
name|type
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidFixedType
argument_list|(
name|type
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidBasicType_data
name|void
name|tst_QDBusType
operator|::
name|isValidBasicType_data
parameter_list|()
block|{
name|addColumns
argument_list|()
expr_stmt|;
name|addBasicTypes
argument_list|(
name|Valid
argument_list|)
expr_stmt|;
name|addVariant
argument_list|(
name|Invalid
argument_list|)
expr_stmt|;
name|addInvalidSingleLetterTypes
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidBasicType
name|void
name|tst_QDBusType
operator|::
name|isValidBasicType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isValid
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|data
operator|.
name|length
argument_list|()
operator|==
literal|1
argument_list|,
literal|"tst_QDBusType"
argument_list|,
literal|"Test is malformed, this function must test only one-letter types"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|isValid
operator|||
operator|(
operator|!
name|isValid
operator|&&
operator|!
name|result
operator|)
argument_list|)
expr_stmt|;
name|int
name|type
init|=
name|data
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
decl_stmt|;
if|if
condition|(
name|isValid
condition|)
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_type_is_basic
argument_list|(
name|type
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidBasicType
argument_list|(
name|type
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidSingleSignature_data
name|void
name|tst_QDBusType
operator|::
name|isValidSingleSignature_data
parameter_list|()
block|{
name|addColumns
argument_list|()
expr_stmt|;
name|addSingleSignatures
argument_list|()
expr_stmt|;
name|addNakedDictEntry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidSingleSignature
name|void
name|tst_QDBusType
operator|::
name|isValidSingleSignature
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_signature_validate_single
argument_list|(
name|data
operator|.
name|toLatin1
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidSingleSignature
argument_list|(
name|data
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidArray_data
name|void
name|tst_QDBusType
operator|::
name|isValidArray_data
parameter_list|()
block|{
name|addColumns
argument_list|()
expr_stmt|;
name|addSingleSignatures
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidArray
name|void
name|tst_QDBusType
operator|::
name|isValidArray
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|data
operator|.
name|prepend
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_signature_validate_single
argument_list|(
name|data
operator|.
name|toLatin1
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidSingleSignature
argument_list|(
name|data
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|data
operator|.
name|prepend
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_signature_validate_single
argument_list|(
name|data
operator|.
name|toLatin1
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidSingleSignature
argument_list|(
name|data
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidSignature_data
name|void
name|tst_QDBusType
operator|::
name|isValidSignature_data
parameter_list|()
block|{
name|isValidSingleSignature_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isValidSignature
name|void
name|tst_QDBusType
operator|::
name|isValidSignature
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|data
operator|.
name|append
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|bool
argument_list|(
name|dbus_signature_validate
argument_list|(
name|data
operator|.
name|toLatin1
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QDBusUtil
operator|::
name|isValidSignature
argument_list|(
name|data
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbustype.moc"
end_include
end_unit
