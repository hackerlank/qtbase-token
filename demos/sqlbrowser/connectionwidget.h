begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONNECTIONWIDGET_H
end_ifndef
begin_define
DECL|macro|CONNECTIONWIDGET_H
define|#
directive|define
name|CONNECTIONWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTreeWidget
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTreeWidgetItem
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QSqlDatabase
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QMenu
argument_list|)
end_macro
begin_decl_stmt
name|class
name|ConnectionWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ConnectionWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ConnectionWidget
argument_list|()
block|;
name|QSqlDatabase
name|currentDatabase
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|tableActivated
argument_list|(
specifier|const
name|QString
operator|&
name|table
argument_list|)
block|;
name|void
name|metaDataRequested
argument_list|(
specifier|const
name|QString
operator|&
name|tableName
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|refresh
argument_list|()
block|;
name|void
name|showMetaData
argument_list|()
block|;
name|void
name|on_tree_itemActivated
argument_list|(
argument|QTreeWidgetItem *item
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|on_tree_currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
name|current
argument_list|,
name|QTreeWidgetItem
operator|*
name|previous
argument_list|)
block|;
name|private
operator|:
name|void
name|setActive
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|)
block|;
name|QTreeWidget
operator|*
name|tree
block|;
name|QAction
operator|*
name|metaDataAction
block|;
name|QString
name|activeDb
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
