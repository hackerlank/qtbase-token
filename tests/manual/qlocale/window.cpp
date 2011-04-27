begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|localeCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|localeCombo
operator|->
name|addItem
argument_list|(
literal|"System"
argument_list|,
name|QLocale
operator|::
name|system
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QLocale
argument_list|>
name|locales
init|=
name|QLocale
operator|::
name|matchingLocales
argument_list|(
name|QLocale
operator|::
name|AnyLanguage
argument_list|,
name|QLocale
operator|::
name|AnyScript
argument_list|,
name|QLocale
operator|::
name|AnyCountry
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QLocale
modifier|&
name|locale
decl|,
name|locales
control|)
block|{
name|QString
name|label
init|=
name|QLocale
operator|::
name|languageToString
argument_list|(
name|locale
operator|.
name|language
argument_list|()
argument_list|)
decl_stmt|;
name|label
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|locale
operator|.
name|script
argument_list|()
operator|!=
name|QLocale
operator|::
name|AnyScript
condition|)
block|{
name|label
operator|+=
name|QLocale
operator|::
name|scriptToString
argument_list|(
name|locale
operator|.
name|script
argument_list|()
argument_list|)
expr_stmt|;
name|label
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
block|}
name|label
operator|+=
name|QLocale
operator|::
name|countryToString
argument_list|(
name|locale
operator|.
name|country
argument_list|()
argument_list|)
expr_stmt|;
name|localeCombo
operator|->
name|addItem
argument_list|(
name|label
argument_list|,
name|locale
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|localeCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tabWidget
operator|=
operator|new
name|QTabWidget
expr_stmt|;
name|info
operator|=
operator|new
name|InfoWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|info
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|calendar
operator|=
operator|new
name|CalendarWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|currency
operator|=
operator|new
name|CurrencyWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|currency
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|languages
operator|=
operator|new
name|LanguagesWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|languages
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|dateFormats
operator|=
operator|new
name|DateFormatsWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|dateFormats
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|numberFormats
operator|=
operator|new
name|NumberFormatsWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|numberFormats
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|miscellaneous
operator|=
operator|new
name|MiscWidget
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|miscellaneous
argument_list|,
name|SLOT
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|localeName
operator|=
operator|new
name|QLabel
argument_list|(
literal|"Locale: foo_BAR"
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|headerLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|headerLayout
operator|->
name|addWidget
argument_list|(
name|localeCombo
argument_list|)
expr_stmt|;
name|headerLayout
operator|->
name|addWidget
argument_list|(
name|localeName
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|central
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|central
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|info
argument_list|,
literal|"Info"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|calendar
argument_list|,
literal|"Calendar"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|currency
argument_list|,
literal|"Currency"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|languages
argument_list|,
literal|"Languages"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|dateFormats
argument_list|,
literal|"Date Formats"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|numberFormats
argument_list|,
literal|"Number Formats"
argument_list|)
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|miscellaneous
argument_list|,
literal|"Text"
argument_list|)
expr_stmt|;
name|localeCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|systemLocaleChanged
argument_list|()
expr_stmt|;
name|setCentralWidget
argument_list|(
name|central
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|systemLocaleChanged
name|void
name|Window
operator|::
name|systemLocaleChanged
parameter_list|()
block|{
name|QLocale
name|l
init|=
name|QLocale
operator|::
name|system
argument_list|()
decl_stmt|;
name|QString
name|lang
init|=
name|QLocale
operator|::
name|languageToString
argument_list|(
name|l
operator|.
name|language
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|script
init|=
name|QLocale
operator|::
name|scriptToString
argument_list|(
name|l
operator|.
name|script
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|country
init|=
name|QLocale
operator|::
name|countryToString
argument_list|(
name|l
operator|.
name|country
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|l
operator|.
name|script
argument_list|()
operator|!=
name|QLocale
operator|::
name|AnyScript
condition|)
name|localeCombo
operator|->
name|setItemText
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"System: %1-%2-%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|lang
argument_list|,
name|script
argument_list|,
name|country
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|localeCombo
operator|->
name|setItemText
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"System: %1-%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|lang
argument_list|,
name|country
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|localeChanged
argument_list|(
literal|0
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|localeChanged
name|void
name|Window
operator|::
name|localeChanged
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
name|QLocale
name|locale
init|=
name|localeCombo
operator|->
name|itemData
argument_list|(
name|idx
argument_list|)
operator|.
name|toLocale
argument_list|()
decl_stmt|;
name|localeName
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"Locale: %1 (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|locale
operator|.
name|bcp47Name
argument_list|()
argument_list|,
name|locale
operator|.
name|name
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|localeChanged
argument_list|(
name|locale
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|Window
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|LocaleChange
case|:
block|{
if|if
condition|(
name|localeCombo
operator|->
name|currentIndex
argument_list|()
operator|==
literal|0
condition|)
name|systemLocaleChanged
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
default|default:
break|break;
block|}
return|return
name|QMainWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
end_unit
