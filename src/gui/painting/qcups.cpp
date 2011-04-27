begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qcups_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CUPS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUXBASE
end_ifndef
begin_comment
comment|// LSB merges everything into cups.h
end_comment
begin_include
include|#
directive|include
file|<cups/language.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qtextcodec.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|CupsGetDests
typedef|typedef
name|int
function_decl|(
modifier|*
name|CupsGetDests
function_decl|)
parameter_list|(
name|cups_dest_t
modifier|*
modifier|*
name|dests
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsFreeDests
typedef|typedef
name|void
function_decl|(
modifier|*
name|CupsFreeDests
function_decl|)
parameter_list|(
name|int
name|num_dests
parameter_list|,
name|cups_dest_t
modifier|*
name|dests
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsGetPPD
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|CupsGetPPD
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|printer
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsMarkOptions
typedef|typedef
name|int
function_decl|(
modifier|*
name|CupsMarkOptions
function_decl|)
parameter_list|(
name|ppd_file_t
modifier|*
name|ppd
parameter_list|,
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
name|options
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PPDOpenFile
typedef|typedef
name|ppd_file_t
modifier|*
function_decl|(
modifier|*
name|PPDOpenFile
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PPDMarkDefaults
typedef|typedef
name|void
function_decl|(
modifier|*
name|PPDMarkDefaults
function_decl|)
parameter_list|(
name|ppd_file_t
modifier|*
name|ppd
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PPDMarkOption
typedef|typedef
name|int
function_decl|(
modifier|*
name|PPDMarkOption
function_decl|)
parameter_list|(
name|ppd_file_t
modifier|*
name|ppd
parameter_list|,
specifier|const
name|char
modifier|*
name|keyword
parameter_list|,
specifier|const
name|char
modifier|*
name|option
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PPDClose
typedef|typedef
name|void
function_decl|(
modifier|*
name|PPDClose
function_decl|)
parameter_list|(
name|ppd_file_t
modifier|*
name|ppd
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PPDMarkOption
typedef|typedef
name|int
function_decl|(
modifier|*
name|PPDMarkOption
function_decl|)
parameter_list|(
name|ppd_file_t
modifier|*
name|ppd
parameter_list|,
specifier|const
name|char
modifier|*
name|keyword
parameter_list|,
specifier|const
name|char
modifier|*
name|option
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsFreeOptions
typedef|typedef
name|void
function_decl|(
modifier|*
name|CupsFreeOptions
function_decl|)
parameter_list|(
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
name|options
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsSetDests
typedef|typedef
name|void
function_decl|(
modifier|*
name|CupsSetDests
function_decl|)
parameter_list|(
name|int
name|num_dests
parameter_list|,
name|cups_dest_t
modifier|*
name|dests
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsLangGet
typedef|typedef
name|cups_lang_t
modifier|*
function_decl|(
modifier|*
name|CupsLangGet
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|language
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsLangEncoding
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|CupsLangEncoding
function_decl|)
parameter_list|(
name|cups_lang_t
modifier|*
name|language
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsAddOption
typedef|typedef
name|int
function_decl|(
modifier|*
name|CupsAddOption
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
modifier|*
name|options
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsTempFd
typedef|typedef
name|int
function_decl|(
modifier|*
name|CupsTempFd
function_decl|)
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CupsPrintFile
typedef|typedef
name|int
function_decl|(
modifier|*
name|CupsPrintFile
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
name|options
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|cupsLoaded
specifier|static
name|bool
name|cupsLoaded
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_cups_num_printers
specifier|static
name|int
name|qt_cups_num_printers
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsGetDests
specifier|static
name|CupsGetDests
name|_cupsGetDests
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsFreeDests
specifier|static
name|CupsFreeDests
name|_cupsFreeDests
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsGetPPD
specifier|static
name|CupsGetPPD
name|_cupsGetPPD
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_ppdOpenFile
specifier|static
name|PPDOpenFile
name|_ppdOpenFile
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_ppdMarkDefaults
specifier|static
name|PPDMarkDefaults
name|_ppdMarkDefaults
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_ppdClose
specifier|static
name|PPDClose
name|_ppdClose
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsMarkOptions
specifier|static
name|CupsMarkOptions
name|_cupsMarkOptions
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_ppdMarkOption
specifier|static
name|PPDMarkOption
name|_ppdMarkOption
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsFreeOptions
specifier|static
name|CupsFreeOptions
name|_cupsFreeOptions
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsSetDests
specifier|static
name|CupsSetDests
name|_cupsSetDests
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsLangGet
specifier|static
name|CupsLangGet
name|_cupsLangGet
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsLangEncoding
specifier|static
name|CupsLangEncoding
name|_cupsLangEncoding
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsAddOption
specifier|static
name|CupsAddOption
name|_cupsAddOption
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsTempFd
specifier|static
name|CupsTempFd
name|_cupsTempFd
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_cupsPrintFile
specifier|static
name|CupsPrintFile
name|_cupsPrintFile
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|resolveCups
specifier|static
name|void
name|resolveCups
parameter_list|()
block|{
name|QLibrary
name|cupsLib
argument_list|(
name|QLatin1String
argument_list|(
literal|"cups"
argument_list|)
argument_list|,
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|cupsLib
operator|.
name|load
argument_list|()
condition|)
block|{
name|_cupsGetDests
operator|=
operator|(
name|CupsGetDests
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsGetDests"
argument_list|)
expr_stmt|;
name|_cupsFreeDests
operator|=
operator|(
name|CupsFreeDests
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsFreeDests"
argument_list|)
expr_stmt|;
name|_cupsGetPPD
operator|=
operator|(
name|CupsGetPPD
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsGetPPD"
argument_list|)
expr_stmt|;
name|_cupsLangGet
operator|=
operator|(
name|CupsLangGet
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsLangGet"
argument_list|)
expr_stmt|;
name|_cupsLangEncoding
operator|=
operator|(
name|CupsLangEncoding
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsLangEncoding"
argument_list|)
expr_stmt|;
name|_ppdOpenFile
operator|=
operator|(
name|PPDOpenFile
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"ppdOpenFile"
argument_list|)
expr_stmt|;
name|_ppdMarkDefaults
operator|=
operator|(
name|PPDMarkDefaults
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"ppdMarkDefaults"
argument_list|)
expr_stmt|;
name|_ppdClose
operator|=
operator|(
name|PPDClose
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"ppdClose"
argument_list|)
expr_stmt|;
name|_cupsMarkOptions
operator|=
operator|(
name|CupsMarkOptions
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsMarkOptions"
argument_list|)
expr_stmt|;
name|_ppdMarkOption
operator|=
operator|(
name|PPDMarkOption
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"ppdMarkOption"
argument_list|)
expr_stmt|;
name|_cupsFreeOptions
operator|=
operator|(
name|CupsFreeOptions
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsFreeOptions"
argument_list|)
expr_stmt|;
name|_cupsSetDests
operator|=
operator|(
name|CupsSetDests
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsSetDests"
argument_list|)
expr_stmt|;
name|_cupsAddOption
operator|=
operator|(
name|CupsAddOption
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsAddOption"
argument_list|)
expr_stmt|;
name|_cupsTempFd
operator|=
operator|(
name|CupsTempFd
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsTempFd"
argument_list|)
expr_stmt|;
name|_cupsPrintFile
operator|=
operator|(
name|CupsPrintFile
operator|)
name|cupsLib
operator|.
name|resolve
argument_list|(
literal|"cupsPrintFile"
argument_list|)
expr_stmt|;
if|if
condition|(
name|_cupsGetDests
operator|&&
name|_cupsFreeDests
condition|)
block|{
name|cups_dest_t
modifier|*
name|printers
decl_stmt|;
name|int
name|num_printers
init|=
name|_cupsGetDests
argument_list|(
operator|&
name|printers
argument_list|)
decl_stmt|;
if|if
condition|(
name|num_printers
condition|)
name|_cupsFreeDests
argument_list|(
name|num_printers
argument_list|,
name|printers
argument_list|)
expr_stmt|;
name|qt_cups_num_printers
operator|=
name|num_printers
expr_stmt|;
block|}
block|}
name|cupsLoaded
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// ================ CUPS Support class ========================
end_comment
begin_constructor
DECL|function|QCUPSSupport
name|QCUPSSupport
operator|::
name|QCUPSSupport
parameter_list|()
member_init_list|:
name|prnCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|printers
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|page_sizes
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currPrinterIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currPPD
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|cupsLoaded
condition|)
name|resolveCups
argument_list|()
expr_stmt|;
comment|// getting all available printers
if|if
condition|(
operator|!
name|isAvailable
argument_list|()
condition|)
return|return;
name|prnCount
operator|=
name|_cupsGetDests
argument_list|(
operator|&
name|printers
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|prnCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|printers
index|[
name|i
index|]
operator|.
name|is_default
condition|)
block|{
name|currPrinterIndex
operator|=
name|i
expr_stmt|;
name|setCurrentPrinter
argument_list|(
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|cups_lang_t
modifier|*
name|cupsLang
init|=
name|_cupsLangGet
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|codec
operator|=
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|_cupsLangEncoding
argument_list|(
name|cupsLang
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|codec
condition|)
name|codec
operator|=
name|QTextCodec
operator|::
name|codecForLocale
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QCUPSSupport
name|QCUPSSupport
operator|::
name|~
name|QCUPSSupport
parameter_list|()
block|{
if|if
condition|(
name|currPPD
condition|)
name|_ppdClose
argument_list|(
name|currPPD
argument_list|)
expr_stmt|;
if|if
condition|(
name|prnCount
condition|)
name|_cupsFreeDests
argument_list|(
name|prnCount
argument_list|,
name|printers
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|availablePrintersCount
name|int
name|QCUPSSupport
operator|::
name|availablePrintersCount
parameter_list|()
specifier|const
block|{
return|return
name|prnCount
return|;
block|}
end_function
begin_function
DECL|function|availablePrinters
specifier|const
name|cups_dest_t
modifier|*
name|QCUPSSupport
operator|::
name|availablePrinters
parameter_list|()
specifier|const
block|{
return|return
name|printers
return|;
block|}
end_function
begin_function
DECL|function|currentPPD
specifier|const
name|ppd_file_t
modifier|*
name|QCUPSSupport
operator|::
name|currentPPD
parameter_list|()
specifier|const
block|{
return|return
name|currPPD
return|;
block|}
end_function
begin_function
DECL|function|setCurrentPrinter
specifier|const
name|ppd_file_t
modifier|*
name|QCUPSSupport
operator|::
name|setCurrentPrinter
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|index
operator|>=
literal|0
operator|&&
name|index
operator|<=
name|prnCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|==
name|prnCount
condition|)
return|return
literal|0
return|;
name|currPrinterIndex
operator|=
name|index
expr_stmt|;
if|if
condition|(
name|currPPD
condition|)
name|_ppdClose
argument_list|(
name|currPPD
argument_list|)
expr_stmt|;
name|currPPD
operator|=
literal|0
expr_stmt|;
name|page_sizes
operator|=
literal|0
expr_stmt|;
specifier|const
name|char
modifier|*
name|ppdFile
init|=
name|_cupsGetPPD
argument_list|(
name|printers
index|[
name|index
index|]
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ppdFile
condition|)
return|return
literal|0
return|;
name|currPPD
operator|=
name|_ppdOpenFile
argument_list|(
name|ppdFile
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|ppdFile
argument_list|)
expr_stmt|;
comment|// marking default options
name|_ppdMarkDefaults
argument_list|(
name|currPPD
argument_list|)
expr_stmt|;
comment|// marking options explicitly set
name|_cupsMarkOptions
argument_list|(
name|currPPD
argument_list|,
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|num_options
argument_list|,
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|options
argument_list|)
expr_stmt|;
comment|// getting pointer to page sizes
name|page_sizes
operator|=
name|ppdOption
argument_list|(
literal|"PageSize"
argument_list|)
expr_stmt|;
return|return
name|currPPD
return|;
block|}
end_function
begin_function
DECL|function|currentPrinterIndex
name|int
name|QCUPSSupport
operator|::
name|currentPrinterIndex
parameter_list|()
specifier|const
block|{
return|return
name|currPrinterIndex
return|;
block|}
end_function
begin_function
DECL|function|isAvailable
name|bool
name|QCUPSSupport
operator|::
name|isAvailable
parameter_list|()
block|{
if|if
condition|(
operator|!
name|cupsLoaded
condition|)
name|resolveCups
argument_list|()
expr_stmt|;
return|return
name|_cupsGetDests
operator|&&
name|_cupsFreeDests
operator|&&
name|_cupsGetPPD
operator|&&
name|_ppdOpenFile
operator|&&
name|_ppdMarkDefaults
operator|&&
name|_ppdClose
operator|&&
name|_cupsMarkOptions
operator|&&
name|_ppdMarkOption
operator|&&
name|_cupsFreeOptions
operator|&&
name|_cupsSetDests
operator|&&
name|_cupsLangGet
operator|&&
name|_cupsLangEncoding
operator|&&
name|_cupsAddOption
operator|&&
operator|(
name|qt_cups_num_printers
operator|>
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|ppdOption
specifier|const
name|ppd_option_t
modifier|*
name|QCUPSSupport
operator|::
name|ppdOption
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|currPPD
condition|)
block|{
for|for
control|(
name|int
name|gr
init|=
literal|0
init|;
name|gr
operator|<
name|currPPD
operator|->
name|num_groups
condition|;
operator|++
name|gr
control|)
block|{
for|for
control|(
name|int
name|opt
init|=
literal|0
init|;
name|opt
operator|<
name|currPPD
operator|->
name|groups
index|[
name|gr
index|]
operator|.
name|num_options
condition|;
operator|++
name|opt
control|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|currPPD
operator|->
name|groups
index|[
name|gr
index|]
operator|.
name|options
index|[
name|opt
index|]
operator|.
name|keyword
argument_list|,
name|key
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|&
name|currPPD
operator|->
name|groups
index|[
name|gr
index|]
operator|.
name|options
index|[
name|opt
index|]
return|;
block|}
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|printerOption
specifier|const
name|cups_option_t
modifier|*
name|QCUPSSupport
operator|::
name|printerOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|num_options
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLatin1String
argument_list|(
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|options
index|[
name|i
index|]
operator|.
name|name
argument_list|)
operator|==
name|key
condition|)
return|return
operator|&
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|options
index|[
name|i
index|]
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|pageSizes
specifier|const
name|ppd_option_t
modifier|*
name|QCUPSSupport
operator|::
name|pageSizes
parameter_list|()
specifier|const
block|{
return|return
name|page_sizes
return|;
block|}
end_function
begin_function
DECL|function|markOption
name|int
name|QCUPSSupport
operator|::
name|markOption
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
block|{
return|return
name|_ppdMarkOption
argument_list|(
name|currPPD
argument_list|,
name|name
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|saveOptions
name|void
name|QCUPSSupport
operator|::
name|saveOptions
parameter_list|(
name|QList
argument_list|<
specifier|const
name|ppd_option_t
modifier|*
argument_list|>
name|options
parameter_list|,
name|QList
argument_list|<
specifier|const
name|char
modifier|*
argument_list|>
name|markedOptions
parameter_list|)
block|{
name|int
name|oldOptionCount
init|=
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|num_options
decl_stmt|;
name|cups_option_t
modifier|*
name|oldOptions
init|=
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|options
decl_stmt|;
name|int
name|newOptionCount
init|=
literal|0
decl_stmt|;
name|cups_option_t
modifier|*
name|newOptions
init|=
literal|0
decl_stmt|;
comment|// copying old options that are not on the new list
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|oldOptionCount
condition|;
operator|++
name|i
control|)
block|{
name|bool
name|contains
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|options
operator|.
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|options
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|->
name|keyword
argument_list|,
name|oldOptions
index|[
name|i
index|]
operator|.
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|contains
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|contains
condition|)
block|{
name|newOptionCount
operator|=
name|_cupsAddOption
argument_list|(
name|oldOptions
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|oldOptions
index|[
name|i
index|]
operator|.
name|value
argument_list|,
name|newOptionCount
argument_list|,
operator|&
name|newOptions
argument_list|)
expr_stmt|;
block|}
block|}
comment|// we can release old option list
name|_cupsFreeOptions
argument_list|(
name|oldOptionCount
argument_list|,
name|oldOptions
argument_list|)
expr_stmt|;
comment|// adding marked options
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|markedOptions
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|markedOptions
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
operator|++
name|i
expr_stmt|;
name|newOptionCount
operator|=
name|_cupsAddOption
argument_list|(
name|name
argument_list|,
name|markedOptions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|newOptionCount
argument_list|,
operator|&
name|newOptions
argument_list|)
expr_stmt|;
block|}
comment|// placing the new option list
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|num_options
operator|=
name|newOptionCount
expr_stmt|;
name|printers
index|[
name|currPrinterIndex
index|]
operator|.
name|options
operator|=
name|newOptions
expr_stmt|;
comment|// saving new default values
name|_cupsSetDests
argument_list|(
name|prnCount
argument_list|,
name|printers
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paperRect
name|QRect
name|QCUPSSupport
operator|::
name|paperRect
parameter_list|(
specifier|const
name|char
modifier|*
name|choice
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|currPPD
condition|)
return|return
name|QRect
argument_list|()
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currPPD
operator|->
name|num_sizes
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|choice
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|width
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|length
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|pageRect
name|QRect
name|QCUPSSupport
operator|::
name|pageRect
parameter_list|(
specifier|const
name|char
modifier|*
name|choice
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|currPPD
condition|)
return|return
name|QRect
argument_list|()
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currPPD
operator|->
name|num_sizes
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|qstrcmp
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|choice
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QRect
argument_list|(
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|left
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|length
operator|-
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|top
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|right
operator|-
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|left
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|top
operator|-
name|currPPD
operator|->
name|sizes
index|[
name|i
index|]
operator|.
name|bottom
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|options
name|QStringList
name|QCUPSSupport
operator|::
name|options
parameter_list|()
specifier|const
block|{
name|QStringList
name|list
decl_stmt|;
name|collectMarkedOptions
argument_list|(
name|list
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|printerHasPPD
name|bool
name|QCUPSSupport
operator|::
name|printerHasPPD
parameter_list|(
specifier|const
name|char
modifier|*
name|printerName
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isAvailable
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|const
name|char
modifier|*
name|ppdFile
init|=
name|_cupsGetPPD
argument_list|(
name|printerName
argument_list|)
decl_stmt|;
if|if
condition|(
name|ppdFile
condition|)
name|unlink
argument_list|(
name|ppdFile
argument_list|)
expr_stmt|;
return|return
operator|(
name|ppdFile
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|unicodeString
name|QString
name|QCUPSSupport
operator|::
name|unicodeString
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
return|return
name|codec
operator|->
name|toUnicode
argument_list|(
name|s
argument_list|)
return|;
else|#
directive|else
return|return
name|QLatin1String
argument_list|(
name|s
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|collectMarkedOptions
name|void
name|QCUPSSupport
operator|::
name|collectMarkedOptions
parameter_list|(
name|QStringList
modifier|&
name|list
parameter_list|,
specifier|const
name|ppd_group_t
modifier|*
name|group
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|group
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|currPPD
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currPPD
operator|->
name|num_groups
condition|;
operator|++
name|i
control|)
block|{
name|collectMarkedOptions
argument_list|(
name|list
argument_list|,
operator|&
name|currPPD
operator|->
name|groups
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|collectMarkedOptionsHelper
argument_list|(
name|list
argument_list|,
operator|&
name|currPPD
operator|->
name|groups
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|group
operator|->
name|num_subgroups
condition|;
operator|++
name|i
control|)
name|collectMarkedOptionsHelper
argument_list|(
name|list
argument_list|,
operator|&
name|group
operator|->
name|subgroups
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|collectMarkedOptionsHelper
name|void
name|QCUPSSupport
operator|::
name|collectMarkedOptionsHelper
parameter_list|(
name|QStringList
modifier|&
name|list
parameter_list|,
specifier|const
name|ppd_group_t
modifier|*
name|group
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|group
operator|->
name|num_options
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|num_choices
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|choices
index|[
name|j
index|]
operator|.
name|marked
operator|==
literal|1
operator|&&
name|qstrcmp
argument_list|(
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|choices
index|[
name|j
index|]
operator|.
name|choice
argument_list|,
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|defchoice
argument_list|)
operator|!=
literal|0
condition|)
name|list
operator|<<
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|keyword
argument_list|)
operator|<<
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|group
operator|->
name|options
index|[
name|i
index|]
operator|.
name|choices
index|[
name|j
index|]
operator|.
name|choice
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|tempFd
name|QPair
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|QCUPSSupport
operator|::
name|tempFd
parameter_list|()
block|{
name|char
name|filename
index|[
literal|512
index|]
decl_stmt|;
name|int
name|fd
init|=
name|_cupsTempFd
argument_list|(
name|filename
argument_list|,
literal|512
argument_list|)
decl_stmt|;
return|return
name|QPair
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
argument_list|(
name|fd
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|filename
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Prints the given file and returns a job id.
end_comment
begin_function
DECL|function|printFile
name|int
name|QCUPSSupport
operator|::
name|printFile
parameter_list|(
specifier|const
name|char
modifier|*
name|printerName
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|int
name|num_options
parameter_list|,
name|cups_option_t
modifier|*
name|options
parameter_list|)
block|{
return|return
name|_cupsPrintFile
argument_list|(
name|printerName
argument_list|,
name|filename
argument_list|,
name|title
argument_list|,
name|num_options
argument_list|,
name|options
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CUPS
end_comment
end_unit
