begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSWINDOW_H
end_ifndef
begin_define
DECL|macro|QIOSWINDOW_H
define|#
directive|define
name|QIOSWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_decl_stmt
DECL|variable|QIOSContext
name|class
name|QIOSContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSWindow
name|class
name|QIOSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSWindow
unit|@
name|interface
name|EAGLView
range|:
name|UIView
operator|<
name|UIKeyInput
operator|>
block|{
name|UITextAutocapitalizationType
name|autocapitalizationType
block|;
name|UITextAutocorrectionType
name|autocorrectionType
block|;
name|BOOL
name|enablesReturnKeyAutomatically
block|;
name|UIKeyboardAppearance
name|keyboardAppearance
block|;
name|UIKeyboardType
name|keyboardType
block|;
name|UIReturnKeyType
name|returnKeyType
block|;
name|BOOL
name|secureTextEntry
block|;
name|QIOSWindow
operator|*
name|m_qioswindow
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithQIOSWindow
operator|:
operator|(
name|QIOSWindow
operator|*
operator|)
name|qioswindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|sendMouseEventForTouches
operator|:
operator|(
name|NSSet
operator|*
operator|)
name|touches
name|withEvent
operator|:
operator|(
name|UIEvent
operator|*
operator|)
name|event
name|fakeButtons
operator|:
operator|(
name|Qt
operator|::
name|MouseButtons
operator|)
name|buttons
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UITextAutocapitalizationType
name|autocapitalizationType
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|autocorrectionType
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|autocorrectionType
name|UITextAutocorrectionType
name|autocorrectionType
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|autocorrectionType
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|BOOL
name|enablesReturnKeyAutomatically
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|keyboardAppearance
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|keyboardAppearance
name|UIKeyboardAppearance
name|keyboardAppearance
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|keyboardAppearance
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UIKeyboardType
name|keyboardType
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|returnKeyType
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|returnKeyType
name|UIReturnKeyType
name|returnKeyType
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|returnKeyType
unit|@
DECL|variable|secureTextEntry
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|getter=isSecureTextEntry
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|secureTextEntry
name|BOOL
name|secureTextEntry
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|secureTextEntry
unit|@
name|end
name|QT_BEGIN_NAMESPACE
name|class
name|QIOSWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|explicit
name|QIOSWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QIOSWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|handleContentOrientationChange
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|GLuint
name|framebufferObject
argument_list|(
argument|const QIOSContext&context
argument_list|)
specifier|const
block|;
name|EAGLView
operator|*
name|nativeView
argument_list|()
specifier|const
block|{
return|return
name|m_view
return|;
block|}
name|private
operator|:
name|EAGLView
operator|*
name|m_view
block|;
name|QRect
name|m_requestedGeometry
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
comment|// QIOSWINDOW_H
end_comment
end_unit
