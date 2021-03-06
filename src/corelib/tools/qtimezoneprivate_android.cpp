begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Drew Parsons<dparsons@emerall.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*     Private      Android implementation */
end_comment
begin_comment
comment|// Create the system default time zone
end_comment
begin_constructor
DECL|function|QAndroidTimeZonePrivate
name|QAndroidTimeZonePrivate
operator|::
name|QAndroidTimeZonePrivate
parameter_list|()
member_init_list|:
name|QTimeZonePrivate
argument_list|()
block|{
comment|// start with system time zone
name|androidTimeZone
operator|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"java.util.TimeZone"
argument_list|,
literal|"getDefault"
argument_list|,
literal|"()Ljava/util/TimeZone;"
argument_list|)
expr_stmt|;
name|init
argument_list|(
literal|"UTC"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|// Create a named time zone
end_comment
begin_constructor
DECL|function|QAndroidTimeZonePrivate
name|QAndroidTimeZonePrivate
operator|::
name|QAndroidTimeZonePrivate
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
member_init_list|:
name|QTimeZonePrivate
argument_list|()
block|{
name|init
argument_list|(
name|ianaId
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QAndroidTimeZonePrivate
name|QAndroidTimeZonePrivate
operator|::
name|QAndroidTimeZonePrivate
parameter_list|(
specifier|const
name|QAndroidTimeZonePrivate
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QTimeZonePrivate
argument_list|(
name|other
argument_list|)
block|{
name|androidTimeZone
operator|=
name|other
operator|.
name|androidTimeZone
expr_stmt|;
name|m_id
operator|=
name|other
operator|.
name|id
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAndroidTimeZonePrivate
name|QAndroidTimeZonePrivate
operator|::
name|~
name|QAndroidTimeZonePrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|QAndroidTimeZonePrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ianaId
parameter_list|)
block|{
name|QJNIObjectPrivate
name|jo_ianaId
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|ianaId
argument_list|)
argument_list|)
decl_stmt|;
name|androidTimeZone
operator|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"java.util.TimeZone"
argument_list|,
literal|"getTimeZone"
argument_list|,
literal|"(Ljava/lang/String;)Ljava/util/TimeZone;"
argument_list|,
cast|static_cast
argument_list|<
name|jstring
argument_list|>
argument_list|(
name|jo_ianaId
operator|.
name|object
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ianaId
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_id
operator|=
name|systemTimeZoneId
argument_list|()
expr_stmt|;
else|else
name|m_id
operator|=
name|ianaId
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clone
name|QTimeZonePrivate
modifier|*
name|QAndroidTimeZonePrivate
operator|::
name|clone
parameter_list|()
block|{
return|return
operator|new
name|QAndroidTimeZonePrivate
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|displayName
name|QString
name|QAndroidTimeZonePrivate
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
name|QString
name|name
decl_stmt|;
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|jboolean
name|daylightTime
init|=
operator|(
name|timeType
operator|==
name|QTimeZone
operator|::
name|DaylightTime
operator|)
decl_stmt|;
comment|// treat QTimeZone::GenericTime as QTimeZone::StandardTime
comment|// treat all NameTypes as java TimeZone style LONG (value 1), except of course QTimeZone::ShortName which is style SHORT (value 0);
name|jint
name|style
init|=
operator|(
name|nameType
operator|==
name|QTimeZone
operator|::
name|ShortName
condition|?
literal|0
else|:
literal|1
operator|)
decl_stmt|;
name|QJNIObjectPrivate
name|jlanguage
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|QLocale
operator|::
name|languageToString
argument_list|(
name|locale
operator|.
name|language
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|jcountry
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|QLocale
operator|::
name|countryToString
argument_list|(
name|locale
operator|.
name|country
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|jvariant
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|QLocale
operator|::
name|scriptToString
argument_list|(
name|locale
operator|.
name|script
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|jlocale
argument_list|(
literal|"java.util.Locale"
argument_list|,
literal|"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"
argument_list|,
cast|static_cast
argument_list|<
name|jstring
argument_list|>
argument_list|(
name|jlanguage
operator|.
name|object
argument_list|()
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|jstring
argument_list|>
argument_list|(
name|jcountry
operator|.
name|object
argument_list|()
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|jstring
argument_list|>
argument_list|(
name|jvariant
operator|.
name|object
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|jname
init|=
name|androidTimeZone
operator|.
name|callObjectMethod
argument_list|(
literal|"getDisplayName"
argument_list|,
literal|"(ZILjava/util/Locale;)Ljava/lang/String;"
argument_list|,
name|daylightTime
argument_list|,
name|style
argument_list|,
name|jlocale
operator|.
name|object
argument_list|()
argument_list|)
decl_stmt|;
name|name
operator|=
name|jname
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
return|return
name|name
return|;
block|}
end_function
begin_function
DECL|function|abbreviation
name|QString
name|QAndroidTimeZonePrivate
operator|::
name|abbreviation
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
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
name|QLocale
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
name|QLocale
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|offsetFromUtc
name|int
name|QAndroidTimeZonePrivate
operator|::
name|offsetFromUtc
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// offsetFromUtc( ) is invoked when androidTimeZone may not yet be set at startup,
comment|// so a validity test is needed here
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
comment|// the java method getOffset() returns milliseconds, but QTimeZone returns seconds
return|return
name|androidTimeZone
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"getOffset"
argument_list|,
literal|"(J)I"
argument_list|,
cast|static_cast
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
argument_list|)
operator|/
literal|1000
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|standardTimeOffset
name|int
name|QAndroidTimeZonePrivate
operator|::
name|standardTimeOffset
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// the java method does not use a reference time
name|Q_UNUSED
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
expr_stmt|;
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
comment|// the java method getRawOffset() returns milliseconds, but QTimeZone returns seconds
return|return
name|androidTimeZone
operator|.
name|callMethod
argument_list|<
name|jint
argument_list|>
argument_list|(
literal|"getRawOffset"
argument_list|)
operator|/
literal|1000
return|;
else|else
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|daylightTimeOffset
name|int
name|QAndroidTimeZonePrivate
operator|::
name|daylightTimeOffset
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|offsetFromUtc
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
operator|-
name|standardTimeOffset
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|hasDaylightTime
name|bool
name|QAndroidTimeZonePrivate
operator|::
name|hasDaylightTime
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
comment|/* note: the Java function only tests for future DST transtions, not past */
return|return
name|androidTimeZone
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"useDaylightTime"
argument_list|)
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isDaylightTime
name|bool
name|QAndroidTimeZonePrivate
operator|::
name|isDaylightTime
parameter_list|(
name|qint64
name|atMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QJNIObjectPrivate
name|jDate
argument_list|(
literal|"java/util/Date"
argument_list|,
literal|"(J)V"
argument_list|,
cast|static_cast
argument_list|<
name|jlong
argument_list|>
argument_list|(
name|atMSecsSinceEpoch
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|androidTimeZone
operator|.
name|callMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
literal|"inDaylightTime"
argument_list|,
literal|"(Ljava/util/Date;)Z"
argument_list|,
name|jDate
operator|.
name|object
argument_list|()
argument_list|)
return|;
block|}
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|data
name|QTimeZonePrivate
operator|::
name|Data
name|QAndroidTimeZonePrivate
operator|::
name|data
parameter_list|(
name|qint64
name|forMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|Data
name|data
decl_stmt|;
name|data
operator|.
name|atMSecsSinceEpoch
operator|=
name|forMSecsSinceEpoch
expr_stmt|;
name|data
operator|.
name|standardTimeOffset
operator|=
name|standardTimeOffset
argument_list|(
name|forMSecsSinceEpoch
argument_list|)
expr_stmt|;
name|data
operator|.
name|offsetFromUtc
operator|=
name|offsetFromUtc
argument_list|(
name|forMSecsSinceEpoch
argument_list|)
expr_stmt|;
name|data
operator|.
name|daylightTimeOffset
operator|=
name|data
operator|.
name|offsetFromUtc
operator|-
name|data
operator|.
name|standardTimeOffset
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
return|return
name|data
return|;
block|}
else|else
block|{
return|return
name|invalidData
argument_list|()
return|;
block|}
block|}
end_function
begin_function
DECL|function|hasTransitions
name|bool
name|QAndroidTimeZonePrivate
operator|::
name|hasTransitions
parameter_list|()
specifier|const
block|{
comment|// java.util.TimeZone does not directly provide transitions
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|nextTransition
name|QTimeZonePrivate
operator|::
name|Data
name|QAndroidTimeZonePrivate
operator|::
name|nextTransition
parameter_list|(
name|qint64
name|afterMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// transitions not available on Android, so return an invalid data object
name|Q_UNUSED
argument_list|(
name|afterMSecsSinceEpoch
argument_list|)
expr_stmt|;
return|return
name|invalidData
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|previousTransition
name|QTimeZonePrivate
operator|::
name|Data
name|QAndroidTimeZonePrivate
operator|::
name|previousTransition
parameter_list|(
name|qint64
name|beforeMSecsSinceEpoch
parameter_list|)
specifier|const
block|{
comment|// transitions not available on Android, so return an invalid data object
name|Q_UNUSED
argument_list|(
name|beforeMSecsSinceEpoch
argument_list|)
expr_stmt|;
return|return
name|invalidData
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Since Android does not provide an API to access transitions,
end_comment
begin_comment
comment|// dataForLocalTime needs to be reimplemented without direct use of transitions
end_comment
begin_function
DECL|function|dataForLocalTime
name|QTimeZonePrivate
operator|::
name|Data
name|QAndroidTimeZonePrivate
operator|::
name|dataForLocalTime
parameter_list|(
name|qint64
name|forLocalMSecs
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|androidTimeZone
operator|.
name|isValid
argument_list|()
condition|)
block|{
return|return
name|invalidData
argument_list|()
return|;
block|}
else|else
block|{
name|qint64
name|UTCepochMSecs
decl_stmt|;
comment|// compare the UTC time with standard offset against normal DST offset of one hour
name|qint64
name|standardUTCMSecs
argument_list|(
name|forLocalMSecs
operator|-
operator|(
name|standardTimeOffset
argument_list|(
name|forLocalMSecs
argument_list|)
operator|*
literal|1000
operator|)
argument_list|)
decl_stmt|;
name|qint64
name|daylightUTCMsecs
decl_stmt|;
comment|// Check if daylight-saving time applies,
comment|// checking also for DST boundaries
if|if
condition|(
name|isDaylightTime
argument_list|(
name|standardUTCMSecs
argument_list|)
condition|)
block|{
comment|// If DST does apply, then standardUTCMSecs will be an hour or so ahead of the real epoch time
comment|// so check that time
name|daylightUTCMsecs
operator|=
name|standardUTCMSecs
operator|-
name|daylightTimeOffset
argument_list|(
name|standardUTCMSecs
argument_list|)
operator|*
literal|1000
expr_stmt|;
if|if
condition|(
name|isDaylightTime
argument_list|(
name|daylightUTCMsecs
argument_list|)
condition|)
block|{
comment|// DST confirmed
name|UTCepochMSecs
operator|=
name|daylightUTCMsecs
expr_stmt|;
block|}
else|else
block|{
comment|// DST has just finished
name|UTCepochMSecs
operator|=
name|standardUTCMSecs
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Standard time indicated, but check for a false negative.
comment|// Would a standard one-hour DST offset indicate DST?
name|daylightUTCMsecs
operator|=
name|standardUTCMSecs
operator|-
literal|3600000
expr_stmt|;
comment|// 3600000 MSECS_PER_HOUR
if|if
condition|(
name|isDaylightTime
argument_list|(
name|daylightUTCMsecs
argument_list|)
condition|)
block|{
comment|// DST may have just started,
comment|// but double check against timezone's own DST offset
comment|// (don't necessarily assume a one-hour offset)
name|daylightUTCMsecs
operator|=
name|standardUTCMSecs
operator|-
name|daylightTimeOffset
argument_list|(
name|daylightUTCMsecs
argument_list|)
operator|*
literal|1000
expr_stmt|;
if|if
condition|(
name|isDaylightTime
argument_list|(
name|daylightUTCMsecs
argument_list|)
condition|)
block|{
comment|// DST confirmed
name|UTCepochMSecs
operator|=
name|daylightUTCMsecs
expr_stmt|;
block|}
else|else
block|{
comment|// false positive, apply standard time after all
name|UTCepochMSecs
operator|=
name|standardUTCMSecs
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// confirmed standard time
name|UTCepochMSecs
operator|=
name|standardUTCMSecs
expr_stmt|;
block|}
block|}
return|return
name|data
argument_list|(
name|UTCepochMSecs
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|systemTimeZoneId
name|QByteArray
name|QAndroidTimeZonePrivate
operator|::
name|systemTimeZoneId
parameter_list|()
specifier|const
block|{
name|QJNIObjectPrivate
name|androidSystemTimeZone
init|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"java.util.TimeZone"
argument_list|,
literal|"getDefault"
argument_list|,
literal|"()Ljava/util/TimeZone;"
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|systemTZIdAndroid
init|=
name|androidSystemTimeZone
operator|.
name|callObjectMethod
argument_list|<
name|jstring
argument_list|>
argument_list|(
literal|"getID"
argument_list|)
decl_stmt|;
name|QByteArray
name|systemTZid
init|=
name|systemTZIdAndroid
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
return|return
name|systemTZid
return|;
block|}
end_function
begin_function
DECL|function|availableTimeZoneIds
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QAndroidTimeZonePrivate
operator|::
name|availableTimeZoneIds
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|availableTimeZoneIdList
decl_stmt|;
name|QJNIObjectPrivate
name|androidAvailableIdList
init|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"java.util.TimeZone"
argument_list|,
literal|"getAvailableIDs"
argument_list|,
literal|"()[Ljava/lang/String;"
argument_list|)
decl_stmt|;
name|QJNIEnvironmentPrivate
name|jniEnv
decl_stmt|;
name|int
name|androidTZcount
init|=
name|jniEnv
operator|->
name|GetArrayLength
argument_list|(
cast|static_cast
argument_list|<
name|jarray
argument_list|>
argument_list|(
name|androidAvailableIdList
operator|.
name|object
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// need separate jobject and QAndroidJniObject here so that we can delete (DeleteLocalRef) the reference to the jobject
comment|// (or else the JNI reference table fills after 512 entries from GetObjectArrayElement)
name|jobject
name|androidTZobject
decl_stmt|;
name|QJNIObjectPrivate
name|androidTZ
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|androidTZcount
condition|;
name|i
operator|++
control|)
block|{
name|androidTZobject
operator|=
name|jniEnv
operator|->
name|GetObjectArrayElement
argument_list|(
cast|static_cast
argument_list|<
name|jobjectArray
argument_list|>
argument_list|(
name|androidAvailableIdList
operator|.
name|object
argument_list|()
argument_list|)
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|androidTZ
operator|=
name|androidTZobject
expr_stmt|;
name|availableTimeZoneIdList
operator|.
name|append
argument_list|(
name|androidTZ
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
name|jniEnv
operator|->
name|DeleteLocalRef
argument_list|(
name|androidTZobject
argument_list|)
expr_stmt|;
block|}
return|return
name|availableTimeZoneIdList
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
