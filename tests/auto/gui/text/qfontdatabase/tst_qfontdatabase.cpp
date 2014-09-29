begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<qfontinfo.h>
end_include
begin_include
include|#
directive|include
file|<qfontmetrics.h>
end_include
begin_include
include|#
directive|include
file|<qtextlayout.h>
end_include
begin_include
include|#
directive|include
file|<private/qrawfont_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_class
DECL|class|tst_QFontDatabase
class|class
name|tst_QFontDatabase
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QFontDatabase
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QFontDatabase
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|styles_data
parameter_list|()
function_decl|;
name|void
name|styles
parameter_list|()
function_decl|;
name|void
name|fixedPitch_data
parameter_list|()
function_decl|;
name|void
name|fixedPitch
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|void
name|trickyFonts_data
parameter_list|()
function_decl|;
name|void
name|trickyFonts
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|widthTwoTimes_data
parameter_list|()
function_decl|;
name|void
name|widthTwoTimes
parameter_list|()
function_decl|;
name|void
name|addAppFont_data
parameter_list|()
function_decl|;
name|void
name|addAppFont
parameter_list|()
function_decl|;
name|void
name|aliases
parameter_list|()
function_decl|;
name|void
name|fallbackFonts
parameter_list|()
function_decl|;
private|private:
DECL|member|m_testFont
specifier|const
name|QString
name|m_testFont
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QFontDatabase
name|tst_QFontDatabase
operator|::
name|tst_QFontDatabase
parameter_list|()
member_init_list|:
name|m_testFont
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"LED_REAL.TTF"
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QFontDatabase
name|tst_QFontDatabase
operator|::
name|~
name|tst_QFontDatabase
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QFontDatabase
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
operator|!
name|m_testFont
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QFontDatabase
operator|::
name|init
parameter_list|()
block|{
comment|// TODO: Add initialization code here.
comment|// This will be executed immediately before each test is run.
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QFontDatabase
operator|::
name|cleanup
parameter_list|()
block|{
comment|// TODO: Add cleanup code here.
comment|// This will be executed immediately after each test is run.
block|}
end_function
begin_function
DECL|function|styles_data
name|void
name|tst_QFontDatabase
operator|::
name|styles_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"font"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Times New Roman"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|styles
name|void
name|tst_QFontDatabase
operator|::
name|styles
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QFontDatabase
name|fdb
decl_stmt|;
name|QStringList
name|styles
init|=
name|fdb
operator|.
name|styles
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QStringList
operator|::
name|Iterator
name|it
init|=
name|styles
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|styles
operator|.
name|end
argument_list|()
condition|)
block|{
name|QString
name|style
init|=
operator|*
name|it
decl_stmt|;
name|QString
name|trimmed
init|=
name|style
operator|.
name|trimmed
argument_list|()
decl_stmt|;
operator|++
name|it
expr_stmt|;
name|QCOMPARE
argument_list|(
name|style
argument_list|,
name|trimmed
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fixedPitch_data
name|void
name|tst_QFontDatabase
operator|::
name|fixedPitch_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"font"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"fixedPitch"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Times New Roman"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Times New Roman"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Arial"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Arial"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Andale Mono"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Andale Mono"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Courier"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Courier"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Courier New"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Courier New"
argument_list|)
operator|<<
literal|true
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Script"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Script"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Lucida Console"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Lucida Console"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DejaVu Sans"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"DejaVu Sans"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DejaVu Sans Mono"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"DejaVu Sans Mono"
argument_list|)
operator|<<
literal|true
expr_stmt|;
else|#
directive|else
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Menlo"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Menlo"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Monaco"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Monaco"
argument_list|)
operator|<<
literal|true
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fixedPitch
name|void
name|tst_QFontDatabase
operator|::
name|fixedPitch
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|fixedPitch
argument_list|)
expr_stmt|;
name|QFontDatabase
name|fdb
decl_stmt|;
if|if
condition|(
operator|!
name|fdb
operator|.
name|families
argument_list|()
operator|.
name|contains
argument_list|(
name|font
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"Font not installed"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fdb
operator|.
name|isFixedPitch
argument_list|(
name|font
argument_list|)
argument_list|,
name|fixedPitch
argument_list|)
expr_stmt|;
name|QFont
name|qfont
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QFontInfo
name|fi
argument_list|(
name|qfont
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|fixedPitch
argument_list|()
argument_list|,
name|fixedPitch
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_function
DECL|function|trickyFonts_data
name|void
name|tst_QFontDatabase
operator|::
name|trickyFonts_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"font"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Geeza Pro"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Geeza Pro"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|trickyFonts
name|void
name|tst_QFontDatabase
operator|::
name|trickyFonts
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QFontDatabase
name|fdb
decl_stmt|;
if|if
condition|(
operator|!
name|fdb
operator|.
name|families
argument_list|()
operator|.
name|contains
argument_list|(
name|font
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"Font not installed"
argument_list|)
expr_stmt|;
name|QFont
name|qfont
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QFontInfo
name|fi
argument_list|(
name|qfont
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|fi
operator|.
name|family
argument_list|()
argument_list|,
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|widthTwoTimes_data
name|void
name|tst_QFontDatabase
operator|::
name|widthTwoTimes_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"font"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"pixelSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Arial"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"Arial"
argument_list|)
operator|<<
literal|1000
operator|<<
name|QString
argument_list|(
literal|"Some text"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|widthTwoTimes
name|void
name|tst_QFontDatabase
operator|::
name|widthTwoTimes
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|font
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|pixelSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setFamily
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|f
operator|.
name|setPixelSize
argument_list|(
name|pixelSize
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|f
argument_list|)
decl_stmt|;
name|int
name|w1
init|=
name|fm
operator|.
name|charWidth
argument_list|(
name|text
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|w2
init|=
name|fm
operator|.
name|charWidth
argument_list|(
name|text
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|w1
argument_list|,
name|w2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addAppFont_data
name|void
name|tst_QFontDatabase
operator|::
name|addAppFont_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"useMemoryFont"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"font file"
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"memory font"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addAppFont
name|void
name|tst_QFontDatabase
operator|::
name|addAppFont
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|useMemoryFont
argument_list|)
expr_stmt|;
name|QSignalSpy
name|fontDbChangedSpy
argument_list|(
name|QGuiApplication
operator|::
name|instance
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|fontDatabaseChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QFontDatabase
name|db
decl_stmt|;
specifier|const
name|QStringList
name|oldFamilies
init|=
name|db
operator|.
name|families
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|oldFamilies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|fontDbChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|int
name|id
decl_stmt|;
if|if
condition|(
name|useMemoryFont
condition|)
block|{
name|QFile
name|fontfile
argument_list|(
name|m_testFont
argument_list|)
decl_stmt|;
name|fontfile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|fontdata
init|=
name|fontfile
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|fontdata
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|id
operator|=
name|QFontDatabase
operator|::
name|addApplicationFontFromData
argument_list|(
name|fontdata
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|id
operator|=
name|QFontDatabase
operator|::
name|addApplicationFont
argument_list|(
name|m_testFont
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NO_FONTCONFIG
argument_list|)
comment|// Documentation says that X11 systems that don't have fontconfig
comment|// don't support application fonts.
name|QCOMPARE
argument_list|(
name|id
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|fontDbChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|id
operator|==
operator|-
literal|1
condition|)
name|QSKIP
argument_list|(
literal|"Skip the test since app fonts are not supported on this system"
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|addedFamilies
init|=
name|QFontDatabase
operator|::
name|applicationFontFamilies
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|addedFamilies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|newFamilies
init|=
name|db
operator|.
name|families
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|newFamilies
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|newFamilies
operator|.
name|count
argument_list|()
operator|>=
name|oldFamilies
operator|.
name|count
argument_list|()
argument_list|)
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
name|addedFamilies
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|QVERIFY
argument_list|(
name|newFamilies
operator|.
name|contains
argument_list|(
name|addedFamilies
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFontDatabase
operator|::
name|removeApplicationFont
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fontDbChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|db
operator|.
name|families
argument_list|()
argument_list|,
name|oldFamilies
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|aliases
name|void
name|tst_QFontDatabase
operator|::
name|aliases
parameter_list|()
block|{
name|QFontDatabase
name|db
decl_stmt|;
specifier|const
name|QStringList
name|families
init|=
name|db
operator|.
name|families
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|families
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|firstFont
init|=
name|families
operator|.
name|front
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|db
operator|.
name|hasFamily
argument_list|(
name|firstFont
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|alias
init|=
name|QStringLiteral
argument_list|(
literal|"AliasToFirstFont"
argument_list|)
operator|+
name|firstFont
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|db
operator|.
name|hasFamily
argument_list|(
name|alias
argument_list|)
argument_list|)
expr_stmt|;
name|QPlatformFontDatabase
operator|::
name|registerAliasToFontFamily
argument_list|(
name|firstFont
argument_list|,
name|alias
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|db
operator|.
name|hasFamily
argument_list|(
name|alias
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fallbackFonts
name|void
name|tst_QFontDatabase
operator|::
name|fallbackFonts
parameter_list|()
block|{
name|QTextLayout
name|layout
decl_stmt|;
name|QString
name|s
decl_stmt|;
name|s
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
literal|0x31
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|.
name|append
argument_list|(
name|QChar
argument_list|(
literal|0x05D0
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setText
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|layout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|layout
operator|.
name|createLine
argument_list|()
expr_stmt|;
name|layout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QGlyphRun
argument_list|>
name|runs
init|=
name|layout
operator|.
name|glyphRuns
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QGlyphRun
name|run
decl|,
name|runs
control|)
block|{
name|QRawFont
name|rawFont
init|=
name|run
operator|.
name|rawFont
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|rawFont
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|run
operator|.
name|glyphIndexes
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|run
operator|.
name|glyphIndexes
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFontDatabase
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfontdatabase.moc"
end_include
end_unit
