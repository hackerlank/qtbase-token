begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMFONTDATABASE_H
end_ifndef
begin_define
DECL|macro|QPLATFORMFONTDATABASE_H
define|#
directive|define
name|QPLATFORMFONTDATABASE_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qconfig.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|5
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/QFontDatabase>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfont_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWritingSystemsPrivate
name|class
name|QWritingSystemsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSupportedWritingSystems
block|{
name|public
label|:
name|QSupportedWritingSystems
argument_list|()
expr_stmt|;
name|QSupportedWritingSystems
argument_list|(
specifier|const
name|QSupportedWritingSystems
operator|&
name|other
argument_list|)
expr_stmt|;
name|QSupportedWritingSystems
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSupportedWritingSystems
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QSupportedWritingSystems
argument_list|()
expr_stmt|;
name|void
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|,
name|bool
name|supported
operator|=
name|true
argument_list|)
decl_stmt|;
name|bool
name|supported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|detach
parameter_list|()
function_decl|;
name|QWritingSystemsPrivate
modifier|*
name|d
decl_stmt|;
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSupportedWritingSystems
operator|&
operator|,
specifier|const
name|QSupportedWritingSystems
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSupportedWritingSystems
operator|&
operator|,
specifier|const
name|QSupportedWritingSystems
operator|&
operator|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSupportedWritingSystems
operator|&
operator|,
specifier|const
name|QSupportedWritingSystems
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSupportedWritingSystems
operator|&
operator|,
specifier|const
name|QSupportedWritingSystems
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QFontRequestPrivate
name|class
name|QFontRequestPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontEngineMulti
name|class
name|QFontEngineMulti
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformFontDatabase
block|{
name|public
label|:
name|virtual
operator|~
name|QPlatformFontDatabase
argument_list|()
expr_stmt|;
name|virtual
name|void
name|populateFontDatabase
parameter_list|()
function_decl|;
name|virtual
name|void
name|populateFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|)
function_decl|;
name|virtual
name|void
name|invalidate
parameter_list|()
function_decl|;
name|virtual
name|QFontEngineMulti
modifier|*
name|fontEngineMulti
argument_list|(
name|QFontEngine
operator|*
name|fontEngine
argument_list|,
name|QChar
operator|::
name|Script
name|script
argument_list|)
decl_stmt|;
name|virtual
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
name|virtual
name|QStringList
name|fallbacksForFamily
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|,
name|QFont
operator|::
name|Style
name|style
argument_list|,
name|QFont
operator|::
name|StyleHint
name|styleHint
argument_list|,
name|QChar
operator|::
name|Script
name|script
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QStringList
name|addApplicationFont
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|virtual
name|void
name|releaseHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
name|virtual
name|QFontEngine
modifier|*
name|fontEngine
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontData
argument_list|,
name|qreal
name|pixelSize
argument_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
argument_list|)
decl_stmt|;
name|virtual
name|QString
name|fontDir
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QFont
name|defaultFont
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|isPrivateFontFamily
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|resolveFontFamilyAlias
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|fontsAlwaysScalable
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|standardSizes
argument_list|()
specifier|const
expr_stmt|;
name|QFontEngine
operator|::
name|SubpixelAntialiasingType
name|subpixelAntialiasingTypeHint
argument_list|()
specifier|const
expr_stmt|;
comment|// helper
specifier|static
name|QSupportedWritingSystems
name|writingSystemsFromTrueTypeBits
parameter_list|(
name|quint32
name|unicodeRange
index|[
literal|4
index|]
parameter_list|,
name|quint32
name|codePageRange
index|[
literal|2
index|]
parameter_list|)
function_decl|;
specifier|static
name|QFont
operator|::
name|Weight
name|weightFromInteger
argument_list|(
argument|int weight
argument_list|)
expr_stmt|;
comment|//callback
specifier|static
name|void
name|registerQPF2Font
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|dataArray
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
specifier|static
name|void
name|registerFont
argument_list|(
specifier|const
name|QString
operator|&
name|familyname
argument_list|,
specifier|const
name|QString
operator|&
name|stylename
argument_list|,
specifier|const
name|QString
operator|&
name|foundryname
argument_list|,
name|QFont
operator|::
name|Weight
name|weight
argument_list|,
name|QFont
operator|::
name|Style
name|style
argument_list|,
name|QFont
operator|::
name|Stretch
name|stretch
argument_list|,
name|bool
name|antialiased
argument_list|,
name|bool
name|scalable
argument_list|,
name|int
name|pixelSize
argument_list|,
name|bool
name|fixedPitch
argument_list|,
specifier|const
name|QSupportedWritingSystems
operator|&
name|writingSystems
argument_list|,
name|void
operator|*
name|handle
argument_list|)
decl_stmt|;
specifier|static
name|void
name|registerFontFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|)
function_decl|;
specifier|static
name|void
name|registerAliasToFontFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|,
specifier|const
name|QString
modifier|&
name|alias
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
comment|// QPLATFORMFONTDATABASE_H
end_comment
end_unit
