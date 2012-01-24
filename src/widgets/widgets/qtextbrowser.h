begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTBROWSER_H
end_ifndef
begin_define
DECL|macro|QTEXTBROWSER_H
define|#
directive|define
name|QTEXTBROWSER_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTBROWSER
DECL|variable|QTextBrowserPrivate
name|class
name|QTextBrowserPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTextBrowser
range|:
name|public
name|QTextEdit
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QUrl source READ source WRITE setSource
argument_list|)
name|Q_OVERRIDE
argument_list|(
argument|bool modified SCRIPTABLE false
argument_list|)
name|Q_OVERRIDE
argument_list|(
argument|bool readOnly DESIGNABLE false SCRIPTABLE false
argument_list|)
name|Q_OVERRIDE
argument_list|(
argument|bool undoRedoEnabled DESIGNABLE false SCRIPTABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QStringList searchPaths READ searchPaths WRITE setSearchPaths
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool openExternalLinks READ openExternalLinks WRITE setOpenExternalLinks
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool openLinks READ openLinks WRITE setOpenLinks
argument_list|)
name|public
operator|:
name|explicit
name|QTextBrowser
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QTextBrowser
argument_list|()
block|;
name|QUrl
name|source
argument_list|()
specifier|const
block|;
name|QStringList
name|searchPaths
argument_list|()
specifier|const
block|;
name|void
name|setSearchPaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|)
block|;
name|virtual
name|QVariant
name|loadResource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
argument_list|)
block|;
name|bool
name|isBackwardAvailable
argument_list|()
specifier|const
block|;
name|bool
name|isForwardAvailable
argument_list|()
specifier|const
block|;
name|void
name|clearHistory
argument_list|()
block|;
name|QString
name|historyTitle
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|QUrl
name|historyUrl
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|backwardHistoryCount
argument_list|()
specifier|const
block|;
name|int
name|forwardHistoryCount
argument_list|()
specifier|const
block|;
name|bool
name|openExternalLinks
argument_list|()
specifier|const
block|;
name|void
name|setOpenExternalLinks
argument_list|(
argument|bool open
argument_list|)
block|;
name|bool
name|openLinks
argument_list|()
specifier|const
block|;
name|void
name|setOpenLinks
argument_list|(
argument|bool open
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|setSource
argument_list|(
specifier|const
name|QUrl
operator|&
name|name
argument_list|)
block|;
name|virtual
name|void
name|backward
argument_list|()
block|;
name|virtual
name|void
name|forward
argument_list|()
block|;
name|virtual
name|void
name|home
argument_list|()
block|;
name|virtual
name|void
name|reload
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|backwardAvailable
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|forwardAvailable
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|historyChanged
argument_list|()
block|;
name|void
name|sourceChanged
argument_list|(
specifier|const
name|QUrl
operator|&
argument_list|)
block|;
name|void
name|highlighted
argument_list|(
specifier|const
name|QUrl
operator|&
argument_list|)
block|;
name|void
name|highlighted
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|anchorClicked
argument_list|(
specifier|const
name|QUrl
operator|&
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|ev
argument_list|)
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|virtual
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|ev
argument_list|)
block|;
name|virtual
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|virtual
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTextBrowser
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextBrowser
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_documentModified()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_activateAnchor(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_highlightLink(const QString&)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTBROWSER
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTBROWSER_H
end_comment
end_unit
