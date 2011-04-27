begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIGNALSPY_H
end_ifndef
begin_define
DECL|macro|QSIGNALSPY_H
define|#
directive|define
name|QSIGNALSPY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Test
argument_list|)
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* ### Qt5: change the class to use regular BC mechanisms, such that we can  * implement things like suggested in task 160192. */
end_comment
begin_decl_stmt
DECL|variable|QObject
name|class
name|QSignalSpy
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QList
decl|<
name|QList
decl|<
name|QVariant
decl|>>
block|{
name|public
label|:
name|QSignalSpy
argument_list|(
argument|QObject *obj
argument_list|,
argument|const char *aSignal
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_BOR
specifier|const
name|int
name|memberOffset
init|=
name|QObject
operator|::
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
decl_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|int
name|memberOffset
init|=
name|QObject
operator|::
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
decl_stmt|;
endif|#
directive|endif
name|Q_ASSERT
argument_list|(
name|obj
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|aSignal
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|aSignal
index|[
literal|0
index|]
operator|-
literal|'0'
operator|)
operator|&
literal|0x03
operator|)
operator|!=
name|QSIGNAL_CODE
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: Not a valid signal, use the SIGNAL macro"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QByteArray
name|ba
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|aSignal
operator|+
literal|1
argument_list|)
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|obj
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|int
name|sigIndex
init|=
name|mo
operator|->
name|indexOfMethod
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sigIndex
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: No such signal: '%s'"
argument_list|,
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|QMetaObject
operator|::
name|connect
argument_list|(
name|obj
argument_list|,
name|sigIndex
argument_list|,
name|this
argument_list|,
name|memberOffset
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: QMetaObject::connect returned false. Unable to connect."
argument_list|)
expr_stmt|;
return|return;
block|}
name|sig
operator|=
name|ba
expr_stmt|;
name|initArgs
argument_list|(
name|mo
operator|->
name|method
argument_list|(
name|sigIndex
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|sig
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|QByteArray
name|signal
argument_list|()
specifier|const
block|{
return|return
name|sig
return|;
block|}
name|int
name|qt_metacall
argument_list|(
name|QMetaObject
operator|::
name|Call
name|call
argument_list|,
name|int
name|methodId
argument_list|,
name|void
operator|*
operator|*
name|a
argument_list|)
block|{
name|methodId
operator|=
name|QObject
operator|::
name|qt_metacall
argument_list|(
name|call
argument_list|,
name|methodId
argument_list|,
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|methodId
operator|<
literal|0
condition|)
return|return
name|methodId
return|;
if|if
condition|(
name|call
operator|==
name|QMetaObject
operator|::
name|InvokeMetaMethod
condition|)
block|{
if|if
condition|(
name|methodId
operator|==
literal|0
condition|)
block|{
name|appendArgs
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
operator|--
name|methodId
expr_stmt|;
block|}
return|return
name|methodId
return|;
block|}
name|private
label|:
name|void
name|initArgs
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|)
block|{
name|QList
operator|<
name|QByteArray
operator|>
name|params
operator|=
name|member
operator|.
name|parameterTypes
argument_list|()
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
name|params
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|tp
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|params
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|tp
operator|==
name|QMetaType
operator|::
name|Void
condition|)
name|qWarning
argument_list|(
literal|"Don't know how to handle '%s', use qRegisterMetaType to register it."
argument_list|,
name|params
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|args
operator|<<
name|tp
expr_stmt|;
block|}
block|}
name|void
name|appendArgs
parameter_list|(
name|void
modifier|*
modifier|*
name|a
parameter_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|list
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
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaType
operator|::
name|Type
name|type
operator|=
name|static_cast
operator|<
name|QMetaType
operator|::
name|Type
operator|>
operator|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|)
expr_stmt|;
name|list
operator|<<
name|QVariant
argument_list|(
name|type
argument_list|,
name|a
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|append
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
comment|// the full, normalized signal name
name|QByteArray
name|sig
decl_stmt|;
comment|// holds the QMetaType types for the argument list of the signal
name|QList
operator|<
name|int
operator|>
name|args
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
