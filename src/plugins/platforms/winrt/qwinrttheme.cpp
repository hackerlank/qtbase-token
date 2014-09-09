begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrttheme.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtmessagedialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPalette>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.viewmanagement.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
namespace|;
end_using
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|uiSettings
specifier|static
name|IUISettings
modifier|*
name|uiSettings
parameter_list|()
block|{
specifier|static
name|ComPtr
argument_list|<
name|IUISettings
argument_list|>
name|settings
decl_stmt|;
if|if
condition|(
operator|!
name|settings
condition|)
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoActivateInstance
argument_list|(
name|Wrappers
operator|::
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_ViewManagement_UISettings
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|settings
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
return|return
name|settings
operator|.
name|Get
argument_list|()
return|;
block|}
end_function
begin_class
DECL|class|QWinRTThemePrivate
class|class
name|QWinRTThemePrivate
block|{
public|public:
DECL|member|palette
name|QPalette
name|palette
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|fromColor
specifier|static
specifier|inline
name|QColor
name|fromColor
parameter_list|(
specifier|const
name|Color
modifier|&
name|color
parameter_list|)
block|{
return|return
name|QColor
argument_list|(
name|color
operator|.
name|R
argument_list|,
name|color
operator|.
name|G
argument_list|,
name|color
operator|.
name|B
argument_list|,
name|color
operator|.
name|A
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWinRTTheme
name|QWinRTTheme
operator|::
name|QWinRTTheme
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWinRTThemePrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTTheme
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|Color
name|color
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINPHONE
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_PopupBackground
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipBase
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|AlternateBase
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_NonTextMedium
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_NonTextMediumHigh
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_NonTextHigh
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Light
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_NonTextMediumLow
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Mid
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_NonTextLow
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_TextHigh
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|WindowText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_TextMedium
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_AccentColor
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_PageBackground
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_TextContrastWithHigh
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|BrightText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_ActiveCaption
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipBase
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_Background
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|AlternateBase
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_ButtonFace
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
operator|.
name|lighter
argument_list|(
literal|110
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Light
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
operator|.
name|lighter
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Mid
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
operator|.
name|dark
argument_list|(
literal|130
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
operator|.
name|dark
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_ButtonText
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_CaptionText
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_Highlight
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_HighlightText
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_Window
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|UIElementColor
argument_list|(
name|UIElementType_Hotlight
argument_list|,
operator|&
name|color
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|d
operator|->
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|BrightText
argument_list|,
name|fromColor
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QWinRTTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
specifier|static
name|bool
name|useNativeDialogs
init|=
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_USE_WINRT_NATIVE_DIALOGS"
argument_list|)
condition|?
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_USE_WINRT_NATIVE_DIALOGS"
argument_list|)
else|:
literal|true
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|FileDialog
operator|||
name|type
operator|==
name|MessageDialog
condition|)
return|return
name|useNativeDialogs
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QWinRTTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|FileDialog
case|:
return|return
operator|new
name|QWinRTFileDialogHelper
return|;
case|case
name|MessageDialog
case|:
return|return
operator|new
name|QWinRTMessageDialogHelper
argument_list|(
name|this
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QPlatformTheme
operator|::
name|createPlatformDialogHelper
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QWinRTTheme
operator|::
name|styleHint
parameter_list|(
name|QPlatformIntegration
operator|::
name|StyleHint
name|hint
parameter_list|)
block|{
name|HRESULT
name|hr
decl_stmt|;
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|CursorFlashTime
case|:
block|{
name|quint32
name|blinkRate
decl_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|get_CaretBlinkRate
argument_list|(
operator|&
name|blinkRate
argument_list|)
expr_stmt|;
name|RETURN_IF_FAILED
argument_list|(
literal|"Failed to get caret blink rate"
argument_list|,
argument|return defaultThemeHint(CursorFlashTime)
argument_list|)
empty_stmt|;
return|return
name|blinkRate
return|;
block|}
case|case
name|QPlatformIntegration
operator|::
name|KeyboardInputInterval
case|:
return|return
name|defaultThemeHint
argument_list|(
name|KeyboardInputInterval
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|MouseDoubleClickInterval
case|:
block|{
name|quint32
name|doubleClickTime
decl_stmt|;
name|hr
operator|=
name|uiSettings
argument_list|()
operator|->
name|get_DoubleClickTime
argument_list|(
operator|&
name|doubleClickTime
argument_list|)
expr_stmt|;
name|RETURN_IF_FAILED
argument_list|(
literal|"Failed to get double click time"
argument_list|,
argument|return defaultThemeHint(MouseDoubleClickInterval)
argument_list|)
empty_stmt|;
return|return
name|doubleClickTime
return|;
block|}
case|case
name|QPlatformIntegration
operator|::
name|StartDragDistance
case|:
return|return
name|defaultThemeHint
argument_list|(
name|StartDragDistance
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|StartDragTime
case|:
return|return
name|defaultThemeHint
argument_list|(
name|StartDragTime
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|KeyboardAutoRepeatRate
case|:
return|return
name|defaultThemeHint
argument_list|(
name|KeyboardAutoRepeatRate
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
case|:
return|return
literal|true
return|;
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskDelay
case|:
return|return
name|defaultThemeHint
argument_list|(
name|PasswordMaskDelay
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|FontSmoothingGamma
case|:
return|return
name|qreal
argument_list|(
literal|1.7
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|StartDragVelocity
case|:
return|return
name|defaultThemeHint
argument_list|(
name|StartDragVelocity
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|UseRtlExtensions
case|:
return|return
literal|false
return|;
case|case
name|QPlatformIntegration
operator|::
name|SynthesizeMouseFromTouchEvents
case|:
return|return
literal|true
return|;
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskCharacter
case|:
return|return
name|defaultThemeHint
argument_list|(
name|PasswordMaskCharacter
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|SetFocusOnTouchRelease
case|:
return|return
literal|false
return|;
case|case
name|QPlatformIntegration
operator|::
name|ShowIsMaximized
case|:
return|return
literal|false
return|;
case|case
name|MousePressAndHoldInterval
case|:
return|return
name|defaultThemeHint
argument_list|(
name|MousePressAndHoldInterval
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|palette
specifier|const
name|QPalette
modifier|*
name|QWinRTTheme
operator|::
name|palette
parameter_list|(
name|Palette
name|type
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTTheme
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|SystemPalette
condition|)
return|return
operator|&
name|d
operator|->
name|palette
return|;
return|return
name|QPlatformTheme
operator|::
name|palette
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
