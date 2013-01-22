begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|MOC_MWERKS_PLUGIN
end_ifdef
begin_include
include|#
directive|include
file|"mwerks_mac.h"
end_include
begin_include
include|#
directive|include
file|"qt_mac.h"
end_include
begin_comment
comment|/* compiler headers */
end_comment
begin_include
include|#
directive|include
file|"DropInCompilerLinker.h"
end_include
begin_include
include|#
directive|include
file|"CompilerMapping.h"
end_include
begin_include
include|#
directive|include
file|"CWPluginErrors.h"
end_include
begin_comment
comment|/* standard headers */
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|//qglobal.cpp
specifier|const
name|unsigned
name|char
modifier|*
name|p_str
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QCString
name|pstring2qstring
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|CW_USE_PRAGMA_EXPORT
end_if
begin_pragma
pragma|#
directive|pragma
name|export
name|on
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|CWPlugin_GetDropInFlags
name|CWPLUGIN_ENTRY
function|(
name|CWPlugin_GetDropInFlags
function|)
parameter_list|(
specifier|const
name|DropInFlags
modifier|*
modifier|*
name|flags
parameter_list|,
name|long
modifier|*
name|flagsSize
parameter_list|)
block|{
specifier|static
specifier|const
name|DropInFlags
name|sFlags
init|=
block|{
name|kCurrentDropInFlagsVersion
block|,
name|CWDROPINCOMPILERTYPE
block|,
name|DROPINCOMPILERLINKERAPIVERSION_7
block|,
name|kCompAlwaysReload
operator||
name|kCompRequiresProjectBuildStartedMsg
block|,
name|Lang_C_CPP
block|,
name|DROPINCOMPILERLINKERAPIVERSION
block|}
decl_stmt|;
operator|*
name|flags
operator|=
operator|&
name|sFlags
expr_stmt|;
operator|*
name|flagsSize
operator|=
sizeof|sizeof
argument_list|(
name|sFlags
argument_list|)
expr_stmt|;
return|return
name|cwNoErr
return|;
block|}
end_function
begin_function
DECL|function|CWPlugin_GetDropInName
name|CWPLUGIN_ENTRY
function|(
name|CWPlugin_GetDropInName
function|)
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|dropinName
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|sDropInName
index|[]
init|=
literal|"McMoc"
decl_stmt|;
operator|*
name|dropinName
operator|=
name|sDropInName
expr_stmt|;
return|return
name|cwNoErr
return|;
block|}
end_function
begin_function
DECL|function|CWPlugin_GetDisplayName
name|CWPLUGIN_ENTRY
function|(
name|CWPlugin_GetDisplayName
function|)
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|displayName
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|sDisplayName
index|[]
init|=
literal|"McMoc"
decl_stmt|;
operator|*
name|displayName
operator|=
name|sDisplayName
expr_stmt|;
return|return
name|cwNoErr
return|;
block|}
end_function
begin_function
DECL|function|CWPlugin_GetTargetList
name|CWPLUGIN_ENTRY
function|(
name|CWPlugin_GetTargetList
function|)
parameter_list|(
specifier|const
name|CWTargetList
modifier|*
modifier|*
name|targetList
parameter_list|)
block|{
specifier|static
name|CWDataType
name|sCPU
init|=
name|targetCPUAny
decl_stmt|;
specifier|static
name|CWDataType
name|sOS
init|=
name|targetOSMacintosh
decl_stmt|;
specifier|static
name|CWTargetList
name|sTargetList
init|=
block|{
name|kCurrentCWTargetListVersion
block|,
literal|1
block|,
operator|&
name|sCPU
block|,
literal|1
block|,
operator|&
name|sOS
block|}
decl_stmt|;
operator|*
name|targetList
operator|=
operator|&
name|sTargetList
expr_stmt|;
return|return
name|cwNoErr
return|;
block|}
end_function
begin_function
DECL|function|CWPlugin_GetDefaultMappingList
name|CWPLUGIN_ENTRY
function|(
name|CWPlugin_GetDefaultMappingList
function|)
parameter_list|(
specifier|const
name|CWExtMapList
modifier|*
modifier|*
name|defaultMappingList
parameter_list|)
block|{
specifier|static
name|CWExtensionMapping
name|sExtension
index|[]
init|=
block|{
block|{
literal|'TEXT'
block|,
literal|".mocs"
block|,
name|kPrecompile
block|}
block|}
decl_stmt|;
specifier|static
name|CWExtMapList
name|sExtensionMapList
init|=
block|{
name|kCurrentCWExtMapListVersion
block|,
literal|3
block|,
name|sExtension
block|}
decl_stmt|;
operator|*
name|defaultMappingList
operator|=
operator|&
name|sExtensionMapList
expr_stmt|;
return|return
name|cwNoErr
return|;
block|}
end_function
begin_if
if|#
directive|if
name|CW_USE_PRAGMA_EXPORT
end_if
begin_pragma
pragma|#
directive|pragma
name|export
name|off
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|CWFileRef
typedef|typedef
name|short
name|CWFileRef
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|line_count
specifier|static
name|int
name|line_count
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function_decl
name|moc_status
name|do_moc
parameter_list|(
name|CWPluginContext
parameter_list|,
specifier|const
name|QCString
modifier|&
parameter_list|,
specifier|const
name|QCString
modifier|&
parameter_list|,
name|CWFileSpec
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|mocify
specifier|static
name|CWResult
name|mocify
parameter_list|(
name|CWPluginContext
name|context
parameter_list|,
specifier|const
name|QCString
modifier|&
name|source
parameter_list|)
block|{
name|CWDisplayLines
argument_list|(
name|context
argument_list|,
name|line_count
operator|++
argument_list|)
expr_stmt|;
name|source
operator|.
name|stripWhiteSpace
argument_list|()
expr_stmt|;
name|CWResult
name|err
decl_stmt|;
name|bool
name|dotmoc
init|=
literal|false
decl_stmt|;
name|QCString
name|stem
init|=
name|source
decl_stmt|,
name|ext
decl_stmt|;
name|int
name|dotpos
init|=
name|stem
operator|.
name|findRev
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|dotpos
operator|!=
operator|-
literal|1
condition|)
block|{
name|ext
operator|=
name|stem
operator|.
name|right
argument_list|(
name|stem
operator|.
name|length
argument_list|()
operator|-
operator|(
name|dotpos
operator|+
literal|1
operator|)
argument_list|)
expr_stmt|;
name|stem
operator|=
name|stem
operator|.
name|left
argument_list|(
name|dotpos
argument_list|)
expr_stmt|;
if|if
condition|(
name|ext
operator|==
literal|"cpp"
condition|)
name|dotmoc
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
comment|//whoa!
block|}
name|QCString
name|dest
decl_stmt|;
if|if
condition|(
name|dotmoc
condition|)
name|dest
operator|=
name|stem
operator|+
literal|".moc"
expr_stmt|;
else|else
name|dest
operator|=
literal|"moc_"
operator|+
name|stem
operator|+
literal|".cpp"
expr_stmt|;
comment|//moc it
name|CWFileSpec
name|destSpec
decl_stmt|;
name|moc_status
name|mocd
init|=
name|do_moc
argument_list|(
name|context
argument_list|,
name|source
argument_list|,
name|dest
argument_list|,
operator|&
name|destSpec
argument_list|,
name|dotmoc
argument_list|)
decl_stmt|;
if|#
directive|if
literal|0
block|QCString derr = "Weird";     switch(mocd) {     case moc_success: derr = "Success"; break;     case moc_parse_error: derr = "Parser Error"; break;     case moc_no_qobject:derr = "No QOBJECT"; break;     case moc_not_time: derr = "Not Time"; break;     case moc_no_source: derr = "No Source"; break;     case moc_general_error: derr = "General Error"; break;     }         char        dmsg[200];         sprintf(dmsg, "\"%s\" %s", source.data(), derr.data());         CWReportMessage(context, NULL, dmsg, NULL, messagetypeError, 0);
endif|#
directive|endif
comment|//handle project
if|if
condition|(
name|mocd
operator|==
name|moc_no_qobject
condition|)
block|{
name|char
name|msg
index|[
literal|400
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|msg
argument_list|,
literal|"\"%s\" No relevant classes found. No output generated."
argument_list|,
name|source
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|CWReportMessage
argument_list|(
name|context
argument_list|,
name|NULL
argument_list|,
name|msg
argument_list|,
name|NULL
argument_list|,
name|messagetypeWarning
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|mocd
operator|==
name|moc_success
operator|||
name|mocd
operator|==
name|moc_not_time
operator|)
operator|&&
operator|!
name|dotmoc
condition|)
block|{
name|long
name|whichFile
decl_stmt|;
name|CWNewProjectEntryInfo
name|ei
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ei
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
name|ei
argument_list|)
argument_list|)
expr_stmt|;
name|ei
operator|.
name|groupPath
operator|=
literal|"QtGenerated"
expr_stmt|;
name|err
operator|=
name|CWAddProjectEntry
argument_list|(
name|context
argument_list|,
operator|&
name|destSpec
argument_list|,
literal|true
argument_list|,
operator|&
name|ei
argument_list|,
operator|&
name|whichFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CWSUCCESS
argument_list|(
name|err
argument_list|)
condition|)
block|{
name|char
name|msg
index|[
literal|200
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|msg
argument_list|,
literal|"\"%s\" not added"
argument_list|,
name|dest
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|CWReportMessage
argument_list|(
name|context
argument_list|,
name|NULL
argument_list|,
name|msg
argument_list|,
name|NULL
argument_list|,
name|messagetypeWarning
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mocd
operator|==
name|moc_success
condition|)
name|CWSetModDate
argument_list|(
name|context
argument_list|,
operator|&
name|destSpec
argument_list|,
name|NULL
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
return|return
name|cwNoErr
return|;
block|}
end_function
begin_function
DECL|function|main
name|pascal
name|short
name|main
parameter_list|(
name|CWPluginContext
name|context
parameter_list|)
block|{
name|short
name|result
decl_stmt|;
name|long
name|request
decl_stmt|;
if|if
condition|(
name|CWGetPluginRequest
argument_list|(
name|context
argument_list|,
operator|&
name|request
argument_list|)
operator|!=
name|cwNoErr
condition|)
return|return
name|cwErrRequestFailed
return|;
name|result
operator|=
name|cwErrInvalidParameter
expr_stmt|;
comment|/* dispatch on compiler request */
switch|switch
condition|(
name|request
condition|)
block|{
case|case
name|reqInitCompiler
case|:
case|case
name|reqTermCompiler
case|:
name|result
operator|=
name|cwNoErr
expr_stmt|;
break|break;
case|case
name|reqCompile
case|:
block|{
name|line_count
operator|=
literal|0
expr_stmt|;
specifier|const
name|char
modifier|*
name|files
init|=
name|NULL
decl_stmt|;
name|long
name|filelen
decl_stmt|;
name|CWGetMainFileText
argument_list|(
name|context
argument_list|,
operator|&
name|files
argument_list|,
operator|&
name|filelen
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|beg
init|=
name|files
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|filelen
condition|;
name|x
operator|++
control|)
block|{
if|if
condition|(
operator|*
operator|(
name|files
operator|++
operator|)
operator|==
literal|'\r'
condition|)
block|{
name|char
name|file
index|[
literal|1024
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|file
argument_list|,
name|beg
argument_list|,
name|files
operator|-
name|beg
argument_list|)
expr_stmt|;
name|file
index|[
operator|(
name|files
operator|-
name|beg
operator|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|mocify
argument_list|(
name|context
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|beg
operator|=
name|files
expr_stmt|;
block|}
block|}
if|if
condition|(
name|beg
operator|!=
name|files
condition|)
block|{
name|char
name|file
index|[
literal|1024
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|file
argument_list|,
name|beg
argument_list|,
name|files
operator|-
name|beg
argument_list|)
expr_stmt|;
name|file
index|[
operator|(
name|files
operator|-
name|beg
operator|)
index|]
operator|=
literal|'\0'
expr_stmt|;
name|mocify
argument_list|(
name|context
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
name|result
operator|=
name|cwNoErr
expr_stmt|;
break|break;
block|}
block|}
comment|/* return result code */
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
