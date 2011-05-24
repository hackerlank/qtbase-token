begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
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
name|debugWithQBool
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
literal|"foo "
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"bar 1 2 "
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
name|QByteArray
name|s_msg
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
name|char
modifier|*
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
block|}
end_function
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
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
block|{
name|qWarning
argument_list|()
operator|<<
literal|"A qWarning() message"
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtWarningMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A qWarning() message "
argument_list|)
argument_list|)
expr_stmt|;
name|qInstallMsgHandler
argument_list|(
literal|0
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
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
block|{
name|qCritical
argument_list|()
operator|<<
literal|"A qCritical() message"
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtCriticalMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A qCritical() message "
argument_list|)
argument_list|)
expr_stmt|;
name|qInstallMsgHandler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|debugWithQBool
name|void
name|tst_QDebug
operator|::
name|debugWithQBool
parameter_list|()
specifier|const
block|{
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|QBool
argument_list|(
literal|false
argument_list|)
operator|<<
name|QBool
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"false true "
argument_list|)
argument_list|)
expr_stmt|;
name|qInstallMsgHandler
argument_list|(
literal|0
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
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
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
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtWarningMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
argument_list|)
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
name|qInstallMsgHandler
argument_list|(
literal|0
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
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|inRef
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"input\" "
argument_list|)
argument_list|)
expr_stmt|;
name|qInstallMsgHandler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Use a null QStringRef. */
block|{
specifier|const
name|QStringRef
name|inRef
decl_stmt|;
name|qInstallMsgHandler
argument_list|(
name|myMessageHandler
argument_list|)
expr_stmt|;
block|{
name|qDebug
argument_list|()
operator|<<
name|inRef
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s_msgType
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|s_msg
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"\" "
argument_list|)
argument_list|)
expr_stmt|;
name|qInstallMsgHandler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
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
