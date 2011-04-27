begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMSCREEN_H
end_ifndef
begin_define
DECL|macro|QPLATFORMSCREEN_H
define|#
directive|define
name|QPLATFORMSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|Q_GUI_EXPORT
name|QPlatformScreen
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
operator|~
name|QPlatformScreen
argument_list|()
block|{ }
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QRect
name|availableGeometry
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
return|;
block|}
name|virtual
name|int
name|depth
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QSize
name|physicalSize
argument_list|()
specifier|const
block|;
comment|//jl: should setDirty be removed.
name|virtual
name|void
name|setDirty
argument_list|(
argument|const QRect&
argument_list|)
block|{}
name|virtual
name|QWidget
operator|*
name|topLevelAt
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|;
comment|//jl: should this function be in QPlatformIntegration
comment|//jl: maybe screenForWidget is a better name?
specifier|static
name|QPlatformScreen
operator|*
name|platformScreenForWidget
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMSCREEN_H
end_comment
end_unit
