begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcups_p.h"
end_include
begin_include
include|#
directive|include
file|"qprintengine.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CUPS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|cupsOptionsList
name|QStringList
name|QCUPSSupport
operator|::
name|cupsOptionsList
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|)
block|{
return|return
name|printer
operator|->
name|printEngine
argument_list|()
operator|->
name|property
argument_list|(
name|PPK_CupsOptions
argument_list|)
operator|.
name|toStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setCupsOptions
name|void
name|QCUPSSupport
operator|::
name|setCupsOptions
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|cupsOptions
parameter_list|)
block|{
name|printer
operator|->
name|printEngine
argument_list|()
operator|->
name|setProperty
argument_list|(
name|PPK_CupsOptions
argument_list|,
name|QVariant
argument_list|(
name|cupsOptions
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCupsOption
name|void
name|QCUPSSupport
operator|::
name|setCupsOption
parameter_list|(
name|QStringList
modifier|&
name|cupsOptions
parameter_list|,
specifier|const
name|QString
modifier|&
name|option
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|cupsOptions
operator|.
name|contains
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|cupsOptions
operator|.
name|replace
argument_list|(
name|cupsOptions
operator|.
name|indexOf
argument_list|(
name|option
argument_list|)
operator|+
literal|1
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|cupsOptions
operator|.
name|append
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|cupsOptions
operator|.
name|append
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setJobHold
name|void
name|QCUPSSupport
operator|::
name|setJobHold
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|JobHoldUntil
name|jobHold
parameter_list|,
specifier|const
name|QTime
modifier|&
name|holdUntilTime
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|jobHold
condition|)
block|{
case|case
name|NoHold
case|:
comment|//default
break|break;
case|case
name|Indefinite
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"indefinite"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DayTime
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"day-time"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Night
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"night"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|SecondShift
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"second-shift"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ThirdShift
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"third-shift"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|Weekend
case|:
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"weekend"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|SpecificTime
case|:
if|if
condition|(
name|holdUntilTime
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|setJobHold
argument_list|(
name|printer
argument_list|,
name|NoHold
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// CUPS expects the time in UTC, user has entered in local time, so get the UTS equivalent
name|QDateTime
name|localDateTime
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
comment|// Check if time is for tomorrow in case of DST change overnight
if|if
condition|(
name|holdUntilTime
operator|<
name|localDateTime
operator|.
name|time
argument_list|()
condition|)
name|localDateTime
operator|.
name|addDays
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|localDateTime
operator|.
name|setTime
argument_list|(
name|holdUntilTime
argument_list|)
expr_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-hold-until"
argument_list|)
argument_list|,
name|localDateTime
operator|.
name|toUTC
argument_list|()
operator|.
name|time
argument_list|()
operator|.
name|toString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"HH:mm"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setJobBilling
name|void
name|QCUPSSupport
operator|::
name|setJobBilling
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|QString
modifier|&
name|jobBilling
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-billing"
argument_list|)
argument_list|,
name|jobBilling
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setJobPriority
name|void
name|QCUPSSupport
operator|::
name|setJobPriority
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|int
name|priority
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-priority"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|priority
argument_list|)
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setBannerPages
name|void
name|QCUPSSupport
operator|::
name|setBannerPages
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|BannerPage
name|startBannerPage
parameter_list|,
specifier|const
name|BannerPage
name|endBannerPage
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
name|QString
name|startBanner
decl_stmt|,
name|endBanner
decl_stmt|;
switch|switch
condition|(
name|startBannerPage
condition|)
block|{
case|case
name|NoBanner
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"none"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Standard
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"standard"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Unclassified
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"unclassified"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Confidential
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"confidential"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Classified
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"classified"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Secret
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"secret"
argument_list|)
expr_stmt|;
break|break;
case|case
name|TopSecret
case|:
name|startBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"topsecret"
argument_list|)
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|endBannerPage
condition|)
block|{
case|case
name|NoBanner
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"none"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Standard
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"standard"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Unclassified
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"unclassified"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Confidential
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"confidential"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Classified
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"classified"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Secret
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"secret"
argument_list|)
expr_stmt|;
break|break;
case|case
name|TopSecret
case|:
name|endBanner
operator|=
name|QStringLiteral
argument_list|(
literal|"topsecret"
argument_list|)
expr_stmt|;
break|break;
block|}
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"job-sheets"
argument_list|)
argument_list|,
name|startBanner
operator|+
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
operator|+
name|endBanner
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPageSet
name|void
name|QCUPSSupport
operator|::
name|setPageSet
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|PageSet
name|pageSet
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
name|QString
name|pageSetString
decl_stmt|;
switch|switch
condition|(
name|pageSet
condition|)
block|{
case|case
name|OddPages
case|:
name|pageSetString
operator|=
name|QStringLiteral
argument_list|(
literal|"odd"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EvenPages
case|:
name|pageSetString
operator|=
name|QStringLiteral
argument_list|(
literal|"even"
argument_list|)
expr_stmt|;
break|break;
case|case
name|AllPages
case|:
name|pageSetString
operator|=
name|QStringLiteral
argument_list|(
literal|"all"
argument_list|)
expr_stmt|;
break|break;
block|}
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"page-set"
argument_list|)
argument_list|,
name|pageSetString
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPagesPerSheetLayout
name|void
name|QCUPSSupport
operator|::
name|setPagesPerSheetLayout
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
specifier|const
name|PagesPerSheet
name|pagesPerSheet
parameter_list|,
specifier|const
name|PagesPerSheetLayout
name|pagesPerSheetLayout
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|pagesPerSheetData
index|[]
init|=
block|{
literal|"1"
block|,
literal|"2"
block|,
literal|"4"
block|,
literal|"6"
block|,
literal|"9"
block|,
literal|"16"
block|,
literal|0
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|pageLayoutData
index|[]
init|=
block|{
literal|"lrtb"
block|,
literal|"lrbt"
block|,
literal|"rlbt"
block|,
literal|"rltb"
block|,
literal|"btlr"
block|,
literal|"btrl"
block|,
literal|"tblr"
block|,
literal|"tbrl"
block|,
literal|0
block|}
decl_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"number-up"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|pagesPerSheetData
index|[
name|pagesPerSheet
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"number-up-layout"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|pageLayoutData
index|[
name|pagesPerSheetLayout
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPageRange
name|void
name|QCUPSSupport
operator|::
name|setPageRange
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|,
name|int
name|pageFrom
parameter_list|,
name|int
name|pageTo
parameter_list|)
block|{
name|QStringList
name|cupsOptions
init|=
name|cupsOptionsList
argument_list|(
name|printer
argument_list|)
decl_stmt|;
name|setCupsOption
argument_list|(
name|cupsOptions
argument_list|,
name|QStringLiteral
argument_list|(
literal|"page-ranges"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"%1-%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|pageFrom
argument_list|)
operator|.
name|arg
argument_list|(
name|pageTo
argument_list|)
argument_list|)
expr_stmt|;
name|setCupsOptions
argument_list|(
name|printer
argument_list|,
name|cupsOptions
argument_list|)
expr_stmt|;
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
