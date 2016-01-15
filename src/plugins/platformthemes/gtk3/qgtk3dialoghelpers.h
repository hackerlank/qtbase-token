begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGTK3DIALOGHELPERS_H
end_ifndef
begin_define
DECL|macro|QGTK3DIALOGHELPERS_H
define|#
directive|define
name|QGTK3DIALOGHELPERS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_typedef
DECL|typedef|GtkDialog
typedef|typedef
name|struct
name|_GtkDialog
name|GtkDialog
typedef|;
end_typedef
begin_typedef
DECL|typedef|GtkFileFilter
typedef|typedef
name|struct
name|_GtkFileFilter
name|GtkFileFilter
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGtk3Dialog
name|class
name|QGtk3Dialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk3ColorDialogHelper
range|:
name|public
name|QPlatformColorDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk3ColorDialogHelper
argument_list|()
block|;
operator|~
name|QGtk3ColorDialogHelper
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags flags
argument_list|,
argument|Qt::WindowModality modality
argument_list|,
argument|QWindow *parent
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|exec
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|hide
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCurrentColor
argument_list|(
argument|const QColor&color
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QColor
name|currentColor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
specifier|static
name|void
name|onColorChanged
argument_list|(
name|QGtk3ColorDialogHelper
operator|*
name|helper
argument_list|)
block|;
name|void
name|applyOptions
argument_list|()
block|;
name|QScopedPointer
operator|<
name|QGtk3Dialog
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk3FileDialogHelper
range|:
name|public
name|QPlatformFileDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk3FileDialogHelper
argument_list|()
block|;
operator|~
name|QGtk3FileDialogHelper
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags flags
argument_list|,
argument|Qt::WindowModality modality
argument_list|,
argument|QWindow *parent
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|exec
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|hide
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|defaultNameFilterDisables
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setDirectory
argument_list|(
argument|const QUrl&directory
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QUrl
name|directory
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|selectFile
argument_list|(
argument|const QUrl&filename
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QUrl
operator|>
name|selectedFiles
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFilter
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|selectNameFilter
argument_list|(
argument|const QString&filter
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QString
name|selectedNameFilter
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
specifier|static
name|void
name|onSelectionChanged
argument_list|(
name|GtkDialog
operator|*
name|dialog
argument_list|,
name|QGtk3FileDialogHelper
operator|*
name|helper
argument_list|)
block|;
specifier|static
name|void
name|onCurrentFolderChanged
argument_list|(
name|QGtk3FileDialogHelper
operator|*
name|helper
argument_list|)
block|;
name|void
name|applyOptions
argument_list|()
block|;
name|void
name|setNameFilters
argument_list|(
specifier|const
name|QStringList
operator|&
name|filters
argument_list|)
block|;
name|QUrl
name|_dir
block|;
name|QList
operator|<
name|QUrl
operator|>
name|_selection
block|;
name|QHash
operator|<
name|QString
block|,
name|GtkFileFilter
operator|*
operator|>
name|_filters
block|;
name|QHash
operator|<
name|GtkFileFilter
operator|*
block|,
name|QString
operator|>
name|_filterNames
block|;
name|QScopedPointer
operator|<
name|QGtk3Dialog
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk3FontDialogHelper
range|:
name|public
name|QPlatformFontDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk3FontDialogHelper
argument_list|()
block|;
operator|~
name|QGtk3FontDialogHelper
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags flags
argument_list|,
argument|Qt::WindowModality modality
argument_list|,
argument|QWindow *parent
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|exec
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|hide
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCurrentFont
argument_list|(
argument|const QFont&font
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFont
name|currentFont
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
name|void
name|applyOptions
argument_list|()
block|;
name|QScopedPointer
operator|<
name|QGtk3Dialog
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGTK3DIALOGHELPERS_H
end_comment
end_unit
