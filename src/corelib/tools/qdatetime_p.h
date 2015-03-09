begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATETIME_P_H
end_ifndef
begin_define
DECL|macro|QDATETIME_P_H
define|#
directive|define
name|QDATETIME_P_H
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
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qtimezone.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDateTimePrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
comment|// Never change or delete this enum, it is required for backwards compatible
comment|// serialization of QDateTime before 5.2, so is essentially public API
expr|enum
name|Spec
block|{
name|LocalUnknown
operator|=
operator|-
literal|1
block|,
name|LocalStandard
operator|=
literal|0
block|,
name|LocalDST
operator|=
literal|1
block|,
name|UTC
operator|=
literal|2
block|,
name|OffsetFromUTC
operator|=
literal|3
block|,
name|TimeZone
operator|=
literal|4
block|}
block|;
comment|// Daylight Time Status
block|enum
name|DaylightStatus
block|{
name|NoDaylightTime
operator|=
operator|-
literal|2
block|,
name|UnknownDaylightTime
operator|=
operator|-
literal|1
block|,
name|StandardTime
operator|=
literal|0
block|,
name|DaylightTime
operator|=
literal|1
block|}
block|;
comment|// Status of date/time
block|enum
name|StatusFlag
block|{
name|NullDate
operator|=
literal|0x01
block|,
name|NullTime
operator|=
literal|0x02
block|,
name|ValidDate
operator|=
literal|0x04
block|,
comment|// just the date field
name|ValidTime
operator|=
literal|0x08
block|,
comment|// just the time field
name|ValidDateTime
operator|=
literal|0x10
block|,
comment|// the whole object (including timezone)
name|SetToStandardTime
operator|=
literal|0x40
block|,
name|SetToDaylightTime
operator|=
literal|0x80
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|StatusFlags
argument_list|,
argument|StatusFlag
argument_list|)
name|QDateTimePrivate
argument_list|()
operator|:
name|m_msecs
argument_list|(
literal|0
argument_list|)
block|,
name|m_spec
argument_list|(
name|Qt
operator|::
name|LocalTime
argument_list|)
block|,
name|m_offsetFromUtc
argument_list|(
literal|0
argument_list|)
block|,
name|m_status
argument_list|(
argument|NullDate | NullTime
argument_list|)
block|{}
name|QDateTimePrivate
argument_list|(
argument|const QDate&toDate
argument_list|,
argument|const QTime&toTime
argument_list|,
argument|Qt::TimeSpec toSpec
argument_list|,
argument|int offsetSeconds
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QDateTimePrivate
argument_list|(
specifier|const
name|QDate
operator|&
name|toDate
argument_list|,
specifier|const
name|QTime
operator|&
name|toTime
argument_list|,
specifier|const
name|QTimeZone
operator|&
name|timeZone
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
comment|// ### XXX: when the tooling situation improves, look at fixing the padding.
comment|// 4 bytes padding
name|qint64
name|m_msecs
block|;
name|Qt
operator|::
name|TimeSpec
name|m_spec
block|;
name|int
name|m_offsetFromUtc
block|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QTimeZone
name|m_timeZone
block|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
name|StatusFlags
name|m_status
block|;
name|void
name|setTimeSpec
argument_list|(
argument|Qt::TimeSpec spec
argument_list|,
argument|int offsetSeconds
argument_list|)
block|;
name|void
name|setDateTime
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|,
specifier|const
name|QTime
operator|&
name|time
argument_list|)
block|;
name|void
name|getDateTime
argument_list|(
argument|QDate *date
argument_list|,
argument|QTime *time
argument_list|)
specifier|const
block|;
name|void
name|setDaylightStatus
argument_list|(
argument|DaylightStatus status
argument_list|)
block|;
name|DaylightStatus
name|daylightStatus
argument_list|()
specifier|const
block|;
comment|// Returns msecs since epoch, assumes offset value is current
specifier|inline
name|qint64
name|toMSecsSinceEpoch
argument_list|()
specifier|const
block|;
name|void
name|checkValidDateTime
argument_list|()
block|;
name|void
name|refreshDateTime
argument_list|()
block|;
comment|// Get/set date and time status
specifier|inline
name|bool
name|isNullDate
argument_list|()
specifier|const
block|{
return|return
name|m_status
operator|&
name|NullDate
return|;
block|}
specifier|inline
name|bool
name|isNullTime
argument_list|()
specifier|const
block|{
return|return
name|m_status
operator|&
name|NullTime
return|;
block|}
specifier|inline
name|bool
name|isValidDate
argument_list|()
specifier|const
block|{
return|return
name|m_status
operator|&
name|ValidDate
return|;
block|}
specifier|inline
name|bool
name|isValidTime
argument_list|()
specifier|const
block|{
return|return
name|m_status
operator|&
name|ValidTime
return|;
block|}
specifier|inline
name|bool
name|isValidDateTime
argument_list|()
specifier|const
block|{
return|return
name|m_status
operator|&
name|ValidDateTime
return|;
block|}
specifier|inline
name|void
name|setValidDateTime
argument_list|()
block|{
name|m_status
operator||=
name|ValidDateTime
block|; }
specifier|inline
name|void
name|clearValidDateTime
argument_list|()
block|{
name|m_status
operator|&=
operator|~
name|ValidDateTime
block|; }
specifier|inline
name|void
name|clearSetToDaylightStatus
argument_list|()
block|{
name|m_status
operator|&=
operator|~
operator|(
name|SetToStandardTime
operator||
name|SetToDaylightTime
operator|)
block|; }
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
specifier|static
name|qint64
name|zoneMSecsToEpochMSecs
argument_list|(
argument|qint64 msecs
argument_list|,
argument|const QTimeZone&zone
argument_list|,
argument|QDate *localDate =
literal|0
argument_list|,
argument|QTime *localTime =
literal|0
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_BOOTSTRAPPED
specifier|static
specifier|inline
name|qint64
name|minJd
argument_list|()
block|{
return|return
name|QDate
operator|::
name|minJd
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|qint64
name|maxJd
argument_list|()
block|{
return|return
name|QDate
operator|::
name|maxJd
argument_list|()
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATETIME_P_H
end_comment
end_unit
