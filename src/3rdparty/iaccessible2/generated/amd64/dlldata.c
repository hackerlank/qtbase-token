begin_unit
begin_comment
comment|/*********************************************************    DllData file -- generated by MIDL compiler           DO NOT ALTER THIS FILE     This file is regenerated by MIDL on every IDL file compile.     To completely reconstruct this file, delete it and rerun MIDL    on all the IDL files in this DLL, specifying this file for the    /dlldata command line option  *********************************************************/
end_comment
begin_define
DECL|macro|PROXY_DELEGATION
define|#
directive|define
name|PROXY_DELEGATION
end_define
begin_include
include|#
directive|include
file|<rpcproxy.h>
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
name|EXTERN_PROXY_FILE
argument_list|(
argument|ia2_api_all
argument_list|)
name|PROXYFILE_LIST_START
comment|/* Start of list */
name|REFERENCE_PROXY_FILE
argument_list|(
name|ia2_api_all
argument_list|)
decl_stmt|,
comment|/* End of list */
name|PROXYFILE_LIST_END
name|DLLDATA_ROUTINES
argument_list|(
name|aProxyFileList
argument_list|,
name|GET_DLL_CLSID
argument_list|)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_comment
comment|/*extern "C" */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* end of generated dlldata file */
end_comment
end_unit
