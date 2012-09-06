begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PROJECTGENERATOR_H
end_ifndef
begin_define
DECL|macro|PROJECTGENERATOR_H
define|#
directive|define
name|PROJECTGENERATOR_H
end_define
begin_include
include|#
directive|include
file|"makefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|ProjectGenerator
range|:
name|public
name|MakefileGenerator
block|{
name|bool
name|init_flag
block|;
name|bool
name|addFile
argument_list|(
name|QString
argument_list|)
block|;
name|bool
name|addConfig
argument_list|(
argument|const QString&
argument_list|,
argument|bool add=true
argument_list|)
block|;
name|QString
name|getWritableVar
argument_list|(
argument|const char *
argument_list|,
argument|bool fixPath=true
argument_list|)
block|;
name|QString
name|fixPathToQmake
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|init
argument_list|()
block|;
name|virtual
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|public
operator|:
name|ProjectGenerator
argument_list|()
block|;
operator|~
name|ProjectGenerator
argument_list|()
block|;
name|virtual
name|bool
name|supportsMetaBuild
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|openOutput
argument_list|(
argument|QFile&
argument_list|,
argument|const QString&
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~ProjectGenerator
specifier|inline
name|ProjectGenerator
operator|::
operator|~
name|ProjectGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PROJECTGENERATOR_H
end_comment
end_unit
