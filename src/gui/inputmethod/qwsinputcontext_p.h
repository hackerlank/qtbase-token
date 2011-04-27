begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWSINPUTCONTEXT_P_H
end_ifndef
begin_define
DECL|macro|QWSINPUTCONTEXT_P_H
define|#
directive|define
name|QWSINPUTCONTEXT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtGui/qinputcontext.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWSIMEvent
name|class
name|QWSIMEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWSIMQueryEvent
name|class
name|QWSIMQueryEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWSIMInitEvent
name|class
name|QWSIMInitEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWSInputContext
range|:
name|public
name|QInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QWSInputContext
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWSInputContext
argument_list|()
block|{}
name|QString
name|identifierName
argument_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|QString
name|language
argument_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|void
name|reset
argument_list|()
block|;
name|void
name|update
argument_list|()
block|;
name|void
name|mouseHandler
argument_list|(
argument|int x
argument_list|,
argument|QMouseEvent *event
argument_list|)
block|;
name|void
name|setFocusWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|widgetDestroyed
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|bool
name|isComposing
argument_list|()
specifier|const
block|;
specifier|static
name|QWidget
operator|*
name|activeWidget
argument_list|()
block|;
specifier|static
name|bool
name|translateIMEvent
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QWSIMEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|bool
name|translateIMQueryEvent
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QWSIMQueryEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|bool
name|translateIMInitEvent
argument_list|(
specifier|const
name|QWSIMInitEvent
operator|*
name|e
argument_list|)
block|;
specifier|static
name|void
name|updateImeStatus
argument_list|(
argument|QWidget *w
argument_list|,
argument|bool hasFocus
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
begin_comment
comment|// QT_NO_QWS_INPUTMETHODS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWSINPUTCONTEXT_P_H
end_comment
end_unit
