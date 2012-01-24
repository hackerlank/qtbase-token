begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmeegoplatforminputcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QTextCharFormat>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|"serveraddressproxy.h"
end_include
begin_include
include|#
directive|include
file|"serverproxy.h"
end_include
begin_include
include|#
directive|include
file|"contextadaptor.h"
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|debug
name|enum
type|{
name|debug
init|=
literal|0
end_decl_stmt
begin_enum
DECL|enum|InputPanelVisibility
unit|};
enum|enum
name|InputPanelVisibility
block|{
DECL|enumerator|InputPanelHidden
name|InputPanelHidden
block|,
DECL|enumerator|InputPanelShowRequested
name|InputPanelShowRequested
block|,
DECL|enumerator|InputPanelShown
name|InputPanelShown
block|}
enum|;
end_enum
begin_enum
DECL|enum|MaliitOrientationAngle
enum|enum
name|MaliitOrientationAngle
block|{
DECL|enumerator|Angle0
name|Angle0
init|=
literal|0
block|,
DECL|enumerator|Angle90
name|Angle90
init|=
literal|90
block|,
DECL|enumerator|Angle180
name|Angle180
init|=
literal|180
block|,
DECL|enumerator|Angle270
name|Angle270
init|=
literal|270
block|}
enum|;
end_enum
begin_function
DECL|function|orientationAngle
specifier|static
name|int
name|orientationAngle
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
switch|switch
condition|(
name|orientation
condition|)
block|{
case|case
name|Qt
operator|::
name|PrimaryOrientation
case|:
comment|// Urgh.
case|case
name|Qt
operator|::
name|PortraitOrientation
case|:
return|return
name|Angle270
return|;
case|case
name|Qt
operator|::
name|LandscapeOrientation
case|:
return|return
name|Angle0
return|;
case|case
name|Qt
operator|::
name|InvertedPortraitOrientation
case|:
return|return
name|Angle90
return|;
case|case
name|Qt
operator|::
name|InvertedLandscapeOrientation
case|:
return|return
name|Angle180
return|;
block|}
return|return
name|Angle0
return|;
block|}
end_function
begin_comment
comment|// From MTF:
end_comment
begin_comment
comment|//! Content type for text entries. Used at least with MTextEdit
end_comment
begin_enum
DECL|enum|TextContentType
enum|enum
name|TextContentType
block|{
comment|//! all characters allowed
DECL|enumerator|FreeTextContentType
name|FreeTextContentType
block|,
comment|//! only integer numbers allowed
DECL|enumerator|NumberContentType
name|NumberContentType
block|,
comment|//! allows numbers and certain other characters used in phone numbers
DECL|enumerator|PhoneNumberContentType
name|PhoneNumberContentType
block|,
comment|//! allows only characters permitted in email address
DECL|enumerator|EmailContentType
name|EmailContentType
block|,
comment|//! allows only character permitted in URL address
DECL|enumerator|UrlContentType
name|UrlContentType
block|,
comment|//! allows content with user defined format
DECL|enumerator|CustomContentType
name|CustomContentType
block|}
enum|;
end_enum
begin_function
DECL|function|contentTypeFromHints
specifier|static
name|TextContentType
name|contentTypeFromHints
parameter_list|(
name|Qt
operator|::
name|InputMethodHints
name|hints
parameter_list|)
block|{
name|TextContentType
name|type
init|=
name|FreeTextContentType
decl_stmt|;
name|hints
operator|&=
name|Qt
operator|::
name|ImhExclusiveInputMask
expr_stmt|;
if|if
condition|(
name|hints
operator|==
name|Qt
operator|::
name|ImhFormattedNumbersOnly
operator|||
name|hints
operator|==
name|Qt
operator|::
name|ImhDigitsOnly
condition|)
name|type
operator|=
name|NumberContentType
expr_stmt|;
elseif|else
if|if
condition|(
name|hints
operator|==
name|Qt
operator|::
name|ImhDialableCharactersOnly
condition|)
name|type
operator|=
name|PhoneNumberContentType
expr_stmt|;
elseif|else
if|if
condition|(
name|hints
operator|==
name|Qt
operator|::
name|ImhEmailCharactersOnly
condition|)
name|type
operator|=
name|EmailContentType
expr_stmt|;
elseif|else
if|if
condition|(
name|hints
operator|==
name|Qt
operator|::
name|ImhUrlCharactersOnly
condition|)
name|type
operator|=
name|UrlContentType
expr_stmt|;
return|return
name|type
return|;
block|}
end_function
begin_function
DECL|function|maliitServerAddress
specifier|static
name|QString
name|maliitServerAddress
parameter_list|()
block|{
name|org
operator|::
name|maliit
operator|::
name|Server
operator|::
name|Address
name|serverAddress
argument_list|(
name|QStringLiteral
argument_list|(
literal|"org.maliit.server"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/org/maliit/server/address"
argument_list|)
argument_list|,
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|address
argument_list|(
name|serverAddress
operator|.
name|address
argument_list|()
argument_list|)
decl_stmt|;
comment|// Fallback to old socket when org.maliit.server service is not available
if|if
condition|(
name|address
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"unix:path=/tmp/meego-im-uiserver/imserver_dbus"
argument_list|)
return|;
return|return
name|address
return|;
block|}
end_function
begin_class
DECL|class|QMeeGoPlatformInputContextPrivate
class|class
name|QMeeGoPlatformInputContextPrivate
block|{
public|public:
name|QMeeGoPlatformInputContextPrivate
parameter_list|(
name|QMeeGoPlatformInputContext
modifier|*
name|qq
parameter_list|)
constructor_decl|;
DECL|function|~QMeeGoPlatformInputContextPrivate
name|~
name|QMeeGoPlatformInputContextPrivate
parameter_list|()
block|{
operator|delete
name|adaptor
expr_stmt|;
operator|delete
name|server
expr_stmt|;
block|}
name|void
name|sendStateUpdate
parameter_list|(
name|bool
name|focusChanged
init|=
literal|false
parameter_list|)
function_decl|;
DECL|member|connection
name|QDBusConnection
name|connection
decl_stmt|;
DECL|member|server
name|ComMeegoInputmethodUiserver1Interface
modifier|*
name|server
decl_stmt|;
DECL|member|adaptor
name|Inputcontext1Adaptor
modifier|*
name|adaptor
decl_stmt|;
DECL|member|imState
name|QMap
argument_list|<
name|QString
argument_list|,
name|QVariant
argument_list|>
name|imState
decl_stmt|;
DECL|member|visibility
name|InputPanelVisibility
name|visibility
decl_stmt|;
DECL|member|valid
name|bool
name|valid
decl_stmt|;
DECL|member|active
name|bool
name|active
decl_stmt|;
DECL|member|correctionEnabled
name|bool
name|correctionEnabled
decl_stmt|;
DECL|member|keyboardRect
name|QRect
name|keyboardRect
decl_stmt|;
DECL|member|preedit
name|QString
name|preedit
decl_stmt|;
DECL|member|window
name|QWeakPointer
argument_list|<
name|QWindow
argument_list|>
name|window
decl_stmt|;
DECL|member|q
name|QMeeGoPlatformInputContext
modifier|*
name|q
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QMeeGoPlatformInputContext
name|QMeeGoPlatformInputContext
operator|::
name|QMeeGoPlatformInputContext
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QMeeGoPlatformInputContextPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"QMeeGoPlatformInputContext::QMeeGoPlatformInputContext()"
expr_stmt|;
name|QInputPanel
modifier|*
name|p
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|p
argument_list|,
name|SIGNAL
argument_list|(
name|inputItemChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|inputItemChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMeeGoPlatformInputContext
name|QMeeGoPlatformInputContext
operator|::
name|~
name|QMeeGoPlatformInputContext
parameter_list|(
name|void
parameter_list|)
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isValid
name|bool
name|QMeeGoPlatformInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|valid
return|;
block|}
end_function
begin_function
DECL|function|invokeAction
name|void
name|QMeeGoPlatformInputContext
operator|::
name|invokeAction
parameter_list|(
name|QInputPanel
operator|::
name|Action
name|action
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
if|if
condition|(
name|action
operator|==
name|QInputPanel
operator|::
name|Click
condition|)
block|{
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|x
operator|>=
name|d
operator|->
name|preedit
operator|.
name|length
argument_list|()
condition|)
block|{
name|reset
argument_list|()
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|imState
index|[
literal|"preeditClickPos"
index|]
operator|=
name|x
expr_stmt|;
name|d
operator|->
name|sendStateUpdate
argument_list|()
expr_stmt|;
comment|// The first argument is the mouse pos and the second is the
comment|// preedit rectangle. Both are unused on the server side.
name|d
operator|->
name|server
operator|->
name|mouseClickedOnPreedit
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QPlatformInputContext
operator|::
name|invokeAction
argument_list|(
name|action
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QMeeGoPlatformInputContext
operator|::
name|reset
parameter_list|()
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|hadPreedit
init|=
operator|!
name|d
operator|->
name|preedit
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
if|if
condition|(
name|hadPreedit
operator|&&
name|input
condition|)
block|{
comment|// ### selection
name|QInputMethodEvent
name|event
decl_stmt|;
name|event
operator|.
name|setCommitString
argument_list|(
name|d
operator|->
name|preedit
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|preedit
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|QDBusPendingReply
argument_list|<
name|void
argument_list|>
name|reply
init|=
name|d
operator|->
name|server
operator|->
name|reset
argument_list|()
decl_stmt|;
if|if
condition|(
name|hadPreedit
condition|)
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QMeeGoPlatformInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
name|queries
parameter_list|)
block|{
name|QInputPanel
modifier|*
name|panel
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
decl_stmt|;
name|QObject
modifier|*
name|input
init|=
name|panel
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
name|QInputMethodQueryEvent
name|query
argument_list|(
name|queries
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImSurroundingText
condition|)
name|d
operator|->
name|imState
index|[
literal|"surroundingText"
index|]
operator|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImSurroundingText
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImCursorPosition
condition|)
name|d
operator|->
name|imState
index|[
literal|"cursorPosition"
index|]
operator|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCursorPosition
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImAnchorPosition
condition|)
name|d
operator|->
name|imState
index|[
literal|"anchorPosition"
index|]
operator|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImAnchorPosition
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImCursorRectangle
condition|)
block|{
name|QRect
name|rect
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|rect
operator|=
name|panel
operator|->
name|inputItemTransform
argument_list|()
operator|.
name|mapRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|panel
operator|->
name|inputWindow
argument_list|()
decl_stmt|;
if|if
condition|(
name|window
condition|)
name|d
operator|->
name|imState
index|[
literal|"cursorRectangle"
index|]
operator|=
name|QRect
argument_list|(
name|window
operator|->
name|mapToGlobal
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImCurrentSelection
condition|)
name|d
operator|->
name|imState
index|[
literal|"hasSelection"
index|]
operator|=
operator|!
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCurrentSelection
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImHints
condition|)
block|{
name|Qt
operator|::
name|InputMethodHints
name|hints
init|=
name|Qt
operator|::
name|InputMethodHints
argument_list|(
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImHints
argument_list|)
operator|.
name|toUInt
argument_list|()
argument_list|)
decl_stmt|;
name|d
operator|->
name|imState
index|[
literal|"predictionEnabled"
index|]
operator|=
operator|!
operator|(
name|hints
operator|&
name|Qt
operator|::
name|ImhNoPredictiveText
operator|)
expr_stmt|;
name|d
operator|->
name|imState
index|[
literal|"autocapitalizationEnabled"
index|]
operator|=
operator|!
operator|(
name|hints
operator|&
name|Qt
operator|::
name|ImhNoAutoUppercase
operator|)
expr_stmt|;
name|d
operator|->
name|imState
index|[
literal|"hiddenText"
index|]
operator|=
operator|(
name|hints
operator|&
name|Qt
operator|::
name|ImhHiddenText
operator|)
operator|!=
literal|0
expr_stmt|;
name|d
operator|->
name|imState
index|[
literal|"contentType"
index|]
operator|=
name|contentTypeFromHints
argument_list|(
name|hints
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|sendStateUpdate
argument_list|(
comment|/*focusChanged*/
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardRect
name|QRectF
name|QMeeGoPlatformInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|keyboardRect
return|;
block|}
end_function
begin_function
DECL|function|activationLostEvent
name|void
name|QMeeGoPlatformInputContext
operator|::
name|activationLostEvent
parameter_list|()
block|{
name|d
operator|->
name|active
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|visibility
operator|=
name|InputPanelHidden
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commitString
name|void
name|QMeeGoPlatformInputContext
operator|::
name|commitString
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|,
name|int
name|replacementStart
parameter_list|,
name|int
name|replacementLength
parameter_list|,
name|int
name|cursorPos
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
name|d
operator|->
name|preedit
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"CommitString"
operator|<<
name|string
expr_stmt|;
comment|// ### start/cursorPos
name|QInputMethodEvent
name|event
decl_stmt|;
name|event
operator|.
name|setCommitString
argument_list|(
name|string
argument_list|,
name|replacementStart
argument_list|,
name|replacementLength
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePreedit
name|void
name|QMeeGoPlatformInputContext
operator|::
name|updatePreedit
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|arguments
init|=
name|message
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|arguments
operator|.
name|count
argument_list|()
operator|!=
literal|5
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QMeeGoPlatformInputContext::updatePreedit: Received message from input method server with wrong parameters."
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|preedit
operator|=
name|arguments
index|[
literal|0
index|]
operator|.
name|toString
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attributes
decl_stmt|;
specifier|const
name|QDBusArgument
name|formats
init|=
name|arguments
index|[
literal|1
index|]
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
decl_stmt|;
name|formats
operator|.
name|beginArray
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|formats
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|formats
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|int
name|start
decl_stmt|,
name|length
decl_stmt|,
name|preeditFace
decl_stmt|;
name|formats
operator|>>
name|start
operator|>>
name|length
operator|>>
name|preeditFace
expr_stmt|;
name|formats
operator|.
name|endStructure
argument_list|()
expr_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
enum|enum
name|PreeditFace
block|{
name|PreeditDefault
block|,
name|PreeditNoCandidates
block|,
name|PreeditKeyPress
block|,
comment|//!< Used for displaying the hwkbd key just pressed
name|PreeditUnconvertible
block|,
comment|//!< Inactive preedit region, not clickable
name|PreeditActive
block|,
comment|//!< Preedit region with active suggestions
block|}
enum|;
switch|switch
condition|(
name|PreeditFace
argument_list|(
name|preeditFace
argument_list|)
condition|)
block|{
case|case
name|PreeditDefault
case|:
case|case
name|PreeditKeyPress
case|:
name|format
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|SingleUnderline
argument_list|)
expr_stmt|;
name|format
operator|.
name|setUnderlineColor
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PreeditNoCandidates
case|:
name|format
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|SingleUnderline
argument_list|)
expr_stmt|;
name|format
operator|.
name|setUnderlineColor
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PreeditUnconvertible
case|:
name|format
operator|.
name|setForeground
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|PreeditActive
case|:
name|format
operator|.
name|setForeground
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|153
argument_list|,
literal|50
argument_list|,
literal|204
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|format
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|attributes
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|TextFormat
argument_list|,
name|start
argument_list|,
name|length
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
name|formats
operator|.
name|endArray
argument_list|()
expr_stmt|;
name|int
name|replacementStart
init|=
name|arguments
index|[
literal|2
index|]
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|replacementLength
init|=
name|arguments
index|[
literal|3
index|]
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|cursorPos
init|=
name|arguments
index|[
literal|4
index|]
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|debug
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"updatePreedit"
operator|<<
name|d
operator|->
name|preedit
operator|<<
name|replacementStart
operator|<<
name|replacementLength
operator|<<
name|cursorPos
expr_stmt|;
if|if
condition|(
name|cursorPos
operator|>=
literal|0
condition|)
name|attributes
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|Cursor
argument_list|,
name|cursorPos
argument_list|,
literal|1
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|QInputMethodEvent
name|event
argument_list|(
name|d
operator|->
name|preedit
argument_list|,
name|attributes
argument_list|)
decl_stmt|;
if|if
condition|(
name|replacementStart
operator|||
name|replacementLength
condition|)
name|event
operator|.
name|setCommitString
argument_list|(
name|QString
argument_list|()
argument_list|,
name|replacementStart
argument_list|,
name|replacementLength
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copy
name|void
name|QMeeGoPlatformInputContext
operator|::
name|copy
parameter_list|()
block|{
comment|// Not supported at the moment.
block|}
end_function
begin_function
DECL|function|imInitiatedHide
name|void
name|QMeeGoPlatformInputContext
operator|::
name|imInitiatedHide
parameter_list|()
block|{
name|d
operator|->
name|visibility
operator|=
name|InputPanelHidden
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
comment|// ### clear focus
block|}
end_function
begin_function
DECL|function|keyEvent
name|void
name|QMeeGoPlatformInputContext
operator|::
name|keyEvent
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|,
name|uchar
parameter_list|)
block|{
comment|// Not supported at the moment.
block|}
end_function
begin_function
DECL|function|paste
name|void
name|QMeeGoPlatformInputContext
operator|::
name|paste
parameter_list|()
block|{
comment|// Not supported at the moment.
block|}
end_function
begin_function
DECL|function|preeditRectangle
name|bool
name|QMeeGoPlatformInputContext
operator|::
name|preeditRectangle
parameter_list|(
name|int
modifier|&
name|x
parameter_list|,
name|int
modifier|&
name|y
parameter_list|,
name|int
modifier|&
name|width
parameter_list|,
name|int
modifier|&
name|height
parameter_list|)
block|{
comment|// ###
name|QRect
name|r
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|cursorRectangle
argument_list|()
operator|.
name|toRect
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|r
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|x
operator|=
name|r
operator|.
name|x
argument_list|()
expr_stmt|;
name|y
operator|=
name|r
operator|.
name|y
argument_list|()
expr_stmt|;
name|width
operator|=
name|r
operator|.
name|width
argument_list|()
expr_stmt|;
name|height
operator|=
name|r
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|selection
name|bool
name|QMeeGoPlatformInputContext
operator|::
name|selection
parameter_list|(
name|QString
modifier|&
name|selection
parameter_list|)
block|{
name|selection
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return
literal|false
return|;
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|ImCurrentSelection
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|QVariant
name|value
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCurrentSelection
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|value
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|selection
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setDetectableAutoRepeat
name|void
name|QMeeGoPlatformInputContext
operator|::
name|setDetectableAutoRepeat
parameter_list|(
name|bool
parameter_list|)
block|{
comment|// Not supported.
block|}
end_function
begin_function
DECL|function|setGlobalCorrectionEnabled
name|void
name|QMeeGoPlatformInputContext
operator|::
name|setGlobalCorrectionEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|d
operator|->
name|correctionEnabled
operator|=
name|enable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLanguage
name|void
name|QMeeGoPlatformInputContext
operator|::
name|setLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
comment|// Unused at the moment.
block|}
end_function
begin_function
DECL|function|setRedirectKeys
name|void
name|QMeeGoPlatformInputContext
operator|::
name|setRedirectKeys
parameter_list|(
name|bool
parameter_list|)
block|{
comment|// Not supported.
block|}
end_function
begin_function
DECL|function|setSelection
name|void
name|QMeeGoPlatformInputContext
operator|::
name|setSelection
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|length
parameter_list|)
block|{
name|QObject
modifier|*
name|input
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|inputItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|input
condition|)
return|return;
name|QList
argument_list|<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|>
name|attributes
decl_stmt|;
name|attributes
operator|<<
name|QInputMethodEvent
operator|::
name|Attribute
argument_list|(
name|QInputMethodEvent
operator|::
name|Selection
argument_list|,
name|start
argument_list|,
name|length
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|QInputMethodEvent
name|event
argument_list|(
name|QString
argument_list|()
argument_list|,
name|attributes
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|input
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateInputMethodArea
name|void
name|QMeeGoPlatformInputContext
operator|::
name|updateInputMethodArea
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|d
operator|->
name|keyboardRect
operator|=
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|emitKeyboardRectChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateServerWindowOrientation
name|void
name|QMeeGoPlatformInputContext
operator|::
name|updateServerWindowOrientation
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
name|d
operator|->
name|server
operator|->
name|appOrientationChanged
argument_list|(
name|orientationAngle
argument_list|(
name|orientation
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|inputItemChanged
name|void
name|QMeeGoPlatformInputContext
operator|::
name|inputItemChanged
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
name|QInputPanel
modifier|*
name|panel
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
decl_stmt|;
name|QObject
modifier|*
name|input
init|=
name|panel
operator|->
name|inputItem
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|panel
operator|->
name|inputWindow
argument_list|()
decl_stmt|;
if|if
condition|(
name|window
operator|!=
name|d
operator|->
name|window
operator|.
name|data
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|window
condition|)
name|disconnect
argument_list|(
name|d
operator|->
name|window
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|contentOrientationChanged
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateServerWindowOrientation
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|window
operator|=
name|window
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|window
condition|)
name|connect
argument_list|(
name|d
operator|->
name|window
operator|.
name|data
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|contentOrientationChanged
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateServerWindowOrientation
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|imState
index|[
literal|"focusState"
index|]
operator|=
name|input
operator|!=
literal|0
expr_stmt|;
if|if
condition|(
name|input
condition|)
block|{
if|if
condition|(
name|window
condition|)
name|d
operator|->
name|imState
index|[
literal|"winId"
index|]
operator|=
cast|static_cast
argument_list|<
name|qulonglong
argument_list|>
argument_list|(
name|window
operator|->
name|winId
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|active
condition|)
block|{
name|d
operator|->
name|active
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|server
operator|->
name|activateContext
argument_list|()
expr_stmt|;
if|if
condition|(
name|window
condition|)
name|d
operator|->
name|server
operator|->
name|appOrientationChanged
argument_list|(
name|orientationAngle
argument_list|(
name|window
operator|->
name|contentOrientation
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|d
operator|->
name|sendStateUpdate
argument_list|(
comment|/*focusChanged*/
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|input
operator|&&
name|window
operator|&&
name|d
operator|->
name|visibility
operator|==
name|InputPanelShowRequested
condition|)
name|showInputPanel
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showInputPanel
name|void
name|QMeeGoPlatformInputContext
operator|::
name|showInputPanel
parameter_list|()
block|{
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"showInputPanel"
expr_stmt|;
name|QInputPanel
modifier|*
name|panel
init|=
name|qApp
operator|->
name|inputPanel
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|panel
operator|->
name|inputItem
argument_list|()
operator|||
operator|!
name|panel
operator|->
name|inputWindow
argument_list|()
condition|)
name|d
operator|->
name|visibility
operator|=
name|InputPanelShowRequested
expr_stmt|;
else|else
block|{
name|d
operator|->
name|server
operator|->
name|showInputMethod
argument_list|()
expr_stmt|;
name|d
operator|->
name|visibility
operator|=
name|InputPanelShown
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|hideInputPanel
name|void
name|QMeeGoPlatformInputContext
operator|::
name|hideInputPanel
parameter_list|()
block|{
name|d
operator|->
name|server
operator|->
name|hideInputMethod
argument_list|()
expr_stmt|;
name|d
operator|->
name|visibility
operator|=
name|InputPanelHidden
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isInputPanelVisible
name|bool
name|QMeeGoPlatformInputContext
operator|::
name|isInputPanelVisible
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|visibility
operator|==
name|InputPanelShown
return|;
block|}
end_function
begin_constructor
DECL|function|QMeeGoPlatformInputContextPrivate
name|QMeeGoPlatformInputContextPrivate
operator|::
name|QMeeGoPlatformInputContextPrivate
parameter_list|(
name|QMeeGoPlatformInputContext
modifier|*
name|qq
parameter_list|)
member_init_list|:
name|connection
argument_list|(
name|QDBusConnection
operator|::
name|connectToPeer
argument_list|(
name|maliitServerAddress
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"MeeGoIMProxy"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|server
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|adaptor
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|visibility
argument_list|(
name|InputPanelHidden
argument_list|)
member_init_list|,
name|valid
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|active
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|correctionEnabled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|q
argument_list|(
name|qq
argument_list|)
block|{
if|if
condition|(
operator|!
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|qDebug
argument_list|(
literal|"QMeeGoPlatformInputContext: not connected."
argument_list|)
expr_stmt|;
return|return;
block|}
name|server
operator|=
operator|new
name|ComMeegoInputmethodUiserver1Interface
argument_list|(
name|QStringLiteral
argument_list|(
literal|""
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/com/meego/inputmethod/uiserver1"
argument_list|)
argument_list|,
name|connection
argument_list|)
expr_stmt|;
name|adaptor
operator|=
operator|new
name|Inputcontext1Adaptor
argument_list|(
name|qq
argument_list|)
expr_stmt|;
name|connection
operator|.
name|registerObject
argument_list|(
literal|"/com/meego/inputmethod/inputcontext"
argument_list|,
name|qq
argument_list|)
expr_stmt|;
enum|enum
name|InputMethodMode
block|{
comment|//! Normal mode allows to use preedit and error correction
name|InputMethodModeNormal
block|,
comment|//! Virtual keyboard sends QKeyEvent for every key press or release
name|InputMethodModeDirect
block|,
comment|//! Used with proxy widget
name|InputMethodModeProxy
block|}
enum|;
name|imState
index|[
literal|"inputMethodMode"
index|]
operator|=
name|InputMethodModeNormal
expr_stmt|;
name|imState
index|[
literal|"correctionEnabled"
index|]
operator|=
literal|true
expr_stmt|;
name|valid
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sendStateUpdate
name|void
name|QMeeGoPlatformInputContextPrivate
operator|::
name|sendStateUpdate
parameter_list|(
name|bool
name|focusChanged
parameter_list|)
block|{
name|server
operator|->
name|updateWidgetInformation
argument_list|(
name|imState
argument_list|,
name|focusChanged
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
