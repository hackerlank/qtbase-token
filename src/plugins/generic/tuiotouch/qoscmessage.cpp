begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Robin Burchell<robin.burchell@viroteck.net> ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtEndian>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|"qoscmessage_p.h"
end_include
begin_include
include|#
directive|include
file|"qtuio_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcTuioMessage
argument_list|,
literal|"qt.qpa.tuio.message"
argument_list|)
comment|// TUIO packets are transmitted using the OSC protocol, located at:
comment|//   http://opensoundcontrol.org/specification
comment|// Snippets of this specification have been pasted into the source as a means of
comment|// easily communicating requirements.
DECL|function|QOscMessage
name|QOscMessage
operator|::
name|QOscMessage
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
range|:
name|m_isValid
argument_list|(
literal|false
argument_list|)
block|{
name|qCDebug
argument_list|(
name|lcTuioMessage
argument_list|)
operator|<<
name|data
operator|.
name|toHex
argument_list|()
block|;
name|quint32
name|parsedBytes
operator|=
literal|0
block|;
comment|// "An OSC message consists of an OSC Address Pattern"
name|QByteArray
name|addressPattern
block|;
if|if
condition|(
operator|!
name|qt_readOscString
argument_list|(
name|data
argument_list|,
name|addressPattern
argument_list|,
name|parsedBytes
argument_list|)
operator|||
name|addressPattern
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
return|return;
comment|// "followed by an OSC Type Tag String"
name|QByteArray
name|typeTagString
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|qt_readOscString
argument_list|(
name|data
argument_list|,
name|typeTagString
argument_list|,
name|parsedBytes
argument_list|)
condition|)
return|return;
end_if
begin_comment
comment|// "Note: some older implementations of OSC may omit the OSC Type Tag string.
end_comment
begin_comment
comment|// Until all such implementations are updated, OSC implementations should be
end_comment
begin_comment
comment|// robust in the case of a missing OSC Type Tag String."
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// (although, the editor notes one may question how exactly the hell one is
end_comment
begin_comment
comment|// supposed to be robust when the behavior is unspecified.)
end_comment
begin_if
if|if
condition|(
name|typeTagString
operator|.
name|size
argument_list|()
operator|==
literal|0
operator|||
name|typeTagString
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
literal|','
condition|)
return|return;
end_if
begin_decl_stmt
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
decl_stmt|;
end_decl_stmt
begin_comment
comment|// "followed by zero or more OSC Arguments."
end_comment
begin_for
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|typeTagString
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|char
name|typeTag
init|=
name|typeTagString
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|typeTag
operator|==
literal|'s'
condition|)
block|{
comment|// osc-string
name|QByteArray
name|aString
decl_stmt|;
if|if
condition|(
operator|!
name|qt_readOscString
argument_list|(
name|data
argument_list|,
name|aString
argument_list|,
name|parsedBytes
argument_list|)
condition|)
return|return;
name|arguments
operator|.
name|append
argument_list|(
name|aString
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeTag
operator|==
literal|'i'
condition|)
block|{
comment|// int32
if|if
condition|(
name|parsedBytes
operator|>
operator|(
name|quint32
operator|)
name|data
operator|.
name|size
argument_list|()
operator|||
name|data
operator|.
name|size
argument_list|()
operator|-
name|parsedBytes
operator|<
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
condition|)
return|return;
name|quint32
name|anInt
init|=
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
operator|+
name|parsedBytes
argument_list|)
decl_stmt|;
name|parsedBytes
operator|+=
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
expr_stmt|;
comment|// TODO: is int32 in OSC signed, or unsigned?
name|arguments
operator|.
name|append
argument_list|(
operator|(
name|int
operator|)
name|anInt
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeTag
operator|==
literal|'f'
condition|)
block|{
comment|// float32
if|if
condition|(
name|parsedBytes
operator|>
operator|(
name|quint32
operator|)
name|data
operator|.
name|size
argument_list|()
operator|||
name|data
operator|.
name|size
argument_list|()
operator|-
name|parsedBytes
operator|<
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
condition|)
return|return;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
union|union
block|{
name|quint32
name|u
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|value
union|;
name|value
operator|.
name|u
operator|=
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
operator|+
name|parsedBytes
argument_list|)
expr_stmt|;
name|parsedBytes
operator|+=
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
expr_stmt|;
name|arguments
operator|.
name|append
argument_list|(
name|value
operator|.
name|f
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Reading argument of unknown type "
operator|<<
name|typeTag
expr_stmt|;
return|return;
block|}
block|}
end_for
begin_expr_stmt
name|m_isValid
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_addressPattern
operator|=
name|addressPattern
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_arguments
operator|=
name|arguments
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qCDebug
argument_list|(
name|lcTuioMessage
argument_list|)
operator|<<
literal|"Message with address pattern: "
operator|<<
name|addressPattern
operator|<<
literal|" arguments: "
operator|<<
name|arguments
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  bool
DECL|function|isValid
name|QOscMessage
end_macro
begin_expr_stmt
DECL|function|isValid
operator|::
name|isValid
operator|(
operator|)
specifier|const
block|{
return|return
name|m_isValid
return|;
block|}
end_expr_stmt
begin_function
DECL|function|addressPattern
name|QByteArray
name|QOscMessage
operator|::
name|addressPattern
parameter_list|()
specifier|const
block|{
return|return
name|m_addressPattern
return|;
block|}
end_function
begin_function
DECL|function|arguments
name|QList
argument_list|<
name|QVariant
argument_list|>
name|QOscMessage
operator|::
name|arguments
parameter_list|()
specifier|const
block|{
return|return
name|m_arguments
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
