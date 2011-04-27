begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<private/qmutexpool_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|void
modifier|*
name|qdbus_resolve_me
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
operator|!
name|defined
name|QT_LINKED_LIBDBUS
end_if
begin_decl_stmt
DECL|variable|qdbus_libdbus
specifier|static
name|QLibrary
modifier|*
name|qdbus_libdbus
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qdbus_unloadLibDBus
name|void
name|qdbus_unloadLibDBus
parameter_list|()
block|{
operator|delete
name|qdbus_libdbus
expr_stmt|;
name|qdbus_libdbus
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qdbus_loadLibDBus
name|bool
name|qdbus_loadLibDBus
parameter_list|()
block|{
specifier|static
specifier|volatile
name|bool
name|triedToLoadLibrary
init|=
literal|false
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|QMutexLocker
name|locker
argument_list|(
name|QMutexPool
operator|::
name|globalInstanceGet
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|qdbus_resolve_me
argument_list|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QLibrary
modifier|*
modifier|&
name|lib
init|=
name|qdbus_libdbus
decl_stmt|;
if|if
condition|(
name|triedToLoadLibrary
condition|)
return|return
name|lib
operator|&&
name|lib
operator|->
name|isLoaded
argument_list|()
return|;
name|lib
operator|=
operator|new
name|QLibrary
expr_stmt|;
name|triedToLoadLibrary
operator|=
literal|true
expr_stmt|;
specifier|static
name|int
name|majorversions
index|[]
init|=
block|{
literal|3
block|,
literal|2
block|,
operator|-
literal|1
block|}
decl_stmt|;
name|lib
operator|->
name|unload
argument_list|()
expr_stmt|;
name|lib
operator|->
name|setFileName
argument_list|(
name|QLatin1String
argument_list|(
literal|"dbus-1"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|majorversions
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|majorversions
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|lib
operator|->
name|setFileNameAndVersion
argument_list|(
name|lib
operator|->
name|fileName
argument_list|()
argument_list|,
name|majorversions
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|lib
operator|->
name|load
argument_list|()
operator|&&
name|lib
operator|->
name|resolve
argument_list|(
literal|"dbus_connection_open_private"
argument_list|)
condition|)
return|return
literal|true
return|;
name|lib
operator|->
name|unload
argument_list|()
expr_stmt|;
block|}
operator|delete
name|lib
expr_stmt|;
name|lib
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qdbus_resolve_conditionally
name|void
modifier|*
name|qdbus_resolve_conditionally
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|qdbus_loadLibDBus
argument_list|()
condition|)
return|return
name|qdbus_libdbus
operator|->
name|resolve
argument_list|(
name|name
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qdbus_resolve_me
name|void
modifier|*
name|qdbus_resolve_me
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|qdbus_loadLibDBus
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Cannot find libdbus-1 in your system to resolve symbol '%s'."
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|ptr
operator|=
name|qdbus_libdbus
operator|->
name|resolve
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr
condition|)
name|qFatal
argument_list|(
literal|"Cannot resolve '%s' in your libdbus-1."
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function
begin_macro
name|Q_DESTRUCTOR_FUNCTION
argument_list|(
argument|qdbus_unloadLibDBus
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_LINKED_LIBDBUS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
