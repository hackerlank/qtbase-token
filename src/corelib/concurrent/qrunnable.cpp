begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QRunnable     \since 4.4     \brief The QRunnable class is the base class for all runnable objects.      \ingroup thread      The QRunnable class is an interface for representing a task or     piece of code that needs to be executed, represented by your     reimplementation of the run() function.      You can use QThreadPool to execute your code in a separate     thread. QThreadPool deletes the QRunnable automatically if     autoDelete() returns true (the default). Use setAutoDelete() to     change the auto-deletion flag.      QThreadPool supports executing the same QRunnable more than once     by calling QThreadPool::tryStart(this) from within the run() function.      If autoDelete is enabled the QRunnable will be deleted when     the last thread exits the run function. Calling QThreadPool::start()     multiple times with the same QRunnable when autoDelete is enabled     creates a race condition and is not recommended.      \sa QThreadPool */
end_comment
begin_comment
comment|/*! \fn QRunnable::run()     Implement this pure virtual function in your subclass. */
end_comment
begin_comment
comment|/*! \fn QRunnable::QRunnable()     Constructs a QRunnable. Auto-deletion is enabled by default.      \sa autoDelete(), setAutoDelete() */
end_comment
begin_comment
comment|/*! \fn QRunnable::~QRunnable()     QRunnable virtual destructor. */
end_comment
begin_comment
comment|/*! \fn bool QRunnable::autoDelete() const      Returns true is auto-deletion is enabled; false otherwise.      If auto-deletion is enabled, QThreadPool will automatically delete     this runnable after calling run(); otherwise, ownership remains     with the application programmer.      \sa setAutoDelete(), QThreadPool */
end_comment
begin_comment
comment|/*! \fn bool QRunnable::setAutoDelete(bool autoDelete)      Enables auto-deletion if \a autoDelete is true; otherwise     auto-deletion is disabled.      If auto-deletion is enabled, QThreadPool will automatically delete     this runnable after calling run(); otherwise, ownership remains     with the application programmer.      Note that this flag must be set before calling     QThreadPool::start(). Calling this function after     QThreadPool::start() results in undefined behavior.      \sa autoDelete(), QThreadPool */
end_comment
end_unit
