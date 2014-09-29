begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|NSImage
modifier|*
name|qt_mac_create_nsimage
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|CGImageRef
name|qt_mac_toCGImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|qImage
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|CGImageRef
name|qt_mac_toCGImageMask
parameter_list|(
specifier|const
name|QImage
modifier|&
name|qImage
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QImage
name|qt_mac_toQImage
parameter_list|(
name|CGImageRef
name|image
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
begin_function_decl
name|NSRect
name|qt_mac_toNSRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QRect
name|qt_mac_toQRect
parameter_list|(
specifier|const
name|NSRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QColor
name|qt_mac_toQColor
parameter_list|(
specifier|const
name|NSColor
modifier|*
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QColor
name|qt_mac_toQColor
parameter_list|(
name|CGColorRef
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Creates a mutable shape, it's the caller's responsibility to release.
end_comment
begin_function_decl
name|HIMutableShapeRef
name|qt_mac_QRegionToHIMutableShape
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|OSStatus
name|qt_mac_drawCGImage
parameter_list|(
name|CGContextRef
name|inContext
parameter_list|,
specifier|const
name|CGRect
modifier|*
name|inBounds
parameter_list|,
name|CGImageRef
name|inImage
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
begin_decl_stmt
name|NSDragOperation
name|qt_mac_mapDropAction
argument_list|(
name|Qt
operator|::
name|DropAction
name|action
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|NSDragOperation
name|qt_mac_mapDropActions
argument_list|(
name|Qt
operator|::
name|DropActions
name|actions
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|DropAction
name|qt_mac_mapNSDragOperation
argument_list|(
argument|NSDragOperation nsActions
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Qt
operator|::
name|DropActions
name|qt_mac_mapNSDragOperations
argument_list|(
argument|NSDragOperation nsActions
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
name|CGColorSpaceRef
name|qt_mac_colorSpaceForDeviceType
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|qt_mac_applicationName
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|int
name|qt_mac_flipYCoordinate
parameter_list|(
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qreal
name|qt_mac_flipYCoordinate
parameter_list|(
name|qreal
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPointF
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|NSPoint
modifier|&
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSPoint
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSPoint
name|qt_mac_flipPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|NSRect
name|qt_mac_flipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Qt
operator|::
name|MouseButton
name|cocoaButton2QtButton
argument_list|(
argument|NSInteger buttonNum
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|qt_mac_execute_apple_script
parameter_list|(
specifier|const
name|char
modifier|*
name|script
parameter_list|,
name|long
name|script_len
parameter_list|,
name|AEDesc
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qt_mac_execute_apple_script
parameter_list|(
specifier|const
name|char
modifier|*
name|script
parameter_list|,
name|AEDesc
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qt_mac_execute_apple_script
parameter_list|(
specifier|const
name|QString
modifier|&
name|script
parameter_list|,
name|AEDesc
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// strip out '&' characters, and convert "&&" to a single '&', in menu
end_comment
begin_comment
comment|// text - since menu text is sometimes decorated with these for Windows
end_comment
begin_comment
comment|// accelerators.
end_comment
begin_function_decl
name|QString
name|qt_mac_removeAmpersandEscapes
parameter_list|(
name|QString
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_enum
enum|enum
block|{
DECL|enumerator|QtCocoaEventSubTypeWakeup
name|QtCocoaEventSubTypeWakeup
init|=
name|SHRT_MAX
block|,
DECL|enumerator|QtCocoaEventSubTypePostMessage
name|QtCocoaEventSubTypePostMessage
init|=
name|SHRT_MAX
operator|-
literal|1
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|QCocoaPostMessageArgs
block|{
name|public
label|:
name|id
name|target
decl_stmt|;
name|SEL
name|selector
decl_stmt|;
name|int
name|argCount
decl_stmt|;
name|id
name|arg1
decl_stmt|;
name|id
name|arg2
decl_stmt|;
name|QCocoaPostMessageArgs
argument_list|(
argument|id target
argument_list|,
argument|SEL selector
argument_list|,
argument|int argCount=
literal|0
argument_list|,
argument|id arg1=
literal|0
argument_list|,
argument|id arg2=
literal|0
argument_list|)
block|:
name|target
argument_list|(
name|target
argument_list|)
operator|,
name|selector
argument_list|(
name|selector
argument_list|)
operator|,
name|argCount
argument_list|(
name|argCount
argument_list|)
operator|,
name|arg1
argument_list|(
name|arg1
argument_list|)
operator|,
name|arg2
argument_list|(
argument|arg2
argument_list|)
block|{
index|[
name|target
name|retain
index|]
block|;
index|[
name|arg1
name|retain
index|]
block|;
index|[
name|arg2
name|retain
index|]
block|;     }
operator|~
name|QCocoaPostMessageArgs
argument_list|()
block|{
index|[
name|arg2
name|release
index|]
block|;
index|[
name|arg1
name|release
index|]
block|;
index|[
name|target
name|release
index|]
block|;     }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|CGContextRef
name|qt_mac_cg_context
parameter_list|(
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qt_mac_resolveOption
name|T
name|qt_mac_resolveOption
argument_list|(
argument|const T&fallback
argument_list|,
argument|const QByteArray&environment
argument_list|)
block|{
comment|// check for environment variable
if|if
condition|(
operator|!
name|environment
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QByteArray
name|env
init|=
name|qgetenv
argument_list|(
name|environment
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|T
argument_list|(
name|env
operator|.
name|toInt
argument_list|()
argument_list|)
return|;
comment|// works when T is bool, int.
block|}
end_expr_stmt
begin_return
return|return
name|fallback
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|qt_mac_resolveOption
name|T
name|qt_mac_resolveOption
argument_list|(
argument|const T&fallback
argument_list|,
argument|QWindow *window
argument_list|,
argument|const QByteArray&property
argument_list|,
argument|const QByteArray&environment
argument_list|)
block|{
comment|// check for environment variable
if|if
condition|(
operator|!
name|environment
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QByteArray
name|env
init|=
name|qgetenv
argument_list|(
name|environment
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|env
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|T
argument_list|(
name|env
operator|.
name|toInt
argument_list|()
argument_list|)
return|;
comment|// works when T is bool, int.
block|}
end_expr_stmt
begin_comment
comment|// check for window property
end_comment
begin_if
if|if
condition|(
name|window
operator|&&
operator|!
name|property
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QVariant
name|windowProperty
init|=
name|window
operator|->
name|property
argument_list|(
name|property
argument_list|)
decl_stmt|;
if|if
condition|(
name|windowProperty
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|windowProperty
operator|.
name|value
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
end_if
begin_comment
comment|// return default value.
end_comment
begin_return
return|return
name|fallback
return|;
end_return
begin_endif
unit|} QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|//QCOCOAHELPERS_H
end_comment
end_unit
