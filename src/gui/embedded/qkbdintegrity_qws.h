begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKBDINTEGRITY_QWS_H
end_ifndef
begin_define
DECL|macro|QKBDINTEGRITY_QWS_H
define|#
directive|define
name|QKBDINTEGRITY_QWS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qkbd_qws.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_QWS_KEYBOARD
ifndef|#
directive|ifndef
name|QT_NO_QWS_KBD_INTEGRITY
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWSIntKbPrivate
name|class
name|QWSIntKbPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWSIntKeyboardHandler
range|:
name|public
name|QWSKeyboardHandler
block|{
name|public
operator|:
name|explicit
name|QWSIntKeyboardHandler
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
operator|~
name|QWSIntKeyboardHandler
argument_list|()
block|;
comment|//protected:
comment|//    virtual void processKeyEvent(int keycode, bool isPress, bool autoRepeat);
name|private
operator|:
name|QWSIntKbPrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_KBD_INTEGRITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_KEYBOARD
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKBDINTEGRITY_QWS_H
end_comment
end_unit
