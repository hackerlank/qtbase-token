begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBACKINGSTORE_COCOA_H
end_ifndef
begin_define
DECL|macro|QBACKINGSTORE_COCOA_H
define|#
directive|define
name|QBACKINGSTORE_COCOA_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|"qcocoawindow.h"
end_include
begin_include
include|#
directive|include
file|"qnsview.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|public
operator|:
name|QCocoaBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QCocoaBackingStore
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|void
name|flush
argument_list|(
name|QWindow
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QRegion
operator|&
argument_list|)
block|;
name|bool
name|scroll
argument_list|(
argument|const QRegion&area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|CGImageRef
name|getBackingStoreCGImage
argument_list|()
block|;
name|qreal
name|getBackingStoreDevicePixelRatio
argument_list|()
block|;
name|private
operator|:
name|QImage
name|m_qImage
block|;
name|CGImageRef
name|m_cgImage
block|;
name|QSize
name|m_requestedSize
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
end_unit
