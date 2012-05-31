begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|initialize
name|void
name|QFont
operator|::
name|initialize
parameter_list|()
block|{ }
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
name|QPlatformFontDatabase
modifier|*
name|fontDB
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
decl_stmt|;
specifier|const
name|QStringList
name|fallbacks
init|=
name|fontDB
operator|->
name|fallbacksForFamily
argument_list|(
name|QString
argument_list|()
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
operator|!
name|fallbacks
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|fallbacks
operator|.
name|first
argument_list|()
return|;
return|return
name|QString
argument_list|()
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
