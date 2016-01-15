begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidsystemlocale.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidSystemLocale
name|QAndroidSystemLocale
operator|::
name|QAndroidSystemLocale
parameter_list|()
member_init_list|:
name|m_locale
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|getLocaleFromJava
name|void
name|QAndroidSystemLocale
operator|::
name|getLocaleFromJava
parameter_list|()
specifier|const
block|{
name|QWriteLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|javaLocaleObject
decl_stmt|;
name|QJNIObjectPrivate
name|javaActivity
argument_list|(
name|QtAndroid
operator|::
name|activity
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|javaActivity
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QJNIObjectPrivate
name|resources
init|=
name|javaActivity
operator|.
name|callObjectMethod
argument_list|(
literal|"getResources"
argument_list|,
literal|"()Landroid/content/res/Resources;"
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|configuration
init|=
name|resources
operator|.
name|callObjectMethod
argument_list|(
literal|"getConfiguration"
argument_list|,
literal|"()Landroid/content/res/Configuration;"
argument_list|)
decl_stmt|;
name|javaLocaleObject
operator|=
name|configuration
operator|.
name|getObjectField
argument_list|(
literal|"locale"
argument_list|,
literal|"Ljava/util/Locale;"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|javaLocaleObject
operator|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"java/util/Locale"
argument_list|,
literal|"getDefault"
argument_list|,
literal|"()Ljava/util/Locale;"
argument_list|)
expr_stmt|;
block|}
name|QString
name|languageCode
init|=
name|javaLocaleObject
operator|.
name|callObjectMethod
argument_list|(
literal|"getLanguage"
argument_list|,
literal|"()Ljava/lang/String;"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QString
name|countryCode
init|=
name|javaLocaleObject
operator|.
name|callObjectMethod
argument_list|(
literal|"getCountry"
argument_list|,
literal|"()Ljava/lang/String;"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|m_locale
operator|=
name|QLocale
argument_list|(
name|languageCode
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|countryCode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|query
name|QVariant
name|QAndroidSystemLocale
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
if|if
condition|(
name|type
operator|==
name|LocaleChanged
condition|)
block|{
name|getLocaleFromJava
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
name|m_lock
argument_list|)
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
name|m_locale
operator|.
name|decimalPoint
argument_list|()
return|;
case|case
name|GroupSeparator
case|:
return|return
name|m_locale
operator|.
name|groupSeparator
argument_list|()
return|;
case|case
name|ZeroDigit
case|:
return|return
name|m_locale
operator|.
name|zeroDigit
argument_list|()
return|;
case|case
name|NegativeSign
case|:
return|return
name|m_locale
operator|.
name|negativeSign
argument_list|()
return|;
case|case
name|DateFormatLong
case|:
return|return
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|StandaloneMonthNameLong
case|:
return|return
name|m_locale
operator|.
name|standaloneMonthName
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
name|StandaloneMonthNameShort
case|:
return|return
name|m_locale
operator|.
name|standaloneMonthName
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
operator|.
name|positiveSign
argument_list|()
return|;
case|case
name|AMText
case|:
return|return
name|m_locale
operator|.
name|amText
argument_list|()
return|;
case|case
name|PMText
case|:
return|return
name|m_locale
operator|.
name|pmText
argument_list|()
return|;
case|case
name|FirstDayOfWeek
case|:
return|return
name|m_locale
operator|.
name|firstDayOfWeek
argument_list|()
return|;
case|case
name|CurrencySymbol
case|:
return|return
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|StringToStandardQuotation
case|:
return|return
name|m_locale
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
name|m_locale
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
name|m_locale
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
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"This can't happen."
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
begin_function
DECL|function|fallbackUiLocale
name|QLocale
name|QAndroidSystemLocale
operator|::
name|fallbackUiLocale
parameter_list|()
specifier|const
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
decl_stmt|;
return|return
name|m_locale
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
