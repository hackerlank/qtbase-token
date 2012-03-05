begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   qmlcodemarker.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMLCODEMARKER_H
end_ifndef
begin_define
DECL|macro|QMLCODEMARKER_H
define|#
directive|define
name|QMLCODEMARKER_H
end_define
begin_include
include|#
directive|include
file|"qqmljsastfwd_p.h"
end_include
begin_include
include|#
directive|include
file|"cppcodemarker.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QmlCodeMarker
range|:
name|public
name|CppCodeMarker
block|{
name|public
operator|:
name|QmlCodeMarker
argument_list|()
block|;
operator|~
name|QmlCodeMarker
argument_list|()
block|;
name|virtual
name|bool
name|recognizeCode
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|)
block|;
name|virtual
name|bool
name|recognizeExtension
argument_list|(
specifier|const
name|QString
operator|&
name|ext
argument_list|)
block|;
name|virtual
name|bool
name|recognizeLanguage
argument_list|(
specifier|const
name|QString
operator|&
name|language
argument_list|)
block|;
name|virtual
name|Atom
operator|::
name|Type
name|atomType
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|plainName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|virtual
name|QString
name|plainFullName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|virtual
name|QString
name|markedUpCode
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Location
operator|&
name|location
argument_list|)
block|;
name|virtual
name|QString
name|markedUpName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|virtual
name|QString
name|markedUpFullName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|virtual
name|QString
name|markedUpIncludes
argument_list|(
specifier|const
name|QStringList
operator|&
name|includes
argument_list|)
block|;
name|virtual
name|QString
name|functionBeginRegExp
argument_list|(
specifier|const
name|QString
operator|&
name|funcName
argument_list|)
block|;
name|virtual
name|QString
name|functionEndRegExp
argument_list|(
specifier|const
name|QString
operator|&
name|funcName
argument_list|)
block|;
comment|/* Copied from src/declarative/qml/qdeclarativescriptparser.cpp */
name|QList
operator|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
operator|>
name|extractPragmas
argument_list|(
name|QString
operator|&
name|script
argument_list|)
block|;
name|private
operator|:
name|QString
name|addMarkUp
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Location
operator|&
name|location
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
