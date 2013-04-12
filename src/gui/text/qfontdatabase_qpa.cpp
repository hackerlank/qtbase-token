begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlibraryinfo.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qsettings.h>
end_include
begin_include
include|#
directive|include
file|"qfontengine_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_registerFont
name|Q_GUI_EXPORT
name|void
name|qt_registerFont
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|,
specifier|const
name|QString
modifier|&
name|stylename
parameter_list|,
specifier|const
name|QString
modifier|&
name|foundryname
parameter_list|,
name|int
name|weight
parameter_list|,
name|QFont
operator|::
name|Style
name|style
parameter_list|,
name|int
name|stretch
parameter_list|,
name|bool
name|antialiased
parameter_list|,
name|bool
name|scalable
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|bool
name|fixedPitch
parameter_list|,
specifier|const
name|QSupportedWritingSystems
modifier|&
name|writingSystems
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|QFontDatabasePrivate
modifier|*
name|d
init|=
name|privateDb
argument_list|()
decl_stmt|;
comment|//    qDebug()<< "Adding font"<< familyName<< weight<< style<< pixelSize<< antialiased;
name|QtFontStyle
operator|::
name|Key
name|styleKey
decl_stmt|;
name|styleKey
operator|.
name|style
operator|=
name|style
expr_stmt|;
name|styleKey
operator|.
name|weight
operator|=
name|weight
expr_stmt|;
name|styleKey
operator|.
name|stretch
operator|=
name|stretch
expr_stmt|;
name|QtFontFamily
modifier|*
name|f
init|=
name|d
operator|->
name|family
argument_list|(
name|familyName
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|f
operator|->
name|fixedPitch
operator|=
name|fixedPitch
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QFontDatabase
operator|::
name|WritingSystemsCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|writingSystems
operator|.
name|supported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
name|f
operator|->
name|writingSystems
index|[
name|i
index|]
operator|=
name|QtFontFamily
operator|::
name|Supported
expr_stmt|;
block|}
name|QtFontFoundry
modifier|*
name|foundry
init|=
name|f
operator|->
name|foundry
argument_list|(
name|foundryname
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QtFontStyle
modifier|*
name|fontStyle
init|=
name|foundry
operator|->
name|style
argument_list|(
name|styleKey
argument_list|,
name|stylename
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|fontStyle
operator|->
name|smoothScalable
operator|=
name|scalable
expr_stmt|;
name|fontStyle
operator|->
name|antialiased
operator|=
name|antialiased
expr_stmt|;
name|QtFontSize
modifier|*
name|size
init|=
name|fontStyle
operator|->
name|pixelSize
argument_list|(
name|pixelSize
condition|?
name|pixelSize
else|:
name|SMOOTH_SCALABLE
argument_list|,
literal|true
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|->
name|handle
condition|)
block|{
name|QPlatformIntegration
modifier|*
name|integration
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
if|if
condition|(
name|integration
condition|)
name|integration
operator|->
name|fontDatabase
argument_list|()
operator|->
name|releaseHandle
argument_list|(
name|size
operator|->
name|handle
argument_list|)
expr_stmt|;
block|}
name|size
operator|->
name|handle
operator|=
name|handle
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_registerAliasToFontFamily
name|Q_GUI_EXPORT
name|void
name|qt_registerAliasToFontFamily
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
block|{
if|if
condition|(
name|alias
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QFontDatabasePrivate
modifier|*
name|d
init|=
name|privateDb
argument_list|()
decl_stmt|;
name|QtFontFamily
modifier|*
name|f
init|=
name|d
operator|->
name|family
argument_list|(
name|familyName
argument_list|,
literal|false
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
condition|)
return|return;
if|if
condition|(
name|f
operator|->
name|aliases
operator|.
name|contains
argument_list|(
name|alias
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return;
name|f
operator|->
name|aliases
operator|.
name|push_back
argument_list|(
name|alias
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fallbackFamilies
specifier|static
name|QStringList
name|fallbackFamilies
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|,
name|QFont
operator|::
name|Style
name|style
parameter_list|,
name|QFont
operator|::
name|StyleHint
name|styleHint
parameter_list|,
name|QChar
operator|::
name|Script
name|script
parameter_list|)
block|{
name|QStringList
name|retList
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|fallbacksForFamily
argument_list|(
name|family
argument_list|,
name|style
argument_list|,
name|styleHint
argument_list|,
name|script
argument_list|)
decl_stmt|;
name|QFontDatabasePrivate
modifier|*
name|db
init|=
name|privateDb
argument_list|()
decl_stmt|;
name|QStringList
operator|::
name|iterator
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|retList
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|retList
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|bool
name|contains
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|db
operator|->
name|count
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|db
operator|->
name|families
index|[
name|j
index|]
operator|->
name|matchesFamilyName
argument_list|(
operator|*
name|i
argument_list|)
condition|)
block|{
name|contains
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|contains
condition|)
block|{
name|i
operator|=
name|retList
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|i
operator|--
expr_stmt|;
block|}
block|}
return|return
name|retList
return|;
block|}
end_function
begin_function_decl
specifier|static
name|void
name|registerFont
parameter_list|(
name|QFontDatabasePrivate
operator|::
name|ApplicationFont
modifier|*
name|fnt
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|initializeDb
specifier|static
name|void
name|initializeDb
parameter_list|()
block|{
name|QFontDatabasePrivate
modifier|*
name|db
init|=
name|privateDb
argument_list|()
decl_stmt|;
comment|// init by asking for the platformfontdb for the first time or after invalidation
if|if
condition|(
operator|!
name|db
operator|->
name|count
condition|)
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|populateFontDatabase
argument_list|()
expr_stmt|;
if|if
condition|(
name|db
operator|->
name|reregisterAppFonts
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|db
operator|->
name|applicationFonts
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|db
operator|->
name|applicationFonts
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|families
operator|.
name|isEmpty
argument_list|()
condition|)
name|registerFont
argument_list|(
operator|&
name|db
operator|->
name|applicationFonts
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|db
operator|->
name|reregisterAppFonts
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|load
specifier|static
specifier|inline
name|void
name|load
parameter_list|(
specifier|const
name|QString
modifier|&
init|=
name|QString
argument_list|()
parameter_list|,
name|int
init|=
operator|-
literal|1
parameter_list|)
block|{
comment|// Only initialize the database if it has been cleared or not initialized yet
if|if
condition|(
operator|!
name|privateDb
argument_list|()
operator|->
name|count
condition|)
name|initializeDb
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|static
DECL|function|loadSingleEngine
name|QFontEngine
modifier|*
name|loadSingleEngine
parameter_list|(
name|int
name|script
parameter_list|,
specifier|const
name|QFontDef
modifier|&
name|request
parameter_list|,
name|QtFontFoundry
modifier|*
name|foundry
parameter_list|,
name|QtFontStyle
modifier|*
name|style
parameter_list|,
name|QtFontSize
modifier|*
name|size
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|foundry
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QPlatformFontDatabase
modifier|*
name|pfdb
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
decl_stmt|;
name|int
name|pixelSize
init|=
name|size
operator|->
name|pixelSize
decl_stmt|;
if|if
condition|(
operator|!
name|pixelSize
operator|||
operator|(
name|style
operator|->
name|smoothScalable
operator|&&
name|pixelSize
operator|==
name|SMOOTH_SCALABLE
operator|)
operator|||
name|pfdb
operator|->
name|fontsAlwaysScalable
argument_list|()
condition|)
block|{
name|pixelSize
operator|=
name|request
operator|.
name|pixelSize
expr_stmt|;
block|}
name|QFontDef
name|def
init|=
name|request
decl_stmt|;
name|def
operator|.
name|pixelSize
operator|=
name|pixelSize
expr_stmt|;
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|def
argument_list|,
name|script
argument_list|)
decl_stmt|;
name|QFontEngine
modifier|*
name|engine
init|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngine
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|engine
condition|)
block|{
name|engine
operator|=
name|pfdb
operator|->
name|fontEngine
argument_list|(
name|def
argument_list|,
name|QChar
operator|::
name|Script
argument_list|(
name|script
argument_list|)
argument_list|,
name|size
operator|->
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|def
argument_list|,
name|script
argument_list|)
decl_stmt|;
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|instance
argument_list|()
operator|->
name|insertEngine
argument_list|(
name|key
argument_list|,
name|engine
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|engine
return|;
block|}
end_function
begin_function
specifier|static
DECL|function|loadEngine
name|QFontEngine
modifier|*
name|loadEngine
parameter_list|(
name|int
name|script
parameter_list|,
specifier|const
name|QFontDef
modifier|&
name|request
parameter_list|,
name|QtFontFamily
modifier|*
name|family
parameter_list|,
name|QtFontFoundry
modifier|*
name|foundry
parameter_list|,
name|QtFontStyle
modifier|*
name|style
parameter_list|,
name|QtFontSize
modifier|*
name|size
parameter_list|)
block|{
name|QFontEngine
modifier|*
name|engine
init|=
name|loadSingleEngine
argument_list|(
name|script
argument_list|,
name|request
argument_list|,
name|foundry
argument_list|,
name|style
argument_list|,
name|size
argument_list|)
decl_stmt|;
comment|//make sure that the db has all fallback families
if|if
condition|(
name|engine
operator|&&
name|engine
operator|->
name|type
argument_list|()
operator|!=
name|QFontEngine
operator|::
name|Multi
operator|&&
operator|!
operator|(
name|request
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoFontMerging
operator|)
operator|&&
operator|!
name|engine
operator|->
name|symbol
condition|)
block|{
if|if
condition|(
name|family
operator|&&
operator|!
name|family
operator|->
name|askedForFallback
condition|)
block|{
name|QFont
operator|::
name|Style
name|fontStyle
init|=
name|QFont
operator|::
name|Style
argument_list|(
name|style
operator|->
name|key
operator|.
name|style
argument_list|)
decl_stmt|;
name|QFont
operator|::
name|StyleHint
name|styleHint
init|=
name|QFont
operator|::
name|StyleHint
argument_list|(
name|request
operator|.
name|styleHint
argument_list|)
decl_stmt|;
if|if
condition|(
name|styleHint
operator|==
name|QFont
operator|::
name|AnyStyle
operator|&&
name|request
operator|.
name|fixedPitch
condition|)
name|styleHint
operator|=
name|QFont
operator|::
name|TypeWriter
expr_stmt|;
name|family
operator|->
name|fallbackFamilies
operator|=
name|fallbackFamilies
argument_list|(
name|family
operator|->
name|name
argument_list|,
name|fontStyle
argument_list|,
name|styleHint
argument_list|,
name|QChar
operator|::
name|Script
argument_list|(
name|script
argument_list|)
argument_list|)
expr_stmt|;
name|family
operator|->
name|askedForFallback
operator|=
literal|true
expr_stmt|;
block|}
name|QStringList
name|fallbacks
init|=
name|privateDb
argument_list|()
operator|->
name|fallbackFamilies
decl_stmt|;
if|if
condition|(
name|family
operator|&&
operator|!
name|family
operator|->
name|fallbackFamilies
operator|.
name|isEmpty
argument_list|()
condition|)
name|fallbacks
operator|=
name|family
operator|->
name|fallbackFamilies
expr_stmt|;
name|QPlatformFontDatabase
modifier|*
name|pfdb
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
decl_stmt|;
name|QFontEngineMulti
modifier|*
name|pfMultiEngine
init|=
name|pfdb
operator|->
name|fontEngineMulti
argument_list|(
name|engine
argument_list|,
name|QChar
operator|::
name|Script
argument_list|(
name|script
argument_list|)
argument_list|)
decl_stmt|;
name|pfMultiEngine
operator|->
name|setFallbackFamiliesList
argument_list|(
name|fallbacks
argument_list|)
expr_stmt|;
name|engine
operator|=
name|pfMultiEngine
expr_stmt|;
comment|// Cache Multi font engine as well in case we got the FT single
comment|// font engine when we are actually looking for a Multi one
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|request
argument_list|,
name|script
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|instance
argument_list|()
operator|->
name|insertEngine
argument_list|(
name|key
argument_list|,
name|engine
argument_list|)
expr_stmt|;
block|}
return|return
name|engine
return|;
block|}
end_function
begin_function
DECL|function|registerFont
specifier|static
name|void
name|registerFont
parameter_list|(
name|QFontDatabasePrivate
operator|::
name|ApplicationFont
modifier|*
name|fnt
parameter_list|)
block|{
name|QFontDatabasePrivate
modifier|*
name|db
init|=
name|privateDb
argument_list|()
decl_stmt|;
name|fnt
operator|->
name|families
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|addApplicationFont
argument_list|(
name|fnt
operator|->
name|data
argument_list|,
name|fnt
operator|->
name|fileName
argument_list|)
expr_stmt|;
name|db
operator|->
name|reregisterAppFonts
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeApplicationFont
name|bool
name|QFontDatabase
operator|::
name|removeApplicationFont
parameter_list|(
name|int
name|handle
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|fontDatabaseMutex
argument_list|()
argument_list|)
decl_stmt|;
name|QFontDatabasePrivate
modifier|*
name|db
init|=
name|privateDb
argument_list|()
decl_stmt|;
if|if
condition|(
name|handle
operator|<
literal|0
operator|||
name|handle
operator|>=
name|db
operator|->
name|applicationFonts
operator|.
name|count
argument_list|()
condition|)
return|return
literal|false
return|;
name|db
operator|->
name|applicationFonts
index|[
name|handle
index|]
operator|=
name|QFontDatabasePrivate
operator|::
name|ApplicationFont
argument_list|()
expr_stmt|;
name|db
operator|->
name|reregisterAppFonts
operator|=
literal|true
expr_stmt|;
name|db
operator|->
name|invalidate
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|removeAllApplicationFonts
name|bool
name|QFontDatabase
operator|::
name|removeAllApplicationFonts
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
name|fontDatabaseMutex
argument_list|()
argument_list|)
decl_stmt|;
name|QFontDatabasePrivate
modifier|*
name|db
init|=
name|privateDb
argument_list|()
decl_stmt|;
if|if
condition|(
name|db
operator|->
name|applicationFonts
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|db
operator|->
name|applicationFonts
operator|.
name|clear
argument_list|()
expr_stmt|;
name|db
operator|->
name|invalidate
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|supportsThreadedFontRendering
name|bool
name|QFontDatabase
operator|::
name|supportsThreadedFontRendering
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
name|QFontEngine
modifier|*
DECL|function|findFont
name|QFontDatabase
operator|::
name|findFont
parameter_list|(
name|int
name|script
parameter_list|,
specifier|const
name|QFontPrivate
modifier|*
name|fp
parameter_list|,
specifier|const
name|QFontDef
modifier|&
name|request
parameter_list|,
name|bool
name|multi
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|fontDatabaseMutex
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
name|force_encoding_id
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
operator|!
name|privateDb
argument_list|()
operator|->
name|count
condition|)
name|initializeDb
argument_list|()
expr_stmt|;
name|QFontEngine
modifier|*
name|engine
decl_stmt|;
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|request
argument_list|,
name|script
argument_list|,
name|multi
condition|?
literal|1
else|:
literal|0
argument_list|)
decl_stmt|;
name|engine
operator|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngine
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|FM_DEBUG
argument_list|(
literal|"Cache hit level 1"
argument_list|)
expr_stmt|;
return|return
name|engine
return|;
block|}
name|QString
name|family_name
decl_stmt|,
name|foundry_name
decl_stmt|;
name|parseFontName
argument_list|(
name|request
operator|.
name|family
argument_list|,
name|foundry_name
argument_list|,
name|family_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|qt_enable_test_font
operator|&&
name|request
operator|.
name|family
operator|==
name|QLatin1String
argument_list|(
literal|"__Qt__Box__Engine__"
argument_list|)
condition|)
block|{
name|engine
operator|=
operator|new
name|QTestFontEngine
argument_list|(
name|request
operator|.
name|pixelSize
argument_list|)
expr_stmt|;
name|engine
operator|->
name|fontDef
operator|=
name|request
expr_stmt|;
block|}
name|QtFontDesc
name|desc
decl_stmt|;
name|match
argument_list|(
name|script
argument_list|,
name|request
argument_list|,
name|family_name
argument_list|,
name|foundry_name
argument_list|,
name|force_encoding_id
argument_list|,
operator|&
name|desc
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|.
name|family
operator|!=
literal|0
operator|&&
name|desc
operator|.
name|foundry
operator|!=
literal|0
operator|&&
name|desc
operator|.
name|style
operator|!=
literal|0
condition|)
block|{
name|engine
operator|=
name|loadEngine
argument_list|(
name|script
argument_list|,
name|request
argument_list|,
name|desc
operator|.
name|family
argument_list|,
name|desc
operator|.
name|foundry
argument_list|,
name|desc
operator|.
name|style
argument_list|,
name|desc
operator|.
name|size
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|FM_DEBUG
argument_list|(
literal|"  NO MATCH FOUND\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|engine
operator|&&
name|engine
operator|->
name|type
argument_list|()
operator|!=
name|QFontEngine
operator|::
name|TestFontEngine
condition|)
block|{
name|initFontDef
argument_list|(
name|desc
argument_list|,
name|request
argument_list|,
operator|&
name|engine
operator|->
name|fontDef
argument_list|,
name|engine
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Multi
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
condition|)
block|{
name|QFontDef
name|def
init|=
name|request
decl_stmt|;
if|if
condition|(
name|def
operator|.
name|family
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|def
operator|.
name|family
operator|=
name|fp
operator|->
name|request
operator|.
name|family
expr_stmt|;
name|def
operator|.
name|family
operator|=
name|def
operator|.
name|family
operator|.
name|left
argument_list|(
name|def
operator|.
name|family
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|engine
condition|)
block|{
if|if
condition|(
operator|!
name|request
operator|.
name|family
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
name|fallbacks
init|=
name|request
operator|.
name|fallBackFamilies
operator|+
name|fallbackFamilies
argument_list|(
name|request
operator|.
name|family
argument_list|,
name|QFont
operator|::
name|Style
argument_list|(
name|request
operator|.
name|style
argument_list|)
argument_list|,
name|QFont
operator|::
name|StyleHint
argument_list|(
name|request
operator|.
name|styleHint
argument_list|)
argument_list|,
name|QChar
operator|::
name|Script
argument_list|(
name|script
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
operator|!
name|engine
operator|&&
name|i
operator|<
name|fallbacks
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QFontDef
name|def
init|=
name|request
decl_stmt|;
name|def
operator|.
name|family
operator|=
name|fallbacks
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|def
argument_list|,
name|script
argument_list|,
name|multi
condition|?
literal|1
else|:
literal|0
argument_list|)
decl_stmt|;
name|engine
operator|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngine
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|engine
condition|)
block|{
name|QtFontDesc
name|desc
decl_stmt|;
name|match
argument_list|(
name|script
argument_list|,
name|def
argument_list|,
name|def
operator|.
name|family
argument_list|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|&
name|desc
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|.
name|family
operator|==
literal|0
operator|&&
name|desc
operator|.
name|foundry
operator|==
literal|0
operator|&&
name|desc
operator|.
name|style
operator|==
literal|0
condition|)
block|{
continue|continue;
block|}
name|engine
operator|=
name|loadEngine
argument_list|(
name|script
argument_list|,
name|def
argument_list|,
name|desc
operator|.
name|family
argument_list|,
name|desc
operator|.
name|foundry
argument_list|,
name|desc
operator|.
name|style
argument_list|,
name|desc
operator|.
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|engine
condition|)
block|{
name|initFontDef
argument_list|(
name|desc
argument_list|,
name|def
argument_list|,
operator|&
name|engine
operator|->
name|fontDef
argument_list|,
name|engine
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Multi
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
if|if
condition|(
operator|!
name|engine
condition|)
name|engine
operator|=
operator|new
name|QFontEngineBox
argument_list|(
name|request
operator|.
name|pixelSize
argument_list|)
expr_stmt|;
name|FM_DEBUG
argument_list|(
literal|"returning box engine"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fp
operator|&&
name|fp
operator|->
name|dpi
operator|>
literal|0
condition|)
block|{
name|engine
operator|->
name|fontDef
operator|.
name|pointSize
operator|=
name|qreal
argument_list|(
name|double
argument_list|(
operator|(
name|engine
operator|->
name|fontDef
operator|.
name|pixelSize
operator|*
literal|72
operator|)
operator|/
name|fp
operator|->
name|dpi
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|engine
operator|->
name|fontDef
operator|.
name|pointSize
operator|=
name|request
operator|.
name|pointSize
expr_stmt|;
block|}
return|return
name|engine
return|;
block|}
end_function
begin_function
DECL|function|load
name|void
name|QFontDatabase
operator|::
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
block|{
name|QFontDef
name|req
init|=
name|d
operator|->
name|request
decl_stmt|;
if|if
condition|(
name|req
operator|.
name|pixelSize
operator|==
operator|-
literal|1
condition|)
block|{
name|req
operator|.
name|pixelSize
operator|=
name|floor
argument_list|(
operator|(
operator|(
name|req
operator|.
name|pointSize
operator|*
name|d
operator|->
name|dpi
operator|)
operator|/
literal|72
operator|)
operator|*
literal|100
operator|+
literal|0.5
argument_list|)
operator|/
literal|100
expr_stmt|;
name|req
operator|.
name|pixelSize
operator|=
name|qRound
argument_list|(
name|req
operator|.
name|pixelSize
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|req
operator|.
name|pointSize
operator|<
literal|0
condition|)
name|req
operator|.
name|pointSize
operator|=
name|req
operator|.
name|pixelSize
operator|*
literal|72.0
operator|/
name|d
operator|->
name|dpi
expr_stmt|;
if|if
condition|(
name|req
operator|.
name|weight
operator|==
literal|0
condition|)
name|req
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Normal
expr_stmt|;
if|if
condition|(
name|req
operator|.
name|stretch
operator|==
literal|0
condition|)
name|req
operator|.
name|stretch
operator|=
literal|100
expr_stmt|;
comment|// Until we specifically asked not to, try looking for Multi font engine
comment|// first, the last '1' indicates that we want Multi font engine instead
comment|// of single ones
name|bool
name|multi
init|=
operator|!
operator|(
name|req
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoFontMerging
operator|)
decl_stmt|;
name|QFontCache
operator|::
name|Key
name|key
argument_list|(
name|req
argument_list|,
name|script
argument_list|,
name|multi
condition|?
literal|1
else|:
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|engineData
condition|)
name|getEngineData
argument_list|(
name|d
argument_list|,
name|req
argument_list|)
expr_stmt|;
comment|// the cached engineData could have already loaded the engine we want
if|if
condition|(
name|d
operator|->
name|engineData
operator|->
name|engines
index|[
name|script
index|]
condition|)
return|return;
name|QFontEngine
modifier|*
name|fe
init|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngine
argument_list|(
name|key
argument_list|)
decl_stmt|;
comment|// list of families to try
name|QStringList
name|family_list
decl_stmt|;
if|if
condition|(
operator|!
name|req
operator|.
name|family
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
name|familiesForRequest
init|=
name|familyList
argument_list|(
name|req
argument_list|)
decl_stmt|;
comment|// Add primary selection
name|family_list
operator|<<
name|familiesForRequest
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
comment|// Fallbacks requested in font request
name|req
operator|.
name|fallBackFamilies
operator|=
name|familiesForRequest
expr_stmt|;
comment|// add the default family
name|QString
name|defaultFamily
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
operator|.
name|family
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|family_list
operator|.
name|contains
argument_list|(
name|defaultFamily
argument_list|)
condition|)
name|family_list
operator|<<
name|defaultFamily
expr_stmt|;
block|}
comment|// null family means find the first font matching the specified script
name|family_list
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|family_list
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|family_list
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
operator|!
name|fe
operator|&&
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|req
operator|.
name|family
operator|=
operator|*
name|it
expr_stmt|;
name|fe
operator|=
name|QFontDatabase
operator|::
name|findFont
argument_list|(
name|script
argument_list|,
name|d
argument_list|,
name|req
argument_list|,
name|multi
argument_list|)
expr_stmt|;
if|if
condition|(
name|fe
operator|&&
operator|(
name|fe
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Box
operator|)
operator|&&
operator|!
name|req
operator|.
name|family
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|fe
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|0
condition|)
operator|delete
name|fe
expr_stmt|;
name|fe
operator|=
literal|0
expr_stmt|;
block|}
comment|// No need to check requested fallback families again
name|req
operator|.
name|fallBackFamilies
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|fe
operator|->
name|symbol
operator|||
operator|(
name|d
operator|->
name|request
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoFontMerging
operator|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QChar
operator|::
name|ScriptCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|engineData
operator|->
name|engines
index|[
name|i
index|]
condition|)
block|{
name|d
operator|->
name|engineData
operator|->
name|engines
index|[
name|i
index|]
operator|=
name|fe
expr_stmt|;
name|fe
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
block|}
block|}
else|else
block|{
name|d
operator|->
name|engineData
operator|->
name|engines
index|[
name|script
index|]
operator|=
name|fe
expr_stmt|;
name|fe
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
block|}
end_function
begin_function
DECL|function|resolveFontFamilyAlias
name|QString
name|QFontDatabase
operator|::
name|resolveFontFamilyAlias
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|resolveFontFamilyAlias
argument_list|(
name|family
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
