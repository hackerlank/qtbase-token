begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GENERATOR_H
end_ifndef
begin_define
DECL|macro|GENERATOR_H
define|#
directive|define
name|GENERATOR_H
end_define
begin_include
include|#
directive|include
file|"moc.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Generator
block|{
name|FILE
modifier|*
name|out
decl_stmt|;
name|ClassDef
modifier|*
name|cdef
decl_stmt|;
name|QVector
operator|<
name|uint
operator|>
name|meta_data
expr_stmt|;
name|public
label|:
name|Generator
argument_list|(
name|ClassDef
operator|*
name|classDef
argument_list|,
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|metaTypes
argument_list|,
name|FILE
operator|*
name|outfile
operator|=
literal|0
argument_list|)
expr_stmt|;
name|void
name|generateCode
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|registerClassInfoStrings
parameter_list|()
function_decl|;
name|void
name|generateClassInfos
parameter_list|()
function_decl|;
name|void
name|registerFunctionStrings
argument_list|(
specifier|const
name|QList
operator|<
name|FunctionDef
operator|>
operator|&
name|list
argument_list|)
decl_stmt|;
name|void
name|generateFunctions
argument_list|(
specifier|const
name|QList
operator|<
name|FunctionDef
operator|>
operator|&
name|list
argument_list|,
specifier|const
name|char
operator|*
name|functype
argument_list|,
name|int
name|type
argument_list|)
decl_stmt|;
name|void
name|generateFunctionRevisions
argument_list|(
specifier|const
name|QList
operator|<
name|FunctionDef
operator|>
operator|&
name|list
argument_list|,
specifier|const
name|char
operator|*
name|functype
argument_list|)
decl_stmt|;
name|void
name|registerEnumStrings
parameter_list|()
function_decl|;
name|void
name|generateEnums
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|registerPropertyStrings
parameter_list|()
function_decl|;
name|void
name|generateProperties
parameter_list|()
function_decl|;
name|void
name|generateMetacall
parameter_list|()
function_decl|;
name|void
name|generateStaticMetacall
parameter_list|()
function_decl|;
name|void
name|generateSignal
parameter_list|(
name|FunctionDef
modifier|*
name|def
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|generatePluginMetaData
parameter_list|()
function_decl|;
name|void
name|strreg
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
comment|// registers a string
name|int
name|stridx
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
comment|// returns a string's id
name|QList
operator|<
name|QByteArray
operator|>
name|strings
expr_stmt|;
name|QByteArray
name|purestSuperClass
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|metaTypes
expr_stmt|;
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
comment|// GENERATOR_H
end_comment
end_unit
