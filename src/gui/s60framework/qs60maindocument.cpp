begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Symbian application wrapper of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qs60mainappui.h"
end_include
begin_include
include|#
directive|include
file|"qs60maindocument.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_symbian_p.h"
end_include
begin_include
include|#
directive|include
file|<exception>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QS60MainDocument   \since 4.6   \brief The QS60MainDocument class is a helper class for S60 migration.    \warning This class is provided only to get access to S60 specific   functionality in the application framework classes. It is not   portable. We strongly recommend against using it in new applications.    The QS60MainDocument provides a helper class for use in migrating   from existing S60 based applications to Qt based applications. It is   used in the exact same way as the \c CEikDocument class from   Symbian, but internally provides extensions used by Qt.    When modifying old S60 applications that rely on implementing   functions in \c CEikDocument, the class should be modified to   inherit from this class instead of \c CEikDocument. Then the   application can choose to override only certain functions.    For more information on \c CEikDocument, please see the S60   documentation.    Unlike other Qt classes, QS60MainDocument behaves like an S60 class,   and can throw Symbian leaves.    \sa QS60MainApplication, QS60MainAppUi  */
end_comment
begin_comment
comment|/*!  * \brief Constructs an instance of QS60MainDocument.  *  * \a mainApplication should contain a pointer to a QS60MainApplication instance.  */
end_comment
begin_constructor
DECL|function|QS60MainDocument
name|QS60MainDocument
operator|::
name|QS60MainDocument
parameter_list|(
name|CEikApplication
modifier|&
name|mainApplication
parameter_list|)
member_init_list|:
name|QS60MainDocumentBase
argument_list|(
name|mainApplication
argument_list|)
block|{
comment|// No implementation required
block|}
end_constructor
begin_comment
comment|/*!  * \brief Destroys the QS60MainDocument.  */
end_comment
begin_destructor
DECL|function|~QS60MainDocument
name|QS60MainDocument
operator|::
name|~
name|QS60MainDocument
parameter_list|()
block|{
comment|// No implementation required
block|}
end_destructor
begin_comment
comment|/*!  * \brief Creates an instance of QS60MainAppUi.  *  * \sa QS60MainAppUi  */
end_comment
begin_function
DECL|function|CreateAppUiL
name|CEikAppUi
modifier|*
name|QS60MainDocument
operator|::
name|CreateAppUiL
parameter_list|()
block|{
comment|// Create the application user interface, and return a pointer to it;
comment|// the framework takes ownership of this object
return|return
operator|(
cast|static_cast
argument_list|<
name|CEikAppUi
operator|*
argument_list|>
argument_list|(
operator|new
operator|(
name|ELeave
operator|)
name|QS60MainAppUi
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|OpenFileL
name|CFileStore
modifier|*
name|QS60MainDocument
operator|::
name|OpenFileL
parameter_list|(
name|TBool
comment|/*aDoOpen*/
parameter_list|,
specifier|const
name|TDesC
modifier|&
name|aFilename
parameter_list|,
name|RFs
modifier|&
comment|/*aFs*/
parameter_list|)
block|{
name|QT_TRYCATCH_LEAVING
argument_list|(
argument|{         QCoreApplication* app = QCoreApplication::instance();         QString qname = qt_TDesC2QString(aFilename);         QFileOpenEvent* event = new QFileOpenEvent(qname);         app->postEvent(app, event);     }
argument_list|)
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   \internal  */
end_comment
begin_function
DECL|function|OpenFileL
name|void
name|QS60MainDocument
operator|::
name|OpenFileL
parameter_list|(
name|CFileStore
modifier|*
modifier|&
name|aFileStore
parameter_list|,
name|RFile
modifier|&
name|aFile
parameter_list|)
block|{
name|QT_TRYCATCH_LEAVING
argument_list|(
argument|{         QCoreApplication* app = QCoreApplication::instance();         QFileOpenEvent* event = new QFileOpenEvent(aFile);         app->postEvent(app, event);         aFileStore =
literal|0
argument|;     }
argument_list|)
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
