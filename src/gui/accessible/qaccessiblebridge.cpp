begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblebridge.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QAccessibleBridge     \brief The QAccessibleBridge class is the base class for     accessibility back-ends.      \ingroup accessibility      Qt supports Microsoft Active Accessibility (MSAA), Mac OS X     Accessibility, and the Unix/X11 AT-SPI standard. By subclassing     QAccessibleBridge, you can support other backends than the     predefined ones.      Currently, custom bridges are only supported on Unix. We might     add support for them on other platforms as well if there is     enough demand.      \sa QAccessible, QAccessibleBridgePlugin */
end_comment
begin_comment
comment|/*!     \fn QAccessibleBridge::~QAccessibleBridge()      Destroys the accessibility bridge object. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleBridge::setRootObject(QAccessibleInterface *object)      This function is called by Qt at application startup to set the     root accessible object of the application to \a object. All other     accessible objects in the application can be reached by the     client using object navigation. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleBridge::notifyAccessibilityUpdate(int reason, QAccessibleInterface *interface, int child)      This function is called by Qt to notify the bridge about a change     in the accessibility information for object wrapped by the given     \a interface.      \a reason specifies the cause of the change. It can take values     of type QAccessible::Event.      \a child is the (1-based) index of the child element that has     changed. When \a child is 0, the object itself has changed.      \sa QAccessible::updateAccessibility() */
end_comment
begin_comment
comment|/*!     \class QAccessibleBridgePlugin     \brief The QAccessibleBridgePlugin class provides an abstract     base for accessibility bridge plugins.      \ingroup plugins     \ingroup accessibility      Writing an accessibility bridge plugin is achieved by subclassing     this base class, reimplementing the pure virtual functions keys()     and create(), and exporting the class with the     Q_EXPORT_PLUGIN2() macro.      \sa QAccessibleBridge, QAccessiblePlugin, {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     Constructs an accessibility bridge plugin with the given \a     parent. This is invoked automatically by the Q_EXPORT_PLUGIN2()     macro. */
end_comment
begin_constructor
DECL|function|QAccessibleBridgePlugin
name|QAccessibleBridgePlugin
operator|::
name|QAccessibleBridgePlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{  }
end_constructor
begin_comment
comment|/*!     Destroys the accessibility bridge plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it is no longer used. */
end_comment
begin_destructor
DECL|function|~QAccessibleBridgePlugin
name|QAccessibleBridgePlugin
operator|::
name|~
name|QAccessibleBridgePlugin
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!     \fn QStringList QAccessibleBridgePlugin::keys() const      Returns the list of keys this plugins supports.      These keys must be the names of the bridges that this     plugin provides.      \sa create() */
end_comment
begin_comment
comment|/*!     \fn QAccessibleBridge *QAccessibleBridgePlugin::create(const QString&key)      Creates and returns the QAccessibleBridge object corresponding to     the given \a key. Keys are case sensitive.      \sa keys() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
end_unit
