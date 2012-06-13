begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qstylehints.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|hint
specifier|static
specifier|inline
name|QVariant
name|hint
parameter_list|(
name|QPlatformIntegration
operator|::
name|StyleHint
name|h
parameter_list|)
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|styleHint
argument_list|(
name|h
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QStyleHints     \since 5.0     \brief The QStyleHints contains platform specific hints and settings.     \inmodule QtGui  */
end_comment
begin_constructor
DECL|function|QStyleHints
name|QStyleHints
operator|::
name|QStyleHints
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|mouseDoubleClickInterval
name|int
name|QStyleHints
operator|::
name|mouseDoubleClickInterval
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|MouseDoubleClickInterval
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startDragDistance
name|int
name|QStyleHints
operator|::
name|startDragDistance
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|StartDragDistance
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startDragTime
name|int
name|QStyleHints
operator|::
name|startDragTime
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|StartDragTime
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|startDragVelocity
name|int
name|QStyleHints
operator|::
name|startDragVelocity
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|StartDragVelocity
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|keyboardInputInterval
name|int
name|QStyleHints
operator|::
name|keyboardInputInterval
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|KeyboardInputInterval
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|keyboardAutoRepeatRate
name|int
name|QStyleHints
operator|::
name|keyboardAutoRepeatRate
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|KeyboardAutoRepeatRate
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|cursorFlashTime
name|int
name|QStyleHints
operator|::
name|cursorFlashTime
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|CursorFlashTime
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|showIsFullScreen
name|bool
name|QStyleHints
operator|::
name|showIsFullScreen
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
argument_list|)
operator|.
name|toBool
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|passwordMaskDelay
name|int
name|QStyleHints
operator|::
name|passwordMaskDelay
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|PasswordMaskDelay
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fontSmoothingGamma
name|qreal
name|QStyleHints
operator|::
name|fontSmoothingGamma
parameter_list|()
specifier|const
block|{
return|return
name|hint
argument_list|(
name|QPlatformIntegration
operator|::
name|FontSmoothingGamma
argument_list|)
operator|.
name|toReal
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
