begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qglyphrun.h"
end_include
begin_include
include|#
directive|include
file|"qglyphrun_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGlyphRun     \brief The QGlyphRun class provides direct access to the internal glyphs in a font.     \since 4.8      \ingroup text     \mainclass      When Qt displays a string of text encoded in Unicode, it will first convert the Unicode points     into a list of glyph indexes and a list of positions based on one or more fonts. The Unicode     representation of the text and the QFont object will in this case serve as a convenient     abstraction that hides the details of what actually takes place when displaying the text     on-screen. For instance, by the time the text actually reaches the screen, it may be represented     by a set of fonts in addition to the one specified by the user, e.g. in case the originally     selected font did not support all the writing systems contained in the text.      Under certain circumstances, it can be useful as an application developer to have more low-level     control over which glyphs in a specific font are drawn to the screen. This could for instance     be the case in applications that use an external font engine and text shaper together with Qt.     QGlyphRun provides an interface to the raw data needed to get text on the screen. It     contains a list of glyph indexes, a position for each glyph and a font.      It is the user's responsibility to ensure that the selected font actually contains the     provided glyph indexes.      QTextLayout::glyphRuns() or QTextFragment::glyphRuns() can be used to convert unicode encoded     text into a list of QGlyphRun objects, and QPainter::drawGlyphRun() can be used to draw the     glyphs.      \note Please note that QRawFont is considered local to the thread in which it is constructed.     This in turn means that a new QRawFont will have to be created and set on the QGlyphRun if it is     moved to a different thread. If the QGlyphRun contains a reference to a QRawFont from a different     thread than the current, it will not be possible to draw the glyphs using a QPainter, as the     QRawFont is considered invalid and inaccessible in this case. */
end_comment
begin_comment
comment|/*!     Constructs an empty QGlyphRun object. */
end_comment
begin_constructor
DECL|function|QGlyphRun
name|QGlyphRun
operator|::
name|QGlyphRun
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QGlyphRunPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QGlyphRun object which is a copy of \a other. */
end_comment
begin_constructor
DECL|function|QGlyphRun
name|QGlyphRun
operator|::
name|QGlyphRun
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QGlyphRun. */
end_comment
begin_destructor
DECL|function|~QGlyphRun
name|QGlyphRun
operator|::
name|~
name|QGlyphRun
parameter_list|()
block|{
comment|// Required for QExplicitlySharedDataPointer
block|}
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QGlyphRun
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|!=
literal|1
condition|)
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Assigns \a other to this QGlyphRun object. */
end_comment
begin_function
DECL|function|operator =
name|QGlyphRun
modifier|&
name|QGlyphRun
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Compares \a other to this QGlyphRun object. Returns true if the list of glyph indexes,     the list of positions and the font are all equal, otherwise returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QGlyphRun
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
name|other
operator|.
name|d
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|d
operator|->
name|glyphIndexDataSize
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphIndexDataSize
operator|)
operator|||
operator|(
name|d
operator|->
name|glyphPositionDataSize
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphPositionDataSize
operator|)
condition|)
block|{
return|return
literal|false
return|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qMax
argument_list|(
name|d
operator|->
name|glyphIndexDataSize
argument_list|,
name|d
operator|->
name|glyphPositionDataSize
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|<
name|d
operator|->
name|glyphIndexDataSize
operator|&&
name|d
operator|->
name|glyphIndexData
index|[
name|i
index|]
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphIndexData
index|[
name|i
index|]
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|i
operator|<
name|d
operator|->
name|glyphPositionDataSize
operator|&&
name|d
operator|->
name|glyphPositionData
index|[
name|i
index|]
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphPositionData
index|[
name|i
index|]
condition|)
return|return
literal|false
return|;
block|}
return|return
operator|(
name|d
operator|->
name|overline
operator|==
name|other
operator|.
name|d
operator|->
name|overline
operator|&&
name|d
operator|->
name|underline
operator|==
name|other
operator|.
name|d
operator|->
name|underline
operator|&&
name|d
operator|->
name|strikeOut
operator|==
name|other
operator|.
name|d
operator|->
name|strikeOut
operator|&&
name|d
operator|->
name|rawFont
operator|==
name|other
operator|.
name|d
operator|->
name|rawFont
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Compares \a other to this QGlyphRun object. Returns true if any of the list of glyph     indexes, the list of positions or the font are different, otherwise returns false. */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|QGlyphRun
operator|::
name|operator
name|!=
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the font selected for this QGlyphRun object.      \sa setRawFont() */
end_comment
begin_function
DECL|function|rawFont
name|QRawFont
name|QGlyphRun
operator|::
name|rawFont
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|rawFont
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the font in which to look up the glyph indexes to the \a rawFont     specified.      \sa rawFont(), setGlyphIndexes() */
end_comment
begin_function
DECL|function|setRawFont
name|void
name|QGlyphRun
operator|::
name|setRawFont
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|rawFont
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|rawFont
operator|=
name|rawFont
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the glyph indexes for this QGlyphRun object.      \sa setGlyphIndexes(), setPositions() */
end_comment
begin_function
DECL|function|glyphIndexes
name|QVector
argument_list|<
name|quint32
argument_list|>
name|QGlyphRun
operator|::
name|glyphIndexes
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|glyphIndexes
operator|.
name|constData
argument_list|()
operator|==
name|d
operator|->
name|glyphIndexData
condition|)
block|{
return|return
name|d
operator|->
name|glyphIndexes
return|;
block|}
else|else
block|{
name|QVector
argument_list|<
name|quint32
argument_list|>
name|indexes
argument_list|(
name|d
operator|->
name|glyphIndexDataSize
argument_list|)
decl_stmt|;
name|qMemCopy
argument_list|(
name|indexes
operator|.
name|data
argument_list|()
argument_list|,
name|d
operator|->
name|glyphIndexData
argument_list|,
name|d
operator|->
name|glyphIndexDataSize
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|indexes
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Set the glyph indexes for this QGlyphRun object to \a glyphIndexes. The glyph indexes must     be valid for the selected font. */
end_comment
begin_function
DECL|function|setGlyphIndexes
name|void
name|QGlyphRun
operator|::
name|setGlyphIndexes
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|glyphIndexes
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexes
operator|=
name|glyphIndexes
expr_stmt|;
comment|// Keep a reference to the QVector to avoid copying
name|d
operator|->
name|glyphIndexData
operator|=
name|glyphIndexes
operator|.
name|constData
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexDataSize
operator|=
name|glyphIndexes
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the position of the edge of the baseline for each glyph in this set of glyph indexes. */
end_comment
begin_function
DECL|function|positions
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|QGlyphRun
operator|::
name|positions
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|glyphPositions
operator|.
name|constData
argument_list|()
operator|==
name|d
operator|->
name|glyphPositionData
condition|)
block|{
return|return
name|d
operator|->
name|glyphPositions
return|;
block|}
else|else
block|{
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|glyphPositions
argument_list|(
name|d
operator|->
name|glyphPositionDataSize
argument_list|)
decl_stmt|;
name|qMemCopy
argument_list|(
name|glyphPositions
operator|.
name|data
argument_list|()
argument_list|,
name|d
operator|->
name|glyphPositionData
argument_list|,
name|d
operator|->
name|glyphPositionDataSize
operator|*
sizeof|sizeof
argument_list|(
name|QPointF
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|glyphPositions
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the positions of the edge of the baseline for each glyph in this set of glyph indexes to     \a positions. */
end_comment
begin_function
DECL|function|setPositions
name|void
name|QGlyphRun
operator|::
name|setPositions
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|QPointF
argument_list|>
modifier|&
name|positions
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositions
operator|=
name|positions
expr_stmt|;
comment|// Keep a reference to the vector to avoid copying
name|d
operator|->
name|glyphPositionData
operator|=
name|positions
operator|.
name|constData
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositionDataSize
operator|=
name|positions
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Clears all data in the QGlyphRun object. */
end_comment
begin_function
DECL|function|clear
name|void
name|QGlyphRun
operator|::
name|clear
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|rawFont
operator|=
name|QRawFont
argument_list|()
expr_stmt|;
name|d
operator|->
name|strikeOut
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|overline
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|underline
operator|=
literal|false
expr_stmt|;
name|setPositions
argument_list|(
name|QVector
argument_list|<
name|QPointF
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|setGlyphIndexes
argument_list|(
name|QVector
argument_list|<
name|quint32
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the glyph indexes and positions of this QGlyphRun to use the first \a size     elements in the arrays \a glyphIndexArray and \a glyphPositionArray. The data is     \e not copied. The caller must guarantee that the arrays are not deleted as long     as this QGlyphRun and any copies of it exists.      \sa setGlyphIndexes(), setPositions() */
end_comment
begin_function
DECL|function|setRawData
name|void
name|QGlyphRun
operator|::
name|setRawData
parameter_list|(
specifier|const
name|quint32
modifier|*
name|glyphIndexArray
parameter_list|,
specifier|const
name|QPointF
modifier|*
name|glyphPositionArray
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexData
operator|=
name|glyphIndexArray
expr_stmt|;
name|d
operator|->
name|glyphPositionData
operator|=
name|glyphPositionArray
expr_stmt|;
name|d
operator|->
name|glyphIndexDataSize
operator|=
name|d
operator|->
name|glyphPositionDataSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with an overline decoration.     \sa setOverline() */
end_comment
begin_function
DECL|function|overline
name|bool
name|QGlyphRun
operator|::
name|overline
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|overline
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an overline decoration if \a overline is true.   Otherwise the QGlyphRun should be painted with no overline decoration.    \sa overline() */
end_comment
begin_function
DECL|function|setOverline
name|void
name|QGlyphRun
operator|::
name|setOverline
parameter_list|(
name|bool
name|overline
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|overline
operator|=
name|overline
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with an underline decoration.     \sa setUnderline() */
end_comment
begin_function
DECL|function|underline
name|bool
name|QGlyphRun
operator|::
name|underline
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|underline
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an underline decoration if \a underline is   true. Otherwise the QGlyphRun should be painted with no underline decoration.    \sa underline() */
end_comment
begin_function
DECL|function|setUnderline
name|void
name|QGlyphRun
operator|::
name|setUnderline
parameter_list|(
name|bool
name|underline
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|underline
operator|=
name|underline
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with a strike out decoration.     \sa setStrikeOut() */
end_comment
begin_function
DECL|function|strikeOut
name|bool
name|QGlyphRun
operator|::
name|strikeOut
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|strikeOut
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an strike out decoration if \a strikeOut is   true. Otherwise the QGlyphRun should be painted with no strike out decoration.    \sa strikeOut() */
end_comment
begin_function
DECL|function|setStrikeOut
name|void
name|QGlyphRun
operator|::
name|setStrikeOut
parameter_list|(
name|bool
name|strikeOut
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|strikeOut
operator|=
name|strikeOut
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the smallest rectangle that contains all glyphs in this QGlyphRun.    \since 5.0 */
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|QGlyphRun
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
name|qreal
name|minX
decl_stmt|,
name|minY
decl_stmt|,
name|maxX
decl_stmt|,
name|maxY
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|qMin
argument_list|(
name|d
operator|->
name|glyphPositions
operator|.
name|size
argument_list|()
argument_list|,
name|d
operator|->
name|glyphIndexes
operator|.
name|size
argument_list|()
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|QRectF
name|glyphRect
init|=
name|d
operator|->
name|rawFont
operator|.
name|boundingRect
argument_list|(
name|d
operator|->
name|glyphIndexes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|glyphRect
operator|.
name|translate
argument_list|(
name|d
operator|->
name|glyphPositions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
name|minX
operator|=
name|glyphRect
operator|.
name|left
argument_list|()
expr_stmt|;
name|minY
operator|=
name|glyphRect
operator|.
name|top
argument_list|()
expr_stmt|;
name|maxX
operator|=
name|glyphRect
operator|.
name|right
argument_list|()
expr_stmt|;
name|maxY
operator|=
name|glyphRect
operator|.
name|bottom
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|minX
operator|=
name|qMin
argument_list|(
name|glyphRect
operator|.
name|left
argument_list|()
argument_list|,
name|minX
argument_list|)
expr_stmt|;
name|minY
operator|=
name|qMin
argument_list|(
name|glyphRect
operator|.
name|top
argument_list|()
argument_list|,
name|minY
argument_list|)
expr_stmt|;
name|maxX
operator|=
name|qMax
argument_list|(
name|glyphRect
operator|.
name|right
argument_list|()
argument_list|,
name|maxX
argument_list|)
expr_stmt|;
name|maxY
operator|=
name|qMax
argument_list|(
name|glyphRect
operator|.
name|bottom
argument_list|()
argument_list|,
name|maxY
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|(
name|minX
argument_list|,
name|minY
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|maxX
argument_list|,
name|maxY
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_RAWFONT
end_comment
end_unit
