begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|object
parameter_list|,
name|child
parameter_list|,
name|event
parameter_list|)
define|\
value|QVERIFY(QTestAccessibility::verifyEvent(object, child, (int)event))
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
file|<QtGui/qapplication.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Test
argument_list|)
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QTestAccessibilityEvent
struct|struct
name|QTestAccessibilityEvent
block|{
DECL|function|QTestAccessibilityEvent
name|QTestAccessibilityEvent
argument_list|(
argument|QObject* o =
literal|0
argument_list|,
argument|int c =
literal|0
argument_list|,
argument|int e =
literal|0
argument_list|)
block|:
name|object
argument_list|(
name|o
argument_list|)
operator|,
name|child
argument_list|(
name|c
argument_list|)
operator|,
name|event
argument_list|(
argument|e
argument_list|)
block|{}
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTestAccessibilityEvent
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|o
operator|.
name|object
operator|==
name|object
operator|&&
name|o
operator|.
name|child
operator|==
name|child
operator|&&
name|o
operator|.
name|event
operator|==
name|event
return|;
block|}
DECL|member|object
name|QObject
modifier|*
name|object
decl_stmt|;
DECL|member|child
name|int
name|child
decl_stmt|;
DECL|member|event
name|int
name|event
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|EventList
typedef|typedef
name|QList
operator|<
name|QTestAccessibilityEvent
operator|>
name|EventList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QTestAccessibility
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
name|QTestAccessibilityEvent
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
specifier|static
name|bool
name|verifyEvent
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|e
parameter_list|)
block|{
return|return
name|verifyEvent
argument_list|(
name|QTestAccessibilityEvent
argument_list|(
name|o
argument_list|,
name|c
argument_list|,
name|e
argument_list|)
argument_list|)
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
name|QApplication
modifier|*
name|app
init|=
name|qobject_cast
operator|<
name|QApplication
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
literal|"%s: root Object is not a QApplication!"
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
specifier|static
name|void
name|updateHandler
argument_list|(
argument|QObject *o
argument_list|,
argument|int c
argument_list|,
argument|QAccessible::Event e
argument_list|)
block|{
comment|//    qDebug("updateHandler called: %p %d %d", o, c, (int)e);
name|eventList
argument_list|()
operator|.
name|append
argument_list|(
name|QTestAccessibilityEvent
argument_list|(
name|o
argument_list|,
name|c
argument_list|,
operator|(
name|int
operator|)
name|e
argument_list|)
argument_list|)
block|;     }
specifier|static
name|EventList
operator|&
name|eventList
argument_list|()
block|{
specifier|static
name|EventList
name|list
block|;
return|return
name|list
return|;
block|}
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
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
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
