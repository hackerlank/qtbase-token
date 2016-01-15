begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdesktopservices.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DESKTOPSERVICES
end_ifndef
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qstandardpaths.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformservices.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QOpenUrlHandlerRegistry
class|class
name|QOpenUrlHandlerRegistry
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|QOpenUrlHandlerRegistry
specifier|inline
name|QOpenUrlHandlerRegistry
parameter_list|()
member_init_list|:
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
block|{}
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
DECL|struct|Handler
struct|struct
name|Handler
block|{
DECL|member|receiver
name|QObject
modifier|*
name|receiver
decl_stmt|;
DECL|member|name
name|QByteArray
name|name
decl_stmt|;
block|}
struct|;
DECL|typedef|HandlerHash
typedef|typedef
name|QHash
argument_list|<
name|QString
argument_list|,
name|Handler
argument_list|>
name|HandlerHash
typedef|;
DECL|member|handlers
name|HandlerHash
name|handlers
decl_stmt|;
public|public
name|Q_SLOTS
public|:
name|void
name|handlerDestroyed
parameter_list|(
name|QObject
modifier|*
name|handler
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QOpenUrlHandlerRegistry
argument_list|,
argument|handlerRegistry
argument_list|)
end_macro
begin_function
DECL|function|handlerDestroyed
name|void
name|QOpenUrlHandlerRegistry
operator|::
name|handlerDestroyed
parameter_list|(
name|QObject
modifier|*
name|handler
parameter_list|)
block|{
name|HandlerHash
operator|::
name|Iterator
name|it
init|=
name|handlers
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|handlers
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|receiver
operator|==
name|handler
condition|)
block|{
name|it
operator|=
name|handlers
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|it
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \class QDesktopServices     \brief The QDesktopServices class provides methods for accessing common desktop services.     \since 4.2     \ingroup desktop     \inmodule QtGui      Many desktop environments provide services that can be used by applications to     perform common tasks, such as opening a web page, in a way that is both consistent     and takes into account the user's application preferences.      This class contains functions that provide simple interfaces to these services     that indicate whether they succeeded or failed.      The openUrl() function is used to open files located at arbitrary URLs in external     applications. For URLs that correspond to resources on the local filing system     (where the URL scheme is "file"), a suitable application will be used to open the     file; otherwise, a web browser will be used to fetch and display the file.      The user's desktop settings control whether certain executable file types are     opened for browsing, or if they are executed instead. Some desktop environments     are configured to prevent users from executing files obtained from non-local URLs,     or to ask the user's permission before doing so.      \section1 URL Handlers      The behavior of the openUrl() function can be customized for individual URL     schemes to allow applications to override the default handling behavior for     certain types of URLs.      The dispatch mechanism allows only one custom handler to be used for each URL     scheme; this is set using the setUrlHandler() function. Each handler is     implemented as a slot which accepts only a single QUrl argument.      The existing handlers for each scheme can be removed with the     unsetUrlHandler() function. This returns the handling behavior for the given     scheme to the default behavior.      This system makes it easy to implement a help system, for example. Help could be     provided in labels and text browsers using \uicontrol{help://myapplication/mytopic}     URLs, and by registering a handler it becomes possible to display the help text     inside the application:      \snippet code/src_gui_util_qdesktopservices.cpp 0      If inside the handler you decide that you can't open the requested     URL, you can just call QDesktopServices::openUrl() again with the     same argument, and it will try to open the URL using the     appropriate mechanism for the user's desktop environment.      \note Since Qt 5, storageLocation() and displayName() are replaced by functionality     provided by the QStandardPaths class.      \sa QSystemTrayIcon, QProcess, QStandardPaths */
end_comment
begin_comment
comment|/*!     Opens the given \a url in the appropriate Web browser for the user's desktop     environment, and returns \c true if successful; otherwise returns \c false.      If the URL is a reference to a local file (i.e., the URL scheme is "file") then     it will be opened with a suitable application instead of a Web browser.      The following example opens a file on the Windows file system residing on a path     that contains spaces:      \snippet code/src_gui_util_qdesktopservices.cpp 2      If a \c mailto URL is specified, the user's e-mail client will be used to open a     composer window containing the options specified in the URL, similar to the way     \c mailto links are handled by a Web browser.      For example, the following URL contains a recipient (\c{user@foo.com}), a     subject (\c{Test}), and a message body (\c{Just a test}):      \snippet code/src_gui_util_qdesktopservices.cpp 1      \warning Although many e-mail clients can send attachments and are     Unicode-aware, the user may have configured their client without these features.     Also, certain e-mail clients (e.g., Lotus Notes) have problems with long URLs.      \warning A return value of \c true indicates that the application has successfully requested     the operating system to open the URL in an external application. The external application may     still fail to launch or fail to open the requested URL. This result will not be reported back     to the application.      \sa setUrlHandler() */
end_comment
begin_function
DECL|function|openUrl
name|bool
name|QDesktopServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QOpenUrlHandlerRegistry
modifier|*
name|registry
init|=
name|handlerRegistry
argument_list|()
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registry
operator|->
name|mutex
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|insideOpenUrlHandler
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|insideOpenUrlHandler
condition|)
block|{
name|QOpenUrlHandlerRegistry
operator|::
name|HandlerHash
operator|::
name|ConstIterator
name|handler
init|=
name|registry
operator|->
name|handlers
operator|.
name|constFind
argument_list|(
name|url
operator|.
name|scheme
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|handler
operator|!=
name|registry
operator|->
name|handlers
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|insideOpenUrlHandler
operator|=
literal|true
expr_stmt|;
name|bool
name|result
init|=
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|handler
operator|->
name|receiver
argument_list|,
name|handler
operator|->
name|name
operator|.
name|constData
argument_list|()
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QUrl
argument_list|,
name|url
argument_list|)
argument_list|)
decl_stmt|;
name|insideOpenUrlHandler
operator|=
literal|false
expr_stmt|;
return|return
name|result
return|;
comment|// ### support bool slot return type
block|}
block|}
if|if
condition|(
operator|!
name|url
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|QPlatformIntegration
modifier|*
name|platformIntegration
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformIntegration
condition|)
return|return
literal|false
return|;
name|QPlatformServices
modifier|*
name|platformServices
init|=
name|platformIntegration
operator|->
name|services
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformServices
condition|)
block|{
name|qWarning
argument_list|(
literal|"The platform plugin does not support services."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"file"
argument_list|)
condition|?
name|platformServices
operator|->
name|openDocument
argument_list|(
name|url
argument_list|)
else|:
name|platformServices
operator|->
name|openUrl
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the handler for the given \a scheme to be the handler \a method provided by     the \a receiver object.      This function provides a way to customize the behavior of openUrl(). If openUrl()     is called with a URL with the specified \a scheme then the given \a method on the     \a receiver object is called instead of QDesktopServices launching an external     application.      The provided method must be implemented as a slot that only accepts a single QUrl     argument.      If setUrlHandler() is used to set a new handler for a scheme which already     has a handler, the existing handler is simply replaced with the new one.     Since QDesktopServices does not take ownership of handlers, no objects are     deleted when a handler is replaced.      Note that the handler will always be called from within the same thread that     calls QDesktopServices::openUrl().      \sa openUrl(), unsetUrlHandler() */
end_comment
begin_function
DECL|function|setUrlHandler
name|void
name|QDesktopServices
operator|::
name|setUrlHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|method
parameter_list|)
block|{
name|QOpenUrlHandlerRegistry
modifier|*
name|registry
init|=
name|handlerRegistry
argument_list|()
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|registry
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|receiver
condition|)
block|{
name|registry
operator|->
name|handlers
operator|.
name|remove
argument_list|(
name|scheme
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenUrlHandlerRegistry
operator|::
name|Handler
name|h
decl_stmt|;
name|h
operator|.
name|receiver
operator|=
name|receiver
expr_stmt|;
name|h
operator|.
name|name
operator|=
name|method
expr_stmt|;
name|registry
operator|->
name|handlers
operator|.
name|insert
argument_list|(
name|scheme
operator|.
name|toLower
argument_list|()
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|receiver
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|registry
argument_list|,
name|SLOT
argument_list|(
name|handlerDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes a previously set URL handler for the specified \a scheme.      \sa setUrlHandler() */
end_comment
begin_function
DECL|function|unsetUrlHandler
name|void
name|QDesktopServices
operator|::
name|unsetUrlHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|)
block|{
name|setUrlHandler
argument_list|(
name|scheme
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \enum QDesktopServices::StandardLocation     \since 4.4     \obsolete     Use QStandardPaths::StandardLocation (see storageLocation() for porting notes)      This enum describes the different locations that can be queried by     QDesktopServices::storageLocation and QDesktopServices::displayName.      \value DesktopLocation Returns the user's desktop directory.     \value DocumentsLocation Returns the user's document.     \value FontsLocation Returns the user's fonts.     \value ApplicationsLocation Returns the user's applications.     \value MusicLocation Returns the users music.     \value MoviesLocation Returns the user's movies.     \value PicturesLocation Returns the user's pictures.     \value TempLocation Returns the system's temporary directory.     \value HomeLocation Returns the user's home directory.     \value DataLocation Returns a directory location where persistent            application data can be stored. QCoreApplication::applicationName            and QCoreApplication::organizationName should work on all            platforms.     \value CacheLocation Returns a directory location where user-specific            non-essential (cached) data should be written.      \sa storageLocation(), displayName() */
end_comment
begin_comment
comment|/*!     \fn QString QDesktopServices::storageLocation(StandardLocation type)     \obsolete     Use QStandardPaths::writableLocation()      \note when porting QDesktopServices::DataLocation to QStandardPaths::DataLocation,     a different path will be returned.      \c{QDesktopServices::DataLocation} was \c{GenericDataLocation + "/data/organization/application"},     while QStandardPaths::DataLocation is \c{GenericDataLocation + "/organization/application"}.      Also note that \c{application} could be empty in Qt 4, if QCoreApplication::setApplicationName()     wasn't called, while in Qt 5 it defaults to the name of the executable.      Therefore, if you still need to access the Qt 4 path (for example for data migration to Qt 5), replace     \code     QDesktopServices::storageLocation(QDesktopServices::DataLocation)     \endcode     with     \code     QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) +     "/data/organization/application"     \endcode     (assuming an organization name and an application name were set). */
end_comment
begin_comment
comment|/*!     \fn QString QDesktopServices::displayName(StandardLocation type)     \obsolete     Use QStandardPaths::displayName() */
end_comment
begin_function_decl
specifier|extern
name|Q_CORE_EXPORT
name|QString
name|qt_applicationName_noFallback
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|storageLocationImpl
name|QString
name|QDesktopServices
operator|::
name|storageLocationImpl
parameter_list|(
name|QStandardPaths
operator|::
name|StandardLocation
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|QStandardPaths
operator|::
name|AppLocalDataLocation
condition|)
block|{
comment|// Preserve Qt 4 compatibility:
comment|// * QCoreApplication::applicationName() must default to empty
comment|// * Unix data location is under the "data/" subdirectory
specifier|const
name|QString
name|compatAppName
init|=
name|qt_applicationName_noFallback
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|baseDir
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|QString
name|result
init|=
name|baseDir
decl_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|compatAppName
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|compatAppName
expr_stmt|;
return|return
name|result
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
return|return
name|baseDir
operator|+
name|QLatin1String
argument_list|(
literal|"/data/"
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|compatAppName
return|;
endif|#
directive|endif
block|}
return|return
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qdesktopservices.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DESKTOPSERVICES
end_comment
end_unit
