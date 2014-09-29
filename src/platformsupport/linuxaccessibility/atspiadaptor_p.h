begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ATSPIADAPTOR_H
end_ifndef
begin_define
DECL|macro|ATSPIADAPTOR_H
define|#
directive|define
name|ATSPIADAPTOR_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<atspi/atspi-constants.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusvirtualobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|"dbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"struct_marshallers_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpiAccessibleInterface
name|class
name|QSpiAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpiApplicationAdaptor
name|class
name|QSpiApplicationAdaptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AtSpiAdaptor
range|:
name|public
name|QDBusVirtualObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|AtSpiAdaptor
argument_list|(
name|DBusConnection
operator|*
name|connection
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|AtSpiAdaptor
argument_list|()
block|;
name|void
name|registerApplication
argument_list|()
block|;
name|QString
name|introspect
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|bool
name|handleMessage
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|void
name|notify
argument_list|(
name|QAccessibleEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|checkInitializedAndEnabled
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|eventListenerRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|bus
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|eventListenerDeregistered
argument_list|(
specifier|const
name|QString
operator|&
name|bus
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|windowActivated
argument_list|(
argument|QObject* window
argument_list|,
argument|bool active
argument_list|)
block|;
name|private
operator|:
name|void
name|updateEventListeners
argument_list|()
block|;
name|void
name|setBitFlag
argument_list|(
specifier|const
name|QString
operator|&
name|flag
argument_list|)
block|;
comment|// sending messages
name|QVariantList
name|packDBusSignalArguments
argument_list|(
argument|const QString&type
argument_list|,
argument|int data1
argument_list|,
argument|int data2
argument_list|,
argument|const QVariant&variantData
argument_list|)
specifier|const
block|;
name|bool
name|sendDBusSignal
argument_list|(
argument|const QString&path
argument_list|,
argument|const QString&interface
argument_list|,
argument|const QString&name
argument_list|,
argument|const QVariantList&arguments
argument_list|)
specifier|const
block|;
name|QVariant
name|variantForPath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|void
name|sendFocusChanged
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
name|void
name|notifyAboutCreation
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
name|void
name|notifyAboutDestruction
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
name|void
name|childrenChanged
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
comment|// handlers for the different accessible interfaces
name|bool
name|applicationInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|accessibleInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|componentInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|actionInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|textInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|editableTextInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|valueInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|bool
name|tableInterface
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|function
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|)
block|;
name|void
name|sendReply
argument_list|(
argument|const QDBusConnection&connection
argument_list|,
argument|const QDBusMessage&message
argument_list|,
argument|const QVariant&argument
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|interfaceFromPath
argument_list|(
argument|const QString& dbusPath
argument_list|)
specifier|const
block|;
name|QString
name|pathForInterface
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
name|QString
name|pathForObject
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|void
name|notifyStateChange
argument_list|(
argument|QAccessibleInterface *interface
argument_list|,
argument|const QString& state
argument_list|,
argument|int value
argument_list|)
block|;
comment|// accessible helper functions
name|AtspiRole
name|getRole
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
name|QSpiRelationArray
name|relationSet
argument_list|(
argument|QAccessibleInterface *interface
argument_list|,
argument|const QDBusConnection&connection
argument_list|)
specifier|const
block|;
name|QStringList
name|accessibleInterfaces
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
comment|// component helper functions
specifier|static
name|QRect
name|getExtents
argument_list|(
argument|QAccessibleInterface *interface
argument_list|,
argument|uint coordType
argument_list|)
block|;
specifier|static
name|QRect
name|translateRectToWindowCoordinates
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
comment|// action helper functions
name|QSpiActionArray
name|getActions
argument_list|(
argument|QAccessibleInterface *interface
argument_list|)
specifier|const
block|;
comment|// text helper functions
name|QVariantList
name|getAttributes
argument_list|(
argument|QAccessibleInterface *
argument_list|,
argument|int offset
argument_list|,
argument|bool includeDefaults
argument_list|)
specifier|const
block|;
name|QVariantList
name|getAttributeValue
argument_list|(
argument|QAccessibleInterface *
argument_list|,
argument|int offset
argument_list|,
argument|const QString&attributeName
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QVariant
operator|>
name|getCharacterExtents
argument_list|(
argument|QAccessibleInterface *
argument_list|,
argument|int offset
argument_list|,
argument|uint coordType
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QVariant
operator|>
name|getRangeExtents
argument_list|(
argument|QAccessibleInterface *
argument_list|,
argument|int startOffset
argument_list|,
argument|int endOffset
argument_list|,
argument|uint coordType
argument_list|)
specifier|const
block|;
name|QAccessible
operator|::
name|TextBoundaryType
name|qAccessibleBoundaryType
argument_list|(
argument|int atspiTextBoundaryType
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|inheritsQAction
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
comment|// private vars
name|QSpiObjectReference
name|accessibilityRegistry
block|;
name|DBusConnection
operator|*
name|m_dbus
block|;
name|QSpiApplicationAdaptor
operator|*
name|m_applicationAdaptor
block|;
comment|/// Assigned from the accessibility registry.
name|int
name|m_applicationId
block|;
comment|// Bit fields - which updates to send
comment|// AT-SPI has some events that we do not care about:
comment|// document
comment|// document-load-complete
comment|// document-load-stopped
comment|// document-reload
name|uint
name|sendFocus
operator|:
literal|1
block|;
comment|// mouse abs/rel/button
comment|// all of object
name|uint
name|sendObject
operator|:
literal|1
block|;
name|uint
name|sendObject_active_descendant_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_attributes_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_bounds_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_children_changed
operator|:
literal|1
block|;
comment|//    uint sendObject_children_changed_add : 1;
comment|//    uint sendObject_children_changed_remove : 1;
name|uint
name|sendObject_column_deleted
operator|:
literal|1
block|;
name|uint
name|sendObject_column_inserted
operator|:
literal|1
block|;
name|uint
name|sendObject_column_reordered
operator|:
literal|1
block|;
name|uint
name|sendObject_link_selected
operator|:
literal|1
block|;
name|uint
name|sendObject_model_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_description
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_name
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_parent
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_role
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_caption
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_column_description
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_column_header
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_row_description
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_row_header
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_table_summary
operator|:
literal|1
block|;
name|uint
name|sendObject_property_change_accessible_value
operator|:
literal|1
block|;
name|uint
name|sendObject_row_deleted
operator|:
literal|1
block|;
name|uint
name|sendObject_row_inserted
operator|:
literal|1
block|;
name|uint
name|sendObject_row_reordered
operator|:
literal|1
block|;
name|uint
name|sendObject_selection_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_state_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_text_attributes_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_text_bounds_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_text_caret_moved
operator|:
literal|1
block|;
name|uint
name|sendObject_text_changed
operator|:
literal|1
block|;
comment|//    uint sendObject_text_changed_delete : 1;
comment|//    uint sendObject_text_changed_insert : 1;
name|uint
name|sendObject_text_selection_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_value_changed
operator|:
literal|1
block|;
name|uint
name|sendObject_visible_data_changed
operator|:
literal|1
block|;
comment|// we don't implement terminal
comment|// terminal-application_changed/charwidth_changed/columncount_changed/line_changed/linecount_changed
name|uint
name|sendWindow
operator|:
literal|1
block|;
name|uint
name|sendWindow_activate
operator|:
literal|1
block|;
name|uint
name|sendWindow_close
operator|:
literal|1
block|;
name|uint
name|sendWindow_create
operator|:
literal|1
block|;
name|uint
name|sendWindow_deactivate
operator|:
literal|1
block|;
comment|//    uint sendWindow_desktop_create : 1;
comment|//    uint sendWindow_desktop_destroy : 1;
name|uint
name|sendWindow_lower
operator|:
literal|1
block|;
name|uint
name|sendWindow_maximize
operator|:
literal|1
block|;
name|uint
name|sendWindow_minimize
operator|:
literal|1
block|;
name|uint
name|sendWindow_move
operator|:
literal|1
block|;
name|uint
name|sendWindow_raise
operator|:
literal|1
block|;
name|uint
name|sendWindow_reparent
operator|:
literal|1
block|;
name|uint
name|sendWindow_resize
operator|:
literal|1
block|;
name|uint
name|sendWindow_restore
operator|:
literal|1
block|;
name|uint
name|sendWindow_restyle
operator|:
literal|1
block|;
name|uint
name|sendWindow_shade
operator|:
literal|1
block|;
name|uint
name|sendWindow_unshade
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
