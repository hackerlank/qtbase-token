begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTranslator>
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QInputDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QColorDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDesktopWidget>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_languageChange
class|class
name|tst_languageChange
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_languageChange
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|retranslatability_data
parameter_list|()
function_decl|;
name|void
name|retranslatability
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_languageChange
name|tst_languageChange
operator|::
name|tst_languageChange
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_languageChange
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_languageChange
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_comment
comment|/**  * Records all calls to translate()  */
end_comment
begin_class
DECL|class|TransformTranslator
class|class
name|TransformTranslator
super|:
specifier|public
name|QTranslator
block|{
name|Q_OBJECT
public|public:
DECL|function|TransformTranslator
name|TransformTranslator
parameter_list|()
member_init_list|:
name|QTranslator
argument_list|()
block|{}
DECL|function|TransformTranslator
name|TransformTranslator
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTranslator
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|translate
specifier|virtual
name|QString
name|translate
parameter_list|(
specifier|const
name|char
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
init|=
literal|0
parameter_list|)
specifier|const
block|{
name|QByteArray
name|total
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|total
operator|.
name|append
argument_list|(
literal|"::"
argument_list|)
expr_stmt|;
name|total
operator|.
name|append
argument_list|(
name|sourceText
argument_list|)
expr_stmt|;
if|if
condition|(
name|comment
condition|)
block|{
name|total
operator|.
name|append
argument_list|(
literal|"::"
argument_list|)
expr_stmt|;
name|total
operator|.
name|append
argument_list|(
name|comment
argument_list|)
expr_stmt|;
block|}
name|m_translations
operator|.
name|insert
argument_list|(
name|total
argument_list|)
expr_stmt|;
name|QString
name|res
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
name|int
argument_list|(
name|qstrlen
argument_list|(
name|sourceText
argument_list|)
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|QChar
name|ch
init|=
name|QLatin1Char
argument_list|(
name|sourceText
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|ch
operator|.
name|isLower
argument_list|()
condition|)
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|.
name|isUpper
argument_list|()
condition|)
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|res
operator|.
name|append
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|res
return|;
block|}
DECL|function|isEmpty
specifier|virtual
name|bool
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
public|public
name|slots
public|:
DECL|function|install
name|void
name|install
parameter_list|()
block|{
name|QCoreApplication
operator|::
name|installTranslator
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|2500
argument_list|)
expr_stmt|;
name|QApplication
operator|::
name|closeAllWindows
argument_list|()
expr_stmt|;
block|}
public|public:
DECL|member|m_translations
specifier|mutable
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|m_translations
decl_stmt|;
block|}
class|;
end_class
begin_enum
DECL|enum|DialogType
enum|enum
name|DialogType
block|{
DECL|enumerator|InputDialog
name|InputDialog
init|=
literal|1
block|,
DECL|enumerator|ColorDialog
name|ColorDialog
block|,
DECL|enumerator|FileDialog
name|FileDialog
block|}
enum|;
end_enum
begin_typedef
DECL|typedef|TranslationSet
typedef|typedef
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|TranslationSet
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|TranslationSet
argument_list|)
end_macro
begin_function
DECL|function|retranslatability_data
name|void
name|tst_languageChange
operator|::
name|retranslatability_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"dialogType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|TranslationSet
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
comment|//next we fill it with data
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QInputDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|InputDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QDialogButtonBox::Cancel"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QColorDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|ColorDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QDialogButtonBox::Cancel"
operator|<<
literal|"QColorDialog::&Sat:"
operator|<<
literal|"QColorDialog::&Add to Custom Colors"
operator|<<
literal|"QColorDialog::&Green:"
operator|<<
literal|"QColorDialog::&Red:"
operator|<<
literal|"QColorDialog::Bl&ue:"
operator|<<
literal|"QColorDialog::A&lpha channel:"
operator|<<
literal|"QColorDialog::&Basic colors"
operator|<<
literal|"QColorDialog::&Custom colors"
operator|<<
literal|"QColorDialog::&Val:"
operator|<<
literal|"QColorDialog::Hu&e:"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QFileDialog"
argument_list|)
operator|<<
name|int
argument_list|(
name|FileDialog
argument_list|)
operator|<<
operator|(
name|QSet
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
operator|<<
literal|"QFileDialog::All Files (*)"
operator|<<
literal|"QFileDialog::Back"
operator|<<
literal|"QFileDialog::Create New Folder"
operator|<<
literal|"QFileDialog::Detail View"
ifndef|#
directive|ifndef
name|Q_OS_MAC
operator|<<
literal|"QFileDialog::File"
endif|#
directive|endif
operator|<<
literal|"QFileDialog::Files of type:"
operator|<<
literal|"QFileDialog::Forward"
operator|<<
literal|"QFileDialog::List View"
operator|<<
literal|"QFileDialog::Look in:"
operator|<<
literal|"QFileDialog::Open"
operator|<<
literal|"QFileDialog::Parent Directory"
operator|<<
literal|"QFileDialog::Show "
operator|<<
literal|"QFileDialog::Show&hidden files"
operator|<<
literal|"QFileDialog::&Delete"
operator|<<
literal|"QFileDialog::&New Folder"
operator|<<
literal|"QFileDialog::&Rename"
operator|<<
literal|"QFileSystemModel::Date Modified"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"QFileSystemModel::My Computer"
else|#
directive|else
operator|<<
literal|"QFileSystemModel::Computer"
endif|#
directive|endif
operator|<<
literal|"QFileSystemModel::Size"
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|<<
literal|"QFileSystemModel::Kind::Match OS X Finder"
else|#
directive|else
operator|<<
literal|"QFileSystemModel::Type::All other platforms"
endif|#
directive|endif
comment|//<< "QFileSystemModel::%1 KB"
operator|<<
literal|"QDialogButtonBox::Cancel"
operator|<<
literal|"QDialogButtonBox::Open"
operator|<<
literal|"QFileDialog::File&name:"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retranslatability
name|void
name|tst_languageChange
operator|::
name|retranslatability
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|dialogType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|TranslationSet
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// This will always be queried for when a language changes
name|expected
operator|.
name|insert
argument_list|(
literal|"QApplication::QT_LAYOUT_DIRECTION::Translate this string to the string 'LTR' in left-to-right "
literal|"languages or to 'RTL' in right-to-left languages (such as Hebrew and Arabic) to "
literal|"get proper widget layout."
argument_list|)
expr_stmt|;
name|TransformTranslator
name|translator
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_NOKIAX86
argument_list|)
comment|// Allow a little extra time or emulator startup delays cause failure
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|5000
argument_list|,
operator|&
name|translator
argument_list|,
name|SLOT
argument_list|(
name|install
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|500
argument_list|,
operator|&
name|translator
argument_list|,
name|SLOT
argument_list|(
name|install
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|dialogType
condition|)
block|{
case|case
name|InputDialog
case|:
operator|(
name|void
operator|)
name|QInputDialog
operator|::
name|getInteger
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"title"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ColorDialog
case|:
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|QSKIP
argument_list|(
literal|"The native color dialog is used on Mac OS"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|QColorDialog
operator|::
name|getColor
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|FileDialog
case|:
block|{
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|QSKIP
argument_list|(
literal|"The native file dialog is used on Mac OS"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFileDialog
name|dlg
decl_stmt|;
name|dlg
operator|.
name|setOption
argument_list|(
name|QFileDialog
operator|::
name|DontUseNativeDialog
argument_list|)
expr_stmt|;
name|QString
name|tmpParentDir
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
literal|"/languagechangetestdir"
decl_stmt|;
name|QString
name|tmpDir
init|=
name|tmpParentDir
operator|+
literal|"/finaldir"
decl_stmt|;
name|QString
name|fooName
init|=
name|tmpParentDir
operator|+
literal|"/foo"
decl_stmt|;
name|QDir
name|dir
decl_stmt|;
name|QCOMPARE
argument_list|(
name|dir
operator|.
name|mkpath
argument_list|(
name|tmpDir
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
comment|// Just create a new file instead of copying exe, because there is no read access to /sys/bin
block|{
name|QFile
name|fooFile
argument_list|(
name|fooName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fooFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
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
literal|2048
condition|;
name|i
operator|++
control|)
comment|// File needs to be big enough for size to read in KB
name|fooFile
operator|.
name|write
argument_list|(
literal|"@"
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|QCOMPARE
argument_list|(
name|QFile
operator|::
name|copy
argument_list|(
name|QApplication
operator|::
name|applicationFilePath
argument_list|()
argument_list|,
name|fooName
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dlg
operator|.
name|setDirectory
argument_list|(
name|tmpParentDir
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|dlg
operator|.
name|setDirectory
argument_list|(
literal|"\\Windows"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dlg
operator|.
name|setFileMode
argument_list|(
name|QFileDialog
operator|::
name|ExistingFiles
argument_list|)
expr_stmt|;
name|dlg
operator|.
name|setViewMode
argument_list|(
name|QFileDialog
operator|::
name|Detail
argument_list|)
expr_stmt|;
name|dlg
operator|.
name|exec
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_NOKIAX86
argument_list|)
comment|// increase the wait time because of increased delay caused by emulator startup
name|QTest
operator|::
name|qWait
argument_list|(
literal|15000
argument_list|)
expr_stmt|;
else|#
directive|else
name|QTest
operator|::
name|qWait
argument_list|(
literal|3000
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCOMPARE
argument_list|(
name|QFile
operator|::
name|remove
argument_list|(
name|fooName
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir
operator|.
name|rmdir
argument_list|(
name|tmpDir
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dir
operator|.
name|rmdir
argument_list|(
name|tmpParentDir
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|#
directive|if
literal|0
block|QList<QByteArray> list = translator.m_translations.toList();     qSort(list);     qDebug()<< list;
endif|#
directive|endif
comment|// In case we use a Color dialog, we do not want to test for
comment|// strings non existing in the dialog and which do not get
comment|// translated.
if|if
condition|(
operator|(
name|dialogType
operator|==
name|ColorDialog
operator|)
operator|&&
ifndef|#
directive|ifndef
name|Q_OS_WINCE
operator|(
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|width
argument_list|()
operator|<
literal|480
operator|||
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|height
argument_list|()
operator|<
literal|350
operator|)
else|#
directive|else
literal|true
comment|// On Qt/WinCE we always use compact mode
endif|#
directive|endif
condition|)
block|{
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Basic colors"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Custom colors"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Define Custom Colors>>"
argument_list|)
expr_stmt|;
name|expected
operator|.
name|remove
argument_list|(
literal|"QColorDialog::&Add to Custom Colors"
argument_list|)
expr_stmt|;
block|}
comment|// see if all of our *expected* translations was translated.
comment|// (There might be more, but thats not that bad)
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|commonTranslations
init|=
name|expected
decl_stmt|;
name|commonTranslations
operator|.
name|intersect
argument_list|(
name|translator
operator|.
name|m_translations
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|expected
operator|.
name|subtract
argument_list|(
name|commonTranslations
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Missing:"
operator|<<
name|expected
expr_stmt|;
if|if
condition|(
operator|!
name|translator
operator|.
name|m_translations
operator|.
name|subtract
argument_list|(
name|commonTranslations
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Unexpected:"
operator|<<
name|translator
operator|.
name|m_translations
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|expected
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_languageChange
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_languagechange.moc"
end_include
end_unit
