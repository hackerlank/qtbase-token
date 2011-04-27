begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_class
DECL|class|tst_QGuiMetaType
class|class
name|tst_QGuiMetaType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QGuiMetaType
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QGuiMetaType
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|constructGuiType_data
parameter_list|()
function_decl|;
name|void
name|constructGuiType
parameter_list|()
function_decl|;
name|void
name|constructGuiTypeCopy_data
parameter_list|()
function_decl|;
name|void
name|constructGuiTypeCopy
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QGuiMetaType
name|tst_QGuiMetaType
operator|::
name|tst_QGuiMetaType
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QGuiMetaType
name|tst_QGuiMetaType
operator|::
name|~
name|tst_QGuiMetaType
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|constructGuiType_data
name|void
name|tst_QGuiMetaType
operator|::
name|constructGuiType_data
parameter_list|()
block|{
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
name|i
init|=
name|QMetaType
operator|::
name|FirstGuiType
init|;
name|i
operator|<=
name|QMetaType
operator|::
name|LastGuiType
condition|;
operator|++
name|i
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|i
argument_list|)
argument_list|)
operator|<<
name|i
expr_stmt|;
block|}
end_function
begin_comment
comment|// Tests how fast QMetaType can default-construct and destroy a Qt GUI
end_comment
begin_comment
comment|// type. The purpose of this benchmark is to measure the overhead of
end_comment
begin_comment
comment|// using type id-based creation compared to creating the type directly
end_comment
begin_comment
comment|// (i.e. "T *t = new T(); delete t;").
end_comment
begin_function
DECL|function|constructGuiType
name|void
name|tst_QGuiMetaType
operator|::
name|constructGuiType
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|constructGuiTypeCopy_data
name|void
name|tst_QGuiMetaType
operator|::
name|constructGuiTypeCopy_data
parameter_list|()
block|{
name|constructGuiType_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Tests how fast QMetaType can copy-construct and destroy a Qt GUI
end_comment
begin_comment
comment|// type. The purpose of this benchmark is to measure the overhead of
end_comment
begin_comment
comment|// using type id-based creation compared to creating the type directly
end_comment
begin_comment
comment|// (i.e. "T *t = new T(other); delete t;").
end_comment
begin_function
DECL|function|constructGuiTypeCopy
name|void
name|tst_QGuiMetaType
operator|::
name|constructGuiTypeCopy
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QVariant
name|other
argument_list|(
name|typeId
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|void
modifier|*
name|copy
init|=
name|other
operator|.
name|constData
argument_list|()
decl_stmt|;
name|QBENCHMARK
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
literal|100000
condition|;
operator|++
name|i
control|)
block|{
name|void
modifier|*
name|data
init|=
name|QMetaType
operator|::
name|construct
argument_list|(
name|typeId
argument_list|,
name|copy
argument_list|)
decl_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|typeId
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGuiMetaType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qguimetatype.moc"
end_include
end_unit
