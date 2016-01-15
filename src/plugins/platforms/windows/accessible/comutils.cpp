begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<ocidl.h>
end_include
begin_include
include|#
directive|include
file|<olectl.h>
end_include
begin_include
include|#
directive|include
file|"comutils.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QDateTimeToDATE
specifier|static
name|DATE
name|QDateTimeToDATE
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dt
operator|.
name|isValid
argument_list|()
operator|||
name|dt
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|949998
return|;
comment|// Special value for no date (01/01/4501)
name|SYSTEMTIME
name|stime
decl_stmt|;
name|memset
argument_list|(
operator|&
name|stime
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|stime
argument_list|)
argument_list|)
expr_stmt|;
name|QDate
name|date
init|=
name|dt
operator|.
name|date
argument_list|()
decl_stmt|;
name|QTime
name|time
init|=
name|dt
operator|.
name|time
argument_list|()
decl_stmt|;
if|if
condition|(
name|date
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
name|date
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|stime
operator|.
name|wDay
operator|=
name|date
operator|.
name|day
argument_list|()
expr_stmt|;
name|stime
operator|.
name|wMonth
operator|=
name|date
operator|.
name|month
argument_list|()
expr_stmt|;
name|stime
operator|.
name|wYear
operator|=
name|date
operator|.
name|year
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|time
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
name|time
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|stime
operator|.
name|wMilliseconds
operator|=
name|time
operator|.
name|msec
argument_list|()
expr_stmt|;
name|stime
operator|.
name|wSecond
operator|=
name|time
operator|.
name|second
argument_list|()
expr_stmt|;
name|stime
operator|.
name|wMinute
operator|=
name|time
operator|.
name|minute
argument_list|()
expr_stmt|;
name|stime
operator|.
name|wHour
operator|=
name|time
operator|.
name|hour
argument_list|()
expr_stmt|;
block|}
name|double
name|vtime
decl_stmt|;
name|SystemTimeToVariantTime
argument_list|(
operator|&
name|stime
argument_list|,
operator|&
name|vtime
argument_list|)
expr_stmt|;
return|return
name|vtime
return|;
block|}
end_function
begin_function
DECL|function|QColorToOLEColor
specifier|inline
name|uint
name|QColorToOLEColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|col
parameter_list|)
block|{
return|return
name|qRgba
argument_list|(
name|col
operator|.
name|blue
argument_list|()
argument_list|,
name|col
operator|.
name|green
argument_list|()
argument_list|,
name|col
operator|.
name|red
argument_list|()
argument_list|,
literal|0x00
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|QVariant2VARIANT
name|bool
name|QVariant2VARIANT
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|var
parameter_list|,
name|VARIANT
modifier|&
name|arg
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|typeName
parameter_list|,
name|bool
name|out
parameter_list|)
block|{
name|QVariant
name|qvar
init|=
name|var
decl_stmt|;
comment|// "type" is the expected type, so coerce if necessary
name|QVariant
operator|::
name|Type
name|proptype
init|=
name|typeName
operator|.
name|isEmpty
argument_list|()
condition|?
name|QVariant
operator|::
name|Invalid
else|:
name|QVariant
operator|::
name|nameToType
argument_list|(
name|typeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|proptype
operator|==
name|QVariant
operator|::
name|UserType
operator|&&
operator|!
name|typeName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|typeName
operator|==
literal|"short"
operator|||
name|typeName
operator|==
literal|"char"
condition|)
name|proptype
operator|=
name|QVariant
operator|::
name|Int
expr_stmt|;
elseif|else
if|if
condition|(
name|typeName
operator|==
literal|"float"
condition|)
name|proptype
operator|=
name|QVariant
operator|::
name|Double
expr_stmt|;
block|}
if|if
condition|(
name|proptype
operator|!=
name|QVariant
operator|::
name|Invalid
operator|&&
name|proptype
operator|!=
name|QVariant
operator|::
name|UserType
operator|&&
name|proptype
operator|!=
name|qvar
operator|.
name|type
argument_list|()
condition|)
block|{
if|if
condition|(
name|qvar
operator|.
name|canConvert
argument_list|(
name|proptype
argument_list|)
condition|)
name|qvar
operator|.
name|convert
argument_list|(
name|proptype
argument_list|)
expr_stmt|;
else|else
name|qvar
operator|=
name|QVariant
argument_list|(
name|proptype
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_VARIANT
operator||
name|VT_BYREF
operator|)
operator|&&
name|arg
operator|.
name|pvarVal
condition|)
block|{
return|return
name|QVariant2VARIANT
argument_list|(
name|var
argument_list|,
operator|*
name|arg
operator|.
name|pvarVal
argument_list|,
name|typeName
argument_list|,
literal|false
argument_list|)
return|;
block|}
if|if
condition|(
name|out
operator|&&
name|proptype
operator|==
name|QVariant
operator|::
name|UserType
operator|&&
name|typeName
operator|==
literal|"QVariant"
condition|)
block|{
name|VARIANT
modifier|*
name|pVariant
init|=
operator|new
name|VARIANT
decl_stmt|;
name|QVariant2VARIANT
argument_list|(
name|var
argument_list|,
operator|*
name|pVariant
argument_list|,
name|QByteArray
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator|=
name|VT_VARIANT
operator||
name|VT_BYREF
expr_stmt|;
name|arg
operator|.
name|pvarVal
operator|=
name|pVariant
expr_stmt|;
return|return
literal|true
return|;
block|}
switch|switch
condition|(
operator|(
name|int
operator|)
name|qvar
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|String
case|:
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_BSTR
operator||
name|VT_BYREF
operator|)
condition|)
block|{
if|if
condition|(
operator|*
name|arg
operator|.
name|pbstrVal
condition|)
name|SysFreeString
argument_list|(
operator|*
name|arg
operator|.
name|pbstrVal
argument_list|)
expr_stmt|;
operator|*
name|arg
operator|.
name|pbstrVal
operator|=
name|QStringToBSTR
argument_list|(
name|qvar
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator|=
name|VT_BSTR
operator||
name|VT_BYREF
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_BSTR
expr_stmt|;
name|arg
operator|.
name|bstrVal
operator|=
name|QStringToBSTR
argument_list|(
name|qvar
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pbstrVal
operator|=
operator|new
name|BSTR
argument_list|(
name|arg
operator|.
name|bstrVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QVariant
operator|::
name|Int
case|:
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_I4
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|plVal
operator|=
name|qvar
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_I4
expr_stmt|;
name|arg
operator|.
name|lVal
operator|=
name|qvar
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
if|if
condition|(
name|typeName
operator|==
literal|"short"
condition|)
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_I2
expr_stmt|;
name|arg
operator|.
name|piVal
operator|=
operator|new
name|short
argument_list|(
name|arg
operator|.
name|lVal
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeName
operator|==
literal|"char"
condition|)
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_I1
expr_stmt|;
name|arg
operator|.
name|pcVal
operator|=
operator|new
name|char
argument_list|(
name|arg
operator|.
name|lVal
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|plVal
operator|=
operator|new
name|long
argument_list|(
name|arg
operator|.
name|lVal
argument_list|)
expr_stmt|;
block|}
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QVariant
operator|::
name|UInt
case|:
if|if
condition|(
name|out
operator|&&
operator|(
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_UINT
operator||
name|VT_BYREF
operator|)
operator|||
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_I4
operator||
name|VT_BYREF
operator|)
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|puintVal
operator|=
name|qvar
operator|.
name|toUInt
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_UINT
expr_stmt|;
name|arg
operator|.
name|uintVal
operator|=
name|qvar
operator|.
name|toUInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|puintVal
operator|=
operator|new
name|uint
argument_list|(
name|arg
operator|.
name|uintVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QVariant
operator|::
name|LongLong
case|:
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_CY
operator||
name|VT_BYREF
operator|)
condition|)
block|{
name|arg
operator|.
name|pcyVal
operator|->
name|int64
operator|=
name|qvar
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
block|}
elseif|else
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_I8
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|pllVal
operator|=
name|qvar
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_I8
expr_stmt|;
name|arg
operator|.
name|llVal
operator|=
name|qvar
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pllVal
operator|=
operator|new
name|LONGLONG
argument_list|(
name|arg
operator|.
name|llVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
else|#
directive|else
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_CY
expr_stmt|;
name|arg
operator|.
name|cyVal
operator|.
name|int64
operator|=
name|qvar
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pcyVal
operator|=
operator|new
name|CY
argument_list|(
name|arg
operator|.
name|cyVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
endif|#
directive|endif
break|break;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_CY
operator||
name|VT_BYREF
operator|)
condition|)
block|{
name|arg
operator|.
name|pcyVal
operator|->
name|int64
operator|=
name|qvar
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
block|}
elseif|else
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_UI8
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|pullVal
operator|=
name|qvar
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_UI8
expr_stmt|;
name|arg
operator|.
name|ullVal
operator|=
name|qvar
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pullVal
operator|=
operator|new
name|ULONGLONG
argument_list|(
name|arg
operator|.
name|ullVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
else|#
directive|else
block|}
end_function
begin_else
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_CY
expr_stmt|;
name|arg
operator|.
name|cyVal
operator|.
name|int64
operator|=
name|qvar
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pcyVal
operator|=
operator|new
name|CY
argument_list|(
name|arg
operator|.
name|cyVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_else
begin_endif
endif|#
directive|endif
end_endif
begin_break
break|break;
end_break
begin_case
case|case
name|QVariant
operator|::
name|Bool
case|:
end_case
begin_if
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_BOOL
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|pboolVal
operator|=
name|qvar
operator|.
name|toBool
argument_list|()
condition|?
name|VARIANT_TRUE
else|:
name|VARIANT_FALSE
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_BOOL
expr_stmt|;
name|arg
operator|.
name|boolVal
operator|=
name|qvar
operator|.
name|toBool
argument_list|()
condition|?
name|VARIANT_TRUE
else|:
name|VARIANT_FALSE
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pboolVal
operator|=
operator|new
name|short
argument_list|(
name|arg
operator|.
name|boolVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_if
begin_break
break|break;
end_break
begin_case
case|case
name|QVariant
operator|::
name|Double
case|:
end_case
begin_if
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_R8
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|pdblVal
operator|=
name|qvar
operator|.
name|toDouble
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_R8
expr_stmt|;
name|arg
operator|.
name|dblVal
operator|=
name|qvar
operator|.
name|toDouble
argument_list|()
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
if|if
condition|(
name|typeName
operator|==
literal|"float"
condition|)
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_R4
expr_stmt|;
name|arg
operator|.
name|pfltVal
operator|=
operator|new
name|float
argument_list|(
name|arg
operator|.
name|dblVal
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|pdblVal
operator|=
operator|new
name|double
argument_list|(
name|arg
operator|.
name|dblVal
argument_list|)
expr_stmt|;
block|}
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_if
begin_break
break|break;
end_break
begin_case
case|case
name|QVariant
operator|::
name|Color
case|:
end_case
begin_if
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_COLOR
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|plVal
operator|=
name|QColorToOLEColor
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|qvar
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_COLOR
expr_stmt|;
name|arg
operator|.
name|lVal
operator|=
name|QColorToOLEColor
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|qvar
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|plVal
operator|=
operator|new
name|long
argument_list|(
name|arg
operator|.
name|lVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_if
begin_break
break|break;
end_break
begin_case
case|case
name|QVariant
operator|::
name|Date
case|:
end_case
begin_case
case|case
name|QVariant
operator|::
name|Time
case|:
end_case
begin_case
case|case
name|QVariant
operator|::
name|DateTime
case|:
end_case
begin_if
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_DATE
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|pdate
operator|=
name|QDateTimeToDATE
argument_list|(
name|qvar
operator|.
name|toDateTime
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_DATE
expr_stmt|;
name|arg
operator|.
name|date
operator|=
name|QDateTimeToDATE
argument_list|(
name|qvar
operator|.
name|toDateTime
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|pdate
operator|=
operator|new
name|DATE
argument_list|(
name|arg
operator|.
name|date
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_if
begin_break
break|break;
end_break
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// not a value with min/max semantics
end_comment
begin_ifndef
unit|case QVariant::Font:         if (out&& arg.vt == (VT_DISPATCH|VT_BYREF)) {             if (*arg.ppdispVal)                 (*arg.ppdispVal)->Release();             *arg.ppdispVal = QFontToIFont(qvariant_cast<QFont>(qvar));         } else {             arg.vt = VT_DISPATCH;             arg.pdispVal = QFontToIFont(qvariant_cast<QFont>(qvar));             if (out) {                 arg.ppdispVal = new IDispatch*(arg.pdispVal);                 arg.vt |= VT_BYREF;             }         }         break;     case QVariant::Pixmap:         if (out&& arg.vt == (VT_DISPATCH|VT_BYREF)) {             if (*arg.ppdispVal)                 (*arg.ppdispVal)->Release();             *arg.ppdispVal = QPixmapToIPicture(qvariant_cast<QPixmap>(qvar));         } else {             arg.vt = VT_DISPATCH;             arg.pdispVal = QPixmapToIPicture(qvariant_cast<QPixmap>(qvar));             if (out) {                 arg.ppdispVal = new IDispatch*(arg.pdispVal);                 arg.vt |= VT_BYREF;             }         }         break;     case QVariant::Cursor:         {
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_endif
unit|int shape = qvariant_cast<QCursor>(qvar).shape();             if (out&& (arg.vt& VT_BYREF)) {                 switch (arg.vt& ~VT_BYREF) {                 case VT_I4:                     *arg.plVal = shape;                     break;                 case VT_I2:                     *arg.piVal = shape;                     break;                 case VT_UI4:                     *arg.pulVal = shape;                     break;                 case VT_UI2:                     *arg.puiVal = shape;                     break;                 case VT_INT:                     *arg.pintVal = shape;                     break;                 case VT_UINT:                     *arg.puintVal = shape;                     break;                 }             } else {                 arg.vt = VT_I4;                 arg.lVal = shape;                 if (out) {                     arg.plVal = new long(arg.lVal);                     arg.vt |= VT_BYREF;                 }             }
endif|#
directive|endif
end_endif
begin_comment
unit|}         break;      case QVariant::List:         {             const QList<QVariant> list = qvar.toList();             const int count = list.count();             VARTYPE vt = VT_VARIANT;             QVariant::Type listType = QVariant::LastType;
comment|// == QVariant
end_comment
begin_comment
unit|if (!typeName.isEmpty()&& typeName.startsWith("QList<")) {                 const QByteArray listTypeName = typeName.mid(6, typeName.length() - 7);
comment|// QList<int> -> int
end_comment
begin_if
unit|listType = QVariant::nameToType(listTypeName);             }              VARIANT variant;             void *pElement =&variant;             switch (listType) {             case QVariant::Int:                 vt = VT_I4;                 pElement =&variant.lVal;                 break;             case QVariant::Double:                 vt = VT_R8;                 pElement =&variant.dblVal;                 break;             case QVariant::DateTime:                 vt = VT_DATE;                 pElement =&variant.date;                 break;             case QVariant::Bool:                 vt = VT_BOOL;                 pElement =&variant.boolVal;                 break;             case QVariant::LongLong:
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
end_if
begin_else
unit|vt = VT_I8;                 pElement =&variant.llVal;
else|#
directive|else
end_else
begin_endif
unit|vt = VT_CY;                 pElement =&variant.cyVal;
endif|#
directive|endif
end_endif
begin_comment
unit|break;             default:                 break;             }             SAFEARRAY *array = 0;             bool is2D = false;
comment|// If the first element in the array is a list the whole list is
end_comment
begin_comment
comment|// treated as a 2D array. The column count is taken from the 1st element.
end_comment
begin_ifdef
unit|if (count) {                 QVariantList col = list.at(0).toList();                 int maxColumns = col.count();                 if (maxColumns) {                     is2D = true;                     SAFEARRAYBOUND rgsabound[2] = { {0} };                     rgsabound[0].cElements = count;                     rgsabound[1].cElements = maxColumns;                     array = SafeArrayCreate(VT_VARIANT, 2, rgsabound);                     LONG rgIndices[2];                     for (LONG i = 0; i< count; ++i) {                         rgIndices[0] = i;                         QVariantList columns = list.at(i).toList();                         int columnCount = qMin(maxColumns, columns.count());                         for (LONG j = 0;  j< columnCount; ++j) {                             QVariant elem = columns.at(j);                             VariantInit(&variant);                             QVariant2VARIANT(elem, variant, elem.typeName());                             rgIndices[1] = j;                             SafeArrayPutElement(array, rgIndices, pElement);                             clearVARIANT(&variant);                         }                     }                  }             }             if (!is2D) {                 array = SafeArrayCreateVector(vt, 0, count);                 for (LONG index = 0; index< count; ++index) {                     QVariant elem = list.at(index);                     if (listType != QVariant::LastType)                         elem.convert(listType);                     VariantInit(&variant);                     QVariant2VARIANT(elem, variant, elem.typeName());                     SafeArrayPutElement(array,&index, pElement);                     clearVARIANT(&variant);                 }             }             if (out&& arg.vt == (VT_ARRAY|vt|VT_BYREF)) {                 if (*arg.pparray)                     SafeArrayDestroy(*arg.pparray);                 *arg.pparray = array;             } else {                 arg.vt = VT_ARRAY|vt;                 arg.parray = array;                 if (out) {                     arg.pparray = new SAFEARRAY*(arg.parray);                     arg.vt |= VT_BYREF;                 }             }         }         break;      case QVariant::StringList:         {             const QStringList list = qvar.toStringList();             const int count = list.count();             SAFEARRAY *array = SafeArrayCreateVector(VT_BSTR, 0, count);             for (LONG index = 0; index< count; ++index) {                 QString elem = list.at(index);                 BSTR bstr = QStringToBSTR(elem);                 SafeArrayPutElement(array,&index, bstr);                 SysFreeString(bstr);             }              if (out&& arg.vt == (VT_ARRAY|VT_BSTR|VT_BYREF)) {                 if (*arg.pparray)                     SafeArrayDestroy(*arg.pparray);                 *arg.pparray = array;             } else {                 arg.vt = VT_ARRAY|VT_BSTR;                 arg.parray = array;                 if (out) {                     arg.pparray = new SAFEARRAY*(arg.parray);                     arg.vt |= VT_BYREF;                 }             }         }         break;      case QVariant::ByteArray:         {             const QByteArray bytes = qvar.toByteArray();             const uint count = bytes.count();             SAFEARRAY *array = SafeArrayCreateVector(VT_UI1, 0, count);             if (count) {                 const char *data = bytes.constData();                 char *dest;                 SafeArrayAccessData(array, (void **)&dest);                 memcpy(dest, data, count);                 SafeArrayUnaccessData(array);             }              if (out&& arg.vt == (VT_ARRAY|VT_UI1|VT_BYREF)) {                 if (*arg.pparray)                     SafeArrayDestroy(*arg.pparray);                 *arg.pparray = array;             } else {                 arg.vt = VT_ARRAY|VT_UI1;                 arg.parray = array;                 if (out) {                     arg.pparray = new SAFEARRAY*(arg.parray);                     arg.vt |= VT_BYREF;                 }             }         }         break;
ifdef|#
directive|ifdef
name|QAX_SERVER
end_ifdef
begin_endif
unit|case QVariant::Rect:     case QVariant::Size:     case QVariant::Point:         {             typedef HRESULT(WINAPI* PGetRecordInfoFromTypeInfo)(ITypeInfo *, IRecordInfo **);             static PGetRecordInfoFromTypeInfo pGetRecordInfoFromTypeInfo = 0;             static bool resolved = false;             if (!resolved) {                 QSystemLibrary oleaut32(QLatin1String("oleaut32"));                 pGetRecordInfoFromTypeInfo = (PGetRecordInfoFromTypeInfo)oleaut32.resolve("GetRecordInfoFromTypeInfo");                 resolved = true;             }             if (!pGetRecordInfoFromTypeInfo)                 break;              ITypeInfo *typeInfo = 0;             IRecordInfo *recordInfo = 0;             CLSID clsid = qvar.type() == QVariant::Rect ? CLSID_QRect                 :qvar.type() == QVariant::Size ? CLSID_QSize                 :CLSID_QPoint;             qAxTypeLibrary->GetTypeInfoOfGuid(clsid,&typeInfo);             if (!typeInfo)                 break;             pGetRecordInfoFromTypeInfo(typeInfo,&recordInfo);             typeInfo->Release();             if (!recordInfo)                 break;              void *record = 0;             switch (qvar.type()) {             case QVariant::Rect:                 {                     QRect qrect(qvar.toRect());                     recordInfo->RecordCreateCopy(&qrect,&record);                 }                 break;             case QVariant::Size:                 {                     QSize qsize(qvar.toSize());                     recordInfo->RecordCreateCopy(&qsize,&record);                 }                 break;             case QVariant::Point:                 {                     QPoint qpoint(qvar.toPoint());                     recordInfo->RecordCreateCopy(&qpoint,&record);                 }                 break;             }              arg.vt = VT_RECORD;             arg.pRecInfo = recordInfo,             arg.pvRecord = record;             if (out) {                 qWarning("QVariant2VARIANT: out-parameter not supported for records");                 return false;            }         }         break;
endif|#
directive|endif
end_endif
begin_comment
comment|// QAX_SERVER
end_comment
begin_ifdef
unit|case QVariant::UserType:         {             QByteArray subType = qvar.typeName();
ifdef|#
directive|ifdef
name|QAX_SERVER
end_ifdef
begin_endif
unit|if (subType.endsWith('*'))                 subType.truncate(subType.length() - 1);
endif|#
directive|endif
end_endif
begin_ifdef
unit|if (!qstrcmp(qvar.typeName(), "IDispatch*")) {                 arg.vt = VT_DISPATCH;                 arg.pdispVal = *(IDispatch**)qvar.data();                 if (arg.pdispVal)                     arg.pdispVal->AddRef();                 if (out) {                     qWarning("QVariant2VARIANT: out-parameter not supported for IDispatch");                     return false;                 }             } else if (!qstrcmp(qvar.typeName(), "IDispatch**")) {                 arg.vt = VT_DISPATCH;                 arg.ppdispVal = *(IDispatch***)qvar.data();                 if (out)                     arg.vt |= VT_BYREF;             } else if (!qstrcmp(qvar.typeName(), "IUnknown*")) {                 arg.vt = VT_UNKNOWN;                 arg.punkVal = *(IUnknown**)qvar.data();                 if (arg.punkVal)                     arg.punkVal->AddRef();                 if (out) {                     qWarning("QVariant2VARIANT: out-parameter not supported for IUnknown");                     return false;                 }
ifdef|#
directive|ifdef
name|QAX_SERVER
end_ifdef
begin_comment
unit|} else if (qAxFactory()->metaObject(QString::fromLatin1(subType.constData()))) {                 arg.vt = VT_DISPATCH;                 void *user = *(void**)qvar.constData();
comment|//                qVariantGet(qvar, user, qvar.typeName());
end_comment
begin_else
unit|if (!user) {                     arg.pdispVal = 0;                 } else {                     qAxFactory()->createObjectWrapper(static_cast<QObject*>(user),&arg.pdispVal);                 }                 if (out) {                     qWarning("QVariant2VARIANT: out-parameter not supported for subtype");                     return false;                 }
else|#
directive|else
end_else
begin_comment
unit|} else if (QMetaType::type(subType)) {                 QAxObject *object = *(QAxObject**)qvar.constData();
comment|//                qVariantGet(qvar, object, subType);
end_comment
begin_endif
unit|arg.vt = VT_DISPATCH;                 object->queryInterface(IID_IDispatch, (void**)&arg.pdispVal);                 if (out) {                     qWarning("QVariant2VARIANT: out-parameter not supported for subtype");                     return false;                 }
endif|#
directive|endif
end_endif
begin_endif
unit|} else {                 return false;             }         }         break;
endif|#
directive|endif
end_endif
begin_case
case|case
name|QVariant
operator|::
name|Invalid
case|:
end_case
begin_comment
comment|// default-parameters not set
end_comment
begin_if
if|if
condition|(
name|out
operator|&&
name|arg
operator|.
name|vt
operator|==
operator|(
name|VT_ERROR
operator||
name|VT_BYREF
operator|)
condition|)
block|{
operator|*
name|arg
operator|.
name|plVal
operator|=
name|DISP_E_PARAMNOTFOUND
expr_stmt|;
block|}
else|else
block|{
name|arg
operator|.
name|vt
operator|=
name|VT_ERROR
expr_stmt|;
name|arg
operator|.
name|lVal
operator|=
name|DISP_E_PARAMNOTFOUND
expr_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|arg
operator|.
name|plVal
operator|=
operator|new
name|long
argument_list|(
name|arg
operator|.
name|lVal
argument_list|)
expr_stmt|;
name|arg
operator|.
name|vt
operator||=
name|VT_BYREF
expr_stmt|;
block|}
block|}
end_if
begin_break
break|break;
end_break
begin_default
default|default:
end_default
begin_return
return|return
literal|false
return|;
end_return
begin_expr_stmt
unit|}      Q_ASSERT
operator|(
operator|!
name|out
operator|||
operator|(
name|arg
operator|.
name|vt
operator|&
name|VT_BYREF
operator|)
operator|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
literal|true
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
