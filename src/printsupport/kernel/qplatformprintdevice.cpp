begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformprintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qprintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|"qprintdialog.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpagelayout.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_constructor
DECL|function|QPlatformPrintDevice
name|QPlatformPrintDevice
operator|::
name|QPlatformPrintDevice
parameter_list|()
member_init_list|:
name|m_isRemote
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsMultipleCopies
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsCollateCopies
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_havePageSizes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsCustomPageSizes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveResolutions
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveInputSlots
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveOutputBins
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveDuplexModes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveColorModes
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QPlatformPrintDevice
name|QPlatformPrintDevice
operator|::
name|QPlatformPrintDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
member_init_list|:
name|m_id
argument_list|(
name|id
argument_list|)
member_init_list|,
name|m_isRemote
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsMultipleCopies
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsCollateCopies
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_havePageSizes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_supportsCustomPageSizes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveResolutions
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveInputSlots
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveOutputBins
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveDuplexModes
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_haveColorModes
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformPrintDevice
name|QPlatformPrintDevice
operator|::
name|~
name|QPlatformPrintDevice
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|id
name|QString
name|QPlatformPrintDevice
operator|::
name|id
parameter_list|()
specifier|const
block|{
return|return
name|m_id
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QPlatformPrintDevice
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
end_function
begin_function
DECL|function|location
name|QString
name|QPlatformPrintDevice
operator|::
name|location
parameter_list|()
specifier|const
block|{
return|return
name|m_location
return|;
block|}
end_function
begin_function
DECL|function|makeAndModel
name|QString
name|QPlatformPrintDevice
operator|::
name|makeAndModel
parameter_list|()
specifier|const
block|{
return|return
name|m_makeAndModel
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QPlatformPrintDevice
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isDefault
name|bool
name|QPlatformPrintDevice
operator|::
name|isDefault
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isRemote
name|bool
name|QPlatformPrintDevice
operator|::
name|isRemote
parameter_list|()
specifier|const
block|{
return|return
name|m_isRemote
return|;
block|}
end_function
begin_function
DECL|function|isValidPageLayout
name|bool
name|QPlatformPrintDevice
operator|::
name|isValidPageLayout
parameter_list|(
specifier|const
name|QPageLayout
modifier|&
name|layout
parameter_list|,
name|int
name|resolution
parameter_list|)
specifier|const
block|{
comment|// Check the page size is supported
if|if
condition|(
operator|!
name|supportedPageSize
argument_list|(
name|layout
operator|.
name|pageSize
argument_list|()
argument_list|)
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// Check the margins are valid
name|QMarginsF
name|pointMargins
init|=
name|layout
operator|.
name|margins
argument_list|(
name|QPageLayout
operator|::
name|Point
argument_list|)
decl_stmt|;
name|QMarginsF
name|printMargins
init|=
name|printableMargins
argument_list|(
name|layout
operator|.
name|pageSize
argument_list|()
argument_list|,
name|layout
operator|.
name|orientation
argument_list|()
argument_list|,
name|resolution
argument_list|)
decl_stmt|;
return|return
name|pointMargins
operator|.
name|left
argument_list|()
operator|>=
name|printMargins
operator|.
name|left
argument_list|()
operator|&&
name|pointMargins
operator|.
name|right
argument_list|()
operator|>=
name|printMargins
operator|.
name|right
argument_list|()
operator|&&
name|pointMargins
operator|.
name|top
argument_list|()
operator|>=
name|printMargins
operator|.
name|top
argument_list|()
operator|&&
name|pointMargins
operator|.
name|bottom
argument_list|()
operator|>=
name|printMargins
operator|.
name|bottom
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|state
name|QPrint
operator|::
name|DeviceState
name|QPlatformPrintDevice
operator|::
name|state
parameter_list|()
specifier|const
block|{
return|return
name|QPrint
operator|::
name|Error
return|;
block|}
end_function
begin_function
DECL|function|supportsMultipleCopies
name|bool
name|QPlatformPrintDevice
operator|::
name|supportsMultipleCopies
parameter_list|()
specifier|const
block|{
return|return
name|m_supportsMultipleCopies
return|;
block|}
end_function
begin_function
DECL|function|supportsCollateCopies
name|bool
name|QPlatformPrintDevice
operator|::
name|supportsCollateCopies
parameter_list|()
specifier|const
block|{
return|return
name|m_supportsCollateCopies
return|;
block|}
end_function
begin_function
DECL|function|loadPageSizes
name|void
name|QPlatformPrintDevice
operator|::
name|loadPageSizes
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|defaultPageSize
parameter_list|()
specifier|const
block|{
return|return
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSizes
name|QList
argument_list|<
name|QPageSize
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedPageSizes
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
return|return
name|m_pageSizes
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|pageSize
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QPageSize
argument_list|()
return|;
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
comment|// First try match on name and id for case where printer defines same size twice with different names
comment|// e.g. Windows defines DMPAPER_11X17 and DMPAPER_TABLOID with names "11x17" and "Tabloid", but both
comment|// map to QPageSize::Tabloid / PPD Key "Tabloid" / ANSI B Tabloid
if|if
condition|(
name|pageSize
operator|.
name|id
argument_list|()
operator|!=
name|QPageSize
operator|::
name|Custom
condition|)
block|{
for|for
control|(
specifier|const
name|QPageSize
modifier|&
name|ps
range|:
name|m_pageSizes
control|)
block|{
if|if
condition|(
name|ps
operator|.
name|id
argument_list|()
operator|==
name|pageSize
operator|.
name|id
argument_list|()
operator|&&
name|ps
operator|.
name|name
argument_list|()
operator|==
name|pageSize
operator|.
name|name
argument_list|()
condition|)
return|return
name|ps
return|;
block|}
block|}
comment|// Next try match on id only if not custom
if|if
condition|(
name|pageSize
operator|.
name|id
argument_list|()
operator|!=
name|QPageSize
operator|::
name|Custom
condition|)
block|{
for|for
control|(
specifier|const
name|QPageSize
modifier|&
name|ps
range|:
name|m_pageSizes
control|)
block|{
if|if
condition|(
name|ps
operator|.
name|id
argument_list|()
operator|==
name|pageSize
operator|.
name|id
argument_list|()
condition|)
return|return
name|ps
return|;
block|}
block|}
comment|// Next try a match on size, in case it's a custom with a different name
return|return
name|supportedPageSizeMatch
argument_list|(
name|pageSize
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
name|QPageSize
operator|::
name|PageSizeId
name|pageSizeId
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
for|for
control|(
specifier|const
name|QPageSize
modifier|&
name|ps
range|:
name|m_pageSizes
control|)
block|{
if|if
condition|(
name|ps
operator|.
name|id
argument_list|()
operator|==
name|pageSizeId
condition|)
return|return
name|ps
return|;
block|}
comment|// If no supported page size found, try use a custom size instead if supported
return|return
name|supportedPageSizeMatch
argument_list|(
name|QPageSize
argument_list|(
name|pageSizeId
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QString
modifier|&
name|pageName
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
for|for
control|(
specifier|const
name|QPageSize
modifier|&
name|ps
range|:
name|m_pageSizes
control|)
block|{
if|if
condition|(
name|ps
operator|.
name|name
argument_list|()
operator|==
name|pageName
condition|)
return|return
name|ps
return|;
block|}
return|return
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sizePoints
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
comment|// Try to find a supported page size based on fuzzy-matched point size
return|return
name|supportedPageSizeMatch
argument_list|(
name|QPageSize
argument_list|(
name|sizePoints
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|,
name|QPageSize
operator|::
name|Unit
name|units
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_havePageSizes
condition|)
name|loadPageSizes
argument_list|()
expr_stmt|;
comment|// Try to find a supported page size based on fuzzy-matched unit size
return|return
name|supportedPageSizeMatch
argument_list|(
name|QPageSize
argument_list|(
name|size
argument_list|,
name|units
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportedPageSizeMatch
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|supportedPageSizeMatch
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
specifier|const
block|{
comment|// Try to find a supported page size based on point size
for|for
control|(
specifier|const
name|QPageSize
modifier|&
name|ps
range|:
name|m_pageSizes
control|)
block|{
if|if
condition|(
name|ps
operator|.
name|sizePoints
argument_list|()
operator|==
name|pageSize
operator|.
name|sizePoints
argument_list|()
condition|)
return|return
name|ps
return|;
block|}
return|return
name|QPageSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|supportsCustomPageSizes
name|bool
name|QPlatformPrintDevice
operator|::
name|supportsCustomPageSizes
parameter_list|()
specifier|const
block|{
return|return
name|m_supportsCustomPageSizes
return|;
block|}
end_function
begin_function
DECL|function|minimumPhysicalPageSize
name|QSize
name|QPlatformPrintDevice
operator|::
name|minimumPhysicalPageSize
parameter_list|()
specifier|const
block|{
return|return
name|m_minimumPhysicalPageSize
return|;
block|}
end_function
begin_function
DECL|function|maximumPhysicalPageSize
name|QSize
name|QPlatformPrintDevice
operator|::
name|maximumPhysicalPageSize
parameter_list|()
specifier|const
block|{
return|return
name|m_maximumPhysicalPageSize
return|;
block|}
end_function
begin_function
DECL|function|printableMargins
name|QMarginsF
name|QPlatformPrintDevice
operator|::
name|printableMargins
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|,
name|QPageLayout
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|resolution
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|pageSize
argument_list|)
name|Q_UNUSED
argument_list|(
argument|orientation
argument_list|)
name|Q_UNUSED
argument_list|(
argument|resolution
argument_list|)
return|return
name|QMarginsF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|loadResolutions
name|void
name|QPlatformPrintDevice
operator|::
name|loadResolutions
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultResolution
name|int
name|QPlatformPrintDevice
operator|::
name|defaultResolution
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|supportedResolutions
name|QList
argument_list|<
name|int
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedResolutions
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveResolutions
condition|)
name|loadResolutions
argument_list|()
expr_stmt|;
return|return
name|m_resolutions
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadInputSlots
name|void
name|QPlatformPrintDevice
operator|::
name|loadInputSlots
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultInputSlot
name|QPrint
operator|::
name|InputSlot
name|QPlatformPrintDevice
operator|::
name|defaultInputSlot
parameter_list|()
specifier|const
block|{
name|QPrint
operator|::
name|InputSlot
name|input
decl_stmt|;
name|input
operator|.
name|key
operator|=
name|QByteArrayLiteral
argument_list|(
literal|"Auto"
argument_list|)
expr_stmt|;
name|input
operator|.
name|name
operator|=
name|QPrintDialog
operator|::
name|tr
argument_list|(
literal|"Automatic"
argument_list|)
expr_stmt|;
name|input
operator|.
name|id
operator|=
name|QPrint
operator|::
name|Auto
expr_stmt|;
return|return
name|input
return|;
block|}
end_function
begin_function
DECL|function|supportedInputSlots
name|QList
argument_list|<
name|QPrint
operator|::
name|InputSlot
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedInputSlots
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveInputSlots
condition|)
name|loadInputSlots
argument_list|()
expr_stmt|;
return|return
name|m_inputSlots
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadOutputBins
name|void
name|QPlatformPrintDevice
operator|::
name|loadOutputBins
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultOutputBin
name|QPrint
operator|::
name|OutputBin
name|QPlatformPrintDevice
operator|::
name|defaultOutputBin
parameter_list|()
specifier|const
block|{
name|QPrint
operator|::
name|OutputBin
name|output
decl_stmt|;
name|output
operator|.
name|key
operator|=
name|QByteArrayLiteral
argument_list|(
literal|"Auto"
argument_list|)
expr_stmt|;
name|output
operator|.
name|name
operator|=
name|QPrintDialog
operator|::
name|tr
argument_list|(
literal|"Automatic"
argument_list|)
expr_stmt|;
name|output
operator|.
name|id
operator|=
name|QPrint
operator|::
name|AutoOutputBin
expr_stmt|;
return|return
name|output
return|;
block|}
end_function
begin_function
DECL|function|supportedOutputBins
name|QList
argument_list|<
name|QPrint
operator|::
name|OutputBin
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedOutputBins
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveOutputBins
condition|)
name|loadOutputBins
argument_list|()
expr_stmt|;
return|return
name|m_outputBins
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadDuplexModes
name|void
name|QPlatformPrintDevice
operator|::
name|loadDuplexModes
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultDuplexMode
name|QPrint
operator|::
name|DuplexMode
name|QPlatformPrintDevice
operator|::
name|defaultDuplexMode
parameter_list|()
specifier|const
block|{
return|return
name|QPrint
operator|::
name|DuplexNone
return|;
block|}
end_function
begin_function
DECL|function|supportedDuplexModes
name|QList
argument_list|<
name|QPrint
operator|::
name|DuplexMode
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedDuplexModes
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveDuplexModes
condition|)
name|loadDuplexModes
argument_list|()
expr_stmt|;
return|return
name|m_duplexModes
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loadColorModes
name|void
name|QPlatformPrintDevice
operator|::
name|loadColorModes
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|defaultColorMode
name|QPrint
operator|::
name|ColorMode
name|QPlatformPrintDevice
operator|::
name|defaultColorMode
parameter_list|()
specifier|const
block|{
return|return
name|QPrint
operator|::
name|GrayScale
return|;
block|}
end_function
begin_function
DECL|function|supportedColorModes
name|QList
argument_list|<
name|QPrint
operator|::
name|ColorMode
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedColorModes
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveColorModes
condition|)
name|loadColorModes
argument_list|()
expr_stmt|;
return|return
name|m_colorModes
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
end_ifndef
begin_function
DECL|function|loadMimeTypes
name|void
name|QPlatformPrintDevice
operator|::
name|loadMimeTypes
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|supportedMimeTypes
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|QPlatformPrintDevice
operator|::
name|supportedMimeTypes
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_haveMimeTypes
condition|)
name|loadMimeTypes
argument_list|()
expr_stmt|;
return|return
name|m_mimeTypes
operator|.
name|toList
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MIMETYPE
end_comment
begin_function
DECL|function|createPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|createPageSize
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QString
modifier|&
name|localizedName
parameter_list|)
block|{
return|return
name|QPageSize
argument_list|(
name|key
argument_list|,
name|size
argument_list|,
name|localizedName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPageSize
name|QPageSize
name|QPlatformPrintDevice
operator|::
name|createPageSize
parameter_list|(
name|int
name|windowsId
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QString
modifier|&
name|localizedName
parameter_list|)
block|{
return|return
name|QPageSize
argument_list|(
name|windowsId
argument_list|,
name|size
argument_list|,
name|localizedName
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
