begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"registry_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_OS_WIN32
comment|/*!   Returns the path part of a registry key.   e.g.       For a key           "Software\\Microsoft\\VisualStudio\\8.0\\Setup\\VC\\ProductDir"       it returns           "Software\\Microsoft\\VisualStudio\\8.0\\Setup\\VC\\" */
DECL|function|keyPath
specifier|static
name|QString
name|keyPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|rKey
parameter_list|)
block|{
name|int
name|idx
init|=
name|rKey
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|rKey
operator|.
name|left
argument_list|(
name|idx
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the name part of a registry key.   e.g.       For a key           "Software\\Microsoft\\VisualStudio\\8.0\\Setup\\VC\\ProductDir"       it returns           "ProductDir" */
end_comment
begin_function
DECL|function|keyName
specifier|static
name|QString
name|keyName
parameter_list|(
specifier|const
name|QString
modifier|&
name|rKey
parameter_list|)
block|{
name|int
name|idx
init|=
name|rKey
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|==
operator|-
literal|1
condition|)
return|return
name|rKey
return|;
name|QString
name|res
argument_list|(
name|rKey
operator|.
name|mid
argument_list|(
name|idx
operator|+
literal|1
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|==
name|QLatin1String
argument_list|(
literal|"Default"
argument_list|)
operator|||
name|res
operator|==
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
condition|)
name|res
operator|=
name|QString
argument_list|()
expr_stmt|;
return|return
name|res
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qt_readRegistryKey
name|QString
name|qt_readRegistryKey
parameter_list|(
name|HKEY
name|parentHandle
parameter_list|,
specifier|const
name|QString
modifier|&
name|rSubkey
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN32
name|QString
name|rSubkeyName
init|=
name|keyName
argument_list|(
name|rSubkey
argument_list|)
decl_stmt|;
name|QString
name|rSubkeyPath
init|=
name|keyPath
argument_list|(
name|rSubkey
argument_list|)
decl_stmt|;
name|HKEY
name|handle
init|=
literal|0
decl_stmt|;
name|LONG
name|res
init|=
name|RegOpenKeyEx
argument_list|(
name|parentHandle
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|rSubkeyPath
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
name|KEY_READ
argument_list|,
operator|&
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|!=
name|ERROR_SUCCESS
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// get the size and type of the value
name|DWORD
name|dataType
decl_stmt|;
name|DWORD
name|dataSize
decl_stmt|;
name|res
operator|=
name|RegQueryValueEx
argument_list|(
name|handle
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|rSubkeyName
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|dataType
argument_list|,
literal|0
argument_list|,
operator|&
name|dataSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|RegCloseKey
argument_list|(
name|handle
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
comment|// get the value
name|QByteArray
name|data
argument_list|(
name|dataSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|res
operator|=
name|RegQueryValueEx
argument_list|(
name|handle
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|rSubkeyName
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
operator|&
name|dataSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|!=
name|ERROR_SUCCESS
condition|)
block|{
name|RegCloseKey
argument_list|(
name|handle
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
switch|switch
condition|(
name|dataType
condition|)
block|{
case|case
name|REG_EXPAND_SZ
case|:
case|case
name|REG_SZ
case|:
block|{
name|result
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
operator|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|REG_MULTI_SZ
case|:
block|{
name|QStringList
name|l
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|QString
name|s
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
operator|+
name|i
argument_list|)
decl_stmt|;
name|i
operator|+=
name|s
operator|.
name|length
argument_list|()
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|l
operator|.
name|append
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|result
operator|=
name|l
operator|.
name|join
argument_list|(
name|QLatin1String
argument_list|(
literal|", "
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|REG_NONE
case|:
case|case
name|REG_BINARY
case|:
block|{
name|result
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|REG_DWORD_BIG_ENDIAN
case|:
case|case
name|REG_DWORD
case|:
block|{
name|Q_ASSERT
argument_list|(
name|data
operator|.
name|size
argument_list|()
operator|==
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|i
argument_list|,
name|data
operator|.
name|constData
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|qWarning
argument_list|(
literal|"QSettings: unknown data %u type in windows registry"
argument_list|,
name|quint32
argument_list|(
name|dataType
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|RegCloseKey
argument_list|(
name|handle
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|parentHandle
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|rSubkey
argument_list|)
endif|#
directive|endif
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
