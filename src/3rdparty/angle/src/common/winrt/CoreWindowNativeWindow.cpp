begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// CoreWindowNativeWindow.cpp: NativeWindow for managing ICoreWindow native window types.
end_comment
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|"common/winrt/CoreWindowNativeWindow.h"
end_include
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
namespace|;
end_using
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|typedef|SizeChangedHandler
typedef|typedef
name|ITypedEventHandler
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|CoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|WindowSizeChangedEventArgs
operator|*
argument_list|>
name|SizeChangedHandler
typedef|;
DECL|function|~CoreWindowNativeWindow
name|CoreWindowNativeWindow
operator|::
name|~
name|CoreWindowNativeWindow
parameter_list|()
block|{
name|unregisterForSizeChangeEvents
argument_list|()
expr_stmt|;
block|}
DECL|function|initialize
name|bool
name|CoreWindowNativeWindow
operator|::
name|initialize
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|,
name|EGLNativeDisplayType
name|display
parameter_list|,
name|IPropertySet
modifier|*
name|propertySet
parameter_list|)
block|{
name|ComPtr
argument_list|<
name|IPropertySet
argument_list|>
name|props
init|=
name|propertySet
decl_stmt|;
name|ComPtr
argument_list|<
name|IInspectable
argument_list|>
name|win
init|=
name|window
decl_stmt|;
name|ComPtr
argument_list|<
name|IInspectable
argument_list|>
name|displayInformation
init|=
name|display
decl_stmt|;
name|SIZE
name|swapChainSize
init|=
block|{}
decl_stmt|;
name|bool
name|swapChainSizeSpecified
init|=
literal|false
decl_stmt|;
name|HRESULT
name|result
init|=
name|S_OK
decl_stmt|;
comment|// IPropertySet is an optional parameter and can be null.
comment|// If one is specified, cache as an IMap and read the properties
comment|// used for initial host initialization.
if|if
condition|(
name|propertySet
condition|)
block|{
name|result
operator|=
name|props
operator|.
name|As
argument_list|(
operator|&
name|mPropertyMap
argument_list|)
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// The EGLRenderSurfaceSizeProperty is optional and may be missing.  The IPropertySet
comment|// was prevalidated to contain the EGLNativeWindowType before being passed to
comment|// this host.
name|result
operator|=
name|GetOptionalSizePropertyValue
argument_list|(
name|mPropertyMap
argument_list|,
name|EGLRenderSurfaceSizeProperty
argument_list|,
operator|&
name|swapChainSize
argument_list|,
operator|&
name|swapChainSizeSpecified
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|win
operator|.
name|As
argument_list|(
operator|&
name|mCoreWindow
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|displayInformation
operator|.
name|As
argument_list|(
operator|&
name|mDisplayInformation
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
if|#
directive|if
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PHONE_APP
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|Graphics
operator|::
name|Display
operator|::
name|IDisplayInformation2
argument_list|>
name|displayInformation2
decl_stmt|;
name|result
operator|=
name|mDisplayInformation
operator|.
name|As
argument_list|(
operator|&
name|displayInformation2
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|displayInformation2
operator|->
name|get_RawPixelsPerViewPixel
argument_list|(
operator|&
name|mScaleFactor
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|ABI
operator|::
name|Windows
operator|::
name|Graphics
operator|::
name|Display
operator|::
name|ResolutionScale
name|resolutionScale
decl_stmt|;
name|result
operator|=
name|mDisplayInformation
operator|->
name|get_ResolutionScale
argument_list|(
operator|&
name|resolutionScale
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|mScaleFactor
operator|=
name|DOUBLE
argument_list|(
name|resolutionScale
argument_list|)
operator|/
literal|100.0
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// If a swapchain size is specfied, then the automatic resize
comment|// behaviors implemented by the host should be disabled.  The swapchain
comment|// will be still be scaled when being rendered to fit the bounds
comment|// of the host.
comment|// Scaling of the swapchain output occurs automatically because if
comment|// the scaling mode setting DXGI_SCALING_STRETCH on the swapchain.
if|if
condition|(
name|swapChainSizeSpecified
condition|)
block|{
name|mClientRect
operator|=
block|{
literal|0
block|,
literal|0
block|,
name|swapChainSize
operator|.
name|cx
block|,
name|swapChainSize
operator|.
name|cy
block|}
expr_stmt|;
name|mSupportsSwapChainResize
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Rect
name|rect
decl_stmt|;
name|HRESULT
name|result
init|=
name|mCoreWindow
operator|->
name|get_Bounds
argument_list|(
operator|&
name|rect
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|LONG
name|width
init|=
name|std
operator|::
name|floor
argument_list|(
name|rect
operator|.
name|Width
operator|*
name|mScaleFactor
operator|+
literal|0.5
argument_list|)
decl_stmt|;
name|LONG
name|height
init|=
name|std
operator|::
name|floor
argument_list|(
name|rect
operator|.
name|Height
operator|*
name|mScaleFactor
operator|+
literal|0.5
argument_list|)
decl_stmt|;
name|mClientRect
operator|=
block|{
literal|0
block|,
literal|0
block|,
name|width
block|,
name|height
block|}
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mNewClientRect
operator|=
name|mClientRect
expr_stmt|;
name|mClientRectChanged
operator|=
literal|false
expr_stmt|;
return|return
name|registerForSizeChangeEvents
argument_list|()
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|registerForSizeChangeEvents
name|bool
name|CoreWindowNativeWindow
operator|::
name|registerForSizeChangeEvents
parameter_list|()
block|{
name|HRESULT
name|result
init|=
name|mCoreWindow
operator|->
name|add_SizeChanged
argument_list|(
name|Callback
argument_list|<
name|SizeChangedHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|CoreWindowNativeWindow
operator|::
name|onSizeChanged
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|mSizeChangedEventToken
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|unregisterForSizeChangeEvents
name|void
name|CoreWindowNativeWindow
operator|::
name|unregisterForSizeChangeEvents
parameter_list|()
block|{
if|if
condition|(
name|mCoreWindow
condition|)
block|{
operator|(
name|void
operator|)
name|mCoreWindow
operator|->
name|remove_SizeChanged
argument_list|(
name|mSizeChangedEventToken
argument_list|)
expr_stmt|;
block|}
name|mSizeChangedEventToken
operator|.
name|value
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|createSwapChain
name|HRESULT
name|CoreWindowNativeWindow
operator|::
name|createSwapChain
parameter_list|(
name|ID3D11Device
modifier|*
name|device
parameter_list|,
name|DXGIFactory
modifier|*
name|factory
parameter_list|,
name|DXGI_FORMAT
name|format
parameter_list|,
name|unsigned
name|int
name|width
parameter_list|,
name|unsigned
name|int
name|height
parameter_list|,
name|DXGISwapChain
modifier|*
modifier|*
name|swapChain
parameter_list|)
block|{
if|if
condition|(
name|device
operator|==
name|NULL
operator|||
name|factory
operator|==
name|NULL
operator|||
name|swapChain
operator|==
name|NULL
operator|||
name|width
operator|==
literal|0
operator|||
name|height
operator|==
literal|0
condition|)
block|{
return|return
name|E_INVALIDARG
return|;
block|}
name|DXGI_SWAP_CHAIN_DESC1
name|swapChainDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|swapChainDesc
operator|.
name|Width
operator|=
name|width
expr_stmt|;
name|swapChainDesc
operator|.
name|Height
operator|=
name|height
expr_stmt|;
name|swapChainDesc
operator|.
name|Format
operator|=
name|format
expr_stmt|;
name|swapChainDesc
operator|.
name|Stereo
operator|=
name|FALSE
expr_stmt|;
name|swapChainDesc
operator|.
name|SampleDesc
operator|.
name|Count
operator|=
literal|1
expr_stmt|;
name|swapChainDesc
operator|.
name|SampleDesc
operator|.
name|Quality
operator|=
literal|0
expr_stmt|;
name|swapChainDesc
operator|.
name|BufferUsage
operator|=
name|DXGI_USAGE_RENDER_TARGET_OUTPUT
operator||
name|DXGI_USAGE_BACK_BUFFER
expr_stmt|;
name|swapChainDesc
operator|.
name|BufferCount
operator|=
literal|2
expr_stmt|;
name|swapChainDesc
operator|.
name|SwapEffect
operator|=
name|DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL
expr_stmt|;
name|swapChainDesc
operator|.
name|Scaling
operator|=
name|DXGI_SCALING_STRETCH
expr_stmt|;
operator|*
name|swapChain
operator|=
literal|nullptr
expr_stmt|;
name|ComPtr
argument_list|<
name|IDXGISwapChain1
argument_list|>
name|newSwapChain
decl_stmt|;
name|HRESULT
name|result
init|=
name|factory
operator|->
name|CreateSwapChainForCoreWindow
argument_list|(
name|device
argument_list|,
name|mCoreWindow
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|swapChainDesc
argument_list|,
literal|nullptr
argument_list|,
name|newSwapChain
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
if|#
directive|if
operator|(
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PHONE_APP
operator|)
comment|// This block is disabled for Qt applications, as the resize events are expected
comment|// Test if swapchain supports resize.  On Windows Phone devices, this will return DXGI_ERROR_UNSUPPORTED.  On
comment|// other devices DXGI_ERROR_INVALID_CALL should be returned because the combination of flags passed
comment|// (DXGI_SWAP_CHAIN_FLAG_NONPREROTATED | DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE) are invalid flag combinations.
if|if
condition|(
name|newSwapChain
operator|->
name|ResizeBuffers
argument_list|(
name|swapChainDesc
operator|.
name|BufferCount
argument_list|,
name|swapChainDesc
operator|.
name|Width
argument_list|,
name|swapChainDesc
operator|.
name|Height
argument_list|,
name|swapChainDesc
operator|.
name|Format
argument_list|,
name|DXGI_SWAP_CHAIN_FLAG_NONPREROTATED
operator||
name|DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE
argument_list|)
operator|==
name|DXGI_ERROR_UNSUPPORTED
condition|)
block|{
name|mSupportsSwapChainResize
operator|=
literal|false
expr_stmt|;
block|}
endif|#
directive|endif
comment|// (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
name|result
operator|=
name|newSwapChain
operator|.
name|CopyTo
argument_list|(
name|swapChain
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// If automatic swapchain resize behaviors have been disabled, then
comment|// unregister for the resize change events.
if|if
condition|(
name|mSupportsSwapChainResize
operator|==
literal|false
condition|)
block|{
name|unregisterForSizeChangeEvents
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
comment|// Basically, this shouldn't be used on Phone
DECL|function|onSizeChanged
name|HRESULT
name|CoreWindowNativeWindow
operator|::
name|onSizeChanged
parameter_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
modifier|*
parameter_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IWindowSizeChangedEventArgs
modifier|*
name|e
parameter_list|)
block|{
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Size
name|size
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|e
operator|->
name|get_Size
argument_list|(
operator|&
name|size
argument_list|)
argument_list|)
condition|)
block|{
name|SIZE
name|windowSizeInPixels
init|=
block|{
name|std
operator|::
name|floor
argument_list|(
name|size
operator|.
name|Width
operator|*
name|mScaleFactor
operator|+
literal|0.5
argument_list|)
block|,
name|std
operator|::
name|floor
operator|(
name|size
operator|.
name|Height
operator|*
name|mScaleFactor
operator|+
literal|0.5
operator|)
block|}
decl_stmt|;
name|setNewClientSize
argument_list|(
name|windowSizeInPixels
argument_list|)
expr_stmt|;
block|}
return|return
name|S_OK
return|;
block|}
block|}
end_namespace
end_unit