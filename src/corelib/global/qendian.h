begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QENDIAN_H
end_ifndef
begin_define
DECL|macro|QENDIAN_H
define|#
directive|define
name|QENDIAN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_comment
comment|// include stdlib.h and hope that it defines __GLIBC__ for glibc-based systems
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef
begin_include
include|#
directive|include
file|<byteswap.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
comment|/*  * ENDIAN FUNCTIONS */
DECL|function|qbswap_helper
specifier|inline
name|void
name|qbswap_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|uchar
modifier|*
name|dest
parameter_list|,
name|int
name|size
parameter_list|)
block|{
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
name|dest
index|[
name|i
index|]
operator|=
name|src
index|[
name|size
operator|-
literal|1
operator|-
name|i
index|]
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * qbswap(const T src, const uchar *dest);  * Changes the byte order of \a src from big endian to little endian or vice versa  * and stores the result in \a dest.  * There is no alignment requirements for \a dest. */
end_comment
begin_expr_stmt
DECL|function|qbswap
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qbswap
argument_list|(
argument|const T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|qbswap_helper
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
operator|&
name|src
operator|)
argument_list|,
name|dest
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|; }
comment|// Used to implement a type-safe and alignment-safe copy operation
comment|// If you want to avoid the memcopy, you must write specializations for this function
DECL|function|qToUnaligned
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qToUnaligned
argument_list|(
argument|const T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|memcpy
argument_list|(
name|dest
argument_list|,
operator|&
name|src
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|; }
comment|/* T qFromLittleEndian(const uchar *src)  * This function will read a little-endian encoded value from \a src  * and return the value in host-endian encoding.  * There is no requirement that \a src must be aligned. */
if|#
directive|if
name|defined
name|Q_CC_SUN
DECL|function|qFromLittleEndian_helper
specifier|inline
name|quint64
name|qFromLittleEndian_helper
argument_list|(
argument|const uchar *src
argument_list|,
argument|quint64 *dest
argument_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000000100
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000010000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000001000000
argument_list|)
operator||
name|src
index|[
literal|4
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000100000000
argument_list|)
operator||
name|src
index|[
literal|5
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000010000000000
argument_list|)
operator||
name|src
index|[
literal|6
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0001000000000000
argument_list|)
operator||
name|src
index|[
literal|7
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0100000000000000
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qFromLittleEndian_helper
specifier|inline
name|quint32
name|qFromLittleEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|quint32
modifier|*
name|dest
parameter_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
name|quint32
argument_list|(
literal|0x00000100
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|quint32
argument_list|(
literal|0x00010000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|quint32
argument_list|(
literal|0x01000000
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFromLittleEndian_helper
specifier|inline
name|quint16
name|qFromLittleEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|quint16
modifier|*
name|dest
parameter_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
literal|0x0100
return|;
block|}
end_function
begin_function
DECL|function|qFromLittleEndian_helper
specifier|inline
name|qint64
name|qFromLittleEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint64
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|qFromLittleEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint64
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qFromLittleEndian_helper
specifier|inline
name|qint32
name|qFromLittleEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint32
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint32
operator|>
operator|(
name|qFromLittleEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint32
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qFromLittleEndian_helper
specifier|inline
name|qint16
name|qFromLittleEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint16
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint16
operator|>
operator|(
name|qFromLittleEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint16
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|qFromLittleEndian
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
name|qFromLittleEndian
argument_list|(
argument|const uchar *src
argument_list|)
block|{
return|return
name|qFromLittleEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qFromLittleEndian
argument_list|(
specifier|const
name|uchar
operator|*
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|quint64
name|template
operator|<
operator|>
specifier|inline
name|quint64
name|qFromLittleEndian
operator|<
name|quint64
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000000100
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000010000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000001000000
argument_list|)
operator||
name|src
index|[
literal|4
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000100000000
argument_list|)
operator||
name|src
index|[
literal|5
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000010000000000
argument_list|)
operator||
name|src
index|[
literal|6
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0001000000000000
argument_list|)
operator||
name|src
index|[
literal|7
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0100000000000000
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint32
name|template
operator|<
operator|>
specifier|inline
name|quint32
name|qFromLittleEndian
operator|<
name|quint32
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
name|quint32
argument_list|(
literal|0x00000100
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|quint32
argument_list|(
literal|0x00010000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|quint32
argument_list|(
literal|0x01000000
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint16
name|template
operator|<
operator|>
specifier|inline
name|quint16
name|qFromLittleEndian
operator|<
name|quint16
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|quint16
argument_list|(
literal|0
operator||
name|src
index|[
literal|0
index|]
operator||
name|src
index|[
literal|1
index|]
operator|*
literal|0x0100
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// signed specializations
end_comment
begin_expr_stmt
DECL|function|qint64
name|template
operator|<
operator|>
specifier|inline
name|qint64
name|qFromLittleEndian
operator|<
name|qint64
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|qFromLittleEndian
operator|<
name|quint64
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint32
name|template
operator|<
operator|>
specifier|inline
name|qint32
name|qFromLittleEndian
operator|<
name|qint32
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint32
operator|>
operator|(
name|qFromLittleEndian
operator|<
name|quint32
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint16
name|template
operator|<
operator|>
specifier|inline
name|qint16
name|qFromLittleEndian
operator|<
name|qint16
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint16
operator|>
operator|(
name|qFromLittleEndian
operator|<
name|quint16
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|quint8
name|template
operator|<
operator|>
specifier|inline
name|quint8
name|qFromLittleEndian
operator|<
name|quint8
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|quint8
operator|>
operator|(
name|src
index|[
literal|0
index|]
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint8
name|template
operator|<
operator|>
specifier|inline
name|qint8
name|qFromLittleEndian
operator|<
name|qint8
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint8
operator|>
operator|(
name|src
index|[
literal|0
index|]
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/* This function will read a big-endian (also known as network order) encoded value from \a src  * and return the value in host-endian encoding.  * There is no requirement that \a src must be aligned. */
end_comment
begin_if
if|#
directive|if
name|defined
name|Q_CC_SUN
end_if
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|quint64
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|quint64
modifier|*
name|dest
parameter_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|7
index|]
operator||
name|src
index|[
literal|6
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000000100
argument_list|)
operator||
name|src
index|[
literal|5
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000010000
argument_list|)
operator||
name|src
index|[
literal|4
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000001000000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000100000000
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000010000000000
argument_list|)
operator||
name|src
index|[
literal|1
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0001000000000000
argument_list|)
operator||
name|src
index|[
literal|0
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0100000000000000
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|quint32
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|quint32
modifier|*
name|dest
parameter_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|3
index|]
operator||
name|src
index|[
literal|2
index|]
operator|*
name|quint32
argument_list|(
literal|0x00000100
argument_list|)
operator||
name|src
index|[
literal|1
index|]
operator|*
name|quint32
argument_list|(
literal|0x00010000
argument_list|)
operator||
name|src
index|[
literal|0
index|]
operator|*
name|quint32
argument_list|(
literal|0x01000000
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|quint16
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|quint16
modifier|*
name|des
parameter_list|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|1
index|]
operator||
name|src
index|[
literal|0
index|]
operator|*
literal|0x0100
return|;
block|}
end_function
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|qint64
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint64
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|qFromBigEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint64
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|qint32
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint32
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint32
operator|>
operator|(
name|qFromBigEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint32
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qFromBigEndian_helper
specifier|inline
name|qint16
name|qFromBigEndian_helper
parameter_list|(
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|qint16
modifier|*
name|dest
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|qint16
operator|>
operator|(
name|qFromBigEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|quint16
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|qFromBigEndian
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
name|qFromBigEndian
argument_list|(
argument|const uchar *src
argument_list|)
block|{
return|return
name|qFromBigEndian_helper
argument_list|(
name|src
argument_list|,
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
name|qFromBigEndian
argument_list|(
specifier|const
name|uchar
operator|*
name|src
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
DECL|function|quint64
specifier|inline
name|quint64
name|qFromBigEndian
operator|<
name|quint64
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|7
index|]
operator||
name|src
index|[
literal|6
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000000100
argument_list|)
operator||
name|src
index|[
literal|5
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000000010000
argument_list|)
operator||
name|src
index|[
literal|4
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000001000000
argument_list|)
operator||
name|src
index|[
literal|3
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000000100000000
argument_list|)
operator||
name|src
index|[
literal|2
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0000010000000000
argument_list|)
operator||
name|src
index|[
literal|1
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0001000000000000
argument_list|)
operator||
name|src
index|[
literal|0
index|]
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x0100000000000000
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
DECL|function|quint32
specifier|inline
name|quint32
name|qFromBigEndian
operator|<
name|quint32
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
literal|0
operator||
name|src
index|[
literal|3
index|]
operator||
name|src
index|[
literal|2
index|]
operator|*
name|quint32
argument_list|(
literal|0x00000100
argument_list|)
operator||
name|src
index|[
literal|1
index|]
operator|*
name|quint32
argument_list|(
literal|0x00010000
argument_list|)
operator||
name|src
index|[
literal|0
index|]
operator|*
name|quint32
argument_list|(
literal|0x01000000
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
DECL|function|quint16
specifier|inline
name|quint16
name|qFromBigEndian
operator|<
name|quint16
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|quint16
argument_list|(
literal|0
operator||
name|src
index|[
literal|1
index|]
operator||
name|src
index|[
literal|0
index|]
operator|*
name|quint16
argument_list|(
literal|0x0100
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// signed specializations
end_comment
begin_expr_stmt
DECL|function|qint64
name|template
operator|<
operator|>
specifier|inline
name|qint64
name|qFromBigEndian
operator|<
name|qint64
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint64
operator|>
operator|(
name|qFromBigEndian
operator|<
name|quint64
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint32
name|template
operator|<
operator|>
specifier|inline
name|qint32
name|qFromBigEndian
operator|<
name|qint32
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint32
operator|>
operator|(
name|qFromBigEndian
operator|<
name|quint32
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint16
name|template
operator|<
operator|>
specifier|inline
name|qint16
name|qFromBigEndian
operator|<
name|qint16
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint16
operator|>
operator|(
name|qFromBigEndian
operator|<
name|quint16
operator|>
operator|(
name|src
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|quint8
name|template
operator|<
operator|>
specifier|inline
name|quint8
name|qFromBigEndian
operator|<
name|quint8
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|quint8
operator|>
operator|(
name|src
index|[
literal|0
index|]
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint8
name|template
operator|<
operator|>
specifier|inline
name|qint8
name|qFromBigEndian
operator|<
name|qint8
operator|>
operator|(
specifier|const
name|uchar
operator|*
name|src
operator|)
block|{
return|return
name|static_cast
operator|<
name|qint8
operator|>
operator|(
name|src
index|[
literal|0
index|]
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/*  * T qbswap(T source).  * Changes the byte order of a value from big endian to little endian or vice versa.  * This function can be used if you are not concerned about alignment issues,  * and it is therefore a bit more convenient and in most cases more efficient. */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|qbswap
argument_list|(
argument|T source
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef
begin_expr_stmt
DECL|function|quint64
name|template
operator|<
operator|>
specifier|inline
name|quint64
name|qbswap
operator|<
name|quint64
operator|>
operator|(
name|quint64
name|source
operator|)
block|{
return|return
name|bswap_64
argument_list|(
name|source
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint32
name|template
operator|<
operator|>
specifier|inline
name|quint32
name|qbswap
operator|<
name|quint32
operator|>
operator|(
name|quint32
name|source
operator|)
block|{
return|return
name|bswap_32
argument_list|(
name|source
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint16
name|template
operator|<
operator|>
specifier|inline
name|quint16
name|qbswap
operator|<
name|quint16
operator|>
operator|(
name|quint16
name|source
operator|)
block|{
return|return
name|bswap_16
argument_list|(
name|source
argument_list|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
DECL|function|quint64
name|template
operator|<
operator|>
specifier|inline
name|quint64
name|qbswap
operator|<
name|quint64
operator|>
operator|(
name|quint64
name|source
operator|)
block|{
return|return
literal|0
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x00000000000000ff
argument_list|)
operator|)
operator|<<
literal|56
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x000000000000ff00
argument_list|)
operator|)
operator|<<
literal|40
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x0000000000ff0000
argument_list|)
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x00000000ff000000
argument_list|)
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x000000ff00000000
argument_list|)
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x0000ff0000000000
argument_list|)
operator|)
operator|>>
literal|24
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x00ff000000000000
argument_list|)
operator|)
operator|>>
literal|40
operator|)
operator||
operator|(
operator|(
name|source
operator|&
name|Q_UINT64_C
argument_list|(
literal|0xff00000000000000
argument_list|)
operator|)
operator|>>
literal|56
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint32
name|template
operator|<
operator|>
specifier|inline
name|quint32
name|qbswap
operator|<
name|quint32
operator|>
operator|(
name|quint32
name|source
operator|)
block|{
return|return
literal|0
operator||
operator|(
operator|(
name|source
operator|&
literal|0x000000ff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|source
operator|&
literal|0x0000ff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|source
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|source
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|quint16
name|template
operator|<
operator|>
specifier|inline
name|quint16
name|qbswap
operator|<
name|quint16
operator|>
operator|(
name|quint16
name|source
operator|)
block|{
return|return
name|quint16
argument_list|(
literal|0
operator||
operator|(
operator|(
name|source
operator|&
literal|0x00ff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|source
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __GLIBC__
end_comment
begin_comment
comment|// signed specializations
end_comment
begin_expr_stmt
DECL|function|qint64
name|template
operator|<
operator|>
specifier|inline
name|qint64
name|qbswap
operator|<
name|qint64
operator|>
operator|(
name|qint64
name|source
operator|)
block|{
return|return
name|qbswap
operator|<
name|quint64
operator|>
operator|(
name|quint64
argument_list|(
name|source
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint32
name|template
operator|<
operator|>
specifier|inline
name|qint32
name|qbswap
operator|<
name|qint32
operator|>
operator|(
name|qint32
name|source
operator|)
block|{
return|return
name|qbswap
operator|<
name|quint32
operator|>
operator|(
name|quint32
argument_list|(
name|source
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint16
name|template
operator|<
operator|>
specifier|inline
name|qint16
name|qbswap
operator|<
name|qint16
operator|>
operator|(
name|qint16
name|source
operator|)
block|{
return|return
name|qbswap
operator|<
name|quint16
operator|>
operator|(
name|quint16
argument_list|(
name|source
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
end_if
begin_expr_stmt
DECL|function|qToBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qToBigEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qFromBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qFromBigEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qToLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qToLittleEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|qbswap
operator|<
name|T
operator|>
operator|(
name|source
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qFromLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qFromLittleEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|qbswap
operator|<
name|T
operator|>
operator|(
name|source
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qToBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qToBigEndian
argument_list|(
argument|T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|qToUnaligned
operator|<
name|T
operator|>
operator|(
name|src
operator|,
name|dest
operator|)
block|; }
DECL|function|qToLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qToLittleEndian
argument_list|(
argument|T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|qbswap
operator|<
name|T
operator|>
operator|(
name|src
operator|,
name|dest
operator|)
block|; }
else|#
directive|else
comment|// Q_LITTLE_ENDIAN
DECL|function|qToBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qToBigEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|qbswap
operator|<
name|T
operator|>
operator|(
name|source
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qFromBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qFromBigEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|qbswap
operator|<
name|T
operator|>
operator|(
name|source
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qToLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qToLittleEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qFromLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|qFromLittleEndian
argument_list|(
argument|T source
argument_list|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qToBigEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qToBigEndian
argument_list|(
argument|T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|qbswap
operator|<
name|T
operator|>
operator|(
name|src
operator|,
name|dest
operator|)
block|; }
DECL|function|qToLittleEndian
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|qToLittleEndian
argument_list|(
argument|T src
argument_list|,
argument|uchar *dest
argument_list|)
block|{
name|qToUnaligned
operator|<
name|T
operator|>
operator|(
name|src
operator|,
name|dest
operator|)
block|; }
endif|#
directive|endif
comment|// Q_BYTE_ORDER == Q_BIG_ENDIAN
DECL|function|quint8
name|template
operator|<
operator|>
specifier|inline
name|quint8
name|qbswap
operator|<
name|quint8
operator|>
operator|(
name|quint8
name|source
operator|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|qint8
name|template
operator|<
operator|>
specifier|inline
name|qint8
name|qbswap
operator|<
name|qint8
operator|>
operator|(
name|qint8
name|source
operator|)
block|{
return|return
name|source
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QENDIAN_H
end_comment
end_unit
