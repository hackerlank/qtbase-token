begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_H
end_ifndef
begin_define
DECL|macro|QTEST_H
define|#
directive|define
name|QTEST_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestdata.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qbenchmark.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qurl.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QTest
block|{
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QString&str
argument_list|)
block|{
return|return
name|QTest
operator|::
name|toPrettyUnicode
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|ushort
operator|*
operator|>
operator|(
name|str
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|str
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QLatin1String&str
argument_list|)
block|{
return|return
name|toString
argument_list|(
name|QString
argument_list|(
name|str
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QByteArray&ba
argument_list|)
block|{
return|return
name|QTest
operator|::
name|toHexRepresentation
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
name|ba
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QTime&time
argument_list|)
block|{
return|return
name|time
operator|.
name|isValid
argument_list|()
operator|?
name|qstrdup
argument_list|(
name|qPrintable
argument_list|(
name|time
operator|.
name|toString
argument_list|(
name|QLatin1String
argument_list|(
literal|"hh:mm:ss.zzz"
argument_list|)
argument_list|)
argument_list|)
argument_list|)
operator|:
name|qstrdup
argument_list|(
literal|"Invalid QTime"
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QDate&date
argument_list|)
block|{
return|return
name|date
operator|.
name|isValid
argument_list|()
operator|?
name|qstrdup
argument_list|(
name|qPrintable
argument_list|(
name|date
operator|.
name|toString
argument_list|(
name|QLatin1String
argument_list|(
literal|"yyyy/MM/dd"
argument_list|)
argument_list|)
argument_list|)
argument_list|)
operator|:
name|qstrdup
argument_list|(
literal|"Invalid QDate"
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QDateTime&dateTime
argument_list|)
block|{
return|return
name|dateTime
operator|.
name|isValid
argument_list|()
operator|?
name|qstrdup
argument_list|(
name|qPrintable
argument_list|(
name|dateTime
operator|.
name|toString
argument_list|(
name|QLatin1String
argument_list|(
literal|"yyyy/MM/dd hh:mm:ss.zzz"
argument_list|)
argument_list|)
operator|+
operator|(
name|dateTime
operator|.
name|timeSpec
argument_list|()
operator|==
name|Qt
operator|::
name|LocalTime
operator|?
name|QLatin1String
argument_list|(
literal|"[local time]"
argument_list|)
operator|:
name|QLatin1String
argument_list|(
literal|"[UTC]"
argument_list|)
operator|)
argument_list|)
argument_list|)
operator|:
name|qstrdup
argument_list|(
literal|"Invalid QDateTime"
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// QT_NO_DATESTRING
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QChar&c
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QChar: '%1' (0x%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|c
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|c
operator|.
name|unicode
argument_list|()
operator|)
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QPoint&p
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QPoint(%1,%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QSize&s
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QSize(%1x%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QRect&s
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QRect(%1,%2 %5x%6) (bottomright %3,%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|left
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|top
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|right
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|bottom
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QPointF&p
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QPointF(%1,%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QSizeF&s
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QSizeF(%1x%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QRectF&s
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QRectF(%1,%2 %5x%6) (bottomright %3,%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|left
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|top
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|right
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|bottom
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|s
operator|.
name|height
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QUrl&uri
argument_list|)
block|{
if|if
condition|(
operator|!
name|uri
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|qstrdup
argument_list|(
name|qPrintable
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Invalid URL: "
argument_list|)
operator|+
name|uri
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
return|;
return|return
name|qstrdup
argument_list|(
name|uri
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QVariant&v
argument_list|)
block|{
name|QByteArray
name|vstring
argument_list|(
literal|"QVariant("
argument_list|)
block|;
if|if
condition|(
name|v
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QByteArray
name|type
argument_list|(
name|v
operator|.
name|typeName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|type
operator|=
name|QByteArray
operator|::
name|number
argument_list|(
name|v
operator|.
name|userType
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|vstring
operator|.
name|append
argument_list|(
name|type
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|v
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|vstring
operator|.
name|append
argument_list|(
literal|','
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
operator|.
name|canConvert
argument_list|(
name|QVariant
operator|::
name|String
argument_list|)
condition|)
block|{
name|vstring
operator|.
name|append
argument_list|(
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|v
operator|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|vstring
operator|.
name|append
argument_list|(
literal|"<value not representable as string>"
argument_list|)
expr_stmt|;
block|}
block|}
end_if
begin_expr_stmt
unit|}     vstring
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|qstrdup
argument_list|(
name|vstring
operator|.
name|constData
argument_list|()
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QString const&t1
argument_list|,
argument|QLatin1String const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|t1
argument_list|,
name|QString
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QLatin1String const&t1
argument_list|,
argument|QString const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|QString
argument_list|(
name|t1
argument_list|)
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QList<T> const&t1
argument_list|,
argument|QList<T> const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
name|char
name|msg
index|[
literal|1024
index|]
block|;
name|msg
index|[
literal|0
index|]
operator|=
literal|'\0'
block|;
name|bool
name|isOk
operator|=
name|true
block|;
specifier|const
name|int
name|actualSize
operator|=
name|t1
operator|.
name|count
argument_list|()
block|;
specifier|const
name|int
name|expectedSize
operator|=
name|t2
operator|.
name|count
argument_list|()
block|;
if|if
condition|(
name|actualSize
operator|!=
name|expectedSize
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|,
literal|"Compared lists have different sizes.\n"
literal|"   Actual   (%s) size: %d\n"
literal|"   Expected (%s) size: %d"
argument_list|,
name|actual
argument_list|,
name|actualSize
argument_list|,
name|expected
argument_list|,
name|expectedSize
argument_list|)
expr_stmt|;
name|isOk
operator|=
name|false
expr_stmt|;
block|}
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|isOk
operator|&&
name|i
operator|<
name|actualSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|t1
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|t2
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|)
condition|)
block|{
name|char
modifier|*
name|val1
init|=
name|toString
argument_list|(
name|t1
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|char
modifier|*
name|val2
init|=
name|toString
argument_list|(
name|t2
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|qsnprintf
argument_list|(
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|,
literal|"Compared lists differ at index %d.\n"
literal|"   Actual   (%s): %s\n"
literal|"   Expected (%s): %s"
argument_list|,
name|i
argument_list|,
name|actual
argument_list|,
name|val1
condition|?
name|val1
else|:
literal|"<null>"
argument_list|,
name|expected
argument_list|,
name|val2
condition|?
name|val2
else|:
literal|"<null>"
argument_list|)
expr_stmt|;
name|isOk
operator|=
name|false
expr_stmt|;
name|delete
index|[]
name|val1
decl_stmt|;
name|delete
index|[]
name|val2
decl_stmt|;
block|}
block|}
end_for
begin_return
return|return
name|compare_helper
argument_list|(
name|isOk
argument_list|,
name|msg
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QStringList const&t1
argument_list|,
argument|QStringList const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
operator|<
name|QString
operator|>
operator|(
name|t1
operator|,
name|t2
operator|,
name|actual
operator|,
name|expected
operator|,
name|file
operator|,
name|line
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QFlags<T> const&t1
argument_list|,
argument|T const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|int
argument_list|(
name|t1
argument_list|)
argument_list|,
name|int
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|QFlags<T> const&t1
argument_list|,
argument|int const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|int
argument_list|(
name|t1
argument_list|)
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|qint64 const&t1
argument_list|,
argument|qint32 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|t1
argument_list|,
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|qint64 const&t1
argument_list|,
argument|quint32 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|t1
argument_list|,
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|quint64 const&t1
argument_list|,
argument|quint32 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|t1
argument_list|,
name|static_cast
operator|<
name|quint64
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|qint32 const&t1
argument_list|,
argument|qint64 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|quint32 const&t1
argument_list|,
argument|qint64 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|quint32 const&t1
argument_list|,
argument|quint64 const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|static_cast
operator|<
name|quint64
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|QTEST_APPLESS_MAIN
unit|} QT_END_NAMESPACE
define|#
directive|define
name|QTEST_APPLESS_MAIN
parameter_list|(
name|TestObject
parameter_list|)
define|\
value|int main(int argc, char *argv[]) \ { \     TestObject tc; \     return QTest::qExec(&tc, argc, argv); \ }
end_define
begin_include
include|#
directive|include
file|<QtTest/qtestsystem.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_WIDGETS_LIB
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtTest/qtest_gui.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_define
DECL|macro|QTEST_DISABLE_KEYPAD_NAVIGATION
define|#
directive|define
name|QTEST_DISABLE_KEYPAD_NAVIGATION
value|QApplication::setNavigationMode(Qt::NavigationModeNone);
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|QTEST_DISABLE_KEYPAD_NAVIGATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QTEST_MAIN
define|#
directive|define
name|QTEST_MAIN
parameter_list|(
name|TestObject
parameter_list|)
define|\
value|int main(int argc, char *argv[]) \ { \     QApplication app(argc, argv); \     app.setAttribute(Qt::AA_Use96Dpi, true); \     QTEST_DISABLE_KEYPAD_NAVIGATION \     TestObject tc; \     return QTest::qExec(&tc, argc, argv); \ }
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|QT_GUI_LIB
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtTest/qtest_gui.h>
end_include
begin_define
define|#
directive|define
name|QTEST_MAIN
parameter_list|(
name|TestObject
parameter_list|)
define|\
value|int main(int argc, char *argv[]) \ { \     QGuiApplication app(argc, argv); \     app.setAttribute(Qt::AA_Use96Dpi, true); \     TestObject tc; \     return QTest::qExec(&tc, argc, argv); \ }
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|QTEST_MAIN
parameter_list|(
name|TestObject
parameter_list|)
define|\
value|int main(int argc, char *argv[]) \ { \     QCoreApplication app(argc, argv); \     app.setAttribute(Qt::AA_Use96Dpi, true); \     TestObject tc; \     return QTest::qExec(&tc, argc, argv); \ }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_GUI_LIB
end_comment
begin_define
DECL|macro|QTEST_GUILESS_MAIN
define|#
directive|define
name|QTEST_GUILESS_MAIN
parameter_list|(
name|TestObject
parameter_list|)
define|\
value|int main(int argc, char *argv[]) \ { \     QCoreApplication app(argc, argv); \     app.setAttribute(Qt::AA_Use96Dpi, true); \     TestObject tc; \     return QTest::qExec(&tc, argc, argv); \ }
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
