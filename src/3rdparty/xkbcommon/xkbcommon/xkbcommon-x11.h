begin_unit
begin_comment
comment|/*  * Copyright Â© 2013 Ran Benita  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_XKBCOMMON_X11_H
end_ifndef
begin_define
DECL|macro|_XKBCOMMON_X11_H
define|#
directive|define
name|_XKBCOMMON_X11_H
end_define
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * @file  * libxkbcommon-x11 API - Additional X11 support for xkbcommon.  */
comment|/**  * @defgroup x11 X11 support  * Additional X11 support for xkbcommon.  *  * @{  */
comment|/**  * The minimal compatible major version of the XKB X11 extension which  * this library can use.  */
DECL|macro|XKB_X11_MIN_MAJOR_XKB_VERSION
define|#
directive|define
name|XKB_X11_MIN_MAJOR_XKB_VERSION
value|1
comment|/**  * The minimal compatible minor version of the XKB X11 extension which  * this library can use (for the minimal major version).  */
DECL|macro|XKB_X11_MIN_MINOR_XKB_VERSION
define|#
directive|define
name|XKB_X11_MIN_MINOR_XKB_VERSION
value|0
comment|/** Flags for the xkb_x11_setup_xkb_extension() function. */
DECL|enum|xkb_x11_setup_xkb_extension_flags
enum|enum
name|xkb_x11_setup_xkb_extension_flags
block|{
comment|/** Do not apply any flags. */
DECL|enumerator|XKB_X11_SETUP_XKB_EXTENSION_NO_FLAGS
name|XKB_X11_SETUP_XKB_EXTENSION_NO_FLAGS
init|=
literal|0
block|}
enum|;
comment|/**  * Setup the XKB X11 extension for this X client.  *  * The xkbcommon-x11 library uses various XKB requests.  Before doing so,  * an X client must notify the server that it will be using the extension.  * This function (or an XCB equivalent) must be called before any other  * function in this library is used.  *  * Some X servers may not support or disable the XKB extension.  If you  * want to support such servers, you need to use a different fallback.  *  * You may call this function several times; it is idempotent.  *  * @param connection  *     An XCB connection to the X server.  * @param major_xkb_version, minor_xkb_version  *     The XKB extension version to request.  To operate correctly, you  *     must have (major_xkb_version, minor_xkb_version)>=  *     (XKB_X11_MIN_MAJOR_XKB_VERSION, XKB_X11_MIN_MINOR_XKB_VERSION),  *     though this is not enforced.  * @param flags  *     Optional flags, or 0.  * @param[out] major_xkb_version_out, minor_xkb_version_out  *     Backfilled with the compatible XKB extension version numbers picked  *     by the server.  Can be NULL.  * @param[out] base_event_out  *     Backfilled with the XKB base (also known as first) event code, needed  *     to distinguish XKB events.  Can be NULL.  * @param[out] base_error_out  *     Backfilled with the XKB base (also known as first) error code, needed  *     to distinguish XKB errors.  Can be NULL.  *  * @returns 1 on success, or 0 on failure.  */
name|int
name|xkb_x11_setup_xkb_extension
parameter_list|(
name|xcb_connection_t
modifier|*
name|connection
parameter_list|,
name|uint16_t
name|major_xkb_version
parameter_list|,
name|uint16_t
name|minor_xkb_version
parameter_list|,
name|enum
name|xkb_x11_setup_xkb_extension_flags
name|flags
parameter_list|,
name|uint16_t
modifier|*
name|major_xkb_version_out
parameter_list|,
name|uint16_t
modifier|*
name|minor_xkb_version_out
parameter_list|,
name|uint8_t
modifier|*
name|base_event_out
parameter_list|,
name|uint8_t
modifier|*
name|base_error_out
parameter_list|)
function_decl|;
comment|/**  * Get the keyboard device ID of the core X11 keyboard.  *  * @param connection An XCB connection to the X server.  *  * @returns A device ID which may be used with other xkb_x11_* functions,  *          or -1 on failure.  */
name|int32_t
name|xkb_x11_get_core_keyboard_device_id
parameter_list|(
name|xcb_connection_t
modifier|*
name|connection
parameter_list|)
function_decl|;
comment|/**  * Create a keymap from an X11 keyboard device.  *  * This function queries the X server with various requests, fetches the  * details of the active keymap on a keyboard device, and creates an  * xkb_keymap from these details.  *  * @param context  *     The context in which to create the keymap.  * @param connection  *     An XCB connection to the X server.  * @param device_id  *     An XInput 1 device ID (in the range 0-255) with input class KEY.  *     Passing values outside of this range is an error.  * @param flags  *     Optional flags for the keymap, or 0.  *  * @returns A keymap retrieved from the X server, or NULL on failure.  *  * @memberof xkb_keymap  */
name|struct
name|xkb_keymap
modifier|*
name|xkb_x11_keymap_new_from_device
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|context
parameter_list|,
name|xcb_connection_t
modifier|*
name|connection
parameter_list|,
name|int32_t
name|device_id
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
function_decl|;
comment|/**  * Create a new keyboard state object from an X11 keyboard device.  *  * This function is the same as xkb_state_new(), only pre-initialized  * with the state of the device at the time this function is called.  *  * @param keymap  *     The keymap for which to create the state.  * @param connection  *     An XCB connection to the X server.  * @param device_id  *     An XInput 1 device ID (in the range 0-255) with input class KEY.  *     Passing values outside of this range is an error.  *  * @returns A new keyboard state object, or NULL on failure.  *  * @memberof xkb_state  */
name|struct
name|xkb_state
modifier|*
name|xkb_x11_state_new_from_device
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xcb_connection_t
modifier|*
name|connection
parameter_list|,
name|int32_t
name|device_id
parameter_list|)
function_decl|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_comment
comment|/* extern "C" */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _XKBCOMMON_X11_H */
end_comment
end_unit
