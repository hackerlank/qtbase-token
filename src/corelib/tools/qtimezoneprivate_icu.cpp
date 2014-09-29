begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtimezone.h"
end_include
begin_include
include|#
directive|include
file|"qtimezoneprivate_p.h"
end_include
begin_include
include|#
directive|include
file|<unicode/ucal.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*     Private      ICU implementation */
comment|// ICU utilities
comment|// Convert TimeType and NameType into ICU UCalendarDisplayNameType
DECL|function|ucalDisplayNameType
specifier|static
name|UCalendarDisplayNameType
name|ucalDisplayNameType
parameter_list|(
name|QTimeZone
operator|::
name|TimeType
name|timeType
parameter_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
parameter_list|)
block|{
comment|// TODO ICU C UCalendarDisplayNameType does not support full set of C++ TimeZone::EDisplayType
switch|switch
condition|(
name|nameType
condition|)
block|{
case|case
name|QTimeZone
operator|::
name|ShortName
case|:
case|case
name|QTimeZone
operator|::
name|OffsetName
case|:
if|if
condition|(
name|timeType
operator|==
name|QTimeZone
operator|::
name|DaylightTime
condition|)
return|return
name|UCAL_SHORT_DST
return|;
comment|// Includes GenericTime
return|return
name|UCAL_SHORT_STANDARD
return|;
case|case
name|QTimeZone
operator|::
name|DefaultName
case|:
case|case
name|QTimeZone
operator|::
name|LongName
case|:
if|if
condition|(
name|timeType
operator|==
name|QTimeZone
operator|::
name|DaylightTime
condition|)
return|return
name|UCAL_DST
return|;
comment|// Includes GenericTime
return|return
name|UCAL_STANDARD
return|;
block|}
return|return
name|UCAL_STANDARD
return|;
block|}
end_function
begin_comment
comment|// Qt wrapper around ucal_getDefaultTimeZone()
end_comment
begin_function
DECL|function|ucalDefaultTimeZoneId
specifier|static
name|QByteArray
name|ucalDefaultTimeZoneId
parameter_list|()
block|{
name|int32_t
name|size
init|=
literal|30
decl_stmt|;
name|QString
name|result
argument_list|(
name|size
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
comment|// size = ucal_getDefaultTimeZone(result, resultLength, status)
name|size
operator|=
name|ucal_getDefaultTimeZone
argument_list|(
cast|reinterpret_cast
argument_list|<
name|UChar
operator|*
argument_list|>
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|size
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|// If overflow, then resize and retry
if|if
condition|(
name|status
operator|==
name|U_BUFFER_OVERFLOW_ERROR
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|size
operator|=
name|ucal_getDefaultTimeZone
argument_list|(
cast|reinterpret_cast
argument_list|<
name|UChar
operator|*
argument_list|>
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|size
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
comment|// If successful on first or second go, resize and return
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
name|result
operator|.
name|toUtf8
argument_list|()
return|;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Qt wrapper around ucal_getTimeZoneDisplayName()
end_comment
begin_function
DECL|function|ucalTimeZoneDisplayName
specifier|static
name|QString
name|ucalTimeZoneDisplayName
parameter_list|(
name|UCalendar
modifier|*
name|ucal
parameter_list|,
name|QTimeZone
operator|::
name|TimeType
name|timeType
parameter_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
parameter_list|,
specifier|const
name|QString
modifier|&
name|localeCode
parameter_list|)
block|{
name|int32_t
name|size
init|=
literal|50
decl_stmt|;
name|QString
name|result
argument_list|(
name|size
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
comment|// size = ucal_getTimeZoneDisplayName(cal, type, locale, result, resultLength, status)
name|size
operator|=
name|ucal_getTimeZoneDisplayName
argument_list|(
name|ucal
argument_list|,
name|ucalDisplayNameType
argument_list|(
name|timeType
argument_list|,
name|nameType
argument_list|)
argument_list|,
name|localeCode
operator|.
name|toUtf8
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|UChar
operator|*
argument_list|>
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|size
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|// If overflow, then resize and retry
if|if
condition|(
name|status
operator|==
name|U_BUFFER_OVERFLOW_ERROR
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|size
operator|=
name|ucal_getTimeZoneDisplayName
argument_list|(
name|ucal
argument_list|,
name|ucalDisplayNameType
argument_list|(
name|timeType
argument_list|,
name|nameType
argument_list|)
argument_list|,
name|localeCode
operator|.
name|toUtf8
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|UChar
operator|*
argument_list|>
argument_list|(
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|size
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
comment|// If successful on first or second go, resize and return
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Qt wrapper around ucal_get() for offsets
end_comment
begin_function
DECL|function|ucalOffsetsAtTime
specifier|static
name|bool
name|ucalOffsetsAtTime
parameter_list|(
name|UCalendar
modifier|*
name|m_ucal
parameter_list|,
name|qint64
name|atMSecsSinceEpoch
parameter_list|,
name|int
modifier|*
name|utcOffset
parameter_list|,
name|int
modifier|*
name|dstOffset
parameter_list|)
block|{
operator|*
name|utcOffset
operator|=
literal|0
expr_stmt|;
operator|*
name|dstOffset
operator|=
literal|0
expr_stmt|;
comment|// Clone the ucal so we don't change the shared object
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UCalendar
modifier|*
name|ucal
init|=
name|ucal_clone
argument_list|(
name|m_ucal
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// Set the date to find the offset for
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucal_setMillis
argument_list|(
name|ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|int32_t
name|utc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
comment|// Returns msecs
name|utc
operator|=
name|ucal_get
argument_list|(
name|ucal
argument_list|,
name|UCAL_ZONE_OFFSET
argument_list|,
operator|&
name|status
argument_list|)
operator|/
literal|1000
expr_stmt|;
block|}
name|int32_t
name|dst
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
comment|// Returns msecs
name|dst
operator|=
name|ucal_get
argument_list|(
name|ucal
argument_list|,
name|UCAL_DST_OFFSET
argument_list|,
operator|&
name|status
argument_list|)
operator|/
literal|1000
expr_stmt|;
block|}
name|ucal_close
argument_list|(
name|ucal
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
operator|*
name|utcOffset
operator|=
name|utc
expr_stmt|;
operator|*
name|dstOffset
operator|=
name|dst
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// ICU Draft api in v50, should be stable in ICU v51. Available in C++ api from ICU v3.8
end_comment
begin_if
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|50
end_if
begin_comment
comment|// Qt wrapper around qt_ucal_getTimeZoneTransitionDate& ucal_get
end_comment
begin_function
DECL|function|ucalTimeZoneTransition
specifier|static
name|QTimeZonePrivate
operator|::
name|Data
name|ucalTimeZoneTransition
parameter_list|(
name|UCalendar
modifier|*
name|m_ucal
parameter_list|,
name|UTimeZoneTransitionType
name|type
parameter_list|,
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
block|{
name|QTimeZonePrivate
operator|::
name|Data
name|tran
init|=
name|QTimeZonePrivate
operator|::
name|invalidData
argument_list|()
decl_stmt|;
comment|// Clone the ucal so we don't change the shared object
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UCalendar
modifier|*
name|ucal
init|=
name|ucal_clone
argument_list|(
name|m_ucal
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
return|return
name|tran
return|;
comment|// Set the date to find the transition for
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucal_setMillis
argument_list|(
name|ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|// Find the transition time
name|UDate
name|tranMSecs
init|=
literal|0
decl_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|bool
name|ok
init|=
name|ucal_getTimeZoneTransitionDate
argument_list|(
name|ucal
argument_list|,
name|type
argument_list|,
operator|&
name|tranMSecs
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
comment|// Set the transition time to find the offsets for
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
operator|&&
name|ok
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucal_setMillis
argument_list|(
name|ucal
argument_list|,
name|tranMSecs
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
name|int32_t
name|utc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
operator|&&
name|ok
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|utc
operator|=
name|ucal_get
argument_list|(
name|ucal
argument_list|,
name|UCAL_ZONE_OFFSET
argument_list|,
operator|&
name|status
argument_list|)
operator|/
literal|1000
expr_stmt|;
block|}
name|int32_t
name|dst
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
operator|&&
name|ok
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|dst
operator|=
name|ucal_get
argument_list|(
name|ucal
argument_list|,
name|UCAL_DST_OFFSET
argument_list|,
operator|&
name|status
argument_list|)
operator|/
literal|1000
expr_stmt|;
block|}
name|ucal_close
argument_list|(
name|ucal
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
operator|||
operator|!
name|ok
condition|)
return|return
name|tran
return|;
name|tran
operator|.
name|atMSecsSinceEpoch
operator|=
name|tranMSecs
expr_stmt|;
name|tran
operator|.
name|offsetFromUtc
operator|=
name|utc
operator|+
name|dst
expr_stmt|;
name|tran
operator|.
name|standardTimeOffset
operator|=
name|utc
expr_stmt|;
name|tran
operator|.
name|daylightTimeOffset
operator|=
name|dst
expr_stmt|;
comment|// TODO No ICU API, use short name instead
if|if
condition|(
name|dst
operator|==
literal|0
condition|)
name|tran
operator|.
name|abbreviation
operator|=
name|ucalTimeZoneDisplayName
argument_list|(
name|m_ucal
argument_list|,
name|QTimeZone
operator|::
name|StandardTime
argument_list|,
name|QTimeZone
operator|::
name|ShortName
argument_list|,
name|QLocale
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|tran
operator|.
name|abbreviation
operator|=
name|ucalTimeZoneDisplayName
argument_list|(
name|m_ucal
argument_list|,
name|QTimeZone
operator|::
name|DaylightTime
argument_list|,
name|QTimeZone
operator|::
name|ShortName
argument_list|,
name|QLocale
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|tran
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// U_ICU_VERSION_SHORT
end_comment
begin_comment
comment|// Convert a uenum to a QList<QByteArray>
end_comment
begin_function
DECL|function|uenumToIdSet
specifier|static
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|uenumToIdSet
parameter_list|(
name|UEnumeration
modifier|*
name|uenum
parameter_list|)
block|{
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|set
decl_stmt|;
name|int32_t
name|size
init|=
literal|0
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
comment|// TODO Perhaps use uenum_unext instead?
name|QByteArray
name|result
init|=
name|uenum_next
argument_list|(
name|uenum
argument_list|,
operator|&
name|size
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
while|while
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
operator|&&
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|set
operator|<<
name|result
expr_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|result
operator|=
name|uenum_next
argument_list|(
name|uenum
argument_list|,
operator|&
name|size
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
return|return
name|set
return|;
block|}
end_function
begin_comment
comment|// Qt wrapper around ucal_getDSTSavings()
end_comment
begin_function
DECL|function|ucalDaylightOffset
specifier|static
name|int
name|ucalDaylightOffset
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
specifier|const
name|int32_t
name|dstMSecs
init|=
name|ucal_getDSTSavings
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|UChar
operator|*
argument_list|>
argument_list|(
name|id
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
return|return
operator|(
name|dstMSecs
operator|/
literal|1000
operator|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|// Create the system default time zone
end_comment
begin_constructor
DECL|function|QIcuTimeZonePrivate
name|QIcuTimeZonePrivate
operator|::
name|QIcuTimeZonePrivate
parameter_list|()
member_init_list|:
name|m_ucal
argument_list|(
literal|0
argument_list|)
block|{
comment|// TODO No ICU C API to obtain sysem tz, assume default hasn't been changed
name|init
argument_list|(
name|ucalDefaultTimeZoneId
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|// Create a named time zone
end_comment
begin_constructor
DECL|function|QIcuTimeZonePrivate
name|QIcuTimeZonePrivate
operator|::
name|QIcuTimeZonePrivate
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
member_init_list|:
name|m_ucal
argument_list|(
literal|0
argument_list|)
block|{
comment|// Need to check validity here as ICu will create a GMT tz if name is invalid
if|if
condition|(
name|availableTimeZoneIds
argument_list|()
operator|.
name|contains
argument_list|(
name|ianaId
argument_list|)
condition|)
name|init
argument_list|(
name|ianaId
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QIcuTimeZonePrivate
name|QIcuTimeZonePrivate
operator|::
name|QIcuTimeZonePrivate
parameter_list|(
specifier|const
name|QIcuTimeZonePrivate
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QTimeZonePrivate
argument_list|(
name|other
argument_list|)
member_init_list|,
name|m_ucal
argument_list|(
literal|0
argument_list|)
block|{
comment|// Clone the ucal so we don't close the shared object
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|m_ucal
operator|=
name|ucal_clone
argument_list|(
name|other
operator|.
name|m_ucal
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|m_id
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_ucal
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QIcuTimeZonePrivate
name|QIcuTimeZonePrivate
operator|::
name|~
name|QIcuTimeZonePrivate
parameter_list|()
block|{
name|ucal_close
argument_list|(
name|m_ucal
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|clone
name|QTimeZonePrivate
modifier|*
name|QIcuTimeZonePrivate
operator|::
name|clone
parameter_list|()
block|{
return|return
operator|new
name|QIcuTimeZonePrivate
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QIcuTimeZonePrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
block|{
name|m_id
operator|=
name|ianaId
expr_stmt|;
specifier|const
name|QString
name|id
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|m_id
argument_list|)
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
comment|//TODO Use UCAL_GREGORIAN for now to match QLocale, change to UCAL_DEFAULT once full ICU support
name|m_ucal
operator|=
name|ucal_open
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|UChar
operator|*
argument_list|>
argument_list|(
name|id
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|id
operator|.
name|size
argument_list|()
argument_list|,
name|QLocale
argument_list|()
operator|.
name|name
argument_list|()
operator|.
name|toUtf8
argument_list|()
argument_list|,
name|UCAL_GREGORIAN
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|m_id
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_ucal
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|displayName
name|QString
name|QIcuTimeZonePrivate
operator|::
name|displayName
parameter_list|(
name|QTimeZone
operator|::
name|TimeType
name|timeType
parameter_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
parameter_list|,
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
specifier|const
block|{
comment|// Return standard offset format name as ICU C api doesn't support it yet
if|if
condition|(
name|nameType
operator|==
name|QTimeZone
operator|::
name|OffsetName
condition|)
block|{
specifier|const
name|Data
name|nowData
init|=
name|data
argument_list|(
name|QDateTime
operator|::
name|currentDateTimeUtc
argument_list|()
operator|.
name|toMSecsSinceEpoch
argument_list|()
argument_list|)
decl_stmt|;
comment|// We can't use transitions reliably to find out right dst offset
comment|// Instead use dst offset api to try get it if needed
if|if
condition|(
name|timeType
operator|==
name|QTimeZone
operator|::
name|DaylightTime
condition|)
return|return
name|isoOffsetFormat
argument_list|(
name|nowData
operator|.
name|standardTimeOffset
operator|+
name|ucalDaylightOffset
argument_list|(
name|m_id
argument_list|)
argument_list|)
return|;
else|else
return|return
name|isoOffsetFormat
argument_list|(
name|nowData
operator|.
name|standardTimeOffset
argument_list|)
return|;
block|}
return|return
name|ucalTimeZoneDisplayName
argument_list|(
name|m_ucal
argument_list|,
name|timeType
argument_list|,
name|nameType
argument_list|,
name|locale
operator|.
name|name
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|abbreviation
name|QString
name|QIcuTimeZonePrivate
operator|::
name|abbreviation
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// TODO No ICU API, use short name instead
if|if
condition|(
name|isDaylightTime
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
condition|)
return|return
name|displayName
argument_list|(
name|QTimeZone
operator|::
name|DaylightTime
argument_list|,
name|QTimeZone
operator|::
name|ShortName
argument_list|,
name|QString
argument_list|()
argument_list|)
return|;
else|else
return|return
name|displayName
argument_list|(
name|QTimeZone
operator|::
name|StandardTime
argument_list|,
name|QTimeZone
operator|::
name|ShortName
argument_list|,
name|QString
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|offsetFromUtc
name|int
name|QIcuTimeZonePrivate
operator|::
name|offsetFromUtc
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
name|int
name|stdOffset
init|=
literal|0
decl_stmt|;
name|int
name|dstOffset
init|=
literal|0
decl_stmt|;
name|ucalOffsetsAtTime
argument_list|(
name|m_ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|stdOffset
argument_list|,
operator|&
name|dstOffset
argument_list|)
expr_stmt|;
return|return
name|stdOffset
operator|+
name|dstOffset
return|;
block|}
end_function
begin_function
DECL|function|standardTimeOffset
name|int
name|QIcuTimeZonePrivate
operator|::
name|standardTimeOffset
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
name|int
name|stdOffset
init|=
literal|0
decl_stmt|;
name|int
name|dstOffset
init|=
literal|0
decl_stmt|;
name|ucalOffsetsAtTime
argument_list|(
name|m_ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|stdOffset
argument_list|,
operator|&
name|dstOffset
argument_list|)
expr_stmt|;
return|return
name|stdOffset
return|;
block|}
end_function
begin_function
DECL|function|daylightTimeOffset
name|int
name|QIcuTimeZonePrivate
operator|::
name|daylightTimeOffset
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
name|int
name|stdOffset
init|=
literal|0
decl_stmt|;
name|int
name|dstOffset
init|=
literal|0
decl_stmt|;
name|ucalOffsetsAtTime
argument_list|(
name|m_ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|stdOffset
argument_list|,
operator|&
name|dstOffset
argument_list|)
expr_stmt|;
return|return
name|dstOffset
return|;
block|}
end_function
begin_function
DECL|function|hasDaylightTime
name|bool
name|QIcuTimeZonePrivate
operator|::
name|hasDaylightTime
parameter_list|()
specifier|const
block|{
comment|// TODO No direct ICU C api, work-around below not reliable?  Find a better way?
return|return
operator|(
name|ucalDaylightOffset
argument_list|(
name|m_id
argument_list|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|isDaylightTime
name|bool
name|QIcuTimeZonePrivate
operator|::
name|isDaylightTime
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// Clone the ucal so we don't change the shared object
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UCalendar
modifier|*
name|ucal
init|=
name|ucal_clone
argument_list|(
name|m_ucal
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// Set the date to find the offset for
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucal_setMillis
argument_list|(
name|ucal
argument_list|,
name|atMSecsSinceEpoch
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
name|bool
name|result
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|result
operator|=
name|ucal_inDaylightTime
argument_list|(
name|ucal
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
name|ucal_close
argument_list|(
name|ucal
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|data
name|QTimeZonePrivate
operator|::
name|Data
name|QIcuTimeZonePrivate
operator|::
name|data
parameter_list|(
name|qint64
name|forMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// Available in ICU C++ api, and draft C api in v50
comment|// TODO When v51 released see if api is stable
name|QTimeZonePrivate
operator|::
name|Data
name|data
init|=
name|invalidData
argument_list|()
decl_stmt|;
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|50
name|data
operator|=
name|ucalTimeZoneTransition
argument_list|(
name|m_ucal
argument_list|,
name|UCAL_TZ_TRANSITION_PREVIOUS_INCLUSIVE
argument_list|,
name|forMSecsSinceEpoch
argument_list|)
expr_stmt|;
else|#
directive|else
name|ucalOffsetsAtTime
argument_list|(
name|m_ucal
argument_list|,
name|forMSecsSinceEpoch
argument_list|,
operator|&
name|data
operator|.
name|standardTimeOffset
argument_list|,
operator|&
name|data
operator|.
name|daylightTimeOffset
argument_list|)
expr_stmt|;
name|data
operator|.
name|offsetFromUtc
operator|=
name|data
operator|.
name|standardTimeOffset
operator|+
name|data
operator|.
name|daylightTimeOffset
expr_stmt|;
name|data
operator|.
name|abbreviation
operator|=
name|abbreviation
argument_list|(
name|forMSecsSinceEpoch
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// U_ICU_VERSION_MAJOR_NUM == 50
name|data
operator|.
name|atMSecsSinceEpoch
operator|=
name|forMSecsSinceEpoch
expr_stmt|;
return|return
name|data
return|;
block|}
end_function
begin_function
DECL|function|hasTransitions
name|bool
name|QIcuTimeZonePrivate
operator|::
name|hasTransitions
parameter_list|()
specifier|const
block|{
comment|// Available in ICU C++ api, and draft C api in v50
comment|// TODO When v51 released see if api is stable
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|50
return|return
literal|true
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
comment|// U_ICU_VERSION_MAJOR_NUM == 50
block|}
end_function
begin_function
DECL|function|nextTransition
name|QTimeZonePrivate
operator|::
name|Data
name|QIcuTimeZonePrivate
operator|::
name|nextTransition
parameter_list|(
name|qint64
name|afterMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// Available in ICU C++ api, and draft C api in v50
comment|// TODO When v51 released see if api is stable
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|50
return|return
name|ucalTimeZoneTransition
argument_list|(
name|m_ucal
argument_list|,
name|UCAL_TZ_TRANSITION_NEXT
argument_list|,
name|afterMSecsSinceEpoch
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|afterMSecsSinceEpoch
argument_list|)
return|return
name|invalidData
argument_list|()
return|;
endif|#
directive|endif
comment|// U_ICU_VERSION_MAJOR_NUM == 50
block|}
end_function
begin_function
DECL|function|previousTransition
name|QTimeZonePrivate
operator|::
name|Data
name|QIcuTimeZonePrivate
operator|::
name|previousTransition
parameter_list|(
name|qint64
name|beforeMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// Available in ICU C++ api, and draft C api in v50
comment|// TODO When v51 released see if api is stable
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|50
return|return
name|ucalTimeZoneTransition
argument_list|(
name|m_ucal
argument_list|,
name|UCAL_TZ_TRANSITION_PREVIOUS
argument_list|,
name|beforeMSecsSinceEpoch
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|beforeMSecsSinceEpoch
argument_list|)
return|return
name|invalidData
argument_list|()
return|;
endif|#
directive|endif
comment|// U_ICU_VERSION_MAJOR_NUM == 50
block|}
end_function
begin_function
DECL|function|systemTimeZoneId
name|QByteArray
name|QIcuTimeZonePrivate
operator|::
name|systemTimeZoneId
parameter_list|()
specifier|const
block|{
comment|// No ICU C API to obtain sysem tz
comment|// TODO Assume default hasn't been changed and is the latests system
return|return
name|ucalDefaultTimeZoneId
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|availableTimeZoneIds
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|QIcuTimeZonePrivate
operator|::
name|availableTimeZoneIds
parameter_list|()
specifier|const
block|{
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UEnumeration
modifier|*
name|uenum
init|=
name|ucal_openTimeZones
argument_list|(
operator|&
name|status
argument_list|)
decl_stmt|;
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|set
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
name|set
operator|=
name|uenumToIdSet
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
name|uenum_close
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
return|return
name|set
return|;
block|}
end_function
begin_function
DECL|function|availableTimeZoneIds
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|QIcuTimeZonePrivate
operator|::
name|availableTimeZoneIds
parameter_list|(
name|QLocale
operator|::
name|Country
name|country
parameter_list|)
specifier|const
block|{
name|QByteArray
name|regionCode
init|=
name|QLocalePrivate
operator|::
name|countryToCode
argument_list|(
name|country
argument_list|)
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UEnumeration
modifier|*
name|uenum
init|=
name|ucal_openCountryTimeZones
argument_list|(
name|regionCode
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|set
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
name|set
operator|=
name|uenumToIdSet
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
name|uenum_close
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
return|return
name|set
return|;
block|}
end_function
begin_function
DECL|function|availableTimeZoneIds
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|QIcuTimeZonePrivate
operator|::
name|availableTimeZoneIds
parameter_list|(
name|int
name|offsetFromUtc
parameter_list|)
specifier|const
block|{
comment|// TODO Available directly in C++ api but not C api, from 4.8 onwards new filter method works
if|#
directive|if
name|U_ICU_VERSION_MAJOR_NUM
operator|>=
literal|49
operator|||
operator|(
name|U_ICU_VERSION_MAJOR_NUM
operator|==
literal|4
operator|&&
name|U_ICU_VERSION_MINOR_NUM
operator|==
literal|8
operator|)
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UEnumeration
modifier|*
name|uenum
init|=
name|ucal_openTimeZoneIDEnumeration
argument_list|(
name|UCAL_ZONE_TYPE_ANY
argument_list|,
literal|0
argument_list|,
operator|&
name|offsetFromUtc
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|set
decl_stmt|;
if|if
condition|(
name|U_SUCCESS
argument_list|(
name|status
argument_list|)
condition|)
name|set
operator|=
name|uenumToIdSet
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
name|uenum_close
argument_list|(
name|uenum
argument_list|)
expr_stmt|;
return|return
name|set
return|;
else|#
directive|else
return|return
name|QTimeZonePrivate
operator|::
name|availableTimeZoneIds
argument_list|(
name|offsetFromUtc
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
