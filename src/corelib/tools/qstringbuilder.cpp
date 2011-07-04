begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstringbuilder.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextcodec.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QStringBuilder     \internal     \reentrant     \since 4.6      \brief The QStringBuilder class is a template class that provides a facility to build up QStrings from smaller chunks.      \ingroup tools     \ingroup shared     \ingroup string-processing       To build a QString by multiple concatenations, QString::operator+()     is typically used. This causes \e{n - 1} reallocations when building     a string from \e{n} chunks.      QStringBuilder uses expression templates to collect the individual     chunks, compute the total size, allocate the required amount of     memory for the final QString object, and copy the chunks into the     allocated memory.      The QStringBuilder class is not to be used explicitly in user     code.  Instances of the class are created as return values of the     operator%() function, acting on objects of type QString,     QLatin1String, QStringRef, QChar, QCharRef,     QLatin1Char, and \c char.      Concatenating strings with operator%() generally yields better     performance then using \c QString::operator+() on the same chunks     if there are three or more of them, and performs equally well in other     cases.      \sa QLatin1String, QString */
comment|/*! \fn QStringBuilder::QStringBuilder(const A&a, const B&b)   Constructs a QStringBuilder from \a a and \a b.  */
comment|/* \fn QStringBuilder::operator%(const A&a, const B&b)      Returns a \c QStringBuilder object that is converted to a QString object     when assigned to a variable of QString type or passed to a function that     takes a QString parameter.      This function is usable with arguments of type \c QString,     \c QLatin1String, \c QStringRef,     \c QChar, \c QCharRef, \c QLatin1Char, and \c char. */
comment|/*! \fn QByteArray QStringBuilder::toLatin1() const   Returns a Latin-1 representation of the string as a QByteArray.  The   returned byte array is undefined if the string contains non-Latin1   characters.  */
comment|/*!     \fn operator QStringBuilder::QString() const       Converts the \c QLatin1String into a \c QString object. */
comment|/*! \internal    Note: The len contains the ending \0  */
DECL|function|convertFromAscii
name|void
name|QAbstractConcatenable
operator|::
name|convertFromAscii
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|int
name|len
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
if|if
condition|(
name|QString
operator|::
name|codecForCStrings
operator|&&
name|len
condition|)
block|{
name|QString
name|tmp
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|a
argument_list|,
name|len
operator|>
literal|0
condition|?
name|len
operator|-
literal|1
else|:
operator|-
literal|1
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|out
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|tmp
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
name|tmp
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|+=
name|tmp
operator|.
name|length
argument_list|()
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|len
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|a
condition|)
return|return;
while|while
condition|(
operator|*
name|a
condition|)
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
operator|*
name|a
operator|++
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
operator|-
literal|1
condition|;
operator|++
name|i
control|)
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
name|a
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|convertToAscii
name|void
name|QAbstractConcatenable
operator|::
name|convertToAscii
parameter_list|(
specifier|const
name|QChar
modifier|*
name|a
parameter_list|,
name|int
name|len
parameter_list|,
name|char
modifier|*
modifier|&
name|out
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
if|if
condition|(
name|QString
operator|::
name|codecForCStrings
condition|)
block|{
name|QByteArray
name|tmp
init|=
name|QString
operator|::
name|codecForCStrings
operator|->
name|fromUnicode
argument_list|(
name|a
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|out
argument_list|,
name|tmp
operator|.
name|constData
argument_list|()
argument_list|,
name|tmp
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|+=
name|tmp
operator|.
name|length
argument_list|()
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|len
operator|==
operator|-
literal|1
condition|)
block|{
while|while
condition|(
name|a
operator|->
name|unicode
argument_list|()
condition|)
name|convertToLatin1
argument_list|(
operator|*
name|a
operator|++
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
name|convertToLatin1
argument_list|(
name|a
index|[
name|i
index|]
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
