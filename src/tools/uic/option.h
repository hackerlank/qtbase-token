begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OPTION_H
end_ifndef
begin_define
DECL|macro|OPTION_H
define|#
directive|define
name|OPTION_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|Option
struct|struct
name|Option
block|{
DECL|enum|Generator
enum|enum
name|Generator
block|{
DECL|enumerator|CppGenerator
name|CppGenerator
block|,
DECL|enumerator|JavaGenerator
name|JavaGenerator
block|}
enum|;
DECL|member|headerProtection
name|unsigned
name|int
name|headerProtection
range|:
literal|1
decl_stmt|;
DECL|member|copyrightHeader
name|unsigned
name|int
name|copyrightHeader
range|:
literal|1
decl_stmt|;
DECL|member|generateImplemetation
name|unsigned
name|int
name|generateImplemetation
range|:
literal|1
decl_stmt|;
DECL|member|generateNamespace
name|unsigned
name|int
name|generateNamespace
range|:
literal|1
decl_stmt|;
DECL|member|autoConnection
name|unsigned
name|int
name|autoConnection
range|:
literal|1
decl_stmt|;
DECL|member|dependencies
name|unsigned
name|int
name|dependencies
range|:
literal|1
decl_stmt|;
DECL|member|extractImages
name|unsigned
name|int
name|extractImages
range|:
literal|1
decl_stmt|;
DECL|member|limitXPM_LineLength
name|unsigned
name|int
name|limitXPM_LineLength
range|:
literal|1
decl_stmt|;
DECL|member|implicitIncludes
name|unsigned
name|int
name|implicitIncludes
range|:
literal|1
decl_stmt|;
DECL|member|generator
name|Generator
name|generator
decl_stmt|;
DECL|member|inputFile
name|QString
name|inputFile
decl_stmt|;
DECL|member|outputFile
name|QString
name|outputFile
decl_stmt|;
DECL|member|qrcOutputFile
name|QString
name|qrcOutputFile
decl_stmt|;
DECL|member|indent
name|QString
name|indent
decl_stmt|;
DECL|member|prefix
name|QString
name|prefix
decl_stmt|;
DECL|member|postfix
name|QString
name|postfix
decl_stmt|;
DECL|member|translateFunction
name|QString
name|translateFunction
decl_stmt|;
DECL|member|uic3
name|QString
name|uic3
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_UIC_JAVA_GENERATOR
DECL|member|javaPackage
name|QString
name|javaPackage
decl_stmt|;
DECL|member|javaOutputDirectory
name|QString
name|javaOutputDirectory
decl_stmt|;
endif|#
directive|endif
DECL|function|Option
name|Option
argument_list|()
operator|:
name|headerProtection
argument_list|(
literal|1
argument_list|)
operator|,
name|copyrightHeader
argument_list|(
literal|1
argument_list|)
operator|,
name|generateImplemetation
argument_list|(
literal|0
argument_list|)
operator|,
name|generateNamespace
argument_list|(
literal|1
argument_list|)
operator|,
name|autoConnection
argument_list|(
literal|1
argument_list|)
operator|,
name|dependencies
argument_list|(
literal|0
argument_list|)
operator|,
name|extractImages
argument_list|(
literal|0
argument_list|)
operator|,
name|limitXPM_LineLength
argument_list|(
literal|0
argument_list|)
operator|,
name|implicitIncludes
argument_list|(
literal|1
argument_list|)
operator|,
name|generator
argument_list|(
name|CppGenerator
argument_list|)
operator|,
name|prefix
argument_list|(
argument|QLatin1String(
literal|"Ui_"
argument|)
argument_list|)
block|{
name|indent
operator|.
name|fill
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
literal|4
argument_list|)
block|; }
DECL|function|messagePrefix
name|QString
name|messagePrefix
argument_list|()
specifier|const
block|{
return|return
name|inputFile
operator|.
name|isEmpty
argument_list|()
operator|?
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"stdin"
argument_list|)
argument_list|)
operator|:
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|inputFile
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// OPTION_H
end_comment
end_unit
