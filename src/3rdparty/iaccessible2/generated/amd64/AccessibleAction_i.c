begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */
end_comment
begin_comment
comment|/* link this file in with the server and any clients */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:56 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleAction.idl:     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
end_comment
begin_comment
comment|/* @@MIDL_FILE_HEADING(  ) */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4049
name|)
end_pragma
begin_comment
comment|/* more than 64k source lines */
end_comment
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
include|#
directive|include
file|<rpc.h>
include|#
directive|include
file|<rpcndr.h>
ifdef|#
directive|ifdef
name|_MIDL_USE_GUIDDEF_
ifndef|#
directive|ifndef
name|INITGUID
DECL|macro|INITGUID
define|#
directive|define
name|INITGUID
include|#
directive|include
file|<guiddef.h>
DECL|macro|INITGUID
undef|#
directive|undef
name|INITGUID
else|#
directive|else
include|#
directive|include
file|<guiddef.h>
endif|#
directive|endif
DECL|macro|MIDL_DEFINE_GUID
define|#
directive|define
name|MIDL_DEFINE_GUID
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|l
parameter_list|,
name|w1
parameter_list|,
name|w2
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|,
name|b3
parameter_list|,
name|b4
parameter_list|,
name|b5
parameter_list|,
name|b6
parameter_list|,
name|b7
parameter_list|,
name|b8
parameter_list|)
define|\
value|DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)
else|#
directive|else
comment|// !_MIDL_USE_GUIDDEF_
ifndef|#
directive|ifndef
name|__IID_DEFINED__
DECL|macro|__IID_DEFINED__
define|#
directive|define
name|__IID_DEFINED__
DECL|struct|_IID
typedef|typedef
struct|struct
name|_IID
block|{
DECL|member|x
name|unsigned
name|long
name|x
decl_stmt|;
DECL|member|s1
name|unsigned
name|short
name|s1
decl_stmt|;
DECL|member|s2
name|unsigned
name|short
name|s2
decl_stmt|;
DECL|member|c
name|unsigned
name|char
name|c
index|[
literal|8
index|]
decl_stmt|;
block|}
DECL|typedef|IID
name|IID
typedef|;
endif|#
directive|endif
comment|// __IID_DEFINED__
ifndef|#
directive|ifndef
name|CLSID_DEFINED
DECL|macro|CLSID_DEFINED
define|#
directive|define
name|CLSID_DEFINED
DECL|typedef|CLSID
typedef|typedef
name|IID
name|CLSID
typedef|;
endif|#
directive|endif
comment|// CLSID_DEFINED
DECL|macro|MIDL_DEFINE_GUID
define|#
directive|define
name|MIDL_DEFINE_GUID
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|l
parameter_list|,
name|w1
parameter_list|,
name|w2
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|,
name|b3
parameter_list|,
name|b4
parameter_list|,
name|b5
parameter_list|,
name|b6
parameter_list|,
name|b7
parameter_list|,
name|b8
parameter_list|)
define|\
value|const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}
endif|#
directive|endif
endif|!_MIDL_USE_GUIDDEF_
name|MIDL_DEFINE_GUID
argument_list|(
name|IID
argument_list|,
name|IID_IAccessibleAction
argument_list|,
literal|0xB70D9F59
argument_list|,
literal|0x3B5A
argument_list|,
literal|0x4dba
argument_list|,
literal|0xAB
argument_list|,
literal|0x9E
argument_list|,
literal|0x22
argument_list|,
literal|0x01
argument_list|,
literal|0x2F
argument_list|,
literal|0x60
argument_list|,
literal|0x7D
argument_list|,
literal|0xF5
argument_list|)
expr_stmt|;
DECL|macro|MIDL_DEFINE_GUID
undef|#
directive|undef
name|MIDL_DEFINE_GUID
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
end_unit
