begin_unit
begin_comment
comment|/*  * Copyright Â© 2008 Ian Osgood<iano@quirkster.com>  * Copyright Â© 2008 Jamey Sharp<jamey@minilop.net>  * Copyright Â© 2008 Josh Triplett<josh@freedesktop.org>  * Copyright Â© 2008 Ulrich Eckhardt<doomster@knuut.de>  *  * Permission is hereby granted, free of charge, to any person  * obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy,  * modify, merge, publish, distribute, sublicense, and/or sell copies  * of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY  * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * Except as contained in this notice, the names of the authors or  * their institutions shall not be used in advertising or otherwise to  * promote the sale, use or other dealings in this Software without  * prior written authorization from the authors.  */
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_define
DECL|macro|XK_MISCELLANY
define|#
directive|define
name|XK_MISCELLANY
end_define
begin_define
DECL|macro|XK_XKB_KEYS
define|#
directive|define
name|XK_XKB_KEYS
end_define
begin_define
DECL|macro|XK_LATIN1
define|#
directive|define
name|XK_LATIN1
end_define
begin_define
DECL|macro|XK_LATIN2
define|#
directive|define
name|XK_LATIN2
end_define
begin_define
DECL|macro|XK_LATIN3
define|#
directive|define
name|XK_LATIN3
end_define
begin_define
DECL|macro|XK_LATIN4
define|#
directive|define
name|XK_LATIN4
end_define
begin_define
DECL|macro|XK_CYRILLIC
define|#
directive|define
name|XK_CYRILLIC
end_define
begin_define
DECL|macro|XK_GREEK
define|#
directive|define
name|XK_GREEK
end_define
begin_define
DECL|macro|XK_ARMENIAN
define|#
directive|define
name|XK_ARMENIAN
end_define
begin_include
include|#
directive|include
file|<X11/keysymdef.h>
end_include
begin_include
include|#
directive|include
file|"xcb_keysyms.h"
end_include
begin_comment
comment|/* Private declaration */
end_comment
begin_enum
DECL|enum|tag_t
enum|enum
name|tag_t
block|{
DECL|enumerator|TAG_COOKIE
name|TAG_COOKIE
block|,
DECL|enumerator|TAG_VALUE
name|TAG_VALUE
block|}
enum|;
end_enum
begin_struct
DECL|struct|_XCBKeySymbols
struct|struct
name|_XCBKeySymbols
block|{
DECL|member|c
name|xcb_connection_t
modifier|*
name|c
decl_stmt|;
DECL|member|tag
name|enum
name|tag_t
name|tag
decl_stmt|;
union|union
block|{
DECL|member|cookie
name|xcb_get_keyboard_mapping_cookie_t
name|cookie
decl_stmt|;
DECL|member|reply
name|xcb_get_keyboard_mapping_reply_t
modifier|*
name|reply
decl_stmt|;
block|}
DECL|member|u
name|u
union|;
block|}
struct|;
end_struct
begin_function_decl
specifier|static
name|void
name|xcb_convert_case
parameter_list|(
name|xcb_keysym_t
name|sym
parameter_list|,
name|xcb_keysym_t
modifier|*
name|lower
parameter_list|,
name|xcb_keysym_t
modifier|*
name|upper
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|xcb_key_symbols_get_reply
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* public implementation */
end_comment
begin_function
name|xcb_key_symbols_t
modifier|*
DECL|function|xcb_key_symbols_alloc
name|xcb_key_symbols_alloc
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
parameter_list|)
block|{
name|xcb_key_symbols_t
modifier|*
name|syms
decl_stmt|;
name|xcb_keycode_t
name|min_keycode
decl_stmt|;
name|xcb_keycode_t
name|max_keycode
decl_stmt|;
if|if
condition|(
operator|!
name|c
condition|)
return|return
name|NULL
return|;
name|syms
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|xcb_key_symbols_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|syms
condition|)
return|return
name|NULL
return|;
name|syms
operator|->
name|c
operator|=
name|c
expr_stmt|;
name|syms
operator|->
name|tag
operator|=
name|TAG_COOKIE
expr_stmt|;
name|min_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|c
argument_list|)
operator|->
name|min_keycode
expr_stmt|;
name|max_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|c
argument_list|)
operator|->
name|max_keycode
expr_stmt|;
name|syms
operator|->
name|u
operator|.
name|cookie
operator|=
name|xcb_get_keyboard_mapping
argument_list|(
name|c
argument_list|,
name|min_keycode
argument_list|,
name|max_keycode
operator|-
name|min_keycode
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|syms
return|;
block|}
end_function
begin_function
name|void
DECL|function|xcb_key_symbols_free
name|xcb_key_symbols_free
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|)
block|{
if|if
condition|(
name|syms
condition|)
block|{
if|if
condition|(
name|syms
operator|->
name|tag
operator|==
name|TAG_VALUE
condition|)
name|free
argument_list|(
name|syms
operator|->
name|u
operator|.
name|reply
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|syms
argument_list|)
expr_stmt|;
name|syms
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*  Use of the 'col' parameter:  A list of KeySyms is associated with each KeyCode. The list is intended to convey the set of symbols on the corresponding key. If the list (ignoring trailing NoSymbol entries) is a single KeySym ``K'', then the list is treated as if it were the list ``K NoSymbol K NoSymbol''. If the list (ignoring trailing NoSymbol entries) is a pair of KeySyms ``K1 K2'', then the list is treated as if it were the list ``K1 K2 K1 K2''. If the list (ignoring trailing NoSymbol entries) is a triple of KeySyms ``K1 K2 K3'', then the list is treated as if it were the list ``K1 K2 K3 NoSymbol''. When an explicit ``void'' element is desired in the list, the value VoidSymbol can be used.  The first four elements of the list are split into two groups of KeySyms. Group 1 contains the first and second KeySyms; Group 2 contains the third and fourth KeySyms. Within each group, if the second element of the group is NoSymbol , then the group should be treated as if the second element were the same as the first element, except when the first element is an alphabetic KeySym ``K'' for which both lowercase and uppercase forms are defined. In that case, the group should be treated as if the first element were the lowercase form of ``K'' and the second element were the uppercase form of ``K.''  The standard rules for obtaining a KeySym from a KeyPress event make use of only the Group 1 and Group 2 KeySyms; no interpretation of other KeySyms in the list is given. Which group to use is determined by the modifier state. Switching between groups is controlled by the KeySym named MODE SWITCH, by attaching that KeySym to some KeyCode and attaching that KeyCode to any one of the modifiers Mod1 through Mod5. This modifier is called the group modifier. For any KeyCode, Group 1 is used when the group modifier is off, and Group 2 is used when the group modifier is on.  The Lock modifier is interpreted as CapsLock when the KeySym named XK_Caps_Lock is attached to some KeyCode and that KeyCode is attached to the Lock modifier. The Lock modifier is interpreted as ShiftLock when the KeySym named XK_Shift_Lock is attached to some KeyCode and that KeyCode is attached to the Lock modifier. If the Lock modifier could be interpreted as both CapsLock and ShiftLock, the CapsLock interpretation is used.  The operation of keypad keys is controlled by the KeySym named XK_Num_Lock, by attaching that KeySym to some KeyCode and attaching that KeyCode to any one of the modifiers Mod1 through Mod5 . This modifier is called the numlock modifier. The standard KeySyms with the prefix ``XK_KP_'' in their name are called keypad KeySyms; these are KeySyms with numeric value in the hexadecimal range 0xFF80 to 0xFFBD inclusive. In addition, vendor-specific KeySyms in the hexadecimal range 0x11000000 to 0x1100FFFF are also keypad KeySyms.  Within a group, the choice of KeySym is determined by applying the first rule that is satisfied from the following list:  * The numlock modifier is on and the second KeySym is a keypad KeySym. In   this case, if the Shift modifier is on, or if the Lock modifier is on   and is interpreted as ShiftLock, then the first KeySym is used,   otherwise the second KeySym is used.  * The Shift and Lock modifiers are both off. In this case, the first   KeySym is used.  * The Shift modifier is off, and the Lock modifier is on and is   interpreted as CapsLock. In this case, the first KeySym is used, but   if that KeySym is lowercase alphabetic, then the corresponding   uppercase KeySym is used instead.  * The Shift modifier is on, and the Lock modifier is on and is   interpreted as CapsLock. In this case, the second KeySym is used, but   if that KeySym is lowercase alphabetic, then the corresponding   uppercase KeySym is used instead.  * The Shift modifier is on, or the Lock modifier is on and is   interpreted as ShiftLock, or both. In this case, the second KeySym is   used.  */
end_comment
begin_function
DECL|function|xcb_key_symbols_get_keysym
name|xcb_keysym_t
name|xcb_key_symbols_get_keysym
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_keycode_t
name|keycode
parameter_list|,
name|int
name|col
parameter_list|)
block|{
name|xcb_keysym_t
modifier|*
name|keysyms
decl_stmt|;
name|xcb_keysym_t
name|keysym_null
init|=
block|{
name|XCB_NO_SYMBOL
block|}
decl_stmt|;
name|xcb_keysym_t
name|lsym
decl_stmt|;
name|xcb_keysym_t
name|usym
decl_stmt|;
name|xcb_keycode_t
name|min_keycode
decl_stmt|;
name|xcb_keycode_t
name|max_keycode
decl_stmt|;
name|int
name|per
decl_stmt|;
if|if
condition|(
operator|!
name|syms
condition|)
return|return
name|keysym_null
return|;
name|xcb_key_symbols_get_reply
argument_list|(
name|syms
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|keysyms
operator|=
name|xcb_get_keyboard_mapping_keysyms
argument_list|(
name|syms
operator|->
name|u
operator|.
name|reply
argument_list|)
expr_stmt|;
name|min_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|min_keycode
expr_stmt|;
name|max_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|max_keycode
expr_stmt|;
name|per
operator|=
name|syms
operator|->
name|u
operator|.
name|reply
operator|->
name|keysyms_per_keycode
expr_stmt|;
if|if
condition|(
operator|(
name|col
operator|<
literal|0
operator|)
operator|||
operator|(
operator|(
name|col
operator|>=
name|per
operator|)
operator|&&
operator|(
name|col
operator|>
literal|3
operator|)
operator|)
operator|||
operator|(
name|keycode
operator|<
name|min_keycode
operator|)
operator|||
operator|(
name|keycode
operator|>
name|max_keycode
operator|)
condition|)
return|return
name|keysym_null
return|;
name|keysyms
operator|=
operator|&
name|keysyms
index|[
operator|(
name|keycode
operator|-
name|min_keycode
operator|)
operator|*
name|per
index|]
expr_stmt|;
if|if
condition|(
name|col
operator|<
literal|4
condition|)
block|{
if|if
condition|(
name|col
operator|>
literal|1
condition|)
block|{
while|while
condition|(
operator|(
name|per
operator|>
literal|2
operator|)
operator|&&
operator|(
name|keysyms
index|[
name|per
operator|-
literal|1
index|]
operator|==
name|XCB_NO_SYMBOL
operator|)
condition|)
name|per
operator|--
expr_stmt|;
if|if
condition|(
name|per
operator|<
literal|3
condition|)
name|col
operator|-=
literal|2
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|per
operator|<=
operator|(
name|col
operator||
literal|1
operator|)
operator|)
operator|||
operator|(
name|keysyms
index|[
name|col
operator||
literal|1
index|]
operator|==
name|XCB_NO_SYMBOL
operator|)
condition|)
block|{
name|xcb_convert_case
argument_list|(
name|keysyms
index|[
name|col
operator|&
operator|~
literal|1
index|]
argument_list|,
operator|&
name|lsym
argument_list|,
operator|&
name|usym
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|col
operator|&
literal|1
operator|)
condition|)
return|return
name|lsym
return|;
elseif|else
if|if
condition|(
name|usym
operator|==
name|lsym
condition|)
return|return
name|keysym_null
return|;
else|else
return|return
name|usym
return|;
block|}
block|}
return|return
name|keysyms
index|[
name|col
index|]
return|;
block|}
end_function
begin_function
name|xcb_keycode_t
modifier|*
DECL|function|xcb_key_symbols_get_keycode
name|xcb_key_symbols_get_keycode
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
name|xcb_keysym_t
name|ks
decl_stmt|;
name|int
name|j
decl_stmt|,
name|nresult
init|=
literal|0
decl_stmt|;
name|xcb_keycode_t
name|i
decl_stmt|,
name|min
decl_stmt|,
name|max
decl_stmt|,
modifier|*
name|result
init|=
name|NULL
decl_stmt|,
modifier|*
name|result_np
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|syms
condition|)
block|{
name|xcb_key_symbols_get_reply
argument_list|(
name|syms
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|min
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|min_keycode
expr_stmt|;
name|max
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|max_keycode
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|syms
operator|->
name|u
operator|.
name|reply
operator|->
name|keysyms_per_keycode
condition|;
name|j
operator|++
control|)
for|for
control|(
name|i
operator|=
name|min
init|;
name|i
operator|&&
name|i
operator|<=
name|max
condition|;
name|i
operator|++
control|)
block|{
name|ks
operator|=
name|xcb_key_symbols_get_keysym
argument_list|(
name|syms
argument_list|,
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
if|if
condition|(
name|ks
operator|==
name|keysym
condition|)
block|{
name|nresult
operator|++
expr_stmt|;
name|result_np
operator|=
name|realloc
argument_list|(
name|result
argument_list|,
sizeof|sizeof
argument_list|(
name|xcb_keycode_t
argument_list|)
operator|*
operator|(
name|nresult
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|result_np
operator|==
name|NULL
condition|)
block|{
name|free
argument_list|(
name|result
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|result
operator|=
name|result_np
expr_stmt|;
name|result
index|[
name|nresult
operator|-
literal|1
index|]
operator|=
name|i
expr_stmt|;
name|result
index|[
name|nresult
index|]
operator|=
name|XCB_NO_SYMBOL
expr_stmt|;
block|}
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
name|xcb_keysym_t
DECL|function|xcb_key_press_lookup_keysym
name|xcb_key_press_lookup_keysym
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_key_press_event_t
modifier|*
name|event
parameter_list|,
name|int
name|col
parameter_list|)
block|{
return|return
name|xcb_key_symbols_get_keysym
argument_list|(
name|syms
argument_list|,
name|event
operator|->
name|detail
argument_list|,
name|col
argument_list|)
return|;
block|}
end_function
begin_function
name|xcb_keysym_t
DECL|function|xcb_key_release_lookup_keysym
name|xcb_key_release_lookup_keysym
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_key_release_event_t
modifier|*
name|event
parameter_list|,
name|int
name|col
parameter_list|)
block|{
return|return
name|xcb_key_symbols_get_keysym
argument_list|(
name|syms
argument_list|,
name|event
operator|->
name|detail
argument_list|,
name|col
argument_list|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_refresh_keyboard_mapping
name|xcb_refresh_keyboard_mapping
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_mapping_notify_event_t
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|request
operator|==
name|XCB_MAPPING_KEYBOARD
operator|&&
name|syms
condition|)
block|{
if|if
condition|(
name|syms
operator|->
name|tag
operator|==
name|TAG_VALUE
condition|)
block|{
name|xcb_keycode_t
name|min_keycode
decl_stmt|;
name|xcb_keycode_t
name|max_keycode
decl_stmt|;
if|if
condition|(
name|syms
operator|->
name|u
operator|.
name|reply
condition|)
block|{
name|free
argument_list|(
name|syms
operator|->
name|u
operator|.
name|reply
argument_list|)
expr_stmt|;
name|syms
operator|->
name|u
operator|.
name|reply
operator|=
name|NULL
expr_stmt|;
block|}
name|syms
operator|->
name|tag
operator|=
name|TAG_COOKIE
expr_stmt|;
name|min_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|min_keycode
expr_stmt|;
name|max_keycode
operator|=
name|xcb_get_setup
argument_list|(
name|syms
operator|->
name|c
argument_list|)
operator|->
name|max_keycode
expr_stmt|;
name|syms
operator|->
name|u
operator|.
name|cookie
operator|=
name|xcb_get_keyboard_mapping
argument_list|(
name|syms
operator|->
name|c
argument_list|,
name|min_keycode
argument_list|,
name|max_keycode
operator|-
name|min_keycode
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* Tests for classes of symbols */
end_comment
begin_function
name|int
DECL|function|xcb_is_keypad_key
name|xcb_is_keypad_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
name|XK_KP_Space
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_KP_Equal
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_private_keypad_key
name|xcb_is_private_keypad_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
literal|0x11000000
operator|)
operator|&&
operator|(
name|keysym
operator|<=
literal|0x1100FFFF
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_cursor_key
name|xcb_is_cursor_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
name|XK_Home
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_Select
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_pf_key
name|xcb_is_pf_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
name|XK_KP_F1
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_KP_F4
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_function_key
name|xcb_is_function_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
name|XK_F1
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_F35
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_misc_function_key
name|xcb_is_misc_function_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
name|keysym
operator|>=
name|XK_Select
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_Break
operator|)
operator|)
return|;
block|}
end_function
begin_function
name|int
DECL|function|xcb_is_modifier_key
name|xcb_is_modifier_key
parameter_list|(
name|xcb_keysym_t
name|keysym
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|keysym
operator|>=
name|XK_Shift_L
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_Hyper_R
operator|)
operator|)
operator|||
operator|(
operator|(
name|keysym
operator|>=
name|XK_ISO_Lock
operator|)
operator|&&
operator|(
name|keysym
operator|<=
name|XK_ISO_Level5_Lock
operator|)
operator|)
operator|||
operator|(
name|keysym
operator|==
name|XK_Mode_switch
operator|)
operator|||
operator|(
name|keysym
operator|==
name|XK_Num_Lock
operator|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/* private functions */
end_comment
begin_function
name|void
DECL|function|xcb_convert_case
name|xcb_convert_case
parameter_list|(
name|xcb_keysym_t
name|sym
parameter_list|,
name|xcb_keysym_t
modifier|*
name|lower
parameter_list|,
name|xcb_keysym_t
modifier|*
name|upper
parameter_list|)
block|{
operator|*
name|lower
operator|=
name|sym
expr_stmt|;
operator|*
name|upper
operator|=
name|sym
expr_stmt|;
switch|switch
condition|(
name|sym
operator|>>
literal|8
condition|)
block|{
case|case
literal|0
case|:
comment|/* Latin 1 */
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_A
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_Z
operator|)
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_a
operator|-
name|XK_A
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_a
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_z
operator|)
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_a
operator|-
name|XK_A
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_Agrave
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_Odiaeresis
operator|)
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_agrave
operator|-
name|XK_Agrave
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_agrave
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_odiaeresis
operator|)
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_agrave
operator|-
name|XK_Agrave
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_Ooblique
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_Thorn
operator|)
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_oslash
operator|-
name|XK_Ooblique
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|sym
operator|>=
name|XK_oslash
operator|)
operator|&&
operator|(
name|sym
operator|<=
name|XK_thorn
operator|)
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_oslash
operator|-
name|XK_Ooblique
operator|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* Latin 2 */
comment|/* Assume the KeySym is a legal value (ignore discontinuities) */
if|if
condition|(
name|sym
operator|==
name|XK_Aogonek
condition|)
operator|*
name|lower
operator|=
name|XK_aogonek
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Lstroke
operator|&&
name|sym
operator|<=
name|XK_Sacute
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_lstroke
operator|-
name|XK_Lstroke
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Scaron
operator|&&
name|sym
operator|<=
name|XK_Zacute
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_scaron
operator|-
name|XK_Scaron
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Zcaron
operator|&&
name|sym
operator|<=
name|XK_Zabovedot
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_zcaron
operator|-
name|XK_Zcaron
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|==
name|XK_aogonek
condition|)
operator|*
name|upper
operator|=
name|XK_Aogonek
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_lstroke
operator|&&
name|sym
operator|<=
name|XK_sacute
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_lstroke
operator|-
name|XK_Lstroke
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_scaron
operator|&&
name|sym
operator|<=
name|XK_zacute
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_scaron
operator|-
name|XK_Scaron
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_zcaron
operator|&&
name|sym
operator|<=
name|XK_zabovedot
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_zcaron
operator|-
name|XK_Zcaron
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Racute
operator|&&
name|sym
operator|<=
name|XK_Tcedilla
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_racute
operator|-
name|XK_Racute
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_racute
operator|&&
name|sym
operator|<=
name|XK_tcedilla
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_racute
operator|-
name|XK_Racute
operator|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* Latin 3 */
comment|/* Assume the KeySym is a legal value (ignore discontinuities) */
if|if
condition|(
name|sym
operator|>=
name|XK_Hstroke
operator|&&
name|sym
operator|<=
name|XK_Hcircumflex
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_hstroke
operator|-
name|XK_Hstroke
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Gbreve
operator|&&
name|sym
operator|<=
name|XK_Jcircumflex
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_gbreve
operator|-
name|XK_Gbreve
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_hstroke
operator|&&
name|sym
operator|<=
name|XK_hcircumflex
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_hstroke
operator|-
name|XK_Hstroke
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_gbreve
operator|&&
name|sym
operator|<=
name|XK_jcircumflex
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_gbreve
operator|-
name|XK_Gbreve
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Cabovedot
operator|&&
name|sym
operator|<=
name|XK_Scircumflex
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_cabovedot
operator|-
name|XK_Cabovedot
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_cabovedot
operator|&&
name|sym
operator|<=
name|XK_scircumflex
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_cabovedot
operator|-
name|XK_Cabovedot
operator|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* Latin 4 */
comment|/* Assume the KeySym is a legal value (ignore discontinuities) */
if|if
condition|(
name|sym
operator|>=
name|XK_Rcedilla
operator|&&
name|sym
operator|<=
name|XK_Tslash
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_rcedilla
operator|-
name|XK_Rcedilla
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_rcedilla
operator|&&
name|sym
operator|<=
name|XK_tslash
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_rcedilla
operator|-
name|XK_Rcedilla
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|==
name|XK_ENG
condition|)
operator|*
name|lower
operator|=
name|XK_eng
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|==
name|XK_eng
condition|)
operator|*
name|upper
operator|=
name|XK_ENG
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Amacron
operator|&&
name|sym
operator|<=
name|XK_Umacron
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_amacron
operator|-
name|XK_Amacron
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_amacron
operator|&&
name|sym
operator|<=
name|XK_umacron
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_amacron
operator|-
name|XK_Amacron
operator|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
comment|/* Cyrillic */
comment|/* Assume the KeySym is a legal value (ignore discontinuities) */
if|if
condition|(
name|sym
operator|>=
name|XK_Serbian_DJE
operator|&&
name|sym
operator|<=
name|XK_Serbian_DZE
condition|)
operator|*
name|lower
operator|-=
operator|(
name|XK_Serbian_DJE
operator|-
name|XK_Serbian_dje
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Serbian_dje
operator|&&
name|sym
operator|<=
name|XK_Serbian_dze
condition|)
operator|*
name|upper
operator|+=
operator|(
name|XK_Serbian_DJE
operator|-
name|XK_Serbian_dje
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Cyrillic_YU
operator|&&
name|sym
operator|<=
name|XK_Cyrillic_HARDSIGN
condition|)
operator|*
name|lower
operator|-=
operator|(
name|XK_Cyrillic_YU
operator|-
name|XK_Cyrillic_yu
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Cyrillic_yu
operator|&&
name|sym
operator|<=
name|XK_Cyrillic_hardsign
condition|)
operator|*
name|upper
operator|+=
operator|(
name|XK_Cyrillic_YU
operator|-
name|XK_Cyrillic_yu
operator|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
comment|/* Greek */
comment|/* Assume the KeySym is a legal value (ignore discontinuities) */
if|if
condition|(
name|sym
operator|>=
name|XK_Greek_ALPHAaccent
operator|&&
name|sym
operator|<=
name|XK_Greek_OMEGAaccent
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_Greek_alphaaccent
operator|-
name|XK_Greek_ALPHAaccent
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Greek_alphaaccent
operator|&&
name|sym
operator|<=
name|XK_Greek_omegaaccent
operator|&&
name|sym
operator|!=
name|XK_Greek_iotaaccentdieresis
operator|&&
name|sym
operator|!=
name|XK_Greek_upsilonaccentdieresis
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_Greek_alphaaccent
operator|-
name|XK_Greek_ALPHAaccent
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Greek_ALPHA
operator|&&
name|sym
operator|<=
name|XK_Greek_OMEGA
condition|)
operator|*
name|lower
operator|+=
operator|(
name|XK_Greek_alpha
operator|-
name|XK_Greek_ALPHA
operator|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|>=
name|XK_Greek_alpha
operator|&&
name|sym
operator|<=
name|XK_Greek_omega
operator|&&
name|sym
operator|!=
name|XK_Greek_finalsmallsigma
condition|)
operator|*
name|upper
operator|-=
operator|(
name|XK_Greek_alpha
operator|-
name|XK_Greek_ALPHA
operator|)
expr_stmt|;
break|break;
case|case
literal|0x14
case|:
comment|/* Armenian */
if|if
condition|(
name|sym
operator|>=
name|XK_Armenian_AYB
operator|&&
name|sym
operator|<=
name|XK_Armenian_fe
condition|)
block|{
operator|*
name|lower
operator|=
name|sym
operator||
literal|1
expr_stmt|;
operator|*
name|upper
operator|=
name|sym
operator|&
operator|~
literal|1
expr_stmt|;
block|}
break|break;
block|}
block|}
end_function
begin_function
name|void
DECL|function|xcb_key_symbols_get_reply
name|xcb_key_symbols_get_reply
parameter_list|(
name|xcb_key_symbols_t
modifier|*
name|syms
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
operator|!
name|syms
condition|)
return|return;
if|if
condition|(
name|syms
operator|->
name|tag
operator|==
name|TAG_COOKIE
condition|)
block|{
name|syms
operator|->
name|tag
operator|=
name|TAG_VALUE
expr_stmt|;
name|syms
operator|->
name|u
operator|.
name|reply
operator|=
name|xcb_get_keyboard_mapping_reply
argument_list|(
name|syms
operator|->
name|c
argument_list|,
name|syms
operator|->
name|u
operator|.
name|cookie
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
