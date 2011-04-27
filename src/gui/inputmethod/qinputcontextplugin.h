begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Definition of QInputContextPlugin class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTCONTEXTPLUGIN_H
end_ifndef
begin_define
DECL|macro|QINPUTCONTEXTPLUGIN_H
define|#
directive|define
name|QINPUTCONTEXTPLUGIN_H
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
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
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
name|QT_NO_IM
argument_list|)
name|class
name|QInputContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputContextPluginPrivate
name|class
name|QInputContextPluginPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QFactoryInterface
name|struct
name|Q_GUI_EXPORT
name|QInputContextFactoryInterface
range|:
name|public
name|QFactoryInterface
block|{
DECL|member|key
name|virtual
name|QInputContext
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|;
DECL|member|key
name|virtual
name|QStringList
name|languages
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|;
DECL|member|key
name|virtual
name|QString
name|displayName
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|;
DECL|member|key
name|virtual
name|QString
name|description
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QInputContextFactoryInterface_iid
define|#
directive|define
name|QInputContextFactoryInterface_iid
value|"com.trolltech.Qt.QInputContextFactoryInterface"
end_define
begin_macro
DECL|function|Q_DECLARE_INTERFACE
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QInputContextFactoryInterface
argument_list|,
argument|QInputContextFactoryInterface_iid
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QInputContextPlugin
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QInputContextFactoryInterface
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QInputContextFactoryInterface
operator|:
name|QFactoryInterface
argument_list|)
name|public
range|:
name|explicit
name|QInputContextPlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QInputContextPlugin
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
name|QInputContext
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QStringList
name|languages
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|displayName
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|description
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
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
comment|// QT_NO_IM
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
comment|// QINPUTCONTEXTPLUGIN_H
end_comment
end_unit
