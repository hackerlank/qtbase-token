begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<private/v8.h>
end_include
begin_include
include|#
directive|include
file|"v8test.h"
end_include
begin_using
using|using
namespace|namespace
name|v8
namespace|;
end_using
begin_class
DECL|class|tst_v8
class|class
name|tst_v8
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_v8
name|tst_v8
parameter_list|()
block|{}
private|private
name|slots
private|:
DECL|function|initTestCase
name|void
name|initTestCase
parameter_list|()
block|{}
DECL|function|cleanupTestCase
name|void
name|cleanupTestCase
parameter_list|()
block|{}
name|void
name|eval
parameter_list|()
function_decl|;
name|void
name|evalwithinwith
parameter_list|()
function_decl|;
name|void
name|userobjectcompare
parameter_list|()
function_decl|;
name|void
name|externalteardown
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|eval
name|void
name|tst_v8
operator|::
name|eval
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|v8test_eval
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|evalwithinwith
name|void
name|tst_v8
operator|::
name|evalwithinwith
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|v8test_evalwithinwith
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|userobjectcompare
name|void
name|tst_v8
operator|::
name|userobjectcompare
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|v8test_userobjectcompare
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|externalteardown
name|void
name|tst_v8
operator|::
name|externalteardown
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|v8test_externalteardown
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|V8
operator|::
name|SetFlagsFromCommandLine
argument_list|(
operator|&
name|argc
argument_list|,
name|argv
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|tst_v8
name|tc
decl_stmt|;
return|return
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|tc
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"tst_v8.moc"
end_include
end_unit
