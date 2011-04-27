begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRIDLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRIDLAYOUT_H
define|#
directive|define
name|QGRIDLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qlayout.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_INCLUDE_COMPAT
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QGridLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGridLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGridLayout
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing
argument_list|)
name|public
operator|:
name|explicit
name|QGridLayout
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|QGridLayout
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT_CONSTRUCTOR
name|QGridLayout
argument_list|(
argument|QWidget *parent
argument_list|,
argument|int nRows
argument_list|,
argument|int nCols =
literal|1
argument_list|,
argument|int border =
literal|0
argument_list|,
argument|int spacing = -
literal|1
argument_list|,
argument|const char *name =
literal|0
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QGridLayout
argument_list|(
argument|int nRows
argument_list|,
argument|int nCols =
literal|1
argument_list|,
argument|int spacing = -
literal|1
argument_list|,
argument|const char *name =
literal|0
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QGridLayout
argument_list|(
argument|QLayout *parentLayout
argument_list|,
argument|int nRows =
literal|1
argument_list|,
argument|int nCols =
literal|1
argument_list|,
argument|int spacing = -
literal|1
argument_list|,
argument|const char *name =
literal|0
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QGridLayout
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
block|;
name|void
name|setHorizontalSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|horizontalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setVerticalSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|verticalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setRowStretch
argument_list|(
argument|int row
argument_list|,
argument|int stretch
argument_list|)
block|;
name|void
name|setColumnStretch
argument_list|(
argument|int column
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|rowStretch
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|columnStretch
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setRowMinimumHeight
argument_list|(
argument|int row
argument_list|,
argument|int minSize
argument_list|)
block|;
name|void
name|setColumnMinimumWidth
argument_list|(
argument|int column
argument_list|,
argument|int minSize
argument_list|)
block|;
name|int
name|rowMinimumHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|columnMinimumWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|int
name|rowCount
argument_list|()
specifier|const
block|;
name|QRect
name|cellRect
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
specifier|inline
name|QT3_SUPPORT
name|QRect
name|cellGeometry
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|{
return|return
name|cellRect
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
return|;
block|}
endif|#
directive|endif
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|;
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|minimumHeightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|;
name|void
name|invalidate
argument_list|()
block|;
specifier|inline
name|void
name|addWidget
argument_list|(
argument|QWidget *w
argument_list|)
block|{
name|QLayout
operator|::
name|addWidget
argument_list|(
name|w
argument_list|)
block|; }
name|void
name|addWidget
argument_list|(
argument|QWidget *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|Qt::Alignment =
literal|0
argument_list|)
block|;
name|void
name|addWidget
argument_list|(
argument|QWidget *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|,
argument|Qt::Alignment =
literal|0
argument_list|)
block|;
name|void
name|addLayout
argument_list|(
argument|QLayout *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|Qt::Alignment =
literal|0
argument_list|)
block|;
name|void
name|addLayout
argument_list|(
argument|QLayout *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|,
argument|Qt::Alignment =
literal|0
argument_list|)
block|;
name|void
name|setOriginCorner
argument_list|(
name|Qt
operator|::
name|Corner
argument_list|)
block|;
name|Qt
operator|::
name|Corner
name|originCorner
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
specifier|inline
name|QT3_SUPPORT
name|void
name|setOrigin
argument_list|(
argument|Qt::Corner corner
argument_list|)
block|{
name|setOriginCorner
argument_list|(
name|corner
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|Qt
operator|::
name|Corner
name|origin
argument_list|()
specifier|const
block|{
return|return
name|originCorner
argument_list|()
return|;
block|}
endif|#
directive|endif
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QLayoutItem
operator|*
name|itemAtPosition
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|void
name|addItem
argument_list|(
argument|QLayoutItem *item
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan =
literal|1
argument_list|,
argument|int columnSpan =
literal|1
argument_list|,
argument|Qt::Alignment =
literal|0
argument_list|)
block|;
name|void
name|setDefaultPositioning
argument_list|(
argument|int n
argument_list|,
argument|Qt::Orientation orient
argument_list|)
block|;
name|void
name|getItemPosition
argument_list|(
argument|int idx
argument_list|,
argument|int *row
argument_list|,
argument|int *column
argument_list|,
argument|int *rowSpan
argument_list|,
argument|int *columnSpan
argument_list|)
block|;
name|protected
operator|:
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|QT3_SUPPORT
name|bool
name|findWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
name|int
operator|*
name|r
argument_list|,
name|int
operator|*
name|c
argument_list|)
block|;
endif|#
directive|endif
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGridLayout
argument_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT
name|void
name|expand
argument_list|(
argument|int rows
argument_list|,
argument|int cols
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|void
name|addRowSpacing
argument_list|(
argument|int row
argument_list|,
argument|int minsize
argument_list|)
block|{
name|addItem
argument_list|(
argument|new QSpacerItem(
literal|0
argument|,minsize)
argument_list|,
argument|row
argument_list|,
literal|0
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|void
name|addColSpacing
argument_list|(
argument|int col
argument_list|,
argument|int minsize
argument_list|)
block|{
name|addItem
argument_list|(
argument|new QSpacerItem(minsize,
literal|0
argument|)
argument_list|,
literal|0
argument_list|,
argument|col
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|void
name|addMultiCellWidget
argument_list|(
argument|QWidget *w
argument_list|,
argument|int fromRow
argument_list|,
argument|int toRow
argument_list|,
argument|int fromCol
argument_list|,
argument|int toCol
argument_list|,
argument|Qt::Alignment _align =
literal|0
argument_list|)
block|{
name|addWidget
argument_list|(
name|w
argument_list|,
name|fromRow
argument_list|,
name|fromCol
argument_list|,
operator|(
name|toRow
operator|<
literal|0
operator|)
operator|?
operator|-
literal|1
operator|:
name|toRow
operator|-
name|fromRow
operator|+
literal|1
argument_list|,
operator|(
name|toCol
operator|<
literal|0
operator|)
operator|?
operator|-
literal|1
operator|:
name|toCol
operator|-
name|fromCol
operator|+
literal|1
argument_list|,
name|_align
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|void
name|addMultiCell
argument_list|(
argument|QLayoutItem *l
argument_list|,
argument|int fromRow
argument_list|,
argument|int toRow
argument_list|,
argument|int fromCol
argument_list|,
argument|int toCol
argument_list|,
argument|Qt::Alignment _align =
literal|0
argument_list|)
block|{
name|addItem
argument_list|(
name|l
argument_list|,
name|fromRow
argument_list|,
name|fromCol
argument_list|,
operator|(
name|toRow
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
name|toRow
operator|-
name|fromRow
operator|+
literal|1
argument_list|,
operator|(
name|toCol
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
name|toCol
operator|-
name|fromCol
operator|+
literal|1
argument_list|,
name|_align
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|void
name|addMultiCellLayout
argument_list|(
argument|QLayout *layout
argument_list|,
argument|int fromRow
argument_list|,
argument|int toRow
argument_list|,
argument|int fromCol
argument_list|,
argument|int toCol
argument_list|,
argument|Qt::Alignment _align =
literal|0
argument_list|)
block|{
name|addLayout
argument_list|(
name|layout
argument_list|,
name|fromRow
argument_list|,
name|fromCol
argument_list|,
operator|(
name|toRow
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
name|toRow
operator|-
name|fromRow
operator|+
literal|1
argument_list|,
operator|(
name|toCol
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
name|toCol
operator|-
name|fromCol
operator|+
literal|1
argument_list|,
name|_align
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|int
name|numRows
argument_list|()
specifier|const
block|{
return|return
name|rowCount
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|numCols
argument_list|()
specifier|const
block|{
return|return
name|columnCount
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|setColStretch
argument_list|(
argument|int col
argument_list|,
argument|int stretch
argument_list|)
block|{
name|setColumnStretch
argument_list|(
name|col
argument_list|,
name|stretch
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|int
name|colStretch
argument_list|(
argument|int col
argument_list|)
specifier|const
block|{
return|return
name|columnStretch
argument_list|(
name|col
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|setColSpacing
argument_list|(
argument|int col
argument_list|,
argument|int minSize
argument_list|)
block|{
name|setColumnMinimumWidth
argument_list|(
name|col
argument_list|,
name|minSize
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|int
name|colSpacing
argument_list|(
argument|int col
argument_list|)
specifier|const
block|{
return|return
name|columnMinimumWidth
argument_list|(
name|col
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|setRowSpacing
argument_list|(
argument|int row
argument_list|,
argument|int minSize
argument_list|)
block|{
name|setRowMinimumHeight
argument_list|(
name|row
argument_list|,
name|minSize
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|int
name|rowSpacing
argument_list|(
argument|int row
argument_list|)
specifier|const
block|{
return|return
name|rowMinimumHeight
argument_list|(
name|row
argument_list|)
return|;
block|}
endif|#
directive|endif
expr|}
block|;
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRIDLAYOUT_H
end_comment
end_unit
