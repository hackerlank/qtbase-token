begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstylefactory.h"
end_include
begin_include
include|#
directive|include
file|"qstyleplugin.h"
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsstyle.h"
end_include
begin_include
include|#
directive|include
file|"qmotifstyle.h"
end_include
begin_include
include|#
directive|include
file|"qcdestyle.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_PLASTIQUE
end_ifndef
begin_include
include|#
directive|include
file|"qplastiquestyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CLEANLOOKS
end_ifndef
begin_include
include|#
directive|include
file|"qcleanlooksstyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
end_ifndef
begin_include
include|#
directive|include
file|"qgtkstyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsxpstyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsvistastyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
end_ifndef
begin_include
include|#
directive|include
file|"qwindowscestyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsmobilestyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_S60
end_ifndef
begin_include
include|#
directive|include
file|"qs60style.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"qmacstyle_mac.h"
name|QT_END_INCLUDE_NAMESPACE
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QStyleFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/styles"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
comment|/*!     \class QStyleFactory     \brief The QStyleFactory class creates QStyle objects.      \ingroup appearance      The QStyle class is an abstract base class that encapsulates the     look and feel of a GUI. QStyleFactory creates a QStyle object     using the create() function and a key identifying the style. The     styles are either built-in or dynamically loaded from a style     plugin (see QStylePlugin).      The valid keys can be retrieved using the keys()     function. Typically they include "windows", "motif", "cde",     "plastique" and "cleanlooks".  Depending on the platform,     "windowsxp", "windowsvista" and "macintosh" may be available.     Note that keys are case insensitive.      \sa QStyle */
comment|/*!     Creates and returns a QStyle object that matches the given \a key, or     returns 0 if no matching style is found.      Both built-in styles and styles from style plugins are queried for a     matching style.      \note The keys used are case insensitive.      \sa keys() */
DECL|function|create
name|QStyle
modifier|*
name|QStyleFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
argument_list|{
name|QStyle
operator|*
name|ret
operator|=
literal|0
argument_list|;
name|QString
name|style
operator|=
name|key
operator|.
name|toLower
argument_list|()
argument_list|;
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWS
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsce"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsCEStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsmobile"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsMobileStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsxp"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsXPStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsvista"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsVistaStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MOTIF
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"motif"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QMotifStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CDE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"cde"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QCDEStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_S60
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"s60"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QS60Style
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_PLASTIQUE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"plastique"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QPlastiqueStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CLEANLOOKS
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"cleanlooks"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QCleanlooksStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"gtk"
argument_list|)
operator|||
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"gtk+"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QGtkStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MAC
argument_list|if
operator|(
name|style
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"macintosh"
argument_list|)
argument_list|)
operator|)
block|{
name|ret
operator|=
operator|new
name|QMacStyle
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
if|if
condition|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"macintosh"
argument_list|)
condition|)
name|style
operator|+=
name|QLatin1String
argument_list|(
literal|" (aqua)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
endif|#
directive|endif
block|{ }
comment|// Keep these here - they make the #ifdefery above work
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
if|if
condition|(
operator|!
name|ret
condition|)
block|{
if|if
condition|(
name|QStyleFactoryInterface
modifier|*
name|factory
type|=
name|qobject_cast
argument_list|<
name|QStyleFactoryInterface
operator|*
argument_list|>
type|(
name|loader
type|(
condition|)->instance(style))
argument_list|)
name|ret
init|=
name|factory
operator|->
name|create
argument_list|(
name|style
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|if
operator|(
name|ret
operator|)
name|ret
operator|->
name|setObjectName
argument_list|(
name|style
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|ret
return|;
end_return
begin_comment
unit|}
comment|/*!     Returns the list of valid keys, i.e. the keys this factory can     create styles for.      \sa create() */
end_comment
begin_macro
unit|QStringList
DECL|function|keys
name|QStyleFactory
end_macro
begin_expr_stmt
DECL|function|keys
operator|::
name|keys
operator|(
operator|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
name|QStringList
name|list
operator|=
name|loader
argument_list|()
operator|->
name|keys
argument_list|()
block|;
else|#
directive|else
name|QStringList
name|list
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWS
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsCE"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsCE"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsMobile"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsMobile"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsXP"
argument_list|)
argument_list|)
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_XP
operator|&&
name|QSysInfo
operator|::
name|WindowsVersion
operator|<
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsXP"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsVista"
argument_list|)
argument_list|)
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_VISTA
operator|&&
name|QSysInfo
operator|::
name|WindowsVersion
operator|<
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsVista"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MOTIF
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Motif"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Motif"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CDE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"CDE"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"CDE"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_S60
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"S60"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"S60"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_PLASTIQUE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Plastique"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Plastique"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"GTK+"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"GTK+"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_CLEANLOOKS
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Cleanlooks"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Cleanlooks"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MAC
end_ifndef
begin_decl_stmt
name|QString
name|mstyle
init|=
name|QLatin1String
argument_list|(
literal|"Macintosh"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_expr_stmt
name|mstyle
operator|+=
name|QLatin1String
argument_list|(
literal|" (aqua)"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|mstyle
argument_list|)
condition|)
name|list
operator|<<
name|mstyle
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
