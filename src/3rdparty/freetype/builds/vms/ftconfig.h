begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftconfig.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    VMS-specific configuration file (specification only).                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2006, 2007, 2008 by             */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This header file contains a number of macro definitions that are used */
end_comment
begin_comment
comment|/* by the rest of the engine.  Most of the macros here are automatically */
end_comment
begin_comment
comment|/* determined at compile time, and you should not need to change it to   */
end_comment
begin_comment
comment|/* port FreeType, except to compile the library with a non-ANSI          */
end_comment
begin_comment
comment|/* compiler.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note however that if some specific modifications are needed, we       */
end_comment
begin_comment
comment|/* advise you to place a modified copy in your build directory.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The build directory is usually `freetype/builds/<system>', and        */
end_comment
begin_comment
comment|/* contains system-specific files that are always included first when    */
end_comment
begin_comment
comment|/* building the library.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTCONFIG_H__
end_ifndef
begin_define
DECL|macro|__FTCONFIG_H__
define|#
directive|define
name|__FTCONFIG_H__
end_define
begin_comment
comment|/* Include the header file containing all developer build options */
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_OPTIONS_H
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_STANDARD_LIBRARY_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*               PLATFORM-SPECIFIC CONFIGURATION MACROS                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These macros can be toggled to suit a specific system.  The current   */
end_comment
begin_comment
comment|/* ones are defaults used to compile FreeType in an ANSI C environment   */
end_comment
begin_comment
comment|/* (16bit compilers are also supported).  Copy this file to your own     */
end_comment
begin_comment
comment|/* `freetype/builds/<system>' directory, and edit it to port the engine. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|HAVE_UNISTD_H
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define
begin_define
DECL|macro|HAVE_FCNTL_H
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define
begin_define
DECL|macro|SIZEOF_INT
define|#
directive|define
name|SIZEOF_INT
value|4
end_define
begin_define
DECL|macro|SIZEOF_LONG
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define
begin_define
DECL|macro|FT_SIZEOF_INT
define|#
directive|define
name|FT_SIZEOF_INT
value|4
end_define
begin_define
DECL|macro|FT_SIZEOF_LONG
define|#
directive|define
name|FT_SIZEOF_LONG
value|4
end_define
begin_define
DECL|macro|FT_CHAR_BIT
define|#
directive|define
name|FT_CHAR_BIT
value|8
end_define
begin_comment
comment|/* Preferred alignment of data */
end_comment
begin_define
DECL|macro|FT_ALIGNMENT
define|#
directive|define
name|FT_ALIGNMENT
value|8
end_define
begin_comment
comment|/* FT_UNUSED is a macro used to indicate that a given parameter is not  */
end_comment
begin_comment
comment|/* used -- this is only used to get rid of unpleasant compiler warnings */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_UNUSED
end_ifndef
begin_define
DECL|macro|FT_UNUSED
define|#
directive|define
name|FT_UNUSED
parameter_list|(
name|arg
parameter_list|)
value|( (arg) = (arg) )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                     AUTOMATIC CONFIGURATION MACROS                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These macros are computed from the ones defined above.  Don't touch   */
end_comment
begin_comment
comment|/* their definition, unless you know precisely what you are doing.  No   */
end_comment
begin_comment
comment|/* porter should need to mess with them.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Mac support                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   This is the only necessary change, so it is defined here instead    */
end_comment
begin_comment
comment|/*   providing a new configuration file.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DARWIN_NO_CARBON
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
name|defined
argument_list|(
name|macintosh
argument_list|)
operator|)
end_if
begin_comment
comment|/* no Carbon frameworks for 64bit 10.4.x */
end_comment
begin_include
include|#
directive|include
file|"AvailabilityMacros.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|&&
expr|\
operator|(
name|MAC_OS_X_VERSION_MIN_REQUIRED
operator|<=
name|MAC_OS_X_VERSION_10_4
operator|)
end_if
begin_define
DECL|macro|DARWIN_NO_CARBON
define|#
directive|define
name|DARWIN_NO_CARBON
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|FT_MACINTOSH
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__SC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MRC__
argument_list|)
end_elif
begin_comment
comment|/* Classic MacOS compilers */
end_comment
begin_include
include|#
directive|include
file|"ConditionalMacros.h"
end_include
begin_if
if|#
directive|if
name|TARGET_OS_MAC
end_if
begin_define
define|#
directive|define
name|FT_MACINTOSH
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* IntN types                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Used to guarantee the size of some specific integers.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Int16
typedef|typedef
name|signed
name|short
name|FT_Int16
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UInt16
typedef|typedef
name|unsigned
name|short
name|FT_UInt16
typedef|;
end_typedef
begin_if
if|#
directive|if
name|FT_SIZEOF_INT
operator|==
literal|4
end_if
begin_typedef
DECL|typedef|FT_Int32
typedef|typedef
name|signed
name|int
name|FT_Int32
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UInt32
typedef|typedef
name|unsigned
name|int
name|FT_UInt32
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
name|FT_SIZEOF_LONG
operator|==
literal|4
end_elif
begin_typedef
DECL|typedef|FT_Int32
typedef|typedef
name|signed
name|long
name|FT_Int32
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UInt32
typedef|typedef
name|unsigned
name|long
name|FT_UInt32
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"no 32bit type found -- please check your configuration files"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* look up an integer type that is at least 32 bits */
end_comment
begin_if
if|#
directive|if
name|FT_SIZEOF_INT
operator|>=
literal|4
end_if
begin_typedef
DECL|typedef|FT_Fast
typedef|typedef
name|int
name|FT_Fast
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UFast
typedef|typedef
name|unsigned
name|int
name|FT_UFast
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
name|FT_SIZEOF_LONG
operator|>=
literal|4
end_elif
begin_typedef
DECL|typedef|FT_Fast
typedef|typedef
name|long
name|FT_Fast
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_UFast
typedef|typedef
name|unsigned
name|long
name|FT_UFast
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* determine whether we have a 64-bit int type for platforms without */
end_comment
begin_comment
comment|/* Autoconf                                                          */
end_comment
begin_if
if|#
directive|if
name|FT_SIZEOF_LONG
operator|==
literal|8
end_if
begin_comment
comment|/* FT_LONG64 must be defined if a 64-bit type is available */
end_comment
begin_define
DECL|macro|FT_LONG64
define|#
directive|define
name|FT_LONG64
end_define
begin_define
DECL|macro|FT_INT64
define|#
directive|define
name|FT_INT64
value|long
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|900
end_elif
begin_comment
comment|/* Visual C++ (and Intel C++) */
end_comment
begin_comment
comment|/* this compiler provides the __int64 type */
end_comment
begin_define
DECL|macro|FT_LONG64
define|#
directive|define
name|FT_LONG64
end_define
begin_define
DECL|macro|FT_INT64
define|#
directive|define
name|FT_INT64
value|__int64
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_elif
begin_comment
comment|/* Borland C++ */
end_comment
begin_comment
comment|/* XXXX: We should probably check the value of __BORLANDC__ in order */
end_comment
begin_comment
comment|/*       to test the compiler version.                               */
end_comment
begin_comment
comment|/* this compiler provides the __int64 type */
end_comment
begin_define
DECL|macro|FT_LONG64
define|#
directive|define
name|FT_LONG64
end_define
begin_define
DECL|macro|FT_INT64
define|#
directive|define
name|FT_INT64
value|__int64
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__WATCOMC__
argument_list|)
end_elif
begin_comment
comment|/* Watcom C++ */
end_comment
begin_comment
comment|/* Watcom doesn't provide 64-bit data types */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
end_elif
begin_comment
comment|/* Metrowerks CodeWarrior */
end_comment
begin_define
DECL|macro|FT_LONG64
define|#
directive|define
name|FT_LONG64
end_define
begin_define
DECL|macro|FT_INT64
define|#
directive|define
name|FT_INT64
value|long long int
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif
begin_comment
comment|/* GCC provides the `long long' type */
end_comment
begin_define
DECL|macro|FT_LONG64
define|#
directive|define
name|FT_LONG64
end_define
begin_define
DECL|macro|FT_INT64
define|#
directive|define
name|FT_INT64
value|long long int
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_SIZEOF_LONG == 8 */
end_comment
begin_define
DECL|macro|FT_BEGIN_STMNT
define|#
directive|define
name|FT_BEGIN_STMNT
value|do {
end_define
begin_define
DECL|macro|FT_END_STMNT
define|#
directive|define
name|FT_END_STMNT
value|} while ( 0 )
end_define
begin_define
DECL|macro|FT_DUMMY_STMNT
define|#
directive|define
name|FT_DUMMY_STMNT
value|FT_BEGIN_STMNT FT_END_STMNT
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A 64-bit data type will create compilation problems if you compile    */
end_comment
begin_comment
comment|/* in strict ANSI mode.  To avoid them, we disable their use if          */
end_comment
begin_comment
comment|/* __STDC__ is defined.  You can however ignore this rule by             */
end_comment
begin_comment
comment|/* defining the FT_CONFIG_OPTION_FORCE_INT64 configuration macro.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|FT_LONG64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FT_CONFIG_OPTION_FORCE_INT64
argument_list|)
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef
begin_comment
comment|/* undefine the 64-bit macros in strict ANSI compilation mode */
end_comment
begin_undef
DECL|macro|FT_LONG64
undef|#
directive|undef
name|FT_LONG64
end_undef
begin_undef
DECL|macro|FT_INT64
undef|#
directive|undef
name|FT_INT64
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __STDC__ */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_LONG64&& !FT_CONFIG_OPTION_FORCE_INT64 */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_MAKE_OPTION_SINGLE_OBJECT
end_ifdef
begin_define
DECL|macro|FT_LOCAL
define|#
directive|define
name|FT_LOCAL
parameter_list|(
name|x
parameter_list|)
value|static  x
end_define
begin_define
DECL|macro|FT_LOCAL_DEF
define|#
directive|define
name|FT_LOCAL_DEF
parameter_list|(
name|x
parameter_list|)
value|static  x
end_define
begin_else
else|#
directive|else
end_else
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_LOCAL
define|#
directive|define
name|FT_LOCAL
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_define
DECL|macro|FT_LOCAL_DEF
define|#
directive|define
name|FT_LOCAL_DEF
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_LOCAL
define|#
directive|define
name|FT_LOCAL
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_define
DECL|macro|FT_LOCAL_DEF
define|#
directive|define
name|FT_LOCAL_DEF
parameter_list|(
name|x
parameter_list|)
value|x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_MAKE_OPTION_SINGLE_OBJECT */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_BASE
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_BASE
define|#
directive|define
name|FT_BASE
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_BASE
define|#
directive|define
name|FT_BASE
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_BASE */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_BASE_DEF
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_BASE_DEF
define|#
directive|define
name|FT_BASE_DEF
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_BASE_DEF
define|#
directive|define
name|FT_BASE_DEF
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_BASE_DEF */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_EXPORT
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_EXPORT
define|#
directive|define
name|FT_EXPORT
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_EXPORT
define|#
directive|define
name|FT_EXPORT
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_EXPORT */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_EXPORT_DEF
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_EXPORT_DEF
define|#
directive|define
name|FT_EXPORT_DEF
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_EXPORT_DEF
define|#
directive|define
name|FT_EXPORT_DEF
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_EXPORT_DEF */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_EXPORT_VAR
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_EXPORT_VAR
define|#
directive|define
name|FT_EXPORT_VAR
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_EXPORT_VAR
define|#
directive|define
name|FT_EXPORT_VAR
parameter_list|(
name|x
parameter_list|)
value|extern  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_EXPORT_VAR */
end_comment
begin_comment
comment|/* The following macros are needed to compile the library with a   */
end_comment
begin_comment
comment|/* C++ compiler and with 16bit compilers.                          */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/* This is special.  Within C++, you must specify `extern "C"' for */
end_comment
begin_comment
comment|/* functions which are used via function pointers, and you also    */
end_comment
begin_comment
comment|/* must do that for structures which contain function pointers to  */
end_comment
begin_comment
comment|/* assure C linkage -- it's not possible to have (local) anonymous */
end_comment
begin_comment
comment|/* functions which are accessed by (global) function pointers.     */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/* FT_CALLBACK_DEF is used to _define_ a callback function.        */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/* FT_CALLBACK_TABLE is used to _declare_ a constant variable that */
end_comment
begin_comment
comment|/* contains pointers to callback functions.                        */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/* FT_CALLBACK_TABLE_DEF is used to _define_ a constant variable   */
end_comment
begin_comment
comment|/* that contains pointers to callback functions.                   */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_comment
comment|/* Some 16bit compilers have to redefine these macros to insert    */
end_comment
begin_comment
comment|/* the infamous `_cdecl' or `__fastcall' declarations.             */
end_comment
begin_comment
comment|/*                                                                 */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CALLBACK_DEF
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_CALLBACK_DEF
define|#
directive|define
name|FT_CALLBACK_DEF
parameter_list|(
name|x
parameter_list|)
value|extern "C"  x
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_CALLBACK_DEF
define|#
directive|define
name|FT_CALLBACK_DEF
parameter_list|(
name|x
parameter_list|)
value|static  x
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CALLBACK_DEF */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CALLBACK_TABLE
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_CALLBACK_TABLE
define|#
directive|define
name|FT_CALLBACK_TABLE
value|extern "C"
end_define
begin_define
DECL|macro|FT_CALLBACK_TABLE_DEF
define|#
directive|define
name|FT_CALLBACK_TABLE_DEF
value|extern "C"
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_CALLBACK_TABLE
define|#
directive|define
name|FT_CALLBACK_TABLE
value|extern
end_define
begin_define
DECL|macro|FT_CALLBACK_TABLE_DEF
define|#
directive|define
name|FT_CALLBACK_TABLE_DEF
end_define
begin_comment
DECL|macro|FT_CALLBACK_TABLE_DEF
comment|/* nothing */
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
comment|/* FT_CALLBACK_TABLE */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCONFIG_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
