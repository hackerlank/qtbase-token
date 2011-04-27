begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MINGW_MAKE_H
end_ifndef
begin_define
DECL|macro|MINGW_MAKE_H
define|#
directive|define
name|MINGW_MAKE_H
end_define
begin_include
include|#
directive|include
file|"winmakefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|MingwMakefileGenerator
range|:
name|public
name|Win32MakefileGenerator
block|{
name|public
operator|:
name|MingwMakefileGenerator
argument_list|()
block|;
operator|~
name|MingwMakefileGenerator
argument_list|()
block|;
name|protected
operator|:
name|QString
name|escapeDependencyPath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|QString
name|getLibTarget
argument_list|()
block|;
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|private
operator|:
name|bool
name|isWindowsShell
argument_list|()
specifier|const
block|;
name|void
name|writeMingwParts
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|writeIncPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeLibsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeLibDirPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeObjectsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeBuildRulesPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeRcFilePart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|processPrlVariable
argument_list|(
specifier|const
name|QString
operator|&
name|var
argument_list|,
specifier|const
name|QStringList
operator|&
name|l
argument_list|)
block|;
name|QStringList
operator|&
name|findDependencies
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|QString
name|preCompHeaderOut
block|;
name|virtual
name|bool
name|findLibraries
argument_list|()
block|;
name|bool
name|findLibraries
argument_list|(
specifier|const
name|QString
operator|&
name|where
argument_list|)
block|;
name|void
name|fixTargetExt
argument_list|()
block|;
name|bool
name|init_flag
block|;
name|QString
name|objectsLinkLine
block|;
name|QString
name|quote
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~MingwMakefileGenerator
specifier|inline
name|MingwMakefileGenerator
operator|::
operator|~
name|MingwMakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MINGW_MAKE_H
end_comment
end_unit
