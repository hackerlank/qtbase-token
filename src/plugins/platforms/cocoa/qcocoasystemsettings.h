begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOASYSTEMSETTINGS_H
end_ifndef
begin_define
DECL|macro|QCOCOASYSTEMSETTINGS_H
define|#
directive|define
name|QCOCOASYSTEMSETTINGS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpalette.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|QPalette
modifier|*
name|qt_mac_createSystemPalette
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
DECL|member|Palette
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Palette
operator|,
name|QPalette
operator|*
operator|>
name|qt_mac_createRolePalettes
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Font
name|QHash
operator|<
name|QPlatformTheme
operator|::
name|Font
operator|,
name|QFont
operator|*
operator|>
name|qt_mac_createRoleFonts
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
