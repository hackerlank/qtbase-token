begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UNIXMAKE_H
end_ifndef
begin_define
DECL|macro|UNIXMAKE_H
define|#
directive|define
name|UNIXMAKE_H
end_define
begin_include
include|#
directive|include
file|"makefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|UnixMakefileGenerator
range|:
name|public
name|MakefileGenerator
block|{
name|bool
name|include_deps
block|;
name|QString
name|libtoolFileName
argument_list|(
argument|bool fixify=true
argument_list|)
block|;
name|void
name|writeLibtoolFile
argument_list|()
block|;
comment|// for libtool
name|void
name|writePrlFile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|public
operator|:
name|UnixMakefileGenerator
argument_list|()
block|;
operator|~
name|UnixMakefileGenerator
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|doPrecompiledHeaders
argument_list|()
specifier|const
block|{
return|return
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"precompile_header"
argument_list|)
return|;
block|}
name|virtual
name|bool
name|doDepends
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Option
operator|::
name|mkfile
operator|::
name|do_stub_makefile
operator|&&
name|MakefileGenerator
operator|::
name|doDepends
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// MinGW x-compiling for QNX
name|virtual
name|QString
name|installRoot
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|virtual
name|QString
name|defaultInstall
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|ProString
name|fixLibFlag
argument_list|(
specifier|const
name|ProString
operator|&
name|lib
argument_list|)
block|;
name|virtual
name|bool
name|findLibraries
argument_list|(
argument|bool linkPrl
argument_list|,
argument|bool mergeLflags
argument_list|)
block|;
name|virtual
name|QString
name|escapeFilePath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|ProString
name|escapeFilePath
argument_list|(
argument|const ProString&path
argument_list|)
specifier|const
block|{
return|return
name|MakefileGenerator
operator|::
name|escapeFilePath
argument_list|(
name|path
argument_list|)
return|;
block|}
name|virtual
name|QStringList
operator|&
name|findDependencies
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|init
argument_list|()
block|;
name|virtual
name|void
name|writeDefaultVariables
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeSubTargets
argument_list|(
argument|QTextStream&t
argument_list|,
argument|QList<SubTarget*> subtargets
argument_list|,
argument|int flags
argument_list|)
block|;
name|void
name|writeMakeParts
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|private
operator|:
name|void
name|init2
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~UnixMakefileGenerator
specifier|inline
name|UnixMakefileGenerator
operator|::
operator|~
name|UnixMakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// UNIXMAKE_H
end_comment
end_unit
