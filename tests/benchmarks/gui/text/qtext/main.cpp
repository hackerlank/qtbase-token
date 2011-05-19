begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QTextDocument>
end_include
begin_include
include|#
directive|include
file|<QTextDocumentWriter>
end_include
begin_include
include|#
directive|include
file|<QTextLayout>
end_include
begin_include
include|#
directive|include
file|<QTextCursor>
end_include
begin_include
include|#
directive|include
file|<private/qtextcontrol_p.h>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_comment
comment|// In Symbian OS test data is located in applications private dir
end_comment
begin_comment
comment|// Application private dir is default serach path for files, so SRCDIR can be set to empty
end_comment
begin_define
DECL|macro|SRCDIR
define|#
directive|define
name|SRCDIR
value|""
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QTextDocument*
argument_list|)
end_macro
begin_class
DECL|class|tst_QText
class|class
name|tst_QText
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QText
name|tst_QText
parameter_list|()
block|{
name|m_lorem
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi."
argument_list|)
expr_stmt|;
name|m_shortLorem
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|loadHtml_data
parameter_list|()
function_decl|;
name|void
name|loadHtml
parameter_list|()
function_decl|;
name|void
name|shaping_data
parameter_list|()
function_decl|;
name|void
name|shaping
parameter_list|()
function_decl|;
name|void
name|odfWriting_empty
parameter_list|()
function_decl|;
name|void
name|odfWriting_text
parameter_list|()
function_decl|;
name|void
name|odfWriting_images
parameter_list|()
function_decl|;
name|void
name|constructControl
parameter_list|()
function_decl|;
name|void
name|constructDocument
parameter_list|()
function_decl|;
name|void
name|newLineReplacement
parameter_list|()
function_decl|;
name|void
name|formatManipulation
parameter_list|()
function_decl|;
name|void
name|fontResolution
parameter_list|()
function_decl|;
name|void
name|layout_data
parameter_list|()
function_decl|;
name|void
name|layout
parameter_list|()
function_decl|;
name|void
name|formattedLayout
parameter_list|()
function_decl|;
name|void
name|paintLayoutToPixmap
parameter_list|()
function_decl|;
name|void
name|paintLayoutToPixmap_painterFill
parameter_list|()
function_decl|;
name|void
name|document
parameter_list|()
function_decl|;
name|void
name|paintDocToPixmap
parameter_list|()
function_decl|;
name|void
name|paintDocToPixmap_painterFill
parameter_list|()
function_decl|;
name|void
name|control
parameter_list|()
function_decl|;
name|void
name|paintControlToPixmap
parameter_list|()
function_decl|;
name|void
name|paintControlToPixmap_painterFill
parameter_list|()
function_decl|;
private|private:
name|QSize
name|setupTextLayout
parameter_list|(
name|QTextLayout
modifier|*
name|layout
parameter_list|,
name|bool
name|wrap
init|=
literal|true
parameter_list|,
name|int
name|wrapWidth
init|=
literal|100
parameter_list|)
function_decl|;
DECL|member|m_lorem
name|QString
name|m_lorem
decl_stmt|;
DECL|member|m_shortLorem
name|QString
name|m_shortLorem
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|loadHtml_data
name|void
name|tst_QText
operator|::
name|loadHtml_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"source"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<html><b>Foo</b></html>"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simple2"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<b>Foo</b>"
argument_list|)
expr_stmt|;
name|QString
name|parag
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<p>%1</p>"
argument_list|)
operator|.
name|arg
argument_list|(
name|m_lorem
argument_list|)
decl_stmt|;
name|QString
name|header
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<html><head><title>test</title></head><body>"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"long"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<html><head><title>test</title></head><body>"
argument_list|)
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|parag
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"</html>"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"table"
argument_list|)
operator|<<
name|header
operator|+
name|QLatin1String
argument_list|(
literal|"<table border=\"1\"1><tr><td>xx</td></tr><tr><td colspan=\"2\">"
argument_list|)
operator|+
name|parag
operator|+
name|QLatin1String
argument_list|(
literal|"</td></tr></table></html"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"crappy"
argument_list|)
operator|<<
name|header
operator|+
name|QLatin1String
argument_list|(
literal|"<table border=\"1\"1><tr><td>xx</td></tr><tr><td colspan=\"2\">"
argument_list|)
operator|+
name|parag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadHtml
name|void
name|tst_QText
operator|::
name|loadHtml
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|source
argument_list|)
expr_stmt|;
name|QTextDocument
name|doc
decl_stmt|;
name|QBENCHMARK
block|{
name|doc
operator|.
name|setHtml
argument_list|(
name|source
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shaping_data
name|void
name|tst_QText
operator|::
name|shaping_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"parag"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lorem"
argument_list|)
operator|<<
name|m_lorem
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"short"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Lorem ipsum dolor sit amet"
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|QFile
name|file
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|SRCDIR
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/bidi.txt"
argument_list|)
argument_list|)
decl_stmt|;
else|#
directive|else
name|QFile
name|file
argument_list|(
name|SRCDIR
literal|"bidi.txt"
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QVERIFY
argument_list|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|data
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|data
operator|.
name|count
argument_list|()
operator|>
literal|1000
argument_list|)
expr_stmt|;
name|QStringList
name|list
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
operator|.
name|data
argument_list|()
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|count
argument_list|()
operator|%
literal|2
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// even amount as we have title and then content.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|count
argument_list|()
condition|;
name|i
operator|+=
literal|2
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|<<
name|list
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shaping
name|void
name|tst_QText
operator|::
name|shaping
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|parag
argument_list|)
expr_stmt|;
name|QTextLayout
name|lay
argument_list|(
name|parag
argument_list|)
decl_stmt|;
name|lay
operator|.
name|setCacheEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// do one run to make sure any fonts are loaded.
name|lay
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|lay
operator|.
name|createLine
argument_list|()
expr_stmt|;
name|lay
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|lay
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|lay
operator|.
name|createLine
argument_list|()
expr_stmt|;
name|lay
operator|.
name|endLayout
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|odfWriting_empty
name|void
name|tst_QText
operator|::
name|odfWriting_empty
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QTextDocumentWriter
operator|::
name|supportedDocumentFormats
argument_list|()
operator|.
name|contains
argument_list|(
literal|"ODF"
argument_list|)
argument_list|)
expr_stmt|;
comment|// odf compiled in
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
argument_list|()
decl_stmt|;
comment|// write it
name|QBENCHMARK
block|{
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QTextDocumentWriter
name|writer
argument_list|(
operator|&
name|buffer
argument_list|,
literal|"ODF"
argument_list|)
decl_stmt|;
name|writer
operator|.
name|write
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
operator|delete
name|doc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|odfWriting_text
name|void
name|tst_QText
operator|::
name|odfWriting_text
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QTextBlockFormat
name|bf
decl_stmt|;
name|bf
operator|.
name|setIndent
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|bf
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|m_lorem
argument_list|)
expr_stmt|;
name|bf
operator|.
name|setTopMargin
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|bf
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|m_lorem
argument_list|)
expr_stmt|;
name|bf
operator|.
name|setRightMargin
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|bf
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|m_lorem
argument_list|)
expr_stmt|;
comment|// write it
name|QBENCHMARK
block|{
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QTextDocumentWriter
name|writer
argument_list|(
operator|&
name|buffer
argument_list|,
literal|"ODF"
argument_list|)
decl_stmt|;
name|writer
operator|.
name|write
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
operator|delete
name|doc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|odfWriting_images
name|void
name|tst_QText
operator|::
name|odfWriting_images
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|m_lorem
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|400
argument_list|,
literal|200
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|m_lorem
argument_list|)
expr_stmt|;
comment|// write it
name|QBENCHMARK
block|{
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QTextDocumentWriter
name|writer
argument_list|(
operator|&
name|buffer
argument_list|,
literal|"ODF"
argument_list|)
decl_stmt|;
name|writer
operator|.
name|write
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
operator|delete
name|doc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupTextLayout
name|QSize
name|tst_QText
operator|::
name|setupTextLayout
parameter_list|(
name|QTextLayout
modifier|*
name|layout
parameter_list|,
name|bool
name|wrap
parameter_list|,
name|int
name|wrapWidth
parameter_list|)
block|{
name|layout
operator|->
name|setCacheEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|int
name|height
init|=
literal|0
decl_stmt|;
name|qreal
name|widthUsed
init|=
literal|0
decl_stmt|;
name|qreal
name|lineWidth
init|=
literal|0
decl_stmt|;
comment|//set manual width
if|if
condition|(
name|wrap
condition|)
name|lineWidth
operator|=
name|wrapWidth
expr_stmt|;
name|layout
operator|->
name|beginLayout
argument_list|()
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|QTextLine
name|line
init|=
name|layout
operator|->
name|createLine
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isValid
argument_list|()
condition|)
break|break;
if|if
condition|(
name|wrap
condition|)
name|line
operator|.
name|setLineWidth
argument_list|(
name|lineWidth
argument_list|)
expr_stmt|;
block|}
name|layout
operator|->
name|endLayout
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
name|layout
operator|->
name|lineCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTextLine
name|line
init|=
name|layout
operator|->
name|lineAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|widthUsed
operator|=
name|qMax
argument_list|(
name|widthUsed
argument_list|,
name|line
operator|.
name|naturalTextWidth
argument_list|()
argument_list|)
expr_stmt|;
name|line
operator|.
name|setPosition
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
name|height
operator|+=
name|int
argument_list|(
name|line
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|QSize
argument_list|(
name|qCeil
argument_list|(
name|widthUsed
argument_list|)
argument_list|,
name|height
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|constructControl
name|void
name|tst_QText
operator|::
name|constructControl
parameter_list|()
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
decl_stmt|;
operator|delete
name|control
expr_stmt|;
name|QBENCHMARK
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
decl_stmt|;
operator|delete
name|control
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|constructDocument
name|void
name|tst_QText
operator|::
name|constructDocument
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
operator|delete
name|doc
expr_stmt|;
name|QBENCHMARK
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
operator|delete
name|doc
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//this step is needed before giving the string to a QTextLayout
end_comment
begin_function
DECL|function|newLineReplacement
name|void
name|tst_QText
operator|::
name|newLineReplacement
parameter_list|()
block|{
name|QString
name|text
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"H\ne\nl\nl\no\n\nW\no\nr\nl\nd"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QString
name|tmp
init|=
name|text
decl_stmt|;
name|tmp
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|,
name|QChar
operator|::
name|LineSeparator
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|formatManipulation
name|void
name|tst_QText
operator|::
name|formatManipulation
parameter_list|()
block|{
name|QFont
name|font
decl_stmt|;
name|QBENCHMARK
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontResolution
name|void
name|tst_QText
operator|::
name|fontResolution
parameter_list|()
block|{
name|QFont
name|font
decl_stmt|;
name|QFont
name|font2
decl_stmt|;
name|font
operator|.
name|setFamily
argument_list|(
literal|"DejaVu"
argument_list|)
expr_stmt|;
name|font2
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QFont
name|res
init|=
name|font
operator|.
name|resolve
argument_list|(
name|font2
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|layout_data
name|void
name|tst_QText
operator|::
name|layout_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"wrap"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"wrap"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"nowrap"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|layout
name|void
name|tst_QText
operator|::
name|layout
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|wrap
argument_list|)
expr_stmt|;
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|,
name|wrap
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|,
name|wrap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//### requires tst_QText to be a friend of QTextLayout
end_comment
begin_comment
comment|/*void tst_QText::stackTextLayout() {     QStackTextEngine engine(m_shortLorem, qApp->font());     QTextLayout layout(&engine);     setupTextLayout(&layout);      QBENCHMARK {         QStackTextEngine engine(m_shortLorem, qApp->font());         QTextLayout layout(&engine);         setupTextLayout(&layout);     } }*/
end_comment
begin_function
DECL|function|formattedLayout
name|void
name|tst_QText
operator|::
name|formattedLayout
parameter_list|()
block|{
comment|//set up formatting
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|ranges
decl_stmt|;
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setForeground
argument_list|(
name|QColor
argument_list|(
literal|"steelblue"
argument_list|)
argument_list|)
expr_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|formatRange
decl_stmt|;
name|formatRange
operator|.
name|format
operator|=
name|format
expr_stmt|;
name|formatRange
operator|.
name|start
operator|=
literal|0
expr_stmt|;
name|formatRange
operator|.
name|length
operator|=
literal|50
expr_stmt|;
name|ranges
operator|.
name|append
argument_list|(
name|formatRange
argument_list|)
expr_stmt|;
block|}
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setAdditionalFormats
argument_list|(
name|ranges
argument_list|)
expr_stmt|;
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setAdditionalFormats
argument_list|(
name|ranges
argument_list|)
expr_stmt|;
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintLayoutToPixmap
name|void
name|tst_QText
operator|::
name|paintLayoutToPixmap
parameter_list|()
block|{
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|layout
operator|.
name|draw
argument_list|(
operator|&
name|p
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintLayoutToPixmap_painterFill
name|void
name|tst_QText
operator|::
name|paintLayoutToPixmap_painterFill
parameter_list|()
block|{
name|QTextLayout
name|layout
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|setupTextLayout
argument_list|(
operator|&
name|layout
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
operator|.
name|width
argument_list|()
argument_list|,
name|img
operator|.
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|layout
operator|.
name|draw
argument_list|(
operator|&
name|p
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|document
name|void
name|tst_QText
operator|::
name|document
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
name|Q_UNUSED
argument_list|(
argument|doc
argument_list|)
name|QBENCHMARK
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintDocToPixmap
name|void
name|tst_QText
operator|::
name|paintDocToPixmap
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setTextWidth
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|doc
operator|->
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|doc
operator|->
name|drawContents
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintDocToPixmap_painterFill
name|void
name|tst_QText
operator|::
name|paintDocToPixmap_painterFill
parameter_list|()
block|{
name|QTextDocument
modifier|*
name|doc
init|=
operator|new
name|QTextDocument
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setTextWidth
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|doc
operator|->
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
operator|.
name|width
argument_list|()
argument_list|,
name|img
operator|.
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|doc
operator|->
name|drawContents
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|control
name|void
name|tst_QText
operator|::
name|control
parameter_list|()
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
argument_list|(
name|m_shortLorem
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|control
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
decl_stmt|;
name|QTextDocument
modifier|*
name|doc
init|=
name|control
operator|->
name|document
argument_list|()
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintControlToPixmap
name|void
name|tst_QText
operator|::
name|paintControlToPixmap
parameter_list|()
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
decl_stmt|;
name|QTextDocument
modifier|*
name|doc
init|=
name|control
operator|->
name|document
argument_list|()
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setTextWidth
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|doc
operator|->
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|control
operator|->
name|drawContents
argument_list|(
operator|&
name|p
argument_list|,
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paintControlToPixmap_painterFill
name|void
name|tst_QText
operator|::
name|paintControlToPixmap_painterFill
parameter_list|()
block|{
name|QTextControl
modifier|*
name|control
init|=
operator|new
name|QTextControl
decl_stmt|;
name|QTextDocument
modifier|*
name|doc
init|=
name|control
operator|->
name|document
argument_list|()
decl_stmt|;
name|doc
operator|->
name|setHtml
argument_list|(
name|m_shortLorem
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setTextWidth
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|doc
operator|->
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|QBENCHMARK
block|{
name|QPixmap
name|img
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
operator|.
name|width
argument_list|()
argument_list|,
name|img
operator|.
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|control
operator|->
name|drawContents
argument_list|(
operator|&
name|p
argument_list|,
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QSizeF
argument_list|(
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QText
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
