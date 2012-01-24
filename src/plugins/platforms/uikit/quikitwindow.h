begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUIKITWINDOW_H
end_ifndef
begin_define
DECL|macro|QUIKITWINDOW_H
define|#
directive|define
name|QUIKITWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QPlatformWindow>
end_include
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_empty
empty|#import<OpenGLES/ES1/gl.h>
end_empty
begin_empty
empty|#import<OpenGLES/ES1/glext.h>
end_empty
begin_empty
empty|#import<OpenGLES/ES2/gl.h>
end_empty
begin_empty
empty|#import<OpenGLES/ES2/glext.h>
end_empty
begin_empty
empty|#import<OpenGLES/EAGL.h>
end_empty
begin_decl_stmt
unit|@
name|interface
name|EAGLView
range|:
name|UIView
operator|<
name|UIKeyInput
operator|>
block|{
name|QPlatformWindow
operator|*
name|mWindow
block|;
name|EAGLContext
operator|*
name|mContext
block|;
name|GLint
name|mFramebufferWidth
block|;
name|GLint
name|mFramebufferHeight
block|;
name|GLuint
name|mFramebuffer
block|,
name|mColorRenderbuffer
block|,
name|mDepthRenderbuffer
block|;
name|id
name|delegate
block|;
comment|// ------- Text Input ----------
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
block|; }
operator|-
operator|(
name|void
operator|)
name|setContext
operator|:
operator|(
name|EAGLContext
operator|*
operator|)
name|newContext
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|presentFramebuffer
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|deleteFramebuffer
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|createFramebuffer
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|makeCurrent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setWindow
operator|:
operator|(
name|QPlatformWindow
operator|*
operator|)
name|window
expr_stmt|;
end_expr_stmt
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
DECL|variable|fbo
name|property
argument_list|(
argument|readonly
argument_list|,
argument|getter=fbo
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|fbo
name|GLint
name|fbo
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|fbo
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|assign
argument_list|)
end_macro
begin_decl_stmt
name|id
name|delegate
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ------- Text Input ----------
end_comment
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
begin_expr_stmt
DECL|variable|secureTextEntry
unit|@
name|end
expr|@
name|protocol
name|EAGLViewDelegate
operator|-
operator|(
name|void
operator|)
name|eaglView
operator|:
operator|(
name|EAGLView
operator|*
operator|)
name|view
name|usesFramebuffer
operator|:
operator|(
name|GLuint
operator|)
name|buffer
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|@
name|end
DECL|variable|EAGLPlatformContext
name|class
name|EAGLPlatformContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QUIKitScreen
name|class
name|QUIKitScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUIKitWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|explicit
name|QUIKitWindow
argument_list|(
name|QWidget
operator|*
name|tlw
argument_list|)
block|;
operator|~
name|QUIKitWindow
argument_list|()
block|;
name|UIWindow
operator|*
name|nativeWindow
argument_list|()
specifier|const
block|{
return|return
name|mWindow
return|;
block|}
name|EAGLView
operator|*
name|nativeView
argument_list|()
specifier|const
block|{
return|return
name|mView
return|;
block|}
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|UIWindow
operator|*
name|ensureNativeWindow
argument_list|()
block|;
name|QPlatformOpenGLContext
operator|*
name|glContext
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QUIKitScreen
operator|*
name|mScreen
block|;
name|UIWindow
operator|*
name|mWindow
block|;
name|EAGLView
operator|*
name|mView
block|;
name|mutable
name|EAGLPlatformContext
operator|*
name|mContext
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
comment|// QUIKITWINDOW_H
end_comment
end_unit
