begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDEBUG_H
end_ifndef
begin_define
DECL|macro|QDEBUG_H
define|#
directive|define
name|QDEBUG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcontiguouscache.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QDebug
block|{
name|friend
name|class
name|QMessageLogger
decl_stmt|;
name|friend
name|class
name|QDebugStateSaverPrivate
decl_stmt|;
struct|struct
name|Stream
block|{
enum|enum
block|{
name|defaultVerbosity
init|=
literal|2
block|,
name|verbosityShift
init|=
literal|29
block|,
name|verbosityMask
init|=
literal|0x7
block|}
enum|;
name|Stream
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
operator|:
name|ts
argument_list|(
name|device
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|QtDebugMsg
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
name|false
argument_list|)
operator|,
name|flags
argument_list|(
argument|defaultVerbosity<< verbosityShift
argument_list|)
block|{}
name|Stream
argument_list|(
name|QString
operator|*
name|string
argument_list|)
operator|:
name|ts
argument_list|(
name|string
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|QtDebugMsg
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
name|false
argument_list|)
operator|,
name|flags
argument_list|(
argument|defaultVerbosity<< verbosityShift
argument_list|)
block|{}
name|Stream
argument_list|(
argument|QtMsgType t
argument_list|)
operator|:
name|ts
argument_list|(
operator|&
name|buffer
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
name|true
argument_list|)
operator|,
name|flags
argument_list|(
argument|defaultVerbosity<< verbosityShift
argument_list|)
block|{}
name|QTextStream
name|ts
expr_stmt|;
name|QString
name|buffer
decl_stmt|;
name|int
name|ref
decl_stmt|;
name|QtMsgType
name|type
decl_stmt|;
name|bool
name|space
decl_stmt|;
name|bool
name|message_output
decl_stmt|;
name|QMessageLogContext
name|context
decl_stmt|;
enum|enum
name|FormatFlag
block|{
comment|// Note: Bits 29..31 are reserved for the verbose level introduced in 5.6.
name|NoQuotes
init|=
literal|0x1
block|}
enum|;
comment|// ### Qt 6: unify with space, introduce own version member
name|bool
name|testFlag
argument_list|(
name|FormatFlag
name|flag
argument_list|)
decl|const
block|{
return|return
operator|(
name|context
operator|.
name|version
operator|>
literal|1
operator|)
condition|?
operator|(
name|flags
operator|&
name|flag
operator|)
else|:
name|false
return|;
block|}
name|void
name|setFlag
parameter_list|(
name|FormatFlag
name|flag
parameter_list|)
block|{
if|if
condition|(
name|context
operator|.
name|version
operator|>
literal|1
condition|)
block|{
name|flags
operator||=
name|flag
expr_stmt|;
block|}
block|}
name|void
name|unsetFlag
parameter_list|(
name|FormatFlag
name|flag
parameter_list|)
block|{
if|if
condition|(
name|context
operator|.
name|version
operator|>
literal|1
condition|)
block|{
name|flags
operator|&=
operator|~
name|flag
expr_stmt|;
block|}
block|}
name|int
name|verbosity
argument_list|()
specifier|const
block|{
return|return
name|context
operator|.
name|version
operator|>
literal|1
operator|?
operator|(
name|flags
operator|>>
name|verbosityShift
operator|)
operator|&
name|verbosityMask
operator|:
name|int
argument_list|(
name|Stream
operator|::
name|defaultVerbosity
argument_list|)
return|;
block|}
name|void
name|setVerbosity
parameter_list|(
name|int
name|v
parameter_list|)
block|{
if|if
condition|(
name|context
operator|.
name|version
operator|>
literal|1
condition|)
block|{
name|flags
operator|&=
operator|~
operator|(
name|verbosityMask
operator|<<
name|verbosityShift
operator|)
expr_stmt|;
name|flags
operator||=
operator|(
name|v
operator|&
name|verbosityMask
operator|)
operator|<<
name|verbosityShift
expr_stmt|;
block|}
block|}
comment|// added in 5.4
name|int
name|flags
decl_stmt|;
block|}
modifier|*
name|stream
struct|;
enum|enum
name|Latin1Content
block|{
name|ContainsBinary
init|=
literal|0
block|,
name|ContainsLatin1
block|}
enum|;
name|void
name|putUcs4
parameter_list|(
name|uint
name|ucs4
parameter_list|)
function_decl|;
name|void
name|putString
parameter_list|(
specifier|const
name|QChar
modifier|*
name|begin
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
name|void
name|putByteArray
parameter_list|(
specifier|const
name|char
modifier|*
name|begin
parameter_list|,
name|size_t
name|length
parameter_list|,
name|Latin1Content
name|content
parameter_list|)
function_decl|;
name|public
label|:
specifier|inline
name|QDebug
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(device)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
name|QString
operator|*
name|string
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(string)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
argument|QtMsgType t
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(t)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
specifier|const
name|QDebug
operator|&
name|o
argument_list|)
operator|:
name|stream
argument_list|(
argument|o.stream
argument_list|)
block|{
operator|++
name|stream
operator|->
name|ref
block|; }
specifier|inline
name|QDebug
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDebug
operator|&
name|other
operator|)
expr_stmt|;
operator|~
name|QDebug
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|swap
parameter_list|(
name|QDebug
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|stream
argument_list|,
name|other
operator|.
name|stream
argument_list|)
expr_stmt|;
block|}
name|QDebug
modifier|&
name|resetFormat
parameter_list|()
function_decl|;
specifier|inline
name|QDebug
modifier|&
name|space
parameter_list|()
block|{
name|stream
operator|->
name|space
operator|=
name|true
expr_stmt|;
name|stream
operator|->
name|ts
operator|<<
literal|' '
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|nospace
parameter_list|()
block|{
name|stream
operator|->
name|space
operator|=
name|false
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|maybeSpace
parameter_list|()
block|{
if|if
condition|(
name|stream
operator|->
name|space
condition|)
name|stream
operator|->
name|ts
operator|<<
literal|' '
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|int
name|verbosity
argument_list|()
specifier|const
block|{
return|return
name|stream
operator|->
name|verbosity
argument_list|()
return|;
block|}
name|void
name|setVerbosity
parameter_list|(
name|int
name|verbosityLevel
parameter_list|)
block|{
name|stream
operator|->
name|setVerbosity
argument_list|(
name|verbosityLevel
argument_list|)
expr_stmt|;
block|}
name|bool
name|autoInsertSpaces
argument_list|()
specifier|const
block|{
return|return
name|stream
operator|->
name|space
return|;
block|}
name|void
name|setAutoInsertSpaces
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|stream
operator|->
name|space
operator|=
name|b
expr_stmt|;
block|}
specifier|inline
name|QDebug
modifier|&
name|quote
parameter_list|()
block|{
name|stream
operator|->
name|unsetFlag
argument_list|(
name|Stream
operator|::
name|NoQuotes
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|noquote
parameter_list|()
block|{
name|stream
operator|->
name|setFlag
argument_list|(
name|Stream
operator|::
name|NoQuotes
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|maybeQuote
parameter_list|(
name|char
name|c
init|=
literal|'"'
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|stream
operator|->
name|testFlag
argument_list|(
name|Stream
operator|::
name|NoQuotes
argument_list|)
operator|)
condition|)
name|stream
operator|->
name|ts
operator|<<
name|c
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QChar
name|t
operator|)
block|{
name|putUcs4
argument_list|(
name|t
operator|.
name|unicode
argument_list|()
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|bool
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
operator|(
name|t
operator|?
literal|"true"
operator|:
literal|"false"
operator|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|char
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|short
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|short
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_UNICODE_STRINGS
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|char16_t
name|t
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|QChar
argument_list|(
name|t
argument_list|)
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|char32_t
name|t
operator|)
block|{
name|putUcs4
argument_list|(
name|t
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|int
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|int
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|long
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|qint64
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|quint64
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|float
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|double
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|t
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QString
operator|&
name|t
operator|)
block|{
name|putString
argument_list|(
name|t
operator|.
name|constData
argument_list|()
argument_list|,
name|uint
argument_list|(
name|t
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QStringRef
operator|&
name|t
operator|)
block|{
name|putString
argument_list|(
name|t
operator|.
name|constData
argument_list|()
argument_list|,
name|uint
argument_list|(
name|t
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QLatin1String
name|t
operator|)
block|{
name|putByteArray
argument_list|(
name|t
operator|.
name|latin1
argument_list|()
argument_list|,
name|t
operator|.
name|size
argument_list|()
argument_list|,
name|ContainsLatin1
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QByteArray
operator|&
name|t
operator|)
block|{
name|putByteArray
argument_list|(
name|t
operator|.
name|constData
argument_list|()
argument_list|,
name|t
operator|.
name|size
argument_list|()
argument_list|,
name|ContainsBinary
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_NULLPTR
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|nullptr_t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
literal|"(nullptr)"
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamFunction
name|f
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamManipulator
name|m
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|m
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QDebug
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QDebugStateSaverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDebugStateSaver
block|{
name|public
label|:
name|QDebugStateSaver
argument_list|(
name|QDebug
operator|&
name|dbg
argument_list|)
expr_stmt|;
operator|~
name|QDebugStateSaver
argument_list|()
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDebugStateSaver
argument_list|)
name|QScopedPointer
operator|<
name|QDebugStateSaverPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QNoDebug
block|{
name|public
label|:
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamFunction
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamManipulator
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|space
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|nospace
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|maybeSpace
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|quote
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|noquote
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|maybeQuote
parameter_list|(
specifier|const
name|char
init|=
literal|'"'
parameter_list|)
block|{
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QDebug
operator|&
name|QDebug
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QDebug
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|other
condition|)
block|{
name|QDebug
name|copy
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|qSwap
argument_list|(
name|stream
argument_list|,
name|copy
operator|.
name|stream
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QList
operator|<
name|T
operator|>
operator|&
name|list
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'('
block|;
for|for
control|(
name|typename
name|QList
operator|<
name|T
operator|>
operator|::
name|size_type
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
condition|)
name|debug
operator|<<
literal|", "
expr_stmt|;
name|debug
operator|<<
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|vec
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QVector"
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|operator
operator|<<
operator|(
name|debug
operator|,
name|vec
operator|.
name|toList
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|map
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QMap("
block|;
for|for
control|(
name|typename
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|map
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|map
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|debug
operator|<<
literal|'('
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|", "
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|')'
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|aKey
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QHash
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|hash
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QHash("
block|;
for|for
control|(
name|typename
name|QHash
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|hash
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|hash
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|debug
operator|<<
literal|'('
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|", "
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|')'
expr_stmt|;
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|T1
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|pair
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QPair("
operator|<<
name|pair
operator|.
name|first
operator|<<
literal|','
operator|<<
name|pair
operator|.
name|second
operator|<<
literal|')'
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|set
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSet"
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|operator
operator|<<
operator|(
name|debug
operator|,
name|set
operator|.
name|toList
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|cache
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QContiguousCache("
block|;
for|for
control|(
name|int
name|i
init|=
name|cache
operator|.
name|firstIndex
argument_list|()
init|;
name|i
operator|<=
name|cache
operator|.
name|lastIndex
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|debug
operator|<<
name|cache
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|cache
operator|.
name|lastIndex
argument_list|()
condition|)
name|debug
operator|<<
literal|", "
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_function_decl
unit|Q_CORE_EXPORT
name|QDebug
name|qt_QMetaEnum_debugOperator
parameter_list|(
name|QDebug
modifier|&
parameter_list|,
name|int
name|value
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|meta
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QDebug
name|qt_QMetaEnum_flagDebugOperator
parameter_list|(
name|QDebug
modifier|&
name|dbg
parameter_list|,
name|quint64
name|value
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|meta
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|member|Value
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|T
operator|>
operator|::
name|Value
operator|,
name|QDebug
operator|>
operator|::
name|Type
DECL|function|operator
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
name|T
name|value
operator|)
block|{
specifier|const
name|QMetaObject
operator|*
name|obj
operator|=
name|qt_getEnumMetaObject
argument_list|(
name|value
argument_list|)
block|;
specifier|const
name|char
operator|*
name|name
operator|=
name|qt_getEnumName
argument_list|(
name|value
argument_list|)
block|;
return|return
name|qt_QMetaEnum_debugOperator
argument_list|(
argument|dbg
argument_list|,
argument|typename QFlags<T>::Int(value)
argument_list|,
argument|obj
argument_list|,
argument|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
DECL|member|Value
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|T
operator|>
operator|::
name|Value
operator|||
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|QFlags
operator|<
name|T
operator|>
expr|>
operator|::
name|Value
operator|,
name|QDebug
operator|>
operator|::
name|Type
DECL|function|operator
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QFlags
operator|<
name|T
operator|>
operator|&
name|flags
operator|)
block|{
specifier|const
name|QMetaObject
operator|*
name|obj
operator|=
name|qt_getEnumMetaObject
argument_list|(
name|T
argument_list|()
argument_list|)
block|;
specifier|const
name|char
operator|*
name|name
operator|=
name|qt_getEnumName
argument_list|(
name|T
argument_list|()
argument_list|)
block|;
return|return
name|qt_QMetaEnum_flagDebugOperator
argument_list|(
name|debug
argument_list|,
name|quint64
argument_list|(
name|flags
argument_list|)
argument_list|,
name|obj
argument_list|,
name|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
DECL|member|Value
operator|!
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|T
operator|>
operator|::
name|Value
operator|&&
operator|!
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|QFlags
operator|<
name|T
operator|>
expr|>
operator|::
name|Value
operator|,
name|QDebug
operator|>
operator|::
name|Type
DECL|function|operator
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QFlags
operator|<
name|T
operator|>
operator|&
name|flags
operator|)
else|#
directive|else
comment|// !QT_NO_QOBJECT
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QFlags
operator|<
name|T
operator|>
operator|&
name|flags
operator|)
endif|#
directive|endif
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
block|;
name|debug
operator|.
name|resetFormat
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QFlags("
operator|<<
name|hex
operator|<<
name|showbase
block|;
name|bool
name|needSeparator
operator|=
name|false
block|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|flags
operator|.
name|testFlag
argument_list|(
name|T
argument_list|(
literal|1
operator|<<
name|i
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|needSeparator
condition|)
name|debug
operator|<<
literal|'|'
expr_stmt|;
else|else
name|needSeparator
operator|=
name|true
expr_stmt|;
name|debug
operator|<<
operator|(
name|typename
name|QFlags
operator|<
name|T
operator|>
operator|::
name|Int
argument_list|(
literal|1
argument_list|)
operator|<<
name|i
operator|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
return|;
end_return
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_comment
comment|// We provide QDebug stream operators for commonly used Core Foundation
end_comment
begin_comment
comment|// and Core Graphics types, as well as NSObject. Additional CF/CG types
end_comment
begin_comment
comment|// may be added by the user, using Q_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE.
end_comment
begin_define
DECL|macro|QT_FOR_EACH_CORE_FOUNDATION_TYPE
define|#
directive|define
name|QT_FOR_EACH_CORE_FOUNDATION_TYPE
parameter_list|(
name|F
parameter_list|)
define|\
value|F(CFArray) \     F(CFURL) \     F(CFData) \     F(CFNumber) \     F(CFDictionary) \     F(CFLocale) \     F(CFDate) \     F(CFBoolean) \     F(CFTimeZone) \  #define QT_FOR_EACH_MUTABLE_CORE_FOUNDATION_TYPE(F) \     F(CFError) \     F(CFBundle) \  #define QT_FOR_EACH_CORE_GRAPHICS_TYPE(F) \     F(CGPath) \  #define QT_FOR_EACH_MUTABLE_CORE_GRAPHICS_TYPE(F) \     F(CGColorSpace) \     F(CGImage) \     F(CGFont) \     F(CGColor) \  #define QT_FORWARD_DECLARE_CF_TYPE(type) Q_FORWARD_DECLARE_CF_TYPE(type);
end_define
begin_define
DECL|macro|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
define|#
directive|define
name|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
parameter_list|(
name|type
parameter_list|)
value|Q_FORWARD_DECLARE_MUTABLE_CF_TYPE(type);
end_define
begin_define
DECL|macro|QT_FORWARD_DECLARE_CG_TYPE
define|#
directive|define
name|QT_FORWARD_DECLARE_CG_TYPE
parameter_list|(
name|type
parameter_list|)
value|typedef const struct type *type ## Ref;
end_define
begin_define
DECL|macro|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
define|#
directive|define
name|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
parameter_list|(
name|type
parameter_list|)
value|typedef struct type *type ## Ref;
end_define
begin_expr_stmt
DECL|macro|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
unit|QT_END_NAMESPACE
name|Q_FORWARD_DECLARE_CF_TYPE
argument_list|(
name|CFString
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|NSObject
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSObject
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_CF_TYPE
name|QT_FOR_EACH_CORE_FOUNDATION_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
name|QT_FOR_EACH_MUTABLE_CORE_FOUNDATION_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_CG_TYPE
name|QT_FOR_EACH_CORE_GRAPHICS_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_CG_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
name|QT_FOR_EACH_MUTABLE_CORE_GRAPHICS_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
define|#
directive|define
name|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
parameter_list|(
name|CFType
parameter_list|)
define|\
value|Q_CORE_EXPORT QDebug operator<<(QDebug, CFType##Ref);
DECL|macro|Q_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
define|#
directive|define
name|Q_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
parameter_list|(
name|CFType
parameter_list|)
define|\
value|QDebug operator<<(QDebug debug, CFType##Ref ref) \     { \         if (!ref) \             return debug<< QT_STRINGIFY(CFType) "Ref(0x0)"; \         if (CFStringRef description = CFCopyDescription(ref)) { \             QDebugStateSaver saver(debug); \             debug.noquote()<< description; \             CFRelease(description); \         } \         return debug; \     }
comment|// Defined in qcore_mac_objc.mm
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|NSObject
operator|*
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
name|CFStringRef
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
name|QT_FOR_EACH_CORE_FOUNDATION_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
name|QT_FOR_EACH_MUTABLE_CORE_FOUNDATION_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
name|QT_FOR_EACH_CORE_GRAPHICS_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
name|QT_FOR_EACH_MUTABLE_CORE_GRAPHICS_TYPE
argument_list|(
name|QT_FORWARD_DECLARE_QDEBUG_OPERATOR_FOR_CF_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_undef
DECL|macro|QT_FORWARD_DECLARE_CF_TYPE
undef|#
directive|undef
name|QT_FORWARD_DECLARE_CF_TYPE
end_undef
begin_undef
DECL|macro|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
undef|#
directive|undef
name|QT_FORWARD_DECLARE_MUTABLE_CF_TYPE
end_undef
begin_undef
DECL|macro|QT_FORWARD_DECLARE_CG_TYPE
undef|#
directive|undef
name|QT_FORWARD_DECLARE_CG_TYPE
end_undef
begin_undef
DECL|macro|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
undef|#
directive|undef
name|QT_FORWARD_DECLARE_MUTABLE_CG_TYPE
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_MAC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDEBUG_H
end_comment
end_unit
