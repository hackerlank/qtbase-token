begin_unit
begin_comment
comment|/**  * Copyright Â© 2012 Intel Corporation  * Copyright Â© 2012 Ran Benita<ran234@gmail.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Author: Daniel Stone<daniel@fooishbar.org>  */
end_comment
begin_include
include|#
directive|include
file|"keymap.h"
end_include
begin_function
specifier|static
name|void
DECL|function|update_builtin_keymap_fields
name|update_builtin_keymap_fields
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
name|struct
name|xkb_context
modifier|*
name|ctx
init|=
name|keymap
operator|->
name|ctx
decl_stmt|;
comment|/*      * Add predefined (AKA real, core, X11) modifiers.      * The order is important!      */
name|darray_appends_t
argument_list|(
name|keymap
operator|->
name|mods
argument_list|,
expr|struct
name|xkb_mod
argument_list|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Shift"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Lock"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Control"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Mod1"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Mod2"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Mod3"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Mod4"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
operator|,
block|{
operator|.
name|name
operator|=
name|xkb_atom_intern_literal
argument_list|(
name|ctx
argument_list|,
literal|"Mod5"
argument_list|)
operator|,
operator|.
name|type
operator|=
name|MOD_REAL
block|}
block|)
function|;
end_function
begin_function
unit|}  struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new
name|xkb_keymap_new
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
name|keymap
operator|=
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|keymap
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
name|keymap
operator|->
name|refcnt
operator|=
literal|1
expr_stmt|;
name|keymap
operator|->
name|ctx
operator|=
name|xkb_context_ref
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|keymap
operator|->
name|format
operator|=
name|format
expr_stmt|;
name|keymap
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
name|update_builtin_keymap_fields
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|struct
name|xkb_key
modifier|*
DECL|function|XkbKeyByName
name|XkbKeyByName
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|,
name|bool
name|use_aliases
parameter_list|)
block|{
name|struct
name|xkb_key
modifier|*
name|key
decl_stmt|;
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
if|if
condition|(
name|key
operator|->
name|name
operator|==
name|name
condition|)
return|return
name|key
return|;
if|if
condition|(
name|use_aliases
condition|)
block|{
name|xkb_atom_t
name|new_name
init|=
name|XkbResolveKeyAlias
argument_list|(
name|keymap
argument_list|,
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|new_name
operator|!=
name|XKB_ATOM_NONE
condition|)
return|return
name|XkbKeyByName
argument_list|(
name|keymap
argument_list|,
name|new_name
argument_list|,
name|false
argument_list|)
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function
begin_function
name|xkb_atom_t
DECL|function|XkbResolveKeyAlias
name|XkbResolveKeyAlias
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|keymap
operator|->
name|num_key_aliases
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|keymap
operator|->
name|key_aliases
index|[
name|i
index|]
operator|.
name|alias
operator|==
name|name
condition|)
return|return
name|keymap
operator|->
name|key_aliases
index|[
name|i
index|]
operator|.
name|real
return|;
return|return
name|XKB_ATOM_NONE
return|;
block|}
end_function
begin_function
name|void
DECL|function|XkbEscapeMapName
name|XkbEscapeMapName
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
block|{
comment|/*      * All latin-1 alphanumerics, plus parens, slash, minus, underscore and      * wildcards.      */
specifier|static
specifier|const
name|unsigned
name|char
name|legal
index|[]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xa7
block|,
literal|0xff
block|,
literal|0x83
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x87
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0xff
block|}
decl_stmt|;
if|if
condition|(
operator|!
name|name
condition|)
return|return;
while|while
condition|(
operator|*
name|name
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|legal
index|[
operator|*
name|name
operator|/
literal|8
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
operator|*
name|name
operator|%
literal|8
operator|)
operator|)
operator|)
condition|)
operator|*
name|name
operator|=
literal|'_'
expr_stmt|;
name|name
operator|++
expr_stmt|;
block|}
block|}
end_function
end_unit