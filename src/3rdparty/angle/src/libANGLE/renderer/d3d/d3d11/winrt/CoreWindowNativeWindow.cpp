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
file|"libANGLE/renderer/d3d/d3d11/winrt/CoreWindowNativeWindow.h"
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
name|IPropertySet
modifier|*
name|propertySet
parameter_list|)
block|{
name|mOrientationChangedEventToken
operator|.
name|value
operator|=
literal|0
expr_stmt|;
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
name|SIZE
name|swapChainSize
init|=
block|{}
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
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
comment|// The EGLRenderSurfaceSizeProperty is optional and may be missing. The IPropertySet
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
name|mSwapChainSizeSpecified
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
comment|// The EGLRenderResolutionScaleProperty is optional and may be missing. The IPropertySet
comment|// was prevalidated to contain the EGLNativeWindowType before being passed to
comment|// this host.
name|result
operator|=
name|GetOptionalSinglePropertyValue
argument_list|(
name|mPropertyMap
argument_list|,
name|EGLRenderResolutionScaleProperty
argument_list|,
operator|&
name|mSwapChainScale
argument_list|,
operator|&
name|mSwapChainScaleSpecified
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|mSwapChainScaleSpecified
condition|)
block|{
comment|// Default value for the scale is 1.0f
name|mSwapChainScale
operator|=
literal|1.0f
expr_stmt|;
block|}
comment|// A EGLRenderSurfaceSizeProperty and a EGLRenderResolutionScaleProperty can't both be specified
if|if
condition|(
name|mSwapChainScaleSpecified
operator|&&
name|mSwapChainSizeSpecified
condition|)
block|{
name|ERR
argument_list|(
literal|"It is invalid to specify both an EGLRenderSurfaceSizeProperty and a EGLRenderResolutionScaleProperty."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
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
comment|// If a swapchain size is specfied, then the automatic resize
comment|// behaviors implemented by the host should be disabled.  The swapchain
comment|// will be still be scaled when being rendered to fit the bounds
comment|// of the host.
comment|// Scaling of the swapchain output occurs automatically because if
comment|// the scaling mode setting DXGI_SCALING_STRETCH on the swapchain.
if|if
condition|(
name|mSwapChainSizeSpecified
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
block|}
else|else
block|{
name|SIZE
name|coreWindowSize
decl_stmt|;
name|result
operator|=
name|GetCoreWindowSizeInPixels
argument_list|(
name|mCoreWindow
argument_list|,
operator|&
name|coreWindowSize
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
name|mClientRect
operator|=
block|{
literal|0
block|,
literal|0
block|,
cast|static_cast
argument_list|<
name|long
argument_list|>
argument_list|(
name|coreWindowSize
operator|.
name|cx
operator|*
name|mSwapChainScale
argument_list|)
block|,
expr|static_cast
operator|<
name|long
operator|>
operator|(
name|coreWindowSize
operator|.
name|cy
operator|*
name|mSwapChainScale
operator|)
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
name|IDisplayInformationStatics
argument_list|>
name|displayInformation
decl_stmt|;
name|result
operator|=
name|GetActivationFactory
argument_list|(
name|HStringReference
argument_list|(
name|RuntimeClass_Windows_Graphics_Display_DisplayInformation
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|displayInformation
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
name|result
operator|=
name|displayInformation
operator|->
name|GetForCurrentView
argument_list|(
operator|&
name|mDisplayInformation
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
name|ComPtr
argument_list|<
name|IWindowSizeChangedEventHandler
argument_list|>
name|sizeChangedHandler
decl_stmt|;
name|HRESULT
name|result
init|=
name|Microsoft
operator|::
name|WRL
operator|::
name|MakeAndInitialize
argument_list|<
name|CoreWindowSizeChangedHandler
argument_list|>
argument_list|(
name|sizeChangedHandler
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|,
name|this
operator|->
name|shared_from_this
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
name|result
operator|=
name|mCoreWindow
operator|->
name|add_SizeChanged
argument_list|(
name|sizeChangedHandler
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|mSizeChangedEventToken
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|&&
operator|(
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PHONE_APP
operator|)
name|ComPtr
argument_list|<
name|IDisplayOrientationEventHandler
argument_list|>
name|orientationChangedHandler
decl_stmt|;
name|result
operator|=
name|sizeChangedHandler
operator|.
name|As
argument_list|(
operator|&
name|orientationChangedHandler
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
name|result
operator|=
name|mDisplayInformation
operator|->
name|add_OrientationChanged
argument_list|(
name|orientationChangedHandler
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|mOrientationChangedEventToken
argument_list|)
expr_stmt|;
name|orientationChangedHandler
operator|->
name|Invoke
argument_list|(
name|mDisplayInformation
operator|.
name|Get
argument_list|()
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|&&
operator|(
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PHONE_APP
operator|)
if|if
condition|(
name|mDisplayInformation
condition|)
block|{
operator|(
name|void
operator|)
name|mDisplayInformation
operator|->
name|remove_OrientationChanged
argument_list|(
name|mOrientationChangedEventToken
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|mSizeChangedEventToken
operator|.
name|value
operator|=
literal|0
expr_stmt|;
name|mOrientationChangedEventToken
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
name|bool
name|containsAlpha
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
name|mRotationFlags
condition|?
name|height
else|:
name|width
expr_stmt|;
name|swapChainDesc
operator|.
name|Height
operator|=
name|mRotationFlags
condition|?
name|width
else|:
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
name|DXGI_USAGE_SHADER_INPUT
operator||
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
name|swapChainDesc
operator|.
name|AlphaMode
operator|=
name|DXGI_ALPHA_MODE_UNSPECIFIED
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
literal|0
comment|//(WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP) // Qt: allow Windows Phone to resize, but don't modify the backing texture in the swap chain.
comment|// Test if swapchain supports resize.  On Windows Phone devices, this will return DXGI_ERROR_UNSUPPORTED.  On
comment|// other devices DXGI_ERROR_INVALID_CALL should be returned because the combination of flags passed
comment|// (DXGI_SWAP_CHAIN_FLAG_NONPREROTATED | DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE) are invalid flag combinations.
block|if (newSwapChain->ResizeBuffers(swapChainDesc.BufferCount, swapChainDesc.Width, swapChainDesc.Height, swapChainDesc.Format, DXGI_SWAP_CHAIN_FLAG_NONPREROTATED | DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE) == DXGI_ERROR_UNSUPPORTED)         {             mSupportsSwapChainResize = false;         }
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
DECL|function|scaleSwapChain
specifier|inline
name|HRESULT
name|CoreWindowNativeWindow
operator|::
name|scaleSwapChain
parameter_list|(
specifier|const
name|Size
modifier|&
name|windowSize
parameter_list|,
specifier|const
name|RECT
modifier|&
name|clientRect
parameter_list|)
block|{
comment|// We don't need to do any additional work to scale CoreWindow swapchains.
comment|// Using DXGI_SCALING_STRETCH to create the swapchain above does all the necessary work.
return|return
name|S_OK
return|;
block|}
DECL|function|GetCoreWindowSizeInPixels
name|HRESULT
name|GetCoreWindowSizeInPixels
parameter_list|(
specifier|const
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
argument_list|>
modifier|&
name|coreWindow
parameter_list|,
name|SIZE
modifier|*
name|windowSize
parameter_list|)
block|{
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Rect
name|bounds
decl_stmt|;
name|HRESULT
name|result
init|=
name|coreWindow
operator|->
name|get_Bounds
argument_list|(
operator|&
name|bounds
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
operator|*
name|windowSize
operator|=
block|{
name|ConvertDipsToPixels
argument_list|(
name|bounds
operator|.
name|Width
argument_list|)
block|,
name|ConvertDipsToPixels
argument_list|(
argument|bounds.Height
argument_list|)
block|}
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
block|}
end_namespace
end_unit
