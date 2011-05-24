begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTER_P_H
end_ifndef
begin_define
DECL|macro|QPRINTER_P_H
define|#
directive|define
name|QPRINTER_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"QtGui/qprinter.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qprintengine.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPrintEngine
name|class
name|QPrintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPreviewPaintEngine
name|class
name|QPreviewPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPicture
name|class
name|QPicture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPrinterPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPrinter
argument_list|)
name|public
label|:
name|QPrinterPrivate
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|)
operator|:
name|printEngine
argument_list|(
literal|0
argument_list|)
operator|,
name|paintEngine
argument_list|(
literal|0
argument_list|)
operator|,
name|q_ptr
argument_list|(
name|printer
argument_list|)
operator|,
name|printRange
argument_list|(
name|QPrinter
operator|::
name|AllPages
argument_list|)
operator|,
name|minPage
argument_list|(
literal|1
argument_list|)
operator|,
name|maxPage
argument_list|(
name|INT_MAX
argument_list|)
operator|,
name|fromPage
argument_list|(
literal|0
argument_list|)
operator|,
name|toPage
argument_list|(
literal|0
argument_list|)
operator|,
name|use_default_engine
argument_list|(
name|true
argument_list|)
operator|,
name|validPrinter
argument_list|(
name|false
argument_list|)
operator|,
name|hasCustomPageMargins
argument_list|(
name|false
argument_list|)
operator|,
name|hasUserSetPageSize
argument_list|(
argument|false
argument_list|)
block|{     }
operator|~
name|QPrinterPrivate
argument_list|()
block|{      }
name|void
name|createDefaultEngines
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWWIDGET
name|QList
operator|<
specifier|const
name|QPicture
operator|*
operator|>
name|previewPages
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreviewMode
parameter_list|(
name|bool
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|addToManualSetList
argument_list|(
name|QPrintEngine
operator|::
name|PrintEnginePropertyKey
name|key
argument_list|)
decl_stmt|;
name|QPrinter
operator|::
name|PrinterMode
name|printerMode
expr_stmt|;
name|QPrinter
operator|::
name|OutputFormat
name|outputFormat
expr_stmt|;
name|QPrintEngine
modifier|*
name|printEngine
decl_stmt|;
name|QPaintEngine
modifier|*
name|paintEngine
decl_stmt|;
name|QPrintEngine
modifier|*
name|realPrintEngine
decl_stmt|;
name|QPaintEngine
modifier|*
name|realPaintEngine
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWWIDGET
name|QPreviewPaintEngine
modifier|*
name|previewEngine
decl_stmt|;
endif|#
directive|endif
name|QPrinter
modifier|*
name|q_ptr
decl_stmt|;
name|QPrinter
operator|::
name|PrintRange
name|printRange
expr_stmt|;
name|int
name|minPage
decl_stmt|,
name|maxPage
decl_stmt|,
name|fromPage
decl_stmt|,
name|toPage
decl_stmt|;
name|uint
name|use_default_engine
range|:
literal|1
decl_stmt|;
name|uint
name|had_default_engines
range|:
literal|1
decl_stmt|;
name|uint
name|validPrinter
range|:
literal|1
decl_stmt|;
name|uint
name|hasCustomPageMargins
range|:
literal|1
decl_stmt|;
name|uint
name|hasUserSetPageSize
range|:
literal|1
decl_stmt|;
comment|// Used to remember which properties have been manually set by the user.
name|QList
operator|<
name|QPrintEngine
operator|::
name|PrintEnginePropertyKey
operator|>
name|manualSetList
expr_stmt|;
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
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTER_P_H
end_comment
end_unit
