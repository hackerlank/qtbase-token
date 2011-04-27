begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_include
include|#
directive|include
file|"qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qabstractfileengine.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<qendian.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_coretext_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_mac_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|int
name|qt_mac_pixelsize
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|def
parameter_list|,
name|int
name|dpi
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qfont_mac.cpp
end_comment
begin_function_decl
name|int
name|qt_mac_pointsize
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|def
parameter_list|,
name|int
name|dpi
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qfont_mac.cpp
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
end_ifndef
begin_function
DECL|function|initWritingSystems
specifier|static
name|void
name|initWritingSystems
parameter_list|(
name|QtFontFamily
modifier|*
name|family
parameter_list|,
name|ATSFontRef
name|atsFont
parameter_list|)
block|{
name|ByteCount
name|length
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ATSFontGetTable
argument_list|(
name|atsFont
argument_list|,
name|MAKE_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'S'
argument_list|,
literal|'/'
argument_list|,
literal|'2'
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|length
argument_list|)
operator|!=
name|noErr
condition|)
return|return;
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|os2Table
argument_list|(
name|length
argument_list|)
decl_stmt|;
if|if
condition|(
name|length
operator|<
literal|86
operator|||
name|ATSFontGetTable
argument_list|(
name|atsFont
argument_list|,
name|MAKE_TAG
argument_list|(
literal|'O'
argument_list|,
literal|'S'
argument_list|,
literal|'/'
argument_list|,
literal|'2'
argument_list|)
argument_list|,
literal|0
argument_list|,
name|length
argument_list|,
name|os2Table
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|length
argument_list|)
operator|!=
name|noErr
condition|)
return|return;
comment|// See also qfontdatabase_win.cpp, offsets taken from OS/2 table in the TrueType spec
name|quint32
name|unicodeRange
index|[
literal|4
index|]
init|=
block|{
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|42
argument_list|)
block|,
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|46
argument_list|)
block|,
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|50
argument_list|)
block|,
name|qFromBigEndian
operator|<
name|quint32
operator|>
operator|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|54
operator|)
block|}
decl_stmt|;
name|quint32
name|codePageRange
index|[
literal|2
index|]
init|=
block|{
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|78
argument_list|)
block|,
name|qFromBigEndian
operator|<
name|quint32
operator|>
operator|(
name|os2Table
operator|.
name|data
argument_list|()
operator|+
literal|82
operator|)
block|}
decl_stmt|;
name|QList
argument_list|<
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|>
name|systems
init|=
name|qt_determine_writing_systems_from_truetype_bits
argument_list|(
name|unicodeRange
argument_list|,
name|codePageRange
argument_list|)
decl_stmt|;
if|#
directive|if
literal|0
block|QCFString name;     ATSFontGetName(atsFont, kATSOptionFlagsDefault,&name);     qDebug()<< systems.count()<< "writing systems for"<< QString(name); qDebug()<< "first char"<< hex<< unicodeRange[0];     for (int i = 0; i< systems.count(); ++i)         qDebug()<< QFontDatabase::writingSystemName(systems.at(i));
endif|#
directive|endif
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|systems
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|family
operator|->
name|writingSystems
index|[
name|systems
operator|.
name|at
argument_list|(
name|i
argument_list|)
index|]
operator|=
name|QtFontFamily
operator|::
name|Supported
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
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
if|if
condition|(
operator|!
name|db
operator|||
name|db
operator|->
name|count
condition|)
return|return;
if|#
directive|if
name|defined
argument_list|(
name|QT_MAC_USE_COCOA
argument_list|)
operator|&&
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
if|if
condition|(
name|QSysInfo
operator|::
name|MacintoshVersion
operator|>=
name|QSysInfo
operator|::
name|MV_10_5
condition|)
block|{
name|QCFType
argument_list|<
name|CTFontCollectionRef
argument_list|>
name|collection
init|=
name|CTFontCollectionCreateFromAvailableFonts
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|collection
condition|)
return|return;
name|QCFType
argument_list|<
name|CFArrayRef
argument_list|>
name|fonts
init|=
name|CTFontCollectionCreateMatchingFontDescriptors
argument_list|(
name|collection
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fonts
condition|)
return|return;
name|QString
name|foundry_name
init|=
literal|"CoreText"
decl_stmt|;
specifier|const
name|int
name|numFonts
init|=
name|CFArrayGetCount
argument_list|(
name|fonts
argument_list|)
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
name|numFonts
condition|;
operator|++
name|i
control|)
block|{
name|CTFontDescriptorRef
name|font
init|=
operator|(
name|CTFontDescriptorRef
operator|)
name|CFArrayGetValueAtIndex
argument_list|(
name|fonts
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|QCFString
name|family_name
init|=
operator|(
name|CFStringRef
operator|)
name|CTFontDescriptorCopyAttribute
argument_list|(
name|font
argument_list|,
name|kCTFontFamilyNameAttribute
argument_list|)
decl_stmt|;
name|QtFontFamily
modifier|*
name|family
init|=
name|db
operator|->
name|family
argument_list|(
name|family_name
argument_list|,
literal|true
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|ws
init|=
literal|1
init|;
name|ws
operator|<
name|QFontDatabase
operator|::
name|WritingSystemsCount
condition|;
operator|++
name|ws
control|)
name|family
operator|->
name|writingSystems
index|[
name|ws
index|]
operator|=
name|QtFontFamily
operator|::
name|Supported
expr_stmt|;
name|QtFontFoundry
modifier|*
name|foundry
init|=
name|family
operator|->
name|foundry
argument_list|(
name|foundry_name
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QtFontStyle
operator|::
name|Key
name|styleKey
decl_stmt|;
if|if
condition|(
name|QCFType
argument_list|<
name|CFDictionaryRef
argument_list|>
name|styles
init|=
operator|(
name|CFDictionaryRef
operator|)
name|CTFontDescriptorCopyAttribute
argument_list|(
name|font
argument_list|,
name|kCTFontTraitsAttribute
argument_list|)
condition|)
block|{
if|if
condition|(
name|CFNumberRef
name|weight
init|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|styles
argument_list|,
name|kCTFontWeightTrait
argument_list|)
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|CFNumberIsFloatType
argument_list|(
name|weight
argument_list|)
argument_list|)
expr_stmt|;
name|double
name|d
decl_stmt|;
if|if
condition|(
name|CFNumberGetValue
argument_list|(
name|weight
argument_list|,
name|kCFNumberDoubleType
argument_list|,
operator|&
name|d
argument_list|)
condition|)
block|{
comment|//qDebug()<< "BOLD"<< (QString)family_name<< d;
name|styleKey
operator|.
name|weight
operator|=
operator|(
name|d
operator|>
literal|0.0
operator|)
condition|?
name|QFont
operator|::
name|Bold
else|:
name|QFont
operator|::
name|Normal
expr_stmt|;
block|}
block|}
if|if
condition|(
name|CFNumberRef
name|italic
init|=
operator|(
name|CFNumberRef
operator|)
name|CFDictionaryGetValue
argument_list|(
name|styles
argument_list|,
name|kCTFontSlantTrait
argument_list|)
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|CFNumberIsFloatType
argument_list|(
name|italic
argument_list|)
argument_list|)
expr_stmt|;
name|double
name|d
decl_stmt|;
if|if
condition|(
name|CFNumberGetValue
argument_list|(
name|italic
argument_list|,
name|kCFNumberDoubleType
argument_list|,
operator|&
name|d
argument_list|)
condition|)
block|{
comment|//qDebug()<< "ITALIC"<< (QString)family_name<< d;
if|if
condition|(
name|d
operator|>
literal|0.0
condition|)
name|styleKey
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
block|}
block|}
block|}
name|QtFontStyle
modifier|*
name|style
init|=
name|foundry
operator|->
name|style
argument_list|(
name|styleKey
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|style
operator|->
name|smoothScalable
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|QCFType
argument_list|<
name|CFNumberRef
argument_list|>
name|size
init|=
operator|(
name|CFNumberRef
operator|)
name|CTFontDescriptorCopyAttribute
argument_list|(
name|font
argument_list|,
name|kCTFontSizeAttribute
argument_list|)
condition|)
block|{
comment|//qDebug()<< "WHEE";
name|int
name|pixel_size
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|CFNumberIsFloatType
argument_list|(
name|size
argument_list|)
condition|)
block|{
name|double
name|d
decl_stmt|;
name|CFNumberGetValue
argument_list|(
name|size
argument_list|,
name|kCFNumberDoubleType
argument_list|,
operator|&
name|d
argument_list|)
expr_stmt|;
name|pixel_size
operator|=
name|d
expr_stmt|;
block|}
else|else
block|{
name|CFNumberGetValue
argument_list|(
name|size
argument_list|,
name|kCFNumberIntType
argument_list|,
operator|&
name|pixel_size
argument_list|)
expr_stmt|;
block|}
comment|//qDebug()<< "SIZE"<< (QString)family_name<< pixel_size;
if|if
condition|(
name|pixel_size
condition|)
name|style
operator|->
name|pixelSize
argument_list|(
name|pixel_size
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|//qDebug()<< "WTF?";
block|}
block|}
block|}
else|else
endif|#
directive|endif
block|{
ifndef|#
directive|ifndef
name|QT_MAC_USE_COCOA
name|FMFontIterator
name|it
decl_stmt|;
if|if
condition|(
operator|!
name|FMCreateFontIterator
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|kFMUseGlobalScopeOption
argument_list|,
operator|&
name|it
argument_list|)
condition|)
block|{
while|while
condition|(
literal|true
condition|)
block|{
name|FMFont
name|fmFont
decl_stmt|;
if|if
condition|(
name|FMGetNextFont
argument_list|(
operator|&
name|it
argument_list|,
operator|&
name|fmFont
argument_list|)
operator|!=
name|noErr
condition|)
break|break;
name|FMFontFamily
name|fmFamily
decl_stmt|;
name|FMFontStyle
name|fmStyle
decl_stmt|;
name|QString
name|familyName
decl_stmt|;
name|QtFontStyle
operator|::
name|Key
name|styleKey
decl_stmt|;
name|ATSFontRef
name|atsFont
init|=
name|FMGetATSFontRefFromFont
argument_list|(
name|fmFont
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|FMGetFontFamilyInstanceFromFont
argument_list|(
name|fmFont
argument_list|,
operator|&
name|fmFamily
argument_list|,
operator|&
name|fmStyle
argument_list|)
condition|)
block|{
block|{
comment|//sanity check the font, and see if we can use it at all! --Sam
name|ATSUFontID
name|fontID
decl_stmt|;
if|if
condition|(
name|ATSUFONDtoFontID
argument_list|(
name|fmFamily
argument_list|,
literal|0
argument_list|,
operator|&
name|fontID
argument_list|)
operator|!=
name|noErr
condition|)
continue|continue;
block|}
if|if
condition|(
name|fmStyle
operator|&
operator|::
name|italic
condition|)
name|styleKey
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|fmStyle
operator|&
operator|::
name|bold
condition|)
name|styleKey
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
name|ATSFontFamilyRef
name|familyRef
init|=
name|FMGetATSFontFamilyRefFromFontFamily
argument_list|(
name|fmFamily
argument_list|)
decl_stmt|;
name|QCFString
name|cfFamilyName
decl_stmt|;
empty_stmt|;
name|ATSFontFamilyGetName
argument_list|(
name|familyRef
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|cfFamilyName
argument_list|)
expr_stmt|;
name|familyName
operator|=
name|cfFamilyName
expr_stmt|;
block|}
else|else
block|{
name|QCFString
name|cfFontName
decl_stmt|;
name|ATSFontGetName
argument_list|(
name|atsFont
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|cfFontName
argument_list|)
expr_stmt|;
name|familyName
operator|=
name|cfFontName
expr_stmt|;
name|quint16
name|macStyle
init|=
literal|0
decl_stmt|;
block|{
name|uchar
name|data
index|[
literal|4
index|]
decl_stmt|;
name|ByteCount
name|len
init|=
literal|4
decl_stmt|;
if|if
condition|(
name|ATSFontGetTable
argument_list|(
name|atsFont
argument_list|,
name|MAKE_TAG
argument_list|(
literal|'h'
argument_list|,
literal|'e'
argument_list|,
literal|'a'
argument_list|,
literal|'d'
argument_list|)
argument_list|,
literal|44
argument_list|,
literal|4
argument_list|,
operator|&
name|data
argument_list|,
operator|&
name|len
argument_list|)
operator|==
name|noErr
condition|)
name|macStyle
operator|=
name|qFromBigEndian
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|macStyle
operator|&
literal|1
condition|)
name|styleKey
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
if|if
condition|(
name|macStyle
operator|&
literal|2
condition|)
name|styleKey
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
block|}
name|QtFontFamily
modifier|*
name|family
init|=
name|db
operator|->
name|family
argument_list|(
name|familyName
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QtFontFoundry
modifier|*
name|foundry
init|=
name|family
operator|->
name|foundry
argument_list|(
name|QString
argument_list|()
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|QtFontStyle
modifier|*
name|style
init|=
name|foundry
operator|->
name|style
argument_list|(
name|styleKey
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|style
operator|->
name|pixelSize
argument_list|(
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|style
operator|->
name|smoothScalable
operator|=
literal|true
expr_stmt|;
name|initWritingSystems
argument_list|(
name|family
argument_list|,
name|atsFont
argument_list|)
expr_stmt|;
block|}
name|FMDisposeFontIterator
argument_list|(
operator|&
name|it
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
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
name|initializeDb
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|styleHint
specifier|static
specifier|const
name|char
modifier|*
name|styleHint
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|request
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|stylehint
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|request
operator|.
name|styleHint
condition|)
block|{
case|case
name|QFont
operator|::
name|SansSerif
case|:
name|stylehint
operator|=
literal|"Arial"
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|Serif
case|:
name|stylehint
operator|=
literal|"Times New Roman"
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|TypeWriter
case|:
name|stylehint
operator|=
literal|"Courier New"
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|request
operator|.
name|fixedPitch
condition|)
name|stylehint
operator|=
literal|"Courier New"
expr_stmt|;
break|break;
block|}
return|return
name|stylehint
return|;
block|}
end_function
begin_function
DECL|function|weightToFloat
specifier|static
specifier|inline
name|float
name|weightToFloat
parameter_list|(
name|unsigned
name|int
name|weight
parameter_list|)
block|{
return|return
operator|(
name|weight
operator|-
literal|50
operator|)
operator|/
literal|100.0
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
comment|// sanity checks
if|if
condition|(
operator|!
name|qApp
condition|)
name|qWarning
argument_list|(
literal|"QFont: Must construct a QApplication before a QFont"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|script
operator|>=
literal|0
operator|&&
name|script
operator|<
name|QUnicodeTables
operator|::
name|ScriptCount
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|QFontDef
name|req
init|=
name|d
operator|->
name|request
decl_stmt|;
name|req
operator|.
name|pixelSize
operator|=
name|qt_mac_pixelsize
argument_list|(
name|req
argument_list|,
name|d
operator|->
name|dpi
argument_list|)
expr_stmt|;
comment|// set the point size to 0 to get better caching
name|req
operator|.
name|pointSize
operator|=
literal|0
expr_stmt|;
name|QFontCache
operator|::
name|Key
name|key
init|=
name|QFontCache
operator|::
name|Key
argument_list|(
name|req
argument_list|,
name|QUnicodeTables
operator|::
name|Common
argument_list|,
name|d
operator|->
name|screen
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|engineData
operator|=
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|findEngineData
argument_list|(
name|key
argument_list|)
operator|)
condition|)
block|{
name|d
operator|->
name|engineData
operator|=
operator|new
name|QFontEngineData
expr_stmt|;
name|QFontCache
operator|::
name|instance
argument_list|()
operator|->
name|insertEngineData
argument_list|(
name|key
argument_list|,
name|d
operator|->
name|engineData
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|engineData
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
if|if
condition|(
name|d
operator|->
name|engineData
operator|->
name|engine
condition|)
comment|// already loaded
return|return;
comment|// set it to the actual pointsize, so QFontInfo will do the right thing
name|req
operator|.
name|pointSize
operator|=
name|qRound
argument_list|(
name|qt_mac_pointsize
argument_list|(
name|d
operator|->
name|request
argument_list|,
name|d
operator|->
name|dpi
argument_list|)
argument_list|)
expr_stmt|;
name|QFontEngine
modifier|*
name|e
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
name|e
operator|&&
name|qt_enable_test_font
operator|&&
name|req
operator|.
name|family
operator|==
name|QLatin1String
argument_list|(
literal|"__Qt__Box__Engine__"
argument_list|)
condition|)
block|{
name|e
operator|=
operator|new
name|QTestFontEngine
argument_list|(
name|req
operator|.
name|pixelSize
argument_list|)
expr_stmt|;
name|e
operator|->
name|fontDef
operator|=
name|req
expr_stmt|;
block|}
if|if
condition|(
name|e
condition|)
block|{
name|e
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|d
operator|->
name|engineData
operator|->
name|engine
operator|=
name|e
expr_stmt|;
return|return;
comment|// the font info and fontdef should already be filled
block|}
comment|//find the font
name|QStringList
name|family_list
init|=
name|familyList
argument_list|(
name|req
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|stylehint
init|=
name|styleHint
argument_list|(
name|req
argument_list|)
decl_stmt|;
if|if
condition|(
name|stylehint
condition|)
name|family_list
operator|<<
name|QLatin1String
argument_list|(
name|stylehint
argument_list|)
expr_stmt|;
comment|// add QFont::defaultFamily() to the list, for compatibility with
comment|// previous versions
name|family_list
operator|<<
name|QApplication
operator|::
name|font
argument_list|()
operator|.
name|defaultFamily
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_MAC_USE_COCOA
argument_list|)
name|QCFString
name|fontName
init|=
name|NULL
decl_stmt|,
name|familyName
init|=
name|NULL
decl_stmt|;
else|#
directive|else
name|ATSFontFamilyRef
name|familyRef
init|=
literal|0
decl_stmt|;
name|ATSFontRef
name|fontRef
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
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
operator|!
name|db
operator|->
name|count
condition|)
name|initializeDb
argument_list|()
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
name|family_list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|db
operator|->
name|count
condition|;
operator|++
name|k
control|)
block|{
if|if
condition|(
name|db
operator|->
name|families
index|[
name|k
index|]
operator|->
name|name
operator|.
name|compare
argument_list|(
name|family_list
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
block|{
name|QByteArray
name|family_name
init|=
name|db
operator|->
name|families
index|[
name|k
index|]
operator|->
name|name
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_MAC_USE_COCOA
argument_list|)
name|QCFType
argument_list|<
name|CTFontRef
argument_list|>
name|ctFont
init|=
name|CTFontCreateWithName
argument_list|(
name|QCFString
argument_list|(
name|db
operator|->
name|families
index|[
name|k
index|]
operator|->
name|name
argument_list|)
argument_list|,
literal|12
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctFont
condition|)
block|{
name|fontName
operator|=
name|CTFontCopyFullName
argument_list|(
name|ctFont
argument_list|)
expr_stmt|;
name|familyName
operator|=
name|CTFontCopyFamilyName
argument_list|(
name|ctFont
argument_list|)
expr_stmt|;
goto|goto
name|FamilyFound
goto|;
block|}
else|#
directive|else
name|familyRef
operator|=
name|ATSFontFamilyFindFromName
argument_list|(
name|QCFString
argument_list|(
name|db
operator|->
name|families
index|[
name|k
index|]
operator|->
name|name
argument_list|)
argument_list|,
name|kATSOptionFlagsDefault
argument_list|)
expr_stmt|;
if|if
condition|(
name|familyRef
condition|)
block|{
name|fontRef
operator|=
name|ATSFontFindFromName
argument_list|(
name|QCFString
argument_list|(
name|db
operator|->
name|families
index|[
name|k
index|]
operator|->
name|name
argument_list|)
argument_list|,
name|kATSOptionFlagsDefault
argument_list|)
expr_stmt|;
goto|goto
name|FamilyFound
goto|;
block|}
endif|#
directive|endif
block|}
block|}
block|}
name|FamilyFound
label|:
comment|//fill in the engine's font definition
name|QFontDef
name|fontDef
init|=
name|d
operator|->
name|request
decl_stmt|;
comment|//copy..
if|if
condition|(
name|fontDef
operator|.
name|pointSize
operator|<
literal|0
condition|)
name|fontDef
operator|.
name|pointSize
operator|=
name|qt_mac_pointsize
argument_list|(
name|fontDef
argument_list|,
name|d
operator|->
name|dpi
argument_list|)
expr_stmt|;
else|else
name|fontDef
operator|.
name|pixelSize
operator|=
name|qt_mac_pixelsize
argument_list|(
name|fontDef
argument_list|,
name|d
operator|->
name|dpi
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
name|fontDef
operator|.
name|family
operator|=
name|familyName
expr_stmt|;
name|QFontEngine
modifier|*
name|engine
init|=
operator|new
name|QCoreTextFontEngineMulti
argument_list|(
name|fontName
argument_list|,
name|fontDef
argument_list|,
name|d
operator|->
name|kerning
argument_list|)
decl_stmt|;
else|#
directive|else
name|QCFString
name|actualName
decl_stmt|;
if|if
condition|(
name|ATSFontFamilyGetName
argument_list|(
name|familyRef
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|actualName
argument_list|)
operator|==
name|noErr
condition|)
name|fontDef
operator|.
name|family
operator|=
name|actualName
expr_stmt|;
name|QFontEngine
modifier|*
name|engine
init|=
operator|new
name|QFontEngineMacMulti
argument_list|(
name|familyRef
argument_list|,
name|fontRef
argument_list|,
name|fontDef
argument_list|,
name|d
operator|->
name|kerning
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|d
operator|->
name|engineData
operator|->
name|engine
operator|=
name|engine
expr_stmt|;
name|engine
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
comment|//a ref for the engineData->engine
name|QFontCache
operator|::
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
name|ATSFontContainerRef
name|handle
decl_stmt|;
name|OSStatus
name|e
init|=
name|noErr
decl_stmt|;
if|if
condition|(
name|fnt
operator|->
name|data
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|#
directive|if
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_5
operator|)
if|if
condition|(
name|QSysInfo
operator|::
name|MacintoshVersion
operator|>=
name|QSysInfo
operator|::
name|MV_10_5
condition|)
block|{
specifier|extern
name|OSErr
name|qt_mac_create_fsref
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|FSRef
operator|*
argument_list|)
decl_stmt|;
comment|// qglobal.cpp
name|FSRef
name|ref
decl_stmt|;
if|if
condition|(
name|qt_mac_create_fsref
argument_list|(
name|fnt
operator|->
name|fileName
argument_list|,
operator|&
name|ref
argument_list|)
operator|!=
name|noErr
condition|)
return|return;
name|ATSFontActivateFromFileReference
argument_list|(
operator|&
name|ref
argument_list|,
name|kATSFontContextLocal
argument_list|,
name|kATSFontFormatUnspecified
argument_list|,
literal|0
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|handle
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
ifndef|#
directive|ifndef
name|Q_WS_MAC64
specifier|extern
name|Q_CORE_EXPORT
name|OSErr
name|qt_mac_create_fsspec
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|FSSpec
operator|*
argument_list|)
decl_stmt|;
comment|// global.cpp
name|FSSpec
name|spec
decl_stmt|;
if|if
condition|(
name|qt_mac_create_fsspec
argument_list|(
name|fnt
operator|->
name|fileName
argument_list|,
operator|&
name|spec
argument_list|)
operator|!=
name|noErr
condition|)
return|return;
name|e
operator|=
name|ATSFontActivateFromFileSpecification
argument_list|(
operator|&
name|spec
argument_list|,
name|kATSFontContextLocal
argument_list|,
name|kATSFontFormatUnspecified
argument_list|,
literal|0
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|handle
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
else|else
block|{
name|e
operator|=
name|ATSFontActivateFromMemory
argument_list|(
operator|(
name|void
operator|*
operator|)
name|fnt
operator|->
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|fnt
operator|->
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|kATSFontContextLocal
argument_list|,
name|kATSFontFormatUnspecified
argument_list|,
literal|0
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|handle
argument_list|)
expr_stmt|;
name|fnt
operator|->
name|data
operator|=
name|QByteArray
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|e
operator|!=
name|noErr
condition|)
return|return;
name|ItemCount
name|fontCount
init|=
literal|0
decl_stmt|;
name|e
operator|=
name|ATSFontFindFromContainer
argument_list|(
name|handle
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|fontCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|!=
name|noErr
condition|)
return|return;
name|QVarLengthArray
argument_list|<
name|ATSFontRef
argument_list|>
name|containedFonts
argument_list|(
name|fontCount
argument_list|)
decl_stmt|;
name|e
operator|=
name|ATSFontFindFromContainer
argument_list|(
name|handle
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
name|fontCount
argument_list|,
name|containedFonts
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|fontCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|!=
name|noErr
condition|)
return|return;
name|fnt
operator|->
name|families
operator|.
name|clear
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_MAC_USE_COCOA
argument_list|)
comment|// Make sure that the family name set on the font matches what
comment|// kCTFontFamilyNameAttribute returns in initializeDb().
comment|// So far the best solution seems find the installed font
comment|// using CoreText and get the family name from it.
comment|// (ATSFontFamilyGetName appears to be the correct API, but also
comment|// returns the font display name.)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|containedFonts
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QCFString
name|fontPostScriptName
decl_stmt|;
name|ATSFontGetPostScriptName
argument_list|(
name|containedFonts
index|[
name|i
index|]
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|fontPostScriptName
argument_list|)
expr_stmt|;
name|QCFType
argument_list|<
name|CTFontDescriptorRef
argument_list|>
name|font
init|=
name|CTFontDescriptorCreateWithNameAndSize
argument_list|(
name|fontPostScriptName
argument_list|,
literal|14
argument_list|)
decl_stmt|;
name|QCFString
name|familyName
init|=
operator|(
name|CFStringRef
operator|)
name|CTFontDescriptorCopyAttribute
argument_list|(
name|font
argument_list|,
name|kCTFontFamilyNameAttribute
argument_list|)
decl_stmt|;
name|fnt
operator|->
name|families
operator|.
name|append
argument_list|(
name|familyName
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|containedFonts
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QCFString
name|family
decl_stmt|;
name|ATSFontGetName
argument_list|(
name|containedFonts
index|[
name|i
index|]
argument_list|,
name|kATSOptionFlagsDefault
argument_list|,
operator|&
name|family
argument_list|)
expr_stmt|;
name|fnt
operator|->
name|families
operator|.
name|append
argument_list|(
name|family
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|fnt
operator|->
name|handle
operator|=
name|handle
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
name|OSStatus
name|e
init|=
name|ATSFontDeactivate
argument_list|(
name|db
operator|->
name|applicationFonts
operator|.
name|at
argument_list|(
name|handle
argument_list|)
operator|.
name|handle
argument_list|,
comment|/*iRefCon=*/
literal|0
argument_list|,
name|kATSOptionFlagsDefault
argument_list|)
decl_stmt|;
if|if
condition|(
name|e
operator|!=
name|noErr
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
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|removeApplicationFont
argument_list|(
name|i
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
