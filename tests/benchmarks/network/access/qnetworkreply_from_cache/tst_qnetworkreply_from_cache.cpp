begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Hewlett-Packard Development Company, L.P. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkDiskCache>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QTcpSocket>
end_include
begin_define
DECL|macro|TEST_CASE_TIMEOUT
define|#
directive|define
name|TEST_CASE_TIMEOUT
value|30
end_define
begin_class
DECL|class|NetworkDiskCache
class|class
name|NetworkDiskCache
super|:
specifier|public
name|QNetworkDiskCache
block|{
public|public:
DECL|function|NetworkDiskCache
name|NetworkDiskCache
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QNetworkDiskCache
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|member|cachedData
name|QByteArray
name|cachedData
decl_stmt|;
DECL|function|metaData
specifier|virtual
name|QNetworkCacheMetaData
name|metaData
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QNetworkCacheMetaData
name|metaData
decl_stmt|;
if|if
condition|(
operator|!
name|cachedData
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|metaData
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|metaData
operator|.
name|setLastModified
argument_list|(
name|now
operator|.
name|addDays
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|metaData
operator|.
name|setExpirationDate
argument_list|(
name|now
operator|.
name|addDays
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|metaData
operator|.
name|setSaveToDisk
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
return|return
name|metaData
return|;
block|}
DECL|function|data
specifier|virtual
name|QIODevice
modifier|*
name|data
parameter_list|(
specifier|const
name|QUrl
modifier|&
comment|/*url*/
parameter_list|)
block|{
if|if
condition|(
name|cachedData
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|QBuffer
modifier|*
name|buffer
init|=
operator|new
name|QBuffer
decl_stmt|;
name|buffer
operator|->
name|setData
argument_list|(
name|cachedData
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|HttpServer
class|class
name|HttpServer
super|:
specifier|public
name|QTcpServer
block|{
name|Q_OBJECT
public|public:
DECL|function|HttpServer
name|HttpServer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|reply
parameter_list|)
member_init_list|:
name|m_reply
argument_list|(
name|reply
argument_list|)
member_init_list|,
name|m_writePos
argument_list|()
member_init_list|,
name|m_client
argument_list|()
block|{
name|listen
argument_list|(
name|QHostAddress
operator|::
name|AnyIPv4
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
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
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
private|private
name|Q_SLOTS
private|:
DECL|function|accept
name|void
name|accept
parameter_list|()
block|{
name|m_client
operator|=
name|nextPendingConnection
argument_list|()
expr_stmt|;
name|m_client
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_client
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
name|reply
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|reply
name|void
name|reply
parameter_list|()
block|{
name|disconnect
argument_list|(
name|m_client
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_client
operator|->
name|readAll
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|m_client
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|write
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|()
expr_stmt|;
block|}
DECL|function|write
name|void
name|write
parameter_list|()
block|{
name|qint64
name|pos
init|=
name|m_client
operator|->
name|write
argument_list|(
name|m_reply
operator|.
name|mid
argument_list|(
name|m_writePos
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|>
literal|0
condition|)
name|m_writePos
operator|+=
name|pos
expr_stmt|;
if|if
condition|(
name|m_writePos
operator|>=
name|m_reply
operator|.
name|size
argument_list|()
condition|)
name|m_client
operator|->
name|disconnect
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_reply
name|QByteArray
name|m_reply
decl_stmt|;
DECL|member|m_writePos
name|qint64
name|m_writePos
decl_stmt|;
DECL|member|m_client
name|QTcpSocket
modifier|*
name|m_client
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_qnetworkreply_from_cache
class|class
name|tst_qnetworkreply_from_cache
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_qnetworkreply_from_cache
parameter_list|()
constructor_decl|;
name|void
name|timeReadAll
parameter_list|(
specifier|const
name|QString
modifier|&
name|headers
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|readAll_data
parameter_list|()
function_decl|;
name|void
name|readAll
parameter_list|()
function_decl|;
name|void
name|readAllFromCache_data
parameter_list|()
function_decl|;
name|void
name|readAllFromCache
parameter_list|()
function_decl|;
protected|protected
name|Q_SLOTS
protected|:
DECL|function|replyReadAll
name|void
name|replyReadAll
parameter_list|()
block|{
name|m_replyData
operator|+=
name|m_reply
operator|->
name|readAll
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_tempDir
name|QTemporaryDir
name|m_tempDir
decl_stmt|;
DECL|member|m_networkAccessManager
name|QNetworkAccessManager
modifier|*
name|m_networkAccessManager
decl_stmt|;
DECL|member|m_networkDiskCache
name|NetworkDiskCache
modifier|*
name|m_networkDiskCache
decl_stmt|;
DECL|member|m_reply
name|QNetworkReply
modifier|*
name|m_reply
decl_stmt|;
DECL|member|m_replyData
name|QByteArray
name|m_replyData
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_qnetworkreply_from_cache
name|tst_qnetworkreply_from_cache
operator|::
name|tst_qnetworkreply_from_cache
parameter_list|()
member_init_list|:
name|m_tempDir
argument_list|(
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
literal|"/tst_qnetworkreply_from_cache.XXXXXX"
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|timeReadAll
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|timeReadAll
parameter_list|(
specifier|const
name|QString
modifier|&
name|headers
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QByteArray
name|reply
decl_stmt|;
name|reply
operator|.
name|append
argument_list|(
name|headers
argument_list|)
expr_stmt|;
name|reply
operator|.
name|append
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|m_replyData
operator|.
name|reserve
argument_list|(
name|data
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|HttpServer
name|server
argument_list|(
name|reply
argument_list|)
decl_stmt|;
name|QBENCHMARK_ONCE
block|{
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
name|QString
argument_list|(
literal|"http://127.0.0.1:%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|m_reply
operator|=
name|m_networkAccessManager
operator|->
name|get
argument_list|(
name|request
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_reply
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
name|replyReadAll
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_reply
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
name|TEST_CASE_TIMEOUT
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|m_reply
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|m_replyData
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|data
argument_list|,
name|m_replyData
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|initTestCase
parameter_list|()
block|{
name|m_networkAccessManager
operator|=
operator|new
name|QNetworkAccessManager
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_networkDiskCache
operator|=
operator|new
name|NetworkDiskCache
argument_list|(
name|m_networkAccessManager
argument_list|)
expr_stmt|;
name|m_networkDiskCache
operator|->
name|setCacheDirectory
argument_list|(
name|m_tempDir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|m_networkAccessManager
operator|->
name|setCache
argument_list|(
name|m_networkDiskCache
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|cleanup
parameter_list|()
block|{
name|m_replyData
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readAll_data
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|readAll_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dataSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|1e6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|5e6
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10MB"
argument_list|)
operator|<<
operator|(
name|int
operator|)
literal|10e6
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readAll
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|readAll
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|QString
name|headers
init|=
name|QString
argument_list|(
literal|"HTTP/1.0 200 OK\r\nContent-Length: %1\r\n\r\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|dataSize
argument_list|)
decl_stmt|;
name|QByteArray
name|data
argument_list|(
name|QByteArray
argument_list|(
name|dataSize
argument_list|,
operator|(
name|char
operator|)
literal|42
argument_list|)
argument_list|)
decl_stmt|;
name|m_networkDiskCache
operator|->
name|cachedData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|timeReadAll
argument_list|(
name|headers
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readAllFromCache_data
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|readAllFromCache_data
parameter_list|()
block|{
name|readAll_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readAllFromCache
name|void
name|tst_qnetworkreply_from_cache
operator|::
name|readAllFromCache
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|QByteArray
name|headers
argument_list|(
literal|"HTTP/1.0 304 Use Cache\r\n\r\n"
argument_list|)
decl_stmt|;
name|QByteArray
name|data
argument_list|(
name|QByteArray
argument_list|(
name|dataSize
argument_list|,
operator|(
name|char
operator|)
literal|42
argument_list|)
argument_list|)
decl_stmt|;
name|m_networkDiskCache
operator|->
name|cachedData
operator|=
name|data
expr_stmt|;
name|timeReadAll
argument_list|(
name|headers
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qnetworkreply_from_cache
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkreply_from_cache.moc"
end_include
end_unit
