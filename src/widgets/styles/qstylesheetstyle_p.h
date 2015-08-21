begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLESHEETSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QSTYLESHEETSTYLE_P_H
define|#
directive|define
name|QSTYLESHEETSTYLE_P_H
end_define
begin_include
include|#
directive|include
file|"private/qwindowsstyle_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
end_ifndef
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qevent.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qset.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qapplication.h"
end_include
begin_include
include|#
directive|include
file|"private/qcssparser_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qbrush.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists purely as an
comment|// implementation detail.  This header file may change from version to
comment|// version without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
DECL|variable|QRenderRule
name|class
name|QRenderRule
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollArea
name|class
name|QAbstractScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleSheetStylePrivate
name|class
name|QStyleSheetStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionTitleBar
name|class
name|QStyleOptionTitleBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QStyleSheetStyle
range|:
name|public
name|QWindowsStyle
block|{
typedef|typedef
name|QWindowsStyle
name|ParentStyle
typedef|;
name|Q_OBJECT
name|public
operator|:
name|QStyleSheetStyle
argument_list|(
name|QStyle
operator|*
name|baseStyle
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|~
name|QStyleSheetStyle
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|drawComplexControl
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|drawControl
argument_list|(
name|ControlElement
name|element
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|drawItemPixmap
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|int
name|alignment
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|drawItemText
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|int
name|alignment
argument_list|,
specifier|const
name|QPalette
operator|&
name|pal
argument_list|,
name|bool
name|enabled
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QPalette
operator|::
name|ColorRole
name|textRole
operator|=
name|QPalette
operator|::
name|NoRole
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|drawPrimitive
argument_list|(
name|PrimitiveElement
name|pe
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
name|generatedIconPixmap
argument_list|(
name|QIcon
operator|::
name|Mode
name|iconMode
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SubControl
name|hitTestComplexControl
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
specifier|const
name|QPoint
operator|&
name|pt
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|itemPixmapRect
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|int
name|alignment
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|itemTextRect
argument_list|(
specifier|const
name|QFontMetrics
operator|&
name|metrics
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|int
name|alignment
argument_list|,
name|bool
name|enabled
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|pixelMetric
argument_list|(
name|PixelMetric
name|metric
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|polish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|polish
argument_list|(
name|QApplication
operator|*
name|app
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|polish
argument_list|(
name|QPalette
operator|&
name|pal
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|sizeFromContents
argument_list|(
name|ContentsType
name|ct
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
specifier|const
name|QSize
operator|&
name|contentsSize
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPalette
name|standardPalette
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QIcon
name|standardIcon
argument_list|(
name|StandardPixmap
name|standardIcon
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
name|standardPixmap
argument_list|(
name|StandardPixmap
name|standardPixmap
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|layoutSpacing
argument_list|(
name|QSizePolicy
operator|::
name|ControlType
name|control1
argument_list|,
name|QSizePolicy
operator|::
name|ControlType
name|control2
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|styleHint
argument_list|(
name|StyleHint
name|sh
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|,
name|QStyleHintReturn
operator|*
name|shret
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|subElementRect
argument_list|(
name|SubElement
name|r
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|subControlRect
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
name|SubControl
name|sc
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_comment
comment|// These functions are called from QApplication/QWidget. Be careful.
end_comment
begin_expr_stmt
name|QStyle
operator|*
name|baseStyle
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|repolish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|repolish
parameter_list|(
name|QApplication
modifier|*
name|app
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|unpolish
argument_list|(
name|QApplication
operator|*
name|app
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStyle
modifier|*
name|base
decl_stmt|;
end_decl_stmt
begin_function
name|void
name|ref
parameter_list|()
block|{
operator|++
name|refcount
expr_stmt|;
block|}
end_function
begin_function
name|void
name|deref
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|refcount
operator|>
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|--
name|refcount
condition|)
name|delete
name|this
decl_stmt|;
block|}
end_function
begin_decl_stmt
name|void
name|updateStyleSheetFont
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|saveWidgetFont
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QFont
operator|&
name|font
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|clearWidgetFont
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|styleSheetPalette
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
name|QPalette
modifier|*
name|pal
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|refcount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QRenderRule
decl_stmt|;
end_decl_stmt
begin_function_decl
name|int
name|nativeFrameWidth
parameter_list|(
specifier|const
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QRenderRule
name|renderRule
argument_list|(
specifier|const
name|QObject
operator|*
argument_list|,
name|int
argument_list|,
name|quint64
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRenderRule
name|renderRule
argument_list|(
specifier|const
name|QObject
operator|*
argument_list|,
specifier|const
name|QStyleOption
operator|*
argument_list|,
name|int
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|defaultSize
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|,
name|QSize
argument_list|,
specifier|const
name|QRect
operator|&
argument_list|,
name|int
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|positionRect
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|,
specifier|const
name|QRenderRule
operator|&
argument_list|,
specifier|const
name|QRenderRule
operator|&
argument_list|,
name|int
argument_list|,
specifier|const
name|QRect
operator|&
argument_list|,
name|Qt
operator|::
name|LayoutDirection
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|positionRect
argument_list|(
specifier|const
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QRenderRule
operator|&
name|rule2
argument_list|,
name|int
name|pe
argument_list|,
specifier|const
name|QRect
operator|&
name|originRect
argument_list|,
name|Qt
operator|::
name|LayoutDirection
name|dir
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mutable
name|QCss
operator|::
name|Parser
name|parser
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPalette
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unsetPalette
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setProperties
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setGeometry
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|unsetStyleSheetFont
argument_list|(
name|QWidget
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVector
operator|<
name|QCss
operator|::
name|StyleRule
operator|>
name|styleRules
argument_list|(
argument|const QObject *obj
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|hasStyleRule
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
argument_list|,
name|int
name|part
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|QStyle
operator|::
name|SubControl
operator|,
name|QRect
operator|>
name|titleBarLayout
argument_list|(
argument|const QWidget *w
argument_list|,
argument|const QStyleOptionTitleBar *tb
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QCss
operator|::
name|StyleSheet
name|getDefaultStyleSheet
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|Alignment
name|resolveAlignment
argument_list|(
name|Qt
operator|::
name|LayoutDirection
argument_list|,
name|Qt
operator|::
name|Alignment
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|isNaturalChild
parameter_list|(
specifier|const
name|QObject
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|initObject
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_decl_stmt
specifier|static
name|int
name|numinstances
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QStyleSheetStyle
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStyleSheetStyle
argument_list|)
end_macro
begin_decl_stmt
unit|};
name|class
name|QStyleSheetStyleCaches
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|Q_SLOTS
operator|:
name|void
name|objectDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
name|void
name|styleDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
name|public
operator|:
name|QHash
operator|<
specifier|const
name|QObject
operator|*
block|,
name|QVector
operator|<
name|QCss
operator|::
name|StyleRule
operator|>
expr|>
name|styleRulesCache
block|;
name|QHash
operator|<
specifier|const
name|QObject
operator|*
block|,
name|QHash
operator|<
name|int
block|,
name|bool
operator|>
expr|>
name|hasStyleRuleCache
block|;
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QHash
operator|<
name|quint64
operator|,
name|QRenderRule
operator|>
expr|>
name|QRenderRules
expr_stmt|;
name|QHash
operator|<
specifier|const
name|QObject
operator|*
block|,
name|QRenderRules
operator|>
name|renderRulesCache
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
specifier|const
name|void
operator|*
operator|,
name|QCss
operator|::
name|StyleSheet
operator|>
name|styleSheetCache
expr_stmt|;
end_expr_stmt
begin_comment
comment|// parsed style sheets
end_comment
begin_expr_stmt
name|QSet
operator|<
specifier|const
name|QWidget
operator|*
operator|>
name|autoFillDisabledWidgets
expr_stmt|;
end_expr_stmt
begin_comment
comment|// widgets whose palettes and fonts we have tampered. stored value pair is
end_comment
begin_comment
comment|// QPair<old widget value, resolve mask of stylesheet value>
end_comment
begin_expr_stmt
name|QHash
operator|<
specifier|const
name|QWidget
operator|*
operator|,
name|QPair
operator|<
name|QPalette
operator|,
name|uint
operator|>
expr|>
name|customPaletteWidgets
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
specifier|const
name|QWidget
operator|*
operator|,
name|QPair
operator|<
name|QFont
operator|,
name|uint
operator|>
expr|>
name|customFontWidgets
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_STYLESHEET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTYLESHEETSTYLE_P_H
end_comment
end_unit
