begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp, qcolor_x11.cpp, qfiledialog.cpp
end_comment
begin_comment
comment|// and many other.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Private AppKit class (dumped from classdump).
end_comment
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_empty
empty|#import "qnsframeview_mac_p.h"
end_empty
begin_decl_stmt
unit|@
name|interface
name|NSTitledFrame
range|:
name|NSFrameView
block|{
name|int
name|resizeFlags
block|;
name|id
name|fileButton
block|;
comment|/* NSDocumentDragButton* */
name|NSSize
name|titleCellSize
block|; }
operator|+
operator|(
name|float
operator|)
name|_windowBorderThickness
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_minXWindowBorderWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_maxXWindowBorderWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_minYWindowBorderHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|_resizeFromEdge
operator|+
operator|(
name|char
operator|)
name|_resizeFromEdge
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|NSRect
operator|)
name|frameRectForContentRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp24
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|fp24
operator|+
operator|(
name|NSRect
operator|)
name|contentRectForFrameRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp24
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
expr|struct
name|_NSSize
operator|)
name|minFrameSizeForMinContentSize
operator|:
operator|(
expr|struct
name|_NSSize
operator|)
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp16
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
expr|struct
name|_NSSize
operator|)
name|minContentSizeForMinFrameSize
operator|:
operator|(
expr|struct
name|_NSSize
operator|)
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp16
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|minFrameWidthWithTitle
operator|:
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
expr|struct
name|_NSSize
operator|)
name|_titleCellSizeForTitle
operator|:
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_titleCellHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_windowTitlebarTitleMinHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_titlebarHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
expr|struct
name|_NSSize
operator|)
name|sizeOfTitlebarButtons
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|windowTitlebarLinesSpacingWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|windowTitlebarTitleLinesSpacingWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_contentToFrameMinXWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_contentToFrameMaxXWidth
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_contentToFrameMinYHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|float
operator|)
name|_contentToFrameMaxYHeight
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|initWithFrame
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|styleMask
operator|:
operator|(
name|unsigned
name|int
operator|)
name|fp24
name|owner
operator|:
name|fp28
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|dealloc
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setIsClosable
operator|:
operator|(
name|char
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setIsResizable
operator|:
operator|(
name|char
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_resetTitleFont
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_setUtilityWindow
operator|:
operator|(
name|char
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|isOpaque
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|worksWhenModal
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|propagateFrameDirtyRects
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_showDrawRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawFrameInterior
operator|:
operator|(
name|NSRect
operator|*
operator|)
name|fp8
name|clip
operator|:
operator|(
name|NSRect
operator|)
name|fp12
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drawFrame
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawFrameRects
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawTitlebar
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawTitlebarPattern
operator|:
operator|(
name|int
operator|)
name|fp8
name|inRect
operator|:
operator|(
name|NSRect
operator|)
name|fp12
name|clippedByRect
operator|:
operator|(
name|NSRect
operator|)
name|fp28
name|forKey
operator|:
operator|(
name|char
operator|)
name|fp44
name|alignment
operator|:
operator|(
name|int
operator|)
name|fp48
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawTitlebarLines
operator|:
operator|(
name|int
operator|)
name|fp8
name|inRect
operator|:
operator|(
name|NSRect
operator|)
name|fp12
name|clippedByRect
operator|:
operator|(
name|NSRect
operator|)
name|fp28
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|frameHighlightColor
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|frameShadowColor
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setFrameSize
operator|:
operator|(
expr|struct
name|_NSSize
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setFrameOrigin
operator|:
operator|(
expr|struct
name|_NSPoint
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|tileAndSetWindowShape
operator|:
operator|(
name|char
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|tile
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_tileTitlebar
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setTitle
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|_shouldRepresentFilename
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setRepresentedFilename
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawTitleStringIn
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|withColor
operator|:
name|fp24
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|titleFont
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_drawResizeIndicators
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|titleButtonOfClass
operator|:
operator|(
name|Class
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|initTitleButton
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|newCloseButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|newZoomButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|newMiniaturizeButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|newFileButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
name|fileButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_removeButtons
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_updateButtons
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|_eventInTitlebar
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|acceptsFirstMouse
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDown
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseUp
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDown
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseUp
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|resizeEdgeForEvent
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|fp16
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|_resizeDeltaFromPoint
operator|:
operator|(
expr|struct
name|_NSPoint
operator|)
name|fp8
name|toEvent
operator|:
name|fp16
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_validFrameForResizeFrame
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|fromResizeEdge
operator|:
operator|(
name|int
operator|)
name|fp24
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|frame
operator|:
operator|(
name|NSRect
operator|)
name|fp8
name|resizedFromEdge
operator|:
operator|(
name|int
operator|)
name|fp24
name|withDelta
operator|:
operator|(
expr|struct
name|_NSSize
operator|)
name|fp28
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|char
operator|)
name|constrainResizeEdge
operator|:
operator|(
name|int
operator|*
operator|)
name|fp8
name|withDelta
operator|:
operator|(
expr|struct
name|_NSSize
operator|)
name|fp12
name|elapsedTime
operator|:
operator|(
name|float
operator|)
name|fp20
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|resizeWithEvent
operator|:
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|resizeFlags
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|resetCursorRects
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setDocumentEdited
operator|:
operator|(
name|char
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|miniaturizedSize
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|minFrameSize
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowBorderThickness
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowTitlebarXResizeBorderThickness
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowTitlebarYResizeBorderThickness
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowResizeBorderThickness
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minXWindowBorderWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_maxXWindowBorderWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minYWindowBorderHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_invalidateTitleCellSize
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|_invalidateTitleCellWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_titleCellHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|_titleCellSize
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_titlebarHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|titlebarRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxTitlebarTitleRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_titlebarTitleRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowTitlebarTitleMinHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|dragRectForFrameRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|sizeOfTitlebarButtons
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSSize
operator|)
name|_sizeOfTitlebarFileButton
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowTitlebarButtonSpacingWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minXTitlebarButtonsWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_maxXTitlebarButtonsWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|_numberOfTitlebarLines
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|windowTitlebarLinesSpacingWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|windowTitlebarTitleLinesSpacingWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minLinesWidthWithSpace
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXTitlebarLinesRectWithTitleCellRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXTitlebarLinesRectWithTitleCellRect
operator|:
operator|(
name|NSRect
operator|)
name|fp8
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minXTitlebarDecorationMinWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_maxXTitlebarDecorationMinWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSPoint
operator|)
name|_closeButtonOrigin
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSPoint
operator|)
name|_zoomButtonOrigin
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSPoint
operator|)
name|_collapseButtonOrigin
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
expr|struct
name|_NSPoint
operator|)
name|_fileButtonOrigin
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_maxYTitlebarDragHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_minXTitlebarDragWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_maxXTitlebarDragWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_contentToFrameMinXWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_contentToFrameMaxXWidth
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_contentToFrameMinYHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_contentToFrameMaxYHeight
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|contentRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|float
operator|)
name|_windowResizeCornerThickness
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minYminXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minYmaxXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXminYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXmaxYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxYminXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxYmaxXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXminYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXmaxYResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXTitlebarResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXTitlebarResizeRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minXBorderRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxXBorderRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_maxYBorderRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSRect
operator|)
name|_minYBorderRect
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
end_unit
