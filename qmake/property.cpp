begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"property.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|QStringList
name|qmake_mkspec_paths
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//project.cpp
end_comment
begin_struct
specifier|static
specifier|const
struct|struct
block|{
DECL|member|name
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
DECL|member|loc
name|QLibraryInfo
operator|::
name|LibraryLocation
name|loc
decl_stmt|;
DECL|member|raw
name|bool
name|raw
decl_stmt|;
block|}
DECL|variable|propList
name|propList
index|[]
init|=
block|{
block|{
literal|"QT_SYSROOT"
block|,
name|QLibraryInfo
operator|::
name|SysrootPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_INSTALL_PREFIX"
block|,
name|QLibraryInfo
operator|::
name|PrefixPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DATA"
block|,
name|QLibraryInfo
operator|::
name|DataPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DOCS"
block|,
name|QLibraryInfo
operator|::
name|DocumentationPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_HEADERS"
block|,
name|QLibraryInfo
operator|::
name|HeadersPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_LIBS"
block|,
name|QLibraryInfo
operator|::
name|LibrariesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_BINS"
block|,
name|QLibraryInfo
operator|::
name|BinariesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_TESTS"
block|,
name|QLibraryInfo
operator|::
name|TestsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_PLUGINS"
block|,
name|QLibraryInfo
operator|::
name|PluginsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_IMPORTS"
block|,
name|QLibraryInfo
operator|::
name|ImportsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_TRANSLATIONS"
block|,
name|QLibraryInfo
operator|::
name|TranslationsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_CONFIGURATION"
block|,
name|QLibraryInfo
operator|::
name|SettingsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_EXAMPLES"
block|,
name|QLibraryInfo
operator|::
name|ExamplesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DEMOS"
block|,
name|QLibraryInfo
operator|::
name|ExamplesPath
block|,
literal|false
block|}
block|,
comment|// Just backwards compat
block|{
literal|"QT_RAW_INSTALL_PREFIX"
block|,
name|QLibraryInfo
operator|::
name|PrefixPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_DATA"
block|,
name|QLibraryInfo
operator|::
name|DataPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_DOCS"
block|,
name|QLibraryInfo
operator|::
name|DocumentationPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_HEADERS"
block|,
name|QLibraryInfo
operator|::
name|HeadersPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_LIBS"
block|,
name|QLibraryInfo
operator|::
name|LibrariesPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_BINS"
block|,
name|QLibraryInfo
operator|::
name|BinariesPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_TESTS"
block|,
name|QLibraryInfo
operator|::
name|TestsPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_PLUGINS"
block|,
name|QLibraryInfo
operator|::
name|PluginsPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_IMPORTS"
block|,
name|QLibraryInfo
operator|::
name|ImportsPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_TRANSLATIONS"
block|,
name|QLibraryInfo
operator|::
name|TranslationsPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_CONFIGURATION"
block|,
name|QLibraryInfo
operator|::
name|SettingsPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_RAW_INSTALL_EXAMPLES"
block|,
name|QLibraryInfo
operator|::
name|ExamplesPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_HOST_PREFIX"
block|,
name|QLibraryInfo
operator|::
name|HostPrefixPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_HOST_DATA"
block|,
name|QLibraryInfo
operator|::
name|HostDataPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_HOST_BINS"
block|,
name|QLibraryInfo
operator|::
name|HostBinariesPath
block|,
literal|true
block|}
block|, }
struct|;
end_struct
begin_constructor
DECL|function|QMakeProperty
name|QMakeProperty
operator|::
name|QMakeProperty
parameter_list|()
member_init_list|:
name|settings
argument_list|(
literal|0
argument_list|)
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
sizeof|sizeof
argument_list|(
name|propList
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|propList
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|m_values
index|[
name|QString
operator|::
name|fromLatin1
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|name
argument_list|)
index|]
operator|=
name|propList
index|[
name|i
index|]
operator|.
name|raw
condition|?
name|QLibraryInfo
operator|::
name|rawLocation
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|loc
argument_list|)
else|:
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|loc
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMakeProperty
name|QMakeProperty
operator|::
name|~
name|QMakeProperty
parameter_list|()
block|{
operator|delete
name|settings
expr_stmt|;
name|settings
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initSettings
name|void
name|QMakeProperty
operator|::
name|initSettings
parameter_list|()
block|{
if|if
condition|(
operator|!
name|settings
condition|)
block|{
name|settings
operator|=
operator|new
name|QSettings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
literal|"Trolltech"
argument_list|,
literal|"QMake"
argument_list|)
expr_stmt|;
name|settings
operator|->
name|setFallbacksEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
name|QString
DECL|function|keyBase
name|QMakeProperty
operator|::
name|keyBase
parameter_list|(
name|bool
name|version
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|version
condition|)
return|return
name|QString
argument_list|(
name|qmake_version
argument_list|()
argument_list|)
operator|+
literal|"/"
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
name|QString
DECL|function|value
name|QMakeProperty
operator|::
name|value
parameter_list|(
name|QString
name|v
parameter_list|,
name|bool
name|just_check
parameter_list|)
block|{
name|QString
name|val
init|=
name|m_values
operator|.
name|value
argument_list|(
name|v
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|val
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|val
return|;
elseif|else
if|if
condition|(
name|v
operator|==
literal|"QMAKE_MKSPECS"
condition|)
return|return
name|qmake_mkspec_paths
argument_list|()
operator|.
name|join
argument_list|(
name|Option
operator|::
name|dirlist_sep
argument_list|)
return|;
elseif|else
if|if
condition|(
name|v
operator|==
literal|"QMAKE_VERSION"
condition|)
return|return
name|qmake_version
argument_list|()
return|;
ifdef|#
directive|ifdef
name|QT_VERSION_STR
elseif|else
if|if
condition|(
name|v
operator|==
literal|"QT_VERSION"
condition|)
return|return
name|QT_VERSION_STR
return|;
endif|#
directive|endif
name|initSettings
argument_list|()
expr_stmt|;
name|int
name|slash
init|=
name|v
operator|.
name|lastIndexOf
argument_list|(
literal|'/'
argument_list|)
decl_stmt|;
name|QVariant
name|var
init|=
name|settings
operator|->
name|value
argument_list|(
name|keyBase
argument_list|(
name|slash
operator|==
operator|-
literal|1
argument_list|)
operator|+
name|v
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|var
operator|.
name|isValid
argument_list|()
decl_stmt|;
name|QString
name|ret
init|=
name|var
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|QString
name|version
init|=
name|qmake_version
argument_list|()
decl_stmt|;
if|if
condition|(
name|slash
operator|!=
operator|-
literal|1
condition|)
block|{
name|version
operator|=
name|v
operator|.
name|left
argument_list|(
name|slash
operator|-
literal|1
argument_list|)
expr_stmt|;
name|v
operator|=
name|v
operator|.
name|mid
argument_list|(
name|slash
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|settings
operator|->
name|beginGroup
argument_list|(
name|keyBase
argument_list|(
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|subs
init|=
name|settings
operator|->
name|childGroups
argument_list|()
decl_stmt|;
name|settings
operator|->
name|endGroup
argument_list|()
expr_stmt|;
name|subs
operator|.
name|sort
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
name|subs
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|x
operator|>=
literal|0
condition|;
name|x
operator|--
control|)
block|{
name|QString
name|s
init|=
name|subs
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
name|s
operator|.
name|isEmpty
argument_list|()
operator|||
name|s
operator|>
name|version
condition|)
continue|continue;
name|var
operator|=
name|settings
operator|->
name|value
argument_list|(
name|keyBase
argument_list|(
literal|false
argument_list|)
operator|+
name|s
operator|+
literal|"/"
operator|+
name|v
argument_list|)
expr_stmt|;
name|ok
operator|=
name|var
operator|.
name|isValid
argument_list|()
expr_stmt|;
name|ret
operator|=
name|var
operator|.
name|toString
argument_list|()
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
if|if
condition|(
operator|!
name|just_check
condition|)
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"Fell back from %s -> %s for '%s'."
argument_list|,
name|version
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|s
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|v
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
block|}
block|}
return|return
name|ok
condition|?
name|ret
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
DECL|function|hasValue
name|QMakeProperty
operator|::
name|hasValue
parameter_list|(
name|QString
name|v
parameter_list|)
block|{
return|return
operator|!
name|value
argument_list|(
name|v
argument_list|,
literal|true
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
name|void
DECL|function|setValue
name|QMakeProperty
operator|::
name|setValue
parameter_list|(
name|QString
name|var
parameter_list|,
specifier|const
name|QString
modifier|&
name|val
parameter_list|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|settings
operator|->
name|setValue
argument_list|(
name|keyBase
argument_list|()
operator|+
name|var
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
DECL|function|remove
name|QMakeProperty
operator|::
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|var
parameter_list|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|settings
operator|->
name|remove
argument_list|(
name|keyBase
argument_list|()
operator|+
name|var
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|bool
DECL|function|exec
name|QMakeProperty
operator|::
name|exec
parameter_list|()
block|{
name|bool
name|ret
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_QUERY_PROPERTY
condition|)
block|{
if|if
condition|(
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|settings
operator|->
name|beginGroup
argument_list|(
name|keyBase
argument_list|(
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|subs
init|=
name|settings
operator|->
name|childGroups
argument_list|()
decl_stmt|;
name|settings
operator|->
name|endGroup
argument_list|()
expr_stmt|;
name|subs
operator|.
name|sort
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
name|subs
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|x
operator|>=
literal|0
condition|;
name|x
operator|--
control|)
block|{
name|QString
name|s
init|=
name|subs
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
name|s
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|settings
operator|->
name|beginGroup
argument_list|(
name|keyBase
argument_list|(
literal|false
argument_list|)
operator|+
name|s
argument_list|)
expr_stmt|;
name|QStringList
name|keys
init|=
name|settings
operator|->
name|childKeys
argument_list|()
decl_stmt|;
name|settings
operator|->
name|endGroup
argument_list|()
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it2
init|=
name|keys
operator|.
name|begin
argument_list|()
init|;
name|it2
operator|!=
name|keys
operator|.
name|end
argument_list|()
condition|;
name|it2
operator|++
control|)
block|{
name|QString
name|ret
init|=
name|settings
operator|->
name|value
argument_list|(
name|keyBase
argument_list|(
literal|false
argument_list|)
operator|+
name|s
operator|+
literal|"/"
operator|+
operator|(
operator|*
name|it2
operator|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|s
operator|!=
name|qmake_version
argument_list|()
condition|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s/"
argument_list|,
name|s
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:%s\n"
argument_list|,
operator|(
operator|*
name|it2
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|ret
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|QStringList
name|specialProps
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|propList
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|propList
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|specialProps
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|specialProps
operator|.
name|append
argument_list|(
literal|"QMAKE_MKSPECS"
argument_list|)
expr_stmt|;
name|specialProps
operator|.
name|append
argument_list|(
literal|"QMAKE_VERSION"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_VERSION_STR
name|specialProps
operator|.
name|append
argument_list|(
literal|"QT_VERSION"
argument_list|)
expr_stmt|;
endif|#
directive|endif
foreach|foreach
control|(
name|QString
name|prop
decl|,
name|specialProps
control|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:%s\n"
argument_list|,
name|prop
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|value
argument_list|(
name|prop
argument_list|)
operator|.
name|toLatin1
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
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
if|if
condition|(
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:"
argument_list|,
operator|(
operator|*
name|it
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasValue
argument_list|(
operator|(
operator|*
name|it
operator|)
argument_list|)
condition|)
block|{
name|ret
operator|=
literal|false
expr_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"**Unknown**\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s\n"
argument_list|,
name|value
argument_list|(
operator|(
operator|*
name|it
operator|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_SET_PROPERTY
condition|)
block|{
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
name|QString
name|var
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
name|it
operator|++
expr_stmt|;
if|if
condition|(
name|it
operator|==
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|)
block|{
name|ret
operator|=
literal|false
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|var
operator|.
name|startsWith
argument_list|(
literal|"."
argument_list|)
condition|)
name|setValue
argument_list|(
name|var
argument_list|,
operator|(
operator|*
name|it
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_UNSET_PROPERTY
condition|)
block|{
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
name|QString
name|var
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|var
operator|.
name|startsWith
argument_list|(
literal|"."
argument_list|)
condition|)
name|remove
argument_list|(
name|var
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
