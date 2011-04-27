begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGUIAPPLICATION_QPA_H
end_ifndef
begin_define
DECL|macro|QGUIAPPLICATION_QPA_H
define|#
directive|define
name|QGUIAPPLICATION_QPA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QGuiApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGuiApplication
range|:
name|public
name|QCoreApplication
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int doubleClickInterval  READ doubleClickInterval WRITE setDoubleClickInterval
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int keyboardInputInterval READ keyboardInputInterval WRITE setKeyboardInputInterval
argument_list|)
name|public
operator|:
name|QGuiApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|,
name|int
operator|=
name|ApplicationFlags
argument_list|)
block|;
name|virtual
operator|~
name|QGuiApplication
argument_list|()
block|;
if|#
directive|if
literal|0
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
block|static QCursor *overrideCursor();     static void setOverrideCursor(const QCursor&);     static void changeOverrideCursor(const QCursor&);     static void restoreOverrideCursor();
endif|#
directive|endif
block|static QFont font();     static QFont font(const QWidget*);     static QFont font(const char *className);     static void setFont(const QFont&, const char* className = 0);     static QFontMetrics fontMetrics();
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
block|static QClipboard *clipboard();
endif|#
directive|endif
endif|#
directive|endif
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
argument_list|()
block|;
specifier|static
name|void
name|setDoubleClickInterval
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|doubleClickInterval
argument_list|()
block|;
specifier|static
name|void
name|setKeyboardInputInterval
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|keyboardInputInterval
argument_list|()
block|;
specifier|static
name|QPlatformNativeInterface
operator|*
name|platformNativeInterface
argument_list|()
block|;
specifier|static
name|int
name|exec
argument_list|()
block|;
name|bool
name|notify
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|compressEvent
argument_list|(
name|QEvent
operator|*
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
name|QPostEventList
operator|*
argument_list|)
block|;
name|QGuiApplication
argument_list|(
name|QGuiApplicationPrivate
operator|&
name|p
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGuiApplication
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGuiApplication
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QGestureManager
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGUIAPPLICATION_QPA_H
end_comment
end_unit
