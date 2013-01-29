begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOANATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QCOCOANATIVEINTERFACE_H
define|#
directive|define
name|QCOCOANATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformPrinterSupport
name|class
name|QPlatformPrinterSupport
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintEngine
name|class
name|QPrintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QCocoaNativeInterface
argument_list|()
block|;
name|void
operator|*
name|nativeResourceForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|NativeResourceForIntegrationFunction
name|nativeResourceFunctionForIntegration
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|void
operator|*
name|cglContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|void
operator|*
name|nsOpenGLContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|onAppFocusWindowChanged
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
comment|/*         "Virtual" function to create the platform printer support         implementation.          We use an invokable function instead of a virtual one, we do not want         this in the QPlatform* API yet.          This was added here only because QPlatformNativeInterface is a QObject         and allow us to use QMetaObject::indexOfMethod() from the printsupport         plugin.     */
name|Q_INVOKABLE
name|QPlatformPrinterSupport
operator|*
name|createPlatformPrinterSupport
argument_list|()
block|;
comment|/*         Function to return the NSPrintInfo * from QMacPaintEnginePrivate.         Needed by the native print dialog in the Qt Print Support module.     */
name|Q_INVOKABLE
name|void
operator|*
name|NSPrintInfoForPrintEngine
argument_list|(
name|QPrintEngine
operator|*
name|printEngine
argument_list|)
block|;
comment|// QMacPastebardMime support. The mac pasteboard void pointers are
comment|// QMacPastebardMime instances from the cocoa plugin or qtmacextras
comment|// These two classes are kept in sync and can be casted between.
specifier|static
name|void
name|addToMimeList
argument_list|(
name|void
operator|*
name|macPasteboardMime
argument_list|)
block|;
specifier|static
name|void
name|removeFromMimeList
argument_list|(
name|void
operator|*
name|macPasteboardMime
argument_list|)
block|;
specifier|static
name|void
name|registerDraggedTypes
argument_list|(
specifier|const
name|QStringList
operator|&
name|types
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOANATIVEINTERFACE_H
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
