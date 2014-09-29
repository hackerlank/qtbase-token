begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This test is for "release" mode, with -DQT_NO_DEBUG -DQT_NO_DEBUG_OUTPUT
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
end_ifndef
begin_define
DECL|macro|QT_NO_DEBUG
define|#
directive|define
name|QT_NO_DEBUG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
end_ifndef
begin_define
DECL|macro|QT_NO_DEBUG_OUTPUT
define|#
directive|define
name|QT_NO_DEBUG_OUTPUT
end_define
begin_endif
endif|#
directive|endif
end_endif
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
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QNoDebug
class|class
name|tst_QNoDebug
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|noDebugOutput
parameter_list|()
specifier|const
function_decl|;
name|void
name|streaming
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|noDebugOutput
name|void
name|tst_QNoDebug
operator|::
name|noDebugOutput
parameter_list|()
specifier|const
block|{
name|QLoggingCategory
name|cat
argument_list|(
literal|"custom"
argument_list|)
decl_stmt|;
comment|// should do nothing
name|qDebug
argument_list|()
operator|<<
literal|"foo"
expr_stmt|;
name|qCDebug
argument_list|(
name|cat
argument_list|)
operator|<<
literal|"foo"
expr_stmt|;
comment|// qWarning still works, though
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"custom-bar"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"bar"
expr_stmt|;
name|qCWarning
argument_list|(
name|cat
argument_list|)
operator|<<
literal|"custom-bar"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|streaming
name|void
name|tst_QNoDebug
operator|::
name|streaming
parameter_list|()
specifier|const
block|{
name|QDateTime
name|dt
argument_list|(
name|QDate
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|debugString
init|=
name|dt
operator|.
name|toString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"yyyy-MM-dd HH:mm:ss.zzz t"
argument_list|)
argument_list|)
operator|+
name|QStringLiteral
argument_list|(
literal|" Qt::LocalTime"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QDateTime(\"%1\")"
argument_list|)
operator|.
name|arg
argument_list|(
name|debugString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|dt
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QNoDebug
name|QTEST_MAIN
argument_list|(
name|tst_QNoDebug
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qnodebug.moc"
end_include
end_unit
