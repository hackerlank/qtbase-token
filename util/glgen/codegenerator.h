begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utilities of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CODEGENERATOR_H
end_ifndef
begin_define
DECL|macro|CODEGENERATOR_H
define|#
directive|define
name|CODEGENERATOR_H
end_define
begin_include
include|#
directive|include
file|"specparser.h"
end_include
begin_decl_stmt
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CodeGenerator
block|{
name|public
label|:
name|explicit
name|CodeGenerator
parameter_list|()
function_decl|;
name|void
name|setParser
parameter_list|(
name|SpecParser
modifier|*
name|parser
parameter_list|)
block|{
name|m_parser
operator|=
name|parser
expr_stmt|;
block|}
name|void
name|generateCoreClasses
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|)
decl|const
decl_stmt|;
name|void
name|generateExtensionClasses
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// Generic support
enum|enum
name|ClassVisibility
block|{
name|Public
block|,
name|Private
block|}
enum|;
enum|enum
name|ClassComponent
block|{
name|Declaration
init|=
literal|0
block|,
name|Definition
block|}
enum|;
name|bool
name|isLegacyVersion
argument_list|(
name|Version
name|v
argument_list|)
decl|const
decl_stmt|;
name|bool
name|versionHasProfiles
argument_list|(
name|Version
name|v
argument_list|)
decl|const
decl_stmt|;
name|FunctionCollection
name|functionCollection
argument_list|(
specifier|const
name|VersionProfile
operator|&
name|classVersionProfile
argument_list|)
decl|const
decl_stmt|;
name|void
name|writePreamble
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|,
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
name|replacement
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|writePostamble
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|,
name|QTextStream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
name|QString
name|passByType
argument_list|(
specifier|const
name|Argument
operator|&
name|arg
argument_list|)
decl|const
decl_stmt|;
name|QString
name|safeArgumentName
argument_list|(
specifier|const
name|QString
operator|&
name|arg
argument_list|)
decl|const
decl_stmt|;
comment|// Core functionality support
name|QString
name|coreClassFileName
argument_list|(
specifier|const
name|VersionProfile
operator|&
name|versionProfile
argument_list|,
specifier|const
name|QString
operator|&
name|fileExtension
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeCoreHelperClasses
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|ClassComponent
name|component
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeCoreClasses
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeCoreFactoryHeader
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeCoreFactoryImplementation
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|generateClassName
argument_list|(
specifier|const
name|VersionProfile
operator|&
name|classVersion
argument_list|,
name|ClassVisibility
name|visibility
operator|=
name|Public
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeBackendClassDeclaration
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|VersionProfile
operator|&
name|versionProfile
argument_list|,
specifier|const
name|QString
operator|&
name|baseClass
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeBackendClassImplementation
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|VersionProfile
operator|&
name|versionProfile
argument_list|,
specifier|const
name|QString
operator|&
name|baseClass
argument_list|)
decl|const
decl_stmt|;
name|void
name|writePublicClassDeclaration
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|,
specifier|const
name|VersionProfile
operator|&
name|versionProfile
argument_list|,
specifier|const
name|QString
operator|&
name|baseClass
argument_list|)
decl|const
decl_stmt|;
name|void
name|writePublicClassImplementation
argument_list|(
specifier|const
name|QString
operator|&
name|baseFileName
argument_list|,
specifier|const
name|VersionProfile
operator|&
name|versionProfile
argument_list|,
specifier|const
name|QString
operator|&
name|baseClass
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeClassFunctionDeclarations
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|FunctionCollection
operator|&
name|functionSets
argument_list|,
name|ClassVisibility
name|visibility
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeFunctionDeclaration
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|Function
operator|&
name|f
argument_list|,
name|ClassVisibility
name|visibility
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeClassInlineFunctions
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
operator|&
name|className
argument_list|,
specifier|const
name|FunctionCollection
operator|&
name|functionSet
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeInlineFunction
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
operator|&
name|className
argument_list|,
specifier|const
name|QString
operator|&
name|backendVar
argument_list|,
specifier|const
name|Function
operator|&
name|f
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeEntryPointResolutionCode
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|FunctionCollection
operator|&
name|functionSet
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeEntryPointResolutionStatement
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|Function
operator|&
name|f
argument_list|,
specifier|const
name|QString
operator|&
name|prefix
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|useGetProcAddress
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|VersionProfile
operator|>
name|backendsForFunctionCollection
argument_list|(
argument|const FunctionCollection&functionSet
argument_list|)
specifier|const
expr_stmt|;
name|QString
name|backendClassName
argument_list|(
specifier|const
name|VersionProfile
operator|&
name|v
argument_list|)
decl|const
decl_stmt|;
name|QString
name|backendVariableName
argument_list|(
specifier|const
name|VersionProfile
operator|&
name|v
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeBackendVariableDeclarations
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QList
operator|<
name|VersionProfile
operator|>
operator|&
name|backends
argument_list|)
decl|const
decl_stmt|;
comment|// Extension class support
name|void
name|writeExtensionHeader
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeExtensionImplementation
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeExtensionClassDeclaration
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
operator|&
name|extension
argument_list|,
name|ClassVisibility
name|visibility
operator|=
name|Public
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeExtensionClassImplementation
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
operator|&
name|extension
argument_list|)
decl|const
decl_stmt|;
name|QString
name|generateExtensionClassName
argument_list|(
specifier|const
name|QString
operator|&
name|extension
argument_list|,
name|ClassVisibility
name|visibility
operator|=
name|Public
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeExtensionInlineFunction
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|,
specifier|const
name|QString
operator|&
name|className
argument_list|,
specifier|const
name|Function
operator|&
name|f
argument_list|)
decl|const
decl_stmt|;
name|SpecParser
modifier|*
name|m_parser
decl_stmt|;
name|mutable
name|QMap
operator|<
name|QString
operator|,
name|int
operator|>
name|m_extensionIds
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CODEGENERATOR_H
end_comment
end_unit
