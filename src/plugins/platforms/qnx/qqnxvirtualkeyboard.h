begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|VIRTUALKEYBOARD_H_
end_ifndef
begin_define
DECL|macro|VIRTUALKEYBOARD_H_
define|#
directive|define
name|VIRTUALKEYBOARD_H_
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<sys/pps.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Shamelessly copied from the browser - this should be rewritten once we have a proper PPS wrapper class */
end_comment
begin_decl_stmt
name|class
name|QQnxVirtualKeyboard
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// NOTE:  Not all the following keyboard modes are currently used.
comment|// Default - Regular Keyboard
comment|// Url/Email - Enhanced keys for each types.
comment|// Web - Regular keyboard with two blank keys, currently unused.
comment|// NumPunc - Numbers& Punctionation, alternate to Symbol
comment|// Symbol - All symbols, alternate to NumPunc, currently unused.
comment|// Phone - Phone enhanced keyboard - currently unused as no alternate keyboard available to access a-zA-Z
comment|// Pin - Keyboard for entering Pins (Hex values) currently unused.
comment|//
comment|// SPECIAL NOTE: Usage of NumPunc may have to be removed, ABC button is non-functional.
comment|//
expr|enum
name|KeyboardMode
block|{
name|Default
block|,
name|Url
block|,
name|Email
block|,
name|Web
block|,
name|NumPunc
block|,
name|Symbol
block|,
name|Phone
block|,
name|Pin
block|}
block|;
name|QQnxVirtualKeyboard
argument_list|()
block|;
operator|~
name|QQnxVirtualKeyboard
argument_list|()
block|;
name|bool
name|showKeyboard
argument_list|()
block|;
name|bool
name|hideKeyboard
argument_list|()
block|;
name|int
name|height
argument_list|()
block|{
return|return
name|m_visible
operator|?
name|m_height
operator|:
literal|0
return|;
block|}
name|void
name|setKeyboardMode
argument_list|(
name|KeyboardMode
argument_list|)
block|;
name|void
name|notifyClientActiveStateChange
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|{
return|return
name|m_visible
return|;
block|}
name|QLocale
name|locale
argument_list|()
specifier|const
block|{
return|return
name|m_locale
return|;
block|}
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|localeChanged
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|void
name|visibilityChanged
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|heightChanged
argument_list|(
argument|int height
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|ppsDataReady
argument_list|()
block|;
name|private
operator|:
comment|// Will be called internally if needed.
name|bool
name|connect
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
name|bool
name|queryPPSInfo
argument_list|()
block|;
name|void
name|handleKeyboardInfoMessage
argument_list|()
block|;
name|void
name|handleKeyboardStateChangeMessage
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|applyKeyboardModeOptions
argument_list|()
block|;
name|void
name|addDefaultModeOptions
argument_list|()
block|;
name|void
name|addUrlModeOptions
argument_list|()
block|;
name|void
name|addEmailModeOptions
argument_list|()
block|;
name|void
name|addWebModeOptions
argument_list|()
block|;
name|void
name|addNumPuncModeOptions
argument_list|()
block|;
name|void
name|addSymbolModeOptions
argument_list|()
block|;
name|void
name|addPhoneModeOptions
argument_list|()
block|;
name|void
name|addPinModeOptions
argument_list|()
block|;
name|pps_encoder_t
operator|*
name|m_encoder
block|;
name|pps_decoder_t
operator|*
name|m_decoder
block|;
name|char
operator|*
name|m_buffer
block|;
name|int
name|m_height
block|;
name|int
name|m_fd
block|;
name|KeyboardMode
name|m_keyboardMode
block|;
name|bool
name|m_visible
block|;
name|QLocale
name|m_locale
block|;
name|QSocketNotifier
operator|*
name|m_readNotifier
block|;
comment|// Path to keyboardManager in PPS.
specifier|static
specifier|const
name|char
operator|*
name|ms_PPSPath
block|;
specifier|static
specifier|const
name|size_t
name|ms_bufferSize
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* VIRTUALKEYBOARD_H_ */
end_comment
end_unit
