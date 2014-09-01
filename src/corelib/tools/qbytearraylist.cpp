begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 by Southwest Research Institute (R) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qbytearraylist.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*! \typedef QByteArrayListIterator     \relates QByteArrayList      The QByteArrayListIterator type definition provides a Java-style const     iterator for QByteArrayList.      QByteArrayList provides both \l{Java-style iterators} and     \l{STL-style iterators}. The Java-style const iterator is simply     a type definition for QListIterator<QByteArray>.      \sa QMutableByteArrayListIterator, QByteArrayList::const_iterator */
comment|/*! \typedef QMutableByteArrayListIterator     \relates QByteArrayList      The QByteArrayListIterator type definition provides a Java-style     non-const iterator for QByteArrayList.      QByteArrayList provides both \l{Java-style iterators} and     \l{STL-style iterators}. The Java-style non-const iterator is     simply a type definition for QMutableListIterator<QByteArray>.      \sa QByteArrayListIterator, QByteArrayList::iterator */
comment|/*!     \class QByteArrayList     \inmodule QtCore     \since 5.4     \brief The QByteArrayList class provides a list of byte arrays.      \ingroup tools     \ingroup shared     \ingroup string-processing      \reentrant      QByteArrayList is actually just a QList<QByteArray>. It is documented as a     full class just for simplicity of documenting the member methods that exist     only in QList<QByteArray>.      All of QList's functionality also applies to QByteArrayList. For example, you     can use isEmpty() to test whether the list is empty, and you can call     functions like append(), prepend(), insert(), replace(), removeAll(),     removeAt(), removeFirst(), removeLast(), and removeOne() to modify a     QByteArrayList. In addition, QByteArrayList provides several join()     methods for concatenating the list into a single QByteArray.      The purpose of QByteArrayList is quite different from that of QStringList.     Whereas QStringList has many methods for manipulation of elements within     the list, QByteArrayList does not.     Normally, QStringList should be used whenever working with a list of printable     strings. QByteArrayList should be used to handle and efficiently join large blobs     of binary data, as when sequentially receiving serialized data through a     QIODevice.      \sa QByteArray, QStringList */
comment|/*!     \fn QByteArray QByteArrayList::join() const      Joins all the byte arrays into a single byte array. */
comment|/*!     \fn QByteArray QByteArrayList::join(const QByteArray&separator) const      Joins all the byte arrays into a single byte array with each     element separated by the given \a separator. */
comment|/*!     \fn QByteArray QByteArrayList::join(char separator) const      Joins all the byte arrays into a single byte array with each     element separated by the given \a separator. */
DECL|function|QByteArrayList_joinedSize
specifier|static
name|int
name|QByteArrayList_joinedSize
parameter_list|(
specifier|const
name|QByteArrayList
modifier|*
name|that
parameter_list|,
name|int
name|seplen
parameter_list|)
block|{
name|int
name|totalLength
init|=
literal|0
decl_stmt|;
specifier|const
name|int
name|size
init|=
name|that
operator|->
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
name|totalLength
operator|+=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|size
operator|>
literal|0
condition|)
name|totalLength
operator|+=
name|seplen
operator|*
operator|(
name|size
operator|-
literal|1
operator|)
expr_stmt|;
return|return
name|totalLength
return|;
block|}
end_function
begin_function
DECL|function|QByteArrayList_join
name|QByteArray
name|QtPrivate
operator|::
name|QByteArrayList_join
parameter_list|(
specifier|const
name|QByteArrayList
modifier|*
name|that
parameter_list|,
specifier|const
name|char
modifier|*
name|sep
parameter_list|,
name|int
name|seplen
parameter_list|)
block|{
name|QByteArray
name|res
decl_stmt|;
if|if
condition|(
specifier|const
name|int
name|joinedSize
init|=
name|QByteArrayList_joinedSize
argument_list|(
name|that
argument_list|,
name|seplen
argument_list|)
condition|)
name|res
operator|.
name|reserve
argument_list|(
name|joinedSize
argument_list|)
expr_stmt|;
comment|// don't call reserve(0) - it allocates one byte for the NUL
specifier|const
name|int
name|size
init|=
name|that
operator|->
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
condition|)
name|res
operator|.
name|append
argument_list|(
name|sep
argument_list|,
name|seplen
argument_list|)
expr_stmt|;
name|res
operator|+=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit