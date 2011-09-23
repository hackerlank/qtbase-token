begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbwmsupport.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXcbWMSupport
name|QXcbWMSupport
operator|::
name|QXcbWMSupport
parameter_list|(
name|QXcbConnection
modifier|*
name|c
parameter_list|)
member_init_list|:
name|QXcbObject
argument_list|(
name|c
argument_list|)
block|{
name|updateNetWMAtoms
argument_list|()
expr_stmt|;
name|updateVirtualRoots
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|isSupportedByWM
name|bool
name|QXcbWMSupport
operator|::
name|isSupportedByWM
parameter_list|(
name|xcb_atom_t
name|atom
parameter_list|)
specifier|const
block|{
return|return
name|net_wm_atoms
operator|.
name|contains
argument_list|(
name|atom
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|updateNetWMAtoms
name|void
name|QXcbWMSupport
operator|::
name|updateNetWMAtoms
parameter_list|()
block|{
name|net_wm_atoms
operator|.
name|clear
argument_list|()
expr_stmt|;
name|xcb_window_t
name|root
init|=
name|connection
argument_list|()
operator|->
name|screens
argument_list|()
operator|.
name|at
argument_list|(
name|connection
argument_list|()
operator|->
name|primaryScreen
argument_list|()
argument_list|)
operator|->
name|root
argument_list|()
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|remaining
init|=
literal|0
decl_stmt|;
do|do
block|{
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_get_property_cookie_t
name|cookie
init|=
name|xcb_get_property
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|root
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_SUPPORTED
argument_list|)
argument_list|,
name|XCB_ATOM_ATOM
argument_list|,
name|offset
argument_list|,
literal|1024
argument_list|)
decl_stmt|;
name|xcb_get_property_reply_t
modifier|*
name|reply
init|=
name|xcb_get_property_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|||
name|error
condition|)
break|break;
name|remaining
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|reply
operator|->
name|type
operator|==
name|XCB_ATOM_ATOM
operator|&&
name|reply
operator|->
name|format
operator|==
literal|32
condition|)
block|{
name|int
name|len
init|=
name|xcb_get_property_value_length
argument_list|(
name|reply
argument_list|)
operator|/
literal|4
decl_stmt|;
name|xcb_atom_t
modifier|*
name|atoms
init|=
operator|(
name|xcb_atom_t
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|reply
argument_list|)
decl_stmt|;
name|int
name|s
init|=
name|net_wm_atoms
operator|.
name|size
argument_list|()
decl_stmt|;
name|net_wm_atoms
operator|.
name|resize
argument_list|(
name|s
operator|+
name|len
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|net_wm_atoms
operator|.
name|data
argument_list|()
operator|+
name|s
argument_list|,
name|atoms
argument_list|,
name|len
operator|*
sizeof|sizeof
argument_list|(
name|xcb_atom_t
argument_list|)
argument_list|)
expr_stmt|;
name|remaining
operator|=
name|reply
operator|->
name|bytes_after
expr_stmt|;
name|offset
operator|+=
name|len
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|remaining
operator|>
literal|0
condition|)
do|;
comment|//    qDebug()<< "======== updateNetWMAtoms";
comment|//    for (int i = 0; i< net_wm_atoms.size(); ++i)
comment|//        qDebug()<< atomName(net_wm_atoms.at(i));
comment|//    qDebug()<< "======== updateNetWMAtoms";
block|}
end_function
begin_comment
comment|// update the virtual roots array
end_comment
begin_function
DECL|function|updateVirtualRoots
name|void
name|QXcbWMSupport
operator|::
name|updateVirtualRoots
parameter_list|()
block|{
name|net_virtual_roots
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|isSupportedByWM
argument_list|(
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_VIRTUAL_ROOTS
argument_list|)
argument_list|)
condition|)
return|return;
name|xcb_window_t
name|root
init|=
name|connection
argument_list|()
operator|->
name|screens
argument_list|()
operator|.
name|at
argument_list|(
name|connection
argument_list|()
operator|->
name|primaryScreen
argument_list|()
argument_list|)
operator|->
name|root
argument_list|()
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|remaining
init|=
literal|0
decl_stmt|;
do|do
block|{
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_get_property_cookie_t
name|cookie
init|=
name|xcb_get_property
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|root
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_VIRTUAL_ROOTS
argument_list|)
argument_list|,
name|XCB_ATOM_ATOM
argument_list|,
name|offset
argument_list|,
literal|1024
argument_list|)
decl_stmt|;
name|xcb_get_property_reply_t
modifier|*
name|reply
init|=
name|xcb_get_property_reply
argument_list|(
name|xcb_connection
argument_list|()
argument_list|,
name|cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|||
name|error
condition|)
break|break;
name|remaining
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|reply
operator|->
name|type
operator|==
name|XCB_ATOM_ATOM
operator|&&
name|reply
operator|->
name|format
operator|==
literal|32
condition|)
block|{
name|int
name|len
init|=
name|xcb_get_property_value_length
argument_list|(
name|reply
argument_list|)
operator|/
literal|4
decl_stmt|;
name|xcb_atom_t
modifier|*
name|atoms
init|=
operator|(
name|xcb_atom_t
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|reply
argument_list|)
decl_stmt|;
name|int
name|s
init|=
name|net_wm_atoms
operator|.
name|size
argument_list|()
decl_stmt|;
name|net_wm_atoms
operator|.
name|resize
argument_list|(
name|s
operator|+
name|len
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|net_wm_atoms
operator|.
name|data
argument_list|()
operator|+
name|s
argument_list|,
name|atoms
argument_list|,
name|len
operator|*
sizeof|sizeof
argument_list|(
name|xcb_atom_t
argument_list|)
argument_list|)
expr_stmt|;
name|remaining
operator|=
name|reply
operator|->
name|bytes_after
expr_stmt|;
name|offset
operator|+=
name|len
expr_stmt|;
block|}
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|remaining
operator|>
literal|0
condition|)
do|;
name|qDebug
argument_list|()
operator|<<
literal|"======== updateVirtualRoots"
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|net_virtual_roots
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qDebug
argument_list|()
operator|<<
name|connection
argument_list|()
operator|->
name|atomName
argument_list|(
name|net_virtual_roots
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"======== updateVirtualRoots"
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
