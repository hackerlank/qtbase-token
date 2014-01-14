begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
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
begin_include
include|#
directive|include
file|<dxgi1_2.h>
end_include
begin_include
include|#
directive|include
file|<d3d11.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_using
using|using
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
using|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowsDirect2DBackingStorePrivate
class|class
name|QWindowsDirect2DBackingStorePrivate
block|{
public|public:
DECL|function|QWindowsDirect2DBackingStorePrivate
name|QWindowsDirect2DBackingStorePrivate
parameter_list|()
block|{}
DECL|member|swapChain
name|ComPtr
argument_list|<
name|IDXGISwapChain1
argument_list|>
name|swapChain
decl_stmt|;
DECL|member|backingStore
name|QSharedPointer
argument_list|<
name|QWindowsDirect2DBitmap
argument_list|>
name|backingStore
decl_stmt|;
DECL|member|nativePaintDevice
name|QScopedPointer
argument_list|<
name|QWindowsDirect2DPaintDevice
argument_list|>
name|nativePaintDevice
decl_stmt|;
DECL|function|init
name|bool
name|init
parameter_list|(
name|HWND
name|hwnd
parameter_list|)
block|{
name|DXGI_SWAP_CHAIN_DESC1
name|desc
init|=
block|{}
decl_stmt|;
name|desc
operator|.
name|Format
operator|=
name|DXGI_FORMAT_B8G8R8A8_UNORM
expr_stmt|;
name|desc
operator|.
name|SampleDesc
operator|.
name|Count
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|BufferUsage
operator|=
name|DXGI_USAGE_RENDER_TARGET_OUTPUT
expr_stmt|;
name|desc
operator|.
name|BufferCount
operator|=
literal|1
expr_stmt|;
name|desc
operator|.
name|SwapEffect
operator|=
name|DXGI_SWAP_EFFECT_SEQUENTIAL
expr_stmt|;
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|dxgiFactory
argument_list|()
operator|->
name|CreateSwapChainForHwnd
argument_list|(
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d3dDevice
argument_list|()
argument_list|,
comment|// [in]   IUnknown *pDevice
name|hwnd
argument_list|,
comment|// [in]   HWND hWnd
operator|&
name|desc
argument_list|,
comment|// [in]   const DXGI_SWAP_CHAIN_DESC1 *pDesc
name|NULL
argument_list|,
comment|// [in]   const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc
name|NULL
argument_list|,
comment|// [in]   IDXGIOutput *pRestrictToOutput
name|swapChain
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
comment|// [out]  IDXGISwapChain1 **ppSwapChain
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"%s: Could not create swap chain: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
return|;
block|}
DECL|function|setupPaintDevice
name|bool
name|setupPaintDevice
parameter_list|()
block|{
if|if
condition|(
operator|!
name|backingStore
condition|)
block|{
name|ComPtr
argument_list|<
name|ID2D1DeviceContext
argument_list|>
name|deviceContext
decl_stmt|;
name|ComPtr
argument_list|<
name|IDXGISurface1
argument_list|>
name|backBufferSurface
decl_stmt|;
name|ComPtr
argument_list|<
name|ID2D1Bitmap1
argument_list|>
name|backBufferBitmap
decl_stmt|;
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dDevice
argument_list|()
operator|->
name|CreateDeviceContext
argument_list|(
name|D2D1_DEVICE_CONTEXT_OPTIONS_NONE
argument_list|,
name|deviceContext
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Couldn't create Direct2D Device context: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|hr
operator|=
name|swapChain
operator|->
name|GetBuffer
argument_list|(
literal|0
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|backBufferSurface
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not query backbuffer for DXGI Surface: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|hr
operator|=
name|deviceContext
operator|->
name|CreateBitmapFromDxgiSurface
argument_list|(
name|backBufferSurface
operator|.
name|Get
argument_list|()
argument_list|,
name|NULL
argument_list|,
name|backBufferBitmap
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Could not create Direct2D Bitmap from DXGI Surface: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|backingStore
operator|.
name|reset
argument_list|(
operator|new
name|QWindowsDirect2DBitmap
argument_list|(
name|backBufferBitmap
operator|.
name|Get
argument_list|()
argument_list|,
name|deviceContext
operator|.
name|Get
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|nativePaintDevice
condition|)
name|nativePaintDevice
operator|.
name|reset
argument_list|(
operator|new
name|QWindowsDirect2DPaintDevice
argument_list|(
name|backingStore
operator|.
name|data
argument_list|()
argument_list|,
name|QInternal
operator|::
name|Widget
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|releaseBackingStore
name|void
name|releaseBackingStore
parameter_list|()
block|{
name|nativePaintDevice
operator|.
name|reset
argument_list|()
expr_stmt|;
name|backingStore
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
block|{
name|setupPaintDevice
argument_list|()
expr_stmt|;
return|return
name|nativePaintDevice
operator|.
name|data
argument_list|()
return|;
block|}
DECL|function|flush
name|void
name|flush
parameter_list|()
block|{
name|swapChain
operator|->
name|Present
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|/*!     \class QWindowsDirect2DBackingStore     \brief Backing store for windows.     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsDirect2DBackingStore
name|QWindowsDirect2DBackingStore
operator|::
name|QWindowsDirect2DBackingStore
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
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QWindowsDirect2DBackingStorePrivate
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
name|bool
name|QWindowsDirect2DBackingStore
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
condition|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBackingStore
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|init
argument_list|(
name|windowsWindow
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|create
name|QWindowsDirect2DBackingStore
modifier|*
name|QWindowsDirect2DBackingStore
operator|::
name|create
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QWindowsDirect2DBackingStore
modifier|*
name|result
init|=
operator|new
name|QWindowsDirect2DBackingStore
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
operator|->
name|init
argument_list|()
condition|)
block|{
operator|delete
name|result
expr_stmt|;
name|result
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_destructor
DECL|function|~QWindowsDirect2DBackingStore
name|QWindowsDirect2DBackingStore
operator|::
name|~
name|QWindowsDirect2DBackingStore
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBackingStore
argument_list|)
expr_stmt|;
name|d
operator|->
name|releaseBackingStore
argument_list|()
expr_stmt|;
name|d
operator|->
name|swapChain
operator|.
name|Reset
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWindowsDirect2DBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
name|QPaintDevice
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
condition|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBackingStore
argument_list|)
expr_stmt|;
name|result
operator|=
name|d
operator|->
name|paintDevice
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsDirect2DBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|,
specifier|const
name|QPoint
modifier|&
parameter_list|)
block|{
if|if
condition|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
condition|)
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DBackingStore
argument_list|)
expr_stmt|;
name|d
operator|->
name|flush
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWindowsDirect2DBackingStore
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
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|!=
name|QSurface
operator|::
name|RasterSurface
condition|)
return|return;
name|Q_D
argument_list|(
name|QWindowsDirect2DBackingStore
argument_list|)
expr_stmt|;
name|d
operator|->
name|releaseBackingStore
argument_list|()
expr_stmt|;
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d3dDeviceContext
argument_list|()
operator|->
name|ClearState
argument_list|()
expr_stmt|;
name|HRESULT
name|hr
init|=
name|d
operator|->
name|swapChain
operator|->
name|ResizeBuffers
argument_list|(
literal|0
argument_list|,
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
name|DXGI_FORMAT_UNKNOWN
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"%s: Could not resize buffers: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowsWindow
name|QWindowsWindow
modifier|*
name|QWindowsDirect2DBackingStore
operator|::
name|windowsWindow
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit