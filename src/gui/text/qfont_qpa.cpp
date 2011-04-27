begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformFontDatabase>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|initialize
name|void
name|QFont
operator|::
name|initialize
parameter_list|()
block|{
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|populateFontDatabase
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QFont
operator|::
name|cleanup
parameter_list|()
block|{
name|QFontCache
operator|::
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*****************************************************************************   QFont member functions  *****************************************************************************/
end_comment
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QFont
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|rawName
name|QString
name|QFont
operator|::
name|rawName
parameter_list|()
specifier|const
block|{
return|return
name|QLatin1String
argument_list|(
literal|"unknown"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setRawName
name|void
name|QFont
operator|::
name|setRawName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|defaultFamily
name|QString
name|QFont
operator|::
name|defaultFamily
parameter_list|()
specifier|const
block|{
name|QString
name|familyName
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|request
operator|.
name|styleHint
condition|)
block|{
case|case
name|QFont
operator|::
name|Times
case|:
name|familyName
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"times"
argument_list|)
expr_stmt|;
case|case
name|QFont
operator|::
name|Courier
case|:
case|case
name|QFont
operator|::
name|Monospace
case|:
name|familyName
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"monospace"
argument_list|)
expr_stmt|;
case|case
name|QFont
operator|::
name|Decorative
case|:
name|familyName
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"old english"
argument_list|)
expr_stmt|;
case|case
name|QFont
operator|::
name|Helvetica
case|:
case|case
name|QFont
operator|::
name|System
case|:
default|default:
name|familyName
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"helvetica"
argument_list|)
expr_stmt|;
block|}
name|QStringList
name|list
init|=
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
operator|->
name|fallbacksForFamily
argument_list|(
name|familyName
argument_list|,
name|QFont
operator|::
name|StyleNormal
argument_list|,
name|QFont
operator|::
name|StyleHint
argument_list|(
name|d
operator|->
name|request
operator|.
name|styleHint
argument_list|)
argument_list|,
name|QUnicodeTables
operator|::
name|Common
argument_list|)
decl_stmt|;
if|if
condition|(
name|list
operator|.
name|size
argument_list|()
condition|)
block|{
name|familyName
operator|=
name|list
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|familyName
return|;
block|}
end_function
begin_function
DECL|function|lastResortFamily
name|QString
name|QFont
operator|::
name|lastResortFamily
parameter_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"helvetica"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|lastResortFont
name|QString
name|QFont
operator|::
name|lastResortFont
parameter_list|()
specifier|const
block|{
name|qFatal
argument_list|(
literal|"QFont::lastResortFont: Cannot find any reasonable font"
argument_list|)
expr_stmt|;
comment|// Shut compiler up
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
