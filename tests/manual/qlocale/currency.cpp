begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"currency.h"
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QLocale>
end_include
begin_constructor
DECL|function|CurrencyWidget
name|CurrencyWidget
operator|::
name|CurrencyWidget
parameter_list|()
block|{
name|QGridLayout
modifier|*
name|l
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|currencySymbolLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Symbol:"
argument_list|)
expr_stmt|;
name|currencySymbol
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|currencyISOLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"ISO Code:"
argument_list|)
expr_stmt|;
name|currencyISO
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|currencyNameLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Display name:"
argument_list|)
expr_stmt|;
name|currencyName
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|currencyFormattingLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Currency formatting:"
argument_list|)
expr_stmt|;
name|currencyFormattingValue
operator|=
operator|new
name|QLineEdit
argument_list|(
name|QString
operator|::
name|number
argument_list|(
literal|1234.56
argument_list|,
literal|'f'
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|currencyFormattingSymbolLabel
operator|=
operator|new
name|QLabel
argument_list|(
literal|"currency:"
argument_list|)
expr_stmt|;
name|currencyFormattingSymbol
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|currencyFormatting
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|currencyFormattingValue
operator|->
name|setFixedWidth
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|currencyFormattingSymbol
operator|->
name|setFixedWidth
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencySymbolLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencySymbol
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyISOLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyISO
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyNameLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyName
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyFormattingLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyFormattingValue
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyFormattingSymbolLabel
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyFormattingSymbol
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|currencyFormatting
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|v
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|v
operator|->
name|addLayout
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|v
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|currencyFormattingSymbol
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateCurrencyFormatting
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currencyFormattingValue
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateCurrencyFormatting
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|updateCurrencyFormatting
name|void
name|CurrencyWidget
operator|::
name|updateCurrencyFormatting
parameter_list|()
block|{
name|QString
name|result
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|QString
name|symbol
init|=
name|currencyFormattingSymbol
operator|->
name|text
argument_list|()
decl_stmt|;
name|QString
name|value
init|=
name|currencyFormattingValue
operator|->
name|text
argument_list|()
decl_stmt|;
name|int
name|i
init|=
name|value
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|result
operator|=
name|locale
argument_list|()
operator|.
name|toCurrencyString
argument_list|(
name|i
argument_list|,
name|symbol
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|double
name|d
init|=
name|value
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|result
operator|=
name|locale
argument_list|()
operator|.
name|toCurrencyString
argument_list|(
name|d
argument_list|,
name|symbol
argument_list|)
expr_stmt|;
block|}
name|currencyFormatting
operator|->
name|setText
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localeChanged
name|void
name|CurrencyWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|setLocale
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|currencySymbol
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|currencySymbol
argument_list|()
argument_list|)
expr_stmt|;
name|currencyISO
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|currencySymbol
argument_list|(
name|QLocale
operator|::
name|CurrencyIsoCode
argument_list|)
argument_list|)
expr_stmt|;
name|currencyName
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|currencySymbol
argument_list|(
name|QLocale
operator|::
name|CurrencyDisplayName
argument_list|)
argument_list|)
expr_stmt|;
name|updateCurrencyFormatting
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
