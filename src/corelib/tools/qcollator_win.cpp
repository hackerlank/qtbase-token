begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<qsysinfo.h>
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
name|collator
operator|=
literal|0
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
block|{ }
end_function
begin_function
DECL|function|setCaseSensitivity
name|void
name|QCollator
operator|::
name|setCaseSensitivity
parameter_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
name|cs
operator|==
name|Qt
operator|::
name|CaseSensitive
condition|)
name|d
operator|->
name|collator
operator|&=
operator|~
name|NORM_IGNORECASE
expr_stmt|;
else|else
name|d
operator|->
name|collator
operator||=
name|NORM_IGNORECASE
expr_stmt|;
block|}
end_function
begin_function
DECL|function|caseSensitivity
name|Qt
operator|::
name|CaseSensitivity
name|QCollator
operator|::
name|caseSensitivity
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|collator
operator|&
name|NORM_IGNORECASE
condition|?
name|Qt
operator|::
name|CaseInsensitive
else|:
name|Qt
operator|::
name|CaseSensitive
return|;
block|}
end_function
begin_comment
comment|//NOTE: SORT_DIGITSASNUMBERS is available since win7
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SORT_DIGITSASNUMBERS
end_ifndef
begin_define
DECL|macro|SORT_DIGITSASNUMBERS
define|#
directive|define
name|SORT_DIGITSASNUMBERS
value|8
end_define
begin_endif
endif|#
directive|endif
end_endif
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
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
operator|>=
name|QSysInfo
operator|::
name|WV_WINDOWS7
condition|)
block|{
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
name|on
condition|)
name|d
operator|->
name|collator
operator||=
name|SORT_DIGITSASNUMBERS
expr_stmt|;
else|else
name|d
operator|->
name|collator
operator|&=
operator|~
name|SORT_DIGITSASNUMBERS
expr_stmt|;
block|}
else|else
block|{
name|Q_UNUSED
argument_list|(
name|on
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"unsupported in the win collation implementation"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|numericMode
name|bool
name|QCollator
operator|::
name|numericMode
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
operator|>=
name|QSysInfo
operator|::
name|WV_WINDOWS7
condition|)
block|{
return|return
name|bool
argument_list|(
name|d
operator|->
name|collator
operator|&
name|SORT_DIGITSASNUMBERS
argument_list|)
return|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"unsupported in the win collation implementation"
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
end_function
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
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
name|on
condition|)
name|d
operator|->
name|collator
operator||=
name|NORM_IGNORESYMBOLS
expr_stmt|;
else|else
name|d
operator|->
name|collator
operator|&=
operator|~
name|NORM_IGNORESYMBOLS
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ignorePunctuation
name|bool
name|QCollator
operator|::
name|ignorePunctuation
parameter_list|()
specifier|const
block|{
return|return
name|bool
argument_list|(
name|d
operator|->
name|collator
operator|&
name|NORM_IGNORESYMBOLS
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
comment|//* from Windows documentation *
comment|// Returns one of the following values if successful. To maintain the C runtime convention of
comment|// comparing strings, the value 2 can be subtracted from a nonzero return value. Then, the
comment|// meaning of<0, ==0, and>0 is consistent with the C runtime.
return|return
name|CompareString
argument_list|(
name|LOCALE_USER_DEFAULT
argument_list|,
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|s1
argument_list|)
argument_list|,
name|len1
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|s2
argument_list|)
argument_list|,
name|len2
argument_list|)
operator|-
literal|2
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
name|str1
parameter_list|,
specifier|const
name|QString
modifier|&
name|str2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|str1
operator|.
name|constData
argument_list|()
argument_list|,
name|str1
operator|.
name|size
argument_list|()
argument_list|,
name|str2
operator|.
name|constData
argument_list|()
argument_list|,
name|str2
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
name|int
name|size
init|=
name|LCMapStringW
argument_list|(
name|LOCALE_USER_DEFAULT
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QString
name|ret
argument_list|(
name|size
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|int
name|finalSize
init|=
name|LCMapStringW
argument_list|(
name|LOCALE_USER_DEFAULT
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|ret
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|ret
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|finalSize
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"there were problems when generating the ::sortKey by LCMapStringW with error:"
operator|<<
name|GetLastError
argument_list|()
expr_stmt|;
block|}
return|return
name|QCollatorSortKey
argument_list|(
operator|new
name|QCollatorSortKeyPrivate
argument_list|(
name|ret
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <
name|bool
name|QCollatorSortKey
operator|::
name|operator
name|<
parameter_list|(
specifier|const
name|QCollatorSortKey
modifier|&
name|otherKey
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|m_key
operator|<
name|otherKey
operator|.
name|d
operator|->
name|m_key
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
name|d
operator|->
name|m_key
operator|.
name|compare
argument_list|(
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