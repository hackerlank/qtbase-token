begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPICTUREFORMATPLUGIN_H
end_ifndef
begin_define
DECL|macro|QPICTUREFORMATPLUGIN_H
define|#
directive|define
name|QPICTUREFORMATPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PICTURE
argument_list|)
name|class
name|QPicture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QFactoryInterface
name|struct
name|Q_GUI_EXPORT
name|QPictureFormatInterface
range|:
name|public
name|QFactoryInterface
block|{
name|virtual
name|bool
name|loadPicture
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
specifier|const
name|QString
operator|&
name|filename
argument_list|,
name|QPicture
operator|*
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|savePicture
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|QPicture
operator|&
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|installIOHandler
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QPictureFormatInterface_iid
define|#
directive|define
name|QPictureFormatInterface_iid
value|"com.trolltech.Qt.QPictureFormatInterface"
end_define
begin_macro
DECL|function|Q_DECLARE_INTERFACE
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QPictureFormatInterface
argument_list|,
argument|QPictureFormatInterface_iid
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPictureFormatPlugin
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPictureFormatInterface
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QPictureFormatInterface
operator|:
name|QFactoryInterface
argument_list|)
name|public
range|:
name|explicit
name|QPictureFormatPlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QPictureFormatPlugin
argument_list|()
expr_stmt|;
name|virtual
name|QStringList
name|keys
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|loadPicture
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QPicture
modifier|*
name|pic
parameter_list|)
function_decl|;
name|virtual
name|bool
name|savePicture
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
specifier|const
name|QPicture
modifier|&
name|pic
parameter_list|)
function_decl|;
name|virtual
name|bool
name|installIOHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY || QT_NO_PICTURE
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPICTUREFORMATPLUGIN_H
end_comment
end_unit
