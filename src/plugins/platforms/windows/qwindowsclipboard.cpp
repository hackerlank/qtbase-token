begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsole.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsmime.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsguieventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QClipboard>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMimeData>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|formatTextPlainC
specifier|static
specifier|const
name|char
name|formatTextPlainC
index|[]
init|=
literal|"text/plain"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|formatTextHtmlC
specifier|static
specifier|const
name|char
name|formatTextHtmlC
index|[]
init|=
literal|"text/html"
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QWindowsClipboard     \brief Clipboard implementation.      Registers a non-visible clipboard viewer window that     receives clipboard events in its own window procedure to be     able to receive clipboard-changed events, which     QPlatformClipboard needs to emit. That requires housekeeping     of the next in the viewer chain.      \note The OLE-functions used in this class require OleInitialize().      \internal     \ingroup qt-lighthouse-win */
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QMimeData
modifier|&
name|m
parameter_list|)
block|{
name|QDebug
name|nospace
init|=
name|d
operator|.
name|nospace
argument_list|()
decl_stmt|;
specifier|const
name|QStringList
name|formats
init|=
name|m
operator|.
name|formats
argument_list|()
decl_stmt|;
name|nospace
operator|<<
literal|"QMimeData: "
operator|<<
name|formats
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|", "
argument_list|)
argument_list|)
operator|<<
literal|'\n'
operator|<<
literal|"  Text="
operator|<<
name|m
operator|.
name|hasText
argument_list|()
operator|<<
literal|" HTML="
operator|<<
name|m
operator|.
name|hasHtml
argument_list|()
operator|<<
literal|" Color="
operator|<<
name|m
operator|.
name|hasColor
argument_list|()
operator|<<
literal|" Image="
operator|<<
name|m
operator|.
name|hasImage
argument_list|()
operator|<<
literal|" URLs="
operator|<<
name|m
operator|.
name|hasUrls
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|hasText
argument_list|()
condition|)
name|nospace
operator|<<
literal|"  Text: '"
operator|<<
name|m
operator|.
name|text
argument_list|()
operator|<<
literal|"'\n"
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|hasHtml
argument_list|()
condition|)
name|nospace
operator|<<
literal|"  HTML: '"
operator|<<
name|m
operator|.
name|html
argument_list|()
operator|<<
literal|"'\n"
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|hasColor
argument_list|()
condition|)
name|nospace
operator|<<
literal|"  Color: "
operator|<<
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|m
operator|.
name|colorData
argument_list|()
argument_list|)
operator|<<
literal|'\n'
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|hasImage
argument_list|()
condition|)
name|nospace
operator|<<
literal|"  Image: "
operator|<<
name|qvariant_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|m
operator|.
name|imageData
argument_list|()
argument_list|)
operator|.
name|size
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|hasUrls
argument_list|()
condition|)
name|nospace
operator|<<
literal|"  URLs: "
operator|<<
name|m
operator|.
name|urls
argument_list|()
operator|<<
literal|'\n'
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_comment
comment|/*!     \class QWindowsClipboardRetrievalMimeData     \brief Special mime data class managing delayed retrieval of clipboard data.      Implementation of QWindowsInternalMimeDataBase that obtains the     IDataObject from the clipboard.      \sa QWindowsInternalMimeDataBase, QWindowsClipboard     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_function
DECL|function|retrieveDataObject
name|IDataObject
modifier|*
name|QWindowsClipboardRetrievalMimeData
operator|::
name|retrieveDataObject
parameter_list|()
specifier|const
block|{
name|IDataObject
modifier|*
name|pDataObj
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|OleGetClipboard
argument_list|(
operator|&
name|pDataObj
argument_list|)
operator|==
name|S_OK
condition|)
return|return
name|pDataObj
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|releaseDataObject
name|void
name|QWindowsClipboardRetrievalMimeData
operator|::
name|releaseDataObject
parameter_list|(
name|IDataObject
modifier|*
name|dataObject
parameter_list|)
specifier|const
block|{
name|dataObject
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
end_function
begin_extern
DECL|function|qClipboardViewerWndProc
extern|extern
literal|"C"
name|LRESULT
name|QT_WIN_CALLBACK
name|qClipboardViewerWndProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
name|LRESULT
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QWindowsClipboard
operator|::
name|instance
argument_list|()
operator|&&
name|QWindowsClipboard
operator|::
name|instance
argument_list|()
operator|->
name|clipboardViewerWndProc
argument_list|(
name|hwnd
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|,
operator|&
name|result
argument_list|)
condition|)
return|return
name|result
return|;
return|return
name|DefWindowProc
argument_list|(
name|hwnd
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
return|;
block|}
end_extern
begin_decl_stmt
DECL|member|m_instance
name|QWindowsClipboard
modifier|*
name|QWindowsClipboard
operator|::
name|m_instance
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QWindowsClipboard
name|QWindowsClipboard
operator|::
name|QWindowsClipboard
parameter_list|()
member_init_list|:
name|m_data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_clipboardViewer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_nextClipboardViewer
argument_list|(
literal|0
argument_list|)
block|{
name|QWindowsClipboard
operator|::
name|m_instance
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsClipboard
name|QWindowsClipboard
operator|::
name|~
name|QWindowsClipboard
parameter_list|()
block|{
name|unregisterViewer
argument_list|()
expr_stmt|;
comment|// Should release data if owner.
name|releaseIData
argument_list|()
expr_stmt|;
name|QWindowsClipboard
operator|::
name|m_instance
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|releaseIData
name|void
name|QWindowsClipboard
operator|::
name|releaseIData
parameter_list|()
block|{
if|if
condition|(
name|m_data
condition|)
block|{
operator|delete
name|m_data
operator|->
name|mimeData
argument_list|()
expr_stmt|;
name|m_data
operator|->
name|releaseQt
argument_list|()
expr_stmt|;
name|m_data
operator|->
name|Release
argument_list|()
expr_stmt|;
name|m_data
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|registerViewer
name|void
name|QWindowsClipboard
operator|::
name|registerViewer
parameter_list|()
block|{
name|m_clipboardViewer
operator|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|createDummyWindow
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt5ClipboardView"
argument_list|)
argument_list|,
literal|L"Qt5ClipboardView"
argument_list|,
name|qClipboardViewerWndProc
argument_list|,
name|WS_OVERLAPPED
argument_list|)
expr_stmt|;
name|m_nextClipboardViewer
operator|=
name|SetClipboardViewer
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"%s m_clipboardViewer: %p next=%p"
argument_list|,
name|__FUNCTION__
argument_list|,
name|m_clipboardViewer
argument_list|,
name|m_nextClipboardViewer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterViewer
name|void
name|QWindowsClipboard
operator|::
name|unregisterViewer
parameter_list|()
block|{
if|if
condition|(
name|m_clipboardViewer
condition|)
block|{
name|ChangeClipboardChain
argument_list|(
name|m_clipboardViewer
argument_list|,
name|m_nextClipboardViewer
argument_list|)
expr_stmt|;
name|DestroyWindow
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
name|m_clipboardViewer
operator|=
name|m_nextClipboardViewer
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|propagateClipboardMessage
name|void
name|QWindowsClipboard
operator|::
name|propagateClipboardMessage
parameter_list|(
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_nextClipboardViewer
condition|)
return|return;
comment|// In rare cases, a clipboard viewer can hang (application crashed,
comment|// suspended by a shell prompt 'Select' or debugger).
if|if
condition|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|isHungAppWindow
operator|&&
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|isHungAppWindow
argument_list|(
name|m_nextClipboardViewer
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Cowardly refusing to send clipboard message to hung application..."
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return;
block|}
name|SendMessage
argument_list|(
name|m_nextClipboardViewer
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \brief Windows procedure of the clipboard viewer. Emits changed and does     housekeeping of the viewer chain. */
end_comment
begin_function
DECL|function|clipboardViewerWndProc
name|bool
name|QWindowsClipboard
operator|::
name|clipboardViewerWndProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|,
name|LRESULT
modifier|*
name|result
parameter_list|)
block|{
operator|*
name|result
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"%s HWND=%p 0x%x %s"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hwnd
argument_list|,
name|message
argument_list|,
name|QWindowsGuiEventDispatcher
operator|::
name|windowsMessageName
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|message
condition|)
block|{
case|case
name|WM_CHANGECBCHAIN
case|:
block|{
specifier|const
name|HWND
name|toBeRemoved
init|=
operator|(
name|HWND
operator|)
name|wParam
decl_stmt|;
if|if
condition|(
name|toBeRemoved
operator|==
name|m_nextClipboardViewer
condition|)
block|{
name|m_nextClipboardViewer
operator|=
operator|(
name|HWND
operator|)
name|lParam
expr_stmt|;
block|}
else|else
block|{
name|propagateClipboardMessage
argument_list|(
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
case|case
name|WM_DRAWCLIPBOARD
case|:
block|{
specifier|const
name|bool
name|owned
init|=
name|ownsClipboard
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"Clipboard changed owned %d"
argument_list|,
name|owned
argument_list|)
expr_stmt|;
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
comment|// clean up the clipboard object if we no longer own the clipboard
if|if
condition|(
operator|!
name|owned
operator|&&
name|m_data
condition|)
name|releaseIData
argument_list|()
expr_stmt|;
name|propagateClipboardMessage
argument_list|(
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
case|case
name|WM_DESTROY
case|:
comment|// Recommended shutdown
if|if
condition|(
name|ownsClipboard
argument_list|()
condition|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"Clipboard owner on shutdown, releasing."
argument_list|)
expr_stmt|;
name|OleFlushClipboard
argument_list|()
expr_stmt|;
name|releaseIData
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
comment|// switch (message)
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QWindowsClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|mode
expr_stmt|;
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|ownsClipboard
argument_list|()
condition|)
return|return
name|m_data
operator|->
name|mimeData
argument_list|()
return|;
return|return
operator|&
name|m_retrievalData
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QWindowsClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|mimeData
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|mode
operator|<<
operator|*
name|mimeData
expr_stmt|;
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return;
specifier|const
name|bool
name|newData
init|=
operator|!
name|m_data
operator|||
name|m_data
operator|->
name|mimeData
argument_list|()
operator|!=
name|mimeData
decl_stmt|;
if|if
condition|(
name|newData
condition|)
block|{
name|releaseIData
argument_list|()
expr_stmt|;
if|if
condition|(
name|mimeData
condition|)
name|m_data
operator|=
operator|new
name|QWindowsOleDataObject
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
block|}
specifier|const
name|HRESULT
name|src
init|=
name|OleSetClipboard
argument_list|(
name|m_data
argument_list|)
decl_stmt|;
if|if
condition|(
name|src
operator|!=
name|S_OK
condition|)
block|{
name|QString
name|mimeDataFormats
init|=
name|mimeData
condition|?
name|mimeData
operator|->
name|formats
argument_list|()
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|", "
argument_list|)
argument_list|)
else|:
name|QString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"NULL"
argument_list|)
argument_list|)
decl_stmt|;
name|qErrnoWarning
argument_list|(
literal|"OleSetClipboard: Failed to set mime data (%s) on clipboard: %s"
argument_list|,
name|qPrintable
argument_list|(
name|mimeDataFormats
argument_list|)
argument_list|,
name|QWindowsContext
operator|::
name|comErrorString
argument_list|(
name|src
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|releaseIData
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QWindowsClipboard
operator|::
name|clear
parameter_list|()
block|{
specifier|const
name|HRESULT
name|src
init|=
name|OleSetClipboard
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|src
operator|!=
name|S_OK
condition|)
name|qErrnoWarning
argument_list|(
literal|"OleSetClipboard: Failed to clear the clipboard: 0x%lx"
argument_list|,
name|src
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QWindowsClipboard
operator|::
name|supportsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
return|;
block|}
end_function
begin_comment
comment|// Need a non-virtual in destructor.
end_comment
begin_function
DECL|function|ownsClipboard
name|bool
name|QWindowsClipboard
operator|::
name|ownsClipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_data
operator|&&
name|OleIsCurrentClipboard
argument_list|(
name|m_data
argument_list|)
operator|==
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|ownsMode
name|bool
name|QWindowsClipboard
operator|::
name|ownsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|result
init|=
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
condition|?
name|ownsClipboard
argument_list|()
else|:
literal|false
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"%s %d returns %d"
argument_list|,
name|__FUNCTION__
argument_list|,
name|mode
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
