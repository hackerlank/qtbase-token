begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<qjsondocument.h>
end_include
begin_include
include|#
directive|include
file|<qjsonobject.h>
end_include
begin_class
DECL|class|BenchmarkQtBinaryJson
class|class
name|BenchmarkQtBinaryJson
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|BenchmarkQtBinaryJson
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|parseNumbers
parameter_list|()
function_decl|;
name|void
name|parseJson
parameter_list|()
function_decl|;
name|void
name|parseJsonToVariant
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|BenchmarkQtBinaryJson
name|BenchmarkQtBinaryJson
operator|::
name|BenchmarkQtBinaryJson
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{  }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|BenchmarkQtBinaryJson
operator|::
name|initTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|BenchmarkQtBinaryJson
operator|::
name|cleanupTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|init
name|void
name|BenchmarkQtBinaryJson
operator|::
name|init
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanup
name|void
name|BenchmarkQtBinaryJson
operator|::
name|cleanup
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|parseNumbers
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseNumbers
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
name|QLatin1String
argument_list|(
literal|"numbers.json"
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|parseJson
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseJson
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
name|QLatin1String
argument_list|(
literal|"../../../auto/corelib/json/test.json"
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|parseJsonToVariant
name|void
name|BenchmarkQtBinaryJson
operator|::
name|parseJsonToVariant
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
name|QLatin1String
argument_list|(
literal|"../../../auto/corelib/json/test.json"
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|testJson
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|testJson
argument_list|)
decl_stmt|;
name|QVariant
name|v
init|=
name|doc
operator|.
name|toVariant
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|BenchmarkQtBinaryJson
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_bench_qtbinaryjson.moc"
end_include
end_unit
