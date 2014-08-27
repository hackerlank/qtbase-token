begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcollator_p.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|<unicode/utypes.h>
end_include
begin_include
include|#
directive|include
file|<unicode/ucol.h>
end_include
begin_include
include|#
directive|include
file|<unicode/ustring.h>
end_include
begin_include
include|#
directive|include
file|<unicode/ures.h>
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|init
name|void
name|QCollatorPrivate
operator|::
name|init
parameter_list|()
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|QByteArray
name|name
init|=
name|locale
operator|.
name|bcp47Name
argument_list|()
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|collator
operator|=
name|ucol_open
argument_list|(
name|name
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"Could not create collator: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
comment|// enable normalization by default
name|ucol_setAttribute
argument_list|(
name|collator
argument_list|,
name|UCOL_NORMALIZATION_MODE
argument_list|,
name|UCOL_ON
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|// The strength attribute in ICU is rather badly documented. Basically UCOL_PRIMARY
comment|// ignores differences between base characters and accented characters as well as case.
comment|// So A and A-umlaut would compare equal.
comment|// UCOL_SECONDARY ignores case differences. UCOL_TERTIARY is the default in most languages
comment|// and does case sensitive comparison.
comment|// UCOL_QUATERNARY is used as default in a few languages such as Japanese to take care of some
comment|// additional differences in those languages.
name|UColAttributeValue
name|val
init|=
operator|(
name|caseSensitivity
operator|==
name|Qt
operator|::
name|CaseSensitive
operator|)
condition|?
name|UCOL_DEFAULT_STRENGTH
else|:
name|UCOL_SECONDARY
decl_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucol_setAttribute
argument_list|(
name|collator
argument_list|,
name|UCOL_STRENGTH
argument_list|,
name|val
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"ucol_setAttribute: Case First failed: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucol_setAttribute
argument_list|(
name|collator
argument_list|,
name|UCOL_NUMERIC_COLLATION
argument_list|,
name|numericMode
condition|?
name|UCOL_ON
else|:
name|UCOL_OFF
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"ucol_setAttribute: numeric collation failed: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|ucol_setAttribute
argument_list|(
name|collator
argument_list|,
name|UCOL_ALTERNATE_HANDLING
argument_list|,
name|ignorePunctuation
condition|?
name|UCOL_SHIFTED
else|:
name|UCOL_NON_IGNORABLE
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"ucol_setAttribute: Alternate handling failed: %d"
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|dirty
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QCollatorPrivate
operator|::
name|cleanup
parameter_list|()
block|{
if|if
condition|(
name|collator
condition|)
name|ucol_close
argument_list|(
name|collator
argument_list|)
expr_stmt|;
name|collator
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QChar
modifier|*
name|s1
parameter_list|,
name|int
name|len1
parameter_list|,
specifier|const
name|QChar
modifier|*
name|s2
parameter_list|,
name|int
name|len2
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|dirty
condition|)
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
return|return
name|ucol_strcoll
argument_list|(
name|d
operator|->
name|collator
argument_list|,
operator|(
specifier|const
name|UChar
operator|*
operator|)
name|s1
argument_list|,
name|len1
argument_list|,
operator|(
specifier|const
name|UChar
operator|*
operator|)
name|s2
argument_list|,
name|len2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QString
modifier|&
name|s1
parameter_list|,
specifier|const
name|QString
modifier|&
name|s2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|s1
operator|.
name|constData
argument_list|()
argument_list|,
name|s1
operator|.
name|size
argument_list|()
argument_list|,
name|s2
operator|.
name|constData
argument_list|()
argument_list|,
name|s2
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|s1
parameter_list|,
specifier|const
name|QStringRef
modifier|&
name|s2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|s1
operator|.
name|constData
argument_list|()
argument_list|,
name|s1
operator|.
name|size
argument_list|()
argument_list|,
name|s2
operator|.
name|constData
argument_list|()
argument_list|,
name|s2
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sortKey
name|QCollatorSortKey
name|QCollator
operator|::
name|sortKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|dirty
condition|)
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|QByteArray
name|result
argument_list|(
literal|16
operator|+
name|string
operator|.
name|size
argument_list|()
operator|+
operator|(
name|string
operator|.
name|size
argument_list|()
operator|>>
literal|2
operator|)
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|int
name|size
init|=
name|ucol_getSortKey
argument_list|(
name|d
operator|->
name|collator
argument_list|,
operator|(
specifier|const
name|UChar
operator|*
operator|)
name|string
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
name|result
operator|.
name|data
argument_list|()
argument_list|,
name|result
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|>
name|result
operator|.
name|size
argument_list|()
condition|)
block|{
name|result
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|size
operator|=
name|ucol_getSortKey
argument_list|(
name|d
operator|->
name|collator
argument_list|,
operator|(
specifier|const
name|UChar
operator|*
operator|)
name|string
operator|.
name|constData
argument_list|()
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
name|result
operator|.
name|data
argument_list|()
argument_list|,
name|result
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|truncate
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
name|QCollatorSortKey
argument_list|(
operator|new
name|QCollatorSortKeyPrivate
argument_list|(
name|result
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollatorSortKey
operator|::
name|compare
parameter_list|(
specifier|const
name|QCollatorSortKey
modifier|&
name|otherKey
parameter_list|)
specifier|const
block|{
return|return
name|qstrcmp
argument_list|(
name|d
operator|->
name|m_key
argument_list|,
name|otherKey
operator|.
name|d
operator|->
name|m_key
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
