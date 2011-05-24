begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
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
file|"qrawfont_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontengine_ft_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qfontengine_x11_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QFontEngineFTRawFont
class|class
name|QFontEngineFTRawFont
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
super|:
specifier|public
name|QFontEngineX11FT
else|#
directive|else
super|:
specifier|public
name|QFontEngineFT
endif|#
directive|endif
block|{
public|public:
DECL|function|QFontEngineFTRawFont
name|QFontEngineFTRawFont
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
member_init_list|:
name|QFontEngineX11FT
argument_list|(
name|fontDef
argument_list|)
else|#
directive|else
public|:
name|QFontEngineFT
parameter_list|(
name|fontDef
parameter_list|)
endif|#
directive|endif
block|{     }
DECL|function|updateFamilyNameAndStyle
name|void
name|updateFamilyNameAndStyle
parameter_list|()
block|{
name|fontDef
operator|.
name|family
operator|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|freetype
operator|->
name|face
operator|->
name|family_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_ITALIC
condition|)
name|fontDef
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|fontDef
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
block|}
DECL|function|initFromData
name|bool
name|initFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|)
block|{
name|FaceId
name|faceId
decl_stmt|;
name|faceId
operator|.
name|filename
operator|=
literal|""
expr_stmt|;
name|faceId
operator|.
name|index
operator|=
literal|0
expr_stmt|;
return|return
name|init
argument_list|(
name|faceId
argument_list|,
literal|true
argument_list|,
name|Format_None
argument_list|,
name|fontData
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|platformCleanUp
name|void
name|QRawFontPrivate
operator|::
name|platformCleanUp
parameter_list|()
block|{
comment|// Font engine handles all resources
block|}
end_function
begin_function
DECL|function|platformLoadFromData
name|void
name|QRawFontPrivate
operator|::
name|platformLoadFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|fontEngine
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QFontDef
name|fontDef
decl_stmt|;
name|fontDef
operator|.
name|pixelSize
operator|=
name|pixelSize
expr_stmt|;
name|QFontEngineFTRawFont
modifier|*
name|fe
init|=
operator|new
name|QFontEngineFTRawFont
argument_list|(
name|fontDef
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fe
operator|->
name|initFromData
argument_list|(
name|fontData
argument_list|)
condition|)
block|{
operator|delete
name|fe
expr_stmt|;
return|return;
block|}
name|fe
operator|->
name|updateFamilyNameAndStyle
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|hintingPreference
condition|)
block|{
case|case
name|QFont
operator|::
name|PreferNoHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintNone
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferFullHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintFull
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferVerticalHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintLight
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|// Leave it as it is
break|break;
block|}
name|fontEngine
operator|=
name|fe
expr_stmt|;
name|fontEngine
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
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
