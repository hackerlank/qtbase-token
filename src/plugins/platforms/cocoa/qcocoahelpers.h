begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).  ** Contact: http://www.qt-project.org/  **  ** This file is part of the plugins of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** GNU Lesser General Public License Usage  ** This file may be used under the terms of the GNU Lesser General Public  ** License version 2.1 as published by the Free Software Foundation and  ** appearing in the file LICENSE.LGPL included in the packaging of this  ** file. Please review the following information to ensure the GNU Lesser  ** General Public License version 2.1 requirements will be met:  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** In addition, as a special exception, Nokia gives you certain additional  ** rights. These rights are described in the Nokia Qt LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU General  ** Public License version 3.0 as published by the Free Software Foundation  ** and appearing in the file LICENSE.GPL included in the packaging of this  ** file. Please review the following information to ensure the GNU General  ** Public License version 3.0 requirements will be met:  ** http://www.gnu.org/copyleft/gpl.html.  **  ** Other Usage  ** Alternatively, this file may be used in accordance with the terms and  ** conditions contained in a signed written agreement between you and Nokia.  **  **  **  **  **  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAHELPERS_H
end_ifndef
begin_define
DECL|macro|QCOCOAHELPERS_H
define|#
directive|define
name|QCOCOAHELPERS_H
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
comment|// This file is not part of the Qt API.  It provides helper functions
end_comment
begin_comment
comment|// for the Cocoa lighthouse plugin. This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be removed.
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
file|"qt_mac_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Conversion functions
end_comment
begin_function_decl
name|QStringList
name|qt_mac_NSArrayToQStringList
parameter_list|(
name|void
modifier|*
name|nsarray
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
modifier|*
name|qt_mac_QStringListToNSMutableArrayVoid
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qt_mac_QStringListToNSMutableArray
specifier|inline
name|NSMutableArray
modifier|*
name|qt_mac_QStringListToNSMutableArray
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|qstrlist
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|NSMutableArray
operator|*
operator|>
operator|(
name|qt_mac_QStringListToNSMutableArrayVoid
argument_list|(
name|qstrlist
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_NSStringToQString
specifier|inline
name|QString
name|qt_mac_NSStringToQString
parameter_list|(
specifier|const
name|NSString
modifier|*
name|nsstr
parameter_list|)
block|{
return|return
name|QCFString
operator|::
name|toQString
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|CFStringRef
operator|>
operator|(
name|nsstr
operator|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_QStringToNSString
specifier|inline
name|NSString
modifier|*
name|qt_mac_QStringToNSString
parameter_list|(
specifier|const
name|QString
modifier|&
name|qstr
parameter_list|)
block|{
return|return
index|[
name|const_cast
operator|<
name|NSString
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|NSString
operator|*
operator|>
operator|(
name|QCFString
operator|::
name|toCFStringRef
argument_list|(
name|qstr
argument_list|)
operator|)
operator|)
name|autorelease
index|]
return|;
block|}
end_function
begin_function_decl
name|CGImageRef
name|qt_mac_image_to_cgimage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSImage
modifier|*
name|qt_mac_cgimage_to_nsimage
parameter_list|(
name|CGImageRef
name|iamge
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSImage
modifier|*
name|qt_mac_create_nsimage
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pm
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSSize
name|qt_mac_toNSSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|qtSize
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QChar
name|qt_mac_qtKey2CocoaKey
argument_list|(
name|Qt
operator|::
name|Key
name|key
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|Key
name|qt_mac_cocoaKey2QtKey
argument_list|(
argument|QChar keyCode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Misc
end_comment
begin_function_decl
name|void
name|qt_mac_transformProccessToForegroundApplication
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|qt_mac_removeMnemonics
parameter_list|(
specifier|const
name|QString
modifier|&
name|original
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|CGColorSpaceRef
name|qt_mac_genericColorSpace
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|CGColorSpaceRef
name|qt_mac_displayColorSpace
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|qt_mac_applicationName
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|qt_mac_flipYCoordinate
specifier|inline
name|int
name|qt_mac_flipYCoordinate
parameter_list|(
name|int
name|y
parameter_list|)
block|{
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|y
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_flipYCoordinate
specifier|inline
name|qreal
name|qt_mac_flipYCoordinate
parameter_list|(
name|qreal
name|y
parameter_list|)
block|{
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|y
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_flipPoint
specifier|inline
name|QPointF
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|NSPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|p
operator|.
name|x
argument_list|,
name|qt_mac_flipYCoordinate
argument_list|(
name|p
operator|.
name|y
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_flipPoint
specifier|inline
name|NSPoint
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|NSMakePoint
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|qt_mac_flipYCoordinate
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_flipPoint
specifier|inline
name|NSPoint
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
return|return
name|NSMakePoint
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|qt_mac_flipYCoordinate
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function_decl
name|NSRect
name|qt_mac_flipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|QWindow
modifier|*
name|window
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
comment|//QCOCOAHELPERS_H
end_comment
end_unit
