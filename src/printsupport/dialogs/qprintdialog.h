begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTDIALOG_H
end_ifndef
begin_define
DECL|macro|QPRINTDIALOG_H
define|#
directive|define
name|QPRINTDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtPrintSupport/qabstractprintdialog.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
DECL|variable|QPrintDialogPrivate
name|class
name|QPrintDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_PRINTSUPPORT_EXPORT
name|QPrintDialog
range|:
name|public
name|QAbstractPrintDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrintDialog
argument_list|)
name|Q_ENUMS
argument_list|(
argument|PrintDialogOption
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|PrintDialogOptions options READ options WRITE setOptions
argument_list|)
name|public
operator|:
name|explicit
name|QPrintDialog
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QPrintDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPrintDialog
argument_list|()
block|;
name|int
name|exec
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|virtual
name|void
name|accept
argument_list|()
block|;
endif|#
directive|endif
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|;
name|void
name|setOption
argument_list|(
argument|PrintDialogOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|PrintDialogOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|PrintDialogOptions options
argument_list|)
block|;
name|PrintDialogOptions
name|options
argument_list|()
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_QDOC
name|QPrinter
operator|*
name|printer
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|accepted
argument_list|()
block|{
name|QDialog
operator|::
name|accepted
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|accepted
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|accepted
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|)
block|;
name|private
operator|:
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_chbPrintLastFirstToggled(bool)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_collapseOrExpandDialog()
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_MESSAGEBOX
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_checkFields()
argument_list|)
endif|#
directive|endif
comment|// QT_NO_MESSAGEBOX
name|friend
name|class
name|QUnixPrintWidget
block|;
endif|#
directive|endif
comment|// Q_OS_UNIX
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTDIALOG
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
comment|// QPRINTDIALOG_H
end_comment
end_unit
