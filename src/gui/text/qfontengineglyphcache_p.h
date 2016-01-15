begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINEGLYPHCACHE_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINEGLYPHCACHE_P_H
define|#
directive|define
name|QFONTENGINEGLYPHCACHE_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|"private/qfont_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfontengine_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QFontEngineGlyphCache
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QFontEngineGlyphCache
argument_list|(
argument|QFontEngine::GlyphFormat format
argument_list|,
argument|const QTransform&matrix
argument_list|)
operator|:
name|m_format
argument_list|(
name|format
argument_list|)
block|,
name|m_transform
argument_list|(
argument|matrix
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_format
operator|!=
name|QFontEngine
operator|::
name|Format_None
argument_list|)
block|;     }
name|virtual
operator|~
name|QFontEngineGlyphCache
argument_list|()
block|;
name|QFontEngine
operator|::
name|GlyphFormat
name|glyphFormat
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
specifier|const
name|QTransform
operator|&
name|transform
argument_list|()
specifier|const
block|{
return|return
name|m_transform
return|;
block|}
name|QFontEngine
operator|::
name|GlyphFormat
name|m_format
block|;
name|QTransform
name|m_transform
block|; }
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|GlyphPointerHash
typedef|typedef
name|QHash
operator|<
name|void
operator|*
operator|,
name|QList
operator|<
name|QFontEngineGlyphCache
operator|*
operator|>
expr|>
name|GlyphPointerHash
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|GlyphIntHash
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QList
operator|<
name|QFontEngineGlyphCache
operator|*
operator|>
expr|>
name|GlyphIntHash
expr_stmt|;
end_typedef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
