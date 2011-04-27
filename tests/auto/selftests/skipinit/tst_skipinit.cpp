begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_SkipInit
class|class
name|tst_SkipInit
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
specifier|const
function_decl|;
name|void
name|aTestFunction
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_SkipInit
operator|::
name|initTestCase
parameter_list|()
specifier|const
block|{
name|QSKIP
argument_list|(
literal|"Skip inside initTestCase. This should skip all tests in the class."
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal   This function should never be run because initTestCase fails.  */
end_comment
begin_function
DECL|function|aTestFunction
name|void
name|tst_SkipInit
operator|::
name|aTestFunction
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ERROR: This function is NOT supposed to be run."
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_SkipInit
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_skipinit.moc"
end_include
end_unit
