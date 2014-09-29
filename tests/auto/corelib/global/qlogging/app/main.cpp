begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_GNU
end_ifdef
begin_define
DECL|macro|NEVER_INLINE
define|#
directive|define
name|NEVER_INLINE
value|__attribute__((__noinline__))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|NEVER_INLINE
define|#
directive|define
name|NEVER_INLINE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|T
struct|struct
name|T
block|{
DECL|function|T
name|T
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"static constructor"
argument_list|)
expr_stmt|;
block|}
DECL|function|~T
name|~
name|T
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"static destructor"
argument_list|)
expr_stmt|;
block|}
block|}
DECL|variable|t
name|t
struct|;
end_struct
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
specifier|virtual
name|NEVER_INLINE
name|QString
name|mySlot1
parameter_list|()
function_decl|;
private|private:
specifier|virtual
name|NEVER_INLINE
name|void
name|myFunction
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|mySlot1
name|QString
name|MyClass
operator|::
name|mySlot1
parameter_list|()
block|{
name|myFunction
argument_list|(
literal|34
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|myFunction
name|void
name|MyClass
operator|::
name|myFunction
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"from_a_function"
operator|<<
name|a
expr_stmt|;
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
name|app
operator|.
name|setApplicationName
argument_list|(
literal|"tst_qlogging"
argument_list|)
expr_stmt|;
name|qSetMessagePattern
argument_list|(
literal|"[%{type}] %{message}"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"qDebug"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"qWarning"
argument_list|)
expr_stmt|;
name|qCritical
argument_list|(
literal|"qCritical"
argument_list|)
expr_stmt|;
name|QLoggingCategory
name|cat
argument_list|(
literal|"category"
argument_list|)
decl_stmt|;
name|qCWarning
argument_list|(
name|cat
argument_list|)
operator|<<
literal|"qDebug with category"
expr_stmt|;
name|qSetMessagePattern
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"qDebug2"
argument_list|)
expr_stmt|;
name|MyClass
name|cl
decl_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
operator|&
name|cl
argument_list|,
literal|"mySlot1"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
