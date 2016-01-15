begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qtextboundaryfinder.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<private/qunicodetools_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTextBoundaryFinderPrivate
class|class
name|QTextBoundaryFinderPrivate
block|{
public|public:
DECL|member|attributes
name|QCharAttributes
name|attributes
index|[
literal|1
index|]
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
specifier|static
name|void
name|init
parameter_list|(
name|QTextBoundaryFinder
operator|::
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QChar
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|QCharAttributes
modifier|*
name|attributes
parameter_list|)
block|{
specifier|const
name|ushort
modifier|*
name|string
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|ushort
operator|*
argument_list|>
argument_list|(
name|chars
argument_list|)
decl_stmt|;
name|QVarLengthArray
argument_list|<
name|QUnicodeTools
operator|::
name|ScriptItem
argument_list|>
name|scriptItems
decl_stmt|;
block|{
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|scripts
argument_list|(
name|length
argument_list|)
decl_stmt|;
name|QUnicodeTools
operator|::
name|initScripts
argument_list|(
name|string
argument_list|,
name|length
argument_list|,
name|scripts
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|start
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|start
operator|+
literal|1
init|;
name|i
operator|<=
name|length
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|==
name|length
operator|||
name|scripts
index|[
name|i
index|]
operator|!=
name|scripts
index|[
name|start
index|]
condition|)
block|{
name|QUnicodeTools
operator|::
name|ScriptItem
name|item
decl_stmt|;
name|item
operator|.
name|position
operator|=
name|start
expr_stmt|;
name|item
operator|.
name|script
operator|=
name|scripts
index|[
name|start
index|]
expr_stmt|;
name|scriptItems
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|start
operator|=
name|i
expr_stmt|;
block|}
block|}
block|}
name|QUnicodeTools
operator|::
name|CharAttributeOptions
name|options
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QTextBoundaryFinder
operator|::
name|Grapheme
case|:
name|options
operator||=
name|QUnicodeTools
operator|::
name|GraphemeBreaks
expr_stmt|;
break|break;
case|case
name|QTextBoundaryFinder
operator|::
name|Word
case|:
name|options
operator||=
name|QUnicodeTools
operator|::
name|WordBreaks
expr_stmt|;
break|break;
case|case
name|QTextBoundaryFinder
operator|::
name|Sentence
case|:
name|options
operator||=
name|QUnicodeTools
operator|::
name|SentenceBreaks
expr_stmt|;
break|break;
case|case
name|QTextBoundaryFinder
operator|::
name|Line
case|:
name|options
operator||=
name|QUnicodeTools
operator|::
name|LineBreaks
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|QUnicodeTools
operator|::
name|initCharAttributes
argument_list|(
name|string
argument_list|,
name|length
argument_list|,
name|scriptItems
operator|.
name|data
argument_list|()
argument_list|,
name|scriptItems
operator|.
name|count
argument_list|()
argument_list|,
name|attributes
argument_list|,
name|options
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QTextBoundaryFinder     \inmodule QtCore      \brief The QTextBoundaryFinder class provides a way of finding Unicode text boundaries in a string.      \since 4.4     \ingroup tools     \ingroup shared     \ingroup string-processing     \reentrant      QTextBoundaryFinder allows to find Unicode text boundaries in a     string, accordingly to the Unicode text boundary specification (see     \l{http://www.unicode.org/reports/tr14/}{Unicode Standard Annex #14} and     \l{http://www.unicode.org/reports/tr29/}{Unicode Standard Annex #29}).      QTextBoundaryFinder can operate on a QString in four possible     modes depending on the value of \a BoundaryType.      Units of Unicode characters that make up what the user thinks of     as a character or basic unit of the language are here called     Grapheme clusters. The two unicode characters 'A' + diaeresis do     for example form one grapheme cluster as the user thinks of them     as one character, yet it is in this case represented by two     unicode code points     (see \l{http://www.unicode.org/reports/tr29/#Grapheme_Cluster_Boundaries}).      Word boundaries are there to locate the start and end of what a     language considers to be a word     (see \l{http://www.unicode.org/reports/tr29/#Word_Boundaries}).      Line break boundaries give possible places where a line break     might happen and sentence boundaries will show the beginning and     end of whole sentences     (see \l{http://www.unicode.org/reports/tr29/#Sentence_Boundaries} and     \l{http://www.unicode.org/reports/tr14/}).      The first position in a string is always a valid boundary and     refers to the position before the first character. The last     position at the length of the string is also valid and refers     to the position after the last character. */
end_comment
begin_comment
comment|/*!     \enum QTextBoundaryFinder::BoundaryType      \value Grapheme Finds a grapheme which is the smallest boundary. It                     including letters, punctuation marks, numerals and more.     \value Word Finds a word.     \value Line Finds possible positions for breaking the text into multiple     lines.     \value Sentence Finds sentence boundaries. These include periods, question     marks etc. */
end_comment
begin_comment
comment|/*!   \enum QTextBoundaryFinder::BoundaryReason    \value NotAtBoundary  The boundary finder is not at a boundary position.   \value BreakOpportunity  The boundary finder is at a break opportunity position.                            Such a break opportunity might also be an item boundary                            (either StartOfItem, EndOfItem, or combination of both),                            a mandatory line break, or a soft hyphen.   \value StartOfItem  Since 5.0. The boundary finder is at the start of                       a grapheme, a word, a sentence, or a line.   \value EndOfItem  Since 5.0. The boundary finder is at the end of                     a grapheme, a word, a sentence, or a line.   \value MandatoryBreak  Since 5.0. The boundary finder is at the end of line                          (can occur for a Line boundary type only).   \value SoftHyphen  The boundary finder is at the soft hyphen                      (can occur for a Line boundary type only). */
end_comment
begin_comment
comment|/*!   Constructs an invalid QTextBoundaryFinder object. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|()
member_init_list|:
name|t
argument_list|(
name|Grapheme
argument_list|)
member_init_list|,
name|chars
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|length
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Copies the QTextBoundaryFinder object, \a other. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
specifier|const
name|QTextBoundaryFinder
modifier|&
name|other
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|other
operator|.
name|t
argument_list|)
member_init_list|,
name|s
argument_list|(
name|other
operator|.
name|s
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|other
operator|.
name|chars
argument_list|)
member_init_list|,
name|length
argument_list|(
name|other
operator|.
name|length
argument_list|)
member_init_list|,
name|pos
argument_list|(
name|other
operator|.
name|pos
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|other
operator|.
name|d
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|length
operator|>
literal|0
argument_list|)
expr_stmt|;
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|,
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!   Assigns the object, \a other, to another QTextBoundaryFinder object. */
end_comment
begin_function
DECL|function|operator =
name|QTextBoundaryFinder
modifier|&
name|QTextBoundaryFinder
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QTextBoundaryFinder
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
operator|&
name|other
operator|==
name|this
condition|)
return|return
operator|*
name|this
return|;
if|if
condition|(
name|other
operator|.
name|d
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|other
operator|.
name|length
operator|>
literal|0
argument_list|)
expr_stmt|;
name|uint
name|newCapacity
init|=
operator|(
name|other
operator|.
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
decl_stmt|;
name|QTextBoundaryFinderPrivate
modifier|*
name|newD
init|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|realloc
argument_list|(
name|freePrivate
condition|?
name|d
else|:
literal|0
argument_list|,
name|newCapacity
argument_list|)
decl_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|newD
argument_list|)
expr_stmt|;
name|freePrivate
operator|=
literal|true
expr_stmt|;
name|d
operator|=
name|newD
expr_stmt|;
block|}
name|t
operator|=
name|other
operator|.
name|t
expr_stmt|;
name|s
operator|=
name|other
operator|.
name|s
expr_stmt|;
name|chars
operator|=
name|other
operator|.
name|chars
expr_stmt|;
name|length
operator|=
name|other
operator|.
name|length
expr_stmt|;
name|pos
operator|=
name|other
operator|.
name|pos
expr_stmt|;
if|if
condition|(
name|other
operator|.
name|d
condition|)
block|{
name|memcpy
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|,
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|freePrivate
condition|)
name|free
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!   Destructs the QTextBoundaryFinder object. */
end_comment
begin_destructor
DECL|function|~QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|~
name|QTextBoundaryFinder
parameter_list|()
block|{
name|Q_UNUSED
argument_list|(
name|unused
argument_list|)
expr_stmt|;
if|if
condition|(
name|freePrivate
condition|)
name|free
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Creates a QTextBoundaryFinder object of \a type operating on \a string. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|type
argument_list|)
member_init_list|,
name|s
argument_list|(
name|string
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|string
operator|.
name|unicode
argument_list|()
argument_list|)
member_init_list|,
name|length
argument_list|(
name|string
operator|.
name|length
argument_list|()
argument_list|)
member_init_list|,
name|pos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|length
operator|>
literal|0
condition|)
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|init
argument_list|(
name|t
argument_list|,
name|chars
argument_list|,
name|length
argument_list|,
name|d
operator|->
name|attributes
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!   Creates a QTextBoundaryFinder object of \a type operating on \a chars   with \a length.    \a buffer is an optional working buffer of size \a bufferSize you can pass to   the QTextBoundaryFinder. If the buffer is large enough to hold the working   data required (bufferSize>= length + 1), it will use this   instead of allocating its own buffer.    \warning QTextBoundaryFinder does not create a copy of \a chars. It is the   application programmer's responsibility to ensure the array is allocated for   as long as the QTextBoundaryFinder object stays alive. The same applies to   \a buffer. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QChar
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|bufferSize
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|type
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|chars
argument_list|)
member_init_list|,
name|length
argument_list|(
name|length
argument_list|)
member_init_list|,
name|pos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|chars
condition|)
block|{
name|length
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|length
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|buffer
operator|&&
operator|(
name|uint
operator|)
name|bufferSize
operator|>=
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
condition|)
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|buffer
expr_stmt|;
name|freePrivate
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|length
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|QCharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
name|init
argument_list|(
name|t
argument_list|,
name|chars
argument_list|,
name|length
argument_list|,
name|d
operator|->
name|attributes
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!   Moves the finder to the start of the string. This is equivalent to setPosition(0).    \sa setPosition(), position() */
end_comment
begin_function
DECL|function|toStart
name|void
name|QTextBoundaryFinder
operator|::
name|toStart
parameter_list|()
block|{
name|pos
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Moves the finder to the end of the string. This is equivalent to setPosition(string.length()).    \sa setPosition(), position() */
end_comment
begin_function
DECL|function|toEnd
name|void
name|QTextBoundaryFinder
operator|::
name|toEnd
parameter_list|()
block|{
name|pos
operator|=
name|length
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the current position of the QTextBoundaryFinder.    The range is from 0 (the beginning of the string) to the length of   the string inclusive.    \sa setPosition() */
end_comment
begin_function
DECL|function|position
name|int
name|QTextBoundaryFinder
operator|::
name|position
parameter_list|()
specifier|const
block|{
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the current position of the QTextBoundaryFinder to \a position.    If \a position is out of bounds, it will be bound to only valid   positions. In this case, valid positions are from 0 to the length of   the string inclusive.    \sa position() */
end_comment
begin_function
DECL|function|setPosition
name|void
name|QTextBoundaryFinder
operator|::
name|setPosition
parameter_list|(
name|int
name|position
parameter_list|)
block|{
name|pos
operator|=
name|qBound
argument_list|(
literal|0
argument_list|,
name|position
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn QTextBoundaryFinder::BoundaryType QTextBoundaryFinder::type() const    Returns the type of the QTextBoundaryFinder. */
end_comment
begin_comment
comment|/*! \fn bool QTextBoundaryFinder::isValid() const     Returns \c true if the text boundary finder is valid; otherwise returns \c false.    A default QTextBoundaryFinder is invalid. */
end_comment
begin_comment
comment|/*!   Returns the string  the QTextBoundaryFinder object operates on. */
end_comment
begin_function
DECL|function|string
name|QString
name|QTextBoundaryFinder
operator|::
name|string
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|chars
operator|==
name|s
operator|.
name|unicode
argument_list|()
operator|&&
name|length
operator|==
name|s
operator|.
name|length
argument_list|()
condition|)
return|return
name|s
return|;
return|return
name|QString
argument_list|(
name|chars
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Moves the QTextBoundaryFinder to the next boundary position and returns that position.    Returns -1 if there is no next boundary. */
end_comment
begin_function
DECL|function|toNextBoundary
name|int
name|QTextBoundaryFinder
operator|::
name|toNextBoundary
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|pos
operator|<
literal|0
operator|||
name|pos
operator|>=
name|length
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
operator|++
name|pos
expr_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|graphemeBoundary
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Word
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBreak
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Sentence
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Line
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|lineBreak
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Moves the QTextBoundaryFinder to the previous boundary position and returns that position.    Returns -1 if there is no previous boundary. */
end_comment
begin_function
DECL|function|toPreviousBoundary
name|int
name|QTextBoundaryFinder
operator|::
name|toPreviousBoundary
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|pos
operator|<=
literal|0
operator|||
name|pos
operator|>
name|length
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
operator|--
name|pos
expr_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|graphemeBoundary
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Word
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBreak
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Sentence
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Line
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|lineBreak
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Returns \c true if the object's position() is currently at a valid text boundary. */
end_comment
begin_function
DECL|function|isAtBoundary
name|bool
name|QTextBoundaryFinder
operator|::
name|isAtBoundary
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|pos
argument_list|<
literal|0
operator|||
name|pos
argument_list|>
name|length
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|graphemeBoundary
return|;
case|case
name|Word
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBreak
return|;
case|case
name|Sentence
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
return|;
case|case
name|Line
case|:
comment|// ### TR#14 LB2 prohibits break at sot
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|lineBreak
operator|||
name|pos
operator|==
literal|0
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the reasons for the boundary finder to have chosen the current position as a boundary. */
end_comment
begin_function
DECL|function|boundaryReasons
name|QTextBoundaryFinder
operator|::
name|BoundaryReasons
name|QTextBoundaryFinder
operator|::
name|boundaryReasons
parameter_list|()
specifier|const
block|{
name|BoundaryReasons
name|reasons
init|=
name|NotAtBoundary
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|||
name|pos
argument_list|<
literal|0
operator|||
name|pos
argument_list|>
name|length
condition|)
return|return
name|reasons
return|;
specifier|const
name|QCharAttributes
name|attr
init|=
name|d
operator|->
name|attributes
index|[
name|pos
index|]
decl_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
if|if
condition|(
name|attr
operator|.
name|graphemeBoundary
condition|)
block|{
name|reasons
operator||=
name|BreakOpportunity
operator||
name|StartOfItem
operator||
name|EndOfItem
expr_stmt|;
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|EndOfItem
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|==
name|length
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|StartOfItem
operator|)
expr_stmt|;
block|}
break|break;
case|case
name|Word
case|:
if|if
condition|(
name|attr
operator|.
name|wordBreak
condition|)
block|{
name|reasons
operator||=
name|BreakOpportunity
expr_stmt|;
if|if
condition|(
name|attr
operator|.
name|wordStart
condition|)
name|reasons
operator||=
name|StartOfItem
expr_stmt|;
if|if
condition|(
name|attr
operator|.
name|wordEnd
condition|)
name|reasons
operator||=
name|EndOfItem
expr_stmt|;
block|}
break|break;
case|case
name|Sentence
case|:
if|if
condition|(
name|attr
operator|.
name|sentenceBoundary
condition|)
block|{
name|reasons
operator||=
name|BreakOpportunity
operator||
name|StartOfItem
operator||
name|EndOfItem
expr_stmt|;
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|EndOfItem
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|==
name|length
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|StartOfItem
operator|)
expr_stmt|;
block|}
break|break;
case|case
name|Line
case|:
comment|// ### TR#14 LB2 prohibits break at sot
if|if
condition|(
name|attr
operator|.
name|lineBreak
operator|||
name|pos
operator|==
literal|0
condition|)
block|{
name|reasons
operator||=
name|BreakOpportunity
expr_stmt|;
if|if
condition|(
name|attr
operator|.
name|mandatoryBreak
operator|||
name|pos
operator|==
literal|0
condition|)
block|{
name|reasons
operator||=
name|MandatoryBreak
operator||
name|StartOfItem
operator||
name|EndOfItem
expr_stmt|;
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|EndOfItem
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|==
name|length
condition|)
name|reasons
operator|&=
operator|(
operator|~
name|StartOfItem
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pos
operator|>
literal|0
operator|&&
name|chars
index|[
name|pos
operator|-
literal|1
index|]
operator|.
name|unicode
argument_list|()
operator|==
name|QChar
operator|::
name|SoftHyphen
condition|)
block|{
name|reasons
operator||=
name|SoftHyphen
expr_stmt|;
block|}
block|}
break|break;
default|default:
break|break;
block|}
return|return
name|reasons
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
