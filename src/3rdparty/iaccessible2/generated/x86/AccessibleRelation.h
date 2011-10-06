begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the definitions for the interfaces */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:54 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleRelation.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
begin_comment
comment|/* verify that the<rpcndr.h> version is high enough to compile this file*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__REQUIRED_RPCNDR_H_VERSION__
end_ifndef
begin_define
DECL|macro|__REQUIRED_RPCNDR_H_VERSION__
define|#
directive|define
name|__REQUIRED_RPCNDR_H_VERSION__
value|475
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"rpc.h"
end_include
begin_include
include|#
directive|include
file|"rpcndr.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|__RPCNDR_H_VERSION__
end_ifndef
begin_error
error|#
directive|error
error|this stub requires an updated version of<rpcndr.h>
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __RPCNDR_H_VERSION__
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COM_NO_WINDOWS_H
end_ifndef
begin_include
include|#
directive|include
file|"windows.h"
end_include
begin_include
include|#
directive|include
file|"ole2.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*COM_NO_WINDOWS_H*/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__AccessibleRelation_h__
end_ifndef
begin_define
DECL|macro|__AccessibleRelation_h__
define|#
directive|define
name|__AccessibleRelation_h__
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>=
literal|1020
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Forward Declarations */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__IAccessibleRelation_FWD_DEFINED__
end_ifndef
begin_define
DECL|macro|__IAccessibleRelation_FWD_DEFINED__
define|#
directive|define
name|__IAccessibleRelation_FWD_DEFINED__
end_define
begin_typedef
DECL|typedef|IAccessibleRelation
typedef|typedef
name|interface
name|IAccessibleRelation
name|IAccessibleRelation
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __IAccessibleRelation_FWD_DEFINED__ */
end_comment
begin_comment
comment|/* header files for imported files */
end_comment
begin_include
include|#
directive|include
file|"objidl.h"
end_include
begin_include
include|#
directive|include
file|"oaidl.h"
end_include
begin_include
include|#
directive|include
file|"oleacc.h"
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
comment|/* interface __MIDL_itf_AccessibleRelation_0000_0000 */
comment|/* [local] */
DECL|macro|IA2_RELATION_CONTROLLED_BY
define|#
directive|define
name|IA2_RELATION_CONTROLLED_BY
value|( L"controlledBy" )
DECL|macro|IA2_RELATION_CONTROLLER_FOR
define|#
directive|define
name|IA2_RELATION_CONTROLLER_FOR
value|( L"controllerFor" )
DECL|macro|IA2_RELATION_DESCRIBED_BY
define|#
directive|define
name|IA2_RELATION_DESCRIBED_BY
value|( L"describedBy" )
DECL|macro|IA2_RELATION_DESCRIPTION_FOR
define|#
directive|define
name|IA2_RELATION_DESCRIPTION_FOR
value|( L"descriptionFor" )
DECL|macro|IA2_RELATION_EMBEDDED_BY
define|#
directive|define
name|IA2_RELATION_EMBEDDED_BY
value|( L"embeddedBy" )
DECL|macro|IA2_RELATION_EMBEDS
define|#
directive|define
name|IA2_RELATION_EMBEDS
value|( L"embeds" )
DECL|macro|IA2_RELATION_FLOWS_FROM
define|#
directive|define
name|IA2_RELATION_FLOWS_FROM
value|( L"flowsFrom" )
DECL|macro|IA2_RELATION_FLOWS_TO
define|#
directive|define
name|IA2_RELATION_FLOWS_TO
value|( L"flowsTo" )
DECL|macro|IA2_RELATION_LABEL_FOR
define|#
directive|define
name|IA2_RELATION_LABEL_FOR
value|( L"labelFor" )
DECL|macro|IA2_RELATION_LABELED_BY
define|#
directive|define
name|IA2_RELATION_LABELED_BY
value|( L"labelledBy" )
DECL|macro|IA2_RELATION_LABELLED_BY
define|#
directive|define
name|IA2_RELATION_LABELLED_BY
value|( L"labelledBy" )
DECL|macro|IA2_RELATION_MEMBER_OF
define|#
directive|define
name|IA2_RELATION_MEMBER_OF
value|( L"memberOf" )
DECL|macro|IA2_RELATION_NODE_CHILD_OF
define|#
directive|define
name|IA2_RELATION_NODE_CHILD_OF
value|( L"nodeChildOf" )
DECL|macro|IA2_RELATION_PARENT_WINDOW_OF
define|#
directive|define
name|IA2_RELATION_PARENT_WINDOW_OF
value|( L"parentWindowOf" )
DECL|macro|IA2_RELATION_POPUP_FOR
define|#
directive|define
name|IA2_RELATION_POPUP_FOR
value|( L"popupFor" )
DECL|macro|IA2_RELATION_SUBWINDOW_OF
define|#
directive|define
name|IA2_RELATION_SUBWINDOW_OF
value|( L"subwindowOf" )
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_AccessibleRelation_0000_0000_v0_0_c_ifspec
decl_stmt|;
specifier|extern
name|RPC_IF_HANDLE
name|__MIDL_itf_AccessibleRelation_0000_0000_v0_0_s_ifspec
decl_stmt|;
ifndef|#
directive|ifndef
name|__IAccessibleRelation_INTERFACE_DEFINED__
DECL|macro|__IAccessibleRelation_INTERFACE_DEFINED__
define|#
directive|define
name|__IAccessibleRelation_INTERFACE_DEFINED__
comment|/* interface IAccessibleRelation */
comment|/* [uuid][object] */
DECL|variable|IID_IAccessibleRelation
name|EXTERN_C
specifier|const
name|IID
name|IID_IAccessibleRelation
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CINTERFACE
argument_list|)
name|MIDL_INTERFACE
argument_list|(
literal|"7CDF86EE-C3DA-496a-BDA4-281B336E1FDC"
argument_list|)
name|IAccessibleRelation
label|:
name|public
name|IUnknown
block|{
name|public
label|:
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_relationType
parameter_list|(
comment|/* [retval][out] */
name|BSTR
modifier|*
name|relationType
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_localizedRelationType
parameter_list|(
comment|/* [retval][out] */
name|BSTR
modifier|*
name|localizedRelationType
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nTargets
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|nTargets
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_target
parameter_list|(
comment|/* [in] */
name|long
name|targetIndex
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|target
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_targets
parameter_list|(
comment|/* [in] */
name|long
name|maxTargets
parameter_list|,
comment|/* [length_is][size_is][out] */
name|IUnknown
modifier|*
modifier|*
name|targets
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nTargets
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
else|#
directive|else
comment|/* C style interface */
DECL|struct|IAccessibleRelationVtbl
typedef|typedef
struct|struct
name|IAccessibleRelationVtbl
block|{
name|BEGIN_INTERFACE
DECL|member|QueryInterface
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|QueryInterface
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|REFIID
name|riid
parameter_list|,
comment|/* [annotation][iid_is][out] */
name|__RPC__deref_out
name|void
modifier|*
modifier|*
name|ppvObject
parameter_list|)
function_decl|;
DECL|member|AddRef
name|ULONG
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|AddRef
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|)
function_decl|;
DECL|member|Release
name|ULONG
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|Release
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|)
function_decl|;
DECL|member|get_relationType
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_relationType
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|relationType
parameter_list|)
function_decl|;
DECL|member|get_localizedRelationType
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_localizedRelationType
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|localizedRelationType
parameter_list|)
function_decl|;
DECL|member|get_nTargets
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nTargets
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nTargets
parameter_list|)
function_decl|;
DECL|member|get_target
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_target
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|targetIndex
parameter_list|,
comment|/* [retval][out] */
name|IUnknown
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
DECL|member|get_targets
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_targets
function_decl|)
parameter_list|(
name|IAccessibleRelation
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|maxTargets
parameter_list|,
comment|/* [length_is][size_is][out] */
name|IUnknown
modifier|*
modifier|*
name|targets
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nTargets
parameter_list|)
function_decl|;
name|END_INTERFACE
block|}
DECL|typedef|IAccessibleRelationVtbl
name|IAccessibleRelationVtbl
typedef|;
name|interface
name|IAccessibleRelation
block|{
name|CONST_VTBL
name|struct
name|IAccessibleRelationVtbl
modifier|*
name|lpVtbl
decl_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|COBJMACROS
DECL|macro|IAccessibleRelation_QueryInterface
define|#
directive|define
name|IAccessibleRelation_QueryInterface
parameter_list|(
name|This
parameter_list|,
name|riid
parameter_list|,
name|ppvObject
parameter_list|)
define|\
value|( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
DECL|macro|IAccessibleRelation_AddRef
define|#
directive|define
name|IAccessibleRelation_AddRef
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> AddRef(This) )
DECL|macro|IAccessibleRelation_Release
define|#
directive|define
name|IAccessibleRelation_Release
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> Release(This) )
DECL|macro|IAccessibleRelation_get_relationType
define|#
directive|define
name|IAccessibleRelation_get_relationType
parameter_list|(
name|This
parameter_list|,
name|relationType
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_relationType(This,relationType) )
DECL|macro|IAccessibleRelation_get_localizedRelationType
define|#
directive|define
name|IAccessibleRelation_get_localizedRelationType
parameter_list|(
name|This
parameter_list|,
name|localizedRelationType
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_localizedRelationType(This,localizedRelationType) )
DECL|macro|IAccessibleRelation_get_nTargets
define|#
directive|define
name|IAccessibleRelation_get_nTargets
parameter_list|(
name|This
parameter_list|,
name|nTargets
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nTargets(This,nTargets) )
DECL|macro|IAccessibleRelation_get_target
define|#
directive|define
name|IAccessibleRelation_get_target
parameter_list|(
name|This
parameter_list|,
name|targetIndex
parameter_list|,
name|target
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_target(This,targetIndex,target) )
DECL|macro|IAccessibleRelation_get_targets
define|#
directive|define
name|IAccessibleRelation_get_targets
parameter_list|(
name|This
parameter_list|,
name|maxTargets
parameter_list|,
name|targets
parameter_list|,
name|nTargets
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_targets(This,maxTargets,targets,nTargets) )
endif|#
directive|endif
comment|/* COBJMACROS */
endif|#
directive|endif
comment|/* C style interface */
endif|#
directive|endif
comment|/* __IAccessibleRelation_INTERFACE_DEFINED__ */
comment|/* Additional Prototypes for ALL interfaces */
name|unsigned
name|long
name|__RPC_USER
name|BSTR_UserSize
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|char
modifier|*
name|__RPC_USER
name|BSTR_UserMarshal
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|char
modifier|*
name|__RPC_USER
name|BSTR_UserUnmarshal
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|void
name|__RPC_USER
name|BSTR_UserFree
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|,
name|BSTR
modifier|*
parameter_list|)
function_decl|;
comment|/* end of Additional Prototypes */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
