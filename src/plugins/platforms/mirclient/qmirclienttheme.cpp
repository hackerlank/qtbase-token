begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmirclienttheme.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
DECL|member|name
specifier|const
name|char
modifier|*
name|QMirClientTheme
operator|::
name|name
init|=
literal|"ubuntu"
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QMirClientTheme
name|QMirClientTheme
operator|::
name|QMirClientTheme
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QMirClientTheme
name|QMirClientTheme
operator|::
name|~
name|QMirClientTheme
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|themeHint
name|QVariant
name|QMirClientTheme
operator|::
name|themeHint
parameter_list|(
name|ThemeHint
name|hint
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|hint
operator|==
name|QPlatformTheme
operator|::
name|SystemIconThemeName
condition|)
block|{
name|QByteArray
name|iconTheme
init|=
name|qgetenv
argument_list|(
literal|"QTUBUNTU_ICON_THEME"
argument_list|)
decl_stmt|;
if|if
condition|(
name|iconTheme
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
name|QVariant
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ubuntu-mobile"
argument_list|)
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QVariant
argument_list|(
name|QString
argument_list|(
name|iconTheme
argument_list|)
argument_list|)
return|;
block|}
block|}
else|else
block|{
return|return
name|QGenericUnixTheme
operator|::
name|themeHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
end_unit
