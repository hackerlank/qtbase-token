begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_P_H
define|#
directive|define
name|QPAINTENGINE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPaintEngine
argument_list|)
name|public
label|:
name|QPaintEnginePrivate
argument_list|()
operator|:
name|pdev
argument_list|(
literal|0
argument_list|)
operator|,
name|q_ptr
argument_list|(
literal|0
argument_list|)
operator|,
name|currentClipDevice
argument_list|(
literal|0
argument_list|)
operator|,
name|hasSystemTransform
argument_list|(
literal|0
argument_list|)
operator|,
name|hasSystemViewport
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|QPaintEnginePrivate
argument_list|()
block|{ }
name|QPaintDevice
operator|*
name|pdev
expr_stmt|;
name|QPaintEngine
modifier|*
name|q_ptr
decl_stmt|;
name|QRegion
name|systemClip
decl_stmt|;
name|QRect
name|systemRect
decl_stmt|;
name|QRegion
name|systemViewport
decl_stmt|;
name|QTransform
name|systemTransform
decl_stmt|;
name|QPaintDevice
modifier|*
name|currentClipDevice
decl_stmt|;
name|uint
name|hasSystemTransform
range|:
literal|1
decl_stmt|;
name|uint
name|hasSystemViewport
range|:
literal|1
decl_stmt|;
specifier|inline
name|void
name|transformSystemClip
parameter_list|()
block|{
if|if
condition|(
name|systemClip
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|hasSystemTransform
condition|)
block|{
if|if
condition|(
name|systemTransform
operator|.
name|type
argument_list|()
operator|<=
name|QTransform
operator|::
name|TxTranslate
condition|)
name|systemClip
operator|.
name|translate
argument_list|(
name|qRound
argument_list|(
name|systemTransform
operator|.
name|dx
argument_list|()
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|systemTransform
operator|.
name|dy
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|systemClip
operator|=
name|systemTransform
operator|.
name|map
argument_list|(
name|systemClip
argument_list|)
expr_stmt|;
block|}
comment|// Make sure we're inside the viewport.
if|if
condition|(
name|hasSystemViewport
condition|)
block|{
name|systemClip
operator|&=
name|systemViewport
expr_stmt|;
if|if
condition|(
name|systemClip
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// We don't want to paint without system clip, so set it to 1 pixel :)
name|systemClip
operator|=
name|QRect
argument_list|(
name|systemViewport
operator|.
name|boundingRect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
specifier|inline
name|void
name|setSystemTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|xform
parameter_list|)
block|{
name|systemTransform
operator|=
name|xform
expr_stmt|;
if|if
condition|(
operator|(
name|hasSystemTransform
operator|=
operator|!
name|xform
operator|.
name|isIdentity
argument_list|()
operator|)
operator|||
name|hasSystemViewport
condition|)
name|transformSystemClip
argument_list|()
expr_stmt|;
name|systemStateChanged
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|void
name|setSystemViewport
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|systemViewport
operator|=
name|region
expr_stmt|;
name|hasSystemViewport
operator|=
operator|!
name|systemViewport
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
name|systemStateChanged
parameter_list|()
block|{ }
name|void
name|drawBoxTextItem
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QTextItemInt
modifier|&
name|ti
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_P_H
end_comment
end_unit
