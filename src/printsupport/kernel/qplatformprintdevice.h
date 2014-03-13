begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMPRINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QPLATFORMPRINTDEVICE_H
define|#
directive|define
name|QPLATFORMPRINTDEVICE_H
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
comment|// of internal files.  This header file may change from version to version
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
begin_include
include|#
directive|include
file|<private/qprint_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmimetype.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPlatformPrintDevice
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QPlatformPrintDevice
argument_list|()
block|;
name|explicit
name|QPlatformPrintDevice
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|)
block|;
name|virtual
operator|~
name|QPlatformPrintDevice
argument_list|()
block|;
name|QPlatformPrintDevice
operator|*
name|clone
argument_list|()
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPlatformPrintDevice
operator|&
name|other
operator|)
specifier|const
block|;
name|virtual
name|QString
name|id
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|location
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|makeAndModel
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isDefault
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isRemote
argument_list|()
specifier|const
block|;
name|virtual
name|QPrint
operator|::
name|DeviceState
name|state
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isValidPageLayout
argument_list|(
argument|const QPageLayout&layout
argument_list|,
argument|int resolution
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|supportsMultipleCopies
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|supportsCollateCopies
argument_list|()
specifier|const
block|;
name|virtual
name|QPageSize
name|defaultPageSize
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPageSize
operator|>
name|supportedPageSizes
argument_list|()
specifier|const
block|;
name|virtual
name|QPageSize
name|supportedPageSize
argument_list|(
argument|const QPageSize&pageSize
argument_list|)
specifier|const
block|;
name|virtual
name|QPageSize
name|supportedPageSize
argument_list|(
argument|QPageSize::PageSizeId pageSizeId
argument_list|)
specifier|const
block|;
name|virtual
name|QPageSize
name|supportedPageSize
argument_list|(
argument|const QString&pageName
argument_list|)
specifier|const
block|;
name|virtual
name|QPageSize
name|supportedPageSize
argument_list|(
argument|const QSize&pointSize
argument_list|)
specifier|const
block|;
name|virtual
name|QPageSize
name|supportedPageSize
argument_list|(
argument|const QSizeF&size
argument_list|,
argument|QPageSize::Unit units
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|supportsCustomPageSizes
argument_list|()
specifier|const
block|;
name|virtual
name|QSize
name|minimumPhysicalPageSize
argument_list|()
specifier|const
block|;
name|virtual
name|QSize
name|maximumPhysicalPageSize
argument_list|()
specifier|const
block|;
name|virtual
name|QMarginsF
name|printableMargins
argument_list|(
argument|const QPageSize&pageSize
argument_list|,
argument|QPageLayout::Orientation orientation
argument_list|,
argument|int resolution
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|defaultResolution
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|supportedResolutions
argument_list|()
specifier|const
block|;
name|virtual
name|QPrint
operator|::
name|InputSlot
name|defaultInputSlot
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPrint
operator|::
name|InputSlot
operator|>
name|supportedInputSlots
argument_list|()
specifier|const
block|;
name|virtual
name|QPrint
operator|::
name|OutputBin
name|defaultOutputBin
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPrint
operator|::
name|OutputBin
operator|>
name|supportedOutputBins
argument_list|()
specifier|const
block|;
name|virtual
name|QPrint
operator|::
name|DuplexMode
name|defaultDuplexMode
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPrint
operator|::
name|DuplexMode
operator|>
name|supportedDuplexModes
argument_list|()
specifier|const
block|;
name|virtual
name|QPrint
operator|::
name|ColorMode
name|defaultColorMode
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPrint
operator|::
name|ColorMode
operator|>
name|supportedColorModes
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QMimeType
operator|>
name|supportedMimeTypes
argument_list|()
specifier|const
block|;
specifier|static
name|QPageSize
name|createPageSize
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QString
operator|&
name|localizedName
argument_list|)
block|;
specifier|static
name|QPageSize
name|createPageSize
argument_list|(
argument|int windowsId
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QString&localizedName
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|loadPageSizes
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadResolutions
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadInputSlots
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadOutputBins
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadDuplexModes
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadColorModes
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadMimeTypes
argument_list|()
specifier|const
block|;
name|QPageSize
name|supportedPageSizeMatch
argument_list|(
argument|const QPageSize&pageSize
argument_list|)
specifier|const
block|;
name|QString
name|m_id
block|;
name|QString
name|m_name
block|;
name|QString
name|m_location
block|;
name|QString
name|m_makeAndModel
block|;
name|bool
name|m_isRemote
block|;
name|bool
name|m_supportsMultipleCopies
block|;
name|bool
name|m_supportsCollateCopies
block|;
name|mutable
name|bool
name|m_havePageSizes
block|;
name|mutable
name|QVector
operator|<
name|QPageSize
operator|>
name|m_pageSizes
block|;
name|bool
name|m_supportsCustomPageSizes
block|;
name|QSize
name|m_minimumPhysicalPageSize
block|;
name|QSize
name|m_maximumPhysicalPageSize
block|;
name|mutable
name|bool
name|m_haveResolutions
block|;
name|mutable
name|QVector
operator|<
name|int
operator|>
name|m_resolutions
block|;
name|mutable
name|bool
name|m_haveInputSlots
block|;
name|mutable
name|QVector
operator|<
name|QPrint
operator|::
name|InputSlot
operator|>
name|m_inputSlots
block|;
name|mutable
name|bool
name|m_haveOutputBins
block|;
name|mutable
name|QVector
operator|<
name|QPrint
operator|::
name|OutputBin
operator|>
name|m_outputBins
block|;
name|mutable
name|bool
name|m_haveDuplexModes
block|;
name|mutable
name|QVector
operator|<
name|QPrint
operator|::
name|DuplexMode
operator|>
name|m_duplexModes
block|;
name|mutable
name|bool
name|m_haveColorModes
block|;
name|mutable
name|QVector
operator|<
name|QPrint
operator|::
name|ColorMode
operator|>
name|m_colorModes
block|;
name|mutable
name|bool
name|m_haveMimeTypes
block|;
name|mutable
name|QVector
operator|<
name|QMimeType
operator|>
name|m_mimeTypes
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
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMPRINTDEVICE_H
end_comment
end_unit
