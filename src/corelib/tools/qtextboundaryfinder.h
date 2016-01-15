begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTBOUNDARYFINDER_H
end_ifndef
begin_define
DECL|macro|QTEXTBOUNDARYFINDER_H
define|#
directive|define
name|QTEXTBOUNDARYFINDER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qchar.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextBoundaryFinderPrivate
name|class
name|QTextBoundaryFinderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTextBoundaryFinder
block|{
name|public
label|:
name|QTextBoundaryFinder
argument_list|()
expr_stmt|;
name|QTextBoundaryFinder
argument_list|(
specifier|const
name|QTextBoundaryFinder
operator|&
name|other
argument_list|)
expr_stmt|;
name|QTextBoundaryFinder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTextBoundaryFinder
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QTextBoundaryFinder
argument_list|()
expr_stmt|;
enum|enum
name|BoundaryType
block|{
name|Grapheme
block|,
name|Word
block|,
name|Sentence
block|,
name|Line
block|}
enum|;
enum|enum
name|BoundaryReason
block|{
name|NotAtBoundary
init|=
literal|0
block|,
name|BreakOpportunity
init|=
literal|0x1f
block|,
name|StartOfItem
init|=
literal|0x20
block|,
name|EndOfItem
init|=
literal|0x40
block|,
name|MandatoryBreak
init|=
literal|0x80
block|,
name|SoftHyphen
init|=
literal|0x100
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|BoundaryReasons
argument_list|,
argument|BoundaryReason
argument_list|)
name|QTextBoundaryFinder
argument_list|(
argument|BoundaryType type
argument_list|,
argument|const QString&string
argument_list|)
empty_stmt|;
name|QTextBoundaryFinder
argument_list|(
argument|BoundaryType type
argument_list|,
argument|const QChar *chars
argument_list|,
argument|int length
argument_list|,
argument|unsigned char *buffer = Q_NULLPTR
argument_list|,
argument|int bufferSize =
literal|0
argument_list|)
empty_stmt|;
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|d
return|;
block|}
specifier|inline
name|BoundaryType
name|type
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
name|QString
name|string
argument_list|()
specifier|const
expr_stmt|;
name|void
name|toStart
parameter_list|()
function_decl|;
name|void
name|toEnd
parameter_list|()
function_decl|;
name|int
name|position
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPosition
parameter_list|(
name|int
name|position
parameter_list|)
function_decl|;
name|int
name|toNextBoundary
parameter_list|()
function_decl|;
name|int
name|toPreviousBoundary
parameter_list|()
function_decl|;
name|bool
name|isAtBoundary
argument_list|()
specifier|const
expr_stmt|;
name|BoundaryReasons
name|boundaryReasons
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|BoundaryType
name|t
decl_stmt|;
name|QString
name|s
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|chars
decl_stmt|;
name|int
name|length
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|uint
name|freePrivate
range|:
literal|1
decl_stmt|;
name|uint
name|unused
range|:
literal|31
decl_stmt|;
name|QTextBoundaryFinderPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextBoundaryFinder::BoundaryReasons
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
