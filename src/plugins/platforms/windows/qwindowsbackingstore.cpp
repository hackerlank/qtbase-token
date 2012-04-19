begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsnativeimage.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsBackingStore     \brief Backing store for windows.     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|QWindowsBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|~
name|QWindowsBackingStore
parameter_list|()
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWindowsBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|&
name|m_image
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
comment|// TODO: Prepare paint for translucent windows.
specifier|const
name|QRect
name|br
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|1
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|window
operator|<<
name|offset
operator|<<
name|br
expr_stmt|;
name|QWindowsWindow
modifier|*
name|rw
init|=
name|rasterWindow
argument_list|()
decl_stmt|;
specifier|const
name|HDC
name|dc
init|=
name|rw
operator|->
name|getDC
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dc
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"%s: GetDC failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|BitBlt
argument_list|(
name|dc
argument_list|,
name|br
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
argument_list|,
name|br
operator|.
name|width
argument_list|()
argument_list|,
name|br
operator|.
name|height
argument_list|()
argument_list|,
name|m_image
operator|->
name|hdc
argument_list|()
argument_list|,
name|br
operator|.
name|x
argument_list|()
operator|+
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
operator|+
name|offset
operator|.
name|y
argument_list|()
argument_list|,
name|SRCCOPY
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
literal|"%s: BitBlt failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|rw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
comment|// Write image for debug purposes.
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|2
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|fileName
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"win%1_%2.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|rw
operator|->
name|winId
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|n
operator|++
argument_list|)
decl_stmt|;
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|save
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Wrote "
operator|<<
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|<<
name|fileName
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWindowsBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
block|{
name|QDebug
name|nsp
init|=
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|nsp
operator|<<
name|__FUNCTION__
operator|<<
literal|' '
operator|<<
name|rasterWindow
argument_list|()
operator|->
name|window
argument_list|()
operator|<<
literal|' '
operator|<<
name|size
operator|<<
literal|' '
operator|<<
name|region
expr_stmt|;
if|if
condition|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
name|nsp
operator|<<
literal|" from: "
operator|<<
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
name|m_image
operator|.
name|reset
argument_list|(
operator|new
name|QWindowsNativeImage
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|QWindowsNativeImage
operator|::
name|systemFormat
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWindowsBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|1
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rasterWindow
name|QWindowsWindow
modifier|*
name|QWindowsBackingStore
operator|::
name|rasterWindow
parameter_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|w
init|=
name|window
argument_list|()
condition|)
if|if
condition|(
name|QPlatformWindow
modifier|*
name|pw
init|=
name|w
operator|->
name|handle
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|pw
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|getDC
name|HDC
name|QWindowsBackingStore
operator|::
name|getDC
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|m_image
operator|->
name|hdc
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
