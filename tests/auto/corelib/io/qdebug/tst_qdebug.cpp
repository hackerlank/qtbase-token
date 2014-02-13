begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QDebug
class|class
name|tst_QDebug
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|assignment
parameter_list|()
specifier|const
function_decl|;
name|void
name|warningWithoutDebug
parameter_list|()
specifier|const
function_decl|;
name|void
name|criticalWithoutDebug
parameter_list|()
specifier|const
function_decl|;
name|void
name|debugWithBool
parameter_list|()
specifier|const
function_decl|;
name|void
name|debugSpaceHandling
parameter_list|()
specifier|const
function_decl|;
name|void
name|stateSaver
parameter_list|()
specifier|const
function_decl|;
name|void
name|veryLongWarningMessage
parameter_list|()
specifier|const
function_decl|;
name|void
name|qDebugQStringRef
parameter_list|()
specifier|const
function_decl|;
name|void
name|qDebugQLatin1String
parameter_list|()
specifier|const
function_decl|;
name|void
name|textStreamModifiers
parameter_list|()
specifier|const
function_decl|;
name|void
name|defaultMessagehandler
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|assignment
name|void
name|tst_QDebug
operator|::
name|assignment
parameter_list|()
specifier|const
block|{
name|QDebug
name|debug1
argument_list|(
name|QtDebugMsg
argument_list|)
decl_stmt|;
name|QDebug
name|debug2
argument_list|(
name|QtWarningMsg
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtDebugMsg
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"bar 1 2"
argument_list|)
expr_stmt|;
name|debug1
operator|<<
literal|"foo"
expr_stmt|;
name|debug2
operator|<<
literal|"bar"
expr_stmt|;
name|debug1
operator|=
name|debug2
expr_stmt|;
name|debug1
operator|<<
literal|"1"
expr_stmt|;
name|debug2
operator|<<
literal|"2"
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|s_msgType
specifier|static
name|QtMsgType
name|s_msgType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s_msg
specifier|static
name|QString
name|s_msg
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s_file
specifier|static
name|QByteArray
name|s_file
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s_line
specifier|static
name|int
name|s_line
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s_function
specifier|static
name|QByteArray
name|s_function
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|myMessageHandler
specifier|static
name|void
name|myMessageHandler
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
name|context
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
name|s_msg
operator|=
name|msg
expr_stmt|;
name|s_msgType
operator|=
name|type
expr_stmt|;
name|s_file
operator|=
name|context
operator|.
name|file
expr_stmt|;
name|s_line
operator|=
name|context
operator|.
name|line
expr_stmt|;
name|s_function
operator|=
name|context
operator|.
name|function
expr_stmt|;
block|}
end_function
begin_comment
comment|// Helper class to ensure that the testlib message handler gets
end_comment
begin_comment
comment|// restored at the end of each test function, even if the test
end_comment
begin_comment
comment|// fails or throws an exception.
end_comment
begin_class
DECL|class|MessageHandlerSetter
class|class
name|MessageHandlerSetter
block|{
public|public:
DECL|function|MessageHandlerSetter
name|MessageHandlerSetter
parameter_list|(
name|QtMessageHandler
name|newMessageHandler
parameter_list|)
member_init_list|:
name|oldMessageHandler
argument_list|(
name|qInstallMessageHandler
argument_list|(
name|newMessageHandler
argument_list|)
argument_list|)
block|{ }
DECL|function|~MessageHandlerSetter
name|~
name|MessageHandlerSetter
parameter_list|()
block|{
name|qInstallMessageHandler
argument_list|(
name|oldMessageHandler
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|oldMessageHandler
name|QtMessageHandler
name|oldMessageHandler
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*! \internal   The qWarning() stream should be usable even if QT_NO_DEBUG is defined.  */
end_comment
begin_function
DECL|function|warningWithoutDebug
name|void
name|tst_QDebug
operator|::
name|warningWithoutDebug
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qWarning
argument_list|()
operator|<<
literal|"A qWarning() message"
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtWarningMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A qWarning() message"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal   The qCritical() stream should be usable even if QT_NO_DEBUG is defined.  */
end_comment
begin_function
DECL|function|criticalWithoutDebug
name|void
name|tst_QDebug
operator|::
name|criticalWithoutDebug
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qCritical
argument_list|()
operator|<<
literal|"A qCritical() message"
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtCriticalMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A qCritical() message"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|debugWithBool
name|void
name|tst_QDebug
operator|::
name|debugWithBool
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
literal|false
operator|<<
literal|true
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"false true"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyPoint
class|class
name|MyPoint
block|{
public|public:
DECL|function|MyPoint
name|MyPoint
parameter_list|(
name|int
name|val1
parameter_list|,
name|int
name|val2
parameter_list|)
member_init_list|:
name|v1
argument_list|(
name|val1
argument_list|)
member_init_list|,
name|v2
argument_list|(
name|val2
argument_list|)
block|{}
DECL|member|v1
name|int
name|v1
decl_stmt|;
DECL|member|v2
name|int
name|v2
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|s
parameter_list|,
specifier|const
name|MyPoint
modifier|&
name|point
parameter_list|)
block|{
specifier|const
name|QDebugStateSaver
name|saver
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|"MyPoint("
operator|<<
name|point
operator|.
name|v1
operator|<<
literal|", "
operator|<<
name|point
operator|.
name|v2
operator|<<
literal|")"
return|;
block|}
end_function
begin_class
DECL|class|MyLine
class|class
name|MyLine
block|{
public|public:
DECL|function|MyLine
name|MyLine
parameter_list|(
specifier|const
name|MyPoint
modifier|&
name|point1
parameter_list|,
specifier|const
name|MyPoint
modifier|&
name|point2
parameter_list|)
member_init_list|:
name|p1
argument_list|(
name|point1
argument_list|)
member_init_list|,
name|p2
argument_list|(
name|point2
argument_list|)
block|{}
DECL|member|p1
name|MyPoint
name|p1
decl_stmt|;
DECL|member|p2
name|MyPoint
name|p2
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|s
parameter_list|,
specifier|const
name|MyLine
modifier|&
name|line
parameter_list|)
block|{
specifier|const
name|QDebugStateSaver
name|saver
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|"MyLine("
operator|<<
name|line
operator|.
name|p1
operator|<<
literal|", "
operator|<<
name|line
operator|.
name|p2
operator|<<
literal|")"
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|debugSpaceHandling
name|void
name|tst_QDebug
operator|::
name|debugSpaceHandling
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|QDebug
name|d
init|=
name|qDebug
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|d
operator|.
name|autoInsertSpaces
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|.
name|setAutoInsertSpaces
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|d
operator|.
name|autoInsertSpaces
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|<<
literal|"  "
expr_stmt|;
name|d
operator|.
name|setAutoInsertSpaces
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|d
operator|.
name|autoInsertSpaces
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|<<
literal|"foo"
expr_stmt|;
name|d
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|d
operator|<<
literal|"key="
operator|<<
literal|"value"
expr_stmt|;
name|d
operator|.
name|space
argument_list|()
expr_stmt|;
name|d
operator|<<
literal|1
operator|<<
literal|2
expr_stmt|;
name|MyLine
name|line
argument_list|(
name|MyPoint
argument_list|(
literal|10
argument_list|,
literal|11
argument_list|)
argument_list|,
name|MyPoint
argument_list|(
literal|12
argument_list|,
literal|13
argument_list|)
argument_list|)
decl_stmt|;
name|d
operator|<<
name|line
expr_stmt|;
comment|// With the old implementation of MyPoint doing dbg.nospace()<< ...; dbg.space() we ended up with
comment|// MyLine(MyPoint(10, 11) ,  MyPoint(12, 13) )
block|}
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"  foo key=value 1 2 MyLine(MyPoint(10, 11), MyPoint(12, 13))"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stateSaver
name|void
name|tst_QDebug
operator|::
name|stateSaver
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|QDebug
name|d
init|=
name|qDebug
argument_list|()
decl_stmt|;
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|.
name|nospace
argument_list|()
operator|<<
name|hex
operator|<<
name|right
operator|<<
name|qSetFieldWidth
argument_list|(
literal|3
argument_list|)
operator|<<
name|qSetPadChar
argument_list|(
literal|'0'
argument_list|)
operator|<<
literal|42
expr_stmt|;
block|}
name|d
operator|.
name|space
argument_list|()
operator|<<
literal|42
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"02a 42"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|veryLongWarningMessage
name|void
name|tst_QDebug
operator|::
name|veryLongWarningMessage
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
name|QString
name|test
decl_stmt|;
block|{
name|QString
name|part
argument_list|(
literal|"0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789\n"
argument_list|)
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
literal|1000
condition|;
operator|++
name|i
control|)
name|test
operator|.
name|append
argument_list|(
name|part
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Test output:\n%s\nend"
argument_list|,
name|qPrintable
argument_list|(
name|test
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|2
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtWarningMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Test output:\n"
argument_list|)
operator|+
name|test
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\nend"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qDebugQStringRef
name|void
name|tst_QDebug
operator|::
name|qDebugQStringRef
parameter_list|()
specifier|const
block|{
comment|/* Use a basic string. */
block|{
specifier|const
name|QString
name|in
argument_list|(
name|QLatin1String
argument_list|(
literal|"input"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QStringRef
name|inRef
argument_list|(
operator|&
name|in
argument_list|)
decl_stmt|;
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|inRef
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"input\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
comment|/* Use a null QStringRef. */
block|{
specifier|const
name|QStringRef
name|inRef
decl_stmt|;
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|inRef
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qDebugQLatin1String
name|void
name|tst_QDebug
operator|::
name|qDebugQLatin1String
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"foo"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|""
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"barbaz"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"foo\" \"\" \"bar\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textStreamModifiers
name|void
name|tst_QDebug
operator|::
name|textStreamModifiers
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|hex
operator|<<
name|short
argument_list|(
literal|0xf
argument_list|)
operator|<<
name|int
argument_list|(
literal|0xf
argument_list|)
operator|<<
name|unsigned
argument_list|(
literal|0xf
argument_list|)
operator|<<
name|long
argument_list|(
literal|0xf
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|0xf
argument_list|)
operator|<<
name|quint64
argument_list|(
literal|0xf
argument_list|)
expr_stmt|;
block|}
name|QString
name|file
init|=
name|__FILE__
decl_stmt|;
name|int
name|line
init|=
name|__LINE__
operator|-
literal|1
decl_stmt|;
name|QString
name|function
init|=
name|Q_FUNC_INFO
decl_stmt|;
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_msg
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"f f f f f f"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_file
argument_list|)
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_function
argument_list|)
argument_list|,
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultMessagehandler
name|void
name|tst_QDebug
operator|::
name|defaultMessagehandler
parameter_list|()
specifier|const
block|{
name|MessageHandlerSetter
name|mhs
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QtMessageHandler
name|defaultMessageHandler1
init|=
name|qInstallMessageHandler
argument_list|(
operator|(
name|QtMessageHandler
operator|)
literal|0
argument_list|)
decl_stmt|;
name|QtMessageHandler
name|defaultMessageHandler2
init|=
name|qInstallMessageHandler
argument_list|(
name|myMessageHandler
argument_list|)
decl_stmt|;
name|bool
name|same
init|=
operator|(
operator|*
name|defaultMessageHandler1
operator|==
operator|*
name|defaultMessageHandler2
operator|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|same
argument_list|)
expr_stmt|;
name|QtMessageHandler
name|messageHandler
init|=
name|qInstallMessageHandler
argument_list|(
operator|(
name|QtMessageHandler
operator|)
literal|0
argument_list|)
decl_stmt|;
name|same
operator|=
operator|(
operator|*
name|messageHandler
operator|==
operator|*
name|myMessageHandler
operator|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|same
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QDebug
name|QTEST_MAIN
argument_list|(
name|tst_QDebug
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qdebug.moc"
end_include
end_unit
