begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   jscodemarker.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|JSCODEMARKER_H
end_ifndef
begin_define
DECL|macro|JSCODEMARKER_H
define|#
directive|define
name|JSCODEMARKER_H
end_define
begin_include
include|#
directive|include
file|"qmlcodemarker.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|JsCodeMarker
range|:
name|public
name|QmlCodeMarker
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::JsCodeMarker
argument_list|)
name|public
operator|:
name|JsCodeMarker
argument_list|()
block|;
operator|~
name|JsCodeMarker
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
