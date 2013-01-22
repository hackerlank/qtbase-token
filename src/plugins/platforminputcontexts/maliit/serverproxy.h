begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SERVER_H_1318935108
end_ifndef
begin_define
DECL|macro|SERVER_H_1318935108
define|#
directive|define
name|SERVER_H_1318935108
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
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
file|<QtDBus/QtDBus>
end_include
begin_comment
comment|/*  * Proxy class for interface com.meego.inputmethod.uiserver1  */
end_comment
begin_decl_stmt
name|class
name|ComMeegoInputmethodUiserver1Interface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|char
operator|*
name|staticInterfaceName
argument_list|()
block|{
return|return
literal|"com.meego.inputmethod.uiserver1"
return|;
block|}
name|public
operator|:
name|ComMeegoInputmethodUiserver1Interface
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QDBusConnection
operator|&
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
name|ComMeegoInputmethodUiserver1Interface
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|activateContext
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"activateContext"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|appOrientationAboutToChange
argument_list|(
argument|int in0
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"appOrientationAboutToChange"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|appOrientationChanged
argument_list|(
argument|int in0
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"appOrientationChanged"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|hideInputMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"hideInputMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|mouseClickedOnPreedit
argument_list|(
argument|int in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|int in3
argument_list|,
argument|int in4
argument_list|,
argument|int in5
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in1
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in2
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in3
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in4
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in5
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"mouseClickedOnPreedit"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|processKeyEvent
argument_list|(
argument|int in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|const QString&in3
argument_list|,
argument|bool in4
argument_list|,
argument|int in5
argument_list|,
argument|uint in6
argument_list|,
argument|uint in7
argument_list|,
argument|uint in8
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in1
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in2
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in3
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in4
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in5
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in6
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in7
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in8
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"processKeyEvent"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|setPreedit
argument_list|(
argument|const QString&in0
argument_list|,
argument|int in1
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in1
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"setPreedit"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|showInputMethod
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"showInputMethod"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|updateWidgetInformation
argument_list|(
argument|const QMap<QString
argument_list|,
argument|QVariant>&stateInformation
argument_list|,
argument|bool focusChanged
argument_list|)
block|{
name|QDBusMessage
name|msg
operator|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|service
argument_list|()
argument_list|,
name|path
argument_list|()
argument_list|,
name|interface
argument_list|()
argument_list|,
literal|"updateWidgetInformation"
argument_list|)
block|;
name|QDBusArgument
name|map
block|;
name|map
operator|.
name|beginMap
argument_list|(
name|QVariant
operator|::
name|String
argument_list|,
name|qMetaTypeId
operator|<
name|QDBusVariant
operator|>
operator|(
operator|)
argument_list|)
block|;
for|for
control|(
name|QMap
operator|<
name|QString
init|,
name|QVariant
operator|>
operator|::
name|ConstIterator
name|it
operator|=
name|stateInformation
operator|.
name|constBegin
argument_list|()
init|,
name|end
operator|=
name|stateInformation
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|map
operator|.
name|beginMapEntry
argument_list|()
expr_stmt|;
name|map
operator|<<
name|it
operator|.
name|key
argument_list|()
expr_stmt|;
name|map
operator|<<
name|QDBusVariant
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|map
operator|.
name|endMapEntry
argument_list|()
expr_stmt|;
block|}
name|map
operator|.
name|endMap
argument_list|()
expr_stmt|;
name|QList
operator|<
name|QVariant
operator|>
name|args
block|;
name|args
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|map
argument_list|)
operator|<<
name|QVariant
argument_list|(
name|focusChanged
argument_list|)
block|;
name|msg
operator|.
name|setArguments
argument_list|(
name|args
argument_list|)
block|;
return|return
name|connection
argument_list|()
operator|.
name|asyncCall
argument_list|(
name|msg
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|reset
argument_list|()
block|{
return|return
name|asyncCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"reset"
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|setCopyPasteState
argument_list|(
argument|bool in0
argument_list|,
argument|bool in1
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in0
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|in1
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"setCopyPasteState"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
end_expr_stmt
begin_label
name|Q_SIGNALS
label|:
end_label
begin_comment
comment|// SIGNALS
end_comment
begin_decl_stmt
unit|};
name|namespace
name|com
block|{
name|namespace
name|meego
block|{
name|namespace
name|inputmethod
block|{
typedef|typedef
operator|::
name|ComMeegoInputmethodUiserver1Interface
name|uiserver1
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
