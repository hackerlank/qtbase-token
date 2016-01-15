begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlibraryinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestlog_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qxmltestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestresult_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|function|xmlMessageType2String
specifier|static
specifier|const
name|char
modifier|*
name|xmlMessageType2String
parameter_list|(
name|QAbstractTestLogger
operator|::
name|MessageTypes
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|Warn
case|:
return|return
literal|"warn"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QSystem
case|:
return|return
literal|"system"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QDebug
case|:
return|return
literal|"qdebug"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QInfo
case|:
return|return
literal|"qinfo"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QWarning
case|:
return|return
literal|"qwarn"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QFatal
case|:
return|return
literal|"qfatal"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Skip
case|:
return|return
literal|"skip"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Info
case|:
return|return
literal|"info"
return|;
block|}
return|return
literal|"??????"
return|;
block|}
DECL|function|xmlIncidentType2String
specifier|static
specifier|const
name|char
modifier|*
name|xmlIncidentType2String
parameter_list|(
name|QAbstractTestLogger
operator|::
name|IncidentTypes
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|Pass
case|:
return|return
literal|"pass"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|XFail
case|:
return|return
literal|"xfail"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Fail
case|:
return|return
literal|"fail"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|XPass
case|:
return|return
literal|"xpass"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|BlacklistedPass
case|:
return|return
literal|"bpass"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|BlacklistedFail
case|:
return|return
literal|"bfail"
return|;
block|}
return|return
literal|"??????"
return|;
block|}
block|}
end_namespace
begin_constructor
DECL|function|QXmlTestLogger
name|QXmlTestLogger
operator|::
name|QXmlTestLogger
parameter_list|(
name|XmlMode
name|mode
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
member_init_list|:
name|QAbstractTestLogger
argument_list|(
name|filename
argument_list|)
member_init_list|,
name|xmlmode
argument_list|(
name|mode
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QXmlTestLogger
name|QXmlTestLogger
operator|::
name|~
name|QXmlTestLogger
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|startLogging
name|void
name|QXmlTestLogger
operator|::
name|startLogging
parameter_list|()
block|{
name|QAbstractTestLogger
operator|::
name|startLogging
argument_list|()
expr_stmt|;
name|QTestCharBuffer
name|buf
decl_stmt|;
if|if
condition|(
name|xmlmode
operator|==
name|QXmlTestLogger
operator|::
name|Complete
condition|)
block|{
name|QTestCharBuffer
name|quotedTc
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedTc
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
literal|"<TestCase name=\"%s\">\n"
argument_list|,
name|quotedTc
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QTestCharBuffer
name|quotedBuild
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedBuild
argument_list|,
name|QLibraryInfo
operator|::
name|build
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<Environment>\n"
literal|"<QtVersion>%s</QtVersion>\n"
literal|"<QtBuild>%s</QtBuild>\n"
literal|"<QTestVersion>"
name|QTEST_VERSION_STR
literal|"</QTestVersion>\n"
literal|"</Environment>\n"
argument_list|,
name|qVersion
argument_list|()
argument_list|,
name|quotedBuild
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopLogging
name|void
name|QXmlTestLogger
operator|::
name|stopLogging
parameter_list|()
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<Duration msecs=\"%f\"/>\n"
argument_list|,
name|QTestLog
operator|::
name|msecsTotalTime
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|xmlmode
operator|==
name|QXmlTestLogger
operator|::
name|Complete
condition|)
block|{
name|outputString
argument_list|(
literal|"</TestCase>\n"
argument_list|)
expr_stmt|;
block|}
name|QAbstractTestLogger
operator|::
name|stopLogging
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enterTestFunction
name|void
name|QXmlTestLogger
operator|::
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTestCharBuffer
name|quotedFunction
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedFunction
argument_list|,
name|function
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<TestFunction name=\"%s\">\n"
argument_list|,
name|quotedFunction
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leaveTestFunction
name|void
name|QXmlTestLogger
operator|::
name|leaveTestFunction
parameter_list|()
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<Duration msecs=\"%f\"/>\n"
literal|"</TestFunction>\n"
argument_list|,
name|QTestLog
operator|::
name|msecsFunctionTime
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|function|isEmpty
specifier|inline
specifier|static
name|bool
name|isEmpty
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
operator|!
name|str
operator|||
operator|!
name|str
index|[
literal|0
index|]
return|;
block|}
DECL|function|incidentFormatString
specifier|static
specifier|const
name|char
modifier|*
name|incidentFormatString
parameter_list|(
name|bool
name|noDescription
parameter_list|,
name|bool
name|noTag
parameter_list|)
block|{
if|if
condition|(
name|noDescription
condition|)
block|{
if|if
condition|(
name|noTag
condition|)
return|return
literal|"<Incident type=\"%s\" file=\"%s\" line=\"%d\" />\n"
return|;
else|else
return|return
literal|"<Incident type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<DataTag><![CDATA[%s%s%s%s]]></DataTag>\n"
literal|"</Incident>\n"
return|;
block|}
else|else
block|{
if|if
condition|(
name|noTag
condition|)
return|return
literal|"<Incident type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<Description><![CDATA[%s%s%s%s]]></Description>\n"
literal|"</Incident>\n"
return|;
else|else
return|return
literal|"<Incident type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<DataTag><![CDATA[%s%s%s]]></DataTag>\n"
literal|"<Description><![CDATA[%s]]></Description>\n"
literal|"</Incident>\n"
return|;
block|}
block|}
DECL|function|benchmarkResultFormatString
specifier|static
specifier|const
name|char
modifier|*
name|benchmarkResultFormatString
parameter_list|()
block|{
return|return
literal|"<BenchmarkResult metric=\"%s\" tag=\"%s\" value=\"%s\" iterations=\"%d\" />\n"
return|;
block|}
DECL|function|messageFormatString
specifier|static
specifier|const
name|char
modifier|*
name|messageFormatString
parameter_list|(
name|bool
name|noDescription
parameter_list|,
name|bool
name|noTag
parameter_list|)
block|{
if|if
condition|(
name|noDescription
condition|)
block|{
if|if
condition|(
name|noTag
condition|)
return|return
literal|"<Message type=\"%s\" file=\"%s\" line=\"%d\" />\n"
return|;
else|else
return|return
literal|"<Message type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<DataTag><![CDATA[%s%s%s%s]]></DataTag>\n"
literal|"</Message>\n"
return|;
block|}
else|else
block|{
if|if
condition|(
name|noTag
condition|)
return|return
literal|"<Message type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<Description><![CDATA[%s%s%s%s]]></Description>\n"
literal|"</Message>\n"
return|;
else|else
return|return
literal|"<Message type=\"%s\" file=\"%s\" line=\"%d\">\n"
literal|"<DataTag><![CDATA[%s%s%s]]></DataTag>\n"
literal|"<Description><![CDATA[%s]]></Description>\n"
literal|"</Message>\n"
return|;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|addIncident
name|void
name|QXmlTestLogger
operator|::
name|addIncident
parameter_list|(
name|IncidentTypes
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
specifier|const
name|char
modifier|*
name|tag
init|=
name|QTestResult
operator|::
name|currentDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|gtag
init|=
name|QTestResult
operator|::
name|currentGlobalDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|filler
init|=
operator|(
name|tag
operator|&&
name|gtag
operator|)
condition|?
literal|":"
else|:
literal|""
decl_stmt|;
specifier|const
name|bool
name|notag
init|=
name|QTest
operator|::
name|isEmpty
argument_list|(
name|tag
argument_list|)
operator|&&
name|QTest
operator|::
name|isEmpty
argument_list|(
name|gtag
argument_list|)
decl_stmt|;
name|QTestCharBuffer
name|quotedFile
decl_stmt|;
name|QTestCharBuffer
name|cdataGtag
decl_stmt|;
name|QTestCharBuffer
name|cdataTag
decl_stmt|;
name|QTestCharBuffer
name|cdataDescription
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedFile
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataGtag
argument_list|,
name|gtag
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataTag
argument_list|,
name|tag
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataDescription
argument_list|,
name|description
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
name|QTest
operator|::
name|incidentFormatString
argument_list|(
name|QTest
operator|::
name|isEmpty
argument_list|(
name|description
argument_list|)
argument_list|,
name|notag
argument_list|)
argument_list|,
name|QTest
operator|::
name|xmlIncidentType2String
argument_list|(
name|type
argument_list|)
argument_list|,
name|quotedFile
operator|.
name|constData
argument_list|()
argument_list|,
name|line
argument_list|,
name|cdataGtag
operator|.
name|constData
argument_list|()
argument_list|,
name|filler
argument_list|,
name|cdataTag
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataDescription
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addBenchmarkResult
name|void
name|QXmlTestLogger
operator|::
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTestCharBuffer
name|quotedMetric
decl_stmt|;
name|QTestCharBuffer
name|quotedTag
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedMetric
argument_list|,
name|benchmarkMetricName
argument_list|(
name|result
operator|.
name|metric
argument_list|)
argument_list|)
expr_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedTag
argument_list|,
name|result
operator|.
name|context
operator|.
name|tag
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|valuePerIteration
init|=
name|qreal
argument_list|(
name|result
operator|.
name|value
argument_list|)
operator|/
name|qreal
argument_list|(
name|result
operator|.
name|iterations
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
name|QTest
operator|::
name|benchmarkResultFormatString
argument_list|()
argument_list|,
name|quotedMetric
operator|.
name|constData
argument_list|()
argument_list|,
name|quotedTag
operator|.
name|constData
argument_list|()
argument_list|,
name|QByteArray
operator|::
name|number
argument_list|(
name|valuePerIteration
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
comment|//no 64-bit qsnprintf support
name|result
operator|.
name|iterations
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addMessage
name|void
name|QXmlTestLogger
operator|::
name|addMessage
parameter_list|(
name|MessageTypes
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
specifier|const
name|char
modifier|*
name|tag
init|=
name|QTestResult
operator|::
name|currentDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|gtag
init|=
name|QTestResult
operator|::
name|currentGlobalDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|filler
init|=
operator|(
name|tag
operator|&&
name|gtag
operator|)
condition|?
literal|":"
else|:
literal|""
decl_stmt|;
specifier|const
name|bool
name|notag
init|=
name|QTest
operator|::
name|isEmpty
argument_list|(
name|tag
argument_list|)
operator|&&
name|QTest
operator|::
name|isEmpty
argument_list|(
name|gtag
argument_list|)
decl_stmt|;
name|QTestCharBuffer
name|quotedFile
decl_stmt|;
name|QTestCharBuffer
name|cdataGtag
decl_stmt|;
name|QTestCharBuffer
name|cdataTag
decl_stmt|;
name|QTestCharBuffer
name|cdataDescription
decl_stmt|;
name|xmlQuote
argument_list|(
operator|&
name|quotedFile
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataGtag
argument_list|,
name|gtag
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataTag
argument_list|,
name|tag
argument_list|)
expr_stmt|;
name|xmlCdata
argument_list|(
operator|&
name|cdataDescription
argument_list|,
name|message
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
name|QTest
operator|::
name|messageFormatString
argument_list|(
name|message
operator|.
name|isEmpty
argument_list|()
argument_list|,
name|notag
argument_list|)
argument_list|,
name|QTest
operator|::
name|xmlMessageType2String
argument_list|(
name|type
argument_list|)
argument_list|,
name|quotedFile
operator|.
name|constData
argument_list|()
argument_list|,
name|line
argument_list|,
name|cdataGtag
operator|.
name|constData
argument_list|()
argument_list|,
name|filler
argument_list|,
name|cdataTag
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataDescription
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Copy up to n characters from the src string into dest, escaping any special     XML characters as necessary so that dest is suitable for use in an XML     quoted attribute string. */
end_comment
begin_function
DECL|function|xmlQuote
name|int
name|QXmlTestLogger
operator|::
name|xmlQuote
parameter_list|(
name|QTestCharBuffer
modifier|*
name|destBuf
parameter_list|,
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|char
modifier|*
name|dest
init|=
name|destBuf
operator|->
name|data
argument_list|()
decl_stmt|;
operator|*
name|dest
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|src
condition|)
return|return
literal|0
return|;
name|char
modifier|*
name|begin
init|=
name|dest
decl_stmt|;
name|char
modifier|*
name|end
init|=
name|dest
operator|+
name|n
decl_stmt|;
while|while
condition|(
name|dest
operator|<
name|end
condition|)
block|{
switch|switch
condition|(
operator|*
name|src
condition|)
block|{
DECL|macro|MAP_ENTITY
define|#
directive|define
name|MAP_ENTITY
parameter_list|(
name|chr
parameter_list|,
name|ent
parameter_list|)
define|\
value|case chr:                                   \                 if (dest + sizeof(ent)< end) {         \                     strcpy(dest, ent);                  \                     dest += sizeof(ent) - 1;            \                 }                                       \                 else {                                  \                     *dest = 0;                          \                     return (dest+sizeof(ent)-begin);    \                 }                                       \                 ++src;                                  \                 break;
name|MAP_ENTITY
argument_list|(
literal|'>'
argument_list|,
literal|"&gt;"
argument_list|)
expr_stmt|;
name|MAP_ENTITY
argument_list|(
literal|'<'
argument_list|,
literal|"&lt;"
argument_list|)
expr_stmt|;
name|MAP_ENTITY
argument_list|(
literal|'\''
argument_list|,
literal|"&apos;"
argument_list|)
expr_stmt|;
name|MAP_ENTITY
argument_list|(
literal|'"'
argument_list|,
literal|"&quot;"
argument_list|)
expr_stmt|;
name|MAP_ENTITY
argument_list|(
literal|'&'
argument_list|,
literal|"&amp;"
argument_list|)
expr_stmt|;
comment|// not strictly necessary, but allows handling of comments without
comment|// having to explicitly look for `--'
name|MAP_ENTITY
argument_list|(
literal|'-'
argument_list|,
literal|"&#x002D;"
argument_list|)
expr_stmt|;
DECL|macro|MAP_ENTITY
undef|#
directive|undef
name|MAP_ENTITY
case|case
literal|0
case|:
operator|*
name|dest
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|dest
operator|-
name|begin
operator|)
return|;
default|default:
operator|*
name|dest
operator|=
operator|*
name|src
expr_stmt|;
operator|++
name|dest
expr_stmt|;
operator|++
name|src
expr_stmt|;
break|break;
block|}
block|}
comment|// If we get here, dest was completely filled (dest == end)
operator|*
operator|(
name|dest
operator|-
literal|1
operator|)
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|dest
operator|-
name|begin
operator|)
return|;
block|}
end_function
begin_comment
comment|/*     Copy up to n characters from the src string into dest, escaping any     special strings such that dest is suitable for use in an XML CDATA section. */
end_comment
begin_function
DECL|function|xmlCdata
name|int
name|QXmlTestLogger
operator|::
name|xmlCdata
parameter_list|(
name|QTestCharBuffer
modifier|*
name|destBuf
parameter_list|,
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
operator|!
name|n
condition|)
return|return
literal|0
return|;
name|char
modifier|*
name|dest
init|=
name|destBuf
operator|->
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|src
operator|||
name|n
operator|==
literal|1
condition|)
block|{
operator|*
name|dest
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|static
name|char
specifier|const
name|CDATA_END
index|[]
init|=
literal|"]]>"
decl_stmt|;
specifier|static
name|char
specifier|const
name|CDATA_END_ESCAPED
index|[]
init|=
literal|"]]]><![CDATA[]>"
decl_stmt|;
name|char
modifier|*
name|begin
init|=
name|dest
decl_stmt|;
name|char
modifier|*
name|end
init|=
name|dest
operator|+
name|n
decl_stmt|;
while|while
condition|(
name|dest
operator|<
name|end
condition|)
block|{
if|if
condition|(
operator|!
operator|*
name|src
condition|)
block|{
operator|*
name|dest
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|dest
operator|-
name|begin
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|src
argument_list|,
name|CDATA_END
argument_list|,
sizeof|sizeof
argument_list|(
name|CDATA_END
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
name|dest
operator|+
sizeof|sizeof
argument_list|(
name|CDATA_END_ESCAPED
argument_list|)
operator|<
name|end
condition|)
block|{
name|strcpy
argument_list|(
name|dest
argument_list|,
name|CDATA_END_ESCAPED
argument_list|)
expr_stmt|;
name|src
operator|+=
sizeof|sizeof
argument_list|(
name|CDATA_END
argument_list|)
operator|-
literal|1
expr_stmt|;
name|dest
operator|+=
sizeof|sizeof
argument_list|(
name|CDATA_END_ESCAPED
argument_list|)
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
operator|*
name|dest
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|dest
operator|+
sizeof|sizeof
argument_list|(
name|CDATA_END_ESCAPED
argument_list|)
operator|-
name|begin
operator|)
return|;
block|}
continue|continue;
block|}
operator|*
name|dest
operator|=
operator|*
name|src
expr_stmt|;
operator|++
name|src
expr_stmt|;
operator|++
name|dest
expr_stmt|;
block|}
comment|// If we get here, dest was completely filled (dest == end)
operator|*
operator|(
name|dest
operator|-
literal|1
operator|)
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|dest
operator|-
name|begin
operator|)
return|;
block|}
end_function
begin_typedef
DECL|typedef|StringFormatFunction
typedef|typedef
name|int
function_decl|(
modifier|*
name|StringFormatFunction
function_decl|)
parameter_list|(
name|QTestCharBuffer
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*     A wrapper for string functions written to work with a fixed size buffer so they can be called     with a dynamically allocated buffer. */
end_comment
begin_function
DECL|function|allocateStringFn
name|int
name|allocateStringFn
parameter_list|(
name|QTestCharBuffer
modifier|*
name|str
parameter_list|,
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|StringFormatFunction
name|func
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|MAXSIZE
init|=
literal|1024
operator|*
literal|1024
operator|*
literal|2
decl_stmt|;
name|int
name|size
init|=
name|str
operator|->
name|size
argument_list|()
decl_stmt|;
name|int
name|res
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|res
operator|=
name|func
argument_list|(
name|str
argument_list|,
name|src
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|str
operator|->
name|data
argument_list|()
index|[
name|size
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|res
operator|<
name|size
condition|)
block|{
comment|// We succeeded or fatally failed
break|break;
block|}
comment|// buffer wasn't big enough, try again
name|size
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|size
operator|>
name|MAXSIZE
condition|)
block|{
break|break;
block|}
if|if
condition|(
operator|!
name|str
operator|->
name|reset
argument_list|(
name|size
argument_list|)
condition|)
break|break;
comment|// ran out of memory - bye
block|}
return|return
name|res
return|;
block|}
end_function
begin_function
DECL|function|xmlQuote
name|int
name|QXmlTestLogger
operator|::
name|xmlQuote
parameter_list|(
name|QTestCharBuffer
modifier|*
name|str
parameter_list|,
name|char
specifier|const
modifier|*
name|src
parameter_list|)
block|{
return|return
name|allocateStringFn
argument_list|(
name|str
argument_list|,
name|src
argument_list|,
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|xmlCdata
name|int
name|QXmlTestLogger
operator|::
name|xmlCdata
parameter_list|(
name|QTestCharBuffer
modifier|*
name|str
parameter_list|,
name|char
specifier|const
modifier|*
name|src
parameter_list|)
block|{
return|return
name|allocateStringFn
argument_list|(
name|str
argument_list|,
name|src
argument_list|,
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
