begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"baselineprotocol.h"
end_include
begin_include
include|#
directive|include
file|<QLibraryInfo>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QHostInfo>
end_include
begin_include
include|#
directive|include
file|<QSysInfo>
end_include
begin_include
include|#
directive|include
file|<QProcess>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_decl_stmt
specifier|const
name|QString
name|PI_TestCase
argument_list|(
name|QLS
argument_list|(
literal|"TestCase"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_HostName
argument_list|(
name|QLS
argument_list|(
literal|"HostName"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_HostAddress
argument_list|(
name|QLS
argument_list|(
literal|"HostAddress"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_OSName
argument_list|(
name|QLS
argument_list|(
literal|"OSName"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_OSVersion
argument_list|(
name|QLS
argument_list|(
literal|"OSVersion"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_QtVersion
argument_list|(
name|QLS
argument_list|(
literal|"QtVersion"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_QtBuildMode
argument_list|(
name|QLS
argument_list|(
literal|"QtBuildMode"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_GitCommit
argument_list|(
name|QLS
argument_list|(
literal|"GitCommit"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_QMakeSpec
argument_list|(
name|QLS
argument_list|(
literal|"QMakeSpec"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_PulseGitBranch
argument_list|(
name|QLS
argument_list|(
literal|"PulseGitBranch"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_PulseTestrBranch
argument_list|(
name|QLS
argument_list|(
literal|"PulseTestrBranch"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKESPEC
end_ifndef
begin_define
DECL|macro|QMAKESPEC
define|#
directive|define
name|QMAKESPEC
value|"Unknown"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|sysSleep
name|void
name|BaselineProtocol
operator|::
name|sysSleep
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Sleep
argument_list|(
name|DWORD
argument_list|(
name|ms
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct
name|timespec
name|ts
init|=
block|{
name|ms
operator|/
literal|1000
block|,
operator|(
name|ms
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
block|}
decl_stmt|;
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|PlatformInfo
name|PlatformInfo
operator|::
name|PlatformInfo
parameter_list|()
member_init_list|:
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|()
member_init_list|,
name|adHoc
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|localHostInfo
name|PlatformInfo
name|PlatformInfo
operator|::
name|localHostInfo
parameter_list|()
block|{
name|PlatformInfo
name|pi
decl_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_HostName
argument_list|,
name|QHostInfo
operator|::
name|localHostName
argument_list|()
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_QtVersion
argument_list|,
name|QLS
argument_list|(
name|qVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_QMakeSpec
argument_list|,
name|QString
argument_list|(
name|QLS
argument_list|(
name|QMAKESPEC
argument_list|)
argument_list|)
operator|.
name|remove
argument_list|(
name|QRegExp
argument_list|(
name|QLS
argument_list|(
literal|"^.*mkspecs/"
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|pi
operator|.
name|insert
argument_list|(
name|PI_QtBuildMode
argument_list|,
name|QLibraryInfo
operator|::
name|isDebugBuild
argument_list|()
condition|?
name|QLS
argument_list|(
literal|"QtDebug"
argument_list|)
else|:
name|QLS
argument_list|(
literal|"QtRelease"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Linux"
argument_list|)
argument_list|)
expr_stmt|;
name|QProcess
name|uname
decl_stmt|;
name|uname
operator|.
name|start
argument_list|(
name|QLS
argument_list|(
literal|"uname"
argument_list|)
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QLS
argument_list|(
literal|"-r"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|uname
operator|.
name|waitForFinished
argument_list|(
literal|3000
argument_list|)
condition|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|uname
operator|.
name|readAllStandardOutput
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|simplified
argument_list|()
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"WinCE"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Windows"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"MacOS"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|QSysInfo
operator|::
name|macVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Other"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QProcess
name|git
decl_stmt|;
name|QString
name|cmd
decl_stmt|;
name|QStringList
name|args
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|cmd
operator|=
name|QLS
argument_list|(
literal|"cmd.exe"
argument_list|)
expr_stmt|;
name|args
operator|<<
name|QLS
argument_list|(
literal|"/c"
argument_list|)
operator|<<
name|QLS
argument_list|(
literal|"git"
argument_list|)
expr_stmt|;
else|#
directive|else
name|cmd
operator|=
name|QLS
argument_list|(
literal|"git"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|args
operator|<<
name|QLS
argument_list|(
literal|"log"
argument_list|)
operator|<<
name|QLS
argument_list|(
literal|"--max-count=1"
argument_list|)
operator|<<
name|QLS
argument_list|(
literal|"--pretty=%H [%an] [%ad] %s"
argument_list|)
expr_stmt|;
name|git
operator|.
name|start
argument_list|(
name|cmd
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|git
operator|.
name|waitForFinished
argument_list|(
literal|3000
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|git
operator|.
name|exitCode
argument_list|()
condition|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_GitCommit
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|git
operator|.
name|readAllStandardOutput
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|simplified
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|pi
operator|.
name|insert
argument_list|(
name|PI_GitCommit
argument_list|,
name|QLS
argument_list|(
literal|"Unknown"
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|gb
init|=
name|qgetenv
argument_list|(
literal|"PULSE_GIT_BRANCH"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|gb
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|pi
operator|.
name|insert
argument_list|(
name|PI_PulseGitBranch
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|gb
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|setAdHocRun
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|QByteArray
name|tb
init|=
name|qgetenv
argument_list|(
literal|"PULSE_TESTR_BRANCH"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tb
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|pi
operator|.
name|insert
argument_list|(
name|PI_PulseTestrBranch
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|tb
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|setAdHocRun
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
name|pi
return|;
block|}
end_function
begin_constructor
DECL|function|PlatformInfo
name|PlatformInfo
operator|::
name|PlatformInfo
parameter_list|(
specifier|const
name|PlatformInfo
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|(
name|other
argument_list|)
block|{
name|orides
operator|=
name|other
operator|.
name|orides
expr_stmt|;
name|adHoc
operator|=
name|other
operator|.
name|adHoc
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|operator =
name|PlatformInfo
modifier|&
name|PlatformInfo
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|PlatformInfo
modifier|&
name|other
parameter_list|)
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|orides
operator|=
name|other
operator|.
name|orides
expr_stmt|;
name|adHoc
operator|=
name|other
operator|.
name|adHoc
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|addOverride
name|void
name|PlatformInfo
operator|::
name|addOverride
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|orides
operator|.
name|append
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|orides
operator|.
name|append
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overrides
name|QStringList
name|PlatformInfo
operator|::
name|overrides
parameter_list|()
specifier|const
block|{
return|return
name|orides
return|;
block|}
end_function
begin_function
DECL|function|setAdHocRun
name|void
name|PlatformInfo
operator|::
name|setAdHocRun
parameter_list|(
name|bool
name|isAdHoc
parameter_list|)
block|{
name|adHoc
operator|=
name|isAdHoc
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isAdHocRun
name|bool
name|PlatformInfo
operator|::
name|isAdHocRun
parameter_list|()
specifier|const
block|{
return|return
name|adHoc
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|PlatformInfo
modifier|&
name|pi
parameter_list|)
block|{
name|stream
operator|<<
cast|static_cast
argument_list|<
specifier|const
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|&
argument_list|>
argument_list|(
name|pi
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|pi
operator|.
name|orides
operator|<<
name|pi
operator|.
name|adHoc
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|PlatformInfo
modifier|&
name|pi
parameter_list|)
block|{
name|stream
operator|>>
cast|static_cast
argument_list|<
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|&
argument_list|>
argument_list|(
name|pi
argument_list|)
expr_stmt|;
name|stream
operator|>>
name|pi
operator|.
name|orides
operator|>>
name|pi
operator|.
name|adHoc
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|ImageItem
modifier|&
name|ImageItem
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|ImageItem
modifier|&
name|other
parameter_list|)
block|{
name|testFunction
operator|=
name|other
operator|.
name|testFunction
expr_stmt|;
name|itemName
operator|=
name|other
operator|.
name|itemName
expr_stmt|;
name|itemChecksum
operator|=
name|other
operator|.
name|itemChecksum
expr_stmt|;
name|status
operator|=
name|other
operator|.
name|status
expr_stmt|;
name|image
operator|=
name|other
operator|.
name|image
expr_stmt|;
name|imageChecksums
operator|=
name|other
operator|.
name|imageChecksums
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|// Defined in lookup3.c:
end_comment
begin_function_decl
name|void
name|hashword2
parameter_list|(
specifier|const
name|quint32
modifier|*
name|k
parameter_list|,
comment|/* the key, an array of quint32 values */
name|size_t
name|length
parameter_list|,
comment|/* the length of the key, in quint32s */
name|quint32
modifier|*
name|pc
parameter_list|,
comment|/* IN: seed OUT: primary hash value */
name|quint32
modifier|*
name|pb
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* IN: more seed OUT: secondary hash value */
end_comment
begin_function
DECL|function|computeChecksum
name|quint64
name|ImageItem
operator|::
name|computeChecksum
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|QImage
name|img
argument_list|(
name|image
argument_list|)
decl_stmt|;
specifier|const
name|int
name|bpl
init|=
name|img
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
specifier|const
name|int
name|padBytes
init|=
name|bpl
operator|-
operator|(
name|img
operator|.
name|width
argument_list|()
operator|*
name|img
operator|.
name|depth
argument_list|()
operator|/
literal|8
operator|)
decl_stmt|;
if|if
condition|(
name|padBytes
condition|)
block|{
name|uchar
modifier|*
name|p
init|=
name|img
operator|.
name|bits
argument_list|()
operator|+
name|bpl
operator|-
name|padBytes
decl_stmt|;
specifier|const
name|int
name|h
init|=
name|img
operator|.
name|height
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|padBytes
argument_list|)
expr_stmt|;
name|p
operator|+=
name|bpl
expr_stmt|;
block|}
block|}
name|quint32
name|h1
init|=
literal|0xfeedbacc
decl_stmt|;
name|quint32
name|h2
init|=
literal|0x21604894
decl_stmt|;
name|hashword2
argument_list|(
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|img
operator|.
name|constBits
argument_list|()
argument_list|,
name|img
operator|.
name|byteCount
argument_list|()
operator|/
literal|4
argument_list|,
operator|&
name|h1
argument_list|,
operator|&
name|h2
argument_list|)
expr_stmt|;
return|return
operator|(
name|quint64
argument_list|(
name|h1
argument_list|)
operator|<<
literal|32
operator|)
operator||
name|h2
return|;
block|}
end_function
begin_if
if|#
directive|if
literal|0
end_if
begin_endif
unit|QString ImageItem::engineAsString() const {     switch (engine) {     case Raster:         return QLS("Raster");         break;     case OpenGL:         return QLS("OpenGL");         break;     default:         break;     }     return QLS("Unknown"); }  QString ImageItem::formatAsString() const {     static const int numFormats = 16;     static const char *formatNames[numFormats] = {         "Invalid",         "Mono",         "MonoLSB",         "Indexed8",         "RGB32",         "ARGB32",         "ARGB32-Premult",         "RGB16",         "ARGB8565-Premult",         "RGB666",         "ARGB6666-Premult",         "RGB555",         "ARGB8555-Premult",         "RGB888",         "RGB444",         "ARGB4444-Premult"     };     if (renderFormat< 0 || renderFormat>= numFormats)         return QLS("UnknownFormat");     return QLS(formatNames[renderFormat]); }
endif|#
directive|endif
end_endif
begin_function
DECL|function|writeImageToStream
name|void
name|ImageItem
operator|::
name|writeImageToStream
parameter_list|(
name|QDataStream
modifier|&
name|out
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
operator|||
name|image
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Invalid
condition|)
block|{
name|out
operator|<<
name|quint8
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|out
operator|<<
name|quint8
argument_list|(
literal|'Q'
argument_list|)
operator|<<
name|quint8
argument_list|(
name|image
operator|.
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|<<
name|quint8
argument_list|(
name|QSysInfo
operator|::
name|ByteOrder
argument_list|)
operator|<<
name|quint8
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// pad to multiple of 4 bytes
name|out
operator|<<
name|quint32
argument_list|(
name|image
operator|.
name|width
argument_list|()
argument_list|)
operator|<<
name|quint32
argument_list|(
name|image
operator|.
name|height
argument_list|()
argument_list|)
operator|<<
name|quint32
argument_list|(
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|<<
name|qCompress
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|image
operator|.
name|constBits
argument_list|()
argument_list|,
name|image
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
comment|//# can be followed by colormap for formats that use it
block|}
end_function
begin_function
DECL|function|readImageFromStream
name|void
name|ImageItem
operator|::
name|readImageFromStream
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
block|{
name|quint8
name|hdr
decl_stmt|,
name|fmt
decl_stmt|,
name|endian
decl_stmt|,
name|pad
decl_stmt|;
name|quint32
name|width
decl_stmt|,
name|height
decl_stmt|,
name|bpl
decl_stmt|;
name|QByteArray
name|data
decl_stmt|;
name|in
operator|>>
name|hdr
expr_stmt|;
if|if
condition|(
name|hdr
operator|!=
literal|'Q'
condition|)
block|{
name|image
operator|=
name|QImage
argument_list|()
expr_stmt|;
return|return;
block|}
name|in
operator|>>
name|fmt
operator|>>
name|endian
operator|>>
name|pad
expr_stmt|;
if|if
condition|(
operator|!
name|fmt
operator|||
name|fmt
operator|>=
name|QImage
operator|::
name|NImageFormats
condition|)
block|{
name|image
operator|=
name|QImage
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|endian
operator|!=
name|QSysInfo
operator|::
name|ByteOrder
condition|)
block|{
name|qWarning
argument_list|(
literal|"ImageItem cannot read streamed image with different endianness"
argument_list|)
expr_stmt|;
name|image
operator|=
name|QImage
argument_list|()
expr_stmt|;
return|return;
block|}
name|in
operator|>>
name|width
operator|>>
name|height
operator|>>
name|bpl
expr_stmt|;
name|in
operator|>>
name|data
expr_stmt|;
name|data
operator|=
name|qUncompress
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|QImage
name|res
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|bpl
argument_list|,
name|QImage
operator|::
name|Format
argument_list|(
name|fmt
argument_list|)
argument_list|)
decl_stmt|;
name|image
operator|=
name|res
operator|.
name|copy
argument_list|()
expr_stmt|;
comment|//# yuck, seems there is currently no way to avoid data copy
block|}
end_function
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|ImageItem
modifier|&
name|ii
parameter_list|)
block|{
name|stream
operator|<<
name|ii
operator|.
name|testFunction
operator|<<
name|ii
operator|.
name|itemName
operator|<<
name|ii
operator|.
name|itemChecksum
operator|<<
name|quint8
argument_list|(
name|ii
operator|.
name|status
argument_list|)
operator|<<
name|ii
operator|.
name|imageChecksums
operator|<<
name|ii
operator|.
name|misc
expr_stmt|;
name|ii
operator|.
name|writeImageToStream
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|ImageItem
modifier|&
name|ii
parameter_list|)
block|{
name|quint8
name|encStatus
decl_stmt|;
name|stream
operator|>>
name|ii
operator|.
name|testFunction
operator|>>
name|ii
operator|.
name|itemName
operator|>>
name|ii
operator|.
name|itemChecksum
operator|>>
name|encStatus
operator|>>
name|ii
operator|.
name|imageChecksums
operator|>>
name|ii
operator|.
name|misc
expr_stmt|;
name|ii
operator|.
name|status
operator|=
name|ImageItem
operator|::
name|ItemStatus
argument_list|(
name|encStatus
argument_list|)
expr_stmt|;
name|ii
operator|.
name|readImageFromStream
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_constructor
DECL|function|BaselineProtocol
name|BaselineProtocol
operator|::
name|BaselineProtocol
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~BaselineProtocol
name|BaselineProtocol
operator|::
name|~
name|BaselineProtocol
parameter_list|()
block|{
name|socket
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|socket
operator|.
name|state
argument_list|()
operator|!=
name|QTcpSocket
operator|::
name|UnconnectedState
condition|)
name|socket
operator|.
name|waitForDisconnected
argument_list|(
name|Timeout
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|connect
name|bool
name|BaselineProtocol
operator|::
name|connect
parameter_list|(
specifier|const
name|QString
modifier|&
name|testCase
parameter_list|,
name|bool
modifier|*
name|dryrun
parameter_list|,
specifier|const
name|PlatformInfo
modifier|&
name|clientInfo
parameter_list|)
block|{
name|errMsg
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QByteArray
name|serverName
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_LANCELOT_SERVER"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|serverName
operator|.
name|isNull
argument_list|()
condition|)
name|serverName
operator|=
literal|"lancelot.test.qt.nokia.com"
expr_stmt|;
name|socket
operator|.
name|connectToHost
argument_list|(
name|serverName
argument_list|,
name|ServerPort
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForConnected
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
name|sysSleep
argument_list|(
name|Timeout
argument_list|)
expr_stmt|;
comment|// Wait a bit and try again, the server might just be restarting
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForConnected
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
name|errMsg
operator|+=
name|QLS
argument_list|(
literal|"TCP connectToHost failed. Host:"
argument_list|)
operator|+
name|serverName
operator|+
name|QLS
argument_list|(
literal|" port:"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|ServerPort
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
name|PlatformInfo
name|pi
init|=
name|clientInfo
operator|.
name|isEmpty
argument_list|()
condition|?
name|PlatformInfo
operator|::
name|localHostInfo
argument_list|()
else|:
name|clientInfo
decl_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_TestCase
argument_list|,
name|testCase
argument_list|)
expr_stmt|;
name|QByteArray
name|block
decl_stmt|;
name|QDataStream
name|ds
argument_list|(
operator|&
name|block
argument_list|,
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
name|ds
operator|<<
name|pi
expr_stmt|;
if|if
condition|(
operator|!
name|sendBlock
argument_list|(
name|AcceptPlatformInfo
argument_list|,
name|block
argument_list|)
condition|)
block|{
name|errMsg
operator|+=
name|QLS
argument_list|(
literal|"Failed to send data to server."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|Command
name|cmd
init|=
name|UnknownError
decl_stmt|;
if|if
condition|(
operator|!
name|receiveBlock
argument_list|(
operator|&
name|cmd
argument_list|,
operator|&
name|block
argument_list|)
condition|)
block|{
name|errMsg
operator|.
name|prepend
argument_list|(
name|QLS
argument_list|(
literal|"Failed to get response from server. "
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|cmd
operator|==
name|Abort
condition|)
block|{
name|errMsg
operator|+=
name|QLS
argument_list|(
literal|"Server rejected connection. Reason: "
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|block
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|dryrun
condition|)
operator|*
name|dryrun
operator|=
operator|(
name|cmd
operator|==
name|DoDryRun
operator|)
expr_stmt|;
if|if
condition|(
name|cmd
operator|!=
name|Ack
operator|&&
name|cmd
operator|!=
name|DoDryRun
condition|)
block|{
name|errMsg
operator|+=
name|QLS
argument_list|(
literal|"Unexpected response from server."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|acceptConnection
name|bool
name|BaselineProtocol
operator|::
name|acceptConnection
parameter_list|(
name|PlatformInfo
modifier|*
name|pi
parameter_list|)
block|{
name|errMsg
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QByteArray
name|block
decl_stmt|;
name|Command
name|cmd
init|=
name|AcceptPlatformInfo
decl_stmt|;
if|if
condition|(
operator|!
name|receiveBlock
argument_list|(
operator|&
name|cmd
argument_list|,
operator|&
name|block
argument_list|)
operator|||
name|cmd
operator|!=
name|AcceptPlatformInfo
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|pi
condition|)
block|{
name|QDataStream
name|ds
argument_list|(
name|block
argument_list|)
decl_stmt|;
name|ds
operator|>>
operator|*
name|pi
expr_stmt|;
name|pi
operator|->
name|insert
argument_list|(
name|PI_HostAddress
argument_list|,
name|socket
operator|.
name|peerAddress
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|requestBaselineChecksums
name|bool
name|BaselineProtocol
operator|::
name|requestBaselineChecksums
parameter_list|(
specifier|const
name|QString
modifier|&
name|testFunction
parameter_list|,
name|ImageItemList
modifier|*
name|itemList
parameter_list|)
block|{
name|errMsg
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|itemList
condition|)
return|return
literal|false
return|;
for|for
control|(
name|ImageItemList
operator|::
name|iterator
name|it
init|=
name|itemList
operator|->
name|begin
argument_list|()
init|;
name|it
operator|!=
name|itemList
operator|->
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
name|it
operator|->
name|testFunction
operator|=
name|testFunction
expr_stmt|;
name|QByteArray
name|block
decl_stmt|;
name|QDataStream
name|ds
argument_list|(
operator|&
name|block
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|ds
operator|<<
operator|*
name|itemList
expr_stmt|;
if|if
condition|(
operator|!
name|sendBlock
argument_list|(
name|RequestBaselineChecksums
argument_list|,
name|block
argument_list|)
condition|)
return|return
literal|false
return|;
name|Command
name|cmd
decl_stmt|;
name|QByteArray
name|rcvBlock
decl_stmt|;
if|if
condition|(
operator|!
name|receiveBlock
argument_list|(
operator|&
name|cmd
argument_list|,
operator|&
name|rcvBlock
argument_list|)
operator|||
name|cmd
operator|!=
name|BaselineProtocol
operator|::
name|Ack
condition|)
return|return
literal|false
return|;
name|QDataStream
name|rds
argument_list|(
operator|&
name|rcvBlock
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|rds
operator|>>
operator|*
name|itemList
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|submitNewBaseline
name|bool
name|BaselineProtocol
operator|::
name|submitNewBaseline
parameter_list|(
specifier|const
name|ImageItem
modifier|&
name|item
parameter_list|,
name|QByteArray
modifier|*
name|serverMsg
parameter_list|)
block|{
name|Command
name|cmd
decl_stmt|;
return|return
operator|(
name|sendItem
argument_list|(
name|AcceptNewBaseline
argument_list|,
name|item
argument_list|)
operator|&&
name|receiveBlock
argument_list|(
operator|&
name|cmd
argument_list|,
name|serverMsg
argument_list|)
operator|&&
name|cmd
operator|==
name|Ack
operator|)
return|;
block|}
end_function
begin_function
DECL|function|submitMismatch
name|bool
name|BaselineProtocol
operator|::
name|submitMismatch
parameter_list|(
specifier|const
name|ImageItem
modifier|&
name|item
parameter_list|,
name|QByteArray
modifier|*
name|serverMsg
parameter_list|)
block|{
name|Command
name|cmd
decl_stmt|;
return|return
operator|(
name|sendItem
argument_list|(
name|AcceptMismatch
argument_list|,
name|item
argument_list|)
operator|&&
name|receiveBlock
argument_list|(
operator|&
name|cmd
argument_list|,
name|serverMsg
argument_list|)
operator|&&
name|cmd
operator|==
name|Ack
operator|)
return|;
block|}
end_function
begin_function
DECL|function|sendItem
name|bool
name|BaselineProtocol
operator|::
name|sendItem
parameter_list|(
name|Command
name|cmd
parameter_list|,
specifier|const
name|ImageItem
modifier|&
name|item
parameter_list|)
block|{
name|errMsg
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QBuffer
name|buf
decl_stmt|;
name|buf
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|ds
argument_list|(
operator|&
name|buf
argument_list|)
decl_stmt|;
name|ds
operator|<<
name|item
expr_stmt|;
if|if
condition|(
operator|!
name|sendBlock
argument_list|(
name|cmd
argument_list|,
name|buf
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
name|errMsg
operator|.
name|prepend
argument_list|(
name|QLS
argument_list|(
literal|"Failed to submit image to server. "
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|sendBlock
name|bool
name|BaselineProtocol
operator|::
name|sendBlock
parameter_list|(
name|Command
name|cmd
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|block
parameter_list|)
block|{
name|QDataStream
name|s
argument_list|(
operator|&
name|socket
argument_list|)
decl_stmt|;
comment|// TBD: set qds version as a constant
name|s
operator|<<
name|quint16
argument_list|(
name|ProtocolVersion
argument_list|)
operator|<<
name|quint16
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
name|s
operator|.
name|writeBytes
argument_list|(
name|block
operator|.
name|constData
argument_list|()
argument_list|,
name|block
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|receiveBlock
name|bool
name|BaselineProtocol
operator|::
name|receiveBlock
parameter_list|(
name|Command
modifier|*
name|cmd
parameter_list|,
name|QByteArray
modifier|*
name|block
parameter_list|)
block|{
while|while
condition|(
name|socket
operator|.
name|bytesAvailable
argument_list|()
operator|<
name|int
argument_list|(
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|quint16
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForReadyRead
argument_list|(
name|Timeout
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
name|QDataStream
name|ds
argument_list|(
operator|&
name|socket
argument_list|)
decl_stmt|;
name|quint16
name|rcvProtocolVersion
decl_stmt|,
name|rcvCmd
decl_stmt|;
name|ds
operator|>>
name|rcvProtocolVersion
operator|>>
name|rcvCmd
expr_stmt|;
if|if
condition|(
name|rcvProtocolVersion
operator|!=
name|ProtocolVersion
condition|)
block|{
name|errMsg
operator|=
name|QLS
argument_list|(
literal|"Baseline protocol version mismatch, received:"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|rcvProtocolVersion
argument_list|)
operator|+
name|QLS
argument_list|(
literal|" expected:"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|ProtocolVersion
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|cmd
condition|)
operator|*
name|cmd
operator|=
name|Command
argument_list|(
name|rcvCmd
argument_list|)
expr_stmt|;
name|QByteArray
name|uMsg
decl_stmt|;
name|quint32
name|remaining
decl_stmt|;
name|ds
operator|>>
name|remaining
expr_stmt|;
name|uMsg
operator|.
name|resize
argument_list|(
name|remaining
argument_list|)
expr_stmt|;
name|int
name|got
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|uMsgBuf
init|=
name|uMsg
operator|.
name|data
argument_list|()
decl_stmt|;
do|do
block|{
name|got
operator|=
name|ds
operator|.
name|readRawData
argument_list|(
name|uMsgBuf
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
name|remaining
operator|-=
name|got
expr_stmt|;
name|uMsgBuf
operator|+=
name|got
expr_stmt|;
block|}
do|while
condition|(
name|remaining
operator|&&
name|got
operator|>=
literal|0
operator|&&
name|socket
operator|.
name|waitForReadyRead
argument_list|(
name|Timeout
argument_list|)
condition|)
do|;
if|if
condition|(
name|got
operator|<
literal|0
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|block
condition|)
operator|*
name|block
operator|=
name|uMsg
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|errorMessage
name|QString
name|BaselineProtocol
operator|::
name|errorMessage
parameter_list|()
block|{
name|QString
name|ret
init|=
name|errMsg
decl_stmt|;
if|if
condition|(
name|socket
operator|.
name|error
argument_list|()
operator|>=
literal|0
condition|)
name|ret
operator|+=
name|QLS
argument_list|(
literal|" Socket state: "
argument_list|)
operator|+
name|socket
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
end_unit
