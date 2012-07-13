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
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|"tst_qvariant_common.h"
end_include
begin_class
DECL|class|tst_QWidgetsVariant
class|class
name|tst_QWidgetsVariant
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|constructor_invalid_data
parameter_list|()
function_decl|;
name|void
name|constructor_invalid
parameter_list|()
function_decl|;
name|void
name|canConvert_data
parameter_list|()
function_decl|;
name|void
name|canConvert
parameter_list|()
function_decl|;
name|void
name|writeToReadFromDataStream_data
parameter_list|()
function_decl|;
name|void
name|writeToReadFromDataStream
parameter_list|()
function_decl|;
name|void
name|qvariant_cast_QObject_data
parameter_list|()
function_decl|;
name|void
name|qvariant_cast_QObject
parameter_list|()
function_decl|;
name|void
name|qvariant_cast_QObject_derived
parameter_list|()
function_decl|;
name|void
name|debugStream_data
parameter_list|()
function_decl|;
name|void
name|debugStream
parameter_list|()
function_decl|;
name|void
name|widgetsVariantAtExit
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|constructor_invalid_data
name|void
name|tst_QWidgetsVariant
operator|::
name|constructor_invalid_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|uint
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LastGuiType + 1"
argument_list|)
operator|<<
name|uint
argument_list|(
name|QMetaType
operator|::
name|LastGuiType
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|QMetaType
operator|::
name|LastGuiType
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LastWidgetsType + 1"
argument_list|)
operator|<<
name|uint
argument_list|(
name|QMetaType
operator|::
name|LastWidgetsType
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|QMetaType
operator|::
name|LastWidgetsType
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructor_invalid
name|void
name|tst_QWidgetsVariant
operator|::
name|constructor_invalid
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|uint
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
block|{
name|MessageHandlerInvalidType
name|msg
decl_stmt|;
name|QVariant
name|variant
argument_list|(
cast|static_cast
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|>
argument_list|(
name|typeId
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|variant
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|variant
operator|.
name|userType
argument_list|()
operator|==
name|QMetaType
operator|::
name|UnknownType
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|msg
operator|.
name|ok
argument_list|)
expr_stmt|;
block|}
block|{
name|MessageHandlerInvalidType
name|msg
decl_stmt|;
name|QVariant
name|variant
argument_list|(
name|typeId
argument_list|,
comment|/* copy */
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|variant
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|variant
operator|.
name|userType
argument_list|()
operator|==
name|QMetaType
operator|::
name|UnknownType
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|msg
operator|.
name|ok
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|canConvert_data
name|void
name|tst_QWidgetsVariant
operator|::
name|canConvert_data
parameter_list|()
block|{
name|TST_QVARIANT_CANCONVERT_DATATABLE_HEADERS
ifdef|#
directive|ifdef
name|Y
DECL|macro|Y
undef|#
directive|undef
name|Y
endif|#
directive|endif
ifdef|#
directive|ifdef
name|N
DECL|macro|N
undef|#
directive|undef
name|N
endif|#
directive|endif
DECL|macro|Y
define|#
directive|define
name|Y
value|true
DECL|macro|N
define|#
directive|define
name|N
value|false
name|QVariant
name|var
decl_stmt|;
comment|//            bita bitm bool brsh byta col  curs date dt   dbl  font img  int  inv  kseq list ll   map  pal  pen  pix  pnt  rect reg  size sp   str  strl time uint ull
name|var
operator|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QSizePolicy
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"SizePolicy"
argument_list|)
operator|<<
name|var
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|Y
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
operator|<<
name|N
expr_stmt|;
DECL|macro|N
undef|#
directive|undef
name|N
DECL|macro|Y
undef|#
directive|undef
name|Y
block|}
end_function
begin_function
DECL|function|canConvert
name|void
name|tst_QWidgetsVariant
operator|::
name|canConvert
parameter_list|()
block|{
name|TST_QVARIANT_CANCONVERT_FETCH_DATA
name|TST_QVARIANT_CANCONVERT_COMPARE_DATA
block|}
end_function
begin_function
DECL|function|writeToReadFromDataStream_data
name|void
name|tst_QWidgetsVariant
operator|::
name|writeToReadFromDataStream_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"writeVariant"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isNull"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sizepolicy_valid"
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeToReadFromDataStream
name|void
name|tst_QWidgetsVariant
operator|::
name|writeToReadFromDataStream
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|writeVariant
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isNull
argument_list|)
expr_stmt|;
name|QByteArray
name|data
decl_stmt|;
name|QDataStream
name|writeStream
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|writeStream
operator|<<
name|writeVariant
expr_stmt|;
name|QVariant
name|readVariant
decl_stmt|;
name|QDataStream
name|readStream
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|readStream
operator|>>
name|readVariant
expr_stmt|;
name|QVERIFY
argument_list|(
name|readVariant
operator|.
name|isNull
argument_list|()
operator|==
name|isNull
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|CustomQWidget
class|class
name|CustomQWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|CustomQWidget
name|CustomQWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{}
block|}
class|;
end_class
begin_function
DECL|function|qvariant_cast_QObject_data
name|void
name|tst_QWidgetsVariant
operator|::
name|qvariant_cast_QObject_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
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
literal|"success"
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
decl_stmt|;
name|widget
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"from QWidget"
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|widget
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|CustomQWidget
modifier|*
name|customWidget
init|=
operator|new
name|CustomQWidget
decl_stmt|;
name|customWidget
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"from Derived QWidget"
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|customWidget
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qvariant_cast_QObject
name|void
name|tst_QWidgetsVariant
operator|::
name|qvariant_cast_QObject
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|success
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|o
init|=
name|qvariant_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|o
operator|!=
literal|0
argument_list|,
name|success
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
condition|)
block|{
name|QCOMPARE
argument_list|(
name|o
operator|->
name|objectName
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|(
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|value
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|convert
argument_list|(
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|userType
argument_list|()
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|(
name|QMetaType
operator|::
name|QWidgetStar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|canConvert
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|value
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|convert
argument_list|(
name|QMetaType
operator|::
name|QWidgetStar
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|userType
argument_list|()
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|QWidgetStar
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
operator|!
name|data
operator|.
name|canConvert
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|data
operator|.
name|canConvert
argument_list|(
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|data
operator|.
name|canConvert
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|data
operator|.
name|value
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|data
operator|.
name|convert
argument_list|(
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|userType
argument_list|()
operator|!=
name|QMetaType
operator|::
name|QObjectStar
argument_list|)
expr_stmt|;
block|}
operator|delete
name|o
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qvariant_cast_QObject_derived
name|void
name|tst_QWidgetsVariant
operator|::
name|qvariant_cast_QObject_derived
parameter_list|()
block|{
name|CustomQWidget
name|customWidget
decl_stmt|;
name|QWidget
modifier|*
name|widget
init|=
operator|&
name|customWidget
decl_stmt|;
name|QVariant
name|data
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|userType
argument_list|()
operator|==
name|QMetaType
operator|::
name|QWidgetStar
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|value
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|value
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
operator|.
name|value
argument_list|<
name|CustomQWidget
operator|*
argument_list|>
argument_list|()
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|debugStream_data
name|void
name|tst_QWidgetsVariant
operator|::
name|debugStream_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"variant"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|id
init|=
name|QMetaType
operator|::
name|LastGuiType
operator|+
literal|1
init|;
name|id
operator|<
name|QMetaType
operator|::
name|User
condition|;
operator|++
name|id
control|)
block|{
specifier|const
name|char
modifier|*
name|tagName
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tagName
condition|)
continue|continue;
name|QTest
operator|::
name|newRow
argument_list|(
name|tagName
argument_list|)
operator|<<
name|QVariant
argument_list|(
cast|static_cast
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|>
argument_list|(
name|id
argument_list|)
argument_list|)
operator|<<
name|id
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|debugStream
name|void
name|tst_QWidgetsVariant
operator|::
name|debugStream
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|variant
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|MessageHandler
name|msgHandler
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|variant
expr_stmt|;
name|QVERIFY
argument_list|(
name|msgHandler
operator|.
name|testPassed
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|widgetsVariantAtExit
name|void
name|tst_QWidgetsVariant
operator|::
name|widgetsVariantAtExit
parameter_list|()
block|{
comment|// crash test, it should not crash at QApplication exit
specifier|static
name|QVariant
name|sizePolicy
init|=
name|QSizePolicy
argument_list|()
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWidgetsVariant
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwidgetsvariant.moc"
end_include
end_unit
