begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* Dialogs */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_FILEDIALOG
define|#
directive|define
name|QT_NO_FILEDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FONTDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_FONTDIALOG
define|#
directive|define
name|QT_NO_FONTDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_INPUTDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_INPUTDIALOG
define|#
directive|define
name|QT_NO_INPUTDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_PRINTDIALOG
define|#
directive|define
name|QT_NO_PRINTDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSDIALOG
end_ifndef
begin_define
DECL|macro|QT_NO_PROGRESSDIALOG
define|#
directive|define
name|QT_NO_PROGRESSDIALOG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Images */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_BMP
end_ifndef
begin_define
DECL|macro|QT_NO_IMAGEFORMAT_BMP
define|#
directive|define
name|QT_NO_IMAGEFORMAT_BMP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_PPM
end_ifndef
begin_define
DECL|macro|QT_NO_IMAGEFORMAT_PPM
define|#
directive|define
name|QT_NO_IMAGEFORMAT_PPM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Internationalization */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CODECS
end_ifndef
begin_define
DECL|macro|QT_NO_CODECS
define|#
directive|define
name|QT_NO_CODECS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
end_ifndef
begin_define
DECL|macro|QT_NO_TRANSLATION
define|#
directive|define
name|QT_NO_TRANSLATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ItemViews */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLEVIEW
end_ifndef
begin_define
DECL|macro|QT_NO_TABLEVIEW
define|#
directive|define
name|QT_NO_TABLEVIEW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEVIEW
end_ifndef
begin_define
DECL|macro|QT_NO_TREEVIEW
define|#
directive|define
name|QT_NO_TREEVIEW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Kernel */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_define
DECL|macro|QT_NO_CLIPBOARD
define|#
directive|define
name|QT_NO_CLIPBOARD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_define
DECL|macro|QT_NO_DRAGANDDROP
define|#
directive|define
name|QT_NO_DRAGANDDROP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EFFECTS
end_ifndef
begin_define
DECL|macro|QT_NO_EFFECTS
define|#
directive|define
name|QT_NO_EFFECTS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROPERTIES
end_ifndef
begin_define
DECL|macro|QT_NO_PROPERTIES
define|#
directive|define
name|QT_NO_PROPERTIES
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Networking */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_define
DECL|macro|QT_NO_HTTP
define|#
directive|define
name|QT_NO_HTTP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
end_ifndef
begin_define
DECL|macro|QT_NO_UDPSOCKET
define|#
directive|define
name|QT_NO_UDPSOCKET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FTP
end_ifndef
begin_define
DECL|macro|QT_NO_FTP
define|#
directive|define
name|QT_NO_FTP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Painting */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COLORNAMES
end_ifndef
begin_define
DECL|macro|QT_NO_COLORNAMES
define|#
directive|define
name|QT_NO_COLORNAMES
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
end_ifndef
begin_define
DECL|macro|QT_NO_PICTURE
define|#
directive|define
name|QT_NO_PICTURE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_define
DECL|macro|QT_NO_PRINTER
define|#
directive|define
name|QT_NO_PRINTER
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CUPS
end_ifndef
begin_define
DECL|macro|QT_NO_CUPS
define|#
directive|define
name|QT_NO_CUPS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Styles */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
end_ifndef
begin_define
DECL|macro|QT_NO_STYLE_STYLESHEET
define|#
directive|define
name|QT_NO_STYLE_STYLESHEET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Widgets */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CALENDARWIDGET
end_ifndef
begin_define
DECL|macro|QT_NO_CALENDARWIDGET
define|#
directive|define
name|QT_NO_CALENDARWIDGET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATETIMEEDIT
end_ifndef
begin_define
DECL|macro|QT_NO_DATETIMEEDIT
define|#
directive|define
name|QT_NO_DATETIMEEDIT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIAL
end_ifndef
begin_define
DECL|macro|QT_NO_DIAL
define|#
directive|define
name|QT_NO_DIAL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLEWIDGET
end_ifndef
begin_define
DECL|macro|QT_NO_TABLEWIDGET
define|#
directive|define
name|QT_NO_TABLEWIDGET
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
end_ifndef
begin_define
DECL|macro|QT_NO_TREEWIDGET
define|#
directive|define
name|QT_NO_TREEWIDGET
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
