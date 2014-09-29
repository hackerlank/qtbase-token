begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTMETRICS_H
end_ifndef
begin_define
DECL|macro|QFONTMETRICS_H
define|#
directive|define
name|QFONTMETRICS_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_INCLUDE_COMPAT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextCodec
name|class
name|QTextCodec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontMetrics
block|{
name|public
label|:
name|explicit
name|QFontMetrics
parameter_list|(
specifier|const
name|QFont
modifier|&
parameter_list|)
function_decl|;
name|QFontMetrics
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|,
name|QPaintDevice
operator|*
name|pd
argument_list|)
expr_stmt|;
name|QFontMetrics
argument_list|(
specifier|const
name|QFontMetrics
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QFontMetrics
argument_list|()
expr_stmt|;
name|QFontMetrics
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontMetrics
operator|&
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QFontMetrics
modifier|&
name|operator
init|=
operator|(
name|QFontMetrics
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QFontMetrics
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|int
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|int
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|int
name|height
argument_list|()
specifier|const
expr_stmt|;
name|int
name|leading
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lineSpacing
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minLeftBearing
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minRightBearing
argument_list|()
specifier|const
expr_stmt|;
name|int
name|maxWidth
argument_list|()
specifier|const
expr_stmt|;
name|int
name|xHeight
argument_list|()
specifier|const
expr_stmt|;
name|int
name|averageCharWidth
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|inFont
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|bool
name|inFontUcs4
argument_list|(
name|uint
name|ucs4
argument_list|)
decl|const
decl_stmt|;
name|int
name|leftBearing
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|int
name|rightBearing
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|int
name|width
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|int
name|len
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|int
name|width
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|int
name|len
argument_list|,
name|int
name|flags
argument_list|)
decl|const
decl_stmt|;
name|int
name|width
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|int
name|charWidth
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|boundingRect
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|boundingRect
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|boundingRect
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|,
name|int
name|flags
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|int
name|tabstops
operator|=
literal|0
argument_list|,
name|int
operator|*
name|tabarray
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QRect
name|boundingRect
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|int
name|flags
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|int
name|tabstops
operator|=
literal|0
argument_list|,
name|int
operator|*
name|tabarray
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|boundingRect
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|flags
argument_list|,
name|text
argument_list|,
name|tabstops
argument_list|,
name|tabarray
argument_list|)
return|;
block|}
name|QSize
name|size
argument_list|(
name|int
name|flags
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|tabstops
operator|=
literal|0
argument_list|,
name|int
operator|*
name|tabarray
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|tightBoundingRect
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl|const
decl_stmt|;
name|QString
name|elidedText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|Qt
operator|::
name|TextElideMode
name|mode
argument_list|,
name|int
name|width
argument_list|,
name|int
name|flags
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|underlinePos
argument_list|()
specifier|const
expr_stmt|;
name|int
name|overlinePos
argument_list|()
specifier|const
expr_stmt|;
name|int
name|strikeOutPos
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lineWidth
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFontMetrics
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFontMetrics
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|private
label|:
name|friend
name|class
name|QFontMetricsF
decl_stmt|;
name|friend
name|class
name|QStackTextEngine
decl_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QFontPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QFontMetrics
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontMetricsF
block|{
name|public
label|:
name|explicit
name|QFontMetricsF
parameter_list|(
specifier|const
name|QFont
modifier|&
parameter_list|)
function_decl|;
name|QFontMetricsF
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|,
name|QPaintDevice
operator|*
name|pd
argument_list|)
expr_stmt|;
name|QFontMetricsF
argument_list|(
specifier|const
name|QFontMetrics
operator|&
argument_list|)
expr_stmt|;
name|QFontMetricsF
argument_list|(
specifier|const
name|QFontMetricsF
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QFontMetricsF
argument_list|()
expr_stmt|;
name|QFontMetricsF
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontMetricsF
operator|&
operator|)
decl_stmt|;
name|QFontMetricsF
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontMetrics
operator|&
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QFontMetricsF
modifier|&
name|operator
init|=
operator|(
name|QFontMetricsF
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QFontMetricsF
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|qreal
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|height
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|leading
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|lineSpacing
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|minRightBearing
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|maxWidth
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|xHeight
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|averageCharWidth
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|inFont
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|bool
name|inFontUcs4
argument_list|(
name|uint
name|ucs4
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|leftBearing
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|rightBearing
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|width
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|width
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|boundingRect
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|boundingRect
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|boundingRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
name|int
name|flags
argument_list|,
specifier|const
name|QString
operator|&
name|string
argument_list|,
name|int
name|tabstops
operator|=
literal|0
argument_list|,
name|int
operator|*
name|tabarray
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QSizeF
name|size
argument_list|(
name|int
name|flags
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|tabstops
operator|=
literal|0
argument_list|,
name|int
operator|*
name|tabarray
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|tightBoundingRect
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl|const
decl_stmt|;
name|QString
name|elidedText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|Qt
operator|::
name|TextElideMode
name|mode
argument_list|,
name|qreal
name|width
argument_list|,
name|int
name|flags
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|underlinePos
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|overlinePos
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|strikeOutPos
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|lineWidth
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFontMetricsF
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFontMetricsF
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|private
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QFontPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QFontMetricsF
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTMETRICS_H
end_comment
end_unit
