begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBBLITTER_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBBLITTER_H
define|#
directive|define
name|QDIRECTFBBLITTER_H
end_define
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|<private/qblittable_p.h>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_decl_stmt
name|class
name|QDirectFbBlitter
range|:
name|public
name|QBlittable
block|{
name|public
operator|:
name|QDirectFbBlitter
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|IDirectFBSurface
operator|*
name|surface
argument_list|)
block|;
name|QDirectFbBlitter
argument_list|(
argument|const QSize&size
argument_list|,
argument|bool alpha
argument_list|)
block|;
name|virtual
operator|~
name|QDirectFbBlitter
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
name|QColor
operator|&
name|color
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QRectF
operator|&
name|subrect
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|QImage
operator|*
name|doLock
argument_list|()
block|;
name|virtual
name|void
name|doUnlock
argument_list|()
block|;
name|QDirectFBPointer
operator|<
name|IDirectFBSurface
operator|>
name|m_surface
block|;
name|QImage
name|m_image
block|;
name|friend
name|class
name|QDirectFbConvenience
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDirectFbBlitterPlatformPixmap
range|:
name|public
name|QBlittablePlatformPixmap
block|{
name|public
operator|:
name|QBlittable
operator|*
name|createBlittable
argument_list|(
argument|const QSize&size
argument_list|,
argument|bool alpha
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|createBlittable
specifier|inline
name|QBlittable
operator|*
name|QDirectFbBlitterPlatformPixmap
operator|::
name|createBlittable
argument_list|(
argument|const QSize& size
argument_list|,
argument|bool alpha
argument_list|)
specifier|const
block|{
return|return
name|new
name|QDirectFbBlitter
argument_list|(
name|size
argument_list|,
name|alpha
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRECTFBBLITTER_H
end_comment
end_unit
