begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNSVIEW_H
end_ifndef
begin_define
DECL|macro|QNSVIEW_H
define|#
directive|define
name|QNSVIEW_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_decl_stmt
unit|@
name|interface
name|QNSView
range|:
name|NSView
block|{
name|CGImageRef
name|m_cgImage
block|;
name|QWidget
operator|*
name|m_widget
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|; }
operator|-
operator|(
name|id
operator|)
name|init
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithWidget
operator|:
operator|(
name|QWidget
operator|*
operator|)
name|widget
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setImage
operator|:
operator|(
name|QImage
operator|*
operator|)
name|image
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drawRect
operator|:
operator|(
name|NSRect
operator|)
name|dirtyRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isFlipped
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleMouseEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseMoved
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseEntered
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseExited
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QNSVIEW_H
end_comment
end_unit
