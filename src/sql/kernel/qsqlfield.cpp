begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqlfield.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSqlFieldPrivate
class|class
name|QSqlFieldPrivate
block|{
public|public:
DECL|function|QSqlFieldPrivate
name|QSqlFieldPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|nm
argument_list|(
name|name
argument_list|)
member_init_list|,
name|ro
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|type
argument_list|(
name|type
argument_list|)
member_init_list|,
name|req
argument_list|(
name|QSqlField
operator|::
name|Unknown
argument_list|)
member_init_list|,
name|len
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|prec
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|tp
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|gen
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|autoval
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|function|QSqlFieldPrivate
name|QSqlFieldPrivate
parameter_list|(
specifier|const
name|QSqlFieldPrivate
modifier|&
name|other
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|nm
argument_list|(
name|other
operator|.
name|nm
argument_list|)
member_init_list|,
name|ro
argument_list|(
name|other
operator|.
name|ro
argument_list|)
member_init_list|,
name|type
argument_list|(
name|other
operator|.
name|type
argument_list|)
member_init_list|,
name|req
argument_list|(
name|other
operator|.
name|req
argument_list|)
member_init_list|,
name|len
argument_list|(
name|other
operator|.
name|len
argument_list|)
member_init_list|,
name|prec
argument_list|(
name|other
operator|.
name|prec
argument_list|)
member_init_list|,
name|def
argument_list|(
name|other
operator|.
name|def
argument_list|)
member_init_list|,
name|tp
argument_list|(
name|other
operator|.
name|tp
argument_list|)
member_init_list|,
name|gen
argument_list|(
name|other
operator|.
name|gen
argument_list|)
member_init_list|,
name|autoval
argument_list|(
name|other
operator|.
name|autoval
argument_list|)
block|{}
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QSqlFieldPrivate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|nm
operator|==
name|other
operator|.
name|nm
operator|&&
name|ro
operator|==
name|other
operator|.
name|ro
operator|&&
name|type
operator|==
name|other
operator|.
name|type
operator|&&
name|req
operator|==
name|other
operator|.
name|req
operator|&&
name|len
operator|==
name|other
operator|.
name|len
operator|&&
name|prec
operator|==
name|other
operator|.
name|prec
operator|&&
name|def
operator|==
name|other
operator|.
name|def
operator|&&
name|gen
operator|==
name|other
operator|.
name|gen
operator|&&
name|autoval
operator|==
name|other
operator|.
name|autoval
operator|)
return|;
block|}
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|nm
name|QString
name|nm
decl_stmt|;
name|uint
name|ro
range|:
literal|1
decl_stmt|;
DECL|member|type
name|QVariant
operator|::
name|Type
name|type
decl_stmt|;
DECL|member|req
name|QSqlField
operator|::
name|RequiredStatus
name|req
decl_stmt|;
DECL|member|len
name|int
name|len
decl_stmt|;
DECL|member|prec
name|int
name|prec
decl_stmt|;
DECL|member|def
name|QVariant
name|def
decl_stmt|;
DECL|member|tp
name|int
name|tp
decl_stmt|;
name|uint
name|gen
range|:
literal|1
decl_stmt|;
name|uint
name|autoval
range|:
literal|1
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QSqlField     \brief The QSqlField class manipulates the fields in SQL database tables     and views.      \ingroup database     \ingroup shared     \inmodule QtSql      QSqlField represents the characteristics of a single column in a     database table or view, such as the data type and column name. A     field also contains the value of the database column, which can be     viewed or changed.      Field data values are stored as QVariants. Using an incompatible     type is not permitted. For example:      \snippet doc/src/snippets/sqldatabase/sqldatabase.cpp 2      However, the field will attempt to cast certain data types to the     field data type where possible:      \snippet doc/src/snippets/sqldatabase/sqldatabase.cpp 3      QSqlField objects are rarely created explicitly in application     code. They are usually accessed indirectly through \l{QSqlRecord}s     that already contain a list of fields. For example:      \snippet doc/src/snippets/sqldatabase/sqldatabase.cpp 4     \dots     \snippet doc/src/snippets/sqldatabase/sqldatabase.cpp 5     \snippet doc/src/snippets/sqldatabase/sqldatabase.cpp 6      A QSqlField object can provide some meta-data about the field, for     example, its name(), variant type(), length(), precision(),     defaultValue(), typeID(), and its requiredStatus(),     isGenerated() and isReadOnly(). The field's data can be     checked to see if it isNull(), and its value() retrieved. When     editing the data can be set with setValue() or set to NULL with     clear().      \sa QSqlRecord */
end_comment
begin_comment
comment|/*!     \enum QSqlField::RequiredStatus      Specifies whether the field is required or optional.      \value Required  The field must be specified when inserting records.     \value Optional  The fields doesn't have to be specified when inserting records.     \value Unknown  The database driver couldn't determine whether the field is required or                     optional.      \sa requiredStatus() */
end_comment
begin_comment
comment|/*!     Constructs an empty field called \a fieldName of variant type \a     type.      \sa setRequiredStatus() setLength() setPrecision() setDefaultValue() setGenerated() setReadOnly() */
end_comment
begin_constructor
DECL|function|QSqlField
name|QSqlField
operator|::
name|QSqlField
parameter_list|(
specifier|const
name|QString
modifier|&
name|fieldName
parameter_list|,
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QSqlFieldPrivate
argument_list|(
name|fieldName
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|val
operator|=
name|QVariant
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a copy of \a other. */
end_comment
begin_constructor
DECL|function|QSqlField
name|QSqlField
operator|::
name|QSqlField
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
name|val
operator|=
name|other
operator|.
name|val
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Sets the field equal to \a other. */
end_comment
begin_function
DECL|function|operator =
name|QSqlField
modifier|&
name|QSqlField
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|other
parameter_list|)
block|{
name|qAtomicAssign
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
name|val
operator|=
name|other
operator|.
name|val
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QSqlField::operator!=(const QSqlField&other) const     Returns true if the field is unequal to \a other; otherwise returns     false. */
end_comment
begin_comment
comment|/*!     Returns true if the field is equal to \a other; otherwise returns     false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QSqlField
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
operator|(
name|d
operator|==
name|other
operator|.
name|d
operator|||
operator|*
name|d
operator|==
operator|*
name|other
operator|.
name|d
operator|)
operator|&&
name|val
operator|==
name|other
operator|.
name|val
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the object and frees any allocated resources. */
end_comment
begin_destructor
DECL|function|~QSqlField
name|QSqlField
operator|::
name|~
name|QSqlField
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Sets the required status of this field to \a required.      \sa requiredStatus() setType() setLength() setPrecision() setDefaultValue() setGenerated() setReadOnly() */
end_comment
begin_function
DECL|function|setRequiredStatus
name|void
name|QSqlField
operator|::
name|setRequiredStatus
parameter_list|(
name|RequiredStatus
name|required
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|req
operator|=
name|required
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn void QSqlField::setRequired(bool required)      Sets the required status of this field to \l Required if \a     required is true; otherwise sets it to \l Optional.      \sa setRequiredStatus(), requiredStatus() */
end_comment
begin_comment
comment|/*!     Sets the field's length to \a fieldLength. For strings this is the     maximum number of characters the string can hold; the meaning     varies for other types.      \sa length() setType() setRequiredStatus() setPrecision() setDefaultValue() setGenerated() setReadOnly() */
end_comment
begin_function
DECL|function|setLength
name|void
name|QSqlField
operator|::
name|setLength
parameter_list|(
name|int
name|fieldLength
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|len
operator|=
name|fieldLength
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the field's \a precision. This only affects numeric fields.      \sa precision() setType() setRequiredStatus() setLength() setDefaultValue() setGenerated() setReadOnly() */
end_comment
begin_function
DECL|function|setPrecision
name|void
name|QSqlField
operator|::
name|setPrecision
parameter_list|(
name|int
name|precision
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|prec
operator|=
name|precision
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the default value used for this field to \a value.      \sa defaultValue() value() setType() setRequiredStatus() setLength() setPrecision() setGenerated() setReadOnly() */
end_comment
begin_function
DECL|function|setDefaultValue
name|void
name|QSqlField
operator|::
name|setDefaultValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|def
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|setSqlType
name|void
name|QSqlField
operator|::
name|setSqlType
parameter_list|(
name|int
name|type
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|tp
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the generated state. If \a gen is false, no SQL will     be generated for this field; otherwise, Qt classes such as     QSqlQueryModel and QSqlTableModel will generate SQL for this     field.      \sa isGenerated() setType() setRequiredStatus() setLength() setPrecision() setDefaultValue() setReadOnly() */
end_comment
begin_function
DECL|function|setGenerated
name|void
name|QSqlField
operator|::
name|setGenerated
parameter_list|(
name|bool
name|gen
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|gen
operator|=
name|gen
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the value of the field to \a value. If the field is read-only     (isReadOnly() returns true), nothing happens.      If the data type of \a value differs from the field's current     data type, an attempt is made to cast it to the proper type. This     preserves the data type of the field in the case of assignment,     e.g. a QString to an integer data type.      To set the value to NULL, use clear().      \sa value() isReadOnly() defaultValue() */
end_comment
begin_function
DECL|function|setValue
name|void
name|QSqlField
operator|::
name|setValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|isReadOnly
argument_list|()
condition|)
return|return;
name|val
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Clears the value of the field and sets it to NULL.     If the field is read-only, nothing happens.      \sa setValue() isReadOnly() requiredStatus() */
end_comment
begin_function
DECL|function|clear
name|void
name|QSqlField
operator|::
name|clear
parameter_list|()
block|{
if|if
condition|(
name|isReadOnly
argument_list|()
condition|)
return|return;
name|val
operator|=
name|QVariant
argument_list|(
name|type
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the name of the field to \a name.      \sa name() */
end_comment
begin_function
DECL|function|setName
name|void
name|QSqlField
operator|::
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|nm
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the read only flag of the field's value to \a readOnly. A     read-only field cannot have its value set with setValue() and     cannot be cleared to NULL with clear(). */
end_comment
begin_function
DECL|function|setReadOnly
name|void
name|QSqlField
operator|::
name|setReadOnly
parameter_list|(
name|bool
name|readOnly
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|ro
operator|=
name|readOnly
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QVariant QSqlField::value() const      Returns the value of the field as a QVariant.      Use isNull() to check if the field's value is NULL. */
end_comment
begin_comment
comment|/*!     Returns the name of the field.      \sa setName() */
end_comment
begin_function
DECL|function|name
name|QString
name|QSqlField
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|nm
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the field's type as stored in the database.     Note that the actual value might have a different type,     Numerical values that are too large to store in a long     int or double are usually stored as strings to prevent     precision loss.      \sa setType() */
end_comment
begin_function
DECL|function|type
name|QVariant
operator|::
name|Type
name|QSqlField
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_comment
comment|/*!     Set's the field's variant type to \a type.      \sa type() setRequiredStatus() setLength() setPrecision() setDefaultValue() setGenerated() setReadOnly() */
end_comment
begin_function
DECL|function|setType
name|void
name|QSqlField
operator|::
name|setType
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|type
operator|=
name|type
expr_stmt|;
if|if
condition|(
operator|!
name|val
operator|.
name|isValid
argument_list|()
condition|)
name|val
operator|=
name|QVariant
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the field's value is read-only; otherwise returns     false.      \sa setReadOnly() type() requiredStatus() length() precision() defaultValue() isGenerated() */
end_comment
begin_function
DECL|function|isReadOnly
name|bool
name|QSqlField
operator|::
name|isReadOnly
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ro
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the field's value is NULL; otherwise returns     false.      \sa value() */
end_comment
begin_function
DECL|function|isNull
name|bool
name|QSqlField
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|val
operator|.
name|isNull
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QSqlField
operator|::
name|detach
parameter_list|()
block|{
name|qAtomicDetach
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if this is a required field; otherwise returns false.     An \c INSERT will fail if a required field does not have a value.      \sa setRequiredStatus() type() length() precision() defaultValue() isGenerated() */
end_comment
begin_function
DECL|function|requiredStatus
name|QSqlField
operator|::
name|RequiredStatus
name|QSqlField
operator|::
name|requiredStatus
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|req
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the field's length.      If the returned value is negative, it means that the information     is not available from the database.      \sa setLength() type() requiredStatus() precision() defaultValue() isGenerated() */
end_comment
begin_function
DECL|function|length
name|int
name|QSqlField
operator|::
name|length
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|len
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the field's precision; this is only meaningful for numeric     types.      If the returned value is negative, it means that the information     is not available from the database.      \sa setPrecision() type() requiredStatus() length() defaultValue() isGenerated() */
end_comment
begin_function
DECL|function|precision
name|int
name|QSqlField
operator|::
name|precision
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|prec
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the field's default value (which may be NULL).      \sa setDefaultValue() type() requiredStatus() length() precision() isGenerated() */
end_comment
begin_function
DECL|function|defaultValue
name|QVariant
name|QSqlField
operator|::
name|defaultValue
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|def
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the type ID for the field.      If the returned value is negative, it means that the information     is not available from the database. */
end_comment
begin_function
DECL|function|typeID
name|int
name|QSqlField
operator|::
name|typeID
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|tp
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the field is generated; otherwise returns     false.      \sa setGenerated() type() requiredStatus() length() precision() defaultValue() */
end_comment
begin_function
DECL|function|isGenerated
name|bool
name|QSqlField
operator|::
name|isGenerated
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|gen
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the field's variant type is valid; otherwise     returns false. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QSqlField
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|type
operator|!=
name|QVariant
operator|::
name|Invalid
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSqlField
modifier|&
name|f
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_BROKEN_DEBUG_STREAM
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSqlField("
operator|<<
name|f
operator|.
name|name
argument_list|()
operator|<<
literal|", "
operator|<<
name|QVariant
operator|::
name|typeToName
argument_list|(
name|f
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|.
name|length
argument_list|()
operator|>=
literal|0
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", length: "
operator|<<
name|f
operator|.
name|length
argument_list|()
expr_stmt|;
if|if
condition|(
name|f
operator|.
name|precision
argument_list|()
operator|>=
literal|0
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", precision: "
operator|<<
name|f
operator|.
name|precision
argument_list|()
expr_stmt|;
if|if
condition|(
name|f
operator|.
name|requiredStatus
argument_list|()
operator|!=
name|QSqlField
operator|::
name|Unknown
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", required: "
operator|<<
operator|(
name|f
operator|.
name|requiredStatus
argument_list|()
operator|==
name|QSqlField
operator|::
name|Required
condition|?
literal|"yes"
else|:
literal|"no"
operator|)
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", generated: "
operator|<<
operator|(
name|f
operator|.
name|isGenerated
argument_list|()
condition|?
literal|"yes"
else|:
literal|"no"
operator|)
expr_stmt|;
if|if
condition|(
name|f
operator|.
name|typeID
argument_list|()
operator|>=
literal|0
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", typeID: "
operator|<<
name|f
operator|.
name|typeID
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|defaultValue
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|", auto-value: \""
operator|<<
name|f
operator|.
name|defaultValue
argument_list|()
operator|<<
literal|'\"'
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
else|#
directive|else
name|qWarning
argument_list|(
literal|"This compiler doesn't support streaming QSqlField to QDebug"
argument_list|)
expr_stmt|;
return|return
name|dbg
return|;
name|Q_UNUSED
argument_list|(
name|f
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn void QSqlField::setNull()      Use clear() instead. */
end_comment
begin_comment
comment|/*!     Returns true if the value is auto-generated by the database,     for example auto-increment primary key values.      \sa setAutoValue() */
end_comment
begin_function
DECL|function|isAutoValue
name|bool
name|QSqlField
operator|::
name|isAutoValue
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|autoval
return|;
block|}
end_function
begin_comment
comment|/*!     Marks the field as an auto-generated value if \a autoVal     is true.      \sa isAutoValue()  */
end_comment
begin_function
DECL|function|setAutoValue
name|void
name|QSqlField
operator|::
name|setAutoValue
parameter_list|(
name|bool
name|autoVal
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|autoval
operator|=
name|autoVal
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
