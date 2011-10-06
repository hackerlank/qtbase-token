begin_unit
begin_comment
comment|/* this ALWAYS GENERATED file contains the definitions for the interfaces */
end_comment
begin_comment
comment|/* File created by MIDL compiler version 7.00.0555 */
end_comment
begin_comment
comment|/* at Thu Mar 08 14:53:53 2012  */
end_comment
begin_comment
comment|/* Compiler settings for AccessibleHypertext.idl:     Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555      protocol : dce , ms_ext, c_ext, robust     error checks: allocation ref bounds_check enum stub_data      VC __declspec() decoration level:           __declspec(uuid()), __declspec(selectany), __declspec(novtable)          DECLSPEC_UUID(), MIDL_INTERFACE() */
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
name|__AccessibleHypertext_h__
end_ifndef
begin_define
DECL|macro|__AccessibleHypertext_h__
define|#
directive|define
name|__AccessibleHypertext_h__
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
name|__IAccessibleHypertext_FWD_DEFINED__
end_ifndef
begin_define
DECL|macro|__IAccessibleHypertext_FWD_DEFINED__
define|#
directive|define
name|__IAccessibleHypertext_FWD_DEFINED__
end_define
begin_typedef
DECL|typedef|IAccessibleHypertext
typedef|typedef
name|interface
name|IAccessibleHypertext
name|IAccessibleHypertext
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __IAccessibleHypertext_FWD_DEFINED__ */
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
begin_include
include|#
directive|include
file|"AccessibleText.h"
end_include
begin_include
include|#
directive|include
file|"AccessibleHyperlink.h"
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
ifndef|#
directive|ifndef
name|__IAccessibleHypertext_INTERFACE_DEFINED__
DECL|macro|__IAccessibleHypertext_INTERFACE_DEFINED__
define|#
directive|define
name|__IAccessibleHypertext_INTERFACE_DEFINED__
comment|/* interface IAccessibleHypertext */
comment|/* [uuid][object] */
DECL|variable|IID_IAccessibleHypertext
name|EXTERN_C
specifier|const
name|IID
name|IID_IAccessibleHypertext
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
literal|"6B4F8BBF-F1F2-418a-B35E-A195BC4103B9"
argument_list|)
name|IAccessibleHypertext
label|:
name|public
name|IAccessibleText
block|{
name|public
label|:
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_nHyperlinks
parameter_list|(
comment|/* [retval][out] */
name|long
modifier|*
name|hyperlinkCount
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_hyperlink
parameter_list|(
comment|/* [in] */
name|long
name|index
parameter_list|,
comment|/* [retval][out] */
name|IAccessibleHyperlink
modifier|*
modifier|*
name|hyperlink
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
comment|/* [propget] */
name|HRESULT
name|STDMETHODCALLTYPE
name|get_hyperlinkIndex
parameter_list|(
comment|/* [in] */
name|long
name|charIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|hyperlinkIndex
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
else|#
directive|else
comment|/* C style interface */
DECL|struct|IAccessibleHypertextVtbl
typedef|typedef
struct|struct
name|IAccessibleHypertextVtbl
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
name|IAccessibleHypertext
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
name|IAccessibleHypertext
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
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|)
function_decl|;
DECL|member|addSelection
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|addSelection
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|startOffset
parameter_list|,
comment|/* [in] */
name|long
name|endOffset
parameter_list|)
function_decl|;
DECL|member|get_attributes
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_attributes
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|startOffset
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|endOffset
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|textAttributes
parameter_list|)
function_decl|;
DECL|member|get_caretOffset
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_caretOffset
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|offset
parameter_list|)
function_decl|;
DECL|member|get_characterExtents
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_characterExtents
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|,
comment|/* [in] */
name|enum
name|IA2CoordinateType
name|coordType
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|x
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|y
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|width
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|height
parameter_list|)
function_decl|;
DECL|member|get_nSelections
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nSelections
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nSelections
parameter_list|)
function_decl|;
DECL|member|get_offsetAtPoint
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_offsetAtPoint
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|x
parameter_list|,
comment|/* [in] */
name|long
name|y
parameter_list|,
comment|/* [in] */
name|enum
name|IA2CoordinateType
name|coordType
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|offset
parameter_list|)
function_decl|;
DECL|member|get_selection
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_selection
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|selectionIndex
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|startOffset
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|endOffset
parameter_list|)
function_decl|;
DECL|member|get_text
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_text
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|startOffset
parameter_list|,
comment|/* [in] */
name|long
name|endOffset
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
DECL|member|get_textBeforeOffset
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_textBeforeOffset
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|,
comment|/* [in] */
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|startOffset
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|endOffset
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
DECL|member|get_textAfterOffset
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_textAfterOffset
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|,
comment|/* [in] */
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|startOffset
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|endOffset
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
DECL|member|get_textAtOffset
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_textAtOffset
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|,
comment|/* [in] */
name|enum
name|IA2TextBoundaryType
name|boundaryType
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|startOffset
parameter_list|,
comment|/* [out] */
name|long
modifier|*
name|endOffset
parameter_list|,
comment|/* [retval][out] */
name|BSTR
modifier|*
name|text
parameter_list|)
function_decl|;
DECL|member|removeSelection
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|removeSelection
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|selectionIndex
parameter_list|)
function_decl|;
DECL|member|setCaretOffset
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|setCaretOffset
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|offset
parameter_list|)
function_decl|;
DECL|member|setSelection
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|setSelection
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|selectionIndex
parameter_list|,
comment|/* [in] */
name|long
name|startOffset
parameter_list|,
comment|/* [in] */
name|long
name|endOffset
parameter_list|)
function_decl|;
DECL|member|get_nCharacters
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nCharacters
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|nCharacters
parameter_list|)
function_decl|;
DECL|member|scrollSubstringTo
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|scrollSubstringTo
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|startIndex
parameter_list|,
comment|/* [in] */
name|long
name|endIndex
parameter_list|,
comment|/* [in] */
name|enum
name|IA2ScrollType
name|scrollType
parameter_list|)
function_decl|;
DECL|member|scrollSubstringToPoint
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|scrollSubstringToPoint
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|startIndex
parameter_list|,
comment|/* [in] */
name|long
name|endIndex
parameter_list|,
comment|/* [in] */
name|enum
name|IA2CoordinateType
name|coordinateType
parameter_list|,
comment|/* [in] */
name|long
name|x
parameter_list|,
comment|/* [in] */
name|long
name|y
parameter_list|)
function_decl|;
DECL|member|get_newText
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_newText
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|IA2TextSegment
modifier|*
name|newText
parameter_list|)
function_decl|;
DECL|member|get_oldText
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_oldText
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|IA2TextSegment
modifier|*
name|oldText
parameter_list|)
function_decl|;
DECL|member|get_nHyperlinks
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_nHyperlinks
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|hyperlinkCount
parameter_list|)
function_decl|;
DECL|member|get_hyperlink
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_hyperlink
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|index
parameter_list|,
comment|/* [retval][out] */
name|IAccessibleHyperlink
modifier|*
modifier|*
name|hyperlink
parameter_list|)
function_decl|;
DECL|member|get_hyperlinkIndex
comment|/* [propget] */
name|HRESULT
function_decl|(
name|STDMETHODCALLTYPE
modifier|*
name|get_hyperlinkIndex
function_decl|)
parameter_list|(
name|IAccessibleHypertext
modifier|*
name|This
parameter_list|,
comment|/* [in] */
name|long
name|charIndex
parameter_list|,
comment|/* [retval][out] */
name|long
modifier|*
name|hyperlinkIndex
parameter_list|)
function_decl|;
name|END_INTERFACE
block|}
DECL|typedef|IAccessibleHypertextVtbl
name|IAccessibleHypertextVtbl
typedef|;
name|interface
name|IAccessibleHypertext
block|{
name|CONST_VTBL
name|struct
name|IAccessibleHypertextVtbl
modifier|*
name|lpVtbl
decl_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|COBJMACROS
DECL|macro|IAccessibleHypertext_QueryInterface
define|#
directive|define
name|IAccessibleHypertext_QueryInterface
parameter_list|(
name|This
parameter_list|,
name|riid
parameter_list|,
name|ppvObject
parameter_list|)
define|\
value|( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
DECL|macro|IAccessibleHypertext_AddRef
define|#
directive|define
name|IAccessibleHypertext_AddRef
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> AddRef(This) )
DECL|macro|IAccessibleHypertext_Release
define|#
directive|define
name|IAccessibleHypertext_Release
parameter_list|(
name|This
parameter_list|)
define|\
value|( (This)->lpVtbl -> Release(This) )
DECL|macro|IAccessibleHypertext_addSelection
define|#
directive|define
name|IAccessibleHypertext_addSelection
parameter_list|(
name|This
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|)
define|\
value|( (This)->lpVtbl -> addSelection(This,startOffset,endOffset) )
DECL|macro|IAccessibleHypertext_get_attributes
define|#
directive|define
name|IAccessibleHypertext_get_attributes
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|,
name|textAttributes
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_attributes(This,offset,startOffset,endOffset,textAttributes) )
DECL|macro|IAccessibleHypertext_get_caretOffset
define|#
directive|define
name|IAccessibleHypertext_get_caretOffset
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_caretOffset(This,offset) )
DECL|macro|IAccessibleHypertext_get_characterExtents
define|#
directive|define
name|IAccessibleHypertext_get_characterExtents
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|,
name|coordType
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_characterExtents(This,offset,coordType,x,y,width,height) )
DECL|macro|IAccessibleHypertext_get_nSelections
define|#
directive|define
name|IAccessibleHypertext_get_nSelections
parameter_list|(
name|This
parameter_list|,
name|nSelections
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nSelections(This,nSelections) )
DECL|macro|IAccessibleHypertext_get_offsetAtPoint
define|#
directive|define
name|IAccessibleHypertext_get_offsetAtPoint
parameter_list|(
name|This
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|coordType
parameter_list|,
name|offset
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_offsetAtPoint(This,x,y,coordType,offset) )
DECL|macro|IAccessibleHypertext_get_selection
define|#
directive|define
name|IAccessibleHypertext_get_selection
parameter_list|(
name|This
parameter_list|,
name|selectionIndex
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_selection(This,selectionIndex,startOffset,endOffset) )
DECL|macro|IAccessibleHypertext_get_text
define|#
directive|define
name|IAccessibleHypertext_get_text
parameter_list|(
name|This
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|,
name|text
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_text(This,startOffset,endOffset,text) )
DECL|macro|IAccessibleHypertext_get_textBeforeOffset
define|#
directive|define
name|IAccessibleHypertext_get_textBeforeOffset
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|,
name|boundaryType
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|,
name|text
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_textBeforeOffset(This,offset,boundaryType,startOffset,endOffset,text) )
DECL|macro|IAccessibleHypertext_get_textAfterOffset
define|#
directive|define
name|IAccessibleHypertext_get_textAfterOffset
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|,
name|boundaryType
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|,
name|text
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_textAfterOffset(This,offset,boundaryType,startOffset,endOffset,text) )
DECL|macro|IAccessibleHypertext_get_textAtOffset
define|#
directive|define
name|IAccessibleHypertext_get_textAtOffset
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|,
name|boundaryType
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|,
name|text
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_textAtOffset(This,offset,boundaryType,startOffset,endOffset,text) )
DECL|macro|IAccessibleHypertext_removeSelection
define|#
directive|define
name|IAccessibleHypertext_removeSelection
parameter_list|(
name|This
parameter_list|,
name|selectionIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> removeSelection(This,selectionIndex) )
DECL|macro|IAccessibleHypertext_setCaretOffset
define|#
directive|define
name|IAccessibleHypertext_setCaretOffset
parameter_list|(
name|This
parameter_list|,
name|offset
parameter_list|)
define|\
value|( (This)->lpVtbl -> setCaretOffset(This,offset) )
DECL|macro|IAccessibleHypertext_setSelection
define|#
directive|define
name|IAccessibleHypertext_setSelection
parameter_list|(
name|This
parameter_list|,
name|selectionIndex
parameter_list|,
name|startOffset
parameter_list|,
name|endOffset
parameter_list|)
define|\
value|( (This)->lpVtbl -> setSelection(This,selectionIndex,startOffset,endOffset) )
DECL|macro|IAccessibleHypertext_get_nCharacters
define|#
directive|define
name|IAccessibleHypertext_get_nCharacters
parameter_list|(
name|This
parameter_list|,
name|nCharacters
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nCharacters(This,nCharacters) )
DECL|macro|IAccessibleHypertext_scrollSubstringTo
define|#
directive|define
name|IAccessibleHypertext_scrollSubstringTo
parameter_list|(
name|This
parameter_list|,
name|startIndex
parameter_list|,
name|endIndex
parameter_list|,
name|scrollType
parameter_list|)
define|\
value|( (This)->lpVtbl -> scrollSubstringTo(This,startIndex,endIndex,scrollType) )
DECL|macro|IAccessibleHypertext_scrollSubstringToPoint
define|#
directive|define
name|IAccessibleHypertext_scrollSubstringToPoint
parameter_list|(
name|This
parameter_list|,
name|startIndex
parameter_list|,
name|endIndex
parameter_list|,
name|coordinateType
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|( (This)->lpVtbl -> scrollSubstringToPoint(This,startIndex,endIndex,coordinateType,x,y) )
DECL|macro|IAccessibleHypertext_get_newText
define|#
directive|define
name|IAccessibleHypertext_get_newText
parameter_list|(
name|This
parameter_list|,
name|newText
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_newText(This,newText) )
DECL|macro|IAccessibleHypertext_get_oldText
define|#
directive|define
name|IAccessibleHypertext_get_oldText
parameter_list|(
name|This
parameter_list|,
name|oldText
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_oldText(This,oldText) )
DECL|macro|IAccessibleHypertext_get_nHyperlinks
define|#
directive|define
name|IAccessibleHypertext_get_nHyperlinks
parameter_list|(
name|This
parameter_list|,
name|hyperlinkCount
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_nHyperlinks(This,hyperlinkCount) )
DECL|macro|IAccessibleHypertext_get_hyperlink
define|#
directive|define
name|IAccessibleHypertext_get_hyperlink
parameter_list|(
name|This
parameter_list|,
name|index
parameter_list|,
name|hyperlink
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_hyperlink(This,index,hyperlink) )
DECL|macro|IAccessibleHypertext_get_hyperlinkIndex
define|#
directive|define
name|IAccessibleHypertext_get_hyperlinkIndex
parameter_list|(
name|This
parameter_list|,
name|charIndex
parameter_list|,
name|hyperlinkIndex
parameter_list|)
define|\
value|( (This)->lpVtbl -> get_hyperlinkIndex(This,charIndex,hyperlinkIndex) )
endif|#
directive|endif
comment|/* COBJMACROS */
endif|#
directive|endif
comment|/* C style interface */
endif|#
directive|endif
comment|/* __IAccessibleHypertext_INTERFACE_DEFINED__ */
comment|/* Additional Prototypes for ALL interfaces */
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
