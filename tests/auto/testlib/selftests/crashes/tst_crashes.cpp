begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_Crashes
class|class
name|tst_Crashes
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|crash
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|crash
name|void
name|tst_Crashes
operator|::
name|crash
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
comment|//we avoid the error dialogbox to appear on windows
name|SetErrorMode
argument_list|(
name|SEM_NOGPFAULTERRORBOX
operator||
name|SEM_FAILCRITICALERRORS
operator||
name|SEM_NOOPENFILEERRORBOX
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/*         We deliberately dereference an invalid but non-zero address;         it should be non-zero because a few platforms may have special crash behavior         when dereferencing exactly 0 (e.g. some macs have been observed to generate SIGILL         rather than SIGSEGV).     */
name|int
modifier|*
name|i
init|=
literal|0
decl_stmt|;
name|i
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Crashes
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_crashes.moc"
end_include
end_unit
