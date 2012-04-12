begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTBUFFER_P_H
end_ifndef
begin_define
DECL|macro|QPAINTBUFFER_P_H
define|#
directive|define
name|QPAINTBUFFER_P_H
end_define
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengineex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qtextengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintBufferPrivate
name|class
name|QPaintBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintBufferPlayback
name|class
name|QPaintBufferPlayback
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPaintBuffer
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPaintBuffer
argument_list|)
name|public
operator|:
name|QPaintBuffer
argument_list|()
block|;
name|QPaintBuffer
argument_list|(
specifier|const
name|QPaintBuffer
operator|&
name|other
argument_list|)
block|;
operator|~
name|QPaintBuffer
argument_list|()
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|void
name|beginNewFrame
argument_list|()
block|;
name|int
name|numFrames
argument_list|()
specifier|const
block|;
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|int frame =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|frameStartIndex
argument_list|(
argument|int frame
argument_list|)
specifier|const
block|;
name|int
name|frameEndIndex
argument_list|(
argument|int frame
argument_list|)
specifier|const
block|;
name|int
name|processCommands
argument_list|(
argument|QPainter *painter
argument_list|,
argument|int begin
argument_list|,
argument|int end
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|QString
name|commandDescription
argument_list|(
argument|int command
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|void
name|setBoundingRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|;
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric m
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|devType
argument_list|()
specifier|const
block|;
name|QPaintBuffer
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPaintBuffer
operator|&
name|other
operator|)
block|;
name|private
operator|:
name|friend
name|class
name|QPainterReplayer
block|;
name|friend
name|class
name|QOpenGLReplayer
block|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
expr|,
specifier|const
name|QPaintBuffer
operator|&
name|buffer
operator|)
block|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
expr|,
name|QPaintBuffer
operator|&
name|buffer
operator|)
block|;
name|QPaintBufferPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|QPaintBuffer
operator|&
name|buffer
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|QPaintBuffer
operator|&
name|buffer
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QPaintBufferEngine
name|class
name|QPaintBufferEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextItemIntCopy
block|{
name|public
label|:
name|QTextItemIntCopy
argument_list|(
specifier|const
name|QTextItem
operator|&
name|item
argument_list|)
expr_stmt|;
operator|~
name|QTextItemIntCopy
argument_list|()
expr_stmt|;
name|QTextItemInt
operator|&
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|m_item
return|;
block|}
name|private
label|:
name|QTextItemInt
name|m_item
decl_stmt|;
name|QFont
name|m_font
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QPaintBufferCommand
struct|struct
name|QPaintBufferCommand
block|{
DECL|member|id
name|uint
name|id
range|:
literal|8
decl_stmt|;
DECL|member|size
name|uint
name|size
range|:
literal|24
decl_stmt|;
DECL|member|offset
name|int
name|offset
decl_stmt|;
DECL|member|offset2
name|int
name|offset2
decl_stmt|;
DECL|member|extra
name|int
name|extra
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|QPaintBufferCommand
operator|&
name|command
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|QPaintBufferCommand
operator|&
name|command
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPaintBufferCommand
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QPaintBufferPrivate
block|{
name|public
label|:
enum|enum
name|Command
block|{
name|Cmd_Save
block|,
name|Cmd_Restore
block|,
name|Cmd_SetBrush
block|,
name|Cmd_SetBrushOrigin
block|,
name|Cmd_SetClipEnabled
block|,
name|Cmd_SetCompositionMode
block|,
name|Cmd_SetOpacity
block|,
name|Cmd_SetPen
block|,
name|Cmd_SetRenderHints
block|,
name|Cmd_SetTransform
block|,
name|Cmd_SetBackgroundMode
block|,
name|Cmd_ClipPath
block|,
name|Cmd_ClipRect
block|,
name|Cmd_ClipRegion
block|,
name|Cmd_ClipVectorPath
block|,
name|Cmd_DrawVectorPath
block|,
name|Cmd_FillVectorPath
block|,
name|Cmd_StrokeVectorPath
block|,
name|Cmd_DrawConvexPolygonF
block|,
name|Cmd_DrawConvexPolygonI
block|,
name|Cmd_DrawEllipseF
block|,
name|Cmd_DrawEllipseI
block|,
name|Cmd_DrawLineF
block|,
name|Cmd_DrawLineI
block|,
name|Cmd_DrawPath
block|,
name|Cmd_DrawPointsF
block|,
name|Cmd_DrawPointsI
block|,
name|Cmd_DrawPolygonF
block|,
name|Cmd_DrawPolygonI
block|,
name|Cmd_DrawPolylineF
block|,
name|Cmd_DrawPolylineI
block|,
name|Cmd_DrawRectF
block|,
name|Cmd_DrawRectI
block|,
name|Cmd_FillRectBrush
block|,
name|Cmd_FillRectColor
block|,
name|Cmd_DrawText
block|,
name|Cmd_DrawTextItem
block|,
name|Cmd_DrawImagePos
block|,
name|Cmd_DrawImageRect
block|,
name|Cmd_DrawPixmapPos
block|,
name|Cmd_DrawPixmapRect
block|,
name|Cmd_DrawTiledPixmap
block|,
name|Cmd_SystemStateChanged
block|,
name|Cmd_Translate
block|,
name|Cmd_DrawStaticText
block|,
comment|// new commands must be added above this line
name|Cmd_LastCommand
block|}
enum|;
name|QPaintBufferPrivate
argument_list|()
expr_stmt|;
operator|~
name|QPaintBufferPrivate
argument_list|()
expr_stmt|;
name|int
name|addData
parameter_list|(
specifier|const
name|int
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
return|return
literal|0
return|;
name|int
name|pos
init|=
name|ints
operator|.
name|size
argument_list|()
decl_stmt|;
name|ints
operator|.
name|resize
argument_list|(
name|pos
operator|+
name|count
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|ints
operator|.
name|data
argument_list|()
operator|+
name|pos
argument_list|,
name|data
argument_list|,
name|count
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|pos
return|;
block|}
name|int
name|addData
parameter_list|(
specifier|const
name|qreal
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
return|return
literal|0
return|;
name|int
name|pos
init|=
name|floats
operator|.
name|size
argument_list|()
decl_stmt|;
name|floats
operator|.
name|resize
argument_list|(
name|pos
operator|+
name|count
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|floats
operator|.
name|data
argument_list|()
operator|+
name|pos
argument_list|,
name|data
argument_list|,
name|count
operator|*
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|pos
return|;
block|}
name|int
name|addData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|var
parameter_list|)
block|{
name|variants
operator|<<
name|var
expr_stmt|;
return|return
name|variants
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
name|QPaintBufferCommand
modifier|*
name|addCommand
parameter_list|(
name|Command
name|command
parameter_list|)
block|{
name|QPaintBufferCommand
name|cmd
decl_stmt|;
name|cmd
operator|.
name|id
operator|=
name|command
expr_stmt|;
name|cmd
operator|.
name|size
operator|=
name|cmd
operator|.
name|offset
operator|=
name|cmd
operator|.
name|offset2
operator|=
name|cmd
operator|.
name|extra
operator|=
literal|0
expr_stmt|;
name|commands
operator|<<
name|cmd
expr_stmt|;
return|return
operator|&
name|commands
operator|.
name|last
argument_list|()
return|;
block|}
name|QPaintBufferCommand
modifier|*
name|addCommand
parameter_list|(
name|Command
name|command
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|var
parameter_list|)
block|{
name|QPaintBufferCommand
name|cmd
decl_stmt|;
name|cmd
operator|.
name|id
operator|=
name|command
expr_stmt|;
name|cmd
operator|.
name|offset
operator|=
name|addData
argument_list|(
name|var
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|size
operator|=
name|cmd
operator|.
name|offset2
operator|=
name|cmd
operator|.
name|extra
operator|=
literal|0
expr_stmt|;
name|commands
operator|<<
name|cmd
expr_stmt|;
return|return
operator|&
name|commands
operator|.
name|last
argument_list|()
return|;
block|}
name|QPaintBufferCommand
modifier|*
name|addCommand
parameter_list|(
name|Command
name|command
parameter_list|,
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|)
block|{
name|QPaintBufferCommand
name|cmd
decl_stmt|;
name|cmd
operator|.
name|id
operator|=
name|command
expr_stmt|;
name|cmd
operator|.
name|offset
operator|=
name|addData
argument_list|(
name|path
operator|.
name|points
argument_list|()
argument_list|,
name|path
operator|.
name|elementCount
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|offset2
operator|=
name|ints
operator|.
name|size
argument_list|()
expr_stmt|;
name|ints
operator|<<
name|path
operator|.
name|hints
argument_list|()
expr_stmt|;
comment|// The absence of path elements is indicated by setting the highest bit in 'cmd.offset2'.
if|if
condition|(
name|path
operator|.
name|elements
argument_list|()
condition|)
name|addData
argument_list|(
operator|(
specifier|const
name|int
operator|*
operator|)
name|path
operator|.
name|elements
argument_list|()
argument_list|,
name|path
operator|.
name|elementCount
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|cmd
operator|.
name|offset2
operator||=
literal|0x80000000
expr_stmt|;
name|cmd
operator|.
name|size
operator|=
name|path
operator|.
name|elementCount
argument_list|()
expr_stmt|;
name|cmd
operator|.
name|extra
operator|=
literal|0
expr_stmt|;
name|commands
operator|<<
name|cmd
expr_stmt|;
return|return
operator|&
name|commands
operator|.
name|last
argument_list|()
return|;
block|}
name|QPaintBufferCommand
modifier|*
name|addCommand
parameter_list|(
name|Command
name|command
parameter_list|,
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|,
name|int
name|arrayLength
parameter_list|,
name|int
name|elementCount
parameter_list|)
block|{
name|QPaintBufferCommand
name|cmd
decl_stmt|;
name|cmd
operator|.
name|id
operator|=
name|command
expr_stmt|;
name|cmd
operator|.
name|offset
operator|=
name|addData
argument_list|(
name|pts
argument_list|,
name|arrayLength
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|size
operator|=
name|elementCount
expr_stmt|;
name|cmd
operator|.
name|offset2
operator|=
name|cmd
operator|.
name|extra
operator|=
literal|0
expr_stmt|;
name|commands
operator|<<
name|cmd
expr_stmt|;
return|return
operator|&
name|commands
operator|.
name|last
argument_list|()
return|;
block|}
name|QPaintBufferCommand
modifier|*
name|addCommand
parameter_list|(
name|Command
name|command
parameter_list|,
specifier|const
name|int
modifier|*
name|pts
parameter_list|,
name|int
name|arrayLength
parameter_list|,
name|int
name|elementCount
parameter_list|)
block|{
name|QPaintBufferCommand
name|cmd
decl_stmt|;
name|cmd
operator|.
name|id
operator|=
name|command
expr_stmt|;
name|cmd
operator|.
name|offset
operator|=
name|addData
argument_list|(
name|pts
argument_list|,
name|arrayLength
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|size
operator|=
name|elementCount
expr_stmt|;
name|cmd
operator|.
name|offset2
operator|=
name|cmd
operator|.
name|extra
operator|=
literal|0
expr_stmt|;
name|commands
operator|<<
name|cmd
expr_stmt|;
return|return
operator|&
name|commands
operator|.
name|last
argument_list|()
return|;
block|}
specifier|inline
name|void
name|updateBoundingRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|ints
expr_stmt|;
name|QVector
operator|<
name|qreal
operator|>
name|floats
expr_stmt|;
name|QVector
operator|<
name|QVariant
operator|>
name|variants
expr_stmt|;
name|QVector
operator|<
name|QPaintBufferCommand
operator|>
name|commands
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|frames
expr_stmt|;
name|QPaintBufferEngine
modifier|*
name|engine
decl_stmt|;
name|QRectF
name|boundingRect
decl_stmt|;
name|qreal
name|penWidthAdjustment
decl_stmt|;
name|uint
name|calculateBoundingRect
range|:
literal|1
decl_stmt|;
name|void
modifier|*
name|cache
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QVectorPathCmd
struct|struct
name|QVectorPathCmd
block|{
comment|// The absence of path elements is indicated by setting the highest bit in 'cmd.offset2'.
DECL|function|QVectorPathCmd
name|QVectorPathCmd
argument_list|(
name|QPaintBufferPrivate
operator|*
name|d
argument_list|,
specifier|const
name|QPaintBufferCommand
operator|&
name|cmd
argument_list|)
operator|:
name|vectorPath
argument_list|(
argument|d->floats.constData() + cmd.offset
argument_list|,
argument|cmd.size
argument_list|,
argument|cmd.offset2&
literal|0x80000000
argument|?
literal|0
argument|: (const QPainterPath::ElementType *) (d->ints.constData() + cmd.offset2 +
literal|1
argument|)
argument_list|,
argument|*(d->ints.constData() + (cmd.offset2&
literal|0x7fffffff
argument|))
argument_list|)
block|{}
DECL|function|operator
specifier|inline
specifier|const
name|QVectorPath
operator|&
name|operator
argument_list|()
operator|(
operator|)
specifier|const
block|{
return|return
name|vectorPath
return|;
block|}
DECL|member|vectorPath
name|QVectorPath
name|vectorPath
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPainterReplayer
block|{
name|public
label|:
name|QPainterReplayer
argument_list|()
block|{ }
name|virtual
operator|~
name|QPainterReplayer
argument_list|()
block|{ }
name|void
name|setupTransform
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
expr_stmt|;
name|virtual
name|void
name|process
parameter_list|(
specifier|const
name|QPaintBufferCommand
modifier|&
name|cmd
parameter_list|)
function_decl|;
name|void
name|processCommands
parameter_list|(
specifier|const
name|QPaintBuffer
modifier|&
name|buffer
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
name|protected
label|:
name|QPaintBufferPrivate
modifier|*
name|d
decl_stmt|;
name|QTransform
name|m_world_matrix
decl_stmt|;
name|QPainter
modifier|*
name|painter
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPaintEngineExReplayer
range|:
name|public
name|QPainterReplayer
block|{
name|public
operator|:
name|QPaintEngineExReplayer
argument_list|()
block|{ }
name|virtual
name|void
name|process
argument_list|(
specifier|const
name|QPaintBufferCommand
operator|&
name|cmd
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintBufferEnginePrivate
name|class
name|QPaintBufferEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPaintBufferEngine
range|:
name|public
name|QPaintEngineEx
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPaintBufferEngine
argument_list|)
name|public
operator|:
name|QPaintBufferEngine
argument_list|(
name|QPaintBufferPrivate
operator|*
name|buffer
argument_list|)
block|;
name|virtual
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
name|virtual
name|bool
name|end
argument_list|()
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngine
operator|::
name|PaintBuffer
return|;
block|}
name|virtual
name|QPainterState
operator|*
name|createState
argument_list|(
argument|QPainterState *orig
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|)
block|;
name|virtual
name|void
name|fill
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|virtual
name|void
name|stroke
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QRect&rect
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QRegion&region
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|clip
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|virtual
name|void
name|clipEnabledChanged
argument_list|()
block|;
name|virtual
name|void
name|penChanged
argument_list|()
block|;
name|virtual
name|void
name|brushChanged
argument_list|()
block|;
name|virtual
name|void
name|brushOriginChanged
argument_list|()
block|;
name|virtual
name|void
name|opacityChanged
argument_list|()
block|;
name|virtual
name|void
name|compositionModeChanged
argument_list|()
block|;
name|virtual
name|void
name|renderHintsChanged
argument_list|()
block|;
name|virtual
name|void
name|transformChanged
argument_list|()
block|;
name|virtual
name|void
name|backgroundModeChanged
argument_list|()
block|;
name|virtual
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
block|;
name|virtual
name|void
name|fillRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|virtual
name|void
name|drawRects
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|virtual
name|void
name|drawRects
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|virtual
name|void
name|drawLines
argument_list|(
argument|const QLine *lines
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|virtual
name|void
name|drawLines
argument_list|(
argument|const QLineF *lines
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|virtual
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|)
block|;
name|virtual
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|virtual
name|void
name|drawPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
name|virtual
name|void
name|drawPoints
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|virtual
name|void
name|drawPoints
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|virtual
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|;
name|virtual
name|void
name|drawPolygon
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|)
block|;
name|virtual
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&pm
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|virtual
name|void
name|drawImage
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|virtual
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPointF
operator|&
name|s
argument_list|)
block|;
name|virtual
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QTextItem
operator|&
name|ti
argument_list|)
block|;
name|virtual
name|void
name|drawStaticTextItem
argument_list|(
name|QStaticTextItem
operator|*
name|staticTextItem
argument_list|)
block|;
name|virtual
name|void
name|setState
argument_list|(
name|QPainterState
operator|*
name|s
argument_list|)
block|;
name|virtual
name|uint
name|flags
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngineEx
operator|::
name|DoNotEmulate
return|;
block|}
name|QPaintBufferPrivate
operator|*
name|buffer
block|;
name|mutable
name|int
name|m_begin_detected
operator|:
literal|1
block|;
name|mutable
name|int
name|m_save_detected
operator|:
literal|1
block|;
name|mutable
name|int
name|m_stream_raw_text_items
operator|:
literal|1
block|;
name|mutable
name|int
name|m_unused
operator|:
literal|29
block|;
name|mutable
name|QPainterState
operator|*
name|m_created_state
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTBUFFER_P_H
end_comment
end_unit
