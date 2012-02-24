begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformclipboard_qpa.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmimedata.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QClipboardData
class|class
name|QClipboardData
block|{
public|public:
name|QClipboardData
parameter_list|()
constructor_decl|;
name|~
name|QClipboardData
parameter_list|()
destructor_decl|;
DECL|function|setSource
name|void
name|setSource
parameter_list|(
name|QMimeData
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
name|s
operator|==
name|src
condition|)
return|return;
operator|delete
name|src
expr_stmt|;
name|src
operator|=
name|s
expr_stmt|;
block|}
DECL|function|source
name|QMimeData
modifier|*
name|source
parameter_list|()
block|{
return|return
name|src
return|;
block|}
private|private:
DECL|member|src
name|QMimeData
modifier|*
name|src
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QClipboardData
name|QClipboardData
operator|::
name|QClipboardData
parameter_list|()
block|{
name|src
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QClipboardData
name|QClipboardData
operator|::
name|~
name|QClipboardData
parameter_list|()
block|{
operator|delete
name|src
expr_stmt|;
block|}
end_destructor
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QClipboardData
argument_list|,
name|q_clipboardData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_destructor
DECL|function|~QPlatformClipboard
name|QPlatformClipboard
operator|::
name|~
name|QPlatformClipboard
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QPlatformClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
comment|//we know its clipboard
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
expr_stmt|;
return|return
name|q_clipboardData
argument_list|()
operator|->
name|source
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QPlatformClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|data
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
comment|//we know its clipboard
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|q_clipboardData
argument_list|()
operator|->
name|setSource
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|emitChanged
argument_list|(
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QPlatformClipboard
operator|::
name|supportsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
return|;
block|}
end_function
begin_function
DECL|function|ownsMode
name|bool
name|QPlatformClipboard
operator|::
name|ownsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|emitChanged
name|void
name|QPlatformClipboard
operator|::
name|emitChanged
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|emitChanged
argument_list|(
name|mode
argument_list|)
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
comment|//QT_NO_CLIPBOARD
end_comment
end_unit
