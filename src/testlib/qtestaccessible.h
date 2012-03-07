begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTACCESSIBLE_H
end_ifndef
begin_define
DECL|macro|QTESTACCESSIBLE_H
define|#
directive|define
name|QTESTACCESSIBLE_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_define
DECL|macro|QVERIFY_EVENT
define|#
directive|define
name|QVERIFY_EVENT
parameter_list|(
name|event
parameter_list|)
define|\
value|QVERIFY(QTestAccessibility::verifyEvent(event))
end_define
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|EventList
typedef|typedef
name|QList
operator|<
name|QAccessibleEvent
operator|>
name|EventList
expr_stmt|;
end_typedef
begin_expr_stmt
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QAccessibleEvent
operator|&
name|l
operator|,
specifier|const
name|QAccessibleEvent
operator|&
name|r
operator|)
block|{
if|if
condition|(
name|l
operator|.
name|type
argument_list|()
operator|!=
name|r
operator|.
name|type
argument_list|()
operator|||
name|l
operator|.
name|object
argument_list|()
operator|!=
name|r
operator|.
name|object
argument_list|()
operator|||
name|l
operator|.
name|child
argument_list|()
operator|!=
name|r
operator|.
name|child
argument_list|()
condition|)
return|return
name|false
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|l
operator|.
name|type
argument_list|()
operator|==
name|QAccessible
operator|::
name|StateChanged
condition|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|QAccessibleStateChangeEvent
operator|*
operator|>
operator|(
operator|&
name|l
operator|)
operator|->
name|changedStates
argument_list|()
operator|==
name|static_cast
operator|<
specifier|const
name|QAccessibleStateChangeEvent
operator|*
operator|>
operator|(
operator|&
name|r
operator|)
operator|->
name|changedStates
argument_list|()
return|;
block|}
end_if
begin_return
return|return
name|true
return|;
end_return
begin_macro
unit|}  class
name|QTestAccessibility
end_macro
begin_block
block|{
name|public
label|:
specifier|static
name|void
name|initialize
parameter_list|()
block|{
if|if
condition|(
operator|!
name|instance
argument_list|()
condition|)
block|{
name|instance
argument_list|()
operator|=
name|new
name|QTestAccessibility
expr_stmt|;
name|qAddPostRoutine
argument_list|(
name|cleanup
argument_list|)
expr_stmt|;
block|}
block|}
specifier|static
name|void
name|cleanup
parameter_list|()
block|{
name|delete
name|instance
parameter_list|()
function_decl|;
name|instance
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
specifier|static
name|void
name|clearEvents
parameter_list|()
block|{
name|eventList
argument_list|()
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|static
name|EventList
name|events
parameter_list|()
block|{
return|return
name|eventList
argument_list|()
return|;
block|}
specifier|static
name|bool
name|verifyEvent
parameter_list|(
specifier|const
name|QAccessibleEvent
modifier|&
name|ev
parameter_list|)
block|{
if|if
condition|(
name|eventList
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|FALSE
return|;
return|return
name|eventList
argument_list|()
operator|.
name|takeFirst
argument_list|()
operator|==
name|ev
return|;
block|}
name|private
label|:
name|QTestAccessibility
argument_list|()
block|{
name|QAccessible
operator|::
name|installUpdateHandler
argument_list|(
name|updateHandler
argument_list|)
expr_stmt|;
name|QAccessible
operator|::
name|installRootObjectHandler
argument_list|(
name|rootObjectHandler
argument_list|)
expr_stmt|;
block|}
operator|~
name|QTestAccessibility
argument_list|()
block|{
name|QAccessible
operator|::
name|installUpdateHandler
argument_list|(
literal|0
argument_list|)
block|;
name|QAccessible
operator|::
name|installRootObjectHandler
argument_list|(
literal|0
argument_list|)
block|;     }
specifier|static
name|void
name|rootObjectHandler
argument_list|(
argument|QObject *object
argument_list|)
block|{
comment|//    qDebug("rootObjectHandler called %p", object);
if|if
condition|(
name|object
condition|)
block|{
name|QGuiApplication
modifier|*
name|app
init|=
name|qobject_cast
operator|<
name|QGuiApplication
operator|*
operator|>
operator|(
name|object
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|app
condition|)
name|qWarning
argument_list|(
literal|"%s: root Object is not a QGuiApplication!"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"%s: root Object called with 0 pointer"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
block|}
block|}
end_block
begin_function
specifier|static
name|void
name|updateHandler
parameter_list|(
specifier|const
name|QAccessibleEvent
modifier|&
name|event
parameter_list|)
block|{
name|eventList
argument_list|()
operator|.
name|append
argument_list|(
name|copyEvent
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|QAccessibleEvent
name|copyEvent
parameter_list|(
specifier|const
name|QAccessibleEvent
modifier|&
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|.
name|type
argument_list|()
operator|==
name|QAccessible
operator|::
name|StateChanged
condition|)
return|return
name|QAccessibleStateChangeEvent
argument_list|(
name|static_cast
operator|<
specifier|const
name|QAccessibleStateChangeEvent
operator|*
operator|>
operator|(
operator|&
name|event
operator|)
operator|->
name|changedStates
argument_list|()
argument_list|,
name|event
operator|.
name|object
argument_list|()
argument_list|,
name|event
operator|.
name|child
argument_list|()
argument_list|)
return|;
return|return
name|QAccessibleEvent
argument_list|(
name|event
operator|.
name|type
argument_list|()
argument_list|,
name|event
operator|.
name|object
argument_list|()
argument_list|,
name|event
operator|.
name|child
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|EventList
modifier|&
name|eventList
parameter_list|()
block|{
specifier|static
name|EventList
name|list
decl_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
specifier|static
name|QTestAccessibility
modifier|*
modifier|&
name|instance
parameter_list|()
block|{
specifier|static
name|QTestAccessibility
modifier|*
name|ta
init|=
literal|0
decl_stmt|;
return|return
name|ta
return|;
block|}
end_function
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
