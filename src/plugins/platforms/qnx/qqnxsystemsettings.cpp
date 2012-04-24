begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxsystemsettings.h"
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_qnx_createRoleFonts
name|QHash
argument_list|<
name|QPlatformTheme
operator|::
name|Font
argument_list|,
name|QFont
modifier|*
argument_list|>
name|qt_qnx_createRoleFonts
parameter_list|(
name|QPlatformFontDatabase
modifier|*
name|fontDatabase
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// See http://docs.blackberry.com/en/developers/deliverables/27299/Text_tablet_1526156_11.jsp
comment|// which recommends using normal font size of 21 pixels and 36 pixels for titles (not covered
comment|// by the theme system).
name|QFont
name|baseFont
init|=
name|fontDatabase
operator|->
name|defaultFont
argument_list|()
decl_stmt|;
name|baseFont
operator|.
name|setPixelSize
argument_list|(
literal|21
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|QPlatformTheme
operator|::
name|Font
argument_list|,
name|QFont
modifier|*
argument_list|>
name|fonts
decl_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|SystemFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|PushButtonFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|ListViewFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|ListBoxFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|TitleBarFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|MenuFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|ComboMenuItemFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|HeaderViewFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|TipLabelFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|LabelFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|ToolButtonFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|MenuItemFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|ComboLineEditFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|baseFont
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|smallFont
argument_list|(
name|baseFont
argument_list|)
decl_stmt|;
name|smallFont
operator|.
name|setPixelSize
argument_list|(
literal|15
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|SmallFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|smallFont
argument_list|)
argument_list|)
expr_stmt|;
name|fonts
operator|.
name|insert
argument_list|(
name|QPlatformTheme
operator|::
name|MiniFont
argument_list|,
operator|new
name|QFont
argument_list|(
name|smallFont
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|fonts
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
