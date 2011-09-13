begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|"qkeymapper_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QKeyMapper     \since 4.2     \internal      \sa QObject */
end_comment
begin_comment
comment|/*!     Constructs a new key mapper. */
end_comment
begin_constructor
DECL|function|QKeyMapper
name|QKeyMapper
operator|::
name|QKeyMapper
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QKeyMapperPrivate
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the key mapper. */
end_comment
begin_destructor
DECL|function|~QKeyMapper
name|QKeyMapper
operator|::
name|~
name|QKeyMapper
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|possibleKeys
name|QList
argument_list|<
name|int
argument_list|>
name|QKeyMapper
operator|::
name|possibleKeys
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|result
decl_stmt|;
if|if
condition|(
operator|!
name|e
operator|->
name|nativeScanCode
argument_list|()
condition|)
block|{
if|if
condition|(
name|e
operator|->
name|key
argument_list|()
operator|&&
operator|(
name|e
operator|->
name|key
argument_list|()
operator|!=
name|Qt
operator|::
name|Key_unknown
operator|)
condition|)
name|result
operator|<<
name|int
argument_list|(
name|e
operator|->
name|key
argument_list|()
operator|+
name|e
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|e
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|<<
name|int
argument_list|(
name|e
operator|->
name|text
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
operator|+
name|e
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
return|return
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|possibleKeys
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|extern
name|bool
name|qt_sendSpontaneousEvent
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// in qapplication_*.cpp
end_comment
begin_function
DECL|function|changeKeyboard
name|void
name|QKeyMapper
operator|::
name|changeKeyboard
parameter_list|()
block|{
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|clearMappings
argument_list|()
expr_stmt|;
comment|// ## TODO: Support KeyboardLayoutChange on QPA
if|#
directive|if
literal|0
comment|// inform all toplevel widgets of the change
block|QEvent e(QEvent::KeyboardLayoutChange);     QWidgetList list = QApplication::topLevelWidgets();     for (int i = 0; i< list.size(); ++i) {         QWidget *w = list.at(i);         qt_sendSpontaneousEvent(w,&e);     }
endif|#
directive|endif
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QKeyMapper
argument_list|,
argument|keymapper
argument_list|)
end_macro
begin_comment
comment|/*!     Returns the pointer to the single instance of QKeyMapper in the application.     If none yet exists, the function ensures that one is created. */
end_comment
begin_function
DECL|function|instance
name|QKeyMapper
modifier|*
name|QKeyMapper
operator|::
name|instance
parameter_list|()
block|{
return|return
name|keymapper
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qt_keymapper_private
name|QKeyMapperPrivate
modifier|*
name|qt_keymapper_private
parameter_list|()
block|{
return|return
name|QKeyMapper
operator|::
name|instance
argument_list|()
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
