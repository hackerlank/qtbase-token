begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for QNetworkReply functions.
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkaccessmanager.h>
end_include
begin_class
DECL|class|tst_qhttpnetworkconnection
class|class
name|tst_qhttpnetworkconnection
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|bigRemoteFile
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|urlC
specifier|const
name|char
name|urlC
index|[]
init|=
literal|"http://download.qt-project.org/official_releases/online_installers/qt-linux-opensource-1.4.0-x86-online.run"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|bigRemoteFile
name|void
name|tst_qhttpnetworkconnection
operator|::
name|bigRemoteFile
parameter_list|()
block|{
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|qint64
name|size
decl_stmt|;
name|QTime
name|t
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|urlC
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reply
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
name|qDebug
argument_list|()
operator|<<
literal|"Starting download"
operator|<<
name|urlC
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|50
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
name|size
operator|=
name|reply
operator|->
name|size
argument_list|()
expr_stmt|;
operator|delete
name|reply
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Finished!"
operator|<<
name|endl
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Time:"
operator|<<
name|t
operator|.
name|elapsed
argument_list|()
operator|<<
literal|"msec"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bytes:"
operator|<<
name|size
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Speed:"
operator|<<
operator|(
name|size
operator|/
name|qreal
argument_list|(
literal|1024
argument_list|)
operator|)
operator|/
operator|(
name|t
operator|.
name|elapsed
argument_list|()
operator|/
name|qreal
argument_list|(
literal|1000
argument_list|)
operator|)
operator|<<
literal|"KB/sec"
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qhttpnetworkconnection
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
