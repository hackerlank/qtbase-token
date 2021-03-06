begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Governikus GmbH& Co. KG. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsslellipticcurve.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QSslEllipticCurve     \since 5.5      \brief Represents an elliptic curve for use by elliptic-curve cipher algorithms.      \reentrant     \ingroup network     \ingroup ssl     \inmodule QtNetwork      The class QSslEllipticCurve represents an elliptic curve for use by     elliptic-curve cipher algorithms.      Elliptic curves can be constructed from a "short name" (SN) (fromShortName()),     and by a call to QSslConfiguration::supportedEllipticCurves().      QSslEllipticCurve instances can be compared for equality and can be used as keys     in QHash and QSet. They cannot be used as key in a QMap. */
comment|/*!     \fn QSslEllipticCurve::QSslEllipticCurve()      Constructs an invalid elliptic curve.      \sa isValid(), QSslConfiguration::supportedEllipticCurves() */
comment|/*!     \fn QSslEllipticCurve QSslEllipticCurve::fromShortName(const QString&name)      Returns an QSslEllipticCurve instance representing the     named curve \a name. The \a name is the conventional short     name for the curve, as represented by RFC 4492 (for instance \c{secp521r1}),     or as NIST short names (for instance \c{P-256}). The actual set of     recognized names depends on the SSL implementation.      If the given \a name is not supported, returns an invalid QSslEllipticCurve instance.      \note The OpenSSL implementation of this function treats the name case-sensitively.      \sa shortName() */
comment|/*!     \fn QSslEllipticCurve QSslEllipticCurve::fromLongName(const QString&name)      Returns an QSslEllipticCurve instance representing the named curve \a name.     The \a name is a long name for the curve, whose exact spelling depends on the     SSL implementation.      If the given \a name is not supported, returns an invalid QSslEllipticCurve instance.      \note The OpenSSL implementation of this function treats the name case-sensitively.      \sa longName() */
comment|/*!     \fn QString QSslEllipticCurve::shortName() const      Returns the conventional short name for this curve. If this     curve is invalid, returns an empty string.      \sa longName() */
comment|/*!     \fn QString QSslEllipticCurve::longName() const      Returns the conventional long name for this curve. If this     curve is invalid, returns an empty string.      \sa shortName() */
comment|/*!     \fn bool QSslEllipticCurve::isValid() const      Returns true if this elliptic curve is a valid curve, false otherwise. */
comment|/*!     \fn bool QSslEllipticCurve::isTlsNamedCurve() const      Returns true if this elliptic curve is one of the named curves that can be     used in the key exchange when using an elliptic curve cipher with TLS;     false otherwise. */
comment|/*!     \fn bool operator==(QSslEllipticCurve lhs, QSslEllipticCurve rhs)     \since 5.5     \relates QSslEllipticCurve      Returns true if the curve \a lhs represents the same curve of \a rhs; */
comment|/*!     \fn bool operator!=(QSslEllipticCurve lhs, QSslEllipticCurve rhs)     \since 5.5     \relates QSslEllipticCurve      Returns true if the curve \a lhs represents a different curve than \a rhs;     false otherwise. */
comment|/*!     \fn uint qHash(QSslEllipticCurve curve, uint seed)     \since 5.5     \relates QHash      Returns an hash value for the curve \a curve, using \a seed to seed     the calculation. */
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
comment|/*!     \relates QSslEllipticCurve     \since 5.5      Writes the elliptic curve \a curve into the debug object \a debug for     debugging purposes.      \sa {Debugging Techniques} */
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
name|QSslEllipticCurve
name|curve
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
decl_stmt|;
name|debug
operator|.
name|resetFormat
argument_list|()
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|debug
operator|<<
literal|"QSslEllipticCurve("
operator|<<
name|curve
operator|.
name|shortName
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
