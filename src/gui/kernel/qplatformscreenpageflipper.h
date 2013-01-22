begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMSCREENPAGEFLIPPER_H
end_ifndef
begin_define
DECL|macro|QPLATFORMSCREENPAGEFLIPPER_H
define|#
directive|define
name|QPLATFORMSCREENPAGEFLIPPER_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QPlatformScreenBuffer
block|{
name|public
label|:
name|QPlatformScreenBuffer
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QPlatformScreenBuffer
argument_list|()
expr_stmt|;
name|bool
name|isDestroyed
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReady
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|aboutToBeDisplayed
parameter_list|()
function_decl|;
name|virtual
name|void
name|displayed
parameter_list|()
function_decl|;
name|virtual
name|void
name|release
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
operator|*
name|handle
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|bool
name|m_destroyed
decl_stmt|;
name|bool
name|m_ready
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformScreenPageFlipper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QPlatformScreenPageFlipper
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
name|bool
name|displayBuffer
argument_list|(
name|QPlatformScreenBuffer
operator|*
argument_list|)
operator|=
literal|0
block|;
name|Q_SIGNALS
operator|:
name|void
name|bufferDisplayed
argument_list|(
name|QPlatformScreenBuffer
operator|*
argument_list|)
block|;
name|void
name|bufferReleased
argument_list|(
name|QPlatformScreenBuffer
operator|*
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
comment|// QPLATFORMSCREENPAGEFLIPPER_H
end_comment
end_unit
