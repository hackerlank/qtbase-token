begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdecorationfactory_qws.h"
end_include
begin_include
include|#
directive|include
file|"qdecorationplugin_qws.h"
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
file|"qdecorationdefault_qws.h"
end_include
begin_include
include|#
directive|include
file|"qdecorationwindows_qws.h"
end_include
begin_include
include|#
directive|include
file|"qdecorationstyled_qws.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
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
name|QDecorationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/decorations"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
comment|/*!     \class QDecorationFactory     \ingroup qws     \ingroup appearance      \brief The QDecorationFactory class creates window decorations in     Qt for Embedded Linux.      Note that this class is only available in \l{Qt for Embedded Linux}.      QDecorationFactory is used to detect and instantiate the available     decorations, allowing \l{Qt for Embedded Linux} to load the preferred     decoration into the application at runtime. The create() function     returns a QDecoration object representing the decoration     identified by a given key. The valid keys (i.e. the supported     decorations) can be retrieved using the keys() function.      \l{Qt for Embedded Linux} provides three built-in decorations: \c Default,     \c Styled and \c Windows. In addition, custom decorations can be     added using Qt's \l {How to Create Qt Plugins}{plugin mechanism},     i.e. by subclassing the QDecoration class and creating a mouse     driver plugin (QDecorationPlugin).      \sa QDecoration, QDecorationPlugin */
comment|/*!     Creates the decoration specified by the given \a key. Note that     the keys are case-insensitive.      \sa keys() */
DECL|function|create
name|QDecoration
modifier|*
name|QDecorationFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
argument_list|{
name|QDecoration
operator|*
name|ret
operator|=
literal|0
argument_list|;
name|QString
name|decoration
operator|=
name|key
operator|.
name|toLower
argument_list|()
argument_list|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_DEFAULT
argument_list|if
operator|(
name|decoration
operator|==
name|QLatin1String
argument_list|(
literal|"default"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QDecorationDefault
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_WINDOWS
argument_list|if
operator|(
name|decoration
operator|==
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QDecorationWindows
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_STYLED
argument_list|if
operator|(
name|decoration
operator|==
name|QLatin1String
argument_list|(
literal|"styled"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QDecorationStyled
argument_list|;     else
endif|#
directive|endif
block|{ }
comment|// Keep these here - they make the #ifdefery above work
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
if|if
condition|(
operator|!
name|ret
condition|)
block|{
if|if
condition|(
name|QDecorationFactoryInterface
modifier|*
name|factory
type|=
name|qobject_cast
argument_list|<
name|QDecorationFactoryInterface
operator|*
argument_list|>
type|(
name|loader
type|(
condition|)->instance(decoration))
argument_list|)
argument_list|{
name|ret
operator|=
name|factory
operator|->
name|create
argument_list|(
name|decoration
argument_list|)
argument_list|;         }
end_decl_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|return
name|ret
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*!     Returns the list of valid keys, i.e., the available decorations.      \sa create() */
end_comment
begin_macro
unit|QStringList
DECL|function|keys
name|QDecorationFactory
end_macro
begin_expr_stmt
DECL|function|keys
operator|::
name|keys
operator|(
operator|)
block|{
name|QStringList
name|list
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_STYLED
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Styled"
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_DEFAULT
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Default"
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_DECORATION_WINDOWS
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_MAKEDLL
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QStringList
name|plugins
operator|=
name|loader
argument_list|()
operator|->
name|keys
argument_list|()
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|plugins
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|plugins
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
name|list
operator|+=
name|plugins
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_MAKEDLL
end_comment
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
