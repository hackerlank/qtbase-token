begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QCOCOAINPUTCONTEXT_H
define|#
directive|define
name|QCOCOAINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QCocoaInputContext
argument_list|()
block|;
operator|~
name|QCocoaInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|true
return|;
block|}
name|void
name|reset
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QLocale
name|locale
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_locale
return|;
block|}
name|void
name|updateLocale
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|connectSignals
argument_list|()
block|;
name|void
name|focusObjectChanged
argument_list|(
name|QObject
operator|*
name|focusObject
argument_list|)
block|;
name|private
operator|:
name|QPointer
operator|<
name|QWindow
operator|>
name|mWindow
block|;
name|QLocale
name|m_locale
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
comment|// QCOCOAINPUTCONTEXT_H
end_comment
end_unit
