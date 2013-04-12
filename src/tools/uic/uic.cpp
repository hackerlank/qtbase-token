begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|"validator.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
end_ifdef
begin_include
include|#
directive|include
file|"cppwriteincludes.h"
end_include
begin_include
include|#
directive|include
file|"cppwritedeclaration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_UIC_JAVA_GENERATOR
end_ifdef
begin_include
include|#
directive|include
file|"javawriteincludes.h"
end_include
begin_include
include|#
directive|include
file|"javawritedeclaration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qxmlstream.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|Uic
name|Uic
operator|::
name|Uic
parameter_list|(
name|Driver
modifier|*
name|d
parameter_list|)
member_init_list|:
name|drv
argument_list|(
name|d
argument_list|)
member_init_list|,
name|out
argument_list|(
name|d
operator|->
name|output
argument_list|()
argument_list|)
member_init_list|,
name|opt
argument_list|(
name|d
operator|->
name|option
argument_list|()
argument_list|)
member_init_list|,
name|externalPix
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~Uic
name|Uic
operator|::
name|~
name|Uic
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|printDependencies
name|bool
name|Uic
operator|::
name|printDependencies
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|opt
operator|.
name|inputFile
decl_stmt|;
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|f
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
block|{
name|f
operator|.
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
name|DomUI
modifier|*
name|ui
init|=
literal|0
decl_stmt|;
block|{
name|QXmlStreamReader
name|reader
decl_stmt|;
name|reader
operator|.
name|setDevice
argument_list|(
operator|&
name|f
argument_list|)
expr_stmt|;
name|ui
operator|=
name|parseUiFile
argument_list|(
name|reader
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ui
condition|)
return|return
literal|false
return|;
block|}
if|if
condition|(
name|DomIncludes
modifier|*
name|includes
init|=
name|ui
operator|->
name|elementIncludes
argument_list|()
condition|)
block|{
foreach|foreach
control|(
name|DomInclude
modifier|*
name|incl
decl|,
name|includes
operator|->
name|elementInclude
argument_list|()
control|)
block|{
name|QString
name|file
init|=
name|incl
operator|->
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s\n"
argument_list|,
name|file
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|DomCustomWidgets
modifier|*
name|customWidgets
init|=
name|ui
operator|->
name|elementCustomWidgets
argument_list|()
condition|)
block|{
foreach|foreach
control|(
name|DomCustomWidget
modifier|*
name|customWidget
decl|,
name|customWidgets
operator|->
name|elementCustomWidget
argument_list|()
control|)
block|{
if|if
condition|(
name|DomHeader
modifier|*
name|header
init|=
name|customWidget
operator|->
name|elementHeader
argument_list|()
condition|)
block|{
name|QString
name|file
init|=
name|header
operator|->
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s\n"
argument_list|,
name|file
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
operator|delete
name|ui
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|writeCopyrightHeader
name|void
name|Uic
operator|::
name|writeCopyrightHeader
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
block|{
name|QString
name|comment
init|=
name|ui
operator|->
name|elementComment
argument_list|()
decl_stmt|;
if|if
condition|(
name|comment
operator|.
name|size
argument_list|()
condition|)
name|out
operator|<<
literal|"/*\n"
operator|<<
name|comment
operator|<<
literal|"\n*/\n\n"
expr_stmt|;
name|out
operator|<<
literal|"/********************************************************************************\n"
expr_stmt|;
name|out
operator|<<
literal|"** Form generated from reading UI file '"
operator|<<
name|QFileInfo
argument_list|(
name|opt
operator|.
name|inputFile
argument_list|)
operator|.
name|fileName
argument_list|()
operator|<<
literal|"'\n"
expr_stmt|;
name|out
operator|<<
literal|"**\n"
expr_stmt|;
name|out
operator|<<
literal|"** Created by: Qt User Interface Compiler version "
operator|<<
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
name|out
operator|<<
literal|"**\n"
expr_stmt|;
name|out
operator|<<
literal|"** WARNING! All changes made in this file will be lost when recompiling UI file!\n"
expr_stmt|;
name|out
operator|<<
literal|"********************************************************************************/\n\n"
expr_stmt|;
block|}
end_function
begin_comment
comment|// Check the version with a stream reader at the<ui> element.
end_comment
begin_function
DECL|function|versionFromUiAttribute
specifier|static
name|double
name|versionFromUiAttribute
parameter_list|(
name|QXmlStreamReader
modifier|&
name|reader
parameter_list|)
block|{
specifier|const
name|QXmlStreamAttributes
name|attributes
init|=
name|reader
operator|.
name|attributes
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|versionAttribute
init|=
name|QLatin1String
argument_list|(
literal|"version"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|attributes
operator|.
name|hasAttribute
argument_list|(
name|versionAttribute
argument_list|)
condition|)
return|return
literal|4.0
return|;
specifier|const
name|QString
name|version
init|=
name|attributes
operator|.
name|value
argument_list|(
name|versionAttribute
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
return|return
name|version
operator|.
name|toDouble
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|parseUiFile
name|DomUI
modifier|*
name|Uic
operator|::
name|parseUiFile
parameter_list|(
name|QXmlStreamReader
modifier|&
name|reader
parameter_list|)
block|{
name|DomUI
modifier|*
name|ui
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|uiElement
init|=
name|QLatin1String
argument_list|(
literal|"ui"
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
if|if
condition|(
name|reader
operator|.
name|readNext
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|StartElement
condition|)
block|{
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|.
name|compare
argument_list|(
name|uiElement
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
operator|&&
operator|!
name|ui
condition|)
block|{
specifier|const
name|double
name|version
init|=
name|versionFromUiAttribute
argument_list|(
name|reader
argument_list|)
decl_stmt|;
if|if
condition|(
name|version
operator|<
literal|4.0
condition|)
block|{
specifier|const
name|QString
name|msg
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"uic: File generated with too old version of Qt Designer (%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|version
argument_list|)
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|ui
operator|=
operator|new
name|DomUI
argument_list|()
expr_stmt|;
name|ui
operator|->
name|read
argument_list|(
name|reader
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|reader
operator|.
name|raiseError
argument_list|(
name|QLatin1String
argument_list|(
literal|"Unexpected element "
argument_list|)
operator|+
name|reader
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|reader
operator|.
name|hasError
argument_list|()
condition|)
block|{
operator|delete
name|ui
expr_stmt|;
name|ui
operator|=
literal|0
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"uic: Error in line %1, column %2 : %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|ui
return|;
block|}
end_function
begin_function
DECL|function|write
name|bool
name|Uic
operator|::
name|write
parameter_list|(
name|QIODevice
modifier|*
name|in
parameter_list|)
block|{
if|if
condition|(
name|option
argument_list|()
operator|.
name|generator
operator|==
name|Option
operator|::
name|JavaGenerator
condition|)
block|{
comment|// the Java generator ignores header protection
name|opt
operator|.
name|headerProtection
operator|=
literal|false
expr_stmt|;
block|}
name|DomUI
modifier|*
name|ui
init|=
literal|0
decl_stmt|;
block|{
name|QXmlStreamReader
name|reader
decl_stmt|;
name|reader
operator|.
name|setDevice
argument_list|(
name|in
argument_list|)
expr_stmt|;
name|ui
operator|=
name|parseUiFile
argument_list|(
name|reader
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ui
condition|)
return|return
literal|false
return|;
block|}
name|double
name|version
init|=
name|ui
operator|->
name|attributeVersion
argument_list|()
operator|.
name|toDouble
argument_list|()
decl_stmt|;
if|if
condition|(
name|version
operator|<
literal|4.0
condition|)
block|{
operator|delete
name|ui
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: File generated with too old version of Qt Designer\n"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QString
name|language
init|=
name|ui
operator|->
name|attributeLanguage
argument_list|()
decl_stmt|;
name|bool
name|rtn
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|option
argument_list|()
operator|.
name|generator
operator|==
name|Option
operator|::
name|JavaGenerator
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_UIC_JAVA_GENERATOR
if|if
condition|(
name|language
operator|.
name|toLower
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"jambi"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: File is not a 'jambi' form\n"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|rtn
operator|=
name|jwrite
argument_list|(
name|ui
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: option to generate java code not compiled in\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
if|if
condition|(
operator|!
name|language
operator|.
name|isEmpty
argument_list|()
operator|&&
name|language
operator|.
name|toLower
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"c++"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: File is not a 'c++' ui file, language=%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|language
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|rtn
operator|=
name|write
argument_list|(
name|ui
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: option to generate cpp code not compiled in\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
operator|delete
name|ui
expr_stmt|;
return|return
name|rtn
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
end_ifdef
begin_function
DECL|function|write
name|bool
name|Uic
operator|::
name|write
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
block|{
using|using
namespace|namespace
name|CPP
namespace|;
if|if
condition|(
operator|!
name|ui
operator|||
operator|!
name|ui
operator|->
name|elementWidget
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|opt
operator|.
name|copyrightHeader
condition|)
name|writeCopyrightHeader
argument_list|(
name|ui
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt
operator|.
name|headerProtection
condition|)
block|{
name|writeHeaderProtectionStart
argument_list|()
expr_stmt|;
name|out
operator|<<
literal|"\n"
expr_stmt|;
block|}
name|pixFunction
operator|=
name|ui
operator|->
name|elementPixmapFunction
argument_list|()
expr_stmt|;
if|if
condition|(
name|pixFunction
operator|==
name|QLatin1String
argument_list|(
literal|"QPixmap::fromMimeSource"
argument_list|)
condition|)
name|pixFunction
operator|=
name|QLatin1String
argument_list|(
literal|"qPixmapFromMimeSource"
argument_list|)
expr_stmt|;
name|externalPix
operator|=
name|ui
operator|->
name|elementImages
argument_list|()
operator|==
literal|0
expr_stmt|;
name|info
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|cWidgetsInfo
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|WriteIncludes
name|writeIncludes
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|writeIncludes
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|Validator
argument_list|(
name|this
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|WriteDeclaration
argument_list|(
name|this
argument_list|,
name|writeIncludes
operator|.
name|scriptsActivated
argument_list|()
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt
operator|.
name|headerProtection
condition|)
name|writeHeaderProtectionEnd
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_UIC_JAVA_GENERATOR
end_ifdef
begin_function
DECL|function|jwrite
name|bool
name|Uic
operator|::
name|jwrite
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
block|{
using|using
namespace|namespace
name|Java
namespace|;
if|if
condition|(
operator|!
name|ui
operator|||
operator|!
name|ui
operator|->
name|elementWidget
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|opt
operator|.
name|copyrightHeader
condition|)
name|writeCopyrightHeader
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|pixFunction
operator|=
name|ui
operator|->
name|elementPixmapFunction
argument_list|()
expr_stmt|;
if|if
condition|(
name|pixFunction
operator|==
name|QLatin1String
argument_list|(
literal|"QPixmap::fromMimeSource"
argument_list|)
condition|)
name|pixFunction
operator|=
name|QLatin1String
argument_list|(
literal|"qPixmapFromMimeSource"
argument_list|)
expr_stmt|;
name|externalPix
operator|=
name|ui
operator|->
name|elementImages
argument_list|()
operator|==
literal|0
expr_stmt|;
name|info
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|cWidgetsInfo
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|WriteIncludes
argument_list|(
name|this
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|Validator
argument_list|(
name|this
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|WriteDeclaration
argument_list|(
name|this
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|ui
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
end_ifdef
begin_function
DECL|function|writeHeaderProtectionStart
name|void
name|Uic
operator|::
name|writeHeaderProtectionStart
parameter_list|()
block|{
name|QString
name|h
init|=
name|drv
operator|->
name|headerFileName
argument_list|()
decl_stmt|;
name|out
operator|<<
literal|"#ifndef "
operator|<<
name|h
operator|<<
literal|"\n"
operator|<<
literal|"#define "
operator|<<
name|h
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeHeaderProtectionEnd
name|void
name|Uic
operator|::
name|writeHeaderProtectionEnd
parameter_list|()
block|{
name|QString
name|h
init|=
name|drv
operator|->
name|headerFileName
argument_list|()
decl_stmt|;
name|out
operator|<<
literal|"#endif // "
operator|<<
name|h
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|isMainWindow
name|bool
name|Uic
operator|::
name|isMainWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QMainWindow"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isToolBar
name|bool
name|Uic
operator|::
name|isToolBar
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QToolBar"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isButton
name|bool
name|Uic
operator|::
name|isButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QRadioButton"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QToolButton"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QCheckBox"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QPushButton"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QCommandLinkButton"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isContainer
name|bool
name|Uic
operator|::
name|isContainer
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QStackedWidget"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QToolBox"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QTabWidget"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QScrollArea"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QMdiArea"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QWizard"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QDockWidget"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isCustomWidgetContainer
name|bool
name|Uic
operator|::
name|isCustomWidgetContainer
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|isCustomWidgetContainer
argument_list|(
name|className
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isStatusBar
name|bool
name|Uic
operator|::
name|isStatusBar
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QStatusBar"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isMenuBar
name|bool
name|Uic
operator|::
name|isMenuBar
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QMenuBar"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isMenu
name|bool
name|Uic
operator|::
name|isMenu
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
specifier|const
block|{
return|return
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QMenu"
argument_list|)
argument_list|)
operator|||
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QPopupMenu"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
