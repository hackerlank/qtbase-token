begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTXUNITSTREAMER_H
end_ifndef
begin_define
DECL|macro|QTESTXUNITSTREAMER_H
define|#
directive|define
name|QTESTXUNITSTREAMER_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtestbasicstreamer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Test
argument_list|)
name|class
name|QTestLogger
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTestXunitStreamer
range|:
name|public
name|QTestBasicStreamer
block|{
name|public
operator|:
name|QTestXunitStreamer
argument_list|()
block|;
operator|~
name|QTestXunitStreamer
argument_list|()
block|;
name|void
name|formatStart
argument_list|(
argument|const QTestElement *element
argument_list|,
argument|QTestCharBuffer *formatted
argument_list|)
specifier|const
block|;
name|void
name|formatEnd
argument_list|(
argument|const QTestElement *element
argument_list|,
argument|QTestCharBuffer *formatted
argument_list|)
specifier|const
block|;
name|void
name|formatAfterAttributes
argument_list|(
argument|const QTestElement *element
argument_list|,
argument|QTestCharBuffer *formatted
argument_list|)
specifier|const
block|;
name|void
name|formatAttributes
argument_list|(
argument|const QTestElement *element
argument_list|,
argument|const QTestElementAttribute *attribute
argument_list|,
argument|QTestCharBuffer *formatted
argument_list|)
specifier|const
block|;
name|void
name|output
argument_list|(
argument|QTestElement *element
argument_list|)
specifier|const
block|;
name|void
name|outputElements
argument_list|(
argument|QTestElement *element
argument_list|,
argument|bool isChildElement = false
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|displayXunitXmlHeader
argument_list|()
specifier|const
block|;
specifier|static
name|void
name|indentForElement
argument_list|(
argument|const QTestElement* element
argument_list|,
argument|char* buf
argument_list|,
argument|int size
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
