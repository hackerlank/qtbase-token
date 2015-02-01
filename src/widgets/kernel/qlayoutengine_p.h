begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLAYOUTENGINE_P_H
end_ifndef
begin_define
DECL|macro|QLAYOUTENGINE_P_H
define|#
directive|define
name|QLAYOUTENGINE_P_H
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
file|"QtWidgets/qlayoutitem.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyle.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVector
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QVector
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|QLayoutStruct
struct|struct
name|QLayoutStruct
block|{
DECL|function|init
specifier|inline
name|void
name|init
parameter_list|(
name|int
name|stretchFactor
init|=
literal|0
parameter_list|,
name|int
name|minSize
init|=
literal|0
parameter_list|)
block|{
name|stretch
operator|=
name|stretchFactor
expr_stmt|;
name|minimumSize
operator|=
name|sizeHint
operator|=
name|minSize
expr_stmt|;
name|maximumSize
operator|=
name|QLAYOUTSIZE_MAX
expr_stmt|;
name|expansive
operator|=
name|false
expr_stmt|;
name|empty
operator|=
name|true
expr_stmt|;
name|spacing
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|smartSizeHint
name|int
name|smartSizeHint
parameter_list|()
block|{
return|return
operator|(
name|stretch
operator|>
literal|0
operator|)
condition|?
name|minimumSize
else|:
name|sizeHint
return|;
block|}
DECL|function|effectiveSpacer
name|int
name|effectiveSpacer
argument_list|(
name|int
name|uniformSpacer
argument_list|)
decl|const
block|{
name|Q_ASSERT
argument_list|(
name|uniformSpacer
operator|>=
literal|0
operator|||
name|spacing
operator|>=
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|uniformSpacer
operator|>=
literal|0
operator|)
condition|?
name|uniformSpacer
else|:
name|spacing
return|;
block|}
comment|// parameters
DECL|member|stretch
name|int
name|stretch
decl_stmt|;
DECL|member|sizeHint
name|int
name|sizeHint
decl_stmt|;
DECL|member|maximumSize
name|int
name|maximumSize
decl_stmt|;
DECL|member|minimumSize
name|int
name|minimumSize
decl_stmt|;
DECL|member|spacing
name|int
name|spacing
decl_stmt|;
DECL|member|expansive
name|bool
name|expansive
decl_stmt|;
DECL|member|empty
name|bool
name|empty
decl_stmt|;
comment|// temporary storage
DECL|member|done
name|bool
name|done
decl_stmt|;
comment|// result
DECL|member|pos
name|int
name|pos
decl_stmt|;
DECL|member|size
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|void
name|qGeomCalc
argument_list|(
name|QVector
operator|<
name|QLayoutStruct
operator|>
operator|&
name|chain
argument_list|,
name|int
name|start
argument_list|,
name|int
name|count
argument_list|,
name|int
name|pos
argument_list|,
name|int
name|space
argument_list|,
name|int
name|spacer
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sizeHint
parameter_list|,
specifier|const
name|QSize
modifier|&
name|minSizeHint
parameter_list|,
specifier|const
name|QSize
modifier|&
name|minSize
parameter_list|,
specifier|const
name|QSize
modifier|&
name|maxSize
parameter_list|,
specifier|const
name|QSizePolicy
modifier|&
name|sizePolicy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QWidgetItem
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMinSize
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
argument_list|(
specifier|const
name|QSize
operator|&
name|sizeHint
argument_list|,
specifier|const
name|QSize
operator|&
name|minSize
argument_list|,
specifier|const
name|QSize
operator|&
name|maxSize
argument_list|,
specifier|const
name|QSizePolicy
operator|&
name|sizePolicy
argument_list|,
name|Qt
operator|::
name|Alignment
name|align
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
argument_list|(
specifier|const
name|QWidgetItem
operator|*
name|i
argument_list|,
name|Qt
operator|::
name|Alignment
name|align
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|QSize
name|qSmartMaxSize
argument_list|(
specifier|const
name|QWidget
operator|*
name|w
argument_list|,
name|Qt
operator|::
name|Alignment
name|align
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|int
name|qSmartSpacing
argument_list|(
specifier|const
name|QLayout
operator|*
name|layout
argument_list|,
name|QStyle
operator|::
name|PixelMetric
name|pm
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*   Modify total maximum (max), total expansion (exp), and total empty   when adding boxmax/boxexp.    Expansive boxes win over non-expansive boxes.   Non-empty boxes win over empty boxes. */
end_comment
begin_function
DECL|function|qMaxExpCalc
specifier|static
specifier|inline
name|void
name|qMaxExpCalc
parameter_list|(
name|int
modifier|&
name|max
parameter_list|,
name|bool
modifier|&
name|exp
parameter_list|,
name|bool
modifier|&
name|empty
parameter_list|,
name|int
name|boxmax
parameter_list|,
name|bool
name|boxexp
parameter_list|,
name|bool
name|boxempty
parameter_list|)
block|{
if|if
condition|(
name|exp
condition|)
block|{
if|if
condition|(
name|boxexp
condition|)
name|max
operator|=
name|qMax
argument_list|(
name|max
argument_list|,
name|boxmax
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|boxexp
operator|||
operator|(
name|empty
operator|&&
operator|(
operator|!
name|boxempty
operator|||
name|max
operator|==
literal|0
operator|)
operator|)
condition|)
name|max
operator|=
name|boxmax
expr_stmt|;
elseif|else
if|if
condition|(
name|empty
operator|==
name|boxempty
condition|)
name|max
operator|=
name|qMin
argument_list|(
name|max
argument_list|,
name|boxmax
argument_list|)
expr_stmt|;
block|}
name|exp
operator|=
name|exp
operator|||
name|boxexp
expr_stmt|;
name|empty
operator|=
name|empty
operator|&&
name|boxempty
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLAYOUTENGINE_P_H
end_comment
end_unit
