begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qabstractsocket.h>
end_include
begin_class
DECL|class|tst_QAbstractSocket
class|class
name|tst_QAbstractSocket
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAbstractSocket
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QAbstractSocket
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAbstractSocket
name|tst_QAbstractSocket
operator|::
name|tst_QAbstractSocket
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QAbstractSocket
name|tst_QAbstractSocket
operator|::
name|~
name|tst_QAbstractSocket
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|MyAbstractSocket
class|class
name|MyAbstractSocket
super|:
specifier|public
name|QAbstractSocket
block|{
public|public:
DECL|function|MyAbstractSocket
name|MyAbstractSocket
parameter_list|()
member_init_list|:
name|QAbstractSocket
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|,
literal|0
argument_list|)
block|{}
DECL|function|setLocalPort
name|void
name|setLocalPort
parameter_list|(
name|quint16
name|port
parameter_list|)
block|{
name|QAbstractSocket
operator|::
name|setLocalPort
argument_list|(
name|port
argument_list|)
expr_stmt|;
block|}
DECL|function|setPeerPort
name|void
name|setPeerPort
parameter_list|(
name|quint16
name|port
parameter_list|)
block|{
name|QAbstractSocket
operator|::
name|setPeerPort
argument_list|(
name|port
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QAbstractSocket
operator|::
name|getSetCheck
parameter_list|()
block|{
name|MyAbstractSocket
name|obj1
decl_stmt|;
comment|// qint64 QAbstractSocket::readBufferSize()
comment|// void QAbstractSocket::setReadBufferSize(qint64)
name|obj1
operator|.
name|setReadBufferSize
argument_list|(
name|qint64
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qint64
argument_list|(
literal|0
argument_list|)
argument_list|,
name|obj1
operator|.
name|readBufferSize
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setReadBufferSize
argument_list|(
operator|(
name|Q_INT64_C
argument_list|(
operator|-
literal|9223372036854775807
argument_list|)
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|Q_INT64_C
argument_list|(
operator|-
literal|9223372036854775807
argument_list|)
operator|-
literal|1
operator|)
argument_list|,
name|obj1
operator|.
name|readBufferSize
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setReadBufferSize
argument_list|(
name|Q_INT64_C
argument_list|(
literal|9223372036854775807
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Q_INT64_C
argument_list|(
literal|9223372036854775807
argument_list|)
argument_list|,
name|obj1
operator|.
name|readBufferSize
argument_list|()
argument_list|)
expr_stmt|;
comment|// quint16 QAbstractSocket::localPort()
comment|// void QAbstractSocket::setLocalPort(quint16)
name|obj1
operator|.
name|setLocalPort
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|,
name|obj1
operator|.
name|localPort
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setLocalPort
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|,
name|obj1
operator|.
name|localPort
argument_list|()
argument_list|)
expr_stmt|;
comment|// quint16 QAbstractSocket::peerPort()
comment|// void QAbstractSocket::setPeerPort(quint16)
name|obj1
operator|.
name|setPeerPort
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|,
name|obj1
operator|.
name|peerPort
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPeerPort
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|,
name|obj1
operator|.
name|peerPort
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractSocket
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractsocket.moc"
end_include
end_unit
