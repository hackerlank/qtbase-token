begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Contributed by James Su<suzhe@gnuchina.org>
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGB18030CODEC_P_H
end_ifndef
begin_define
DECL|macro|QGB18030CODEC_P_H
define|#
directive|define
name|QGB18030CODEC_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
file|<QtCore/qtextcodec.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|class
name|QGb18030Codec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
name|QGb18030Codec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|{
return|return
literal|"GB18030"
return|;
block|}
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|{
return|return
name|QList
operator|<
name|QByteArray
operator|>
operator|(
operator|)
return|;
block|}
specifier|static
name|int
name|_mibEnum
argument_list|()
block|{
return|return
literal|114
return|;
block|}
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
block|{
return|return
name|_aliases
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGbkCodec
range|:
name|public
name|QGb18030Codec
block|{
name|public
operator|:
name|QGbkCodec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|;
specifier|static
name|int
name|_mibEnum
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
block|{
return|return
name|_aliases
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGb2312Codec
range|:
name|public
name|QGb18030Codec
block|{
name|public
operator|:
name|QGb2312Codec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|{
return|return
name|QList
operator|<
name|QByteArray
operator|>
operator|(
operator|)
return|;
block|}
specifier|static
name|int
name|_mibEnum
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_decl_stmt
name|class
name|QFontGb2312Codec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
name|QFontGb2312Codec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|{
return|return
name|QList
operator|<
name|QByteArray
operator|>
operator|(
operator|)
return|;
block|}
specifier|static
name|int
name|_mibEnum
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontGbkCodec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
name|QFontGbkCodec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|{
return|return
name|QList
operator|<
name|QByteArray
operator|>
operator|(
operator|)
return|;
block|}
specifier|static
name|int
name|_mibEnum
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
block|{
return|return
name|_aliases
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFontGb18030_0Codec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
name|QFontGb18030_0Codec
argument_list|()
block|;
specifier|static
name|QByteArray
name|_name
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|_aliases
argument_list|()
block|{
return|return
name|QList
operator|<
name|QByteArray
operator|>
operator|(
operator|)
return|;
block|}
specifier|static
name|int
name|_mibEnum
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
argument_list|()
return|;
block|}
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
block|{
return|return
name|_aliases
argument_list|()
return|;
block|}
name|int
name|mibEnum
argument_list|()
specifier|const
block|{
return|return
name|_mibEnum
argument_list|()
return|;
block|}
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
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_UNIX
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGB18030CODEC_P_H
end_comment
end_unit
