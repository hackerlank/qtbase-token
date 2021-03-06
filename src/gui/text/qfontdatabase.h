begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTDATABASE_H
end_ifndef
begin_define
DECL|macro|QFONTDATABASE_H
define|#
directive|define
name|QFONTDATABASE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_struct_decl
struct_decl|struct
name|QFontDef
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontDatabasePrivate
name|class
name|QFontDatabasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontDatabase
block|{
name|Q_GADGET
name|public
range|:
comment|// do not re-order or delete entries from this enum without updating the
comment|// QPF2 format and makeqpf!!
range|enum
name|WritingSystem
block|{
name|Any
block|,
name|Latin
block|,
name|Greek
block|,
name|Cyrillic
block|,
name|Armenian
block|,
name|Hebrew
block|,
name|Arabic
block|,
name|Syriac
block|,
name|Thaana
block|,
name|Devanagari
block|,
name|Bengali
block|,
name|Gurmukhi
block|,
name|Gujarati
block|,
name|Oriya
block|,
name|Tamil
block|,
name|Telugu
block|,
name|Kannada
block|,
name|Malayalam
block|,
name|Sinhala
block|,
name|Thai
block|,
name|Lao
block|,
name|Tibetan
block|,
name|Myanmar
block|,
name|Georgian
block|,
name|Khmer
block|,
name|SimplifiedChinese
block|,
name|TraditionalChinese
block|,
name|Japanese
block|,
name|Korean
block|,
name|Vietnamese
block|,
name|Symbol
block|,
name|Other
operator|=
name|Symbol
block|,
name|Ogham
block|,
name|Runic
block|,
name|Nko
block|,
name|WritingSystemsCount
block|}
decl_stmt|;
name|Q_ENUM
argument_list|(
name|WritingSystem
argument_list|)
expr|enum
name|SystemFont
block|{
name|GeneralFont
block|,
name|FixedFont
block|,
name|TitleFont
block|,
name|SmallestReadableFont
block|}
expr_stmt|;
name|Q_ENUM
argument_list|(
argument|SystemFont
argument_list|)
specifier|static
name|QList
operator|<
name|int
operator|>
name|standardSizes
argument_list|()
expr_stmt|;
name|QFontDatabase
argument_list|()
expr_stmt|;
name|QList
operator|<
name|WritingSystem
operator|>
name|writingSystems
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|WritingSystem
operator|>
name|writingSystems
argument_list|(
argument|const QString&family
argument_list|)
specifier|const
expr_stmt|;
name|QStringList
name|families
argument_list|(
name|WritingSystem
name|writingSystem
operator|=
name|Any
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|styles
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|int
operator|>
name|pointSizes
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|smoothSizes
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
argument_list|)
expr_stmt|;
name|QString
name|styleString
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
name|QString
name|styleString
parameter_list|(
specifier|const
name|QFontInfo
modifier|&
name|fontInfo
parameter_list|)
function_decl|;
name|QFont
name|font
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
argument_list|,
name|int
name|pointSize
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isBitmapScalable
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isSmoothlyScalable
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isScalable
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isFixedPitch
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|bool
name|italic
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
argument_list|)
decl|const
decl_stmt|;
name|bool
name|bold
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
argument_list|)
decl|const
decl_stmt|;
name|int
name|weight
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
specifier|const
name|QString
operator|&
name|style
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasFamily
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isPrivateFamily
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QString
name|writingSystemName
parameter_list|(
name|WritingSystem
name|writingSystem
parameter_list|)
function_decl|;
specifier|static
name|QString
name|writingSystemSample
parameter_list|(
name|WritingSystem
name|writingSystem
parameter_list|)
function_decl|;
specifier|static
name|int
name|addApplicationFont
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|int
name|addApplicationFontFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|applicationFontFamilies
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
specifier|static
name|bool
name|removeApplicationFont
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
specifier|static
name|bool
name|removeAllApplicationFonts
parameter_list|()
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|2
argument_list|)
name|QT_DEPRECATED
specifier|static
name|bool
name|supportsThreadedFontRendering
parameter_list|()
function_decl|;
endif|#
directive|endif
specifier|static
name|QFont
name|systemFont
parameter_list|(
name|SystemFont
name|type
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|void
name|createDatabase
parameter_list|()
function_decl|;
specifier|static
name|void
name|parseFontName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QString
modifier|&
name|foundry
parameter_list|,
name|QString
modifier|&
name|family
parameter_list|)
function_decl|;
specifier|static
name|QString
name|resolveFontFamilyAlias
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
function_decl|;
specifier|static
name|QFontEngine
modifier|*
name|findFont
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|request
parameter_list|,
name|int
name|script
parameter_list|)
function_decl|;
specifier|static
name|void
name|load
parameter_list|(
specifier|const
name|QFontPrivate
modifier|*
name|d
parameter_list|,
name|int
name|script
parameter_list|)
function_decl|;
name|friend
struct_decl|struct
name|QFontDef
struct_decl|;
name|friend
name|class
name|QFontPrivate
decl_stmt|;
name|friend
name|class
name|QFontDialog
decl_stmt|;
name|friend
name|class
name|QFontDialogPrivate
decl_stmt|;
name|friend
name|class
name|QFontEngineMulti
decl_stmt|;
name|friend
name|class
name|QRawFont
decl_stmt|;
name|QFontDatabasePrivate
modifier|*
name|d
decl_stmt|;
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
comment|// QFONTDATABASE_H
end_comment
end_unit
