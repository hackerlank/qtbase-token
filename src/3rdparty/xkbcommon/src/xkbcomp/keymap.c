begin_unit
begin_comment
comment|/*  * Copyright Â© 2009 Dan Nicholson  * Copyright Â© 2012 Intel Corporation  * Copyright Â© 2012 Ran Benita<ran234@gmail.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Author: Dan Nicholson<dbn.lists@gmail.com>  *         Daniel Stone<daniel@fooishbar.org>  *         Ran Benita<ran234@gmail.com>  */
end_comment
begin_include
include|#
directive|include
file|"xkbcomp-priv.h"
end_include
begin_function
specifier|static
name|void
DECL|function|ComputeEffectiveMask
name|ComputeEffectiveMask
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|struct
name|xkb_mods
modifier|*
name|mods
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_mod
modifier|*
name|mod
decl_stmt|;
name|xkb_mod_index_t
name|i
decl_stmt|;
comment|/* The effective mask is only real mods for now. */
name|mods
operator|->
name|mask
operator|=
name|mods
operator|->
name|mods
operator|&
name|MOD_REAL_MASK_ALL
expr_stmt|;
name|darray_enumerate
argument_list|(
argument|i
argument_list|,
argument|mod
argument_list|,
argument|keymap->mods
argument_list|)
if|if
condition|(
name|mods
operator|->
name|mods
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|mods
operator|->
name|mask
operator||=
name|mod
operator|->
name|mapping
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|UpdateActionMods
name|UpdateActionMods
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|union
name|xkb_action
modifier|*
name|act
parameter_list|,
name|xkb_mod_mask_t
name|modmap
parameter_list|)
block|{
switch|switch
condition|(
name|act
operator|->
name|type
condition|)
block|{
case|case
name|ACTION_TYPE_MOD_SET
case|:
case|case
name|ACTION_TYPE_MOD_LATCH
case|:
case|case
name|ACTION_TYPE_MOD_LOCK
case|:
if|if
condition|(
name|act
operator|->
name|mods
operator|.
name|flags
operator|&
name|ACTION_MODS_LOOKUP_MODMAP
condition|)
name|act
operator|->
name|mods
operator|.
name|mods
operator|.
name|mods
operator|=
name|modmap
expr_stmt|;
name|ComputeEffectiveMask
argument_list|(
name|keymap
argument_list|,
operator|&
name|act
operator|->
name|mods
operator|.
name|mods
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|default_interpret
specifier|static
specifier|const
name|struct
name|xkb_sym_interpret
name|default_interpret
init|=
block|{
operator|.
name|sym
operator|=
name|XKB_KEY_NoSymbol
block|,
operator|.
name|repeat
operator|=
name|true
block|,
operator|.
name|match
operator|=
name|MATCH_ANY_OR_NONE
block|,
operator|.
name|mods
operator|=
literal|0
block|,
operator|.
name|virtual_mod
operator|=
name|XKB_MOD_INVALID
block|,
operator|.
name|action
operator|=
block|{
operator|.
name|type
operator|=
name|ACTION_TYPE_NONE
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/**  * Find an interpretation which applies to this particular level, either by  * finding an exact match for the symbol and modifier combination, or a  * generic XKB_KEY_NoSymbol match.  */
end_comment
begin_function
specifier|static
specifier|const
name|struct
name|xkb_sym_interpret
modifier|*
DECL|function|FindInterpForKey
name|FindInterpForKey
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|struct
name|xkb_key
modifier|*
name|key
parameter_list|,
name|xkb_layout_index_t
name|group
parameter_list|,
name|xkb_level_index_t
name|level
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_sym_interpret
modifier|*
name|interp
decl_stmt|;
specifier|const
name|xkb_keysym_t
modifier|*
name|syms
decl_stmt|;
name|int
name|num_syms
decl_stmt|;
name|num_syms
operator|=
name|xkb_keymap_key_get_syms_by_level
argument_list|(
name|keymap
argument_list|,
name|key
operator|->
name|keycode
argument_list|,
name|group
argument_list|,
name|level
argument_list|,
operator|&
name|syms
argument_list|)
expr_stmt|;
if|if
condition|(
name|num_syms
operator|==
literal|0
condition|)
return|return
name|NULL
return|;
comment|/*      * There may be multiple matchings interprets; we should always return      * the most specific. Here we rely on compat.c to set up the      * sym_interprets array from the most specific to the least specific,      * such that when we find a match we return immediately.      */
name|darray_foreach
argument_list|(
argument|interp
argument_list|,
argument|keymap->sym_interprets
argument_list|)
block|{
name|xkb_mod_mask_t
name|mods
decl_stmt|;
name|bool
name|found
init|=
name|false
decl_stmt|;
if|if
condition|(
operator|(
name|num_syms
operator|>
literal|1
operator|||
name|interp
operator|->
name|sym
operator|!=
name|syms
index|[
literal|0
index|]
operator|)
operator|&&
name|interp
operator|->
name|sym
operator|!=
name|XKB_KEY_NoSymbol
condition|)
continue|continue;
if|if
condition|(
name|interp
operator|->
name|level_one_only
operator|&&
name|level
operator|!=
literal|0
condition|)
name|mods
operator|=
literal|0
expr_stmt|;
else|else
name|mods
operator|=
name|key
operator|->
name|modmap
expr_stmt|;
switch|switch
condition|(
name|interp
operator|->
name|match
condition|)
block|{
case|case
name|MATCH_NONE
case|:
name|found
operator|=
operator|!
operator|(
name|interp
operator|->
name|mods
operator|&
name|mods
operator|)
expr_stmt|;
break|break;
case|case
name|MATCH_ANY_OR_NONE
case|:
name|found
operator|=
operator|(
operator|!
name|mods
operator|||
operator|(
name|interp
operator|->
name|mods
operator|&
name|mods
operator|)
operator|)
expr_stmt|;
break|break;
case|case
name|MATCH_ANY
case|:
name|found
operator|=
operator|!
operator|!
operator|(
name|interp
operator|->
name|mods
operator|&
name|mods
operator|)
expr_stmt|;
break|break;
case|case
name|MATCH_ALL
case|:
name|found
operator|=
operator|(
operator|(
name|interp
operator|->
name|mods
operator|&
name|mods
operator|)
operator|==
name|interp
operator|->
name|mods
operator|)
expr_stmt|;
break|break;
case|case
name|MATCH_EXACTLY
case|:
name|found
operator|=
operator|(
name|interp
operator|->
name|mods
operator|==
name|mods
operator|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|found
condition|)
return|return
name|interp
return|;
block|}
return|return
operator|&
name|default_interpret
return|;
block|}
end_function
begin_function
specifier|static
name|bool
DECL|function|ApplyInterpsToKey
name|ApplyInterpsToKey
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|struct
name|xkb_key
modifier|*
name|key
parameter_list|)
block|{
name|xkb_mod_mask_t
name|vmodmap
init|=
literal|0
decl_stmt|;
name|xkb_layout_index_t
name|group
decl_stmt|;
name|xkb_level_index_t
name|level
decl_stmt|;
comment|/* If we've been told not to bind interps to this key, then don't. */
if|if
condition|(
name|key
operator|->
name|explicit
operator|&
name|EXPLICIT_INTERP
condition|)
return|return
name|true
return|;
for|for
control|(
name|group
operator|=
literal|0
init|;
name|group
operator|<
name|key
operator|->
name|num_groups
condition|;
name|group
operator|++
control|)
block|{
for|for
control|(
name|level
operator|=
literal|0
init|;
name|level
operator|<
name|XkbKeyGroupWidth
argument_list|(
name|key
argument_list|,
name|group
argument_list|)
condition|;
name|level
operator|++
control|)
block|{
specifier|const
name|struct
name|xkb_sym_interpret
modifier|*
name|interp
decl_stmt|;
name|interp
operator|=
name|FindInterpForKey
argument_list|(
name|keymap
argument_list|,
name|key
argument_list|,
name|group
argument_list|,
name|level
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|interp
condition|)
continue|continue;
comment|/* Infer default key behaviours from the base level. */
if|if
condition|(
name|group
operator|==
literal|0
operator|&&
name|level
operator|==
literal|0
condition|)
if|if
condition|(
operator|!
operator|(
name|key
operator|->
name|explicit
operator|&
name|EXPLICIT_REPEAT
operator|)
operator|&&
name|interp
operator|->
name|repeat
condition|)
name|key
operator|->
name|repeats
operator|=
name|true
expr_stmt|;
if|if
condition|(
operator|(
name|group
operator|==
literal|0
operator|&&
name|level
operator|==
literal|0
operator|)
operator|||
operator|!
name|interp
operator|->
name|level_one_only
condition|)
if|if
condition|(
name|interp
operator|->
name|virtual_mod
operator|!=
name|XKB_MOD_INVALID
condition|)
name|vmodmap
operator||=
operator|(
literal|1
operator|<<
name|interp
operator|->
name|virtual_mod
operator|)
expr_stmt|;
if|if
condition|(
name|interp
operator|->
name|action
operator|.
name|type
operator|!=
name|ACTION_TYPE_NONE
condition|)
name|key
operator|->
name|groups
index|[
name|group
index|]
operator|.
name|levels
index|[
name|level
index|]
operator|.
name|action
operator|=
name|interp
operator|->
name|action
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
operator|(
name|key
operator|->
name|explicit
operator|&
name|EXPLICIT_VMODMAP
operator|)
condition|)
name|key
operator|->
name|vmodmap
operator|=
name|vmodmap
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_comment
comment|/**  * This collects a bunch of disparate functions which was done in the server  * at various points that really should've been done within xkbcomp.  Turns out  * your actions and types are a lot more useful when any of your modifiers  * other than Shift actually do something ...  */
end_comment
begin_function
specifier|static
name|bool
DECL|function|UpdateDerivedKeymapFields
name|UpdateDerivedKeymapFields
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
name|struct
name|xkb_mod
modifier|*
name|mod
decl_stmt|;
name|struct
name|xkb_led
modifier|*
name|led
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|struct
name|xkb_key
modifier|*
name|key
decl_stmt|;
comment|/* Find all the interprets for the key and bind them to actions,      * which will also update the vmodmap. */
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
if|if
condition|(
operator|!
name|ApplyInterpsToKey
argument_list|(
name|keymap
argument_list|,
name|key
argument_list|)
condition|)
return|return
name|false
return|;
comment|/* Update keymap->mods, the virtual -> real mod mapping. */
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
name|darray_enumerate
argument_list|(
argument|i
argument_list|,
argument|mod
argument_list|,
argument|keymap->mods
argument_list|)
if|if
condition|(
name|key
operator|->
name|vmodmap
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|mod
operator|->
name|mapping
operator||=
name|key
operator|->
name|modmap
expr_stmt|;
comment|/* Now update the level masks for all the types to reflect the vmods. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|keymap
operator|->
name|num_types
condition|;
name|i
operator|++
control|)
block|{
name|ComputeEffectiveMask
argument_list|(
name|keymap
argument_list|,
operator|&
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|mods
argument_list|)
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|num_entries
condition|;
name|j
operator|++
control|)
block|{
name|ComputeEffectiveMask
argument_list|(
name|keymap
argument_list|,
operator|&
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|entries
index|[
name|j
index|]
operator|.
name|mods
argument_list|)
expr_stmt|;
name|ComputeEffectiveMask
argument_list|(
name|keymap
argument_list|,
operator|&
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|entries
index|[
name|j
index|]
operator|.
name|preserve
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Update action modifiers. */
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|key
operator|->
name|num_groups
condition|;
name|i
operator|++
control|)
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|XkbKeyGroupWidth
argument_list|(
name|key
argument_list|,
name|i
argument_list|)
condition|;
name|j
operator|++
control|)
name|UpdateActionMods
argument_list|(
name|keymap
argument_list|,
operator|&
name|key
operator|->
name|groups
index|[
name|i
index|]
operator|.
name|levels
index|[
name|j
index|]
operator|.
name|action
argument_list|,
name|key
operator|->
name|modmap
argument_list|)
expr_stmt|;
comment|/* Update vmod -> led maps. */
name|darray_foreach
argument_list|(
argument|led
argument_list|,
argument|keymap->leds
argument_list|)
name|ComputeEffectiveMask
argument_list|(
name|keymap
argument_list|,
operator|&
name|led
operator|->
name|mods
argument_list|)
expr_stmt|;
comment|/* Find maximum number of groups out of all keys in the keymap. */
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
name|keymap
operator|->
name|num_groups
operator|=
name|MAX
argument_list|(
name|keymap
operator|->
name|num_groups
argument_list|,
name|key
operator|->
name|num_groups
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_function
specifier|static
name|bool
DECL|function|UpdateBuiltinKeymapFields
name|UpdateBuiltinKeymapFields
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
name|xkb_atom_intern
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
begin_return
return|return
name|true
return|;
end_return
begin_function_decl
unit|}  typedef
DECL|typedef|compile_file_fn
name|bool
function_decl|(
modifier|*
name|compile_file_fn
function_decl|)
parameter_list|(
name|XkbFile
modifier|*
name|file
parameter_list|,
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|enum
name|merge_mode
name|merge
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|compile_file_fns
specifier|static
specifier|const
name|compile_file_fn
name|compile_file_fns
index|[
name|LAST_KEYMAP_FILE_TYPE
operator|+
literal|1
index|]
init|=
block|{
index|[
name|FILE_TYPE_KEYCODES
index|]
operator|=
name|CompileKeycodes
block|,
index|[
name|FILE_TYPE_TYPES
index|]
operator|=
name|CompileKeyTypes
block|,
index|[
name|FILE_TYPE_COMPAT
index|]
operator|=
name|CompileCompatMap
block|,
index|[
name|FILE_TYPE_SYMBOLS
index|]
operator|=
name|CompileSymbols
block|, }
decl_stmt|;
end_decl_stmt
begin_function
name|bool
DECL|function|CompileKeymap
name|CompileKeymap
parameter_list|(
name|XkbFile
modifier|*
name|file
parameter_list|,
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|enum
name|merge_mode
name|merge
parameter_list|)
block|{
name|bool
name|ok
decl_stmt|;
specifier|const
name|char
modifier|*
name|main_name
decl_stmt|;
name|XkbFile
modifier|*
name|files
index|[
name|LAST_KEYMAP_FILE_TYPE
operator|+
literal|1
index|]
init|=
block|{
name|NULL
block|}
decl_stmt|;
name|enum
name|xkb_file_type
name|type
decl_stmt|;
name|struct
name|xkb_context
modifier|*
name|ctx
init|=
name|keymap
operator|->
name|ctx
decl_stmt|;
name|main_name
operator|=
name|file
operator|->
name|name
condition|?
name|file
operator|->
name|name
else|:
literal|"(unnamed)"
expr_stmt|;
comment|/* Collect section files and check for duplicates. */
for|for
control|(
name|file
operator|=
operator|(
name|XkbFile
operator|*
operator|)
name|file
operator|->
name|defs
init|;
name|file
condition|;
name|file
operator|=
operator|(
name|XkbFile
operator|*
operator|)
name|file
operator|->
name|common
operator|.
name|next
control|)
block|{
if|if
condition|(
name|file
operator|->
name|file_type
operator|<
name|FIRST_KEYMAP_FILE_TYPE
operator|||
name|file
operator|->
name|file_type
operator|>
name|LAST_KEYMAP_FILE_TYPE
condition|)
block|{
name|log_err
argument_list|(
name|ctx
argument_list|,
literal|"Cannot define %s in a keymap file\n"
argument_list|,
name|xkb_file_type_to_string
argument_list|(
name|file
operator|->
name|file_type
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|files
index|[
name|file
operator|->
name|file_type
index|]
condition|)
block|{
name|log_err
argument_list|(
name|ctx
argument_list|,
literal|"More than one %s section in keymap file; "
literal|"All sections after the first ignored\n"
argument_list|,
name|xkb_file_type_to_string
argument_list|(
name|file
operator|->
name|file_type
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|!
name|file
operator|->
name|topName
condition|)
block|{
name|free
argument_list|(
name|file
operator|->
name|topName
argument_list|)
expr_stmt|;
name|file
operator|->
name|topName
operator|=
name|strdup
argument_list|(
name|main_name
argument_list|)
expr_stmt|;
block|}
name|files
index|[
name|file
operator|->
name|file_type
index|]
operator|=
name|file
expr_stmt|;
block|}
comment|/*      * Check that all required section were provided.      * Report everything before failing.      */
name|ok
operator|=
name|true
expr_stmt|;
for|for
control|(
name|type
operator|=
name|FIRST_KEYMAP_FILE_TYPE
init|;
name|type
operator|<=
name|LAST_KEYMAP_FILE_TYPE
condition|;
name|type
operator|++
control|)
block|{
if|if
condition|(
name|files
index|[
name|type
index|]
operator|==
name|NULL
condition|)
block|{
name|log_err
argument_list|(
name|ctx
argument_list|,
literal|"Required section %s missing from keymap\n"
argument_list|,
name|xkb_file_type_to_string
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|ok
operator|=
name|false
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|ok
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|UpdateBuiltinKeymapFields
argument_list|(
name|keymap
argument_list|)
condition|)
return|return
name|false
return|;
comment|/* Compile sections. */
for|for
control|(
name|type
operator|=
name|FIRST_KEYMAP_FILE_TYPE
init|;
name|type
operator|<=
name|LAST_KEYMAP_FILE_TYPE
condition|;
name|type
operator|++
control|)
block|{
name|log_dbg
argument_list|(
name|ctx
argument_list|,
literal|"Compiling %s \"%s\"\n"
argument_list|,
name|xkb_file_type_to_string
argument_list|(
name|type
argument_list|)
argument_list|,
name|files
index|[
name|type
index|]
operator|->
name|topName
argument_list|)
expr_stmt|;
name|ok
operator|=
name|compile_file_fns
index|[
name|type
index|]
operator|(
name|files
index|[
name|type
index|]
operator|,
name|keymap
operator|,
name|merge
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|log_err
argument_list|(
name|ctx
argument_list|,
literal|"Failed to compile %s\n"
argument_list|,
name|xkb_file_type_to_string
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
block|}
return|return
name|UpdateDerivedKeymapFields
argument_list|(
name|keymap
argument_list|)
return|;
block|}
end_function
end_unit