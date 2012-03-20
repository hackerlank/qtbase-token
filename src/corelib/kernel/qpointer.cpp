begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QPointer     \brief The QPointer class is a template class that provides guarded pointers to QObject.      \ingroup objectmodel      A guarded pointer, QPointer<T>, behaves like a normal C++     pointer \c{T *}, except that it is automatically set to 0 when the     referenced object is destroyed (unlike normal C++ pointers, which     become "dangling pointers" in such cases). \c T must be a     subclass of QObject.      Guarded pointers are useful whenever you need to store a pointer     to a QObject that is owned by someone else, and therefore might be     destroyed while you still hold a reference to it. You can safely     test the pointer for validity.      Note that Qt 5 introduces a slight change in behavior when using QPointer.      \list      \li When using QPointer on a QWidget (or a subclass of QWidget), previously     the QPointer would be cleared by the QWidget destructor. Now, the QPointer     is cleared by the QObject destructor (since this is when QWeakPointers are     cleared). Any QPointers tracking a widget will \b NOT be cleared before the     QWidget destructor destroys the children for the widget being tracked.      \endlist      Qt also provides QSharedPointer, an implementation of a reference-counted     shared pointer object, which can be used to maintain a collection of     references to an individual pointer.      Example:      \snippet pointer/pointer.cpp 0     \dots     \snippet pointer/pointer.cpp 1     \snippet pointer/pointer.cpp 2      If the QLabel is deleted in the meantime, the \c label variable     will hold 0 instead of an invalid address, and the last line will     never be executed.      The functions and operators available with a QPointer are the     same as those available with a normal unguarded pointer, except     the pointer arithmetic operators (\c{+}, \c{-}, \c{++}, and     \c{--}), which are normally used only with arrays of objects.      Use QPointers like normal pointers and you will not need to read     this class documentation.      For creating guarded pointers, you can construct or assign to them     from a T* or from another guarded pointer of the same type. You     can compare them with each other using operator==() and     operator!=(), or test for 0 with isNull(). You can dereference     them using either the \c *x or the \c x->member notation.      A guarded pointer will automatically cast to a \c T *, so you can     freely mix guarded and unguarded pointers. This means that if you     have a QPointer<QWidget>, you can pass it to a function that     requires a QWidget *. For this reason, it is of little value to     declare functions to take a QPointer as a parameter; just use     normal pointers. Use a QPointer when you are storing a pointer     over time.      Note that class \c T must inherit QObject, or a compilation or     link error will result.      \sa QSharedPointer, QObject, QObjectCleanupHandler */
end_comment
begin_comment
comment|/*!     \fn QPointer::QPointer()      Constructs a 0 guarded pointer.      \sa isNull() */
end_comment
begin_comment
comment|/*!     \fn QPointer::QPointer(T* p)      Constructs a guarded pointer that points to same object that \a p     points to. */
end_comment
begin_comment
comment|/*!     \fn QPointer::QPointer(const QPointer<T>&p)      Copies one guarded pointer from another. The constructed guarded     pointer points to the same object that \a p points to (which may     be 0). */
end_comment
begin_comment
comment|/*!     \fn QPointer::~QPointer()      Destroys the guarded pointer. Just like a normal pointer,     destroying a guarded pointer does \e not destroy the object being     pointed to. */
end_comment
begin_comment
comment|/*!     \fn QPointer<T>& QPointer::operator=(const QPointer<T>&p)      Assignment operator. This guarded pointer will now point to the     same object that \a p points to. */
end_comment
begin_comment
comment|/*!     \fn QPointer<T>& QPointer::operator=(T* p)      Assignment operator. This guarded pointer will now point to the     same object that \a p points to. */
end_comment
begin_comment
comment|/*!     \fn T* QPointer::data() const     \since 4.4      Returns the pointer to the object being guarded. */
end_comment
begin_comment
comment|/*!     \fn bool QPointer::isNull() const      Returns \c true if the referenced object has been destroyed or if     there is no referenced object; otherwise returns false. */
end_comment
begin_comment
comment|/*!     \fn T* QPointer::operator->() const      Overloaded arrow operator; implements pointer semantics. Just use     this operator as you would with a normal C++ pointer. */
end_comment
begin_comment
comment|/*!     \fn T& QPointer::operator*() const      Dereference operator; implements pointer semantics. Just use this     operator as you would with a normal C++ pointer. */
end_comment
begin_comment
comment|/*!     \fn QPointer::operator T*() const      Cast operator; implements pointer semantics. Because of this     function you can pass a QPointer\<T\> to a function where a T*     is required. */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const T *o, const QPointer<T>&p)     \relates QPointer      Equality operator. Returns true if \a o and the guarded     pointer \a p are pointing to the same object, otherwise     returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QPointer<T>&p, const T *o)     \relates QPointer      Equality operator. Returns true if \a o and the guarded     pointer \a p are pointing to the same object, otherwise     returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool operator==(T *o, const QPointer<T>&p)     \relates QPointer      Equality operator. Returns true if \a o and the guarded     pointer \a p are pointing to the same object, otherwise     returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QPointer<T>&p, T *o)     \relates QPointer      Equality operator. Returns true if \a o and the guarded     pointer \a p are pointing to the same object, otherwise     returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QPointer<T>&p1, const QPointer<T>&p2)     \relates QPointer      Equality operator. Returns true if the guarded pointers \a p1 and \a p2     are pointing to the same object, otherwise     returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const T *o, const QPointer<T>&p)     \relates QPointer      Inequality operator. Returns true if \a o and the guarded     pointer \a p are not pointing to the same object, otherwise     returns false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QPointer<T>&p, const T *o)     \relates QPointer      Inequality operator. Returns true if \a o and the guarded     pointer \a p are not pointing to the same object, otherwise     returns false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(T *o, const QPointer<T>&p)     \relates QPointer      Inequality operator. Returns true if \a o and the guarded     pointer \a p are not pointing to the same object, otherwise     returns false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QPointer<T>&p, T *o)     \relates QPointer      Inequality operator. Returns true if \a o and the guarded     pointer \a p are not pointing to the same object, otherwise     returns false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QPointer<T>&p1, const QPointer<T>&p2)     \relates QPointer      Inequality operator. Returns true if  the guarded pointers \a p1 and     \a p2 are not pointing to the same object, otherwise     returns false. */
end_comment
end_unit
