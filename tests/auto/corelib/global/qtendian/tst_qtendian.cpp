begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qendian.h>
end_include
begin_class
DECL|class|tst_QtEndian
class|class
name|tst_QtEndian
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|fromBigEndian
parameter_list|()
function_decl|;
name|void
name|fromLittleEndian
parameter_list|()
function_decl|;
name|void
name|toBigEndian
parameter_list|()
function_decl|;
name|void
name|toLittleEndian
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|TestData
struct|struct
name|TestData
block|{
DECL|member|data64
name|quint64
name|data64
decl_stmt|;
DECL|member|data32
name|quint32
name|data32
decl_stmt|;
DECL|member|data16
name|quint16
name|data16
decl_stmt|;
DECL|member|data8
name|quint8
name|data8
decl_stmt|;
DECL|member|reserved
name|quint8
name|reserved
decl_stmt|;
block|}
struct|;
end_struct
begin_union
DECL|union|RawTestData
union|union
name|RawTestData
block|{
DECL|member|rawData
name|uchar
name|rawData
index|[
sizeof|sizeof
argument_list|(
name|TestData
argument_list|)
index|]
decl_stmt|;
DECL|member|data
name|TestData
name|data
decl_stmt|;
block|}
union|;
end_union
begin_decl_stmt
DECL|variable|inNativeEndian
specifier|static
specifier|const
name|TestData
name|inNativeEndian
init|=
block|{
name|Q_UINT64_C
argument_list|(
literal|0x0123456789abcdef
argument_list|)
block|,
literal|0x00c0ffee
block|,
literal|0xcafe
block|,
literal|0xcf
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|inBigEndian
specifier|static
specifier|const
name|RawTestData
name|inBigEndian
init|=
block|{
literal|"\x01\x23\x45\x67\x89\xab\xcd\xef"
literal|"\x00\xc0\xff\xee"
literal|"\xca\xfe"
literal|"\xcf"
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|inLittleEndian
specifier|static
specifier|const
name|RawTestData
name|inLittleEndian
init|=
block|{
literal|"\xef\xcd\xab\x89\x67\x45\x23\x01"
literal|"\xee\xff\xc0\x00"
literal|"\xfe\xca"
literal|"\xcf"
block|}
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|EXPAND_ENDIAN_TEST
define|#
directive|define
name|EXPAND_ENDIAN_TEST
parameter_list|(
name|endian
parameter_list|)
define|\
value|do {                                    \
comment|/* Unsigned tests */
value|\         ENDIAN_TEST(endian, quint, 64);     \         ENDIAN_TEST(endian, quint, 32);     \         ENDIAN_TEST(endian, quint, 16);     \         ENDIAN_TEST(endian, quint, 8);      \                                             \
comment|/* Signed tests */
value|\         ENDIAN_TEST(endian, qint, 64);      \         ENDIAN_TEST(endian, qint, 32);      \         ENDIAN_TEST(endian, qint, 16);      \         ENDIAN_TEST(endian, qint, 8);       \     } while (false)
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_define
DECL|macro|ENDIAN_TEST
define|#
directive|define
name|ENDIAN_TEST
parameter_list|(
name|endian
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                                                                \         QCOMPARE(qFrom ## endian ## Endian(                                             \                     (type ## size)(in ## endian ## Endian.data.data ## size)),          \                 (type ## size)(inNativeEndian.data ## size));                           \         QCOMPARE(qFrom ## endian ## Endian<type ## size>(                               \                     in ## endian ## Endian.rawData + offsetof(TestData, data ## size)), \                 (type ## size)(inNativeEndian.data ## size));                           \     } while (false)
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_function
DECL|function|fromBigEndian
name|void
name|tst_QtEndian
operator|::
name|fromBigEndian
parameter_list|()
block|{
name|EXPAND_ENDIAN_TEST
argument_list|(
name|Big
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromLittleEndian
name|void
name|tst_QtEndian
operator|::
name|fromLittleEndian
parameter_list|()
block|{
name|EXPAND_ENDIAN_TEST
argument_list|(
name|Little
argument_list|)
expr_stmt|;
block|}
end_function
begin_undef
DECL|macro|ENDIAN_TEST
undef|#
directive|undef
name|ENDIAN_TEST
end_undef
begin_define
DECL|macro|ENDIAN_TEST
define|#
directive|define
name|ENDIAN_TEST
parameter_list|(
name|endian
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                                                                \         QCOMPARE(qTo ## endian ## Endian(                                               \                     (type ## size)(inNativeEndian.data ## size)),                       \                 (type ## size)(in ## endian ## Endian.data.data ## size));              \                                                                                         \         RawTestData test;                                                               \         qTo ## endian ## Endian(                                                        \                 (type ## size)(inNativeEndian.data ## size),                            \                 test.rawData + offsetof(TestData, data ## size));                       \         QCOMPARE(test.data.data ## size, in ## endian ## Endian.data.data ## size );    \     } while (false)
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_function
DECL|function|toBigEndian
name|void
name|tst_QtEndian
operator|::
name|toBigEndian
parameter_list|()
block|{
name|EXPAND_ENDIAN_TEST
argument_list|(
name|Big
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toLittleEndian
name|void
name|tst_QtEndian
operator|::
name|toLittleEndian
parameter_list|()
block|{
name|EXPAND_ENDIAN_TEST
argument_list|(
name|Little
argument_list|)
expr_stmt|;
block|}
end_function
begin_undef
DECL|macro|ENDIAN_TEST
undef|#
directive|undef
name|ENDIAN_TEST
end_undef
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtEndian
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtendian.moc"
end_include
end_unit
