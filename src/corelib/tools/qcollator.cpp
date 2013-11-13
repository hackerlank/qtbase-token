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
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QCollator     \inmodule QtCore     \brief The QCollator class compares strings according to a localized collation algorithm.      \since 5.2      \reentrant     \ingroup i18n     \ingroup string-processing     \ingroup shared      QCollator is initialized with a QLocale and an optional collation strategy. It tries to     initialize the collator with the specified values. The collator can then be used to compare     and sort strings in a locale dependent fashion.      A QCollator object can be used together with template based sorting algorithms such as std::sort     to sort a list of QStrings.      In addition to the locale and collation strategy, several optional flags can be set that influence     the result of the collation. */
end_comment
begin_comment
comment|/*!     Constructs a QCollator from \a locale. If \a locale is not specified     QLocale::default() will be used.      \sa setLocale()  */
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
name|d
operator|->
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
comment|/*!     \fn void QCollator::swap(QCollator&other)      Swaps this collator with \a other. This function is very fast and     never fails. */
end_comment
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
name|d
operator|->
name|init
argument_list|()
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
name|d
operator|->
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
comment|/*!     \fn void QCollator::setCaseSensitivity(Qt::CaseSensitivity sensitivity)      Sets the case \a sensitivity of the collator.      \sa caseSensitivity()  */
end_comment
begin_comment
comment|/*!     \fn Qt::CaseSensitivity QCollator::caseSensitivity() const      Returns case sensitivity of the collator.      \sa setCaseSensitivity()  */
end_comment
begin_comment
comment|/*!     \fn void QCollator::setNumericMode(bool on)      Enables numeric sorting mode when \a on is set to true.      This will enable proper sorting of numeric digits, so that e.g. 100 sorts after 99.      By default this mode is off.      \sa numericMode()  */
end_comment
begin_comment
comment|/*!     \fn bool QCollator::numericMode() const      Returns \c true if numeric sorting is enabled, false otherwise.      \sa setNumericMode()  */
end_comment
begin_comment
comment|/*!     \fn void QCollator::setIgnorePunctuation(bool on)      If \a on is set to true, punctuation characters and symbols are ignored when determining sort order.      The default is locale dependent.      \sa ignorePunctuation()  */
end_comment
begin_comment
comment|/*!     \fn bool QCollator::ignorePunctuation() const      Returns \c true if punctuation characters and symbols are ignored when determining sort order.      \sa setIgnorePunctuation()  */
end_comment
begin_comment
comment|/*!     \fn int QCollator::compare(const QString&s1, const QString&s2) const      Compares \a s1 with \a s2. Returns -1, 0 or 1 depending on whether \a s1 is     smaller, equal or larger than \a s2.  */
end_comment
begin_comment
comment|/*!     \fn bool QCollator::operator()(const QString&s1, const QString&s2) const     \internal */
end_comment
begin_comment
comment|/*!     \fn int QCollator::compare(const QStringRef&s1, const QStringRef&s2) const     \overload      Compares \a s1 with \a s2. Returns -1, 0 or 1 depending on whether \a s1 is     smaller, equal or larger than \a s2.  */
end_comment
begin_comment
comment|/*!     \fn int QCollator::compare(const QChar *s1, int len1, const QChar *s2, int len2) const     \overload      Compares \a s1 with \a s2. \a len1 and \a len2 specify the length of the     QChar arrays pointer to by \a s1 and \a s2.      Returns -1, 0 or 1 depending on whether \a s1 is smaller, equal or larger than \a s2.  */
end_comment
begin_comment
comment|/*!     \fn QCollatorSortKey QCollator::sortKey(const QString&string) const      Returns a sortKey for \a string.      Creating the sort key is usually somewhat slower, than using the compare()     methods directly. But if the string is compared repeatedly (e.g. when sorting     a whole list of strings), it's usually faster to create the sort keys for each     string and then sort using the keys.  */
end_comment
begin_comment
comment|/*!     \class QCollatorSortKey     \inmodule QtCore     \brief The QCollatorSortKey class can be used to speed up string collation.      \since 5.2      The QCollatorSortKey class is always created by QCollator::sortKey()     and is used for fast strings collation, for example when collating many strings.      \reentrant     \ingroup i18n     \ingroup string-processing     \ingroup shared      \sa QCollator, QCollator::sortKey() */
end_comment
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QCollatorSortKey
name|QCollatorSortKey
operator|::
name|QCollatorSortKey
parameter_list|(
name|QCollatorSortKeyPrivate
modifier|*
name|d
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a copy of the \a other collator key. */
end_comment
begin_constructor
DECL|function|QCollatorSortKey
name|QCollatorSortKey
operator|::
name|QCollatorSortKey
parameter_list|(
specifier|const
name|QCollatorSortKey
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
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the collator key.  */
end_comment
begin_destructor
DECL|function|~QCollatorSortKey
name|QCollatorSortKey
operator|::
name|~
name|QCollatorSortKey
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Assigns \a other to this collator key.  */
end_comment
begin_function
DECL|function|operator =
name|QCollatorSortKey
modifier|&
name|QCollatorSortKey
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QCollatorSortKey
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
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QCollatorSortKey::operator<(const QCollatorSortKey&otherKey) const      According to the QCollator that created the key, returns \c true if the     key should be sorted before than \a otherKey; otherwise returns \c false.      \sa compare()  */
end_comment
begin_comment
comment|/*!     \fn int QCollatorSortKey::compare(const QCollatorSortKey&otherKey) const      Compares the key to \a otherKey. Returns a negative value if the key     is less than \a otherKey, 0 if the key is equal to \a otherKey or a     positive value if the key is greater than \a otherKey.      \sa operator<()  */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
