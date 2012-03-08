begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"author"
argument_list|,
literal|"Sabrina Schweinsteiger"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"url"
argument_list|,
literal|"http://doc.moosesoft.co.uk/1.0/"
argument_list|)
decl|public
range|:
operator|...
block|}
class|;
comment|//! [0]
comment|//! [1]
name|QByteArray
name|normType
init|=
name|QMetaObject
operator|::
name|normalizedType
argument_list|(
literal|" int    const  *"
argument_list|)
decl_stmt|;
comment|// normType is now "const int*"
comment|//! [1]
comment|//! [2]
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|pushButton
argument_list|,
literal|"animateClick"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QMetaObject
block|::
name|invokeMethod
label|:
name|Unable
name|to
name|handle
name|unregistered
name|datatype
decl|'MyType'
comment|//! [3]
comment|//! [4]
name|QString
name|retVal
decl_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|obj
argument_list|,
literal|"compute"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|QString
argument_list|,
name|retVal
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
literal|"sqrt"
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
literal|42
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|double
argument_list|,
literal|9.7
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
class|class
name|MyClass
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"author"
argument_list|,
literal|"Sabrina Schweinsteiger"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"url"
argument_list|,
literal|"http://doc.moosesoft.co.uk/1.0/"
argument_list|)
decl|public
range|:
operator|...
block|}
class|;
comment|//! [5]
comment|//! [propertyCount]
specifier|const
name|QMetaObject
modifier|*
name|metaObject
init|=
name|obj
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|QStringList
name|properties
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|metaObject
operator|->
name|propertyOffset
argument_list|()
init|;
name|i
operator|<
name|metaObject
operator|->
name|propertyCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|properties
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|metaObject
operator|->
name|property
argument_list|(
name|i
argument_list|)
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [propertyCount]
comment|//! [methodCount]
specifier|const
name|QMetaObject
modifier|*
name|metaObject
init|=
name|obj
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|QStringList
name|methods
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|metaObject
operator|->
name|methodOffset
argument_list|()
init|;
name|i
operator|<
name|metaObject
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|methods
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
name|metaObject
operator|->
name|method
argument_list|(
name|i
argument_list|)
operator|.
name|methodSignature
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [methodCount]
comment|//! [6]
name|int
name|methodIndex
init|=
name|pushButton
operator|->
name|metaObject
argument_list|()
operator|->
name|indexOfMethod
argument_list|(
literal|"animateClick()"
argument_list|)
decl_stmt|;
name|QMetaMethod
name|method
init|=
name|metaObject
operator|->
name|method
argument_list|(
name|methodIndex
argument_list|)
decl_stmt|;
name|method
operator|.
name|invoke
argument_list|(
name|pushButton
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QMetaMethod
block|::
name|invoke
label|:
name|Unable
name|to
name|handle
name|unregistered
name|datatype
decl|'MyType'
comment|//! [7]
comment|//! [8]
name|QString
name|retVal
decl_stmt|;
name|QByteArray
name|normalizedSignature
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
literal|"compute(QString, int, double)"
argument_list|)
decl_stmt|;
name|int
name|methodIndex
init|=
name|obj
operator|->
name|metaObject
argument_list|()
operator|->
name|indexOfMethod
argument_list|(
name|normalizedSignature
argument_list|)
decl_stmt|;
name|QMetaMethod
name|method
init|=
name|metaObject
operator|->
name|method
argument_list|(
name|methodIndex
argument_list|)
decl_stmt|;
name|method
operator|.
name|invoke
argument_list|(
name|obj
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|QString
argument_list|,
name|retVal
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
literal|"sqrt"
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
literal|42
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|double
argument_list|,
literal|9.7
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [8]
block|}
end_function
end_unit
