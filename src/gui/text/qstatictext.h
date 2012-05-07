begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATICTEXT_H
end_ifndef
begin_define
DECL|macro|QSTATICTEXT_H
define|#
directive|define
name|QSTATICTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QStaticTextPrivate
name|class
name|QStaticTextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStaticText
block|{
name|public
label|:
enum|enum
name|PerformanceHint
block|{
name|ModerateCaching
block|,
name|AggressiveCaching
block|}
enum|;
name|QStaticText
argument_list|()
expr_stmt|;
name|QStaticText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
expr_stmt|;
name|QStaticText
argument_list|(
specifier|const
name|QStaticText
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QStaticText
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QStaticText
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|data
argument_list|,
name|other
operator|.
name|data
argument_list|)
expr_stmt|;
block|}
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|TextFormat
name|textFormat
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|TextFormat
name|textFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextWidth
parameter_list|(
name|qreal
name|textWidth
parameter_list|)
function_decl|;
name|qreal
name|textWidth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextOption
parameter_list|(
specifier|const
name|QTextOption
modifier|&
name|textOption
parameter_list|)
function_decl|;
name|QTextOption
name|textOption
argument_list|()
specifier|const
expr_stmt|;
name|QSizeF
name|size
argument_list|()
specifier|const
expr_stmt|;
name|void
name|prepare
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|matrix
init|=
name|QTransform
argument_list|()
parameter_list|,
specifier|const
name|QFont
modifier|&
name|font
init|=
name|QFont
argument_list|()
parameter_list|)
function_decl|;
name|void
name|setPerformanceHint
parameter_list|(
name|PerformanceHint
name|performanceHint
parameter_list|)
function_decl|;
name|PerformanceHint
name|performanceHint
argument_list|()
specifier|const
expr_stmt|;
name|QStaticText
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QStaticText
operator|&
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QStaticText
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QStaticText
operator|&
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|detach
parameter_list|()
function_decl|;
name|QExplicitlySharedDataPointer
operator|<
name|QStaticTextPrivate
operator|>
name|data
expr_stmt|;
name|friend
name|class
name|QStaticTextPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QStaticText
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QStaticText
argument_list|)
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTATICTEXT_H
end_comment
end_unit
