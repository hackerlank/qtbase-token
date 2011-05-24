begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtextcodecplugin.h>
end_include
begin_include
include|#
directive|include
file|<qtextcodec.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODECPLUGIN
end_ifndef
begin_include
include|#
directive|include
file|"qeucjpcodec.h"
end_include
begin_include
include|#
directive|include
file|"qjiscodec.h"
end_include
begin_include
include|#
directive|include
file|"qsjiscodec.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_include
include|#
directive|include
file|"qfontjpcodec.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|JPTextCodecs
class|class
name|JPTextCodecs
super|:
specifier|public
name|QTextCodecPlugin
block|{
public|public:
DECL|function|JPTextCodecs
name|JPTextCodecs
parameter_list|()
block|{}
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|names
parameter_list|()
specifier|const
function_decl|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|aliases
parameter_list|()
specifier|const
function_decl|;
name|QList
argument_list|<
name|int
argument_list|>
name|mibEnums
parameter_list|()
specifier|const
function_decl|;
name|QTextCodec
modifier|*
name|createForMib
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|QTextCodec
modifier|*
name|createForName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|names
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|JPTextCodecs
operator|::
name|names
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|+=
name|QEucJpCodec
operator|::
name|_name
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QJisCodec
operator|::
name|_name
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QSjisCodec
operator|::
name|_name
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
name|list
operator|+=
name|QFontJis0201Codec
operator|::
name|_name
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QFontJis0208Codec
operator|::
name|_name
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|JPTextCodecs
operator|::
name|aliases
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|+=
name|QEucJpCodec
operator|::
name|_aliases
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QJisCodec
operator|::
name|_aliases
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QSjisCodec
operator|::
name|_aliases
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
name|list
operator|+=
name|QFontJis0201Codec
operator|::
name|_aliases
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QFontJis0208Codec
operator|::
name|_aliases
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|mibEnums
name|QList
argument_list|<
name|int
argument_list|>
name|JPTextCodecs
operator|::
name|mibEnums
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|list
decl_stmt|;
name|list
operator|+=
name|QEucJpCodec
operator|::
name|_mibEnum
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QJisCodec
operator|::
name|_mibEnum
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QSjisCodec
operator|::
name|_mibEnum
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
name|list
operator|+=
name|QFontJis0201Codec
operator|::
name|_mibEnum
argument_list|()
expr_stmt|;
name|list
operator|+=
name|QFontJis0208Codec
operator|::
name|_mibEnum
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|createForMib
name|QTextCodec
modifier|*
name|JPTextCodecs
operator|::
name|createForMib
parameter_list|(
name|int
name|mib
parameter_list|)
block|{
if|if
condition|(
name|mib
operator|==
name|QEucJpCodec
operator|::
name|_mibEnum
argument_list|()
condition|)
return|return
operator|new
name|QEucJpCodec
return|;
if|if
condition|(
name|mib
operator|==
name|QJisCodec
operator|::
name|_mibEnum
argument_list|()
condition|)
return|return
operator|new
name|QJisCodec
return|;
if|if
condition|(
name|mib
operator|==
name|QSjisCodec
operator|::
name|_mibEnum
argument_list|()
condition|)
return|return
operator|new
name|QSjisCodec
return|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|mib
operator|==
name|QFontJis0208Codec
operator|::
name|_mibEnum
argument_list|()
condition|)
return|return
operator|new
name|QFontJis0208Codec
return|;
if|if
condition|(
name|mib
operator|==
name|QFontJis0201Codec
operator|::
name|_mibEnum
argument_list|()
condition|)
return|return
operator|new
name|QFontJis0201Codec
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createForName
name|QTextCodec
modifier|*
name|JPTextCodecs
operator|::
name|createForName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
name|QEucJpCodec
operator|::
name|_name
argument_list|()
operator|||
name|QEucJpCodec
operator|::
name|_aliases
argument_list|()
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
return|return
operator|new
name|QEucJpCodec
return|;
if|if
condition|(
name|name
operator|==
name|QJisCodec
operator|::
name|_name
argument_list|()
operator|||
name|QJisCodec
operator|::
name|_aliases
argument_list|()
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
return|return
operator|new
name|QJisCodec
return|;
if|if
condition|(
name|name
operator|==
name|QSjisCodec
operator|::
name|_name
argument_list|()
operator|||
name|QSjisCodec
operator|::
name|_aliases
argument_list|()
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
return|return
operator|new
name|QSjisCodec
return|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|name
operator|==
name|QFontJis0208Codec
operator|::
name|_name
argument_list|()
operator|||
name|QFontJis0208Codec
operator|::
name|_aliases
argument_list|()
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
return|return
operator|new
name|QFontJis0208Codec
return|;
if|if
condition|(
name|name
operator|==
name|QFontJis0201Codec
operator|::
name|_name
argument_list|()
operator|||
name|QFontJis0201Codec
operator|::
name|_aliases
argument_list|()
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
return|return
operator|new
name|QFontJis0201Codec
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_expr_stmt
DECL|variable|JPTextCodecs
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
name|JPTextCodecs
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_EXPORT_PLUGIN2
argument_list|(
name|qjpcodecs
argument_list|,
name|JPTextCodecs
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODECPLUGIN
end_comment
end_unit
