begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2013 Konstantin Ritt ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHARFBUZZNG_P_H
end_ifndef
begin_define
DECL|macro|QHARFBUZZNG_P_H
define|#
directive|define
name|QHARFBUZZNG_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|<QtCore/qchar.h>
end_include
begin_include
include|#
directive|include
file|<harfbuzz/hb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Unicode
end_comment
begin_decl_stmt
name|Q_GUI_EXPORT
name|hb_script_t
name|hb_qt_script_to_script
argument_list|(
name|QChar
operator|::
name|Script
name|script
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QChar
operator|::
name|Script
name|hb_qt_script_from_script
argument_list|(
argument|hb_script_t script
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|Q_GUI_EXPORT
name|hb_unicode_funcs_t
modifier|*
name|hb_qt_get_unicode_funcs
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Font
end_comment
begin_function_decl
name|Q_GUI_EXPORT
name|hb_font_funcs_t
modifier|*
name|hb_qt_get_font_funcs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|hb_face_t
modifier|*
name|hb_qt_face_get_for_engine
parameter_list|(
name|QFontEngine
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|hb_font_t
modifier|*
name|hb_qt_font_get_for_engine
parameter_list|(
name|QFontEngine
modifier|*
name|fe
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|void
name|hb_qt_font_set_use_design_metrics
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|uint
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|uint
name|hb_qt_font_get_use_design_metrics
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHARFBUZZNG_P_H
end_comment
end_unit
