begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"tools.h"
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_comment
comment|// std stuff ------------------------------------
end_comment
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_include
include|#
directive|include
file|<conio.h>
end_include
begin_define
DECL|macro|NUMBER_OF_PARTS
define|#
directive|define
name|NUMBER_OF_PARTS
value|7
end_define
begin_function_decl
name|std
operator|::
name|ostream
modifier|&
name|operator
name|<<
parameter_list|(
name|std
operator|::
name|ostream
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|val
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// defined in configureapp.cpp
end_comment
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_function
DECL|function|checkLicense
name|void
name|Tools
operator|::
name|checkLicense
parameter_list|(
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
modifier|&
name|dictionary
parameter_list|,
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
modifier|&
name|licenseInfo
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|dictionary
index|[
literal|"BUILDNOKIA"
index|]
operator|==
literal|"yes"
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"NokiaInternalBuild"
expr_stmt|;
name|dictionary
index|[
literal|"LICENSE_FILE"
index|]
operator|=
literal|""
expr_stmt|;
comment|// No License for nokia developers
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_OPENSOURCE"
expr_stmt|;
return|return;
comment|// No license key checking in internal builds
block|}
name|QString
name|tpLicense
init|=
name|dictionary
index|[
literal|"QT_SOURCE_TREE"
index|]
operator|+
literal|"/LICENSE.PREVIEW.OPENSOURCE"
decl_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|tpLicense
argument_list|)
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"Preview"
expr_stmt|;
name|dictionary
index|[
literal|"LICENSE FILE"
index|]
operator|=
name|tpLicense
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_OPENSOURCE"
expr_stmt|;
return|return;
comment|// No license key checking in Tech Preview
block|}
name|tpLicense
operator|=
name|dictionary
index|[
literal|"QT_SOURCE_TREE"
index|]
operator|+
literal|"/LICENSE.PREVIEW.COMMERCIAL"
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|tpLicense
argument_list|)
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"Preview"
expr_stmt|;
name|dictionary
index|[
literal|"LICENSE FILE"
index|]
operator|=
name|tpLicense
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_DESKTOP"
expr_stmt|;
return|return;
comment|// No license key checking in Tech Preview
block|}
comment|// Read in the license file
name|QFile
name|licenseFile
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
operator|&&
name|licenseFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|cout
operator|<<
literal|"Reading license file in....."
operator|<<
name|qPrintable
argument_list|(
name|path
argument_list|)
operator|<<
name|endl
expr_stmt|;
name|QString
name|buffer
init|=
name|licenseFile
operator|.
name|readLine
argument_list|(
literal|1024
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|buffer
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|buffer
index|[
literal|0
index|]
operator|!=
literal|'#'
condition|)
block|{
name|QStringList
name|components
init|=
name|buffer
operator|.
name|split
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|components
operator|.
name|size
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|QStringList
operator|::
name|Iterator
name|it
init|=
name|components
operator|.
name|begin
argument_list|()
decl_stmt|;
name|QString
name|key
init|=
operator|(
operator|*
name|it
operator|++
operator|)
operator|.
name|trimmed
argument_list|()
operator|.
name|remove
argument_list|(
literal|'"'
argument_list|)
operator|.
name|toUpper
argument_list|()
decl_stmt|;
name|QString
name|value
init|=
operator|(
operator|*
name|it
operator|++
operator|)
operator|.
name|trimmed
argument_list|()
operator|.
name|remove
argument_list|(
literal|'"'
argument_list|)
decl_stmt|;
name|licenseInfo
index|[
name|key
index|]
operator|=
name|value
expr_stmt|;
block|}
block|}
comment|// read next line
name|buffer
operator|=
name|licenseFile
operator|.
name|readLine
argument_list|(
literal|1024
argument_list|)
expr_stmt|;
block|}
name|licenseFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|cout
operator|<<
literal|"License file not found in "
operator|<<
name|QDir
operator|::
name|homePath
argument_list|()
operator|<<
name|endl
expr_stmt|;
name|cout
operator|<<
literal|"Please put the Qt license file, '.qt-license' in your home "
operator|<<
literal|"directory and run configure again."
expr_stmt|;
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
return|return;
block|}
comment|// Verify license info...
name|QString
name|licenseKey
init|=
name|licenseInfo
index|[
literal|"LICENSEKEYEXT"
index|]
decl_stmt|;
name|QByteArray
name|clicenseKey
init|=
name|licenseKey
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
comment|//We check the license
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|SEP
init|=
literal|"-"
decl_stmt|;
name|char
modifier|*
name|licenseParts
index|[
name|NUMBER_OF_PARTS
index|]
decl_stmt|;
name|int
name|partNumber
init|=
literal|0
decl_stmt|;
for|for
control|(
name|char
modifier|*
name|part
init|=
name|strtok
argument_list|(
name|clicenseKey
operator|.
name|data
argument_list|()
argument_list|,
name|SEP
argument_list|)
init|;
name|part
operator|!=
literal|0
condition|;
name|part
operator|=
name|strtok
argument_list|(
literal|0
argument_list|,
name|SEP
argument_list|)
control|)
name|licenseParts
index|[
name|partNumber
operator|++
index|]
operator|=
name|part
expr_stmt|;
if|if
condition|(
name|partNumber
operator|<
operator|(
name|NUMBER_OF_PARTS
operator|-
literal|1
operator|)
condition|)
block|{
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
name|cout
operator|<<
literal|"License file does not contain proper license key."
operator|<<
name|partNumber
operator|<<
name|endl
expr_stmt|;
return|return;
block|}
name|char
name|products
init|=
name|licenseParts
index|[
literal|0
index|]
index|[
literal|0
index|]
decl_stmt|;
name|char
modifier|*
name|platforms
init|=
name|licenseParts
index|[
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|licenseSchema
init|=
name|licenseParts
index|[
literal|2
index|]
decl_stmt|;
name|char
name|licenseFeatures
init|=
name|licenseParts
index|[
literal|3
index|]
index|[
literal|0
index|]
decl_stmt|;
comment|// Determine edition ---------------------------------------------------------------------------
name|QString
name|licenseType
decl_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|licenseSchema
argument_list|,
literal|"F4M"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|licenseType
operator|=
literal|"Commercial"
expr_stmt|;
if|if
condition|(
name|products
operator|==
literal|'F'
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"Universal"
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_UNIVERSAL"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|products
operator|==
literal|'B'
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"FullFramework"
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_DESKTOP"
expr_stmt|;
block|}
else|else
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"GUIFramework"
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_DESKTOPLIGHT"
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|licenseSchema
argument_list|,
literal|"Z4M"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|licenseSchema
argument_list|,
literal|"R4M"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|licenseSchema
argument_list|,
literal|"Q4M"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|products
operator|==
literal|'B'
condition|)
block|{
name|dictionary
index|[
literal|"EDITION"
index|]
operator|=
literal|"Evaluation"
expr_stmt|;
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|=
literal|"QT_EDITION_EVALUATION"
expr_stmt|;
name|licenseType
operator|=
literal|"Evaluation"
expr_stmt|;
block|}
block|}
if|if
condition|(
name|platforms
index|[
literal|2
index|]
operator|==
literal|'L'
condition|)
block|{
specifier|static
specifier|const
name|char
name|src
index|[]
init|=
literal|"8NPQRTZ"
decl_stmt|;
specifier|static
specifier|const
name|char
name|dst
index|[]
init|=
literal|"UCWX9M7"
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|strchr
argument_list|(
name|src
argument_list|,
name|platforms
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
name|platforms
index|[
literal|1
index|]
operator|=
name|dst
index|[
name|p
operator|-
name|src
index|]
expr_stmt|;
block|}
DECL|macro|PL
define|#
directive|define
name|PL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(int(a)+int(b)*256)
name|int
name|platformCode
init|=
name|PL
argument_list|(
name|platforms
index|[
literal|0
index|]
argument_list|,
name|platforms
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|platformCode
condition|)
block|{
case|case
name|PL
argument_list|(
literal|'X'
argument_list|,
literal|'9'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'X'
argument_list|,
literal|'C'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'X'
argument_list|,
literal|'U'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'X'
argument_list|,
literal|'W'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'X'
argument_list|,
literal|'M'
argument_list|)
case|:
comment|// old license key
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|=
literal|"-ALLOS"
expr_stmt|;
break|break;
case|case
name|PL
argument_list|(
literal|'6'
argument_list|,
literal|'M'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'8'
argument_list|,
literal|'M'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'K'
argument_list|,
literal|'M'
argument_list|)
case|:
comment|// old license key
case|case
name|PL
argument_list|(
literal|'N'
argument_list|,
literal|'7'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'N'
argument_list|,
literal|'9'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'N'
argument_list|,
literal|'X'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'9'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'C'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'U'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'W'
argument_list|)
case|:
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|=
literal|"-EMBEDDED"
expr_stmt|;
if|if
condition|(
name|dictionary
index|[
literal|"PLATFORM NAME"
index|]
operator|.
name|contains
argument_list|(
literal|"Windows CE"
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'6'
argument_list|,
literal|'M'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'9'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'C'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'U'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'W'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'K'
argument_list|,
literal|'M'
argument_list|)
condition|)
block|{
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dictionary
index|[
literal|"PLATFORM NAME"
index|]
operator|.
name|contains
argument_list|(
literal|"Symbian"
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'N'
argument_list|,
literal|'9'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'9'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'C'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'U'
argument_list|)
operator|&&
name|platformCode
operator|!=
name|PL
argument_list|(
literal|'S'
argument_list|,
literal|'W'
argument_list|)
condition|)
block|{
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
block|}
break|break;
case|case
name|PL
argument_list|(
literal|'R'
argument_list|,
literal|'M'
argument_list|)
case|:
case|case
name|PL
argument_list|(
literal|'F'
argument_list|,
literal|'M'
argument_list|)
case|:
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|=
literal|"-DESKTOP"
expr_stmt|;
if|if
condition|(
operator|!
name|dictionary
index|[
literal|"PLATFORM NAME"
index|]
operator|.
name|endsWith
argument_list|(
literal|"Windows"
argument_list|)
condition|)
block|{
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
block|}
break|break;
default|default:
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
break|break;
block|}
DECL|macro|PL
undef|#
directive|undef
name|PL
if|if
condition|(
name|dictionary
operator|.
name|value
argument_list|(
literal|"DONE"
argument_list|)
operator|==
literal|"error"
condition|)
block|{
name|cout
operator|<<
literal|"You are not licensed for the "
operator|<<
name|dictionary
index|[
literal|"PLATFORM NAME"
index|]
operator|<<
literal|" platform."
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|cout
operator|<<
literal|"Please contact qt-info@nokia.com to upgrade your license"
operator|<<
name|endl
expr_stmt|;
name|cout
operator|<<
literal|"to include the "
operator|<<
name|dictionary
index|[
literal|"PLATFORM NAME"
index|]
operator|<<
literal|" platform, or install the"
operator|<<
name|endl
expr_stmt|;
name|cout
operator|<<
literal|"Qt Open Source Edition if you intend to develop free software."
operator|<<
name|endl
expr_stmt|;
return|return;
block|}
comment|// Override for evaluation licenses
if|if
condition|(
name|dictionary
index|[
literal|"EDITION"
index|]
operator|==
literal|"Evaluation"
condition|)
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|=
literal|"-EVALUATION"
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|dictionary
index|[
literal|"QT_SOURCE_TREE"
index|]
operator|+
literal|"/.LICENSE"
argument_list|)
condition|)
block|{
comment|// Generic, no-suffix license
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|cout
operator|<<
literal|"License file does not contain proper license key."
operator|<<
name|endl
expr_stmt|;
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
block|}
if|if
condition|(
name|licenseType
operator|.
name|isEmpty
argument_list|()
operator|||
name|dictionary
index|[
literal|"EDITION"
index|]
operator|.
name|isEmpty
argument_list|()
operator|||
name|dictionary
index|[
literal|"QT_EDITION"
index|]
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|cout
operator|<<
literal|"License file does not contain proper license key."
operator|<<
name|endl
expr_stmt|;
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
return|return;
block|}
comment|// copy one of .LICENSE-*(-US) to LICENSE
name|QString
name|toLicenseFile
init|=
name|dictionary
index|[
literal|"QT_SOURCE_TREE"
index|]
operator|+
literal|"/LICENSE"
decl_stmt|;
name|QString
name|fromLicenseFile
init|=
name|dictionary
index|[
literal|"QT_SOURCE_TREE"
index|]
operator|+
literal|"/.LICENSE"
operator|+
name|dictionary
index|[
literal|"LICENSE_EXTENSION"
index|]
decl_stmt|;
if|if
condition|(
name|licenseFeatures
operator|==
literal|'B'
operator|||
name|licenseFeatures
operator|==
literal|'G'
operator|||
name|licenseFeatures
operator|==
literal|'L'
operator|||
name|licenseFeatures
operator|==
literal|'Y'
condition|)
name|fromLicenseFile
operator|+=
literal|"-US"
expr_stmt|;
if|if
condition|(
operator|!
name|CopyFile
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fromLicenseFile
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|toLicenseFile
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|false
argument_list|)
condition|)
block|{
name|cout
operator|<<
literal|"Failed to copy license file ("
operator|<<
name|fromLicenseFile
operator|<<
literal|")"
expr_stmt|;
name|dictionary
index|[
literal|"DONE"
index|]
operator|=
literal|"error"
expr_stmt|;
return|return;
block|}
name|dictionary
index|[
literal|"LICENSE FILE"
index|]
operator|=
name|toLicenseFile
expr_stmt|;
block|}
end_function
end_unit
