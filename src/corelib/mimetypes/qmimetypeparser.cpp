begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_include
include|#
directive|include
file|"qmimetypeparser_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimetype_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimemagicrulematcher_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_include
include|#
directive|include
file|<QtCore/QXmlStreamReader>
end_include
begin_include
include|#
directive|include
file|<QtCore/QXmlStreamWriter>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStack>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// XML tags in MIME files
DECL|variable|mimeInfoTagC
specifier|static
specifier|const
name|char
name|mimeInfoTagC
index|[]
init|=
literal|"mime-info"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mimeTypeTagC
specifier|static
specifier|const
name|char
name|mimeTypeTagC
index|[]
init|=
literal|"mime-type"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mimeTypeAttributeC
specifier|static
specifier|const
name|char
name|mimeTypeAttributeC
index|[]
init|=
literal|"type"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|subClassTagC
specifier|static
specifier|const
name|char
name|subClassTagC
index|[]
init|=
literal|"sub-class-of"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|commentTagC
specifier|static
specifier|const
name|char
name|commentTagC
index|[]
init|=
literal|"comment"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|genericIconTagC
specifier|static
specifier|const
name|char
name|genericIconTagC
index|[]
init|=
literal|"generic-icon"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|iconTagC
specifier|static
specifier|const
name|char
name|iconTagC
index|[]
init|=
literal|"icon"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|nameAttributeC
specifier|static
specifier|const
name|char
name|nameAttributeC
index|[]
init|=
literal|"name"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|globTagC
specifier|static
specifier|const
name|char
name|globTagC
index|[]
init|=
literal|"glob"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|aliasTagC
specifier|static
specifier|const
name|char
name|aliasTagC
index|[]
init|=
literal|"alias"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|patternAttributeC
specifier|static
specifier|const
name|char
name|patternAttributeC
index|[]
init|=
literal|"pattern"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|weightAttributeC
specifier|static
specifier|const
name|char
name|weightAttributeC
index|[]
init|=
literal|"weight"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|caseSensitiveAttributeC
specifier|static
specifier|const
name|char
name|caseSensitiveAttributeC
index|[]
init|=
literal|"case-sensitive"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|localeAttributeC
specifier|static
specifier|const
name|char
name|localeAttributeC
index|[]
init|=
literal|"xml:lang"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|magicTagC
specifier|static
specifier|const
name|char
name|magicTagC
index|[]
init|=
literal|"magic"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|priorityAttributeC
specifier|static
specifier|const
name|char
name|priorityAttributeC
index|[]
init|=
literal|"priority"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|matchTagC
specifier|static
specifier|const
name|char
name|matchTagC
index|[]
init|=
literal|"match"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|matchValueAttributeC
specifier|static
specifier|const
name|char
name|matchValueAttributeC
index|[]
init|=
literal|"value"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|matchTypeAttributeC
specifier|static
specifier|const
name|char
name|matchTypeAttributeC
index|[]
init|=
literal|"type"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|matchOffsetAttributeC
specifier|static
specifier|const
name|char
name|matchOffsetAttributeC
index|[]
init|=
literal|"offset"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|matchMaskAttributeC
specifier|static
specifier|const
name|char
name|matchMaskAttributeC
index|[]
init|=
literal|"mask"
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QMimeTypeParser     \inmodule QtCore     \internal     \brief The QMimeTypeParser class parses MIME types, and builds a MIME database hierarchy by adding to QMimeDatabasePrivate.      Populates QMimeDataBase      \sa QMimeDatabase, QMimeMagicRuleMatcher, MagicRule, MagicStringRule, MagicByteRule, GlobPattern     \sa QMimeTypeParser */
end_comment
begin_comment
comment|/*!     \class QMimeTypeParserBase     \inmodule QtCore     \internal     \brief The QMimeTypeParserBase class parses for a sequence of<mime-type> in a generic way.      Calls abstract handler function process for QMimeType it finds.      \sa QMimeDatabase, QMimeMagicRuleMatcher, MagicRule, MagicStringRule, MagicByteRule, GlobPattern     \sa QMimeTypeParser */
end_comment
begin_comment
comment|/*!     \fn virtual bool QMimeTypeParserBase::process(const QMimeType&t, QString *errorMessage) = 0;     Overwrite to process the sequence of parsed data */
end_comment
begin_function
DECL|function|nextState
name|QMimeTypeParserBase
operator|::
name|ParseState
name|QMimeTypeParserBase
operator|::
name|nextState
parameter_list|(
name|ParseState
name|currentState
parameter_list|,
specifier|const
name|QStringRef
modifier|&
name|startElement
parameter_list|)
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|ParseBeginning
case|:
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|mimeInfoTagC
argument_list|)
condition|)
return|return
name|ParseMimeInfo
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|mimeTypeTagC
argument_list|)
condition|)
return|return
name|ParseMimeType
return|;
return|return
name|ParseError
return|;
case|case
name|ParseMimeInfo
case|:
return|return
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|mimeTypeTagC
argument_list|)
condition|?
name|ParseMimeType
else|:
name|ParseError
return|;
case|case
name|ParseMimeType
case|:
case|case
name|ParseComment
case|:
case|case
name|ParseGenericIcon
case|:
case|case
name|ParseIcon
case|:
case|case
name|ParseGlobPattern
case|:
case|case
name|ParseSubClass
case|:
case|case
name|ParseAlias
case|:
case|case
name|ParseOtherMimeTypeSubTag
case|:
case|case
name|ParseMagicMatchRule
case|:
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|mimeTypeTagC
argument_list|)
condition|)
comment|// Sequence of<mime-type>
return|return
name|ParseMimeType
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|commentTagC
argument_list|)
condition|)
return|return
name|ParseComment
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|genericIconTagC
argument_list|)
condition|)
return|return
name|ParseGenericIcon
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|iconTagC
argument_list|)
condition|)
return|return
name|ParseIcon
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|globTagC
argument_list|)
condition|)
return|return
name|ParseGlobPattern
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|subClassTagC
argument_list|)
condition|)
return|return
name|ParseSubClass
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|aliasTagC
argument_list|)
condition|)
return|return
name|ParseAlias
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|magicTagC
argument_list|)
condition|)
return|return
name|ParseMagic
return|;
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|matchTagC
argument_list|)
condition|)
return|return
name|ParseMagicMatchRule
return|;
return|return
name|ParseOtherMimeTypeSubTag
return|;
case|case
name|ParseMagic
case|:
if|if
condition|(
name|startElement
operator|==
name|QLatin1String
argument_list|(
name|matchTagC
argument_list|)
condition|)
return|return
name|ParseMagicMatchRule
return|;
break|break;
case|case
name|ParseError
case|:
break|break;
block|}
return|return
name|ParseError
return|;
block|}
end_function
begin_comment
comment|// Parse int number from an (attribute) string)
end_comment
begin_function
DECL|function|parseNumber
specifier|static
name|bool
name|parseNumber
parameter_list|(
specifier|const
name|QString
modifier|&
name|n
parameter_list|,
name|int
modifier|*
name|target
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
block|{
name|bool
name|ok
decl_stmt|;
operator|*
name|target
operator|=
name|n
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
operator|*
name|errorMessage
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Not a number '%1'."
argument_list|)
operator|.
name|arg
argument_list|(
name|n
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|// Evaluate a magic match rule like
end_comment
begin_comment
comment|//<match value="must be converted with BinHex" type="string" offset="11"/>
end_comment
begin_comment
comment|//<match value="0x9501" type="big16" offset="0:64"/>
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMREADER
end_ifndef
begin_function
DECL|function|createMagicMatchRule
specifier|static
name|bool
name|createMagicMatchRule
parameter_list|(
specifier|const
name|QXmlStreamAttributes
modifier|&
name|atts
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|,
name|QMimeMagicRule
modifier|*
modifier|&
name|rule
parameter_list|)
block|{
specifier|const
name|QString
name|type
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|matchTypeAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QMimeMagicRule
operator|::
name|Type
name|magicType
init|=
name|QMimeMagicRule
operator|::
name|type
argument_list|(
name|type
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|magicType
operator|==
name|QMimeMagicRule
operator|::
name|Invalid
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: match type %s is not supported."
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|type
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
specifier|const
name|QString
name|value
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|matchValueAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
operator|*
name|errorMessage
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Empty match value detected."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Parse for offset as "1" or "1:10"
name|int
name|startPos
decl_stmt|,
name|endPos
decl_stmt|;
specifier|const
name|QString
name|offsetS
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|matchOffsetAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
specifier|const
name|int
name|colonIndex
init|=
name|offsetS
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|startPosS
init|=
name|colonIndex
operator|==
operator|-
literal|1
condition|?
name|offsetS
else|:
name|offsetS
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|colonIndex
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|endPosS
init|=
name|colonIndex
operator|==
operator|-
literal|1
condition|?
name|offsetS
else|:
name|offsetS
operator|.
name|mid
argument_list|(
name|colonIndex
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|parseNumber
argument_list|(
name|startPosS
argument_list|,
operator|&
name|startPos
argument_list|,
name|errorMessage
argument_list|)
operator|||
operator|!
name|parseNumber
argument_list|(
name|endPosS
argument_list|,
operator|&
name|endPos
argument_list|,
name|errorMessage
argument_list|)
condition|)
return|return
literal|false
return|;
specifier|const
name|QString
name|mask
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|matchMaskAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|rule
operator|=
operator|new
name|QMimeMagicRule
argument_list|(
name|magicType
argument_list|,
name|value
operator|.
name|toUtf8
argument_list|()
argument_list|,
name|startPos
argument_list|,
name|endPos
argument_list|,
name|mask
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|parse
name|bool
name|QMimeTypeParserBase
operator|::
name|parse
parameter_list|(
name|QIODevice
modifier|*
name|dev
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_XMLSTREAMREADER
if|if
condition|(
name|errorMessage
condition|)
operator|*
name|errorMessage
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QXmlStreamReader is not available, cannot parse."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
else|#
directive|else
name|QMimeTypePrivate
name|data
decl_stmt|;
name|int
name|priority
init|=
literal|50
decl_stmt|;
name|QStack
argument_list|<
name|QMimeMagicRule
modifier|*
argument_list|>
name|currentRules
decl_stmt|;
comment|// stack for the nesting of rules
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
name|rules
decl_stmt|;
comment|// toplevel rules
name|QXmlStreamReader
name|reader
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|ParseState
name|ps
init|=
name|ParseBeginning
decl_stmt|;
name|QXmlStreamAttributes
name|atts
decl_stmt|;
while|while
condition|(
operator|!
name|reader
operator|.
name|atEnd
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|reader
operator|.
name|readNext
argument_list|()
condition|)
block|{
case|case
name|QXmlStreamReader
operator|::
name|StartElement
case|:
name|ps
operator|=
name|nextState
argument_list|(
name|ps
argument_list|,
name|reader
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|atts
operator|=
name|reader
operator|.
name|attributes
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|ps
condition|)
block|{
case|case
name|ParseMimeType
case|:
block|{
comment|// start parsing a MIME type name
specifier|const
name|QString
name|name
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|mimeTypeAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|reader
operator|.
name|raiseError
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Missing '%1'-attribute"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mimeTypeAttributeC
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|data
operator|.
name|name
operator|=
name|name
expr_stmt|;
block|}
block|}
break|break;
case|case
name|ParseGenericIcon
case|:
name|data
operator|.
name|genericIconName
operator|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|nameAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|ParseIcon
case|:
name|data
operator|.
name|iconName
operator|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|nameAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|ParseGlobPattern
case|:
block|{
specifier|const
name|QString
name|pattern
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|patternAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|unsigned
name|weight
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|weightAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|caseSensitive
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|caseSensitiveAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"true"
argument_list|)
decl_stmt|;
if|if
condition|(
name|weight
operator|==
literal|0
condition|)
name|weight
operator|=
name|QMimeGlobPattern
operator|::
name|DefaultWeight
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|data
operator|.
name|name
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QMimeGlobPattern
name|glob
argument_list|(
name|pattern
argument_list|,
name|data
operator|.
name|name
argument_list|,
name|weight
argument_list|,
name|caseSensitive
condition|?
name|Qt
operator|::
name|CaseSensitive
else|:
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|process
argument_list|(
name|glob
argument_list|,
name|errorMessage
argument_list|)
condition|)
comment|// for actual glob matching
return|return
literal|false
return|;
name|data
operator|.
name|addGlobPattern
argument_list|(
name|pattern
argument_list|)
expr_stmt|;
comment|// just for QMimeType::globPatterns()
block|}
break|break;
case|case
name|ParseSubClass
case|:
block|{
specifier|const
name|QString
name|inheritsFrom
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|mimeTypeAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|inheritsFrom
operator|.
name|isEmpty
argument_list|()
condition|)
name|processParent
argument_list|(
name|data
operator|.
name|name
argument_list|,
name|inheritsFrom
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ParseComment
case|:
block|{
comment|// comments have locale attributes. We want the default, English one
name|QString
name|locale
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|localeAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|comment
init|=
name|reader
operator|.
name|readElementText
argument_list|()
decl_stmt|;
if|if
condition|(
name|locale
operator|.
name|isEmpty
argument_list|()
condition|)
name|locale
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"en_US"
argument_list|)
expr_stmt|;
name|data
operator|.
name|localeComments
operator|.
name|insert
argument_list|(
name|locale
argument_list|,
name|comment
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ParseAlias
case|:
block|{
specifier|const
name|QString
name|alias
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|mimeTypeAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|alias
operator|.
name|isEmpty
argument_list|()
condition|)
name|processAlias
argument_list|(
name|alias
argument_list|,
name|data
operator|.
name|name
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ParseMagic
case|:
block|{
name|priority
operator|=
literal|50
expr_stmt|;
specifier|const
name|QString
name|priorityS
init|=
name|atts
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|priorityAttributeC
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|priorityS
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|parseNumber
argument_list|(
name|priorityS
argument_list|,
operator|&
name|priority
argument_list|,
name|errorMessage
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
name|currentRules
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//qDebug()<< "MAGIC start for mimetype"<< data.name;
block|}
break|break;
case|case
name|ParseMagicMatchRule
case|:
block|{
name|QMimeMagicRule
modifier|*
name|rule
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|createMagicMatchRule
argument_list|(
name|atts
argument_list|,
name|errorMessage
argument_list|,
name|rule
argument_list|)
condition|)
return|return
literal|false
return|;
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
modifier|*
name|ruleList
decl_stmt|;
if|if
condition|(
name|currentRules
operator|.
name|isEmpty
argument_list|()
condition|)
name|ruleList
operator|=
operator|&
name|rules
expr_stmt|;
else|else
comment|// nest this rule into the proper parent
name|ruleList
operator|=
operator|&
name|currentRules
operator|.
name|top
argument_list|()
operator|->
name|m_subMatches
expr_stmt|;
name|ruleList
operator|->
name|append
argument_list|(
operator|*
name|rule
argument_list|)
expr_stmt|;
comment|//qDebug()<< " MATCH added. Stack size was"<< currentRules.size();
name|currentRules
operator|.
name|push
argument_list|(
operator|&
name|ruleList
operator|->
name|last
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|rule
expr_stmt|;
break|break;
block|}
case|case
name|ParseError
case|:
name|reader
operator|.
name|raiseError
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Unexpected element<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
break|break;
comment|// continue switch QXmlStreamReader::Token...
case|case
name|QXmlStreamReader
operator|::
name|EndElement
case|:
comment|// Finished element
block|{
specifier|const
name|QStringRef
name|elementName
init|=
name|reader
operator|.
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
name|elementName
operator|==
name|QLatin1String
argument_list|(
name|mimeTypeTagC
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|process
argument_list|(
name|QMimeType
argument_list|(
name|data
argument_list|)
argument_list|,
name|errorMessage
argument_list|)
condition|)
return|return
literal|false
return|;
name|data
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|elementName
operator|==
name|QLatin1String
argument_list|(
name|matchTagC
argument_list|)
condition|)
block|{
comment|// Closing a<match> tag, pop stack
name|currentRules
operator|.
name|pop
argument_list|()
expr_stmt|;
comment|//qDebug()<< " MATCH closed. Stack size is now"<< currentRules.size();
block|}
elseif|else
if|if
condition|(
name|elementName
operator|==
name|QLatin1String
argument_list|(
name|magicTagC
argument_list|)
condition|)
block|{
comment|//qDebug()<< "MAGIC ended, we got"<< rules.count()<< "rules, with prio"<< priority;
comment|// Finished a<magic> sequence
name|QMimeMagicRuleMatcher
name|ruleMatcher
argument_list|(
name|data
operator|.
name|name
argument_list|,
name|priority
argument_list|)
decl_stmt|;
name|ruleMatcher
operator|.
name|addRules
argument_list|(
name|rules
argument_list|)
expr_stmt|;
name|processMagicMatcher
argument_list|(
name|ruleMatcher
argument_list|)
expr_stmt|;
name|rules
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|reader
operator|.
name|hasError
argument_list|()
condition|)
block|{
if|if
condition|(
name|errorMessage
condition|)
operator|*
name|errorMessage
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"An error has been encountered at line %1 of %2: %3:"
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|,
name|reader
operator|.
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
endif|#
directive|endif
comment|//QT_NO_XMLSTREAMREADER
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
