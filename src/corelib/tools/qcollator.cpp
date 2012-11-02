begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
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
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCollatorPrivate
class|class
name|QCollatorPrivate
block|{
public|public:
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|locale
name|QLocale
name|locale
decl_stmt|;
DECL|member|collation
name|QCollator
operator|::
name|Collation
name|collation
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
DECL|member|collator
name|UCollator
modifier|*
name|collator
decl_stmt|;
else|#
directive|else
DECL|member|collator
name|void
modifier|*
name|collator
decl_stmt|;
endif|#
directive|endif
DECL|member|indexCharacters
name|QStringList
name|indexCharacters
decl_stmt|;
DECL|function|clear
name|void
name|clear
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_USE_ICU
if|if
condition|(
name|collator
condition|)
name|ucol_close
argument_list|(
name|collator
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|collator
operator|=
literal|0
expr_stmt|;
name|indexCharacters
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|QCollatorPrivate
name|QCollatorPrivate
parameter_list|()
member_init_list|:
name|collation
argument_list|(
name|QCollator
operator|::
name|Default
argument_list|)
member_init_list|,
name|collator
argument_list|(
literal|0
argument_list|)
block|{
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|~
name|QCollatorPrivate
parameter_list|()
destructor_decl|;
private|private:
name|Q_DISABLE_COPY
argument_list|(
argument|QCollatorPrivate
argument_list|)
block|}
class|;
end_class
begin_destructor
DECL|function|~QCollatorPrivate
name|QCollatorPrivate
operator|::
name|~
name|QCollatorPrivate
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_decl_stmt
DECL|variable|collationStringsCount
specifier|static
specifier|const
name|int
name|collationStringsCount
init|=
literal|13
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|collationStrings
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|collationStrings
index|[
name|collationStringsCount
index|]
init|=
block|{
literal|"default"
block|,
literal|"big5han"
block|,
literal|"dictionary"
block|,
literal|"direct"
block|,
literal|"gb2312han"
block|,
literal|"phonebook"
block|,
literal|"pinyin"
block|,
literal|"phonetic"
block|,
literal|"reformed"
block|,
literal|"standard"
block|,
literal|"stroke"
block|,
literal|"traditional"
block|,
literal|"unihan"
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QCollator     \inmodule QtCore     \brief The QCollator class compares strings according to a localized collation algorithm.      \internal      \reentrant     \ingroup i18n     \ingroup string-processing     \ingroup shared      QCollator is initialized with a QLocale and an optional collation strategy. It tries to     initialize the collator with the specified values. The collator can then be used to compare     and sort strings in a locale dependent fashion.      A QCollator object can be used together with template based sorting algorithms such as std::sort     to sort a list of QStrings.      In addition to the locale and collation strategy, several optional flags can be set that influence     the result of the collation. */
end_comment
begin_comment
comment|/*!     Constructs a QCollator from \a locale and \a collation. If \a collation is not     specified the default collation algorithm for the locale is being used. If     \a locale is not specified QLocale::default() is being used.      \sa setLocale, setCollation, setOptions  */
end_comment
begin_constructor
DECL|function|QCollator
name|QCollator
operator|::
name|QCollator
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|,
name|QCollator
operator|::
name|Collation
name|collation
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCollatorPrivate
argument_list|)
block|{
name|d
operator|->
name|locale
operator|=
name|locale
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|collation
operator|>=
literal|0
operator|&&
operator|(
name|int
operator|)
name|collation
operator|<
name|collationStringsCount
condition|)
name|d
operator|->
name|collation
operator|=
name|collation
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Creates a copy of \a other.  */
end_comment
begin_constructor
DECL|function|QCollator
name|QCollator
operator|::
name|QCollator
parameter_list|(
specifier|const
name|QCollator
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the collator.  */
end_comment
begin_destructor
DECL|function|~QCollator
name|QCollator
operator|::
name|~
name|QCollator
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Assigns \a other to this collator.  */
end_comment
begin_function
DECL|function|operator =
name|QCollator
modifier|&
name|QCollator
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QCollator
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|other
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|init
name|void
name|QCollator
operator|::
name|init
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|(
name|int
operator|)
name|d
operator|->
name|collation
operator|<
name|collationStringsCount
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
specifier|const
name|char
modifier|*
name|collationString
init|=
name|collationStrings
index|[
operator|(
name|int
operator|)
name|d
operator|->
name|collation
index|]
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|QByteArray
name|name
init|=
operator|(
name|d
operator|->
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
operator|+
name|QLatin1String
argument_list|(
literal|"@collation="
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|collationString
argument_list|)
operator|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|d
operator|->
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
name|d
operator|->
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
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|detach
name|void
name|QCollator
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
block|{
name|QCollatorPrivate
modifier|*
name|x
init|=
operator|new
name|QCollatorPrivate
decl_stmt|;
name|x
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|x
operator|->
name|locale
operator|=
name|d
operator|->
name|locale
expr_stmt|;
name|x
operator|->
name|collation
operator|=
name|d
operator|->
name|collation
expr_stmt|;
name|x
operator|->
name|collator
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|x
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the locale of the collator to \a locale.  */
end_comment
begin_function
DECL|function|setLocale
name|void
name|QCollator
operator|::
name|setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|locale
operator|=
name|locale
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the locale of the collator.  */
end_comment
begin_function
DECL|function|locale
name|QLocale
name|QCollator
operator|::
name|locale
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|locale
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QCollator::Collation      This enum can be used to specify an alternate collation algorithm to be used instead     of the default algorithm for the locale.      Possible values are:      \value Default Use the default algorithm for the locale     \value Big5Han     \value Direct     \value GB2312Han     \value PhoneBook     \value Pinyin     \value Phonetic     \value Reformed     \value Standard     \value Stroke     \value Traditional     \value UniHan */
end_comment
begin_comment
comment|/*!     Sets the collation algorithm to be used.      \sa QCollator::Collation  */
end_comment
begin_function
DECL|function|setCollation
name|void
name|QCollator
operator|::
name|setCollation
parameter_list|(
name|QCollator
operator|::
name|Collation
name|collation
parameter_list|)
block|{
if|if
condition|(
operator|(
name|int
operator|)
name|collation
operator|<
literal|0
operator|||
operator|(
name|int
operator|)
name|collation
operator|>=
name|collationStringsCount
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|collation
operator|=
name|collation
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the currently used collation algorithm.      \sa QCollator::Collation  */
end_comment
begin_function
DECL|function|collation
name|QCollator
operator|::
name|Collation
name|QCollator
operator|::
name|collation
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|collation
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a unique identifer for this collation object.      This method is helpful to save and restore defined collation     objects.      \sa fromIdentifier  */
end_comment
begin_function
DECL|function|identifier
name|QString
name|QCollator
operator|::
name|identifier
parameter_list|()
specifier|const
block|{
name|QString
name|id
init|=
name|d
operator|->
name|locale
operator|.
name|bcp47Name
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|collation
operator|!=
name|QCollator
operator|::
name|Default
condition|)
block|{
name|id
operator|+=
name|QLatin1String
argument_list|(
literal|"@collation="
argument_list|)
expr_stmt|;
name|id
operator|+=
name|QLatin1String
argument_list|(
name|collationStrings
index|[
name|d
operator|->
name|collation
index|]
argument_list|)
expr_stmt|;
block|}
comment|// this ensures the ID is compatible with ICU
name|id
operator|.
name|replace
argument_list|(
literal|'-'
argument_list|,
literal|'_'
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function
begin_comment
comment|/*!     Creates a QCollator from a unique identifier and returns it.      \sa identifier  */
end_comment
begin_function
DECL|function|fromIdentifier
name|QCollator
name|QCollator
operator|::
name|fromIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|identifier
parameter_list|)
block|{
name|QString
name|localeString
init|=
name|identifier
decl_stmt|;
name|QString
name|collationString
decl_stmt|;
name|int
name|at
init|=
name|identifier
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'@'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|at
operator|>=
literal|0
condition|)
block|{
name|localeString
operator|=
name|identifier
operator|.
name|left
argument_list|(
name|at
argument_list|)
expr_stmt|;
name|collationString
operator|=
name|identifier
operator|.
name|mid
argument_list|(
name|at
operator|+
name|strlen
argument_list|(
literal|"@collation="
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QLocale
name|locale
argument_list|(
name|localeString
argument_list|)
decl_stmt|;
name|Collation
name|collation
init|=
name|Default
decl_stmt|;
if|if
condition|(
operator|!
name|collationString
operator|.
name|isEmpty
argument_list|()
condition|)
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
name|collationStringsCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLatin1String
argument_list|(
name|collationStrings
index|[
name|i
index|]
argument_list|)
operator|==
name|collationString
condition|)
block|{
name|collation
operator|=
name|Collation
argument_list|(
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
return|return
name|QCollator
argument_list|(
name|locale
argument_list|,
name|collation
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!      \enum QCollator::CasePreference      This enum can be used to tailor the case preference during collation.      \value CasePreferenceOff No case preference, use what is the standard for the locale     \value CasePreferenceUpper Sort upper case characters before lower case     \value CasePreferenceLower Sort lower case characters before upper case */
end_comment
begin_comment
comment|/*!     Sets the case preference of the collator.      \sa QCollator::CasePreference  */
end_comment
begin_function
DECL|function|setCasePreference
name|void
name|QCollator
operator|::
name|setCasePreference
parameter_list|(
name|CasePreference
name|c
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UColAttributeValue
name|val
init|=
name|UCOL_OFF
decl_stmt|;
if|if
condition|(
name|c
operator|==
name|QCollator
operator|::
name|CasePreferenceUpper
condition|)
name|val
operator|=
name|UCOL_UPPER_FIRST
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
name|QCollator
operator|::
name|CasePreferenceLower
condition|)
name|val
operator|=
name|UCOL_LOWER_FIRST
expr_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|ucol_setAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_CASE_FIRST
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
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|c
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns case preference of the collator.      \sa QCollator::CasePreference  */
end_comment
begin_function
DECL|function|casePreference
name|QCollator
operator|::
name|CasePreference
name|QCollator
operator|::
name|casePreference
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
switch|switch
condition|(
name|ucol_getAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_CASE_FIRST
argument_list|,
operator|&
name|status
argument_list|)
condition|)
block|{
case|case
name|UCOL_UPPER_FIRST
case|:
return|return
name|QCollator
operator|::
name|CasePreferenceUpper
return|;
case|case
name|UCOL_LOWER_FIRST
case|:
return|return
name|QCollator
operator|::
name|CasePreferenceLower
return|;
case|case
name|UCOL_OFF
case|:
default|default:
break|break;
block|}
endif|#
directive|endif
return|return
name|QCollator
operator|::
name|CasePreferenceOff
return|;
block|}
end_function
begin_comment
comment|/*!     Enables numeric sorting mode when \a on is set to true.      This will enable proper sorting of numeric digits, so that e.g. 100 sorts after 99.      By default this mode is off.  */
end_comment
begin_function
DECL|function|setNumericMode
name|void
name|QCollator
operator|::
name|setNumericMode
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|ucol_setAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_NUMERIC_COLLATION
argument_list|,
name|on
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
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|on
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns true if numeric sorting is enabled, false otherwise.      \sa setNumericMode  */
end_comment
begin_function
DECL|function|numericMode
name|bool
name|QCollator
operator|::
name|numericMode
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UErrorCode
name|status
decl_stmt|;
if|if
condition|(
name|ucol_getAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_NUMERIC_COLLATION
argument_list|,
operator|&
name|status
argument_list|)
operator|==
name|UCOL_ON
condition|)
return|return
literal|true
return|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     If set to true, punctuation characters and symbols are ignored when determining sort order.      The default is locale dependent.  */
end_comment
begin_function
DECL|function|setIgnorePunctuation
name|void
name|QCollator
operator|::
name|setIgnorePunctuation
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UErrorCode
name|status
decl_stmt|;
name|ucol_setAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_ALTERNATE_HANDLING
argument_list|,
name|on
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
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|on
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns true if punctuation characters and symbols are ignored when determining sort order.      \sa setIgnorePunctuation  */
end_comment
begin_function
DECL|function|ignorePunctuation
name|bool
name|QCollator
operator|::
name|ignorePunctuation
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|UErrorCode
name|status
decl_stmt|;
if|if
condition|(
name|ucol_getAttribute
argument_list|(
name|d
operator|->
name|collator
argument_list|,
name|UCOL_ALTERNATE_HANDLING
argument_list|,
operator|&
name|status
argument_list|)
operator|==
name|UCOL_SHIFTED
condition|)
return|return
literal|true
return|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Compares \a s1 with \a s2. Returns -1, 0 or 1 depending on whether \a s1 is     smaller, equal or larger than \a s2.  */
end_comment
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
begin_comment
comment|/*!     \overload      Compares \a s1 with \a s2. Returns -1, 0 or 1 depending on whether \a s1 is     smaller, equal or larger than \a s2.  */
end_comment
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
begin_comment
comment|/*!     \overload      Compares \a s1 with \a s2. \a len1 and \a len2 specify the length of the     QChar arrays pointer to by \a s1 and \a s2.      Returns -1, 0 or 1 depending on whether \a s1 is smaller, equal or larger than \a s2.  */
end_comment
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
ifdef|#
directive|ifdef
name|QT_USE_ICU
specifier|const
name|UCollationResult
name|result
init|=
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
decl_stmt|;
return|return
name|result
return|;
else|#
directive|else
return|return
name|QString
operator|::
name|compare_helper
argument_list|(
operator|(
specifier|const
name|QChar
operator|*
operator|)
name|s1
argument_list|,
name|len1
argument_list|,
operator|(
specifier|const
name|QChar
operator|*
operator|)
name|s2
argument_list|,
name|len2
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns a sortKey for \a string. The sortkey can be used as a placeholder     for the string that can be then sorted using regular strcmp based sorting.      Creating the sort key is usually somewhat slower, then using the compare()     methods directly. But if the string is compared repeatedly (e.g. when sorting     a whole list of strings), it's usually faster to create the sort keys for each     string and then sort using the keys.  */
end_comment
begin_function
DECL|function|sortKey
name|QByteArray
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
ifdef|#
directive|ifdef
name|QT_USE_ICU
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
name|result
return|;
else|#
directive|else
return|return
name|string
operator|.
name|toLower
argument_list|()
operator|.
name|toUtf8
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|englishIndexCharacters
specifier|static
name|QStringList
name|englishIndexCharacters
parameter_list|()
block|{
name|QString
name|chars
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"
argument_list|)
decl_stmt|;
return|return
name|chars
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a string list of primary index characters. This is useful when presenting the     sorted list in a user interface with section headers. */
end_comment
begin_function
DECL|function|indexCharacters
name|QStringList
name|QCollator
operator|::
name|indexCharacters
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|indexCharacters
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|d
operator|->
name|indexCharacters
return|;
ifdef|#
directive|ifdef
name|QT_USE_ICU
name|QByteArray
name|id
init|=
name|identifier
argument_list|()
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|UErrorCode
name|status
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|UResourceBundle
modifier|*
name|res
init|=
name|ures_open
argument_list|(
name|NULL
argument_list|,
name|id
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|d
operator|->
name|indexCharacters
operator|=
name|englishIndexCharacters
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qint32
name|len
init|=
literal|0
decl_stmt|;
name|status
operator|=
name|U_ZERO_ERROR
expr_stmt|;
specifier|const
name|UChar
modifier|*
name|val
init|=
name|ures_getStringByKey
argument_list|(
name|res
argument_list|,
literal|"ExemplarCharactersIndex"
argument_list|,
operator|&
name|len
argument_list|,
operator|&
name|status
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|status
argument_list|)
condition|)
block|{
name|d
operator|->
name|indexCharacters
operator|=
name|englishIndexCharacters
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QString
name|chars
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|QChar
operator|*
argument_list|>
argument_list|(
name|val
argument_list|)
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|chars
operator|.
name|remove
argument_list|(
literal|'['
argument_list|)
expr_stmt|;
name|chars
operator|.
name|remove
argument_list|(
literal|']'
argument_list|)
expr_stmt|;
name|chars
operator|.
name|remove
argument_list|(
literal|'{'
argument_list|)
expr_stmt|;
name|chars
operator|.
name|remove
argument_list|(
literal|'}'
argument_list|)
expr_stmt|;
name|d
operator|->
name|indexCharacters
operator|=
name|chars
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
block|}
block|}
name|ures_close
argument_list|(
name|res
argument_list|)
expr_stmt|;
else|#
directive|else
name|d
operator|->
name|indexCharacters
operator|=
name|englishIndexCharacters
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|d
operator|->
name|indexCharacters
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
