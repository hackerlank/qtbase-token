begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpagedpaintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<qpagedpaintdevice.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|~QPagedPaintDevicePrivate
name|QPagedPaintDevicePrivate
operator|::
name|~
name|QPagedPaintDevicePrivate
operator|(
operator|)
block|{ }
comment|/*!     \class QPagedPaintDevice     \inmodule QtGui      \brief The QPagedPaintDevice class is a represents a paintdevice that supports     multiple pages.      \ingroup painting      Paged paint devices are used to generate output for printing or for formats like PDF.     QPdfWriter and QPrinter inherit from it.   */
comment|/*!   Constructs a new paged paint device.   */
DECL|function|QPagedPaintDevice
name|QPagedPaintDevice
operator|::
name|QPagedPaintDevice
argument_list|()
operator|:
name|d
argument_list|(
argument|new QPagedPaintDevicePrivate
argument_list|)
block|{ }
comment|/*!     \internal     Constructs a new paged paint device with the derived private class. */
DECL|function|QPagedPaintDevice
name|QPagedPaintDevice
operator|::
name|QPagedPaintDevice
argument_list|(
name|QPagedPaintDevicePrivate
operator|*
name|dd
argument_list|)
operator|:
name|d
argument_list|(
argument|dd
argument_list|)
block|{ }
comment|/*!   Destroys the object.   */
DECL|function|~QPagedPaintDevice
name|QPagedPaintDevice
operator|::
name|~
name|QPagedPaintDevice
operator|(
operator|)
block|{
operator|delete
name|d
block|; }
comment|/*!     \internal     Returns the QPagedPaintDevicePrivate. */
DECL|function|dd
name|QPagedPaintDevicePrivate
operator|*
name|QPagedPaintDevice
operator|::
name|dd
operator|(
operator|)
block|{
return|return
name|d
return|;
block|}
end_expr_stmt
begin_comment
comment|/*!     \enum QPagedPaintDevice::PageSize      This enum type lists the available page sizes as defined in the Postscript     PPD standard.  These values are duplicated in QPageSize and QPrinter.      The defined sizes are:      \value A0 841 x 1189 mm     \value A1 594 x 841 mm     \value A2 420 x 594 mm     \value A3 297 x 420 mm     \value A4 210 x 297 mm, 8.26 x 11.69 inches     \value A5 148 x 210 mm     \value A6 105 x 148 mm     \value A7 74 x 105 mm     \value A8 52 x 74 mm     \value A9 37 x 52 mm     \value B0 1000 x 1414 mm     \value B1 707 x 1000 mm     \value B2 500 x 707 mm     \value B3 353 x 500 mm     \value B4 250 x 353 mm     \value B5 176 x 250 mm, 6.93 x 9.84 inches     \value B6 125 x 176 mm     \value B7 88 x 125 mm     \value B8 62 x 88 mm     \value B9 33 x 62 mm     \value B10 31 x 44 mm     \value C5E 163 x 229 mm     \value Comm10E 105 x 241 mm, U.S. Common 10 Envelope     \value DLE 110 x 220 mm     \value Executive 7.5 x 10 inches, 190.5 x 254 mm     \value Folio 210 x 330 mm     \value Ledger 431.8 x 279.4 mm     \value Legal 8.5 x 14 inches, 215.9 x 355.6 mm     \value Letter 8.5 x 11 inches, 215.9 x 279.4 mm     \value Tabloid 279.4 x 431.8 mm     \value Custom Unknown, or a user defined size.     \value A10     \value A3Extra     \value A4Extra     \value A4Plus     \value A4Small     \value A5Extra     \value B5Extra     \value JisB0     \value JisB1     \value JisB2     \value JisB3     \value JisB4     \value JisB5     \value JisB6,     \value JisB7     \value JisB8     \value JisB9     \value JisB10     \value AnsiA = Letter     \value AnsiB = Ledger     \value AnsiC     \value AnsiD     \value AnsiE     \value LegalExtra     \value LetterExtra     \value LetterPlus     \value LetterSmall     \value TabloidExtra     \value ArchA     \value ArchB     \value ArchC     \value ArchD     \value ArchE     \value Imperial7x9     \value Imperial8x10     \value Imperial9x11     \value Imperial9x12     \value Imperial10x11     \value Imperial10x13     \value Imperial10x14     \value Imperial12x11     \value Imperial15x11     \value ExecutiveStandard     \value Note     \value Quarto     \value Statement     \value SuperA     \value SuperB     \value Postcard     \value DoublePostcard     \value Prc16K     \value Prc32K     \value Prc32KBig     \value FanFoldUS     \value FanFoldGerman     \value FanFoldGermanLegal     \value EnvelopeB4     \value EnvelopeB5     \value EnvelopeB6     \value EnvelopeC0     \value EnvelopeC1     \value EnvelopeC2     \value EnvelopeC3     \value EnvelopeC4     \value EnvelopeC5 = C5E     \value EnvelopeC6     \value EnvelopeC65     \value EnvelopeC7     \value EnvelopeDL = DLE     \value Envelope9     \value Envelope10 = Comm10E     \value Envelope11     \value Envelope12     \value Envelope14     \value EnvelopeMonarch     \value EnvelopePersonal     \value EnvelopeChou3     \value EnvelopeChou4     \value EnvelopeInvite     \value EnvelopeItalian     \value EnvelopeKaku2     \value EnvelopeKaku3     \value EnvelopePrc1     \value EnvelopePrc2     \value EnvelopePrc3     \value EnvelopePrc4     \value EnvelopePrc5     \value EnvelopePrc6     \value EnvelopePrc7     \value EnvelopePrc8     \value EnvelopePrc9     \value EnvelopePrc10     \value EnvelopeYou4     \value LastPageSize = EnvelopeYou4     \omitvalue NPageSize     \omitvalue NPaperSize      Due to historic reasons QPageSize::Executive is not the same as the standard     Postscript and Windows Executive size, use QPageSize::ExecutiveStandard instead.      The Postscript standard size QPageSize::Folio is different to the Windows     DMPAPER_FOLIO size, use the Postscript standard size QPageSize::FanFoldGermanLegal     if needed. */
end_comment
begin_comment
comment|/*!   \fn bool QPagedPaintDevice::newPage()    Starts a new page. Returns \c true on success. */
end_comment
begin_comment
comment|/*!   Sets the size of the a page to \a size.    \sa setPageSizeMM()   */
end_comment
begin_function
DECL|function|setPageSize
name|void
name|QPagedPaintDevice
operator|::
name|setPageSize
parameter_list|(
name|PageSize
name|size
parameter_list|)
block|{
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the currently used page size.   */
end_comment
begin_function
DECL|function|pageSize
name|QPagedPaintDevice
operator|::
name|PageSize
name|QPagedPaintDevice
operator|::
name|pageSize
parameter_list|()
specifier|const
block|{
return|return
name|PageSize
argument_list|(
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the page size to \a size. \a size is specified in millimeters.      If the size matches a standard QPagedPaintDevice::PageSize then that page     size will be used, otherwise QPagedPaintDevice::Custom will be set. */
end_comment
begin_function
DECL|function|setPageSizeMM
name|void
name|QPagedPaintDevice
operator|::
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
block|{
name|d
operator|->
name|m_pageLayout
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|size
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the page size in millimeters.   */
end_comment
begin_function
DECL|function|pageSizeMM
name|QSizeF
name|QPagedPaintDevice
operator|::
name|pageSizeMM
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|size
argument_list|(
name|QPageSize
operator|::
name|Millimeter
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the margins to be used to \a margins.    Margins are specified in millimeters.    The margins are purely a hint to the drawing method. They don't affect the   coordinate system or clipping.    \sa margins()   */
end_comment
begin_function
DECL|function|setMargins
name|void
name|QPagedPaintDevice
operator|::
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|margins
parameter_list|)
block|{
name|d
operator|->
name|m_pageLayout
operator|.
name|setUnits
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_pageLayout
operator|.
name|setMargins
argument_list|(
name|QMarginsF
argument_list|(
name|margins
operator|.
name|left
argument_list|,
name|margins
operator|.
name|top
argument_list|,
name|margins
operator|.
name|right
argument_list|,
name|margins
operator|.
name|bottom
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the current margins of the paint device. The default is 0.    Margins are specified in millimeters.    \sa setMargins()   */
end_comment
begin_function
DECL|function|margins
name|QPagedPaintDevice
operator|::
name|Margins
name|QPagedPaintDevice
operator|::
name|margins
parameter_list|()
specifier|const
block|{
name|QMarginsF
name|margins
init|=
name|d
operator|->
name|m_pageLayout
operator|.
name|margins
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
decl_stmt|;
name|Margins
name|result
decl_stmt|;
name|result
operator|.
name|left
operator|=
name|margins
operator|.
name|left
argument_list|()
expr_stmt|;
name|result
operator|.
name|top
operator|=
name|margins
operator|.
name|top
argument_list|()
expr_stmt|;
name|result
operator|.
name|right
operator|=
name|margins
operator|.
name|right
argument_list|()
expr_stmt|;
name|result
operator|.
name|bottom
operator|=
name|margins
operator|.
name|bottom
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Sets the page layout to \a newPageLayout.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new page layout to a new page.     You should not call any painting methods between a call to setPageLayout()     and newPage() as the wrong paint metrics may be used.      Returns true if the page layout was successfully set to \a newPageLayout.      \sa pageLayout() */
end_comment
begin_function
DECL|function|setPageLayout
name|bool
name|QPagedPaintDevice
operator|::
name|setPageLayout
parameter_list|(
specifier|const
name|QPageLayout
modifier|&
name|newPageLayout
parameter_list|)
block|{
return|return
name|d
operator|->
name|setPageLayout
argument_list|(
name|newPageLayout
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Sets the page size to \a pageSize.      To get the current QPageSize use pageLayout().pageSize().      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new page size to a new page.     You should not call any painting methods between a call to setPageSize()     and newPage() as the wrong paint metrics may be used.      Returns true if the page size was successfully set to \a pageSize.      \sa pageLayout() */
end_comment
begin_function
DECL|function|setPageSize
name|bool
name|QPagedPaintDevice
operator|::
name|setPageSize
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
block|{
return|return
name|d
operator|->
name|setPageSize
argument_list|(
name|pageSize
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Sets the page \a orientation.      The page orientation is used to define the orientation of the     page size when obtaining the page rect.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new orientation to a new page.     You should not call any painting methods between a call to setPageOrientation()     and newPage() as the wrong paint metrics may be used.      To get the current QPageLayout::Orientation use pageLayout().pageOrientation().      Returns true if the page orientation was successfully set to \a orientation.      \sa pageLayout() */
end_comment
begin_function
DECL|function|setPageOrientation
name|bool
name|QPagedPaintDevice
operator|::
name|setPageOrientation
parameter_list|(
name|QPageLayout
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
return|return
name|d
operator|->
name|setPageOrientation
argument_list|(
name|orientation
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Set the page \a margins in the current page layout units.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new margins to a new page.     You should not call any painting methods between a call to setPageMargins()     and newPage() as the wrong paint metrics may be used.      To get the current page margins use pageLayout().pageMargins().      Returns true if the page margins were successfully set to \a margins.      \sa pageLayout() */
end_comment
begin_function
DECL|function|setPageMargins
name|bool
name|QPagedPaintDevice
operator|::
name|setPageMargins
parameter_list|(
specifier|const
name|QMarginsF
modifier|&
name|margins
parameter_list|)
block|{
return|return
name|d
operator|->
name|setPageMargins
argument_list|(
name|margins
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Set the page \a margins defined in the given \a units.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new margins to a new page.     You should not call any painting methods between a call to setPageMargins()     and newPage() as the wrong paint metrics may be used.      To get the current page margins use pageLayout().pageMargins().      Returns true if the page margins were successfully set to \a margins.      \sa pageLayout() */
end_comment
begin_function
DECL|function|setPageMargins
name|bool
name|QPagedPaintDevice
operator|::
name|setPageMargins
parameter_list|(
specifier|const
name|QMarginsF
modifier|&
name|margins
parameter_list|,
name|QPageLayout
operator|::
name|Unit
name|units
parameter_list|)
block|{
return|return
name|d
operator|->
name|setPageMargins
argument_list|(
name|margins
argument_list|,
name|units
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Returns the current page layout.  Use this method to access the current     QPageSize, QPageLayout::Orientation, QMarginsF, fullRect() and paintRect().      Note that you cannot use the setters on the returned object, you must either     call the individual QPagedPaintDevice setters or use setPageLayout().      \sa setPageLayout(), setPageSize(), setPageOrientation(), setPageMargins() */
end_comment
begin_function
DECL|function|pageLayout
name|QPageLayout
name|QPagedPaintDevice
operator|::
name|pageLayout
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|pageLayout
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the internal device page layout. */
end_comment
begin_function
DECL|function|devicePageLayout
name|QPageLayout
name|QPagedPaintDevice
operator|::
name|devicePageLayout
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_pageLayout
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the internal device page layout. */
end_comment
begin_function
DECL|function|devicePageLayout
name|QPageLayout
modifier|&
name|QPagedPaintDevice
operator|::
name|devicePageLayout
parameter_list|()
block|{
return|return
name|d
operator|->
name|m_pageLayout
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
