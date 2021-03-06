begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2016 The Qt Company Ltd.  ** Contact: https://www.qt.io/licensing/  **  ** This file is part of the QtGui module of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see https://www.qt.io/terms-conditions. For further  ** information use the contact form at https://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 3 as published by the Free Software  ** Foundation and appearing in the file LICENSE.LGPL3 included in the  ** packaging of this file. Please review the following information to  ** ensure the GNU Lesser General Public License version 3 requirements  ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU  ** General Public License version 2.0 or (at your option) the GNU General  ** Public license version 3 or any later version approved by the KDE Free  ** Qt Foundation. The licenses are as published by the Free Software  ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3  ** included in the packaging of this file. Please review the following  ** information to ensure the GNU General Public License requirements will  ** be met: https://www.gnu.org/licenses/gpl-2.0.html and  ** https://www.gnu.org/licenses/gpl-3.0.html.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qrasterwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintdevicewindow_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QBackingStore>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QRasterWindow   \inmodule QtGui   \since 5.4   \brief QRasterWindow is a convenience class for using QPainter on a QWindow    QRasterWindow is a QWindow with a raster-based, non-OpenGL surface. On top of   the functionality offered by QWindow, QRasterWindow adds a virtual   paintEvent() function and the possibility to open a QPainter on itself. The   underlying paint engine will be the raster one, meaning that all drawing will   happen on the CPU. For performing accelerated, OpenGL-based drawing, use   QOpenGLWindow instead.    Internally the class is thin wrapper for QWindow and QBackingStore   and is very similar to the \l{Raster Window Example}{Raster Window   Example} that uses these classes directly.    \sa QPaintDeviceWindow::paintEvent(), QPaintDeviceWindow::update() */
end_comment
begin_class
DECL|class|QRasterWindowPrivate
class|class
name|QRasterWindowPrivate
super|:
specifier|public
name|QPaintDeviceWindowPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QRasterWindow
parameter_list|)
specifier|public
private|:
name|void
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_Q
argument_list|(
name|QRasterWindow
argument_list|)
expr_stmt|;
specifier|const
name|QSize
name|size
init|=
name|q
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|backingstore
operator|->
name|size
argument_list|()
operator|!=
name|size
condition|)
block|{
name|backingstore
operator|->
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|markWindowAsDirty
argument_list|()
expr_stmt|;
block|}
name|backingstore
operator|->
name|beginPaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
name|void
name|endPaint
parameter_list|()
name|Q_DECL_OVERRIDE
block|{
name|backingstore
operator|->
name|endPaint
argument_list|()
expr_stmt|;
block|}
name|void
name|flush
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_Q
argument_list|(
name|QRasterWindow
argument_list|)
expr_stmt|;
name|backingstore
operator|->
name|flush
argument_list|(
name|region
argument_list|,
name|q
argument_list|)
expr_stmt|;
block|}
DECL|member|backingstore
name|QScopedPointer
argument_list|<
name|QBackingStore
argument_list|>
name|backingstore
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!   Constructs a new QRasterWindow with \a parent. */
end_comment
begin_constructor
DECL|function|QRasterWindow
name|QRasterWindow
operator|::
name|QRasterWindow
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QPaintDeviceWindow
argument_list|(
operator|*
operator|(
operator|new
name|QRasterWindowPrivate
operator|)
argument_list|,
name|parent
argument_list|)
block|{
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|RasterSurface
argument_list|)
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|backingstore
operator|.
name|reset
argument_list|(
operator|new
name|QBackingStore
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|metric
name|int
name|QRasterWindow
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QRasterWindow
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PdmDepth
case|:
return|return
name|d
operator|->
name|backingstore
operator|->
name|paintDevice
argument_list|()
operator|->
name|depth
argument_list|()
return|;
default|default:
break|break;
block|}
return|return
name|QPaintDeviceWindow
operator|::
name|metric
argument_list|(
name|metric
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|redirected
name|QPaintDevice
modifier|*
name|QRasterWindow
operator|::
name|redirected
parameter_list|(
name|QPoint
modifier|*
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QRasterWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|backingstore
operator|->
name|paintDevice
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
