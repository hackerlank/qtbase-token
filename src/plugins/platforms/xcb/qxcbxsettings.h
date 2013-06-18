begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBXSETTINGS_H
end_ifndef
begin_define
DECL|macro|QXCBXSETTINGS_H
define|#
directive|define
name|QXCBXSETTINGS_H
end_define
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbXSettingsPrivate
name|class
name|QXcbXSettingsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbXSettings
range|:
name|public
name|QXcbWindowEventListener
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QXcbXSettings
argument_list|)
name|public
operator|:
name|QXcbXSettings
argument_list|(
name|QXcbScreen
operator|*
name|screen
argument_list|)
block|;
name|QVariant
name|setting
argument_list|(
argument|const QByteArray&property
argument_list|)
specifier|const
block|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|PropertyChangeFunc
function_decl|)
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|property
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
name|void
name|registerCallbackForProperty
argument_list|(
argument|const QByteArray&property
argument_list|,
argument|PropertyChangeFunc func
argument_list|,
argument|void *handle
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|removeCallbackForHandle
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|property
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeCallbackForHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|handlePropertyNotifyEvent
argument_list|(
specifier|const
name|xcb_property_notify_event_t
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QXcbXSettingsPrivate
modifier|*
name|d_ptr
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXCBXSETTINGS_H
end_comment
end_unit