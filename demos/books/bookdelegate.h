begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BOOKDELEGATE_H
end_ifndef
begin_define
DECL|macro|BOOKDELEGATE_H
define|#
directive|define
name|BOOKDELEGATE_H
end_define
begin_include
include|#
directive|include
file|<QModelIndex>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_include
include|#
directive|include
file|<QSqlRelationalDelegate>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QPainter
argument_list|)
end_macro
begin_decl_stmt
name|class
name|BookDelegate
range|:
name|public
name|QSqlRelationalDelegate
block|{
name|public
operator|:
name|BookDelegate
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|editorEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
name|QAbstractItemModel
operator|*
name|model
argument_list|,
specifier|const
name|QStyleOptionViewItem
operator|&
name|option
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|QWidget
operator|*
name|createEditor
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QPixmap
name|star
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
