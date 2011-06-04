begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONT_P_H
end_ifndef
begin_define
DECL|macro|QFONT_P_H
define|#
directive|define
name|QFONT_P_H
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
file|"QtGui/qfont.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|<private/qunicodetables_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|"private/qfixed_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// forwards
DECL|variable|QFontCache
name|class
name|QFontCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QFontDef
struct|struct
name|QFontDef
block|{
DECL|function|QFontDef
specifier|inline
name|QFontDef
argument_list|()
operator|:
name|pointSize
argument_list|(
operator|-
literal|1.0
argument_list|)
operator|,
name|pixelSize
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|styleStrategy
argument_list|(
name|QFont
operator|::
name|PreferDefault
argument_list|)
operator|,
name|styleHint
argument_list|(
name|QFont
operator|::
name|AnyStyle
argument_list|)
operator|,
name|weight
argument_list|(
literal|50
argument_list|)
operator|,
name|fixedPitch
argument_list|(
name|false
argument_list|)
operator|,
name|style
argument_list|(
name|QFont
operator|::
name|StyleNormal
argument_list|)
operator|,
name|stretch
argument_list|(
literal|100
argument_list|)
operator|,
name|ignorePitch
argument_list|(
name|true
argument_list|)
operator|,
name|hintingPreference
argument_list|(
name|QFont
operator|::
name|PreferDefaultHinting
argument_list|)
ifdef|#
directive|ifdef
name|Q_WS_MAC
operator|,
name|fixedPitchComputed
argument_list|(
argument|false
argument_list|)
endif|#
directive|endif
block|{     }
DECL|member|family
name|QString
name|family
expr_stmt|;
DECL|member|styleName
name|QString
name|styleName
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
DECL|member|addStyle
name|QString
name|addStyle
decl_stmt|;
endif|#
directive|endif
comment|// Q_WS_X11
DECL|member|pointSize
name|qreal
name|pointSize
decl_stmt|;
DECL|member|pixelSize
name|qreal
name|pixelSize
decl_stmt|;
DECL|member|styleStrategy
name|uint
name|styleStrategy
range|:
literal|16
decl_stmt|;
DECL|member|styleHint
name|uint
name|styleHint
range|:
literal|8
decl_stmt|;
DECL|member|weight
name|uint
name|weight
range|:
literal|7
decl_stmt|;
comment|// 0-99
DECL|member|fixedPitch
name|uint
name|fixedPitch
range|:
literal|1
decl_stmt|;
DECL|member|style
name|uint
name|style
range|:
literal|2
decl_stmt|;
DECL|member|stretch
name|uint
name|stretch
range|:
literal|12
decl_stmt|;
comment|// 0-400
DECL|member|ignorePitch
name|uint
name|ignorePitch
range|:
literal|1
decl_stmt|;
DECL|member|hintingPreference
name|uint
name|hintingPreference
range|:
literal|2
decl_stmt|;
DECL|member|fixedPitchComputed
name|uint
name|fixedPitchComputed
range|:
literal|1
decl_stmt|;
comment|// for Mac OS X only
DECL|member|reserved
name|int
name|reserved
range|:
literal|14
decl_stmt|;
comment|// for future extensions
name|bool
name|exactMatch
argument_list|(
specifier|const
name|QFontDef
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QFontDef
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|pixelSize
operator|==
name|other
operator|.
name|pixelSize
operator|&&
name|weight
operator|==
name|other
operator|.
name|weight
operator|&&
name|style
operator|==
name|other
operator|.
name|style
operator|&&
name|stretch
operator|==
name|other
operator|.
name|stretch
operator|&&
name|styleHint
operator|==
name|other
operator|.
name|styleHint
operator|&&
name|styleStrategy
operator|==
name|other
operator|.
name|styleStrategy
operator|&&
name|ignorePitch
operator|==
name|other
operator|.
name|ignorePitch
operator|&&
name|fixedPitch
operator|==
name|other
operator|.
name|fixedPitch
operator|&&
name|family
operator|==
name|other
operator|.
name|family
operator|&&
name|hintingPreference
operator|==
name|other
operator|.
name|hintingPreference
ifdef|#
directive|ifdef
name|Q_WS_X11
operator|&&
name|addStyle
operator|==
name|other
operator|.
name|addStyle
endif|#
directive|endif
return|;
block|}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFontDef
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|pixelSize
operator|!=
name|other
operator|.
name|pixelSize
condition|)
return|return
name|pixelSize
operator|<
name|other
operator|.
name|pixelSize
return|;
if|if
condition|(
name|weight
operator|!=
name|other
operator|.
name|weight
condition|)
return|return
name|weight
operator|<
name|other
operator|.
name|weight
return|;
if|if
condition|(
name|style
operator|!=
name|other
operator|.
name|style
condition|)
return|return
name|style
operator|<
name|other
operator|.
name|style
return|;
if|if
condition|(
name|stretch
operator|!=
name|other
operator|.
name|stretch
condition|)
return|return
name|stretch
operator|<
name|other
operator|.
name|stretch
return|;
if|if
condition|(
name|styleHint
operator|!=
name|other
operator|.
name|styleHint
condition|)
return|return
name|styleHint
operator|<
name|other
operator|.
name|styleHint
return|;
if|if
condition|(
name|styleStrategy
operator|!=
name|other
operator|.
name|styleStrategy
condition|)
return|return
name|styleStrategy
operator|<
name|other
operator|.
name|styleStrategy
return|;
if|if
condition|(
name|family
operator|!=
name|other
operator|.
name|family
condition|)
return|return
name|family
operator|<
name|other
operator|.
name|family
return|;
if|if
condition|(
name|hintingPreference
operator|!=
name|other
operator|.
name|hintingPreference
condition|)
return|return
name|hintingPreference
operator|<
name|other
operator|.
name|hintingPreference
return|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|addStyle
operator|!=
name|other
operator|.
name|addStyle
condition|)
return|return
name|addStyle
operator|<
name|other
operator|.
name|addStyle
return|;
endif|#
directive|endif
comment|// Q_WS_X11
if|if
condition|(
name|ignorePitch
operator|!=
name|other
operator|.
name|ignorePitch
condition|)
return|return
name|ignorePitch
operator|<
name|other
operator|.
name|ignorePitch
return|;
if|if
condition|(
name|fixedPitch
operator|!=
name|other
operator|.
name|fixedPitch
condition|)
return|return
name|fixedPitch
operator|<
name|other
operator|.
name|fixedPitch
return|;
return|return
name|false
return|;
block|}
end_struct
begin_decl_stmt
unit|};
name|class
name|QFontEngineData
block|{
name|public
label|:
name|QFontEngineData
argument_list|()
expr_stmt|;
operator|~
name|QFontEngineData
argument_list|()
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QFontCache
modifier|*
name|fontCache
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|QFontEngine
modifier|*
name|engines
index|[
name|QUnicodeTables
operator|::
name|ScriptCount
index|]
decl_stmt|;
else|#
directive|else
name|QFontEngine
modifier|*
name|engine
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontPrivate
block|{
name|public
label|:
ifdef|#
directive|ifdef
name|Q_WS_X11
specifier|static
name|int
name|defaultEncodingID
decl_stmt|;
endif|#
directive|endif
comment|// Q_WS_X11
name|QFontPrivate
argument_list|()
expr_stmt|;
name|QFontPrivate
argument_list|(
specifier|const
name|QFontPrivate
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QFontPrivate
argument_list|()
expr_stmt|;
name|QFontEngine
modifier|*
name|engineForScript
argument_list|(
name|int
name|script
argument_list|)
decl|const
decl_stmt|;
name|void
name|alterCharForCapitalization
argument_list|(
name|QChar
operator|&
name|c
argument_list|)
decl|const
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QFontDef
name|request
decl_stmt|;
name|mutable
name|QFontEngineData
modifier|*
name|engineData
decl_stmt|;
name|int
name|dpi
decl_stmt|;
name|int
name|screen
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|HDC
name|hdc
decl_stmt|;
endif|#
directive|endif
name|uint
name|rawMode
range|:
literal|1
decl_stmt|;
name|uint
name|underline
range|:
literal|1
decl_stmt|;
name|uint
name|overline
range|:
literal|1
decl_stmt|;
name|uint
name|strikeOut
range|:
literal|1
decl_stmt|;
name|uint
name|kerning
range|:
literal|1
decl_stmt|;
name|uint
name|capital
range|:
literal|3
decl_stmt|;
name|bool
name|letterSpacingIsAbsolute
range|:
literal|1
decl_stmt|;
name|QFixed
name|letterSpacing
decl_stmt|;
name|QFixed
name|wordSpacing
decl_stmt|;
name|mutable
name|QFontPrivate
modifier|*
name|scFont
decl_stmt|;
name|QFont
name|smallCapsFont
argument_list|()
specifier|const
block|{
return|return
name|QFont
argument_list|(
name|smallCapsFontPrivate
argument_list|()
argument_list|)
return|;
block|}
name|QFontPrivate
operator|*
name|smallCapsFontPrivate
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QFontPrivate
modifier|*
name|get
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
return|return
name|font
operator|.
name|d
operator|.
name|data
argument_list|()
return|;
block|}
name|void
name|resolve
parameter_list|(
name|uint
name|mask
parameter_list|,
specifier|const
name|QFontPrivate
modifier|*
name|other
parameter_list|)
function_decl|;
name|private
label|:
name|QFontPrivate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontPrivate
operator|&
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QFontCache
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// note: these static functions work on a per-thread basis
specifier|static
name|QFontCache
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|void
name|cleanup
argument_list|()
block|;
name|QFontCache
argument_list|()
block|;
operator|~
name|QFontCache
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_QWS_QPF2
argument_list|)
name|void
name|removeEngineForFont
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontName
argument_list|)
block|;
endif|#
directive|endif
comment|// universal key structure.  QFontEngineDatas and QFontEngines are cached using
comment|// the same keys
block|struct
name|Key
block|{
name|Key
argument_list|()
operator|:
name|script
argument_list|(
literal|0
argument_list|)
block|,
name|screen
argument_list|(
literal|0
argument_list|)
block|{ }
name|Key
argument_list|(
argument|const QFontDef&d
argument_list|,
argument|int c
argument_list|,
argument|int s =
literal|0
argument_list|)
operator|:
name|def
argument_list|(
name|d
argument_list|)
block|,
name|script
argument_list|(
name|c
argument_list|)
block|,
name|screen
argument_list|(
argument|s
argument_list|)
block|{ }
name|QFontDef
name|def
block|;
name|int
name|script
block|;
name|int
name|screen
block|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|script
operator|!=
name|other
operator|.
name|script
condition|)
return|return
name|script
operator|<
name|other
operator|.
name|script
return|;
if|if
condition|(
name|screen
operator|!=
name|other
operator|.
name|screen
condition|)
return|return
name|screen
operator|<
name|other
operator|.
name|screen
return|;
return|return
name|def
operator|<
name|other
operator|.
name|def
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Key
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|def
operator|==
name|other
operator|.
name|def
operator|&&
name|script
operator|==
name|other
operator|.
name|script
operator|&&
name|screen
operator|==
name|other
operator|.
name|screen
return|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// QFontEngineData cache
end_comment
begin_typedef
typedef|typedef
name|QMap
operator|<
name|Key
operator|,
name|QFontEngineData
operator|*
operator|>
name|EngineDataCache
expr_stmt|;
end_typedef
begin_decl_stmt
name|EngineDataCache
name|engineDataCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFontEngineData
modifier|*
name|findEngineData
argument_list|(
specifier|const
name|Key
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|insertEngineData
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|,
name|QFontEngineData
modifier|*
name|engineData
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// QFontEngine cache
end_comment
begin_struct
struct|struct
name|Engine
block|{
name|Engine
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
operator|,
name|timestamp
argument_list|(
literal|0
argument_list|)
operator|,
name|hits
argument_list|(
literal|0
argument_list|)
block|{ }
name|Engine
argument_list|(
name|QFontEngine
operator|*
name|d
argument_list|)
operator|:
name|data
argument_list|(
name|d
argument_list|)
operator|,
name|timestamp
argument_list|(
literal|0
argument_list|)
operator|,
name|hits
argument_list|(
literal|0
argument_list|)
block|{ }
name|QFontEngine
operator|*
name|data
expr_stmt|;
name|uint
name|timestamp
decl_stmt|;
name|uint
name|hits
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|QMap
operator|<
name|Key
operator|,
name|Engine
operator|>
name|EngineCache
expr_stmt|;
end_typedef
begin_decl_stmt
name|EngineCache
name|engineCache
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QFontEngine
modifier|*
name|findEngine
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insertEngine
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|,
name|QFontEngine
modifier|*
name|engine
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
end_if
begin_function_decl
name|void
name|cleanupPrinterFonts
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|increaseCost
parameter_list|(
name|uint
name|cost
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|decreaseCost
parameter_list|(
name|uint
name|cost
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
specifier|const
name|uint
name|min_cost
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|total_cost
decl_stmt|,
name|max_cost
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|current_timestamp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|fast
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|timer_id
decl_stmt|;
end_decl_stmt
begin_function_decl
unit|};
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpiX
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpiY
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|int
name|qt_defaultDpi
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONT_P_H
end_comment
end_unit
