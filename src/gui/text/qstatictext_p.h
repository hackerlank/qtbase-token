begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATICTEXT_P_H
end_ifndef
begin_define
DECL|macro|QSTATICTEXT_P_H
define|#
directive|define
name|QSTATICTEXT_P_H
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
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
file|"qstatictext.h"
end_include
begin_include
include|#
directive|include
file|<private/qtextureglyphcache_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QStaticTextUserData
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|NoUserData
block|,
name|OpenGLUserData
block|}
enum|;
name|QStaticTextUserData
argument_list|(
argument|Type t
argument_list|)
block|:
name|type
argument_list|(
argument|t
argument_list|)
block|{
name|ref
operator|=
literal|0
expr_stmt|;
block|}
name|virtual
operator|~
name|QStaticTextUserData
argument_list|()
block|{}
name|QAtomicInt
name|ref
expr_stmt|;
name|Type
name|type
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStaticTextItem
block|{
name|public
label|:
name|QStaticTextItem
argument_list|()
operator|:
name|chars
argument_list|(
literal|0
argument_list|)
operator|,
name|numChars
argument_list|(
literal|0
argument_list|)
operator|,
name|useBackendOptimizations
argument_list|(
name|false
argument_list|)
operator|,
name|userDataNeedsUpdate
argument_list|(
literal|0
argument_list|)
operator|,
name|m_fontEngine
argument_list|(
literal|0
argument_list|)
operator|,
name|m_userData
argument_list|(
literal|0
argument_list|)
block|{}
name|QStaticTextItem
argument_list|(
argument|const QStaticTextItem&other
argument_list|)
block|{
name|operator
operator|=
operator|(
name|other
operator|)
block|;     }
name|void
name|operator
operator|=
operator|(
specifier|const
name|QStaticTextItem
operator|&
name|other
operator|)
block|{
name|glyphPositions
operator|=
name|other
operator|.
name|glyphPositions
block|;
name|glyphs
operator|=
name|other
operator|.
name|glyphs
block|;
name|chars
operator|=
name|other
operator|.
name|chars
block|;
name|numGlyphs
operator|=
name|other
operator|.
name|numGlyphs
block|;
name|numChars
operator|=
name|other
operator|.
name|numChars
block|;
name|font
operator|=
name|other
operator|.
name|font
block|;
name|color
operator|=
name|other
operator|.
name|color
block|;
name|useBackendOptimizations
operator|=
name|other
operator|.
name|useBackendOptimizations
block|;
name|userDataNeedsUpdate
operator|=
name|other
operator|.
name|userDataNeedsUpdate
block|;
name|m_fontEngine
operator|=
literal|0
block|;
name|m_userData
operator|=
literal|0
block|;
name|setUserData
argument_list|(
name|other
operator|.
name|userData
argument_list|()
argument_list|)
block|;
name|setFontEngine
argument_list|(
name|other
operator|.
name|fontEngine
argument_list|()
argument_list|)
block|;     }
operator|~
name|QStaticTextItem
argument_list|()
expr_stmt|;
name|void
name|setUserData
parameter_list|(
name|QStaticTextUserData
modifier|*
name|newUserData
parameter_list|)
block|{
if|if
condition|(
name|m_userData
operator|==
name|newUserData
condition|)
return|return;
if|if
condition|(
name|m_userData
operator|!=
literal|0
operator|&&
operator|!
name|m_userData
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|m_userData
decl_stmt|;
name|m_userData
operator|=
name|newUserData
expr_stmt|;
if|if
condition|(
name|m_userData
operator|!=
literal|0
condition|)
name|m_userData
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
name|QStaticTextUserData
operator|*
name|userData
argument_list|()
specifier|const
block|{
return|return
name|m_userData
return|;
block|}
name|void
name|setFontEngine
parameter_list|(
name|QFontEngine
modifier|*
name|fe
parameter_list|)
function_decl|;
name|QFontEngine
operator|*
name|fontEngine
argument_list|()
specifier|const
block|{
return|return
name|m_fontEngine
return|;
block|}
union|union
block|{
name|QFixedPoint
modifier|*
name|glyphPositions
decl_stmt|;
comment|// 8 bytes per glyph
name|int
name|positionOffset
decl_stmt|;
block|}
union|;
union|union
block|{
name|glyph_t
modifier|*
name|glyphs
decl_stmt|;
comment|// 4 bytes per glyph
name|int
name|glyphOffset
decl_stmt|;
block|}
union|;
union|union
block|{
name|QChar
modifier|*
name|chars
decl_stmt|;
comment|// 2 bytes per glyph
name|int
name|charOffset
decl_stmt|;
block|}
union|;
comment|// =================
comment|// 14 bytes per glyph
comment|// 12 bytes for pointers
name|int
name|numGlyphs
decl_stmt|;
comment|// 4 bytes per item
name|int
name|numChars
decl_stmt|;
comment|// 4 bytes per item
name|QFont
name|font
decl_stmt|;
comment|// 8 bytes per item
name|QColor
name|color
decl_stmt|;
comment|// 10 bytes per item
name|char
name|useBackendOptimizations
range|:
literal|1
decl_stmt|;
comment|// 1 byte per item
name|char
name|userDataNeedsUpdate
range|:
literal|1
decl_stmt|;
comment|//
comment|// ================
comment|// 51 bytes per item
name|private
label|:
comment|// Needs special handling in setters, so private to avoid abuse
name|QFontEngine
modifier|*
name|m_fontEngine
decl_stmt|;
comment|// 4 bytes per item
name|QStaticTextUserData
modifier|*
name|m_userData
decl_stmt|;
comment|// 8 bytes per item
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QStaticText
name|class
name|QStaticText
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QStaticTextPrivate
block|{
name|public
label|:
name|QStaticTextPrivate
argument_list|()
expr_stmt|;
name|QStaticTextPrivate
argument_list|(
specifier|const
name|QStaticTextPrivate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QStaticTextPrivate
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|paintText
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|,
name|QPainter
modifier|*
name|p
parameter_list|)
function_decl|;
name|void
name|invalidate
parameter_list|()
block|{
name|needsRelayout
operator|=
name|true
expr_stmt|;
block|}
name|QAtomicInt
name|ref
decl_stmt|;
comment|// 4 bytes per text
name|QString
name|text
decl_stmt|;
comment|// 4 bytes per text
name|QFont
name|font
decl_stmt|;
comment|// 8 bytes per text
name|qreal
name|textWidth
decl_stmt|;
comment|// 8 bytes per text
name|QSizeF
name|actualSize
decl_stmt|;
comment|// 16 bytes per text
name|QPointF
name|position
decl_stmt|;
comment|// 16 bytes per text
name|QTransform
name|matrix
decl_stmt|;
comment|// 80 bytes per text
name|QStaticTextItem
modifier|*
name|items
decl_stmt|;
comment|// 4 bytes per text
name|int
name|itemCount
decl_stmt|;
comment|// 4 bytes per text
name|glyph_t
modifier|*
name|glyphPool
decl_stmt|;
comment|// 4 bytes per text
name|QFixedPoint
modifier|*
name|positionPool
decl_stmt|;
comment|// 4 bytes per text
name|QChar
modifier|*
name|charPool
decl_stmt|;
comment|// 4 bytes per text
name|QTextOption
name|textOption
decl_stmt|;
comment|// 28 bytes per text
name|unsigned
name|char
name|needsRelayout
range|:
literal|1
decl_stmt|;
comment|// 1 byte per text
name|unsigned
name|char
name|useBackendOptimizations
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
name|textFormat
range|:
literal|2
decl_stmt|;
name|unsigned
name|char
name|untransformedCoordinates
range|:
literal|1
decl_stmt|;
comment|// ================
comment|// 195 bytes per text
specifier|static
name|QStaticTextPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QStaticText
modifier|*
name|q
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTATICTEXT_P_H
end_comment
end_unit
