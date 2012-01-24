begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Make sure we get a real Q_ASSERT even in release builds
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_DEBUG
end_ifdef
begin_undef
DECL|macro|QT_NO_DEBUG
undef|#
directive|undef
name|QT_NO_DEBUG
end_undef
begin_endif
endif|#
directive|endif
end_endif
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
begin_class
DECL|class|tst_Assert
class|class
name|tst_Assert
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testNumber1
parameter_list|()
specifier|const
function_decl|;
name|void
name|testNumber2
parameter_list|()
specifier|const
function_decl|;
name|void
name|testNumber3
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testNumber1
name|void
name|tst_Assert
operator|::
name|testNumber1
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|testNumber2
name|void
name|tst_Assert
operator|::
name|testNumber2
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testNumber3
name|void
name|tst_Assert
operator|::
name|testNumber3
parameter_list|()
specifier|const
block|{ }
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Assert
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_assert.moc"
end_include
end_unit
