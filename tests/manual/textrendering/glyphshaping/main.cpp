begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_decl_stmt
DECL|variable|fontPixelSize
specifier|static
specifier|const
name|int
name|fontPixelSize
init|=
literal|25
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|fontFamily
argument_list|(
literal|"Series 60 Sans"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|testDataSet
struct|struct
name|testDataSet
block|{
DECL|member|language
name|QString
name|language
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|input
name|QString
name|input
decl_stmt|;
DECL|member|inputOriginal
name|QString
name|inputOriginal
decl_stmt|;
DECL|member|output
name|QString
name|output
decl_stmt|;
DECL|member|outputOriginal
name|QString
name|outputOriginal
decl_stmt|;
DECL|member|outputGlyphIDs
name|QVector
argument_list|<
name|uint
argument_list|>
name|outputGlyphIDs
decl_stmt|;
DECL|member|outputGlyphIDsOriginal
name|QString
name|outputGlyphIDsOriginal
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|charHexCsv2String
name|QString
name|charHexCsv2String
parameter_list|(
specifier|const
name|QString
modifier|&
name|csv
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|charString
decl|,
name|csv
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
control|)
block|{
name|bool
name|isOk
decl_stmt|;
specifier|const
name|uint
name|charUInt
init|=
name|charString
operator|.
name|toUInt
argument_list|(
operator|&
name|isOk
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|isOk
argument_list|)
expr_stmt|;
specifier|const
name|int
name|size
init|=
name|charUInt
operator|>=
name|SHRT_MAX
condition|?
literal|2
else|:
literal|1
decl_stmt|;
name|result
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromUtf16
argument_list|(
operator|(
specifier|const
name|ushort
operator|*
operator|)
operator|&
name|charUInt
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|testDataSetList
name|QList
argument_list|<
name|testDataSet
argument_list|>
name|testDataSetList
parameter_list|()
block|{
name|QList
argument_list|<
name|testDataSet
argument_list|>
name|result
decl_stmt|;
name|QFile
name|file
argument_list|(
literal|"glyphshaping_data.xml"
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|success
init|=
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|success
argument_list|)
expr_stmt|;
specifier|const
name|QLatin1String
name|language
argument_list|(
literal|"language"
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|test
argument_list|(
literal|"test"
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|inputUtf16
argument_list|(
literal|"inpututf16"
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|outputUtf16
argument_list|(
literal|"outpututf16"
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|outputGlyphIDs
argument_list|(
literal|"outputglyphids"
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|name
argument_list|(
literal|"name"
argument_list|)
decl_stmt|;
name|QString
name|languageName
decl_stmt|;
name|QXmlStreamReader
name|reader
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|reader
operator|.
name|atEnd
argument_list|()
condition|)
block|{
specifier|const
name|QXmlStreamReader
operator|::
name|TokenType
name|token
init|=
name|reader
operator|.
name|readNext
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|token
condition|)
block|{
case|case
name|QXmlStreamReader
operator|::
name|StartElement
case|:
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
name|language
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|languageName
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|name
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
name|test
condition|)
block|{
if|if
condition|(
operator|!
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|outputUtf16
argument_list|)
operator|&&
operator|!
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|outputGlyphIDs
argument_list|)
condition|)
continue|continue;
name|Q_ASSERT
argument_list|(
operator|!
name|languageName
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|inputUtf16
argument_list|)
argument_list|)
expr_stmt|;
name|testDataSet
name|set
decl_stmt|;
name|set
operator|.
name|language
operator|=
name|languageName
expr_stmt|;
name|set
operator|.
name|name
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|name
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|set
operator|.
name|inputOriginal
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|inputUtf16
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|set
operator|.
name|input
operator|=
name|charHexCsv2String
argument_list|(
name|set
operator|.
name|inputOriginal
argument_list|)
expr_stmt|;
name|set
operator|.
name|outputOriginal
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|outputUtf16
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|set
operator|.
name|output
operator|=
name|charHexCsv2String
argument_list|(
name|set
operator|.
name|outputOriginal
argument_list|)
expr_stmt|;
name|set
operator|.
name|outputGlyphIDsOriginal
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
name|outputGlyphIDs
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|result
operator|.
name|append
argument_list|(
name|set
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|renderedText
name|QImage
name|renderedText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
specifier|const
name|QFontMetrics
name|metrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|boundingRect
init|=
name|metrics
operator|.
name|boundingRect
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|QImage
name|result
argument_list|(
name|boundingRect
operator|.
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|result
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|boundingRect
operator|.
name|translated
argument_list|(
operator|-
name|boundingRect
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|,
name|text
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|dumpImageHtml
name|QString
name|dumpImageHtml
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|pathName
parameter_list|)
block|{
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"<td/>"
argument_list|)
return|;
name|QFont
name|font
argument_list|(
name|fontFamily
argument_list|)
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
name|fontPixelSize
argument_list|)
expr_stmt|;
specifier|const
name|QImage
name|textImage
init|=
name|renderedText
argument_list|(
name|text
argument_list|,
name|font
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|imageFileName
init|=
operator|(
name|pathName
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"%1.png"
argument_list|)
operator|)
operator|.
name|arg
argument_list|(
name|textImage
operator|.
name|cacheKey
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|success
init|=
name|textImage
operator|.
name|save
argument_list|(
name|imageFileName
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|success
argument_list|)
expr_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<td title=\"%2\"><img src=\"%1\" alt=\"%2\" width=\"%3\" height=\"%4\"/></td>"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|cleanPath
argument_list|(
name|imageFileName
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|text
argument_list|)
operator|.
name|arg
argument_list|(
name|textImage
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|textImage
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|dlItem
name|QString
name|dlItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|dt
parameter_list|,
specifier|const
name|QString
modifier|&
name|dd
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dd
operator|.
name|trimmed
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\t\t\t\t\t\t<dt>%1</dt><dd>%2</dd>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|dt
argument_list|)
operator|.
name|arg
argument_list|(
name|dd
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|dumpHtml
name|bool
name|dumpHtml
parameter_list|(
specifier|const
name|QString
modifier|&
name|pathName
parameter_list|)
block|{
name|QFile
name|htmlPage
argument_list|(
name|pathName
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"index.html"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|htmlPage
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
argument_list|)
condition|)
return|return
literal|false
return|;
name|QString
name|platformName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
literal|"Win32"
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
literal|"X11"
else|#
directive|else
literal|""
endif|#
directive|endif
argument_list|)
decl_stmt|;
name|QString
name|result
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n"
literal|" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n\n"
literal|"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">\n"
literal|"\t<head>\n"
literal|"\t\t<title>Qt on %1 glyph shaping (%2)</title>\n"
literal|"\t\t<meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\" />\n"
literal|"\t\t<style type=\"text/css\" media=\"screen\">\n"
literal|"\t\t\ttable { font-family: Arial; background-color: #ccccff; font-size: 12pt; }\n"
literal|"\t\t\ttd { font-family:\"%2\"; background-color: #eeeeee; font-size: %3px; }\n"
literal|"\t\t\tth { font-weight:normal; }\n"
literal|"\t\t\tdl { font-family: Arial; font-size: 8pt; margin: 3px; }\n"
literal|"\t\t\tdt { font-weight: bold; float: left; }\n"
literal|"\t\t\ttr:hover { background-color: #ddddff; }\n"
literal|"\t\t\ttd:hover { background-color: #ddddff; }\n"
literal|"\t\t</style>\n"
literal|"\t</head>\n"
literal|"\t<body>\n"
literal|"\t\t<h1>Qt on %1 glyph shaping (%2)</h1>\n"
literal|"\t\t<dl>\n"
literal|"\t\t\t<dt>I</dt><dd>Input Utf-16 to shaper</dd>\n"
literal|"\t\t\t<dt>O-Utf</dt><dd>expected output Utf-16</dd>\n"
literal|"\t\t\t<dt>O-ID</dt><dd>expected output Glyph IDs for \"Series 60 Sans\"</dd>\n"
literal|"\t\t</dl>\n"
literal|"\t\t<table>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|platformName
argument_list|)
operator|.
name|arg
argument_list|(
name|fontFamily
argument_list|)
operator|.
name|arg
argument_list|(
name|fontPixelSize
argument_list|)
decl_stmt|;
name|QString
name|languageName
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|testDataSet
modifier|&
name|dataSet
decl|,
name|testDataSetList
argument_list|()
control|)
block|{
if|if
condition|(
name|languageName
operator|!=
name|dataSet
operator|.
name|language
condition|)
block|{
name|result
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\t\t\t<tr>\n"
literal|"\t\t\t\t<th rowspan=\"2\"><h2>%1</h2></th>\n"
literal|"\t\t\t\t<th colspan=\"2\">Qt/%2</th>\n"
literal|"\t\t\t\t<th rowspan=\"2\">Glyphs</th>\n"
literal|"\t\t\t\t<th colspan=\"2\">Browser</th>\n"
literal|"\t\t\t</tr>\n"
literal|"\t\t\t<tr>\n"
literal|"\t\t\t\t<th>In</th>\n"
literal|"\t\t\t\t<th>Out</th>\n"
literal|"\t\t\t\t<th>In</th>\n"
literal|"\t\t\t\t<th>Out</th>\n"
literal|"\t\t\t</tr>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|dataSet
operator|.
name|language
argument_list|)
operator|.
name|arg
argument_list|(
name|platformName
argument_list|)
argument_list|)
expr_stmt|;
name|languageName
operator|=
name|dataSet
operator|.
name|language
expr_stmt|;
block|}
name|QString
name|glyphsData
decl_stmt|;
if|if
condition|(
operator|!
name|dataSet
operator|.
name|inputOriginal
operator|.
name|isEmpty
argument_list|()
condition|)
name|glyphsData
operator|.
name|append
argument_list|(
name|dlItem
argument_list|(
name|QLatin1String
argument_list|(
literal|"I"
argument_list|)
argument_list|,
name|dataSet
operator|.
name|inputOriginal
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dataSet
operator|.
name|outputOriginal
operator|.
name|isEmpty
argument_list|()
condition|)
name|glyphsData
operator|.
name|append
argument_list|(
name|dlItem
argument_list|(
name|QLatin1String
argument_list|(
literal|"O-Utf"
argument_list|)
argument_list|,
name|dataSet
operator|.
name|outputOriginal
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dataSet
operator|.
name|outputGlyphIDsOriginal
operator|.
name|isEmpty
argument_list|()
condition|)
name|glyphsData
operator|.
name|append
argument_list|(
name|dlItem
argument_list|(
name|QLatin1String
argument_list|(
literal|"O-ID"
argument_list|)
argument_list|,
name|dataSet
operator|.
name|outputGlyphIDsOriginal
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|glyphsData
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|glyphsData
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"\t\t\t\t\t<dl>\n"
argument_list|)
argument_list|)
expr_stmt|;
name|glyphsData
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"\t\t\t\t\t</dl>\n"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\t\t\t<tr>\n"
literal|"\t\t\t\t<th>%1</th>\n"
literal|"\t\t\t\t%2\n"
literal|"\t\t\t\t%3\n"
literal|"\t\t\t\t<td>\n"
literal|"%4"
literal|"\t\t\t\t</td>\n"
literal|"\t\t\t\t<td>%5</td>\n"
literal|"\t\t\t\t<td>%6</td>\n"
literal|"\t\t\t</tr>\n"
argument_list|)
operator|.
name|arg
argument_list|(
name|dataSet
operator|.
name|name
argument_list|)
operator|.
name|arg
argument_list|(
name|dumpImageHtml
argument_list|(
name|dataSet
operator|.
name|input
argument_list|,
name|pathName
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|dumpImageHtml
argument_list|(
name|dataSet
operator|.
name|output
argument_list|,
name|pathName
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|glyphsData
argument_list|)
operator|.
name|arg
argument_list|(
name|dataSet
operator|.
name|input
argument_list|)
operator|.
name|arg
argument_list|(
name|dataSet
operator|.
name|output
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\t\t</table>\n"
literal|"\t</body>\n"
literal|"</html>"
argument_list|)
argument_list|)
expr_stmt|;
name|htmlPage
operator|.
name|write
argument_list|(
name|result
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
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
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
return|return
name|dumpHtml
argument_list|(
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
condition|?
literal|0
else|:
literal|1
return|;
block|}
end_function
end_unit
