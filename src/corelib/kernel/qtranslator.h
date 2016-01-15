begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRANSLATOR_H
end_ifndef
begin_define
DECL|macro|QTRANSLATOR_H
define|#
directive|define
name|QTRANSLATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
DECL|variable|QLocale
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTranslatorPrivate
name|class
name|QTranslatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTranslator
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QTranslator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QTranslator
argument_list|()
block|;
name|virtual
name|QString
name|translate
argument_list|(
argument|const char *context
argument_list|,
argument|const char *sourceText
argument_list|,
argument|const char *disambiguation = Q_NULLPTR
argument_list|,
argument|int n = -
literal|1
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|search_delimiters
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|suffix
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|,
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|QString
operator|&
name|prefix
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|suffix
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|load
argument_list|(
argument|const uchar *data
argument_list|,
argument|int len
argument_list|,
argument|const QString&directory = QString()
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTranslator
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTranslator
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TRANSLATION
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTRANSLATOR_H
end_comment
end_unit
