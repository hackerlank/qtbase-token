begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSMIME_H
end_ifndef
begin_define
DECL|macro|QWINDOWSMIME_H
define|#
directive|define
name|QWINDOWSMIME_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsMime
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsMime
argument_list|)
name|public
label|:
name|QWindowsMime
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QWindowsMime
argument_list|()
expr_stmt|;
comment|// for converting from Qt
name|virtual
name|bool
name|canConvertFromMime
argument_list|(
specifier|const
name|FORMATETC
operator|&
name|formatetc
argument_list|,
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|convertFromMime
argument_list|(
specifier|const
name|FORMATETC
operator|&
name|formatetc
argument_list|,
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|,
name|STGMEDIUM
operator|*
name|pmedium
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QVector
operator|<
name|FORMATETC
operator|>
name|formatsForMime
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|const QMimeData *mimeData
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// for converting to Qt
name|virtual
name|bool
name|canConvertToMime
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|,
name|IDataObject
operator|*
name|pDataObj
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QVariant
name|convertToMime
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|,
name|IDataObject
operator|*
name|pDataObj
argument_list|,
name|QVariant
operator|::
name|Type
name|preferredType
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QString
name|mimeForFormat
argument_list|(
specifier|const
name|FORMATETC
operator|&
name|formatetc
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
specifier|static
name|int
name|registerMimeType
parameter_list|(
specifier|const
name|QString
modifier|&
name|mime
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsMimeConverter
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsMimeConverter
argument_list|)
name|public
label|:
name|QWindowsMimeConverter
argument_list|()
expr_stmt|;
operator|~
name|QWindowsMimeConverter
argument_list|()
expr_stmt|;
name|QWindowsMime
modifier|*
name|converterToMime
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|,
name|IDataObject
operator|*
name|pDataObj
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|allMimesForFormats
argument_list|(
name|IDataObject
operator|*
name|pDataObj
argument_list|)
decl|const
decl_stmt|;
name|QWindowsMime
modifier|*
name|converterFromMime
argument_list|(
specifier|const
name|FORMATETC
operator|&
name|formatetc
argument_list|,
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|)
decl|const
decl_stmt|;
name|QVector
operator|<
name|FORMATETC
operator|>
name|allFormatsForMime
argument_list|(
argument|const QMimeData *mimeData
argument_list|)
specifier|const
expr_stmt|;
comment|// Convenience.
name|QVariant
name|convertToMime
argument_list|(
specifier|const
name|QStringList
operator|&
name|mimeTypes
argument_list|,
name|IDataObject
operator|*
name|pDataObj
argument_list|,
name|QVariant
operator|::
name|Type
name|preferredType
argument_list|,
name|QString
operator|*
name|format
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|registerMime
parameter_list|(
name|QWindowsMime
modifier|*
name|mime
parameter_list|)
function_decl|;
name|void
name|unregisterMime
parameter_list|(
name|QWindowsMime
modifier|*
name|mime
parameter_list|)
block|{
name|m_mimes
operator|.
name|removeOne
argument_list|(
name|mime
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|void
name|ensureInitialized
argument_list|()
specifier|const
expr_stmt|;
name|mutable
name|QList
operator|<
name|QWindowsMime
operator|*
operator|>
name|m_mimes
expr_stmt|;
name|mutable
name|int
name|m_internalMimeCount
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSMIME_H
end_comment
end_unit
