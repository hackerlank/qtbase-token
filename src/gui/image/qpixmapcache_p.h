begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPCACHE_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAPCACHE_P_H
define|#
directive|define
name|QPIXMAPCACHE_P_H
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
comment|// This file is not part of the Qt API. This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qpixmapcache.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|"qcache.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|uint
name|qHash
argument_list|(
specifier|const
name|QPixmapCache
operator|::
name|Key
operator|&
name|k
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|class
name|QPixmapCache
operator|::
name|KeyData
block|{
name|public
operator|:
name|KeyData
argument_list|()
operator|:
name|isValid
argument_list|(
name|true
argument_list|)
block|,
name|key
argument_list|(
literal|0
argument_list|)
block|,
name|ref
argument_list|(
literal|1
argument_list|)
block|{}
name|KeyData
argument_list|(
specifier|const
name|KeyData
operator|&
name|other
argument_list|)
operator|:
name|isValid
argument_list|(
name|other
operator|.
name|isValid
argument_list|)
block|,
name|key
argument_list|(
name|other
operator|.
name|key
argument_list|)
block|,
name|ref
argument_list|(
literal|1
argument_list|)
block|{}
operator|~
name|KeyData
argument_list|()
block|{}
name|bool
name|isValid
block|;
name|int
name|key
block|;
name|int
name|ref
block|; }
expr_stmt|;
end_expr_stmt
begin_comment
comment|// XXX: hw: is this a general concept we need to abstract?
end_comment
begin_decl_stmt
name|class
name|QPixmapCacheEntry
range|:
name|public
name|QPixmap
block|{
name|public
operator|:
name|QPixmapCacheEntry
argument_list|(
specifier|const
name|QPixmapCache
operator|::
name|Key
operator|&
name|key
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pix
argument_list|)
operator|:
name|QPixmap
argument_list|(
name|pix
argument_list|)
block|,
name|key
argument_list|(
argument|key
argument_list|)
block|{
name|QPlatformPixmap
operator|*
name|pd
operator|=
name|handle
argument_list|()
block|;
if|if
condition|(
name|pd
operator|&&
name|pd
operator|->
name|classId
argument_list|()
operator|==
name|QPlatformPixmap
operator|::
name|RasterClass
condition|)
block|{
name|QRasterPlatformPixmap
modifier|*
name|d
init|=
name|static_cast
operator|<
name|QRasterPlatformPixmap
operator|*
operator|>
operator|(
name|pd
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|image
operator|.
name|isNull
argument_list|()
operator|&&
name|d
operator|->
name|image
operator|.
name|d
operator|->
name|paintEngine
operator|&&
operator|!
name|d
operator|->
name|image
operator|.
name|d
operator|->
name|paintEngine
operator|->
name|isActive
argument_list|()
condition|)
block|{
name|delete
name|d
operator|->
name|image
operator|.
name|d
operator|->
name|paintEngine
decl_stmt|;
name|d
operator|->
name|image
operator|.
name|d
operator|->
name|paintEngine
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
operator|~
name|QPixmapCacheEntry
argument_list|()
block|;
name|QPixmapCache
operator|::
name|Key
name|key
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
comment|// QPIXMAPCACHE_P_H
end_comment
end_unit
