begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJSONDOCUMENT_H
end_ifndef
begin_define
DECL|macro|QJSONDOCUMENT_H
define|#
directive|define
name|QJSONDOCUMENT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qjsonvalue.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QJsonPrivate
block|{
name|class
name|Parser
decl_stmt|;
block|}
end_decl_stmt
begin_struct
DECL|struct|QJsonParseError
struct|struct
name|Q_CORE_EXPORT
name|QJsonParseError
block|{
DECL|enum|ParseError
enum|enum
name|ParseError
block|{
DECL|enumerator|NoError
name|NoError
init|=
literal|0
block|,
DECL|enumerator|UnterminatedObject
name|UnterminatedObject
block|,
DECL|enumerator|MissingNameSeparator
name|MissingNameSeparator
block|,
DECL|enumerator|UnterminatedArray
name|UnterminatedArray
block|,
DECL|enumerator|MissingValueSeparator
name|MissingValueSeparator
block|,
DECL|enumerator|IllegalValue
name|IllegalValue
block|,
DECL|enumerator|TerminationByNumber
name|TerminationByNumber
block|,
DECL|enumerator|IllegalNumber
name|IllegalNumber
block|,
DECL|enumerator|IllegalEscapeSequence
name|IllegalEscapeSequence
block|,
DECL|enumerator|IllegalUTF8String
name|IllegalUTF8String
block|,
DECL|enumerator|UnterminatedString
name|UnterminatedString
block|,
DECL|enumerator|MissingObject
name|MissingObject
block|,
DECL|enumerator|DeepNesting
name|DeepNesting
block|}
enum|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
DECL|member|offset
name|int
name|offset
decl_stmt|;
DECL|member|error
name|ParseError
name|error
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJsonDocument
block|{
name|public
label|:
ifdef|#
directive|ifdef
name|Q_LITTLE_ENDIAN
specifier|static
specifier|const
name|uint
name|BinaryFormatTag
init|=
operator|(
literal|'q'
operator|)
operator||
operator|(
literal|'b'
operator|<<
literal|8
operator|)
operator||
operator|(
literal|'j'
operator|<<
literal|16
operator|)
operator||
operator|(
literal|'s'
operator|<<
literal|24
operator|)
decl_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|uint
name|BinaryFormatTag
init|=
operator|(
literal|'q'
operator|<<
literal|24
operator|)
operator||
operator|(
literal|'b'
operator|<<
literal|16
operator|)
operator||
operator|(
literal|'j'
operator|<<
literal|8
operator|)
operator||
operator|(
literal|'s'
operator|)
decl_stmt|;
endif|#
directive|endif
name|QJsonDocument
argument_list|()
expr_stmt|;
name|explicit
name|QJsonDocument
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|object
parameter_list|)
function_decl|;
name|explicit
name|QJsonDocument
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|array
parameter_list|)
function_decl|;
operator|~
name|QJsonDocument
argument_list|()
expr_stmt|;
name|QJsonDocument
argument_list|(
specifier|const
name|QJsonDocument
operator|&
name|other
argument_list|)
expr_stmt|;
name|QJsonDocument
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QJsonDocument
operator|&
name|other
operator|)
decl_stmt|;
enum|enum
name|DataValidation
block|{
name|Validate
block|,
name|BypassValidation
block|}
enum|;
specifier|static
name|QJsonDocument
name|fromRawData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|,
name|DataValidation
name|validation
init|=
name|Validate
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|rawData
argument_list|(
name|int
operator|*
name|size
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QJsonDocument
name|fromBinaryData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|DataValidation
name|validation
init|=
name|Validate
parameter_list|)
function_decl|;
name|QByteArray
name|toBinaryData
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QJsonDocument
name|fromVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
function_decl|;
name|QVariant
name|toVariant
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QJsonDocument
name|fromJson
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|json
parameter_list|,
name|QJsonParseError
modifier|*
name|error
init|=
literal|0
parameter_list|)
function_decl|;
name|QByteArray
name|toJson
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isArray
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isObject
argument_list|()
specifier|const
expr_stmt|;
name|QJsonObject
name|object
argument_list|()
specifier|const
expr_stmt|;
name|QJsonArray
name|array
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setObject
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|object
parameter_list|)
function_decl|;
name|void
name|setArray
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|array
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJsonDocument
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJsonDocument
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QJsonValue
decl_stmt|;
name|friend
name|class
name|QJsonPrivate
operator|::
name|Data
expr_stmt|;
name|friend
name|class
name|QJsonPrivate
operator|::
name|Parser
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonDocument
operator|&
operator|)
expr_stmt|;
name|QJsonDocument
argument_list|(
name|QJsonPrivate
operator|::
name|Data
operator|*
name|data
argument_list|)
expr_stmt|;
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonDocument
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QJSONDOCUMENT_H
end_comment
end_unit
