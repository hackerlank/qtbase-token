begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDomDocument>
end_include
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QXmlDefaultHandler>
end_include
begin_include
include|#
directive|include
file|<QXmlInputSource>
end_include
begin_include
include|#
directive|include
file|<QXmlSimpleReader>
end_include
begin_class
DECL|class|tst_QXmlInputSource
class|class
name|tst_QXmlInputSource
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|reset
parameter_list|()
specifier|const
function_decl|;
name|void
name|resetSimplified
parameter_list|()
specifier|const
function_decl|;
name|void
name|waitForReadyIODevice
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!   \internal   \since 4.4    See task 166278.  */
end_comment
begin_function
DECL|function|reset
name|void
name|tst_QXmlInputSource
operator|::
name|reset
parameter_list|()
specifier|const
block|{
specifier|const
name|QString
name|input
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<element attribute1='value1' attribute2='value2'/>"
argument_list|)
argument_list|)
decl_stmt|;
name|QXmlSimpleReader
name|reader
decl_stmt|;
name|QXmlDefaultHandler
name|handler
decl_stmt|;
name|reader
operator|.
name|setContentHandler
argument_list|(
operator|&
name|handler
argument_list|)
expr_stmt|;
name|QXmlInputSource
name|source
decl_stmt|;
name|source
operator|.
name|setData
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|source
operator|.
name|data
argument_list|()
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|source
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|source
operator|.
name|data
argument_list|()
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|source
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader
operator|.
name|parse
argument_list|(
name|source
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|source
operator|.
name|data
argument_list|()
argument_list|,
name|input
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal   \since 4.4    See task 166278.  */
end_comment
begin_function
DECL|function|resetSimplified
name|void
name|tst_QXmlInputSource
operator|::
name|resetSimplified
parameter_list|()
specifier|const
block|{
specifier|const
name|QString
name|input
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<element/>"
argument_list|)
argument_list|)
decl_stmt|;
name|QXmlSimpleReader
name|reader
decl_stmt|;
name|QXmlInputSource
name|source
decl_stmt|;
name|source
operator|.
name|setData
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader
operator|.
name|parse
argument_list|(
name|source
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|source
operator|.
name|data
argument_list|()
argument_list|,
name|input
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ServerAndClient
class|class
name|ServerAndClient
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|ServerAndClient
name|ServerAndClient
parameter_list|(
name|QEventLoop
modifier|&
name|ev
parameter_list|)
member_init_list|:
name|success
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|eventLoop
argument_list|(
name|ev
argument_list|)
member_init_list|,
name|bodyBytesRead
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|bodyLength
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|isBody
argument_list|(
literal|false
argument_list|)
block|{
name|setObjectName
argument_list|(
literal|"serverAndClient"
argument_list|)
expr_stmt|;
name|tcpServer
operator|=
operator|new
name|QTcpServer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tcpServer
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newConnection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tcpServer
operator|->
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
literal|1088
argument_list|)
expr_stmt|;
name|httpClient
operator|=
operator|new
name|QNetworkAccessManager
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|httpClient
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|requestFinished
argument_list|(
name|QNetworkReply
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|member|success
name|bool
name|success
decl_stmt|;
DECL|member|eventLoop
name|QEventLoop
modifier|&
name|eventLoop
decl_stmt|;
public|public
name|slots
public|:
DECL|function|doIt
name|void
name|doIt
parameter_list|()
block|{
name|QUrl
name|url
argument_list|(
literal|"http://127.0.0.1:1088"
argument_list|)
decl_stmt|;
name|QNetworkRequest
name|req
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|req
operator|.
name|setRawHeader
argument_list|(
literal|"POST"
argument_list|,
name|url
operator|.
name|path
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|req
operator|.
name|setRawHeader
argument_list|(
literal|"user-agent"
argument_list|,
literal|"xml-test"
argument_list|)
expr_stmt|;
name|req
operator|.
name|setRawHeader
argument_list|(
literal|"keep-alive"
argument_list|,
literal|"false"
argument_list|)
expr_stmt|;
name|req
operator|.
name|setRawHeader
argument_list|(
literal|"host"
argument_list|,
name|url
operator|.
name|host
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|xmlrpc
argument_list|(
literal|"<methodCall>\r\n\<methodName>SFD.GetVersion</methodName>\r\n\<params/>\r\n\</methodCall>"
argument_list|)
decl_stmt|;
name|req
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentLengthHeader
argument_list|,
name|xmlrpc
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|req
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentTypeHeader
argument_list|,
literal|"text/xml"
argument_list|)
expr_stmt|;
name|httpClient
operator|->
name|post
argument_list|(
name|req
argument_list|,
name|xmlrpc
argument_list|)
expr_stmt|;
block|}
DECL|function|requestFinished
name|void
name|requestFinished
parameter_list|(
name|QNetworkReply
modifier|*
name|reply
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|reply
operator|->
name|error
argument_list|()
argument_list|,
name|QNetworkReply
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|reply
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|newConnection
name|void
name|newConnection
parameter_list|()
block|{
name|QTcpSocket
modifier|*
specifier|const
name|s
init|=
name|tcpServer
operator|->
name|nextPendingConnection
argument_list|()
decl_stmt|;
if|if
condition|(
name|s
condition|)
name|connect
argument_list|(
name|s
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|readyRead
name|void
name|readyRead
parameter_list|()
block|{
name|QTcpSocket
modifier|*
specifier|const
name|s
init|=
cast|static_cast
argument_list|<
name|QTcpSocket
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|s
operator|->
name|bytesAvailable
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|line
argument_list|(
name|s
operator|->
name|readLine
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"Content-Length:"
argument_list|)
condition|)
name|bodyLength
operator|=
name|line
operator|.
name|mid
argument_list|(
literal|15
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|isBody
condition|)
block|{
name|body
operator|.
name|append
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|bodyBytesRead
operator|+=
name|line
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|line
operator|==
literal|"\r\n"
condition|)
block|{
name|isBody
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|bodyLength
operator|==
operator|-
literal|1
condition|)
block|{
name|qFatal
argument_list|(
literal|"No length was specified in the header."
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|bodyBytesRead
operator|==
name|bodyLength
condition|)
block|{
name|QDomDocument
name|domDoc
decl_stmt|;
name|success
operator|=
name|domDoc
operator|.
name|setContent
argument_list|(
name|body
argument_list|)
expr_stmt|;
name|eventLoop
operator|.
name|exit
argument_list|()
expr_stmt|;
block|}
block|}
private|private:
DECL|member|body
name|QByteArray
name|body
decl_stmt|;
DECL|member|bodyBytesRead
DECL|member|bodyLength
name|int
name|bodyBytesRead
decl_stmt|,
name|bodyLength
decl_stmt|;
DECL|member|isBody
name|bool
name|isBody
decl_stmt|;
DECL|member|tcpServer
name|QTcpServer
modifier|*
name|tcpServer
decl_stmt|;
DECL|member|httpClient
name|QNetworkAccessManager
modifier|*
name|httpClient
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|waitForReadyIODevice
name|void
name|tst_QXmlInputSource
operator|::
name|waitForReadyIODevice
parameter_list|()
specifier|const
block|{
name|QEventLoop
name|el
decl_stmt|;
name|ServerAndClient
name|sv
argument_list|(
name|el
argument_list|)
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|1
argument_list|,
operator|&
name|sv
argument_list|,
name|SLOT
argument_list|(
name|doIt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|el
operator|.
name|exec
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|sv
operator|.
name|success
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QXmlInputSource
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qxmlinputsource.moc"
end_include
end_unit
