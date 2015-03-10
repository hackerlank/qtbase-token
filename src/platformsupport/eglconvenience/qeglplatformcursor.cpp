begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"qeglplatformcursor_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformintegration_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformscreen_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QEGLPlatformCursor     \brief Mouse cursor implementation using OpenGL.     \since 5.2     \internal     \ingroup qpa  */
end_comment
begin_constructor
DECL|function|QEGLPlatformCursor
name|QEGLPlatformCursor
operator|::
name|QEGLPlatformCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_visible
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_screen
argument_list|(
cast|static_cast
argument_list|<
name|QEGLPlatformScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
argument_list|)
member_init_list|,
name|m_program
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_vertexCoordEntry
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_textureCoordEntry
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_textureEntry
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_deviceListener
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_updateRequested
argument_list|(
literal|false
argument_list|)
block|{
name|QByteArray
name|hideCursorVal
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_HIDECURSOR"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hideCursorVal
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_visible
operator|=
name|hideCursorVal
operator|.
name|toInt
argument_list|()
operator|==
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|m_visible
condition|)
return|return;
comment|// Try to load the cursor atlas. If this fails, m_visible is set to false and
comment|// paintOnScreen() and setCurrentCursor() become no-ops.
name|initCursorAtlas
argument_list|()
expr_stmt|;
comment|// initialize the cursor
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QCursor
name|cursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
decl_stmt|;
name|setCurrentCursor
argument_list|(
operator|&
name|cursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_deviceListener
operator|=
operator|new
name|QEGLPlatformCursorDeviceListener
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|,
operator|&
name|QInputDeviceManager
operator|::
name|deviceListChanged
argument_list|,
name|m_deviceListener
argument_list|,
operator|&
name|QEGLPlatformCursorDeviceListener
operator|::
name|onDeviceListChanged
argument_list|)
expr_stmt|;
name|updateMouseStatus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEGLPlatformCursor
name|QEGLPlatformCursor
operator|::
name|~
name|QEGLPlatformCursor
parameter_list|()
block|{
name|resetResources
argument_list|()
expr_stmt|;
operator|delete
name|m_deviceListener
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|updateMouseStatus
name|void
name|QEGLPlatformCursor
operator|::
name|updateMouseStatus
parameter_list|()
block|{
name|m_visible
operator|=
name|m_deviceListener
operator|->
name|hasMouse
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasMouse
name|bool
name|QEGLPlatformCursorDeviceListener
operator|::
name|hasMouse
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
operator|->
name|deviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
argument_list|)
operator|>
literal|0
return|;
block|}
end_function
begin_function
DECL|function|onDeviceListChanged
name|void
name|QEGLPlatformCursorDeviceListener
operator|::
name|onDeviceListChanged
parameter_list|(
name|QInputDeviceManager
operator|::
name|DeviceType
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
condition|)
name|m_cursor
operator|->
name|updateMouseStatus
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetResources
name|void
name|QEGLPlatformCursor
operator|::
name|resetResources
parameter_list|()
block|{
if|if
condition|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
condition|)
block|{
operator|delete
name|m_program
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_cursor
operator|.
name|customCursorTexture
argument_list|)
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_cursorAtlas
operator|.
name|texture
argument_list|)
expr_stmt|;
block|}
name|m_program
operator|=
literal|0
expr_stmt|;
name|m_cursor
operator|.
name|customCursorTexture
operator|=
literal|0
expr_stmt|;
name|m_cursor
operator|.
name|customCursorPending
operator|=
operator|!
name|m_cursor
operator|.
name|customCursorImage
operator|.
name|isNull
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|texture
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createShaderPrograms
name|void
name|QEGLPlatformCursor
operator|::
name|createShaderPrograms
parameter_list|()
block|{
specifier|static
specifier|const
name|char
modifier|*
name|textureVertexProgram
init|=
literal|"attribute highp vec2 vertexCoordEntry;\n"
literal|"attribute highp vec2 textureCoordEntry;\n"
literal|"varying highp vec2 textureCoord;\n"
literal|"void main() {\n"
literal|"   textureCoord = textureCoordEntry;\n"
literal|"   gl_Position = vec4(vertexCoordEntry, 1.0, 1.0);\n"
literal|"}\n"
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|textureFragmentProgram
init|=
literal|"uniform sampler2D texture;\n"
literal|"varying highp vec2 textureCoord;\n"
literal|"void main() {\n"
literal|"   gl_FragColor = texture2D(texture, textureCoord).bgra;\n"
literal|"}\n"
decl_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|textureVertexProgram
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|textureFragmentProgram
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|link
argument_list|()
expr_stmt|;
name|m_vertexCoordEntry
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"vertexCoordEntry"
argument_list|)
expr_stmt|;
name|m_textureCoordEntry
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"textureCoordEntry"
argument_list|)
expr_stmt|;
name|m_textureEntry
operator|=
name|m_program
operator|->
name|uniformLocation
argument_list|(
literal|"texture"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createCursorTexture
name|void
name|QEGLPlatformCursor
operator|::
name|createCursorTexture
parameter_list|(
name|uint
modifier|*
name|texture
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|*
name|texture
condition|)
name|glGenTextures
argument_list|(
literal|1
argument_list|,
name|texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
operator|*
name|texture
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
comment|/* level */
argument_list|,
name|GL_RGBA
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|0
comment|/* border */
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initCursorAtlas
name|void
name|QEGLPlatformCursor
operator|::
name|initCursorAtlas
parameter_list|()
block|{
specifier|static
name|QByteArray
name|json
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_CURSOR"
argument_list|)
decl_stmt|;
if|if
condition|(
name|json
operator|.
name|isEmpty
argument_list|()
condition|)
name|json
operator|=
literal|":/cursor.json"
expr_stmt|;
name|QFile
name|file
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|json
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|m_visible
operator|=
literal|false
expr_stmt|;
return|return;
block|}
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
name|QString
name|atlas
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"image"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|atlas
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|cursorsPerRow
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"cursorsPerRow"
argument_list|)
argument_list|)
operator|.
name|toDouble
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|cursorsPerRow
argument_list|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|=
name|cursorsPerRow
expr_stmt|;
specifier|const
name|QJsonArray
name|hotSpots
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"hotSpots"
argument_list|)
argument_list|)
operator|.
name|toArray
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|hotSpots
operator|.
name|count
argument_list|()
operator|==
name|Qt
operator|::
name|LastCursor
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|hotSpots
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QPoint
name|hotSpot
argument_list|(
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|0
index|]
operator|.
name|toDouble
argument_list|()
argument_list|,
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|1
index|]
operator|.
name|toDouble
argument_list|()
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|hotSpots
operator|<<
name|hotSpot
expr_stmt|;
block|}
name|QImage
name|image
init|=
name|QImage
argument_list|(
name|atlas
argument_list|)
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|=
name|image
operator|.
name|width
argument_list|()
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|=
name|image
operator|.
name|height
argument_list|()
operator|/
operator|(
operator|(
name|Qt
operator|::
name|LastCursor
operator|+
name|cursorsPerRow
operator|)
operator|/
name|cursorsPerRow
operator|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|width
operator|=
name|image
operator|.
name|width
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|height
operator|=
name|image
operator|.
name|height
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|image
operator|=
name|image
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_function
DECL|function|changeCursor
name|void
name|QEGLPlatformCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|setCurrentCursor
argument_list|(
name|cursor
argument_list|)
condition|)
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentCursor
name|bool
name|QEGLPlatformCursor
operator|::
name|setCurrentCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_visible
condition|)
return|return
literal|false
return|;
specifier|const
name|Qt
operator|::
name|CursorShape
name|newShape
init|=
name|cursor
condition|?
name|cursor
operator|->
name|shape
argument_list|()
else|:
name|Qt
operator|::
name|ArrowCursor
decl_stmt|;
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|newShape
operator|&&
name|newShape
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_cursor
operator|.
name|customCursorImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
name|m_cursor
operator|.
name|customCursorPending
operator|=
literal|false
expr_stmt|;
block|}
name|m_cursor
operator|.
name|shape
operator|=
name|newShape
expr_stmt|;
if|if
condition|(
name|newShape
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
comment|// standard cursor
specifier|const
name|float
name|ws
init|=
operator|(
name|float
operator|)
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|/
name|m_cursorAtlas
operator|.
name|width
decl_stmt|,
name|hs
init|=
operator|(
name|float
operator|)
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|/
name|m_cursorAtlas
operator|.
name|height
decl_stmt|;
name|m_cursor
operator|.
name|textureRect
operator|=
name|QRectF
argument_list|(
name|ws
operator|*
operator|(
name|m_cursor
operator|.
name|shape
operator|%
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
argument_list|,
name|hs
operator|*
operator|(
name|m_cursor
operator|.
name|shape
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
argument_list|,
name|ws
argument_list|,
name|hs
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|hotSpot
operator|=
name|m_cursorAtlas
operator|.
name|hotSpots
index|[
name|m_cursor
operator|.
name|shape
index|]
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursorAtlas
operator|.
name|texture
expr_stmt|;
name|m_cursor
operator|.
name|size
operator|=
name|QSize
argument_list|(
name|m_cursorAtlas
operator|.
name|cursorWidth
argument_list|,
name|m_cursorAtlas
operator|.
name|cursorHeight
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QImage
name|image
init|=
name|cursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|m_cursor
operator|.
name|textureRect
operator|=
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|hotSpot
operator|=
name|cursor
operator|->
name|hotSpot
argument_list|()
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
literal|0
expr_stmt|;
comment|// will get updated in the next render()
name|m_cursor
operator|.
name|size
operator|=
name|image
operator|.
name|size
argument_list|()
expr_stmt|;
name|m_cursor
operator|.
name|customCursorImage
operator|=
name|image
expr_stmt|;
name|m_cursor
operator|.
name|customCursorPending
operator|=
literal|true
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|CursorUpdateEvent
class|class
name|CursorUpdateEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|function|CursorUpdateEvent
name|CursorUpdateEvent
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
member_init_list|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|)
member_init_list|,
name|m_pos
argument_list|(
name|pos
argument_list|)
member_init_list|,
name|m_region
argument_list|(
name|rgn
argument_list|)
block|{ }
DECL|function|pos
name|QPoint
name|pos
parameter_list|()
specifier|const
block|{
return|return
name|m_pos
return|;
block|}
DECL|function|region
name|QRegion
name|region
parameter_list|()
specifier|const
block|{
return|return
name|m_region
return|;
block|}
private|private:
DECL|member|m_pos
name|QPoint
name|m_pos
decl_stmt|;
DECL|member|m_region
name|QRegion
name|m_region
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|event
name|bool
name|QEGLPlatformCursor
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|User
operator|+
literal|1
condition|)
block|{
name|CursorUpdateEvent
modifier|*
name|ev
init|=
cast|static_cast
argument_list|<
name|CursorUpdateEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|m_updateRequested
operator|=
literal|false
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|m_screen
operator|->
name|topLevelAt
argument_list|(
name|ev
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|,
name|ev
operator|->
name|region
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|(
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QPlatformCursor
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QEGLPlatformCursor
operator|::
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_updateRequested
condition|)
block|{
comment|// Must not flush the window system events directly from here since we are likely to
comment|// be a called directly from QGuiApplication's processMouseEvents. Flushing events
comment|// could cause reentering by dispatching more queued mouse events.
name|m_updateRequested
operator|=
literal|true
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|CursorUpdateEvent
argument_list|(
name|m_cursor
operator|.
name|pos
argument_list|,
name|rgn
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cursorRect
name|QRect
name|QEGLPlatformCursor
operator|::
name|cursorRect
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|m_cursor
operator|.
name|pos
operator|-
name|m_cursor
operator|.
name|hotSpot
argument_list|,
name|m_cursor
operator|.
name|size
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pos
name|QPoint
name|QEGLPlatformCursor
operator|::
name|pos
parameter_list|()
specifier|const
block|{
return|return
name|m_cursor
operator|.
name|pos
return|;
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|QEGLPlatformCursor
operator|::
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
operator|->
name|setCursorPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
name|m_cursor
operator|.
name|pos
operator|=
name|pos
expr_stmt|;
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
name|m_screen
operator|->
name|handleCursorMove
argument_list|(
name|m_cursor
operator|.
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pointerEvent
name|void
name|QEGLPlatformCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|.
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseMove
condition|)
return|return;
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
name|m_cursor
operator|.
name|pos
operator|=
name|event
operator|.
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
expr_stmt|;
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
name|m_screen
operator|->
name|handleCursorMove
argument_list|(
name|m_cursor
operator|.
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintOnScreen
name|void
name|QEGLPlatformCursor
operator|::
name|paintOnScreen
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_visible
condition|)
return|return;
specifier|const
name|QRectF
name|cr
init|=
name|cursorRect
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|screenRect
argument_list|(
name|m_screen
operator|->
name|geometry
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|GLfloat
name|x1
init|=
literal|2
operator|*
operator|(
name|cr
operator|.
name|left
argument_list|()
operator|/
name|screenRect
operator|.
name|width
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|GLfloat
name|x2
init|=
literal|2
operator|*
operator|(
name|cr
operator|.
name|right
argument_list|()
operator|/
name|screenRect
operator|.
name|width
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|GLfloat
name|y1
init|=
literal|1
operator|-
operator|(
name|cr
operator|.
name|top
argument_list|()
operator|/
name|screenRect
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
decl_stmt|;
specifier|const
name|GLfloat
name|y2
init|=
literal|1
operator|-
operator|(
name|cr
operator|.
name|bottom
argument_list|()
operator|/
name|screenRect
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
decl_stmt|;
name|QRectF
name|r
argument_list|(
name|QPointF
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|)
argument_list|)
decl_stmt|;
name|draw
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|draw
name|void
name|QEGLPlatformCursor
operator|::
name|draw
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_program
condition|)
block|{
comment|// one time initialization
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|createShaderPrograms
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_cursorAtlas
operator|.
name|texture
condition|)
block|{
name|createCursorTexture
argument_list|(
operator|&
name|m_cursorAtlas
operator|.
name|texture
argument_list|,
name|m_cursorAtlas
operator|.
name|image
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursorAtlas
operator|.
name|texture
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
operator|&&
name|m_cursor
operator|.
name|customCursorPending
condition|)
block|{
comment|// upload the custom cursor
name|createCursorTexture
argument_list|(
operator|&
name|m_cursor
operator|.
name|customCursorTexture
argument_list|,
name|m_cursor
operator|.
name|customCursorImage
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursor
operator|.
name|customCursorTexture
expr_stmt|;
name|m_cursor
operator|.
name|customCursorPending
operator|=
literal|false
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|m_cursor
operator|.
name|texture
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
specifier|const
name|GLfloat
name|x1
init|=
name|r
operator|.
name|left
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|x2
init|=
name|r
operator|.
name|right
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|y1
init|=
name|r
operator|.
name|top
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|y2
init|=
name|r
operator|.
name|bottom
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|cursorCoordinates
index|[]
init|=
block|{
name|x1
block|,
name|y2
block|,
name|x2
block|,
name|y2
block|,
name|x1
block|,
name|y1
block|,
name|x2
block|,
name|y1
block|}
decl_stmt|;
specifier|const
name|GLfloat
name|s1
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|left
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|s2
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|right
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|t1
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|top
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|t2
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|bottom
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|textureCoordinates
index|[]
init|=
block|{
name|s1
block|,
name|t2
block|,
name|s2
block|,
name|t2
block|,
name|s1
block|,
name|t1
block|,
name|s2
block|,
name|t1
block|}
decl_stmt|;
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_cursor
operator|.
name|texture
argument_list|)
expr_stmt|;
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|enableAttributeArray
argument_list|(
name|m_vertexCoordEntry
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|enableAttributeArray
argument_list|(
name|m_textureCoordEntry
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setAttributeArray
argument_list|(
name|m_vertexCoordEntry
argument_list|,
name|cursorCoordinates
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setAttributeArray
argument_list|(
name|m_textureCoordEntry
argument_list|,
name|textureCoordinates
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
name|m_textureEntry
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glFrontFace
argument_list|(
name|GL_CCW
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glBlendFunc
argument_list|(
name|GL_ONE
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
comment|// disable depth testing to make sure cursor is always on top
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_STRIP
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|disableAttributeArray
argument_list|(
name|m_textureCoordEntry
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|disableAttributeArray
argument_list|(
name|m_vertexCoordEntry
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
