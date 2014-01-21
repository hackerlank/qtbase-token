begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PARSE_DEFINES_H
end_ifndef
begin_define
DECL|macro|PARSE_DEFINES_H
define|#
directive|define
name|PARSE_DEFINES_H
end_define
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_comment
comment|// this is intentionally ugly to test moc's preprocessing capabilities
end_comment
begin_define
DECL|macro|PD_NAMESPACE
define|#
directive|define
name|PD_NAMESPACE
value|PD
end_define
begin_define
DECL|macro|PD_BEGIN_NAMESPACE
define|#
directive|define
name|PD_BEGIN_NAMESPACE
value|namespace PD_NAMESPACE {
end_define
begin_define
DECL|macro|PD_END_NAMESPACE
define|#
directive|define
name|PD_END_NAMESPACE
value|}
end_define
begin_define
DECL|macro|PD_VOIDFUNCTION
define|#
directive|define
name|PD_VOIDFUNCTION
parameter_list|()
value|voidFunction()
end_define
begin_define
DECL|macro|PD_CLASSNAME
define|#
directive|define
name|PD_CLASSNAME
value|ParseDefine
end_define
begin_define
DECL|macro|PD_STRINGIFY
define|#
directive|define
name|PD_STRINGIFY
parameter_list|(
name|a
parameter_list|)
value|#a
end_define
begin_define
DECL|macro|PD_XSTRINGIFY
define|#
directive|define
name|PD_XSTRINGIFY
parameter_list|(
name|a
parameter_list|)
value|PD_STRINGIFY(a)
end_define
begin_define
DECL|macro|PD_SCOPED_STRING
define|#
directive|define
name|PD_SCOPED_STRING
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|PD_STRINGIFY(a) "::" PD_STRINGIFY(b)
end_define
begin_define
DECL|macro|PD_DEFINE1
define|#
directive|define
name|PD_DEFINE1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define
begin_define
DECL|macro|PD_DEFINE2
define|#
directive|define
name|PD_DEFINE2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a comb##b
end_define
begin_define
DECL|macro|PD_DEFINE3
define|#
directive|define
name|PD_DEFINE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a b##ined3()
end_define
begin_define
DECL|macro|PD_COMBINE
define|#
directive|define
name|PD_COMBINE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a b
end_define
begin_define
DECL|macro|PD_TEST_IDENTIFIER_ARG
define|#
directive|define
name|PD_TEST_IDENTIFIER_ARG
parameter_list|(
define|if, while) if while
end_define
begin_define
DECL|macro|QString
define|#
directive|define
name|QString
parameter_list|()
value|error_type
end_define
begin_define
DECL|macro|PD_CLASSINFO
define|#
directive|define
name|PD_CLASSINFO
value|Q_CLASSINFO
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_VARIADIC_MACROS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_MOC_RUN
argument_list|)
end_if
begin_define
DECL|macro|PD_VARARG
define|#
directive|define
name|PD_VARARG
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|x(__VA_ARGS__)
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_MOC_RUN
argument_list|)
end_if
begin_comment
comment|//GCC extension for variadic macros
end_comment
begin_define
DECL|macro|PD_VARARGEXT
define|#
directive|define
name|PD_VARARGEXT
parameter_list|(
name|x
parameter_list|,
name|y
modifier|...
parameter_list|)
value|x(y)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PD_VARARGEXT
define|#
directive|define
name|PD_VARARGEXT
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|x(__VA_ARGS__)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|PD_ADD_SUFFIX
define|#
directive|define
name|PD_ADD_SUFFIX
parameter_list|(
name|x
parameter_list|)
value|PD_DEFINE1(x,_SUFFIX)
end_define
begin_define
DECL|macro|PD_DEFINE_ITSELF
define|#
directive|define
name|PD_DEFINE_ITSELF
value|PD_ADD_SUFFIX(PD_DEFINE_ITSELF)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_RUN
end_ifndef
begin_comment
comment|// macro defined on the command line (in tst_moc.pro)
end_comment
begin_define
DECL|macro|DEFINE_CMDLINE_EMPTY
define|#
directive|define
name|DEFINE_CMDLINE_EMPTY
end_define
begin_define
DECL|macro|DEFINE_CMDLINE_SIGNAL
define|#
directive|define
name|DEFINE_CMDLINE_SIGNAL
value|void cmdlineSignal(const QMap<int, int>&i)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|PD_BEGIN_NAMESPACE
name|class
name|DEFINE_CMDLINE_EMPTY
name|PD_CLASSNAME
name|DEFINE_CMDLINE_EMPTY
range|:
name|public
name|DEFINE_CMDLINE_EMPTY
name|QObject
name|DEFINE_CMDLINE_EMPTY
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"TestString"
argument_list|,
argument|PD_STRINGIFY(PD_CLASSNAME)
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"TestString2"
argument_list|,
argument|PD_XSTRINGIFY(PD_CLASSNAME)
argument_list|)
name|PD_CLASSINFO
argument_list|(
literal|"TestString3"
argument_list|,
literal|"TestValue"
argument_list|)
name|public
operator|:
name|PD_CLASSNAME
argument_list|()
block|{}
name|public
name|slots
operator|:
name|void
name|PD_VOIDFUNCTION
argument_list|()
block|{}
name|QString
name|stringMethod
argument_list|()
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|""
argument_list|)
return|;
block|}
name|void
name|PD_DEFINE1
argument_list|(
argument|comb
argument_list|,
argument|ined1()
argument_list|)
block|{}
name|PD_DEFINE2
argument_list|(
argument|void
argument_list|,
argument|ined2()
argument_list|)
block|{}
name|PD_DEFINE3
argument_list|(
argument|void
argument_list|,
argument|comb
argument_list|)
block|{}
name|PD_COMBINE
argument_list|(
argument|void combined4(int, int)
argument_list|,
argument|{}
argument_list|)
name|PD_COMBINE
argument_list|(
argument|void combined5() {
argument_list|,
argument|}
argument_list|)
name|PD_TEST_IDENTIFIER_ARG
argument_list|(
argument|void
argument_list|,
argument|combined6()
argument_list|)
block|{}
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_VARIADIC_MACROS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_MOC_RUN
argument_list|)
name|PD_VARARG
argument_list|(
argument|void vararg1
argument_list|)
block|{}
name|PD_VARARG
argument_list|(
argument|void vararg2
argument_list|,
argument|int
argument_list|)
block|{}
name|PD_VARARG
argument_list|(
argument|void vararg3
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
block|{}
name|PD_VARARGEXT
argument_list|(
argument|void vararg4
argument_list|)
block|{}
name|PD_VARARGEXT
argument_list|(
argument|void vararg5
argument_list|,
argument|int
argument_list|)
block|{}
name|PD_VARARGEXT
argument_list|(
argument|void vararg6
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
block|{}
else|#
directive|else
name|void
name|vararg1
argument_list|()
block|{}
name|void
name|vararg2
argument_list|(
argument|int
argument_list|)
block|{}
name|void
name|vararg3
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
block|{}
name|void
name|vararg4
argument_list|()
block|{}
name|void
name|vararg5
argument_list|(
argument|int
argument_list|)
block|{}
name|void
name|vararg6
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
block|{}
endif|#
directive|endif
DECL|macro|OUTERFUNCTION
define|#
directive|define
name|OUTERFUNCTION
parameter_list|(
name|x
parameter_list|)
value|x
DECL|macro|INNERFUNCTION
define|#
directive|define
name|INNERFUNCTION
parameter_list|(
name|x
parameter_list|)
value|OUTERFUNCTION(x)
DECL|macro|INNER
define|#
directive|define
name|INNER
value|INNERFUNCTION
name|void
name|INNERFUNCTION
argument_list|(
argument|INNERFUNCTION
argument_list|)
operator|(
name|int
operator|)
block|{}
name|void
name|OUTERFUNCTION
argument_list|(
argument|INNERFUNCTION
argument_list|)
operator|(
name|inner_expanded
argument_list|(
name|int
argument_list|)
operator|)
block|{}
name|void
name|expanded_method
name|OUTERFUNCTION
argument_list|(
argument|INNER
argument_list|)
operator|(
operator|(
name|int
operator|)
operator|)
block|{}
DECL|macro|INNERFUNCTION
undef|#
directive|undef
name|INNERFUNCTION
DECL|macro|cond1
define|#
directive|define
name|cond1
parameter_list|()
value|0x1
DECL|macro|cond2
define|#
directive|define
name|cond2
parameter_list|()
value|0x2
if|#
directive|if
operator|!
operator|(
name|cond1
argument_list|()
operator|&
name|cond2
argument_list|()
operator|)
name|void
name|conditionSlot
argument_list|()
block|{}
endif|#
directive|endif
name|void
name|PD_DEFINE_ITSELF
argument_list|(
argument|int
argument_list|)
block|{}
name|signals
operator|:
name|DEFINE_CMDLINE_SIGNAL
block|;  }
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|QString
undef|#
directive|undef
name|QString
end_undef
begin_macro
name|PD_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
