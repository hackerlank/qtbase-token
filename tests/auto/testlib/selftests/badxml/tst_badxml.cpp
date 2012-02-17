begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<private/qmetaobjectbuilder_p.h>
end_include
begin_comment
comment|/*     This test makes a testlog containing lots of characters which have a special meaning in     XML, with the purpose of exposing bugs in testlib's XML output code. */
end_comment
begin_class
DECL|class|tst_BadXml
class|class
name|tst_BadXml
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|badDataTag
parameter_list|()
specifier|const
function_decl|;
name|void
name|badDataTag_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|badMessage
parameter_list|()
specifier|const
function_decl|;
name|void
name|badMessage_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|failWithNoFile
parameter_list|()
specifier|const
function_decl|;
public|public:
specifier|static
name|QList
argument_list|<
name|QByteArray
argument_list|>
specifier|const
modifier|&
name|badStrings
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*     Custom metaobject to make it possible to change class name at runtime. */
end_comment
begin_class
DECL|class|EmptyClass
class|class
name|EmptyClass
super|:
specifier|public
name|tst_BadXml
block|{
name|Q_OBJECT
block|}
class|;
end_class
begin_class
DECL|class|tst_BadXmlSub
class|class
name|tst_BadXmlSub
super|:
specifier|public
name|tst_BadXml
block|{
public|public:
DECL|function|tst_BadXmlSub
name|tst_BadXmlSub
parameter_list|()
member_init_list|:
name|className
argument_list|(
literal|"tst_BadXml"
argument_list|)
member_init_list|,
name|mo
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|~tst_BadXmlSub
name|~
name|tst_BadXmlSub
parameter_list|()
block|{
name|qFree
argument_list|(
name|mo
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QMetaObject
modifier|*
name|metaObject
parameter_list|()
specifier|const
function_decl|;
DECL|member|className
name|QByteArray
name|className
decl_stmt|;
private|private:
DECL|member|mo
name|QMetaObject
modifier|*
name|mo
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|metaObject
specifier|const
name|QMetaObject
modifier|*
name|tst_BadXmlSub
operator|::
name|metaObject
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mo
operator|||
operator|(
name|mo
operator|->
name|className
argument_list|()
operator|!=
name|className
operator|)
condition|)
block|{
name|qFree
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QMetaObjectBuilder
name|builder
argument_list|(
operator|&
name|EmptyClass
operator|::
name|staticMetaObject
argument_list|)
decl_stmt|;
name|builder
operator|.
name|setClassName
argument_list|(
name|className
argument_list|)
expr_stmt|;
cast|const_cast
argument_list|<
name|tst_BadXmlSub
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|mo
operator|=
name|builder
operator|.
name|toMetaObject
argument_list|()
expr_stmt|;
block|}
return|return
name|mo
return|;
block|}
end_function
begin_comment
comment|/*     Outputs incidents and benchmark results with the current data tag set to a bad string. */
end_comment
begin_function
DECL|function|badDataTag
name|void
name|tst_BadXml
operator|::
name|badDataTag
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|(
literal|"a message"
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{     }
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|shouldFail
argument_list|)
expr_stmt|;
if|if
condition|(
name|shouldFail
condition|)
name|QFAIL
argument_list|(
literal|"a failure"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|badDataTag_data
name|void
name|tst_BadXml
operator|::
name|badDataTag_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"shouldFail"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|char
specifier|const
modifier|*
name|str
decl|,
name|badStrings
argument_list|()
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"fail %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|str
argument_list|)
argument_list|)
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"pass %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|str
argument_list|)
argument_list|)
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|failWithNoFile
name|void
name|tst_BadXml
operator|::
name|failWithNoFile
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|qFail
argument_list|(
literal|"failure message"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Outputs a message containing a bad string. */
end_comment
begin_function
DECL|function|badMessage
name|void
name|tst_BadXml
operator|::
name|badMessage
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|message
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|badMessage_data
name|void
name|tst_BadXml
operator|::
name|badMessage_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"message"
argument_list|)
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QByteArray
specifier|const
modifier|&
name|str
decl|,
name|badStrings
argument_list|()
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"string %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|++
argument_list|)
argument_list|)
argument_list|)
operator|<<
name|str
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*     Returns a list of strings likely to expose bugs in XML output code. */
end_comment
begin_function
DECL|function|badStrings
name|QList
argument_list|<
name|QByteArray
argument_list|>
specifier|const
modifier|&
name|tst_BadXml
operator|::
name|badStrings
parameter_list|()
block|{
specifier|static
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|out
decl_stmt|;
if|if
condition|(
name|out
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|out
operator|<<
literal|"end cdata ]]> text ]]> more text"
expr_stmt|;
name|out
operator|<<
literal|"quotes \" text\" more text"
expr_stmt|;
name|out
operator|<<
literal|"xml close> open< tags< text"
expr_stmt|;
name|out
operator|<<
literal|"all> \" mixed ]]> up> \" in< the ]]> hopes< of triggering \"< ]]> bugs"
expr_stmt|;
block|}
return|return
name|out
return|;
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
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|/*         tst_selftests can't handle multiple XML documents in a single testrun, so we'll         decide before we begin which of our "bad strings" we want to use for our testcase         name.     */
name|int
name|badstring
init|=
operator|-
literal|1
decl_stmt|;
name|QVector
argument_list|<
name|char
specifier|const
operator|*
argument_list|>
name|args
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
name|argc
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-badstring"
argument_list|)
condition|)
block|{
name|bool
name|ok
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|i
operator|<
name|argc
operator|-
literal|1
condition|)
block|{
name|badstring
operator|=
name|QByteArray
argument_list|(
name|argv
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|qFatal
argument_list|(
literal|"Bad `-badstring' option"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|args
operator|<<
name|argv
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
comment|/*         We just want testlib to output a benchmark result, we don't actually care about the value,         so just do one iteration to save time.     */
name|args
operator|<<
literal|"-iterations"
operator|<<
literal|"1"
expr_stmt|;
if|if
condition|(
name|badstring
operator|==
operator|-
literal|1
condition|)
block|{
name|tst_BadXml
name|test
decl_stmt|;
return|return
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|args
operator|.
name|count
argument_list|()
argument_list|,
cast|const_cast
argument_list|<
name|char
operator|*
operator|*
argument_list|>
argument_list|(
name|args
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|badstrings
init|=
name|tst_BadXml
operator|::
name|badStrings
argument_list|()
decl_stmt|;
if|if
condition|(
name|badstring
operator|>=
name|badstrings
operator|.
name|count
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"`-badstring %d' is out of range"
argument_list|,
name|badstring
argument_list|)
expr_stmt|;
name|tst_BadXmlSub
name|test
decl_stmt|;
name|test
operator|.
name|className
operator|=
name|badstrings
index|[
name|badstring
index|]
operator|.
name|constData
argument_list|()
expr_stmt|;
return|return
name|QTest
operator|::
name|qExec
argument_list|(
operator|&
name|test
argument_list|,
name|args
operator|.
name|count
argument_list|()
argument_list|,
cast|const_cast
argument_list|<
name|char
operator|*
operator|*
argument_list|>
argument_list|(
name|args
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"tst_badxml.moc"
end_include
end_unit
