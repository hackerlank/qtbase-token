begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QENGINES_H
end_ifndef
begin_define
DECL|macro|QENGINES_H
define|#
directive|define
name|QENGINES_H
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|BUILD_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QGLPixelBuffer>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QSvgRenderer
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QGLWidget
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QEngine
block|{
name|public
label|:
name|virtual
operator|~
name|QEngine
argument_list|()
expr_stmt|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|prepare
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QColor
modifier|&
name|fillColor
init|=
name|Qt
operator|::
name|white
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|render
parameter_list|(
name|QSvgRenderer
modifier|*
name|r
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|render
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|qpsScript
parameter_list|,
specifier|const
name|QString
modifier|&
name|absFilePath
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|drawOnPainter
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|save
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|cleanup
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QtEngines
block|{
name|public
label|:
specifier|static
name|QtEngines
modifier|*
name|self
parameter_list|()
function_decl|;
name|QtEngines
argument_list|()
expr_stmt|;
name|QList
operator|<
name|QEngine
operator|*
operator|>
name|engines
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QEngine
operator|*
operator|>
name|foreignEngines
argument_list|()
specifier|const
expr_stmt|;
name|QEngine
operator|*
name|defaultEngine
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|init
parameter_list|()
function_decl|;
name|private
label|:
name|QList
operator|<
name|QEngine
operator|*
operator|>
name|m_engines
expr_stmt|;
name|QList
operator|<
name|QEngine
operator|*
operator|>
name|m_foreignEngines
expr_stmt|;
name|QEngine
modifier|*
name|m_defaultEngine
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|RasterEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|RasterEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|private
operator|:
name|QImage
name|image
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|NativeEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|NativeEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|private
operator|:
name|QPixmap
name|pixmap
block|; }
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|BUILD_OPENGL
argument_list|)
end_if
begin_decl_stmt
name|class
name|GLEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|GLEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|_size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|void
name|cleanup
argument_list|()
block|;
name|private
operator|:
name|QGLPixelBuffer
operator|*
name|pbuffer
block|;
name|QGLWidget
operator|*
name|widget
block|;
name|bool
name|usePixelBuffers
block|;
name|QSize
name|size
block|;
name|QColor
name|fillColor
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|WidgetEngineWidget
name|class
name|WidgetEngineWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|WidgetEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|WidgetEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|_size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|void
name|cleanup
argument_list|()
block|;
name|private
operator|:
name|WidgetEngineWidget
operator|*
name|m_widget
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_decl_stmt
name|class
name|PDFEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|PDFEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|void
name|cleanup
argument_list|()
block|;
name|private
operator|:
name|QPrinter
operator|*
name|printer
block|;
name|QSize
name|m_size
block|;
name|QString
name|m_tempFile
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_decl_stmt
name|class
name|PSEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|PSEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|void
name|cleanup
argument_list|()
block|;
name|private
operator|:
name|QPrinter
operator|*
name|printer
block|;
name|QSize
name|m_size
block|;
name|QString
name|m_tempFile
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_decl_stmt
name|class
name|WinPrintEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|WinPrintEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|virtual
name|void
name|cleanup
argument_list|()
block|;
name|private
operator|:
name|QPrinter
operator|*
name|printer
block|;
name|QSize
name|m_size
block|;
name|QString
name|m_tempFile
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_PRINTER
end_comment
begin_decl_stmt
name|class
name|RSVGEngine
range|:
name|public
name|QEngine
block|{
name|public
operator|:
name|RSVGEngine
argument_list|()
block|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|prepare
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
name|QSvgRenderer
operator|*
name|r
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|QStringList
operator|&
name|qpsScript
argument_list|,
specifier|const
name|QString
operator|&
name|absFilePath
argument_list|)
block|;
name|virtual
name|bool
name|drawOnPainter
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|virtual
name|void
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|private
operator|:
name|QString
name|m_fileName
block|;
name|QSize
name|m_size
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
