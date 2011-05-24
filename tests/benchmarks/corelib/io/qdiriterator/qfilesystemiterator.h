begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMITERATOR_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMITERATOR_H
define|#
directive|define
name|QFILESYSTEMITERATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QFileSystemIteratorPrivate
decl_stmt|;
name|class
comment|//Q_CORE_EXPORT
name|QFileSystemIterator
decl_stmt|{ public:     enum IteratorFlag
block|{
name|NoIteratorFlags
operator|=
literal|0x0
operator|,
name|FollowSymlinks
operator|=
literal|0x1
operator|,
name|Subdirectories
operator|=
literal|0x2
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|IteratorFlags
argument_list|,
argument|IteratorFlag
argument_list|)
end_macro
begin_macro
name|QFileSystemIterator
argument_list|(
argument|const QDir&dir
argument_list|,
argument|IteratorFlags flags = NoIteratorFlags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QFileSystemIterator
argument_list|(
argument|const QString&path
argument_list|,
argument|IteratorFlags flags = NoIteratorFlags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QFileSystemIterator
argument_list|(
argument|const QString&path
argument_list|,
argument|QDir::Filters filter
argument_list|,
argument|IteratorFlags flags = NoIteratorFlags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QFileSystemIterator
argument_list|(
argument|const QString&path
argument_list|,
argument|const QStringList&nameFilters
argument_list|,
argument|QDir::Filters filters = QDir::NoFilter
argument_list|,
argument|IteratorFlags flags = NoIteratorFlags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QFileSystemIterator
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|next
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|filePath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QFileInfo
name|fileInfo
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFileSystemIterator
argument_list|)
end_macro
begin_decl_stmt
name|QFileSystemIteratorPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QDir
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFileSystemIterator::IteratorFlags
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
