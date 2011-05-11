begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|RECTBUTTON_H
end_ifndef
begin_define
DECL|macro|RECTBUTTON_H
define|#
directive|define
name|RECTBUTTON_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsObject>
end_include
begin_decl_stmt
name|class
name|RectButton
range|:
name|public
name|QGraphicsObject
block|{
name|Q_OBJECT
name|public
operator|:
name|RectButton
argument_list|(
argument|QString buttonText
argument_list|)
block|;
operator|~
name|RectButton
argument_list|()
block|;
name|virtual
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOptionGraphicsItem
operator|*
name|option
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|protected
operator|:
name|QString
name|m_ButtonText
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|signals
operator|:
name|void
name|clicked
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RECTBUTTON_H
end_comment
end_unit
