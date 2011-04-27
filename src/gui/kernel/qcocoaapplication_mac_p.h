begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (c) 2007-2008, Apple, Inc. ** ** All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are met: ** **   * Redistributions of source code must retain the above copyright notice, **     this list of conditions and the following disclaimer. ** **   * Redistributions in binary form must reproduce the above copyright notice, **     this list of conditions and the following disclaimer in the documentation **     and/or other materials provided with the distribution. ** **   * Neither the name of Apple, Inc. nor the names of its contributors **     may be used to endorse or promote products derived from this software **     without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** ****************************************************************************/
end_comment
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
comment|// of qapplication_*.cpp, qwidget*.cpp, qcolor_x11.cpp, qfiledialog.cpp
end_comment
begin_comment
comment|// and many other.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
begin_comment
comment|/* 	Cocoa Application Categories */
end_comment
begin_include
include|#
directive|include
file|"qmacdefines_mac.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_empty
empty|#import<AppKit/AppKit.h>
end_empty
begin_expr_stmt
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QApplicationPrivate
argument_list|)
expr|@
name|class
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaMenuLoader
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|@
name|interface
name|NSApplication
argument_list|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QApplicationIntegration
argument_list|)
argument_list|)
decl|-
argument_list|(
name|void
argument_list|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_setDockMenu
argument_list|)
range|:
operator|(
name|NSMenu
operator|*
operator|)
name|newMenu
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|QApplicationPrivate
operator|*
operator|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_qappPrivate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QCocoaMenuLoader
argument_list|)
operator|*
operator|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_qcocoamenuLoader
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|QT_MANGLE_NAMESPACE
argument_list|(
name|qt_validModesForFontPanel
argument_list|)
operator|:
operator|(
name|NSFontPanel
operator|*
operator|)
name|fontPanel
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|qt_sendPostedMessage
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|event
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|qt_filterEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|event
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QNSApplication
operator|:
name|NSApplication
block|{ }
expr|@
name|end
name|QT_BEGIN_NAMESPACE
name|void
name|qt_redirectNSApplicationSendEvent
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
