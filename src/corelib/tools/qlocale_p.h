begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALE_P_H
end_ifndef
begin_define
DECL|macro|QLOCALE_P_H
define|#
directive|define
name|QLOCALE_P_H
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
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qnumeric.h"
end_include
begin_include
include|#
directive|include
file|"qlocale.h"
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
name|class
name|Q_CORE_EXPORT
name|QSystemLocale
block|{
name|public
label|:
name|QSystemLocale
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QSystemLocale
argument_list|()
expr_stmt|;
struct|struct
name|CurrencyToStringArgument
block|{
name|CurrencyToStringArgument
argument_list|()
block|{ }
name|CurrencyToStringArgument
argument_list|(
specifier|const
name|QVariant
operator|&
name|v
argument_list|,
specifier|const
name|QString
operator|&
name|s
argument_list|)
operator|:
name|value
argument_list|(
name|v
argument_list|)
operator|,
name|symbol
argument_list|(
argument|s
argument_list|)
block|{ }
name|QVariant
name|value
expr_stmt|;
name|QString
name|symbol
decl_stmt|;
block|}
struct|;
enum|enum
name|QueryType
block|{
name|LanguageId
block|,
comment|// uint
name|CountryId
block|,
comment|// uint
name|DecimalPoint
block|,
comment|// QString
name|GroupSeparator
block|,
comment|// QString
name|ZeroDigit
block|,
comment|// QString
name|NegativeSign
block|,
comment|// QString
name|DateFormatLong
block|,
comment|// QString
name|DateFormatShort
block|,
comment|// QString
name|TimeFormatLong
block|,
comment|// QString
name|TimeFormatShort
block|,
comment|// QString
name|DayNameLong
block|,
comment|// QString, in: int
name|DayNameShort
block|,
comment|// QString, in: int
name|MonthNameLong
block|,
comment|// QString, in: int
name|MonthNameShort
block|,
comment|// QString, in: int
name|DateToStringLong
block|,
comment|// QString, in: QDate
name|DateToStringShort
block|,
comment|// QString in: QDate
name|TimeToStringLong
block|,
comment|// QString in: QTime
name|TimeToStringShort
block|,
comment|// QString in: QTime
name|DateTimeFormatLong
block|,
comment|// QString
name|DateTimeFormatShort
block|,
comment|// QString
name|DateTimeToStringLong
block|,
comment|// QString in: QDateTime
name|DateTimeToStringShort
block|,
comment|// QString in: QDateTime
name|MeasurementSystem
block|,
comment|// uint
name|PositiveSign
block|,
comment|// QString
name|AMText
block|,
comment|// QString
name|PMText
block|,
comment|// QString
name|FirstDayOfWeek
block|,
comment|// Qt::DayOfWeek
name|Weekdays
block|,
comment|// QList<Qt::DayOfWeek>
name|CurrencySymbol
block|,
comment|// QString in: CurrencyToStringArgument
name|CurrencyToString
block|,
comment|// QString in: qlonglong, qulonglong or double
name|UILanguages
block|,
comment|// QStringList
name|StringToStandardQuotation
block|,
comment|// QString in: QStringRef to quote
name|StringToAlternateQuotation
block|,
comment|// QString in: QStringRef to quote
name|ScriptId
block|,
comment|// uint
name|ListToSeparatedString
block|,
comment|// QString
name|LocaleChanged
block|,
comment|// system locale changed
name|NativeLanguageName
block|,
comment|// QString
name|NativeCountryName
block|,
comment|// QString
name|StandaloneMonthNameLong
block|,
comment|// QString, in: int
name|StandaloneMonthNameShort
comment|// QString, in: int
block|}
enum|;
name|virtual
name|QVariant
name|query
argument_list|(
name|QueryType
name|type
argument_list|,
name|QVariant
name|in
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QLocale
name|fallbackUiLocale
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSystemLocale
argument_list|(
name|bool
argument_list|)
expr_stmt|;
name|friend
name|class
name|QSystemLocaleSingleton
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_decl_stmt
name|namespace
name|QIcu
block|{
name|QString
name|toUpper
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localeId
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
name|QString
name|toLower
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|localeId
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|QLocaleId
struct|struct
name|QLocaleId
block|{
comment|// bypass constructors
DECL|function|fromIds
specifier|static
specifier|inline
name|QLocaleId
name|fromIds
parameter_list|(
name|ushort
name|language
parameter_list|,
name|ushort
name|script
parameter_list|,
name|ushort
name|country
parameter_list|)
block|{
specifier|const
name|QLocaleId
name|localeId
init|=
block|{
name|language
block|,
name|script
block|,
name|country
block|}
decl_stmt|;
return|return
name|localeId
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|QLocaleId
name|other
operator|)
specifier|const
block|{
return|return
name|language_id
operator|==
name|other
operator|.
name|language_id
operator|&&
name|script_id
operator|==
name|other
operator|.
name|script_id
operator|&&
name|country_id
operator|==
name|other
operator|.
name|country_id
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|QLocaleId
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|QLocaleId
name|withLikelySubtagsAdded
argument_list|()
specifier|const
expr_stmt|;
name|QLocaleId
name|withLikelySubtagsRemoved
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|name
argument_list|(
name|char
name|separator
operator|=
literal|'-'
argument_list|)
decl|const
decl_stmt|;
DECL|member|language_id
DECL|member|script_id
DECL|member|country_id
name|ushort
name|language_id
decl_stmt|,
name|script_id
decl_stmt|,
name|country_id
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QLocaleData
struct|struct
name|QLocaleData
block|{
DECL|member|public
name|public
label|:
specifier|static
specifier|const
name|QLocaleData
modifier|*
name|findLocaleData
argument_list|(
name|QLocale
operator|::
name|Language
name|language
argument_list|,
DECL|member|script
name|QLocale
operator|::
name|Script
name|script
argument_list|,
DECL|member|country
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|QLocaleData
modifier|*
name|c
parameter_list|()
function_decl|;
DECL|enum|DoubleForm
enum|enum
name|DoubleForm
block|{
DECL|enumerator|DFExponent
name|DFExponent
init|=
literal|0
block|,
DECL|enumerator|DFDecimal
name|DFDecimal
block|,
DECL|enumerator|DFSignificantDigits
name|DFSignificantDigits
block|,
DECL|enumerator|_DFMax
name|_DFMax
init|=
name|DFSignificantDigits
block|}
enum|;
DECL|enum|Flags
enum|enum
name|Flags
block|{
DECL|enumerator|NoFlags
name|NoFlags
init|=
literal|0
block|,
DECL|enumerator|Alternate
name|Alternate
init|=
literal|0x01
block|,
DECL|enumerator|ZeroPadded
name|ZeroPadded
init|=
literal|0x02
block|,
DECL|enumerator|LeftAdjusted
name|LeftAdjusted
init|=
literal|0x04
block|,
DECL|enumerator|BlankBeforePositive
name|BlankBeforePositive
init|=
literal|0x08
block|,
DECL|enumerator|AlwaysShowSign
name|AlwaysShowSign
init|=
literal|0x10
block|,
DECL|enumerator|ThousandsGroup
name|ThousandsGroup
init|=
literal|0x20
block|,
DECL|enumerator|CapitalEorX
name|CapitalEorX
init|=
literal|0x40
block|,
DECL|enumerator|ShowBase
name|ShowBase
init|=
literal|0x80
block|,
DECL|enumerator|UppercaseBase
name|UppercaseBase
init|=
literal|0x100
block|,
DECL|enumerator|ForcePoint
name|ForcePoint
init|=
name|Alternate
block|}
enum|;
DECL|enum|GroupSeparatorMode
enum|enum
name|GroupSeparatorMode
block|{
DECL|enumerator|FailOnGroupSeparators
name|FailOnGroupSeparators
block|,
DECL|enumerator|ParseGroupSeparators
name|ParseGroupSeparators
block|}
enum|;
DECL|enum|NumberMode
DECL|enumerator|IntegerMode
DECL|enumerator|DoubleStandardMode
DECL|enumerator|DoubleScientificMode
enum|enum
name|NumberMode
block|{
name|IntegerMode
block|,
name|DoubleStandardMode
block|,
name|DoubleScientificMode
block|}
enum|;
DECL|typedef|CharBuff
typedef|typedef
name|QVarLengthArray
operator|<
name|char
operator|,
literal|256
operator|>
name|CharBuff
expr_stmt|;
specifier|static
name|QString
name|doubleToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
specifier|const
name|QChar
name|minus
parameter_list|,
specifier|const
name|QChar
name|exponent
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|decimal
parameter_list|,
name|double
name|d
parameter_list|,
name|int
name|precision
parameter_list|,
name|DoubleForm
name|form
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
specifier|static
name|QString
name|longLongToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
specifier|const
name|QChar
name|minus
parameter_list|,
name|qint64
name|l
parameter_list|,
name|int
name|precision
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
specifier|static
name|QString
name|unsLongLongToString
parameter_list|(
specifier|const
name|QChar
name|zero
parameter_list|,
specifier|const
name|QChar
name|group
parameter_list|,
specifier|const
name|QChar
name|plus
parameter_list|,
name|quint64
name|l
parameter_list|,
name|int
name|precision
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
name|QString
name|doubleToString
argument_list|(
name|double
name|d
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|DoubleForm
name|form
operator|=
name|DFSignificantDigits
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
name|QString
name|longLongToString
argument_list|(
name|qint64
name|l
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|int
name|base
operator|=
literal|10
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
name|QString
name|unsLongLongToString
argument_list|(
name|quint64
name|l
argument_list|,
name|int
name|precision
operator|=
operator|-
literal|1
argument_list|,
name|int
name|base
operator|=
literal|10
argument_list|,
name|int
name|width
operator|=
operator|-
literal|1
argument_list|,
name|unsigned
name|flags
operator|=
name|NoFlags
argument_list|)
decl|const
decl_stmt|;
comment|// this function is meant to be called with the result of stringToDouble or bytearrayToDouble
DECL|function|convertDoubleToFloat
specifier|static
name|float
name|convertDoubleToFloat
parameter_list|(
name|double
name|d
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
if|if
condition|(
name|qIsInf
argument_list|(
name|d
argument_list|)
condition|)
return|return
name|float
argument_list|(
name|d
argument_list|)
return|;
if|if
condition|(
name|std
operator|::
name|fabs
argument_list|(
name|d
argument_list|)
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|float
operator|>
operator|::
name|max
argument_list|()
condition|)
block|{
if|if
condition|(
name|ok
operator|!=
literal|0
condition|)
operator|*
name|ok
operator|=
name|false
expr_stmt|;
return|return
literal|0.0f
return|;
block|}
return|return
name|float
argument_list|(
name|d
argument_list|)
return|;
block|}
name|double
name|stringToDouble
argument_list|(
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
name|int
name|len
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
name|qint64
name|stringToLongLong
argument_list|(
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
name|int
name|len
argument_list|,
name|int
name|base
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
name|quint64
name|stringToUnsLongLong
argument_list|(
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
name|int
name|len
argument_list|,
name|int
name|base
argument_list|,
name|bool
operator|*
name|ok
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|)
decl|const
decl_stmt|;
comment|// these functions are used in QIntValidator (QtGui)
name|Q_CORE_EXPORT
specifier|static
name|double
name|bytearrayToDouble
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|,
name|bool
modifier|*
name|overflow
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|qint64
name|bytearrayToLongLong
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|,
name|bool
modifier|*
name|overflow
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
specifier|static
name|quint64
name|bytearrayToUnsLongLong
parameter_list|(
specifier|const
name|char
modifier|*
name|num
parameter_list|,
name|int
name|base
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
name|bool
name|numberToCLocale
argument_list|(
specifier|const
name|QChar
operator|*
name|str
argument_list|,
name|int
name|len
argument_list|,
name|GroupSeparatorMode
name|group_sep_mode
argument_list|,
name|CharBuff
operator|*
name|result
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|char
name|digitToCLocale
argument_list|(
name|QChar
name|c
argument_list|)
decl|const
decl_stmt|;
comment|// this function is used in QIntValidator (QtGui)
name|Q_CORE_EXPORT
name|bool
name|validateChars
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|NumberMode
name|numMode
argument_list|,
name|QByteArray
operator|*
name|buff
argument_list|,
name|int
name|decDigits
operator|=
operator|-
literal|1
argument_list|,
name|bool
name|rejectGroupSeparators
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
DECL|member|public
name|public
label|:
DECL|member|m_script_id
DECL|member|m_country_id
name|quint16
name|m_language_id
decl_stmt|,
name|m_script_id
decl_stmt|,
name|m_country_id
decl_stmt|;
DECL|member|m_decimal
DECL|member|m_group
DECL|member|m_list
DECL|member|m_percent
DECL|member|m_zero
DECL|member|m_minus
DECL|member|m_plus
DECL|member|m_exponential
name|quint16
name|m_decimal
decl_stmt|,
name|m_group
decl_stmt|,
name|m_list
decl_stmt|,
name|m_percent
decl_stmt|,
name|m_zero
decl_stmt|,
name|m_minus
decl_stmt|,
name|m_plus
decl_stmt|,
name|m_exponential
decl_stmt|;
DECL|member|m_quotation_start
DECL|member|m_quotation_end
name|quint16
name|m_quotation_start
decl_stmt|,
name|m_quotation_end
decl_stmt|;
DECL|member|m_alternate_quotation_start
DECL|member|m_alternate_quotation_end
name|quint16
name|m_alternate_quotation_start
decl_stmt|,
name|m_alternate_quotation_end
decl_stmt|;
DECL|member|m_list_pattern_part_start_idx
DECL|member|m_list_pattern_part_start_size
name|quint16
name|m_list_pattern_part_start_idx
decl_stmt|,
name|m_list_pattern_part_start_size
decl_stmt|;
DECL|member|m_list_pattern_part_mid_idx
DECL|member|m_list_pattern_part_mid_size
name|quint16
name|m_list_pattern_part_mid_idx
decl_stmt|,
name|m_list_pattern_part_mid_size
decl_stmt|;
DECL|member|m_list_pattern_part_end_idx
DECL|member|m_list_pattern_part_end_size
name|quint16
name|m_list_pattern_part_end_idx
decl_stmt|,
name|m_list_pattern_part_end_size
decl_stmt|;
DECL|member|m_list_pattern_part_two_idx
DECL|member|m_list_pattern_part_two_size
name|quint16
name|m_list_pattern_part_two_idx
decl_stmt|,
name|m_list_pattern_part_two_size
decl_stmt|;
DECL|member|m_short_date_format_idx
DECL|member|m_short_date_format_size
name|quint16
name|m_short_date_format_idx
decl_stmt|,
name|m_short_date_format_size
decl_stmt|;
DECL|member|m_long_date_format_idx
DECL|member|m_long_date_format_size
name|quint16
name|m_long_date_format_idx
decl_stmt|,
name|m_long_date_format_size
decl_stmt|;
DECL|member|m_short_time_format_idx
DECL|member|m_short_time_format_size
name|quint16
name|m_short_time_format_idx
decl_stmt|,
name|m_short_time_format_size
decl_stmt|;
DECL|member|m_long_time_format_idx
DECL|member|m_long_time_format_size
name|quint16
name|m_long_time_format_idx
decl_stmt|,
name|m_long_time_format_size
decl_stmt|;
DECL|member|m_standalone_short_month_names_idx
DECL|member|m_standalone_short_month_names_size
name|quint16
name|m_standalone_short_month_names_idx
decl_stmt|,
name|m_standalone_short_month_names_size
decl_stmt|;
DECL|member|m_standalone_long_month_names_idx
DECL|member|m_standalone_long_month_names_size
name|quint16
name|m_standalone_long_month_names_idx
decl_stmt|,
name|m_standalone_long_month_names_size
decl_stmt|;
DECL|member|m_standalone_narrow_month_names_idx
DECL|member|m_standalone_narrow_month_names_size
name|quint16
name|m_standalone_narrow_month_names_idx
decl_stmt|,
name|m_standalone_narrow_month_names_size
decl_stmt|;
DECL|member|m_short_month_names_idx
DECL|member|m_short_month_names_size
name|quint16
name|m_short_month_names_idx
decl_stmt|,
name|m_short_month_names_size
decl_stmt|;
DECL|member|m_long_month_names_idx
DECL|member|m_long_month_names_size
name|quint16
name|m_long_month_names_idx
decl_stmt|,
name|m_long_month_names_size
decl_stmt|;
DECL|member|m_narrow_month_names_idx
DECL|member|m_narrow_month_names_size
name|quint16
name|m_narrow_month_names_idx
decl_stmt|,
name|m_narrow_month_names_size
decl_stmt|;
DECL|member|m_standalone_short_day_names_idx
DECL|member|m_standalone_short_day_names_size
name|quint16
name|m_standalone_short_day_names_idx
decl_stmt|,
name|m_standalone_short_day_names_size
decl_stmt|;
DECL|member|m_standalone_long_day_names_idx
DECL|member|m_standalone_long_day_names_size
name|quint16
name|m_standalone_long_day_names_idx
decl_stmt|,
name|m_standalone_long_day_names_size
decl_stmt|;
DECL|member|m_standalone_narrow_day_names_idx
DECL|member|m_standalone_narrow_day_names_size
name|quint16
name|m_standalone_narrow_day_names_idx
decl_stmt|,
name|m_standalone_narrow_day_names_size
decl_stmt|;
DECL|member|m_short_day_names_idx
DECL|member|m_short_day_names_size
name|quint16
name|m_short_day_names_idx
decl_stmt|,
name|m_short_day_names_size
decl_stmt|;
DECL|member|m_long_day_names_idx
DECL|member|m_long_day_names_size
name|quint16
name|m_long_day_names_idx
decl_stmt|,
name|m_long_day_names_size
decl_stmt|;
DECL|member|m_narrow_day_names_idx
DECL|member|m_narrow_day_names_size
name|quint16
name|m_narrow_day_names_idx
decl_stmt|,
name|m_narrow_day_names_size
decl_stmt|;
DECL|member|m_am_idx
DECL|member|m_am_size
name|quint16
name|m_am_idx
decl_stmt|,
name|m_am_size
decl_stmt|;
DECL|member|m_pm_idx
DECL|member|m_pm_size
name|quint16
name|m_pm_idx
decl_stmt|,
name|m_pm_size
decl_stmt|;
DECL|member|m_currency_iso_code
name|char
name|m_currency_iso_code
index|[
literal|3
index|]
decl_stmt|;
DECL|member|m_currency_symbol_idx
DECL|member|m_currency_symbol_size
name|quint16
name|m_currency_symbol_idx
decl_stmt|,
name|m_currency_symbol_size
decl_stmt|;
DECL|member|m_currency_display_name_idx
DECL|member|m_currency_display_name_size
name|quint16
name|m_currency_display_name_idx
decl_stmt|,
name|m_currency_display_name_size
decl_stmt|;
DECL|member|m_currency_format_idx
DECL|member|m_currency_format_size
name|quint8
name|m_currency_format_idx
decl_stmt|,
name|m_currency_format_size
decl_stmt|;
DECL|member|m_currency_negative_format_idx
DECL|member|m_currency_negative_format_size
name|quint8
name|m_currency_negative_format_idx
decl_stmt|,
name|m_currency_negative_format_size
decl_stmt|;
DECL|member|m_language_endonym_idx
DECL|member|m_language_endonym_size
name|quint16
name|m_language_endonym_idx
decl_stmt|,
name|m_language_endonym_size
decl_stmt|;
DECL|member|m_country_endonym_idx
DECL|member|m_country_endonym_size
name|quint16
name|m_country_endonym_idx
decl_stmt|,
name|m_country_endonym_size
decl_stmt|;
DECL|member|m_currency_digits
name|quint16
name|m_currency_digits
range|:
literal|2
decl_stmt|;
DECL|member|m_currency_rounding
name|quint16
name|m_currency_rounding
range|:
literal|3
decl_stmt|;
DECL|member|m_first_day_of_week
name|quint16
name|m_first_day_of_week
range|:
literal|3
decl_stmt|;
DECL|member|m_weekend_start
name|quint16
name|m_weekend_start
range|:
literal|3
decl_stmt|;
DECL|member|m_weekend_end
name|quint16
name|m_weekend_end
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLocalePrivate
block|{
name|public
label|:
specifier|static
name|QLocalePrivate
modifier|*
name|create
parameter_list|(
specifier|const
name|QLocaleData
modifier|*
name|data
parameter_list|,
name|int
name|numberOptions
init|=
literal|0
parameter_list|)
block|{
name|QLocalePrivate
modifier|*
name|retval
init|=
name|new
name|QLocalePrivate
decl_stmt|;
name|retval
operator|->
name|m_data
operator|=
name|data
expr_stmt|;
name|retval
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|retval
operator|->
name|m_numberOptions
operator|=
name|numberOptions
expr_stmt|;
return|return
name|retval
return|;
block|}
name|QChar
name|decimal
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_decimal
argument_list|)
return|;
block|}
name|QChar
name|group
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_group
argument_list|)
return|;
block|}
name|QChar
name|list
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_list
argument_list|)
return|;
block|}
name|QChar
name|percent
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_percent
argument_list|)
return|;
block|}
name|QChar
name|zero
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_zero
argument_list|)
return|;
block|}
name|QChar
name|plus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_plus
argument_list|)
return|;
block|}
name|QChar
name|minus
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_minus
argument_list|)
return|;
block|}
name|QChar
name|exponential
argument_list|()
specifier|const
block|{
return|return
name|QChar
argument_list|(
name|m_data
operator|->
name|m_exponential
argument_list|)
return|;
block|}
name|quint16
name|languageId
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|->
name|m_language_id
return|;
block|}
name|quint16
name|countryId
argument_list|()
specifier|const
block|{
return|return
name|m_data
operator|->
name|m_country_id
return|;
block|}
name|QByteArray
name|bcp47Name
argument_list|(
name|char
name|separator
operator|=
literal|'-'
argument_list|)
decl|const
decl_stmt|;
comment|// ### QByteArray::fromRawData would be more optimal
specifier|inline
name|QString
name|languageCode
argument_list|()
specifier|const
block|{
return|return
name|QLocalePrivate
operator|::
name|languageToCode
argument_list|(
name|QLocale
operator|::
name|Language
argument_list|(
name|m_data
operator|->
name|m_language_id
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|scriptCode
argument_list|()
specifier|const
block|{
return|return
name|QLocalePrivate
operator|::
name|scriptToCode
argument_list|(
name|QLocale
operator|::
name|Script
argument_list|(
name|m_data
operator|->
name|m_script_id
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QString
name|countryCode
argument_list|()
specifier|const
block|{
return|return
name|QLocalePrivate
operator|::
name|countryToCode
argument_list|(
name|QLocale
operator|::
name|Country
argument_list|(
name|m_data
operator|->
name|m_country_id
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|QString
name|languageToCode
argument_list|(
name|QLocale
operator|::
name|Language
name|language
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|scriptToCode
argument_list|(
name|QLocale
operator|::
name|Script
name|script
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|countryToCode
argument_list|(
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
specifier|static
name|QLocale
operator|::
name|Language
name|codeToLanguage
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|QLocale
operator|::
name|Script
name|codeToScript
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|QLocale
operator|::
name|Country
name|codeToCountry
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
expr_stmt|;
specifier|static
name|void
name|getLangAndCountry
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QLocale
operator|::
name|Language
operator|&
name|lang
argument_list|,
name|QLocale
operator|::
name|Script
operator|&
name|script
argument_list|,
name|QLocale
operator|::
name|Country
operator|&
name|cntry
argument_list|)
decl_stmt|;
name|QLocale
operator|::
name|MeasurementSystem
name|measurementSystem
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|void
name|updateSystemPrivate
parameter_list|()
function_decl|;
name|QString
name|dateTimeToString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
specifier|const
name|QDateTime
operator|&
name|datetime
argument_list|,
specifier|const
name|QDate
operator|&
name|dateOnly
argument_list|,
specifier|const
name|QTime
operator|&
name|timeOnly
argument_list|,
specifier|const
name|QLocale
operator|*
name|q
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QLocaleData
modifier|*
name|m_data
decl_stmt|;
name|QBasicAtomicInt
name|ref
decl_stmt|;
name|quint16
name|m_numberOptions
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
operator|>
DECL|function|clone
specifier|inline
name|QLocalePrivate
operator|*
name|QSharedDataPointer
operator|<
name|QLocalePrivate
operator|>
operator|::
name|clone
argument_list|()
block|{
comment|// cannot use QLocalePrivate's copy constructor
comment|// since it is deleted in C++11
return|return
name|QLocalePrivate
operator|::
name|create
argument_list|(
name|d
operator|->
name|m_data
argument_list|,
name|d
operator|->
name|m_numberOptions
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|digitToCLocale
specifier|inline
name|char
name|QLocaleData
operator|::
name|digitToCLocale
argument_list|(
argument|QChar in
argument_list|)
specifier|const
block|{
specifier|const
name|ushort
name|tenUnicode
operator|=
name|m_zero
operator|+
literal|10
block|;
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
name|m_zero
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<
name|tenUnicode
condition|)
return|return
literal|'0'
operator|+
name|in
operator|.
name|unicode
argument_list|()
operator|-
name|m_zero
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|in
operator|.
name|unicode
argument_list|()
operator|>=
literal|'0'
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|<=
literal|'9'
condition|)
return|return
name|in
operator|.
name|toLatin1
argument_list|()
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|m_plus
operator|||
name|in
operator|==
name|QLatin1Char
argument_list|(
literal|'+'
argument_list|)
condition|)
return|return
literal|'+'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|m_minus
operator|||
name|in
operator|==
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
operator|||
name|in
operator|==
name|QChar
argument_list|(
literal|0x2212
argument_list|)
condition|)
return|return
literal|'-'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|m_decimal
condition|)
return|return
literal|'.'
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|m_group
condition|)
return|return
literal|','
return|;
end_if
begin_if
if|if
condition|(
name|in
operator|==
name|m_exponential
operator|||
name|in
operator|==
name|QChar
operator|::
name|toUpper
argument_list|(
name|m_exponential
argument_list|)
condition|)
return|return
literal|'e'
return|;
end_if
begin_comment
comment|// In several languages group() is the char 0xA0, which looks like a space.
end_comment
begin_comment
comment|// People use a regular space instead of it and complain it doesn't work.
end_comment
begin_if
if|if
condition|(
name|m_group
operator|==
literal|0xA0
operator|&&
name|in
operator|.
name|unicode
argument_list|()
operator|==
literal|' '
condition|)
return|return
literal|','
return|;
end_if
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  QString
name|qt_readEscapedFormatString
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
name|int
operator|*
name|idx
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|qt_splitLocaleName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QString
modifier|&
name|lang
parameter_list|,
name|QString
modifier|&
name|script
parameter_list|,
name|QString
modifier|&
name|cntry
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|qt_repeatCount
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_enum
DECL|enumerator|AsciiSpaceMask
enum|enum
block|{
name|AsciiSpaceMask
init|=
operator|(
literal|1
operator|<<
operator|(
literal|' '
operator|-
literal|1
operator|)
operator|)
operator||
operator|(
literal|1
operator|<<
operator|(
literal|'\t'
operator|-
literal|1
operator|)
operator|)
operator||
comment|// 9: HT - horizontal tab
operator|(
literal|1
operator|<<
operator|(
literal|'\n'
operator|-
literal|1
operator|)
operator|)
operator||
comment|// 10: LF - line feed
operator|(
literal|1
operator|<<
operator|(
literal|'\v'
operator|-
literal|1
operator|)
operator|)
operator||
comment|// 11: VT - vertical tab
operator|(
literal|1
operator|<<
operator|(
literal|'\f'
operator|-
literal|1
operator|)
operator|)
operator||
comment|// 12: FF - form feed
operator|(
literal|1
operator|<<
operator|(
literal|'\r'
operator|-
literal|1
operator|)
operator|)
block|}
enum|;
end_enum
begin_comment
comment|// 13: CR - carriage return
end_comment
begin_function
DECL|function|ascii_isspace
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|ascii_isspace
parameter_list|(
name|uchar
name|c
parameter_list|)
block|{
return|return
name|c
operator|>=
literal|1U
operator|&&
name|c
operator|<=
literal|32U
operator|&&
operator|(
name|uint
argument_list|(
name|AsciiSpaceMask
argument_list|)
operator|>>
name|uint
argument_list|(
name|c
operator|-
literal|1
argument_list|)
operator|)
operator|&
literal|1U
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CONSTEXPR
argument_list|)
end_if
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|' '
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|'\t'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|'\v'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|'\f'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|ascii_isspace
argument_list|(
literal|'\r'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
literal|'\0'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
literal|'\a'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
literal|'a'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
literal|'\177'
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
name|uchar
argument_list|(
literal|'\200'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
name|uchar
argument_list|(
literal|'\xA0'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|ascii_isspace
argument_list|(
name|uchar
argument_list|(
literal|'\377'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QStringRef
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QList
operator|<
name|Qt
operator|::
name|DayOfWeek
operator|>
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMLOCALE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSystemLocale
operator|::
name|CurrencyToStringArgument
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALE_P_H
end_comment
end_unit
