begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocale_p.h"
end_include
begin_include
include|#
directive|include
file|"qstringbuilder.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
end_ifndef
begin_struct
DECL|struct|QSystemLocaleData
struct|struct
name|QSystemLocaleData
block|{
DECL|function|QSystemLocaleData
name|QSystemLocaleData
parameter_list|()
member_init_list|:
name|lc_numeric
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
member_init_list|,
name|lc_time
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
member_init_list|,
name|lc_monetary
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
member_init_list|,
name|lc_messages
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
block|{
name|readEnvironment
argument_list|()
expr_stmt|;
block|}
name|void
name|readEnvironment
parameter_list|()
function_decl|;
DECL|member|lock
name|QReadWriteLock
name|lock
decl_stmt|;
DECL|member|lc_numeric
name|QLocale
name|lc_numeric
decl_stmt|;
DECL|member|lc_time
name|QLocale
name|lc_time
decl_stmt|;
DECL|member|lc_monetary
name|QLocale
name|lc_monetary
decl_stmt|;
DECL|member|lc_messages
name|QLocale
name|lc_messages
decl_stmt|;
DECL|member|lc_messages_var
name|QByteArray
name|lc_messages_var
decl_stmt|;
DECL|member|lc_measurement_var
name|QByteArray
name|lc_measurement_var
decl_stmt|;
DECL|member|uiLanguages
name|QStringList
name|uiLanguages
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|readEnvironment
name|void
name|QSystemLocaleData
operator|::
name|readEnvironment
parameter_list|()
block|{
name|QWriteLocker
name|locker
argument_list|(
operator|&
name|lock
argument_list|)
decl_stmt|;
name|QByteArray
name|all
init|=
name|qgetenv
argument_list|(
literal|"LC_ALL"
argument_list|)
decl_stmt|;
name|QByteArray
name|numeric
init|=
name|all
operator|.
name|isEmpty
argument_list|()
condition|?
name|qgetenv
argument_list|(
literal|"LC_NUMERIC"
argument_list|)
else|:
name|all
decl_stmt|;
name|QByteArray
name|time
init|=
name|all
operator|.
name|isEmpty
argument_list|()
condition|?
name|qgetenv
argument_list|(
literal|"LC_TIME"
argument_list|)
else|:
name|all
decl_stmt|;
name|QByteArray
name|monetary
init|=
name|all
operator|.
name|isEmpty
argument_list|()
condition|?
name|qgetenv
argument_list|(
literal|"LC_MONETARY"
argument_list|)
else|:
name|all
decl_stmt|;
name|lc_messages_var
operator|=
name|all
operator|.
name|isEmpty
argument_list|()
condition|?
name|qgetenv
argument_list|(
literal|"LC_MESSAGES"
argument_list|)
else|:
name|all
expr_stmt|;
name|lc_measurement_var
operator|=
name|all
operator|.
name|isEmpty
argument_list|()
condition|?
name|qgetenv
argument_list|(
literal|"LC_MEASUREMENT"
argument_list|)
else|:
name|all
expr_stmt|;
name|QByteArray
name|lang
init|=
name|qgetenv
argument_list|(
literal|"LANG"
argument_list|)
decl_stmt|;
if|if
condition|(
name|lang
operator|.
name|isEmpty
argument_list|()
condition|)
name|lang
operator|=
name|QByteArray
argument_list|(
literal|"C"
argument_list|)
expr_stmt|;
if|if
condition|(
name|numeric
operator|.
name|isEmpty
argument_list|()
condition|)
name|numeric
operator|=
name|lang
expr_stmt|;
if|if
condition|(
name|time
operator|.
name|isEmpty
argument_list|()
condition|)
name|time
operator|=
name|lang
expr_stmt|;
if|if
condition|(
name|monetary
operator|.
name|isEmpty
argument_list|()
condition|)
name|monetary
operator|=
name|lang
expr_stmt|;
if|if
condition|(
name|lc_messages_var
operator|.
name|isEmpty
argument_list|()
condition|)
name|lc_messages_var
operator|=
name|lang
expr_stmt|;
if|if
condition|(
name|lc_measurement_var
operator|.
name|isEmpty
argument_list|()
condition|)
name|lc_measurement_var
operator|=
name|lang
expr_stmt|;
name|lc_numeric
operator|=
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|numeric
argument_list|)
argument_list|)
expr_stmt|;
name|lc_time
operator|=
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|time
argument_list|)
argument_list|)
expr_stmt|;
name|lc_monetary
operator|=
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|monetary
argument_list|)
argument_list|)
expr_stmt|;
name|lc_messages
operator|=
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|lc_messages_var
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QSystemLocaleData
argument_list|,
argument|qSystemLocaleData
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
end_ifndef
begin_function
DECL|function|fallbackLocale
name|QLocale
name|QSystemLocale
operator|::
name|fallbackLocale
parameter_list|()
specifier|const
block|{
name|QByteArray
name|lang
init|=
name|qgetenv
argument_list|(
literal|"LC_ALL"
argument_list|)
decl_stmt|;
if|if
condition|(
name|lang
operator|.
name|isEmpty
argument_list|()
condition|)
name|lang
operator|=
name|qgetenv
argument_list|(
literal|"LC_MESSAGES"
argument_list|)
expr_stmt|;
if|if
condition|(
name|lang
operator|.
name|isEmpty
argument_list|()
condition|)
name|lang
operator|=
name|qgetenv
argument_list|(
literal|"LANG"
argument_list|)
expr_stmt|;
comment|// if the locale is the "C" locale, then we can return the language we found here:
if|if
condition|(
name|lang
operator|.
name|isEmpty
argument_list|()
operator|||
name|lang
operator|==
name|QByteArray
argument_list|(
literal|"C"
argument_list|)
operator|||
name|lang
operator|==
name|QByteArray
argument_list|(
literal|"POSIX"
argument_list|)
condition|)
return|return
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|lang
argument_list|)
argument_list|)
return|;
comment|// if the locale is not the "C" locale and LANGUAGE is not empty, return
comment|// the first part of LANGUAGE if LANGUAGE is set and has a first part:
name|QByteArray
name|language
init|=
name|qgetenv
argument_list|(
literal|"LANGUAGE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|language
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|language
operator|=
name|language
operator|.
name|split
argument_list|(
literal|':'
argument_list|)
operator|.
name|first
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|language
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|language
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QLocale
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|lang
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|query
name|QVariant
name|QSystemLocale
operator|::
name|query
parameter_list|(
name|QueryType
name|type
parameter_list|,
name|QVariant
name|in
parameter_list|)
specifier|const
block|{
name|QSystemLocaleData
modifier|*
name|d
init|=
name|qSystemLocaleData
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|LocaleChanged
condition|)
block|{
name|d
operator|->
name|readEnvironment
argument_list|()
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
name|QReadLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|lock
argument_list|)
decl_stmt|;
specifier|const
name|QLocale
modifier|&
name|lc_numeric
init|=
name|d
operator|->
name|lc_numeric
decl_stmt|;
specifier|const
name|QLocale
modifier|&
name|lc_time
init|=
name|d
operator|->
name|lc_time
decl_stmt|;
specifier|const
name|QLocale
modifier|&
name|lc_monetary
init|=
name|d
operator|->
name|lc_monetary
decl_stmt|;
specifier|const
name|QLocale
modifier|&
name|lc_messages
init|=
name|d
operator|->
name|lc_messages
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DecimalPoint
case|:
return|return
name|lc_numeric
operator|.
name|decimalPoint
argument_list|()
return|;
case|case
name|GroupSeparator
case|:
return|return
name|lc_numeric
operator|.
name|groupSeparator
argument_list|()
return|;
case|case
name|ZeroDigit
case|:
return|return
name|lc_numeric
operator|.
name|zeroDigit
argument_list|()
return|;
case|case
name|NegativeSign
case|:
return|return
name|lc_numeric
operator|.
name|negativeSign
argument_list|()
return|;
case|case
name|DateFormatLong
case|:
return|return
name|lc_time
operator|.
name|dateFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|DateFormatShort
case|:
return|return
name|lc_time
operator|.
name|dateFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|TimeFormatLong
case|:
return|return
name|lc_time
operator|.
name|timeFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|TimeFormatShort
case|:
return|return
name|lc_time
operator|.
name|timeFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|DayNameLong
case|:
return|return
name|lc_time
operator|.
name|dayName
argument_list|(
name|in
operator|.
name|toInt
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|DayNameShort
case|:
return|return
name|lc_time
operator|.
name|dayName
argument_list|(
name|in
operator|.
name|toInt
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|MonthNameLong
case|:
return|return
name|lc_time
operator|.
name|monthName
argument_list|(
name|in
operator|.
name|toInt
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|MonthNameShort
case|:
return|return
name|lc_time
operator|.
name|monthName
argument_list|(
name|in
operator|.
name|toInt
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|DateToStringLong
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toDate
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|DateToStringShort
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toDate
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|TimeToStringLong
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toTime
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|TimeToStringShort
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toTime
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|DateTimeFormatLong
case|:
return|return
name|lc_time
operator|.
name|dateTimeFormat
argument_list|(
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|DateTimeFormatShort
case|:
return|return
name|lc_time
operator|.
name|dateTimeFormat
argument_list|(
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|DateTimeToStringLong
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toDateTime
argument_list|()
argument_list|,
name|QLocale
operator|::
name|LongFormat
argument_list|)
return|;
case|case
name|DateTimeToStringShort
case|:
return|return
name|lc_time
operator|.
name|toString
argument_list|(
name|in
operator|.
name|toDateTime
argument_list|()
argument_list|,
name|QLocale
operator|::
name|ShortFormat
argument_list|)
return|;
case|case
name|PositiveSign
case|:
return|return
name|lc_numeric
operator|.
name|positiveSign
argument_list|()
return|;
case|case
name|AMText
case|:
return|return
name|lc_time
operator|.
name|amText
argument_list|()
return|;
case|case
name|PMText
case|:
return|return
name|lc_time
operator|.
name|pmText
argument_list|()
return|;
case|case
name|FirstDayOfWeek
case|:
return|return
name|lc_time
operator|.
name|firstDayOfWeek
argument_list|()
return|;
case|case
name|CurrencySymbol
case|:
return|return
name|lc_monetary
operator|.
name|currencySymbol
argument_list|(
name|QLocale
operator|::
name|CurrencySymbolFormat
argument_list|(
name|in
operator|.
name|toUInt
argument_list|()
argument_list|)
argument_list|)
return|;
case|case
name|CurrencyToString
case|:
block|{
switch|switch
condition|(
name|in
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Int
case|:
return|return
name|lc_monetary
operator|.
name|toCurrencyString
argument_list|(
name|in
operator|.
name|toInt
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|UInt
case|:
return|return
name|lc_monetary
operator|.
name|toCurrencyString
argument_list|(
name|in
operator|.
name|toUInt
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|Double
case|:
return|return
name|lc_monetary
operator|.
name|toCurrencyString
argument_list|(
name|in
operator|.
name|toDouble
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|LongLong
case|:
return|return
name|lc_monetary
operator|.
name|toCurrencyString
argument_list|(
name|in
operator|.
name|toLongLong
argument_list|()
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
return|return
name|lc_monetary
operator|.
name|toCurrencyString
argument_list|(
name|in
operator|.
name|toULongLong
argument_list|()
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
case|case
name|MeasurementSystem
case|:
block|{
specifier|const
name|QString
name|meas_locale
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|d
operator|->
name|lc_measurement_var
operator|.
name|constData
argument_list|()
argument_list|,
name|d
operator|->
name|lc_measurement_var
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|meas_locale
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"Metric"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QLocale
operator|::
name|MetricSystem
return|;
if|if
condition|(
name|meas_locale
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"Other"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QLocale
operator|::
name|MetricSystem
return|;
return|return
name|QVariant
argument_list|(
operator|(
name|int
operator|)
name|QLocale
argument_list|(
name|meas_locale
argument_list|)
operator|.
name|measurementSystem
argument_list|()
argument_list|)
return|;
block|}
case|case
name|UILanguages
case|:
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|uiLanguages
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|d
operator|->
name|uiLanguages
return|;
name|QString
name|languages
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qgetenv
argument_list|(
literal|"LANGUAGE"
argument_list|)
argument_list|)
decl_stmt|;
name|QStringList
name|lst
decl_stmt|;
if|if
condition|(
name|languages
operator|.
name|isEmpty
argument_list|()
condition|)
name|lst
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|d
operator|->
name|lc_messages_var
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|lst
operator|=
name|languages
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
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
name|lst
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|name
init|=
name|lst
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QString
name|lang
decl_stmt|,
name|script
decl_stmt|,
name|cntry
decl_stmt|;
if|if
condition|(
name|qt_splitLocaleName
argument_list|(
name|name
argument_list|,
name|lang
argument_list|,
name|script
argument_list|,
name|cntry
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|cntry
operator|.
name|length
argument_list|()
condition|)
name|d
operator|->
name|uiLanguages
operator|.
name|append
argument_list|(
name|lang
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|uiLanguages
operator|.
name|append
argument_list|(
name|lang
operator|%
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
operator|%
name|cntry
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|d
operator|->
name|uiLanguages
operator|.
name|isEmpty
argument_list|()
condition|?
name|QVariant
argument_list|()
else|:
name|QVariant
argument_list|(
name|d
operator|->
name|uiLanguages
argument_list|)
return|;
block|}
case|case
name|StringToStandardQuotation
case|:
return|return
name|lc_messages
operator|.
name|quoteString
argument_list|(
name|in
operator|.
name|value
argument_list|<
name|QStringRef
argument_list|>
argument_list|()
argument_list|)
return|;
case|case
name|StringToAlternateQuotation
case|:
return|return
name|lc_messages
operator|.
name|quoteString
argument_list|(
name|in
operator|.
name|value
argument_list|<
name|QStringRef
argument_list|>
argument_list|()
argument_list|,
name|QLocale
operator|::
name|AlternateQuotation
argument_list|)
return|;
case|case
name|ListToSeparatedString
case|:
return|return
name|lc_messages
operator|.
name|createSeparatedList
argument_list|(
name|in
operator|.
name|value
argument_list|<
name|QStringList
argument_list|>
argument_list|()
argument_list|)
return|;
case|case
name|LocaleChanged
case|:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
default|default:
break|break;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMLOCALE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
