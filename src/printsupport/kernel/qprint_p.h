begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtPrintSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINT_P_H
end_ifndef
begin_define
DECL|macro|QPRINT_P_H
define|#
directive|define
name|QPRINT_P_H
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
file|<QtPrintSupport/qprinter.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_if
if|#
directive|if
operator|(
name|defined
name|Q_OS_MAC
operator|&&
operator|!
name|defined
name|Q_OS_IOS
operator|)
operator|||
operator|(
name|defined
name|Q_OS_UNIX
operator|&&
operator|!
name|defined
name|QT_NO_CUPS
operator|)
end_if
begin_include
include|#
directive|include
file|<cups/ppd.h>
end_include
begin_comment
comment|// Use for type defs only, don't want to actually link in main module
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
comment|// From windgdi.h
DECL|macro|DMBIN_UPPER
define|#
directive|define
name|DMBIN_UPPER
value|1
DECL|macro|DMBIN_ONLYONE
define|#
directive|define
name|DMBIN_ONLYONE
value|1
DECL|macro|DMBIN_LOWER
define|#
directive|define
name|DMBIN_LOWER
value|2
DECL|macro|DMBIN_MIDDLE
define|#
directive|define
name|DMBIN_MIDDLE
value|3
DECL|macro|DMBIN_MANUAL
define|#
directive|define
name|DMBIN_MANUAL
value|4
DECL|macro|DMBIN_ENVELOPE
define|#
directive|define
name|DMBIN_ENVELOPE
value|5
DECL|macro|DMBIN_ENVMANUAL
define|#
directive|define
name|DMBIN_ENVMANUAL
value|6
DECL|macro|DMBIN_AUTO
define|#
directive|define
name|DMBIN_AUTO
value|7
DECL|macro|DMBIN_TRACTOR
define|#
directive|define
name|DMBIN_TRACTOR
value|8
DECL|macro|DMBIN_SMALLFMT
define|#
directive|define
name|DMBIN_SMALLFMT
value|9
DECL|macro|DMBIN_LARGEFMT
define|#
directive|define
name|DMBIN_LARGEFMT
value|10
DECL|macro|DMBIN_LARGECAPACITY
define|#
directive|define
name|DMBIN_LARGECAPACITY
value|11
DECL|macro|DMBIN_CASSETTE
define|#
directive|define
name|DMBIN_CASSETTE
value|14
DECL|macro|DMBIN_FORMSOURCE
define|#
directive|define
name|DMBIN_FORMSOURCE
value|15
DECL|macro|DMBIN_USER
define|#
directive|define
name|DMBIN_USER
value|256
name|namespace
name|QPrint
block|{
comment|// Note: Keep in sync with QPrinter::PrinterState for now
comment|// Replace later with more detailed status reporting
enum|enum
name|DeviceState
block|{
name|Idle
block|,
name|Active
block|,
name|Aborted
block|,
name|Error
block|}
enum|;
comment|// Note: Keep in sync with QPrinter::DuplexMode
enum|enum
name|DuplexMode
block|{
name|DuplexNone
init|=
literal|0
block|,
name|DuplexAuto
block|,
name|DuplexLongSide
block|,
name|DuplexShortSide
block|}
enum|;
enum|enum
name|ColorMode
block|{
name|GrayScale
block|,
name|Color
block|}
enum|;
comment|// Note: Keep in sync with QPrinter::PaperSource for now
comment|// If/when made public, rearrange and rename
enum|enum
name|InputSlotId
block|{
name|Upper
block|,
name|Lower
block|,
name|Middle
block|,
name|Manual
block|,
name|Envelope
block|,
name|EnvelopeManual
block|,
name|Auto
block|,
name|Tractor
block|,
name|SmallFormat
block|,
name|LargeFormat
block|,
name|LargeCapacity
block|,
name|Cassette
block|,
name|FormSource
block|,
name|MaxPageSource
block|,
comment|// Deprecated, kept for compatibility to QPrinter
name|CustomInputSlot
block|,
name|LastInputSlot
init|=
name|CustomInputSlot
block|,
name|OnlyOne
init|=
name|Upper
block|}
enum|;
struct|struct
name|InputSlot
block|{
name|QByteArray
name|key
decl_stmt|;
name|QString
name|name
decl_stmt|;
name|QPrint
operator|::
name|InputSlotId
name|id
expr_stmt|;
name|int
name|windowsId
decl_stmt|;
block|}
struct|;
enum|enum
name|OutputBinId
block|{
name|AutoOutputBin
block|,
name|UpperBin
block|,
name|LowerBin
block|,
name|RearBin
block|,
name|CustomOutputBin
block|,
name|LastOutputBin
init|=
name|CustomOutputBin
block|}
enum|;
struct|struct
name|OutputBin
block|{
name|QByteArray
name|key
decl_stmt|;
name|QString
name|name
decl_stmt|;
name|QPrint
operator|::
name|OutputBinId
name|id
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_struct
DECL|struct|InputSlotMap
struct|struct
name|InputSlotMap
block|{
DECL|member|id
name|QPrint
operator|::
name|InputSlotId
name|id
expr_stmt|;
DECL|member|windowsId
name|int
name|windowsId
decl_stmt|;
DECL|member|key
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// Note: PPD standard does not define a standard set of InputSlot keywords,
end_comment
begin_comment
comment|// it is a free form text field left to the PPD writer to decide,
end_comment
begin_comment
comment|// but it does suggest some names for consistency with the Windows enum.
end_comment
begin_decl_stmt
DECL|variable|inputSlotMap
specifier|static
specifier|const
name|InputSlotMap
name|inputSlotMap
index|[]
init|=
block|{
block|{
name|QPrint
operator|::
name|Upper
block|,
name|DMBIN_UPPER
block|,
literal|"Upper"
block|}
block|,
block|{
name|QPrint
operator|::
name|Lower
block|,
name|DMBIN_LOWER
block|,
literal|"Lower"
block|}
block|,
block|{
name|QPrint
operator|::
name|Middle
block|,
name|DMBIN_MIDDLE
block|,
literal|"Middle"
block|}
block|,
block|{
name|QPrint
operator|::
name|Manual
block|,
name|DMBIN_MANUAL
block|,
literal|"Manual"
block|}
block|,
block|{
name|QPrint
operator|::
name|Envelope
block|,
name|DMBIN_ENVELOPE
block|,
literal|"Envelope"
block|}
block|,
block|{
name|QPrint
operator|::
name|EnvelopeManual
block|,
name|DMBIN_ENVMANUAL
block|,
literal|"EnvelopeManual"
block|}
block|,
block|{
name|QPrint
operator|::
name|Auto
block|,
name|DMBIN_AUTO
block|,
literal|"Auto"
block|}
block|,
block|{
name|QPrint
operator|::
name|Tractor
block|,
name|DMBIN_TRACTOR
block|,
literal|"Tractor"
block|}
block|,
block|{
name|QPrint
operator|::
name|SmallFormat
block|,
name|DMBIN_SMALLFMT
block|,
literal|"AnySmallFormat"
block|}
block|,
block|{
name|QPrint
operator|::
name|LargeFormat
block|,
name|DMBIN_LARGEFMT
block|,
literal|"AnyLargeFormat"
block|}
block|,
block|{
name|QPrint
operator|::
name|LargeCapacity
block|,
name|DMBIN_LARGECAPACITY
block|,
literal|"LargeCapacity"
block|}
block|,
block|{
name|QPrint
operator|::
name|Cassette
block|,
name|DMBIN_CASSETTE
block|,
literal|"Cassette"
block|}
block|,
block|{
name|QPrint
operator|::
name|FormSource
block|,
name|DMBIN_FORMSOURCE
block|,
literal|"FormSource"
block|}
block|,
block|{
name|QPrint
operator|::
name|Manual
block|,
name|DMBIN_MANUAL
block|,
literal|"ManualFeed"
block|}
block|,
block|{
name|QPrint
operator|::
name|OnlyOne
block|,
name|DMBIN_ONLYONE
block|,
literal|"OnlyOne"
block|}
block|,
comment|// = QPrint::Upper
block|{
name|QPrint
operator|::
name|CustomInputSlot
block|,
name|DMBIN_USER
block|,
literal|""
block|}
comment|// Must always be last row
block|}
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|OutputBinMap
struct|struct
name|OutputBinMap
block|{
DECL|member|id
name|QPrint
operator|::
name|OutputBinId
name|id
expr_stmt|;
DECL|member|key
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|outputBinMap
specifier|static
specifier|const
name|OutputBinMap
name|outputBinMap
index|[]
init|=
block|{
block|{
name|QPrint
operator|::
name|AutoOutputBin
block|,
literal|""
block|}
block|,
comment|// Not a PPD defined value, internal use only
block|{
name|QPrint
operator|::
name|UpperBin
block|,
literal|"Upper"
block|}
block|,
block|{
name|QPrint
operator|::
name|LowerBin
block|,
literal|"Lower"
block|}
block|,
block|{
name|QPrint
operator|::
name|RearBin
block|,
literal|"Rear"
block|}
block|,
block|{
name|QPrint
operator|::
name|CustomOutputBin
block|,
literal|""
block|}
comment|// Must always be last row
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Print utilities shared by print plugins
end_comment
begin_decl_stmt
name|class
name|QPrintUtils
block|{
name|public
label|:
specifier|static
name|QPrint
operator|::
name|InputSlotId
name|inputSlotKeyToInputSlotId
argument_list|(
argument|const QByteArray&key
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|QPrint
operator|::
name|CustomInputSlot
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|key
operator|==
name|key
condition|)
return|return
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
return|;
block|}
return|return
name|QPrint
operator|::
name|CustomInputSlot
return|;
block|}
specifier|static
name|QByteArray
name|inputSlotIdToInputSlotKey
argument_list|(
name|QPrint
operator|::
name|InputSlotId
name|id
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|QPrint
operator|::
name|CustomInputSlot
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
operator|==
name|id
condition|)
return|return
name|QByteArray
argument_list|(
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|key
argument_list|)
return|;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
specifier|static
name|int
name|inputSlotIdToWindowsId
argument_list|(
name|QPrint
operator|::
name|InputSlotId
name|id
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|QPrint
operator|::
name|CustomInputSlot
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|id
operator|==
name|id
condition|)
return|return
name|inputSlotMap
index|[
name|i
index|]
operator|.
name|windowsId
return|;
block|}
return|return
literal|0
return|;
block|}
specifier|static
name|QPrint
operator|::
name|OutputBinId
name|outputBinKeyToOutputBinId
argument_list|(
argument|const QByteArray&key
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|outputBinMap
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|QPrint
operator|::
name|CustomOutputBin
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|outputBinMap
index|[
name|i
index|]
operator|.
name|key
operator|==
name|key
condition|)
return|return
name|outputBinMap
index|[
name|i
index|]
operator|.
name|id
return|;
block|}
return|return
name|QPrint
operator|::
name|CustomOutputBin
return|;
block|}
specifier|static
name|QByteArray
name|outputBinIdToOutputBinKey
argument_list|(
name|QPrint
operator|::
name|OutputBinId
name|id
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|outputBinMap
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|QPrint
operator|::
name|CustomOutputBin
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|outputBinMap
index|[
name|i
index|]
operator|.
name|id
operator|==
name|id
condition|)
return|return
name|QByteArray
argument_list|(
name|outputBinMap
index|[
name|i
index|]
operator|.
name|key
argument_list|)
return|;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
if|#
directive|if
operator|(
name|defined
name|Q_OS_MAC
operator|&&
operator|!
name|defined
name|Q_OS_IOS
operator|)
operator|||
operator|(
name|defined
name|Q_OS_UNIX
operator|&&
operator|!
name|defined
name|QT_NO_CUPS
operator|)
comment|// PPD utilities shared by CUPS and Mac plugins requiring CUPS headers
comment|// May turn into a proper internal QPpd class if enough shared between Mac and CUPS,
comment|// but where would it live?  Not in base module as don't want to link to CUPS.
comment|// May have to have two copies in plugins to keep in sync.
specifier|static
name|QPrint
operator|::
name|InputSlot
name|ppdChoiceToInputSlot
argument_list|(
argument|const ppd_choice_t&choice
argument_list|)
block|{
name|QPrint
operator|::
name|InputSlot
name|input
block|;
name|input
operator|.
name|key
operator|=
name|choice
operator|.
name|choice
block|;
name|input
operator|.
name|name
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|choice
operator|.
name|text
argument_list|)
block|;
name|input
operator|.
name|id
operator|=
name|inputSlotKeyToInputSlotId
argument_list|(
name|input
operator|.
name|key
argument_list|)
block|;
name|input
operator|.
name|windowsId
operator|=
name|inputSlotMap
index|[
name|input
operator|.
name|id
index|]
operator|.
name|windowsId
block|;
return|return
name|input
return|;
block|}
specifier|static
name|QPrint
operator|::
name|OutputBin
name|ppdChoiceToOutputBin
argument_list|(
argument|const ppd_choice_t&choice
argument_list|)
block|{
name|QPrint
operator|::
name|OutputBin
name|output
block|;
name|output
operator|.
name|key
operator|=
name|choice
operator|.
name|choice
block|;
name|output
operator|.
name|name
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|choice
operator|.
name|text
argument_list|)
block|;
name|output
operator|.
name|id
operator|=
name|outputBinKeyToOutputBinId
argument_list|(
name|output
operator|.
name|key
argument_list|)
block|;
return|return
name|output
return|;
block|}
specifier|static
name|int
name|parsePpdResolution
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
comment|// value can be in form 600dpi or 600x600dpi
name|QByteArray
name|result
init|=
name|value
operator|.
name|split
argument_list|(
literal|'x'
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|.
name|endsWith
argument_list|(
literal|"dpi"
argument_list|)
condition|)
name|result
operator|.
name|chop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
return|return
name|result
operator|.
name|toInt
argument_list|()
return|;
block|}
specifier|static
name|QPrint
operator|::
name|DuplexMode
name|ppdChoiceToDuplexMode
argument_list|(
argument|const QByteArray&choice
argument_list|)
block|{
if|if
condition|(
name|choice
operator|==
literal|"DuplexTumble"
condition|)
return|return
name|QPrint
operator|::
name|DuplexShortSide
return|;
elseif|else
if|if
condition|(
name|choice
operator|==
literal|"DuplexNoTumble"
condition|)
return|return
name|QPrint
operator|::
name|DuplexLongSide
return|;
else|else
comment|// None or SimplexTumble or SimplexNoTumble
return|return
name|QPrint
operator|::
name|DuplexNone
return|;
block|}
endif|#
directive|endif
comment|// Mac and CUPS PPD Utilities
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINT_P_H
end_comment
end_unit
