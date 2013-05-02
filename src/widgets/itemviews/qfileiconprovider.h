begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEICONPROVIDER_H
end_ifndef
begin_define
DECL|macro|QFILEICONPROVIDER_H
define|#
directive|define
name|QFILEICONPROVIDER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileIconProviderPrivate
name|class
name|QFileIconProviderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFileIconProvider
block|{
name|public
label|:
name|QFileIconProvider
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QFileIconProvider
argument_list|()
expr_stmt|;
enum|enum
name|IconType
block|{
name|Computer
block|,
name|Desktop
block|,
name|Trashcan
block|,
name|Network
block|,
name|Drive
block|,
name|Folder
block|,
name|File
block|}
enum|;
enum|enum
name|Option
block|{
name|DontUseCustomDirectoryIcons
init|=
literal|0x00000001
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
name|virtual
name|QIcon
name|icon
argument_list|(
name|IconType
name|type
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QIcon
name|icon
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|info
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QString
name|type
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|info
argument_list|)
decl|const
decl_stmt|;
name|void
name|setOptions
parameter_list|(
name|Options
name|options
parameter_list|)
function_decl|;
name|Options
name|options
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFileIconProvider
argument_list|)
name|QScopedPointer
operator|<
name|QFileIconProviderPrivate
operator|>
name|d_ptr
expr_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QFileIconProvider
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFileIconProvider::Options
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEICONPROVIDER_H
end_comment
end_unit
