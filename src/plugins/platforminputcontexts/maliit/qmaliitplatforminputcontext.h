begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMALIITPLATFORMINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QMALIITPLATFORMINPUTCONTEXT_H
define|#
directive|define
name|QMALIITPLATFORMINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QDBusArgument>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMaliitPlatformInputContextPrivate
name|class
name|QMaliitPlatformInputContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusVariant
name|class
name|QDBusVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusMessage
name|class
name|QDBusMessage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMaliitPlatformInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|QMaliitPlatformInputContext
argument_list|()
block|;
operator|~
name|QMaliitPlatformInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|void
name|invokeAction
argument_list|(
argument|QInputMethod::Action action
argument_list|,
argument|int x
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|void
argument_list|)
block|;
name|void
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|)
block|;
name|virtual
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|showInputPanel
argument_list|()
block|;
name|virtual
name|void
name|hideInputPanel
argument_list|()
block|;
name|virtual
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|;
name|void
name|setFocusObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|activationLostEvent
argument_list|()
block|;
name|void
name|commitString
argument_list|(
argument|const QString&in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|int in3
argument_list|)
block|;
name|void
name|updatePreedit
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|)
block|;
name|void
name|copy
argument_list|()
block|;
name|void
name|imInitiatedHide
argument_list|()
block|;
name|void
name|keyEvent
argument_list|(
argument|int type
argument_list|,
argument|int key
argument_list|,
argument|int modifiers
argument_list|,
argument|const QString&text
argument_list|,
argument|bool autoRepeat
argument_list|,
argument|int count
argument_list|,
argument|uchar requestType_
argument_list|)
block|;
name|void
name|paste
argument_list|()
block|;
name|bool
name|preeditRectangle
argument_list|(
name|int
operator|&
name|x
argument_list|,
name|int
operator|&
name|y
argument_list|,
name|int
operator|&
name|width
argument_list|,
name|int
operator|&
name|height
argument_list|)
block|;
name|bool
name|selection
argument_list|(
name|QString
operator|&
name|selection
argument_list|)
block|;
name|void
name|setDetectableAutoRepeat
argument_list|(
argument|bool in0
argument_list|)
block|;
name|void
name|setGlobalCorrectionEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|setLanguage
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|setRedirectKeys
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|setSelection
argument_list|(
argument|int start
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|updateInputMethodArea
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|void
name|updateServerWindowOrientation
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|private
operator|:
name|QMaliitPlatformInputContextPrivate
operator|*
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
end_unit
