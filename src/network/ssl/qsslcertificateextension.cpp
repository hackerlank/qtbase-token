begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Richard J. Moore<rich@kde.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QSslCertificateExtension     \brief The QSslCertificateExtension provides an API for accessing the extensions of an X509 certificate.     \since 5.0      \rentrant     \ingroup network     \ingroup ssl     \inmodule QtNetwork      QSslCertificateExtension provides access to an extension stored in     an X509 certificate. The information available depends on the type     of extension being accessed.      All X509 certificate extensions have the following properties:      \table     \header        \o Property        \o Description     \row        \o name        \o The human readable name of the extension, eg. 'basicConstraints'.     \row        \o criticality        \o This is a boolean value indicating if the extension is critical           to correctly interpreting the certificate.     \row        \o oid        \o The ASN.1 object identifier that specifies which extension this           is.     \row        \o supported        \o If this is true the structure of the extension's value will not           change between Qt versions.     \row        \o value        \o A QVariant with a structure dependent on the type of extension.     \endtable      Whilst this class provides access to any type of extension, only     some are guaranteed to be returned in a format that will remain     unchanged between releases. The isSupported() method returns true     for extensions where this is the case.      The extensions currently supported, and the structure of the value     returned are as follows:      \table     \header        \o Name        \o OID        \o Details     \row        \o basicConstraints        \o 2.5.29.19        \o Returned as a QVariantMap. The key 'ca' contains a boolean value,           the optional key 'pathLenConstraint' contains an integer.     \row        \o authorityInfoAccess        \o 1.3.6.1.5.5.7.1.1        \o Returned as a QVariantMap. There is a key for each access method,           with the value being a URI.     \row        \o subjectKeyIdentifier        \o 2.5.29.14        \o Returned as a QVariant containing a QString. The string is the key           identifier.     \row        \o authorityKeyIdentifier        \o 2.5.29.35        \o Returned as a QVariantMap. The optional key 'keyid' contains the key           identifier as a hex string stored in a QByteArray. The optional key           'serial' contains the authority key serial number as a qlonglong.           Currently there is no support for the general names field of this           extension.     \endtable      In addition to the supported extensions above, many other common extensions     will be returned in a reasonably structured way. Extensions that the SSL     backend has no support for at all will be returned as a QByteArray.      Further information about the types of extensions certificates can     contain can be found in RFC 5280.      \sa QSslCertificate::extensions()  */
end_comment
begin_include
include|#
directive|include
file|"qsslcertificateextension.h"
end_include
begin_include
include|#
directive|include
file|"qsslcertificateextension_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSslCertificateExtension
name|QSslCertificateExtension
operator|::
name|QSslCertificateExtension
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslCertificateExtensionPrivate
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QSslCertificateExtension
name|QSslCertificateExtension
operator|::
name|QSslCertificateExtension
parameter_list|(
specifier|const
name|QSslCertificateExtension
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSslCertificateExtension
name|QSslCertificateExtension
operator|::
name|~
name|QSslCertificateExtension
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator =
name|QSslCertificateExtension
modifier|&
name|QSslCertificateExtension
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSslCertificateExtension
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
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the ASN.1 OID of this extension.  */
end_comment
begin_function
DECL|function|oid
name|QString
name|QSslCertificateExtension
operator|::
name|oid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|oid
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the extension. If no name is known for the     extension then the OID will be returned.  */
end_comment
begin_function
DECL|function|name
name|QString
name|QSslCertificateExtension
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the value of the extension. The structure of the value     returned depends on the extension type.  */
end_comment
begin_function
DECL|function|value
name|QVariant
name|QSslCertificateExtension
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|value
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the criticality of the extension.  */
end_comment
begin_function
DECL|function|isCritical
name|bool
name|QSslCertificateExtension
operator|::
name|isCritical
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|critical
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the true if this extension is supported. In this case,     supported simply means that the structure of the QVariant returned     by the value() accessor will remain unchanged between versions.     Unsupported extensions can be freely used, however there is no     guarantee that the returned data will have the same structure     between versions.  */
end_comment
begin_function
DECL|function|isSupported
name|bool
name|QSslCertificateExtension
operator|::
name|isSupported
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|supported
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
