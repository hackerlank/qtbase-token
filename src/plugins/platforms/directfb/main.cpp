begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QPlatformIntegrationPlugin>
end_include
begin_include
include|#
directive|include
file|"qdirectfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfb_egl.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|DIRECTFB_GL_EGL
end_ifdef
begin_define
DECL|macro|QT_EGL_BACKEND_STRING
define|#
directive|define
name|QT_EGL_BACKEND_STRING
parameter_list|(
name|list
parameter_list|)
value|list<< "directfbegl";
end_define
begin_define
DECL|macro|QT_EGL_BACKEND_CREATE
define|#
directive|define
name|QT_EGL_BACKEND_CREATE
parameter_list|(
name|list
parameter_list|,
name|out
parameter_list|)
define|\
value|if (list.toLower() == "directfbegl") \         out = new QDirectFbIntegrationEGL;
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|QT_EGL_BACKEND_STRING
parameter_list|(
name|list
parameter_list|)
end_define
begin_define
define|#
directive|define
name|QT_EGL_BACKEND_CREATE
parameter_list|(
name|system
parameter_list|,
name|out
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QDirectFbIntegrationPlugin
class|class
name|QDirectFbIntegrationPlugin
super|:
specifier|public
name|QPlatformIntegrationPlugin
block|{
public|public:
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
name|QPlatformIntegration
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QStringList
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|keys
name|QStringList
name|QDirectFbIntegrationPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"directfb"
expr_stmt|;
name|QT_EGL_BACKEND_STRING
argument_list|(
name|list
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QDirectFbIntegrationPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|system
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
name|QDirectFbIntegration
modifier|*
name|integration
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|system
operator|.
name|toLower
argument_list|()
operator|==
literal|"directfb"
condition|)
name|integration
operator|=
operator|new
name|QDirectFbIntegration
expr_stmt|;
name|QT_EGL_BACKEND_CREATE
argument_list|(
argument|system
argument_list|,
argument|integration
argument_list|)
if|if
condition|(
operator|!
name|integration
condition|)
return|return
literal|0
return|;
name|integration
operator|->
name|initialize
argument_list|()
expr_stmt|;
return|return
name|integration
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|directfb
argument_list|,
argument|QDirectFbIntegrationPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
