begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICONVCODEC_P_H
end_ifndef
begin_define
DECL|macro|QICONVCODEC_P_H
define|#
directive|define
name|QICONVCODEC_P_H
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
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"qtextcodec.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_ICONV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_typedef
DECL|typedef|iconv_t
typedef|typedef
name|void
modifier|*
name|iconv_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<iconv.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QIconvCodec
range|:
name|public
name|QTextCodec
block|{
name|private
operator|:
name|mutable
name|QTextCodec
operator|*
name|utf16Codec
block|;
name|public
operator|:
name|QIconvCodec
argument_list|()
block|;
operator|~
name|QIconvCodec
argument_list|()
block|;
name|QString
name|convertToUnicode
argument_list|(
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
block|;
name|QByteArray
name|convertFromUnicode
argument_list|(
argument|const QChar *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
block|;
name|void
name|init
argument_list|()
specifier|const
block|;
name|iconv_t
name|createIconv_t
argument_list|(
argument|const char *to
argument_list|,
argument|const char *from
argument_list|)
specifier|const
block|;
name|class
name|IconvState
block|{
name|public
operator|:
name|IconvState
argument_list|(
argument|iconv_t x
argument_list|)
block|;
operator|~
name|IconvState
argument_list|()
block|;
name|ConverterState
name|internalState
block|;
name|char
operator|*
name|buffer
block|;
name|int
name|bufferLen
block|;
name|iconv_t
name|cd
block|;
name|char
name|array
index|[
literal|8
index|]
block|;
name|void
name|saveChars
argument_list|(
argument|const char *c
argument_list|,
argument|int count
argument_list|)
block|;     }
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
comment|// Q_OS_UNIX&& !QT_NO_ICONV&& !QT_BOOTSTRAPPED
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QICONVCODEC_P_H
end_comment
end_unit
