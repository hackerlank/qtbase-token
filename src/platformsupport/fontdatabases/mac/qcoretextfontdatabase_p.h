begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORETEXTFONTDATABASE_H
end_ifndef
begin_define
DECL|macro|QCORETEXTFONTDATABASE_H
define|#
directive|define
name|QCORETEXTFONTDATABASE_H
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
file|<qglobal.h>
end_include
begin_define
DECL|macro|HAVE_CORETEXT
define|#
directive|define
name|HAVE_CORETEXT
value|QT_MAC_PLATFORM_SDK_EQUAL_OR_ABOVE(__MAC_10_8, __IPHONE_4_1)
end_define
begin_define
DECL|macro|HAVE_ATS
define|#
directive|define
name|HAVE_ATS
value|QT_MAC_PLATFORM_SDK_EQUAL_OR_ABOVE(__MAC_10_5, __IPHONE_NA)
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_IOS
end_ifndef
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<CoreText/CoreText.h>
end_include
begin_include
include|#
directive|include
file|<CoreGraphics/CoreGraphics.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|HAVE_CORETEXT
end_if
begin_expr_stmt
name|Q_DECLARE_METATYPE
argument_list|(
name|QCFType
operator|<
name|CGFontRef
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_METATYPE
argument_list|(
name|QCFType
operator|<
name|CFURLRef
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|HAVE_ATS
end_if
begin_expr_stmt
DECL|variable|ATSFontContainerRef
name|Q_DECLARE_METATYPE
argument_list|(
name|ATSFontContainerRef
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|FontDescription
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QCoreTextFontDatabase
range|:
name|public
name|QPlatformFontDatabase
block|{
name|public
operator|:
name|QCoreTextFontDatabase
argument_list|()
block|;
operator|~
name|QCoreTextFontDatabase
argument_list|()
block|;
name|void
name|populateFontDatabase
argument_list|()
block|;
name|void
name|populateFamily
argument_list|(
argument|const QString&familyName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFontEngine
operator|*
name|fontEngine
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fontDef
argument_list|,
name|void
operator|*
name|handle
argument_list|)
block|;
name|QFontEngine
operator|*
name|fontEngine
argument_list|(
argument|const QByteArray&fontData
argument_list|,
argument|qreal pixelSize
argument_list|,
argument|QFont::HintingPreference hintingPreference
argument_list|)
block|;
name|QStringList
name|fallbacksForFamily
argument_list|(
argument|const QString&family
argument_list|,
argument|QFont::Style style
argument_list|,
argument|QFont::StyleHint styleHint
argument_list|,
argument|QChar::Script script
argument_list|)
specifier|const
block|;
name|QStringList
name|addApplicationFont
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontData
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|releaseHandle
argument_list|(
name|void
operator|*
name|handle
argument_list|)
block|;
name|bool
name|isPrivateFontFamily
argument_list|(
argument|const QString&family
argument_list|)
specifier|const
block|;
name|QFont
name|defaultFont
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|int
operator|>
name|standardSizes
argument_list|()
specifier|const
block|;
comment|// For iOS and OS X platform themes
name|QFont
operator|*
name|themeFont
argument_list|(
argument|QPlatformTheme::Font
argument_list|)
specifier|const
block|;
specifier|const
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Font
block|,
name|QFont
operator|*
operator|>
operator|&
name|themeFonts
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|populateFromDescriptor
argument_list|(
argument|CTFontDescriptorRef font
argument_list|)
block|;
name|void
name|populateFromFontDescription
argument_list|(
argument|CTFontDescriptorRef font
argument_list|,
argument|const FontDescription&fd
argument_list|)
block|;
name|mutable
name|QString
name|defaultFontName
block|;
name|void
name|removeApplicationFonts
argument_list|()
block|;
name|QVector
operator|<
name|QVariant
operator|>
name|m_applicationFonts
block|;
name|mutable
name|QSet
operator|<
name|CTFontDescriptorRef
operator|>
name|m_systemFontDescriptors
block|;
name|mutable
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Font
block|,
name|QFont
operator|*
operator|>
name|m_themeFonts
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
comment|// QCORETEXTFONTDATABASE_H
end_comment
end_unit
