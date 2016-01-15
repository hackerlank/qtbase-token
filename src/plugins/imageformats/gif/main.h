begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimageiohandler.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_IMAGEFORMAT_GIF
end_ifdef
begin_undef
DECL|macro|QT_NO_IMAGEFORMAT_GIF
undef|#
directive|undef
name|QT_NO_IMAGEFORMAT_GIF
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qgifhandler_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGifPlugin
range|:
name|public
name|QImageIOPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
argument|IID
literal|"org.qt-project.Qt.QImageIOHandlerFactoryInterface"
argument|FILE
literal|"gif.json"
argument_list|)
name|public
operator|:
name|QGifPlugin
argument_list|()
block|;
operator|~
name|QGifPlugin
argument_list|()
block|;
name|Capabilities
name|capabilities
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImageIOHandler
operator|*
name|create
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format = QByteArray()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
