begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformtheme_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformTheme     \since 5.0     \internal     \preliminary     \ingroup qpa     \brief The QPlatformTheme class allows customizing the UI based on themes.  */
comment|/*!     \enum QPlatformTheme::ThemeHint      This enum describes the available theme hints.      \value TextCursorWidth  (int) Determines the width of the text cursor.      \value DropShadow       (bool) Determines whether the drop shadow effect for                             tooltips or whatsthis is enabled.      \value MaximumScrollBarDragDistance (int) Determines the value returned by                             QStyle::pixelMetric(PM_MaximumDragDistance)      \sa themeHint(), QStyle::pixelMetric() */
DECL|function|createPlatformMenu
name|QPlatformMenu
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformMenu
parameter_list|(
name|QMenu
modifier|*
name|menu
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|menu
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenuBar
name|QPlatformMenuBar
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformMenuBar
parameter_list|(
name|QMenuBar
modifier|*
name|menuBar
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QPlatformTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QPlatformTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|themeHint
name|QVariant
name|QPlatformTheme
operator|::
name|themeHint
parameter_list|(
name|ThemeHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|TextCursorWidth
case|:
return|return
name|QVariant
argument_list|(
literal|1
argument_list|)
return|;
case|case
name|DropShadow
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|MaximumScrollBarDragDistance
case|:
return|return
name|QVariant
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
