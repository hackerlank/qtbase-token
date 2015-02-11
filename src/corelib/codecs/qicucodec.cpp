begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qicucodec_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_include
include|#
directive|include
file|"qtextcodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qutfcodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qlatincodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qtsciicodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qisciicodec_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qcoreglobaldata_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"unicode/ucnv.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|TextCodecListConstIt
typedef|typedef
name|QList
argument_list|<
name|QTextCodec
modifier|*
argument_list|>
operator|::
name|ConstIterator
name|TextCodecListConstIt
typedef|;
end_typedef
begin_typedef
DECL|typedef|ByteArrayListConstIt
typedef|typedef
name|QList
argument_list|<
name|QByteArray
argument_list|>
operator|::
name|ConstIterator
name|ByteArrayListConstIt
typedef|;
end_typedef
begin_function
DECL|function|qIcuCodecStateFree
specifier|static
name|void
name|qIcuCodecStateFree
parameter_list|(
name|QTextCodec
operator|::
name|ConverterState
modifier|*
name|state
parameter_list|)
block|{
name|ucnv_close
argument_list|(
cast|static_cast
argument_list|<
name|UConverter
operator|*
argument_list|>
argument_list|(
name|state
operator|->
name|d
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qTextCodecNameMatch
name|bool
name|qTextCodecNameMatch
parameter_list|(
specifier|const
name|char
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|h
parameter_list|)
block|{
return|return
name|ucnv_compareNames
argument_list|(
name|n
argument_list|,
name|h
argument_list|)
operator|==
literal|0
return|;
block|}
end_function
begin_comment
comment|/* The list below is generated from http://www.iana.org/assignments/character-sets/    using the snippet of code below:  #include<QtCore> #include<unicode/ucnv.h>  int main(int argc, char **argv) {     QCoreApplication app(argc, argv);      QFile file("character-sets.txt");     file.open(QFile::ReadOnly);     QByteArray name;     int mib = -1;     QByteArray nameList;     int pos = 0;     while (!file.atEnd()) {         QByteArray s = file.readLine().trimmed();         if (s.isEmpty()) {             if (mib != -1) {                 UErrorCode error = U_ZERO_ERROR;                 const char *standard_name = ucnv_getStandardName(name, "MIME",&error);                 if (U_FAILURE(error) || !standard_name) {                     error = U_ZERO_ERROR;                     standard_name = ucnv_getStandardName(name, "IANA",&error);                 }                 UConverter *conv = ucnv_open(standard_name,&error);                 if (!U_FAILURE(error)&& conv&& standard_name) {                     ucnv_close(conv);                     printf("    { %d, %d },\n", mib, pos);                     nameList += "\"";                     nameList += standard_name;                     nameList += "\\0\"\n";                     pos += strlen(standard_name) + 1;                 }             }             name = QByteArray();             mib = -1;         }         if (s.startsWith("Name: ")) {             name = s.mid(5).trimmed();             if (name.indexOf(' ')> 0)                 name = name.left(name.indexOf(' '));         }         if (s.startsWith("MIBenum:"))             mib = s.mid(8).trimmed().toInt();         if (s.startsWith("Alias:")&& s.contains("MIME")) {             name = s.mid(6).trimmed();             name = name.left(name.indexOf(' ')).trimmed();         }     }     qDebug()<< nameList; } */
end_comment
begin_struct
DECL|struct|MibToName
struct|struct
name|MibToName
block|{
DECL|member|mib
name|short
name|mib
decl_stmt|;
DECL|member|index
name|short
name|index
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|mibToName
specifier|static
name|MibToName
name|mibToName
index|[]
init|=
block|{
block|{
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|4
block|,
literal|9
block|}
block|,
block|{
literal|5
block|,
literal|20
block|}
block|,
block|{
literal|6
block|,
literal|31
block|}
block|,
block|{
literal|7
block|,
literal|42
block|}
block|,
block|{
literal|8
block|,
literal|53
block|}
block|,
block|{
literal|9
block|,
literal|64
block|}
block|,
block|{
literal|10
block|,
literal|75
block|}
block|,
block|{
literal|11
block|,
literal|86
block|}
block|,
block|{
literal|12
block|,
literal|97
block|}
block|,
block|{
literal|13
block|,
literal|108
block|}
block|,
block|{
literal|16
block|,
literal|120
block|}
block|,
block|{
literal|17
block|,
literal|134
block|}
block|,
block|{
literal|18
block|,
literal|144
block|}
block|,
block|{
literal|30
block|,
literal|151
block|}
block|,
block|{
literal|36
block|,
literal|160
block|}
block|,
block|{
literal|37
block|,
literal|167
block|}
block|,
block|{
literal|38
block|,
literal|179
block|}
block|,
block|{
literal|39
block|,
literal|186
block|}
block|,
block|{
literal|40
block|,
literal|198
block|}
block|,
block|{
literal|57
block|,
literal|212
block|}
block|,
block|{
literal|81
block|,
literal|223
block|}
block|,
block|{
literal|82
block|,
literal|234
block|}
block|,
block|{
literal|84
block|,
literal|245
block|}
block|,
block|{
literal|85
block|,
literal|256
block|}
block|,
block|{
literal|104
block|,
literal|267
block|}
block|,
block|{
literal|105
block|,
literal|279
block|}
block|,
block|{
literal|106
block|,
literal|295
block|}
block|,
block|{
literal|109
block|,
literal|301
block|}
block|,
block|{
literal|110
block|,
literal|313
block|}
block|,
block|{
literal|111
block|,
literal|325
block|}
block|,
block|{
literal|113
block|,
literal|337
block|}
block|,
block|{
literal|114
block|,
literal|341
block|}
block|,
block|{
literal|1000
block|,
literal|349
block|}
block|,
block|{
literal|1001
block|,
literal|356
block|}
block|,
block|{
literal|1011
block|,
literal|363
block|}
block|,
block|{
literal|1012
block|,
literal|368
block|}
block|,
block|{
literal|1013
block|,
literal|374
block|}
block|,
block|{
literal|1014
block|,
literal|383
block|}
block|,
block|{
literal|1015
block|,
literal|392
block|}
block|,
block|{
literal|1016
block|,
literal|399
block|}
block|,
block|{
literal|1017
block|,
literal|406
block|}
block|,
block|{
literal|1018
block|,
literal|413
block|}
block|,
block|{
literal|1019
block|,
literal|422
block|}
block|,
block|{
literal|1020
block|,
literal|431
block|}
block|,
block|{
literal|2004
block|,
literal|438
block|}
block|,
block|{
literal|2005
block|,
literal|448
block|}
block|,
block|{
literal|2009
block|,
literal|472
block|}
block|,
block|{
literal|2013
block|,
literal|479
block|}
block|,
block|{
literal|2016
block|,
literal|486
block|}
block|,
block|{
literal|2024
block|,
literal|495
block|}
block|,
block|{
literal|2025
block|,
literal|505
block|}
block|,
block|{
literal|2026
block|,
literal|512
block|}
block|,
block|{
literal|2027
block|,
literal|517
block|}
block|,
block|{
literal|2028
block|,
literal|527
block|}
block|,
block|{
literal|2030
block|,
literal|534
block|}
block|,
block|{
literal|2033
block|,
literal|541
block|}
block|,
block|{
literal|2034
block|,
literal|548
block|}
block|,
block|{
literal|2035
block|,
literal|555
block|}
block|,
block|{
literal|2037
block|,
literal|562
block|}
block|,
block|{
literal|2038
block|,
literal|569
block|}
block|,
block|{
literal|2039
block|,
literal|576
block|}
block|,
block|{
literal|2040
block|,
literal|583
block|}
block|,
block|{
literal|2041
block|,
literal|590
block|}
block|,
block|{
literal|2043
block|,
literal|597
block|}
block|,
block|{
literal|2011
block|,
literal|604
block|}
block|,
block|{
literal|2044
block|,
literal|611
block|}
block|,
block|{
literal|2045
block|,
literal|618
block|}
block|,
block|{
literal|2010
block|,
literal|624
block|}
block|,
block|{
literal|2046
block|,
literal|631
block|}
block|,
block|{
literal|2047
block|,
literal|638
block|}
block|,
block|{
literal|2048
block|,
literal|645
block|}
block|,
block|{
literal|2049
block|,
literal|652
block|}
block|,
block|{
literal|2050
block|,
literal|659
block|}
block|,
block|{
literal|2051
block|,
literal|666
block|}
block|,
block|{
literal|2052
block|,
literal|673
block|}
block|,
block|{
literal|2053
block|,
literal|680
block|}
block|,
block|{
literal|2054
block|,
literal|687
block|}
block|,
block|{
literal|2055
block|,
literal|694
block|}
block|,
block|{
literal|2056
block|,
literal|701
block|}
block|,
block|{
literal|2062
block|,
literal|708
block|}
block|,
block|{
literal|2063
block|,
literal|715
block|}
block|,
block|{
literal|2084
block|,
literal|723
block|}
block|,
block|{
literal|2085
block|,
literal|730
block|}
block|,
block|{
literal|2086
block|,
literal|741
block|}
block|,
block|{
literal|2087
block|,
literal|748
block|}
block|,
block|{
literal|2088
block|,
literal|755
block|}
block|,
block|{
literal|2089
block|,
literal|762
block|}
block|,
block|{
literal|2091
block|,
literal|771
block|}
block|,
block|{
literal|2092
block|,
literal|780
block|}
block|,
block|{
literal|2093
block|,
literal|789
block|}
block|,
block|{
literal|2094
block|,
literal|798
block|}
block|,
block|{
literal|2095
block|,
literal|807
block|}
block|,
block|{
literal|2096
block|,
literal|816
block|}
block|,
block|{
literal|2097
block|,
literal|825
block|}
block|,
block|{
literal|2098
block|,
literal|834
block|}
block|,
block|{
literal|2099
block|,
literal|843
block|}
block|,
block|{
literal|2100
block|,
literal|852
block|}
block|,
block|{
literal|2101
block|,
literal|861
block|}
block|,
block|{
literal|2102
block|,
literal|872
block|}
block|,
block|{
literal|2250
block|,
literal|880
block|}
block|,
block|{
literal|2251
block|,
literal|893
block|}
block|,
block|{
literal|2252
block|,
literal|906
block|}
block|,
block|{
literal|2253
block|,
literal|919
block|}
block|,
block|{
literal|2254
block|,
literal|932
block|}
block|,
block|{
literal|2255
block|,
literal|945
block|}
block|,
block|{
literal|2256
block|,
literal|958
block|}
block|,
block|{
literal|2257
block|,
literal|971
block|}
block|,
block|{
literal|2258
block|,
literal|984
block|}
block|,
block|{
literal|2259
block|,
literal|997
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mibToNameSize
name|int
name|mibToNameSize
init|=
sizeof|sizeof
argument_list|(
name|mibToName
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|MibToName
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mibToNameTable
specifier|static
specifier|const
name|char
name|mibToNameTable
index|[]
init|=
literal|"US-ASCII\0"
literal|"ISO-8859-1\0"
literal|"ISO-8859-2\0"
literal|"ISO-8859-3\0"
literal|"ISO-8859-4\0"
literal|"ISO-8859-5\0"
literal|"ISO-8859-6\0"
literal|"ISO-8859-7\0"
literal|"ISO-8859-8\0"
literal|"ISO-8859-9\0"
literal|"ISO-8859-10\0"
literal|"ISO-2022-JP-1\0"
literal|"Shift_JIS\0"
literal|"EUC-JP\0"
literal|"US-ASCII\0"
literal|"EUC-KR\0"
literal|"ISO-2022-KR\0"
literal|"EUC-KR\0"
literal|"ISO-2022-JP\0"
literal|"ISO-2022-JP-2\0"
literal|"GB_2312-80\0"
literal|"ISO-8859-6\0"
literal|"ISO-8859-6\0"
literal|"ISO-8859-8\0"
literal|"ISO-8859-8\0"
literal|"ISO-2022-CN\0"
literal|"ISO-2022-CN-EXT\0"
literal|"UTF-8\0"
literal|"ISO-8859-13\0"
literal|"ISO-8859-14\0"
literal|"ISO-8859-15\0"
literal|"GBK\0"
literal|"GB18030\0"
literal|"UTF-16\0"
literal|"UTF-32\0"
literal|"SCSU\0"
literal|"UTF-7\0"
literal|"UTF-16BE\0"
literal|"UTF-16LE\0"
literal|"UTF-16\0"
literal|"CESU-8\0"
literal|"UTF-32\0"
literal|"UTF-32BE\0"
literal|"UTF-32LE\0"
literal|"BOCU-1\0"
literal|"hp-roman8\0"
literal|"Adobe-Standard-Encoding\0"
literal|"IBM850\0"
literal|"IBM862\0"
literal|"IBM-Thai\0"
literal|"Shift_JIS\0"
literal|"GB2312\0"
literal|"Big5\0"
literal|"macintosh\0"
literal|"IBM037\0"
literal|"IBM273\0"
literal|"IBM277\0"
literal|"IBM278\0"
literal|"IBM280\0"
literal|"IBM284\0"
literal|"IBM285\0"
literal|"IBM290\0"
literal|"IBM297\0"
literal|"IBM420\0"
literal|"IBM424\0"
literal|"IBM437\0"
literal|"IBM500\0"
literal|"cp851\0"
literal|"IBM852\0"
literal|"IBM855\0"
literal|"IBM857\0"
literal|"IBM860\0"
literal|"IBM861\0"
literal|"IBM863\0"
literal|"IBM864\0"
literal|"IBM865\0"
literal|"IBM868\0"
literal|"IBM869\0"
literal|"IBM870\0"
literal|"IBM871\0"
literal|"IBM918\0"
literal|"IBM1026\0"
literal|"KOI8-R\0"
literal|"HZ-GB-2312\0"
literal|"IBM866\0"
literal|"IBM775\0"
literal|"KOI8-U\0"
literal|"IBM00858\0"
literal|"IBM01140\0"
literal|"IBM01141\0"
literal|"IBM01142\0"
literal|"IBM01143\0"
literal|"IBM01144\0"
literal|"IBM01145\0"
literal|"IBM01146\0"
literal|"IBM01147\0"
literal|"IBM01148\0"
literal|"IBM01149\0"
literal|"Big5-HKSCS\0"
literal|"IBM1047\0"
literal|"windows-1250\0"
literal|"windows-1251\0"
literal|"windows-1252\0"
literal|"windows-1253\0"
literal|"windows-1254\0"
literal|"windows-1255\0"
literal|"windows-1256\0"
literal|"windows-1257\0"
literal|"windows-1258\0"
literal|"TIS-620\0"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|loadQtCodec
specifier|static
name|QTextCodec
modifier|*
name|loadQtCodec
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-8"
argument_list|)
condition|)
return|return
operator|new
name|QUtf8Codec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-16"
argument_list|)
condition|)
return|return
operator|new
name|QUtf16Codec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"ISO-8859-1"
argument_list|)
condition|)
return|return
operator|new
name|QLatin1Codec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-16BE"
argument_list|)
condition|)
return|return
operator|new
name|QUtf16BECodec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-16LE"
argument_list|)
condition|)
return|return
operator|new
name|QUtf16LECodec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-32"
argument_list|)
condition|)
return|return
operator|new
name|QUtf32Codec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-32BE"
argument_list|)
condition|)
return|return
operator|new
name|QUtf32BECodec
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"UTF-32LE"
argument_list|)
condition|)
return|return
operator|new
name|QUtf32LECodec
return|;
ifndef|#
directive|ifndef
name|QT_NO_CODECS
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"TSCII"
argument_list|)
condition|)
return|return
operator|new
name|QTsciiCodec
return|;
if|if
condition|(
operator|!
name|qstrnicmp
argument_list|(
name|name
argument_list|,
literal|"iscii"
argument_list|,
literal|5
argument_list|)
condition|)
return|return
name|QIsciiCodec
operator|::
name|create
argument_list|(
name|name
argument_list|)
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/// \threadsafe
end_comment
begin_function
DECL|function|availableCodecs
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QIcuCodec
operator|::
name|availableCodecs
parameter_list|()
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|codecs
decl_stmt|;
name|int
name|n
init|=
name|ucnv_countAvailable
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|ucnv_getAvailableName
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
specifier|const
name|char
modifier|*
name|standardName
init|=
name|ucnv_getStandardName
argument_list|(
name|name
argument_list|,
literal|"MIME"
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
operator|||
operator|!
name|standardName
condition|)
block|{
name|error
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|standardName
operator|=
name|ucnv_getStandardName
argument_list|(
name|name
argument_list|,
literal|"IANA"
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
condition|)
continue|continue;
name|error
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|int
name|ac
init|=
name|ucnv_countAliases
argument_list|(
name|standardName
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
condition|)
continue|continue;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|ac
condition|;
operator|++
name|j
control|)
block|{
name|error
operator|=
name|U_ZERO_ERROR
expr_stmt|;
specifier|const
name|char
modifier|*
name|alias
init|=
name|ucnv_getAlias
argument_list|(
name|standardName
argument_list|,
name|j
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|error
argument_list|)
condition|)
continue|continue;
name|codecs
operator|+=
name|alias
expr_stmt|;
block|}
block|}
comment|// handled by Qt and not in ICU:
name|codecs
operator|+=
literal|"TSCII"
expr_stmt|;
return|return
name|codecs
return|;
block|}
end_function
begin_comment
comment|/// \threadsafe
end_comment
begin_function
DECL|function|availableMibs
name|QList
argument_list|<
name|int
argument_list|>
name|QIcuCodec
operator|::
name|availableMibs
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|mibs
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mibToNameSize
condition|;
operator|++
name|i
control|)
name|mibs
operator|+=
name|mibToName
index|[
name|i
index|]
operator|.
name|mib
expr_stmt|;
comment|// handled by Qt and not in ICU:
name|mibs
operator|+=
literal|2107
expr_stmt|;
comment|// TSCII
return|return
name|mibs
return|;
block|}
end_function
begin_function
DECL|function|defaultCodecUnlocked
name|QTextCodec
modifier|*
name|QIcuCodec
operator|::
name|defaultCodecUnlocked
parameter_list|()
block|{
name|QCoreGlobalData
modifier|*
name|globalData
init|=
name|QCoreGlobalData
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|globalData
condition|)
return|return
literal|0
return|;
name|QTextCodec
modifier|*
name|c
init|=
name|globalData
operator|->
name|codecForLocale
operator|.
name|loadAcquire
argument_list|()
decl_stmt|;
if|if
condition|(
name|c
condition|)
return|return
name|c
return|;
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALE_IS_UTF8
argument_list|)
specifier|const
name|char
modifier|*
name|name
init|=
literal|"UTF-8"
decl_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|name
init|=
name|ucnv_getDefaultName
argument_list|()
decl_stmt|;
endif|#
directive|endif
name|c
operator|=
name|codecForNameUnlocked
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|globalData
operator|->
name|codecForLocale
operator|.
name|storeRelease
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
name|c
return|;
block|}
end_function
begin_function
DECL|function|codecForNameUnlocked
name|QTextCodec
modifier|*
name|QIcuCodec
operator|::
name|codecForNameUnlocked
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
comment|// backwards compatibility with Qt 4.x
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"CP949"
argument_list|)
condition|)
name|name
operator|=
literal|"windows-949"
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"Apple Roman"
argument_list|)
condition|)
name|name
operator|=
literal|"macintosh"
expr_stmt|;
comment|// these are broken data in ICU 4.4, and can't be resolved even though they are aliases to tis-620
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"windows-874-2000"
argument_list|)
operator|||
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"windows-874"
argument_list|)
operator|||
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"MS874"
argument_list|)
operator|||
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"x-windows-874"
argument_list|)
operator|||
operator|!
name|qstrcmp
argument_list|(
name|name
argument_list|,
literal|"ISO 8859-11"
argument_list|)
condition|)
name|name
operator|=
literal|"TIS-620"
expr_stmt|;
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
comment|// MIME gives better default names
specifier|const
name|char
modifier|*
name|standardName
init|=
name|ucnv_getStandardName
argument_list|(
name|name
argument_list|,
literal|"MIME"
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
operator|||
operator|!
name|standardName
condition|)
block|{
name|error
operator|=
name|U_ZERO_ERROR
expr_stmt|;
name|standardName
operator|=
name|ucnv_getStandardName
argument_list|(
name|name
argument_list|,
literal|"IANA"
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
block|}
name|bool
name|qt_only
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
operator|||
operator|!
name|standardName
condition|)
block|{
name|standardName
operator|=
name|name
expr_stmt|;
name|qt_only
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
comment|// correct some issues where the ICU data set contains duplicated entries.
comment|// Where this happens it's because one data set is a subset of another. We
comment|// always use the larger data set.
if|if
condition|(
name|qstrcmp
argument_list|(
name|standardName
argument_list|,
literal|"GB2312"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|standardName
argument_list|,
literal|"GB_2312-80"
argument_list|)
operator|==
literal|0
condition|)
name|standardName
operator|=
literal|"GBK"
expr_stmt|;
elseif|else
if|if
condition|(
name|qstrcmp
argument_list|(
name|standardName
argument_list|,
literal|"KSC_5601"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|standardName
argument_list|,
literal|"EUC-KR"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|standardName
argument_list|,
literal|"cp1363"
argument_list|)
operator|==
literal|0
condition|)
name|standardName
operator|=
literal|"windows-949"
expr_stmt|;
block|}
name|QCoreGlobalData
modifier|*
name|globalData
init|=
name|QCoreGlobalData
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QTextCodecCache
modifier|*
name|cache
init|=
operator|&
name|globalData
operator|->
name|codecCache
decl_stmt|;
name|QTextCodec
modifier|*
name|codec
decl_stmt|;
if|if
condition|(
name|cache
condition|)
block|{
name|codec
operator|=
name|cache
operator|->
name|value
argument_list|(
name|standardName
argument_list|)
expr_stmt|;
if|if
condition|(
name|codec
condition|)
return|return
name|codec
return|;
block|}
for|for
control|(
name|TextCodecListConstIt
name|it
init|=
name|globalData
operator|->
name|allCodecs
operator|.
name|constBegin
argument_list|()
init|,
name|cend
init|=
name|globalData
operator|->
name|allCodecs
operator|.
name|constEnd
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
name|QTextCodec
modifier|*
name|cursor
init|=
operator|*
name|it
decl_stmt|;
if|if
condition|(
name|qTextCodecNameMatch
argument_list|(
name|cursor
operator|->
name|name
argument_list|()
argument_list|,
name|standardName
argument_list|)
condition|)
block|{
if|if
condition|(
name|cache
condition|)
name|cache
operator|->
name|insert
argument_list|(
name|standardName
argument_list|,
name|cursor
argument_list|)
expr_stmt|;
return|return
name|cursor
return|;
block|}
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|aliases
init|=
name|cursor
operator|->
name|aliases
argument_list|()
decl_stmt|;
for|for
control|(
name|ByteArrayListConstIt
name|ait
init|=
name|aliases
operator|.
name|constBegin
argument_list|()
init|,
name|acend
init|=
name|aliases
operator|.
name|constEnd
argument_list|()
init|;
name|ait
operator|!=
name|acend
condition|;
operator|++
name|ait
control|)
block|{
if|if
condition|(
name|qTextCodecNameMatch
argument_list|(
operator|*
name|ait
argument_list|,
name|standardName
argument_list|)
condition|)
block|{
if|if
condition|(
name|cache
condition|)
name|cache
operator|->
name|insert
argument_list|(
name|standardName
argument_list|,
name|cursor
argument_list|)
expr_stmt|;
return|return
name|cursor
return|;
block|}
block|}
block|}
name|QTextCodec
modifier|*
name|c
init|=
name|loadQtCodec
argument_list|(
name|standardName
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
condition|)
return|return
name|c
return|;
if|if
condition|(
name|qt_only
condition|)
return|return
literal|0
return|;
comment|// check whether there is really a converter for the name available.
name|UConverter
modifier|*
name|conv
init|=
name|ucnv_open
argument_list|(
name|standardName
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|conv
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"codecForName: ucnv_open failed"
operator|<<
name|standardName
operator|<<
name|u_errorName
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|//qDebug()<< "QIcuCodec: Standard name for "<< name<< "is"<< standardName;
name|ucnv_close
argument_list|(
name|conv
argument_list|)
expr_stmt|;
name|c
operator|=
operator|new
name|QIcuCodec
argument_list|(
name|standardName
argument_list|)
expr_stmt|;
if|if
condition|(
name|cache
condition|)
name|cache
operator|->
name|insert
argument_list|(
name|standardName
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
name|c
return|;
block|}
end_function
begin_function
DECL|function|codecForMibUnlocked
name|QTextCodec
modifier|*
name|QIcuCodec
operator|::
name|codecForMibUnlocked
parameter_list|(
name|int
name|mib
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mibToNameSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|mibToName
index|[
name|i
index|]
operator|.
name|mib
operator|==
name|mib
condition|)
return|return
name|codecForNameUnlocked
argument_list|(
name|mibToNameTable
operator|+
name|mibToName
index|[
name|i
index|]
operator|.
name|index
argument_list|)
return|;
block|}
if|if
condition|(
name|mib
operator|==
literal|2107
condition|)
return|return
name|codecForNameUnlocked
argument_list|(
literal|"TSCII"
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QIcuCodec
name|QIcuCodec
operator|::
name|QIcuCodec
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
member_init_list|:
name|m_name
argument_list|(
name|name
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QIcuCodec
name|QIcuCodec
operator|::
name|~
name|QIcuCodec
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getConverter
name|UConverter
modifier|*
name|QIcuCodec
operator|::
name|getConverter
parameter_list|(
name|QTextCodec
operator|::
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|UConverter
modifier|*
name|conv
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|state
condition|)
block|{
if|if
condition|(
operator|!
name|state
operator|->
name|d
condition|)
block|{
comment|// first time
name|state
operator|->
name|flags
operator||=
name|QTextCodec
operator|::
name|FreeFunction
expr_stmt|;
name|QTextCodecUnalignedPointer
operator|::
name|encode
argument_list|(
name|state
operator|->
name|state_data
argument_list|,
name|qIcuCodecStateFree
argument_list|)
expr_stmt|;
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|state
operator|->
name|d
operator|=
name|ucnv_open
argument_list|(
name|m_name
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
name|ucnv_setSubstChars
argument_list|(
cast|static_cast
argument_list|<
name|UConverter
operator|*
argument_list|>
argument_list|(
name|state
operator|->
name|d
argument_list|)
argument_list|,
name|state
operator|->
name|flags
operator|&
name|QTextCodec
operator|::
name|ConvertInvalidToNull
condition|?
literal|"\0"
else|:
literal|"?"
argument_list|,
literal|1
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"getConverter(state) ucnv_open failed"
operator|<<
name|m_name
operator|<<
name|u_errorName
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
name|conv
operator|=
cast|static_cast
argument_list|<
name|UConverter
operator|*
argument_list|>
argument_list|(
name|state
operator|->
name|d
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|conv
condition|)
block|{
comment|// stateless conversion
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|conv
operator|=
name|ucnv_open
argument_list|(
name|m_name
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
name|ucnv_setSubstChars
argument_list|(
name|conv
argument_list|,
literal|"?"
argument_list|,
literal|1
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|U_FAILURE
argument_list|(
name|error
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"getConverter(no state) ucnv_open failed"
operator|<<
name|m_name
operator|<<
name|u_errorName
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
return|return
name|conv
return|;
block|}
end_function
begin_function
DECL|function|convertToUnicode
name|QString
name|QIcuCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|QTextCodec
operator|::
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|UConverter
modifier|*
name|conv
init|=
name|getConverter
argument_list|(
name|state
argument_list|)
decl_stmt|;
name|QString
name|string
argument_list|(
name|length
operator|+
literal|2
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|chars
operator|+
name|length
decl_stmt|;
name|int
name|convertedChars
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|UChar
modifier|*
name|uc
init|=
operator|(
name|UChar
operator|*
operator|)
name|string
operator|.
name|data
argument_list|()
decl_stmt|;
name|UChar
modifier|*
name|ucEnd
init|=
name|uc
operator|+
name|string
operator|.
name|length
argument_list|()
decl_stmt|;
name|uc
operator|+=
name|convertedChars
expr_stmt|;
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|ucnv_toUnicode
argument_list|(
name|conv
argument_list|,
operator|&
name|uc
argument_list|,
name|ucEnd
argument_list|,
operator|&
name|chars
argument_list|,
name|end
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|error
argument_list|)
operator|&&
name|error
operator|!=
name|U_BUFFER_OVERFLOW_ERROR
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"convertToUnicode failed:"
operator|<<
name|u_errorName
argument_list|(
name|error
argument_list|)
expr_stmt|;
break|break;
block|}
name|convertedChars
operator|=
name|uc
operator|-
operator|(
name|UChar
operator|*
operator|)
name|string
operator|.
name|data
argument_list|()
expr_stmt|;
if|if
condition|(
name|chars
operator|>=
name|end
condition|)
break|break;
name|string
operator|.
name|resize
argument_list|(
name|string
operator|.
name|length
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
block|}
name|string
operator|.
name|resize
argument_list|(
name|convertedChars
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|state
condition|)
name|ucnv_close
argument_list|(
name|conv
argument_list|)
expr_stmt|;
return|return
name|string
return|;
block|}
end_function
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QIcuCodec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|unicode
parameter_list|,
name|int
name|length
parameter_list|,
name|QTextCodec
operator|::
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|UConverter
modifier|*
name|conv
init|=
name|getConverter
argument_list|(
name|state
argument_list|)
decl_stmt|;
name|int
name|requiredLength
init|=
name|UCNV_GET_MAX_BYTES_FOR_STRING
argument_list|(
name|length
argument_list|,
name|ucnv_getMaxCharSize
argument_list|(
name|conv
argument_list|)
argument_list|)
decl_stmt|;
name|QByteArray
name|string
argument_list|(
name|requiredLength
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
specifier|const
name|UChar
modifier|*
name|uc
init|=
operator|(
specifier|const
name|UChar
operator|*
operator|)
name|unicode
decl_stmt|;
specifier|const
name|UChar
modifier|*
name|end
init|=
name|uc
operator|+
name|length
decl_stmt|;
name|int
name|convertedChars
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|char
modifier|*
name|ch
init|=
operator|(
name|char
operator|*
operator|)
name|string
operator|.
name|data
argument_list|()
decl_stmt|;
name|char
modifier|*
name|chEnd
init|=
name|ch
operator|+
name|string
operator|.
name|length
argument_list|()
decl_stmt|;
name|ch
operator|+=
name|convertedChars
expr_stmt|;
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|ucnv_fromUnicode
argument_list|(
name|conv
argument_list|,
operator|&
name|ch
argument_list|,
name|chEnd
argument_list|,
operator|&
name|uc
argument_list|,
name|end
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|U_SUCCESS
argument_list|(
name|error
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"convertFromUnicode failed:"
operator|<<
name|u_errorName
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|convertedChars
operator|=
name|ch
operator|-
name|string
operator|.
name|data
argument_list|()
expr_stmt|;
if|if
condition|(
name|uc
operator|>=
name|end
condition|)
break|break;
name|string
operator|.
name|resize
argument_list|(
name|string
operator|.
name|length
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
block|}
name|string
operator|.
name|resize
argument_list|(
name|convertedChars
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|state
condition|)
name|ucnv_close
argument_list|(
name|conv
argument_list|)
expr_stmt|;
return|return
name|string
return|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QIcuCodec
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
end_function
begin_function
DECL|function|aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QIcuCodec
operator|::
name|aliases
parameter_list|()
specifier|const
block|{
name|UErrorCode
name|error
init|=
name|U_ZERO_ERROR
decl_stmt|;
name|int
name|n
init|=
name|ucnv_countAliases
argument_list|(
name|m_name
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|aliases
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|a
init|=
name|ucnv_getAlias
argument_list|(
name|m_name
argument_list|,
name|i
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
comment|// skip the canonical name
if|if
condition|(
operator|!
name|a
operator|||
operator|!
name|qstrcmp
argument_list|(
name|a
argument_list|,
name|m_name
argument_list|)
condition|)
continue|continue;
name|aliases
operator|+=
name|a
expr_stmt|;
block|}
return|return
name|aliases
return|;
block|}
end_function
begin_function
DECL|function|mibEnum
name|int
name|QIcuCodec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mibToNameSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|qTextCodecNameMatch
argument_list|(
name|m_name
argument_list|,
operator|(
name|mibToNameTable
operator|+
name|mibToName
index|[
name|i
index|]
operator|.
name|index
operator|)
argument_list|)
condition|)
return|return
name|mibToName
index|[
name|i
index|]
operator|.
name|mib
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
end_unit
