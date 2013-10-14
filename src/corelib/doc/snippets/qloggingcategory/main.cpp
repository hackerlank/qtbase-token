begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_comment
comment|//![1]
end_comment
begin_comment
comment|// in a header
end_comment
begin_macro
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
argument|QT_DRIVER_USB
argument_list|)
end_macro
begin_comment
comment|// in one source file
end_comment
begin_macro
name|Q_LOGGING_CATEGORY
argument_list|(
argument|QT_DRIVER_USB
argument_list|,
literal|"qt.driver.usb"
argument_list|)
end_macro
begin_comment
comment|//![1]
end_comment
begin_comment
comment|// Completely made up example, inspired by en.wikipedia.org/wiki/USB :)
end_comment
begin_struct
DECL|struct|UsbEntry
struct|struct
name|UsbEntry
block|{
DECL|member|id
name|int
name|id
decl_stmt|;
DECL|member|classtype
name|int
name|classtype
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
modifier|&
name|dbg
parameter_list|,
specifier|const
name|UsbEntry
modifier|&
name|entry
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|""
operator|<<
name|entry
operator|.
name|id
operator|<<
literal|" ("
operator|<<
name|entry
operator|.
name|classtype
operator|<<
literal|")"
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|usbEntries
name|QList
argument_list|<
name|UsbEntry
argument_list|>
name|usbEntries
parameter_list|()
block|{
name|QList
argument_list|<
name|UsbEntry
argument_list|>
name|entries
decl_stmt|;
return|return
name|entries
return|;
block|}
end_function
begin_comment
comment|//![20]
end_comment
begin_function_decl
name|void
name|myCategoryFilter
parameter_list|(
name|QLoggingCategory
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//![20]
end_comment
begin_comment
comment|//![21]
end_comment
begin_decl_stmt
DECL|variable|oldCategoryFilter
name|QLoggingCategory
operator|::
name|CategoryFilter
name|oldCategoryFilter
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|myCategoryFilter
name|void
name|myCategoryFilter
parameter_list|(
name|QLoggingCategory
modifier|*
name|category
parameter_list|)
block|{
comment|// configure qt.driver.usb category here, otherwise forward to to default filter.
if|if
condition|(
name|qstrcmp
argument_list|(
name|category
operator|->
name|categoryName
argument_list|()
argument_list|,
literal|"qt.driver.usb"
argument_list|)
operator|==
literal|0
condition|)
name|category
operator|->
name|setEnabled
argument_list|(
name|QtDebugMsg
argument_list|,
literal|true
argument_list|)
expr_stmt|;
else|else
name|oldCategoryFilter
argument_list|(
name|category
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//![21]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//![2]
name|QLoggingCategory
operator|::
name|setFilterRules
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qt.driver.usb.debug=true"
argument_list|)
argument_list|)
expr_stmt|;
comment|//![2]
comment|//![22]
comment|// ...
name|oldCategoryFilter
operator|=
name|QLoggingCategory
operator|::
name|installFilter
argument_list|(
name|myCategoryFilter
argument_list|)
expr_stmt|;
comment|//![22]
comment|//![3]
name|qSetMessagePattern
argument_list|(
literal|"%{category} %{message}"
argument_list|)
expr_stmt|;
comment|//![3]
comment|//![4]
comment|// usbEntries() will only be called if QT_DRIVER_USB category is enabled
name|qCDebug
argument_list|(
name|QT_DRIVER_USB
argument_list|)
operator|<<
literal|"devices: "
operator|<<
name|usbEntries
argument_list|()
expr_stmt|;
comment|//![4]
block|{
comment|//![10]
name|QLoggingCategory
name|category
argument_list|(
literal|"qt.driver.usb"
argument_list|)
decl_stmt|;
name|qCDebug
argument_list|(
name|category
argument_list|)
operator|<<
literal|"a debug message"
expr_stmt|;
comment|//![10]
block|}
block|{
comment|//![11]
name|QLoggingCategory
name|category
argument_list|(
literal|"qt.driver.usb"
argument_list|)
decl_stmt|;
name|qCWarning
argument_list|(
name|category
argument_list|)
operator|<<
literal|"a warning message"
expr_stmt|;
comment|//![11]
block|}
block|{
comment|//![12]
name|QLoggingCategory
name|category
argument_list|(
literal|"qt.driver.usb"
argument_list|)
decl_stmt|;
name|qCCritical
argument_list|(
name|category
argument_list|)
operator|<<
literal|"a critical message"
expr_stmt|;
comment|//![12]
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
