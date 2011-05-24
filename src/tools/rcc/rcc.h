begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RCC_H
end_ifndef
begin_define
DECL|macro|RCC_H
define|#
directive|define
name|RCC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|RCCFileInfo
name|class
name|RCCFileInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|RCCResourceLibrary
block|{
name|RCCResourceLibrary
argument_list|(
specifier|const
name|RCCResourceLibrary
operator|&
argument_list|)
expr_stmt|;
name|RCCResourceLibrary
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RCCResourceLibrary
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|RCCResourceLibrary
argument_list|()
expr_stmt|;
operator|~
name|RCCResourceLibrary
argument_list|()
expr_stmt|;
name|bool
name|output
parameter_list|(
name|QIODevice
modifier|&
name|out
parameter_list|,
name|QIODevice
modifier|&
name|errorDevice
parameter_list|)
function_decl|;
name|bool
name|readFiles
parameter_list|(
name|bool
name|ignoreErrors
parameter_list|,
name|QIODevice
modifier|&
name|errorDevice
parameter_list|)
function_decl|;
enum|enum
name|Format
block|{
name|Binary
block|,
name|C_Code
block|}
enum|;
name|void
name|setFormat
parameter_list|(
name|Format
name|f
parameter_list|)
block|{
name|m_format
operator|=
name|f
expr_stmt|;
block|}
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|void
name|setInputFiles
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
block|{
name|m_fileNames
operator|=
name|files
expr_stmt|;
block|}
name|QStringList
name|inputFiles
argument_list|()
specifier|const
block|{
return|return
name|m_fileNames
return|;
block|}
name|QStringList
name|dataFiles
argument_list|()
specifier|const
expr_stmt|;
comment|// Return a map of resource identifier (':/newPrefix/images/p1.png') to file.
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|ResourceDataFileMap
expr_stmt|;
name|ResourceDataFileMap
name|resourceDataFileMap
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVerbose
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_verbose
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|verbose
argument_list|()
specifier|const
block|{
return|return
name|m_verbose
return|;
block|}
name|void
name|setInitName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|m_initName
operator|=
name|name
expr_stmt|;
block|}
name|QString
name|initName
argument_list|()
specifier|const
block|{
return|return
name|m_initName
return|;
block|}
name|void
name|setCompressLevel
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|m_compressLevel
operator|=
name|c
expr_stmt|;
block|}
name|int
name|compressLevel
argument_list|()
specifier|const
block|{
return|return
name|m_compressLevel
return|;
block|}
name|void
name|setCompressThreshold
parameter_list|(
name|int
name|t
parameter_list|)
block|{
name|m_compressThreshold
operator|=
name|t
expr_stmt|;
block|}
name|int
name|compressThreshold
argument_list|()
specifier|const
block|{
return|return
name|m_compressThreshold
return|;
block|}
name|void
name|setResourceRoot
parameter_list|(
specifier|const
name|QString
modifier|&
name|root
parameter_list|)
block|{
name|m_resourceRoot
operator|=
name|root
expr_stmt|;
block|}
name|QString
name|resourceRoot
argument_list|()
specifier|const
block|{
return|return
name|m_resourceRoot
return|;
block|}
name|void
name|setUseNameSpace
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|m_useNameSpace
operator|=
name|v
expr_stmt|;
block|}
name|bool
name|useNameSpace
argument_list|()
specifier|const
block|{
return|return
name|m_useNameSpace
return|;
block|}
name|QStringList
name|failedResources
argument_list|()
specifier|const
block|{
return|return
name|m_failedResources
return|;
block|}
name|private
label|:
struct|struct
name|Strings
block|{
name|Strings
argument_list|()
expr_stmt|;
specifier|const
name|QString
name|TAG_RCC
decl_stmt|;
specifier|const
name|QString
name|TAG_RESOURCE
decl_stmt|;
specifier|const
name|QString
name|TAG_FILE
decl_stmt|;
specifier|const
name|QString
name|ATTRIBUTE_LANG
decl_stmt|;
specifier|const
name|QString
name|ATTRIBUTE_PREFIX
decl_stmt|;
specifier|const
name|QString
name|ATTRIBUTE_ALIAS
decl_stmt|;
specifier|const
name|QString
name|ATTRIBUTE_THRESHOLD
decl_stmt|;
specifier|const
name|QString
name|ATTRIBUTE_COMPRESS
decl_stmt|;
block|}
struct|;
name|friend
name|class
name|RCCFileInfo
decl_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|bool
name|addFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|alias
parameter_list|,
specifier|const
name|RCCFileInfo
modifier|&
name|file
parameter_list|)
function_decl|;
name|bool
name|interpretResourceFile
parameter_list|(
name|QIODevice
modifier|*
name|inputDevice
parameter_list|,
specifier|const
name|QString
modifier|&
name|file
parameter_list|,
name|QString
name|currentPath
init|=
name|QString
argument_list|()
parameter_list|,
name|bool
name|ignoreErrors
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|writeHeader
parameter_list|()
function_decl|;
name|bool
name|writeDataBlobs
parameter_list|()
function_decl|;
name|bool
name|writeDataNames
parameter_list|()
function_decl|;
name|bool
name|writeDataStructure
parameter_list|()
function_decl|;
name|bool
name|writeInitializer
parameter_list|()
function_decl|;
name|void
name|writeMangleNamespaceFunction
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|writeAddNamespaceFunction
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|writeHex
parameter_list|(
name|quint8
name|number
parameter_list|)
function_decl|;
name|void
name|writeNumber2
parameter_list|(
name|quint16
name|number
parameter_list|)
function_decl|;
name|void
name|writeNumber4
parameter_list|(
name|quint32
name|number
parameter_list|)
function_decl|;
name|void
name|writeChar
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|m_out
operator|.
name|append
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
name|void
name|writeByteArray
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
specifier|const
name|Strings
name|m_strings
decl_stmt|;
name|RCCFileInfo
modifier|*
name|m_root
decl_stmt|;
name|QStringList
name|m_fileNames
decl_stmt|;
name|QString
name|m_resourceRoot
decl_stmt|;
name|QString
name|m_initName
decl_stmt|;
name|Format
name|m_format
decl_stmt|;
name|bool
name|m_verbose
decl_stmt|;
name|int
name|m_compressLevel
decl_stmt|;
name|int
name|m_compressThreshold
decl_stmt|;
name|int
name|m_treeOffset
decl_stmt|;
name|int
name|m_namesOffset
decl_stmt|;
name|int
name|m_dataOffset
decl_stmt|;
name|bool
name|m_useNameSpace
decl_stmt|;
name|QStringList
name|m_failedResources
decl_stmt|;
name|QIODevice
modifier|*
name|m_errorDevice
decl_stmt|;
name|QByteArray
name|m_out
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RCC_H
end_comment
end_unit
