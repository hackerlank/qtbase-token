begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"qdbusinterface_p.h"
end_include
begin_comment
comment|// for ANNOTATION_NO_WAIT
end_comment
begin_include
include|#
directive|include
file|"qdbusabstractadaptor_p.h"
end_include
begin_comment
comment|// for QCLASSINFO_DBUS_*
end_comment
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_comment
comment|// for the flags
end_comment
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|Q_DBUS_EXPORT
name|QString
name|qDBusGenerateMetaObjectXml
parameter_list|(
name|QString
name|interface
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|mo
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|base
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|typeNameToXml
specifier|static
specifier|inline
name|QString
name|typeNameToXml
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
block|{
comment|// ### copied from qtextdocument.cpp
comment|// ### move this into QtCore at some point
name|QString
name|plain
init|=
name|QLatin1String
argument_list|(
name|typeName
argument_list|)
decl_stmt|;
name|QString
name|rich
decl_stmt|;
name|rich
operator|.
name|reserve
argument_list|(
name|int
argument_list|(
name|plain
operator|.
name|length
argument_list|()
operator|*
literal|1.1
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|plain
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|plain
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'<'
argument_list|)
condition|)
name|rich
operator|+=
name|QLatin1String
argument_list|(
literal|"&lt;"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|plain
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'>'
argument_list|)
condition|)
name|rich
operator|+=
name|QLatin1String
argument_list|(
literal|"&gt;"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|plain
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
condition|)
name|rich
operator|+=
name|QLatin1String
argument_list|(
literal|"&amp;"
argument_list|)
expr_stmt|;
else|else
name|rich
operator|+=
name|plain
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|rich
return|;
block|}
end_function
begin_comment
comment|// implement the D-Bus org.freedesktop.DBus.Introspectable interface
end_comment
begin_comment
comment|// we do that by analysing the metaObject of all the adaptor interfaces
end_comment
begin_function
DECL|function|generateInterfaceXml
specifier|static
name|QString
name|generateInterfaceXml
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|mo
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|methodOffset
parameter_list|,
name|int
name|propOffset
parameter_list|)
block|{
name|QString
name|retval
decl_stmt|;
comment|// start with properties:
if|if
condition|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableProperties
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableProperties
operator|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|propOffset
init|;
name|i
operator|<
name|mo
operator|->
name|propertyCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|accessvalues
index|[]
init|=
block|{
literal|0
block|,
literal|"read"
block|,
literal|"write"
block|,
literal|"readwrite"
block|}
decl_stmt|;
name|QMetaProperty
name|mp
init|=
name|mo
operator|->
name|property
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
operator|(
name|mp
operator|.
name|isScriptable
argument_list|()
operator|&&
operator|(
name|flags
operator|&
name|QDBusConnection
operator|::
name|ExportScriptableProperties
operator|)
operator|)
operator|||
operator|(
operator|!
name|mp
operator|.
name|isScriptable
argument_list|()
operator|&&
operator|(
name|flags
operator|&
name|QDBusConnection
operator|::
name|ExportNonScriptableProperties
operator|)
operator|)
operator|)
condition|)
continue|continue;
name|int
name|access
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|mp
operator|.
name|isReadable
argument_list|()
condition|)
name|access
operator||=
literal|1
expr_stmt|;
if|if
condition|(
name|mp
operator|.
name|isWritable
argument_list|()
condition|)
name|access
operator||=
literal|2
expr_stmt|;
name|int
name|typeId
init|=
name|mp
operator|.
name|userType
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|typeId
condition|)
continue|continue;
specifier|const
name|char
modifier|*
name|signature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|signature
condition|)
continue|continue;
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<property name=\"%1\" type=\"%2\" access=\"%3\""
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|mp
operator|.
name|name
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|signature
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|accessvalues
index|[
name|access
index|]
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|signature
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
block|{
specifier|const
name|char
modifier|*
name|typeName
init|=
name|QVariant
operator|::
name|typeToName
argument_list|(
name|QVariant
operator|::
name|Type
argument_list|(
name|typeId
argument_list|)
argument_list|)
decl_stmt|;
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|">\n<annotation name=\"com.trolltech.QtDBus.QtTypeName\" value=\"%3\"/>\n</property>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|typeName
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|retval
operator|+=
name|QLatin1String
argument_list|(
literal|"/>\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// now add methods:
for|for
control|(
name|int
name|i
init|=
name|methodOffset
init|;
name|i
operator|<
name|mo
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaMethod
name|mm
init|=
name|mo
operator|->
name|method
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QByteArray
name|signature
init|=
name|mm
operator|.
name|signature
argument_list|()
decl_stmt|;
name|int
name|paren
init|=
name|signature
operator|.
name|indexOf
argument_list|(
literal|'('
argument_list|)
decl_stmt|;
name|bool
name|isSignal
decl_stmt|;
if|if
condition|(
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Signal
condition|)
comment|// adding a signal
name|isSignal
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|mm
operator|.
name|access
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Public
operator|&&
operator|(
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Slot
operator|||
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Method
operator|)
condition|)
name|isSignal
operator|=
literal|false
expr_stmt|;
else|else
continue|continue;
comment|// neither signal nor public slot
if|if
condition|(
name|isSignal
operator|&&
operator|!
operator|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableSignals
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableSignals
operator|)
operator|)
condition|)
continue|continue;
comment|// we're not exporting any signals
if|if
condition|(
operator|!
name|isSignal
operator|&&
operator|(
operator|!
operator|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableSlots
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableSlots
operator|)
operator|)
operator|&&
operator|!
operator|(
name|flags
operator|&
operator|(
name|QDBusConnection
operator|::
name|ExportScriptableInvokables
operator||
name|QDBusConnection
operator|::
name|ExportNonScriptableInvokables
operator|)
operator|)
operator|)
condition|)
continue|continue;
comment|// we're not exporting any slots or invokables
name|QString
name|xml
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<%1 name=\"%2\">\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isSignal
condition|?
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|signature
operator|.
name|left
argument_list|(
name|paren
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|// check the return type first
name|int
name|typeId
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|mm
operator|.
name|typeName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|typeId
condition|)
block|{
specifier|const
name|char
modifier|*
name|typeName
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|typeId
argument_list|)
decl_stmt|;
if|if
condition|(
name|typeName
condition|)
block|{
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<arg type=\"%1\" direction=\"out\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|typeName
argument_list|)
argument_list|)
expr_stmt|;
comment|// do we need to describe this argument?
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|typeName
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<annotation name=\"com.trolltech.QtDBus.QtTypeName.Out0\" value=\"%1\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|QVariant
operator|::
name|typeToName
argument_list|(
name|QVariant
operator|::
name|Type
argument_list|(
name|typeId
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
continue|continue;
block|}
elseif|else
if|if
condition|(
operator|*
name|mm
operator|.
name|typeName
argument_list|()
condition|)
continue|continue;
comment|// wasn't a valid type
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|names
init|=
name|mm
operator|.
name|parameterNames
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|int
argument_list|>
name|types
decl_stmt|;
name|int
name|inputCount
init|=
name|qDBusParametersForMethod
argument_list|(
name|mm
argument_list|,
name|types
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputCount
operator|==
operator|-
literal|1
condition|)
continue|continue;
comment|// invalid form
if|if
condition|(
name|isSignal
operator|&&
name|inputCount
operator|+
literal|1
operator|!=
name|types
operator|.
name|count
argument_list|()
condition|)
continue|continue;
comment|// signal with output arguments?
if|if
condition|(
name|isSignal
operator|&&
name|types
operator|.
name|at
argument_list|(
name|inputCount
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
condition|)
continue|continue;
comment|// signal with QDBusMessage argument?
if|if
condition|(
name|isSignal
operator|&&
name|mm
operator|.
name|attributes
argument_list|()
operator|&
name|QMetaMethod
operator|::
name|Cloned
condition|)
continue|continue;
comment|// cloned signal?
name|int
name|j
decl_stmt|;
name|bool
name|isScriptable
init|=
name|mm
operator|.
name|attributes
argument_list|()
operator|&
name|QMetaMethod
operator|::
name|Scriptable
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|1
init|;
name|j
operator|<
name|types
operator|.
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
comment|// input parameter for a slot or output for a signal
if|if
condition|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
condition|)
block|{
name|isScriptable
operator|=
literal|true
expr_stmt|;
continue|continue;
block|}
name|QString
name|name
decl_stmt|;
if|if
condition|(
operator|!
name|names
operator|.
name|at
argument_list|(
name|j
operator|-
literal|1
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"name=\"%1\" "
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|names
operator|.
name|at
argument_list|(
name|j
operator|-
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|isOutput
init|=
name|isSignal
operator|||
name|j
operator|>
name|inputCount
decl_stmt|;
specifier|const
name|char
modifier|*
name|signature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
decl_stmt|;
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<arg %1type=\"%2\" direction=\"%3\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|signature
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
condition|?
name|QLatin1String
argument_list|(
literal|"out"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"in"
argument_list|)
argument_list|)
expr_stmt|;
comment|// do we need to describe this argument?
if|if
condition|(
name|QDBusMetaType
operator|::
name|signatureToType
argument_list|(
name|signature
argument_list|)
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
block|{
specifier|const
name|char
modifier|*
name|typeName
init|=
name|QVariant
operator|::
name|typeToName
argument_list|(
name|QVariant
operator|::
name|Type
argument_list|(
name|types
operator|.
name|at
argument_list|(
name|j
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|xml
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<annotation name=\"com.trolltech.QtDBus.QtTypeName.%1%2\" value=\"%3\"/>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
condition|?
name|QLatin1String
argument_list|(
literal|"Out"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"In"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|isOutput
operator|&&
operator|!
name|isSignal
condition|?
name|j
operator|-
name|inputCount
else|:
name|j
operator|-
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|typeNameToXml
argument_list|(
name|typeName
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|int
name|wantedMask
decl_stmt|;
if|if
condition|(
name|isScriptable
condition|)
name|wantedMask
operator|=
name|isSignal
condition|?
name|QDBusConnection
operator|::
name|ExportScriptableSignals
else|:
name|QDBusConnection
operator|::
name|ExportScriptableSlots
expr_stmt|;
else|else
name|wantedMask
operator|=
name|isSignal
condition|?
name|QDBusConnection
operator|::
name|ExportNonScriptableSignals
else|:
name|QDBusConnection
operator|::
name|ExportNonScriptableSlots
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|wantedMask
operator|)
operator|!=
name|wantedMask
condition|)
continue|continue;
if|if
condition|(
name|qDBusCheckAsyncTag
argument_list|(
name|mm
operator|.
name|tag
argument_list|()
argument_list|)
condition|)
comment|// add the no-reply annotation
name|xml
operator|+=
name|QLatin1String
argument_list|(
literal|"<annotation name=\""
name|ANNOTATION_NO_WAIT
literal|"\""
literal|" value=\"true\"/>\n"
argument_list|)
expr_stmt|;
name|retval
operator|+=
name|xml
expr_stmt|;
name|retval
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"</%1>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|isSignal
condition|?
name|QLatin1String
argument_list|(
literal|"signal"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"method"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|retval
return|;
block|}
end_function
begin_function
DECL|function|qDBusGenerateMetaObjectXml
name|QString
name|qDBusGenerateMetaObjectXml
parameter_list|(
name|QString
name|interface
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|mo
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|base
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
if|if
condition|(
name|interface
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// generate the interface name from the meta object
name|interface
operator|=
name|qDBusInterfaceFromMetaObject
argument_list|(
name|mo
argument_list|)
expr_stmt|;
name|QString
name|xml
decl_stmt|;
name|int
name|idx
init|=
name|mo
operator|->
name|indexOfClassInfo
argument_list|(
name|QCLASSINFO_DBUS_INTROSPECTION
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|>=
name|mo
operator|->
name|classInfoOffset
argument_list|()
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|mo
operator|->
name|classInfo
argument_list|(
name|idx
argument_list|)
operator|.
name|value
argument_list|()
argument_list|)
return|;
else|else
name|xml
operator|=
name|generateInterfaceXml
argument_list|(
name|mo
argument_list|,
name|flags
argument_list|,
name|base
operator|->
name|methodCount
argument_list|()
argument_list|,
name|base
operator|->
name|propertyCount
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// don't add an empty interface
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<interface name=\"%1\">\n%2</interface>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|interface
argument_list|,
name|xml
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
unit|QString qDBusGenerateMetaObjectXml(QString interface, const QMetaObject *mo, const QMetaObject *base,                                    int flags) {     if (interface.isEmpty()) {
comment|// generate the interface name from the meta object
end_comment
begin_comment
unit|int idx = mo->indexOfClassInfo(QCLASSINFO_DBUS_INTERFACE);         if (idx>= mo->classInfoOffset()) {             interface = QLatin1String(mo->classInfo(idx).value());         } else {             interface = QLatin1String(mo->className());             interface.replace(QLatin1String("::"), QLatin1String("."));              if (interface.startsWith(QLatin1String("QDBus"))) {                 interface.prepend(QLatin1String("com.trolltech.QtDBus."));             } else if (interface.startsWith(QLatin1Char('Q'))&&                        interface.length()>= 2&& interface.at(1).isUpper()) {
comment|// assume it's Qt
end_comment
begin_comment
unit|interface.prepend(QLatin1String("com.trolltech.Qt."));             } else if (!QCoreApplication::instance()||                        QCoreApplication::instance()->applicationName().isEmpty()) {                 interface.prepend(QLatin1String("local."));             } else {                 interface.prepend(QLatin1Char('.')).prepend(QCoreApplication::instance()->applicationName());                 QStringList domainName =                     QCoreApplication::instance()->organizationDomain().split(QLatin1Char('.'),                                                                              QString::SkipEmptyParts);                 if (domainName.isEmpty())                     interface.prepend(QLatin1String("local."));                 else                     for (int i = 0; i< domainName.count(); ++i)                         interface.prepend(QLatin1Char('.')).prepend(domainName.at(i));             }         }     }      QString xml;     int idx = mo->indexOfClassInfo(QCLASSINFO_DBUS_INTROSPECTION);     if (idx>= mo->classInfoOffset())         return QString::fromUtf8(mo->classInfo(idx).value());     else         xml = generateInterfaceXml(mo, flags, base->methodCount(), base->propertyCount());      if (xml.isEmpty())         return QString();
comment|// don't add an empty interface
end_comment
begin_endif
unit|return QString::fromLatin1("<interface name=\"%1\">\n%2</interface>\n")         .arg(interface, xml); }
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
