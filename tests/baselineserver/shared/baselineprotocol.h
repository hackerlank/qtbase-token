begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BASELINEPROTOCOL_H
end_ifndef
begin_define
DECL|macro|BASELINEPROTOCOL_H
define|#
directive|define
name|BASELINEPROTOCOL_H
end_define
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_define
DECL|macro|QLS
define|#
directive|define
name|QLS
value|QLatin1String
end_define
begin_define
DECL|macro|QLC
define|#
directive|define
name|QLC
value|QLatin1Char
end_define
begin_define
DECL|macro|FileFormat
define|#
directive|define
name|FileFormat
value|"png"
end_define
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_TestCase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_HostName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_HostAddress
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_OSName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_OSVersion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_QtVersion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_QtBuildMode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_GitCommit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_QMakeSpec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_PulseGitBranch
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|QString
name|PI_PulseTestrBranch
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|PlatformInfo
range|:
name|public
name|QMap
operator|<
name|QString
decl_stmt|,
name|QString
decl|>
block|{
name|public
label|:
name|PlatformInfo
argument_list|()
expr_stmt|;
name|PlatformInfo
argument_list|(
specifier|const
name|PlatformInfo
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|PlatformInfo
argument_list|()
block|{}
name|PlatformInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PlatformInfo
operator|&
name|other
operator|)
expr_stmt|;
specifier|static
name|PlatformInfo
name|localHostInfo
parameter_list|()
function_decl|;
name|void
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
function_decl|;
name|QStringList
name|overrides
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isAdHocRun
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAdHocRun
parameter_list|(
name|bool
name|isAdHoc
parameter_list|)
function_decl|;
name|private
label|:
name|QStringList
name|orides
decl_stmt|;
name|bool
name|adHoc
decl_stmt|;
name|friend
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|PlatformInfo
operator|&
name|pi
operator|)
expr_stmt|;
name|friend
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|PlatformInfo
operator|&
name|pi
operator|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|PlatformInfo
operator|&
name|pi
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|PlatformInfo
operator|&
name|pi
operator|)
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|ImageItem
struct|struct
name|ImageItem
block|{
DECL|member|public
name|public
label|:
name|ImageItem
argument_list|()
operator|:
name|status
argument_list|(
name|Ok
argument_list|)
operator|,
name|itemChecksum
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|ImageItem
name|ImageItem
argument_list|(
argument|const ImageItem&other
argument_list|)
block|{
operator|*
name|this
operator|=
name|other
block|; }
DECL|function|~ImageItem
operator|~
name|ImageItem
argument_list|()
block|{}
DECL|member|operator
name|ImageItem
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ImageItem
operator|&
name|other
operator|)
expr_stmt|;
specifier|static
name|quint64
name|computeChecksum
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
DECL|enum|ItemStatus
enum|enum
name|ItemStatus
block|{
DECL|enumerator|Ok
name|Ok
init|=
literal|0
block|,
DECL|enumerator|BaselineNotFound
name|BaselineNotFound
init|=
literal|1
block|,
DECL|enumerator|IgnoreItem
name|IgnoreItem
init|=
literal|2
block|,
DECL|enumerator|Mismatch
name|Mismatch
init|=
literal|3
block|}
enum|;
DECL|member|testFunction
name|QString
name|testFunction
decl_stmt|;
DECL|member|itemName
name|QString
name|itemName
decl_stmt|;
DECL|member|status
name|ItemStatus
name|status
decl_stmt|;
DECL|member|image
name|QImage
name|image
decl_stmt|;
DECL|member|imageChecksums
name|QList
operator|<
name|quint64
operator|>
name|imageChecksums
expr_stmt|;
DECL|member|itemChecksum
name|quint16
name|itemChecksum
decl_stmt|;
DECL|member|misc
name|QByteArray
name|misc
decl_stmt|;
name|void
name|writeImageToStream
argument_list|(
name|QDataStream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
name|void
name|readImageFromStream
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|stream
operator|,
specifier|const
name|ImageItem
operator|&
name|ii
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|stream
operator|,
name|ImageItem
operator|&
name|ii
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|ImageItem
name|Q_DECLARE_METATYPE
argument_list|(
name|ImageItem
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|ImageItemList
typedef|typedef
name|QVector
operator|<
name|ImageItem
operator|>
name|ImageItemList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|BaselineProtocol
block|{
name|public
label|:
name|BaselineProtocol
argument_list|()
expr_stmt|;
operator|~
name|BaselineProtocol
argument_list|()
expr_stmt|;
specifier|static
name|BaselineProtocol
modifier|*
name|instance
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
comment|// ****************************************************
comment|// Important constants here
comment|// ****************************************************
enum|enum
name|Constant
block|{
name|ProtocolVersion
init|=
literal|5
block|,
name|ServerPort
init|=
literal|54129
block|,
name|Timeout
init|=
literal|15000
block|}
enum|;
enum|enum
name|Command
block|{
name|UnknownError
init|=
literal|0
block|,
comment|// Queries
name|AcceptPlatformInfo
init|=
literal|1
block|,
name|RequestBaselineChecksums
init|=
literal|2
block|,
name|AcceptNewBaseline
init|=
literal|4
block|,
name|AcceptMismatch
init|=
literal|5
block|,
comment|// Responses
name|Ack
init|=
literal|128
block|,
name|Abort
init|=
literal|129
block|,
name|DoDryRun
init|=
literal|130
block|}
enum|;
comment|// For client:
comment|// For advanced client:
name|bool
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
init|=
literal|0
parameter_list|,
specifier|const
name|PlatformInfo
modifier|&
name|clientInfo
init|=
name|PlatformInfo
argument_list|()
parameter_list|)
function_decl|;
name|bool
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
function_decl|;
name|bool
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
function_decl|;
name|bool
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
function_decl|;
comment|// For server:
name|bool
name|acceptConnection
parameter_list|(
name|PlatformInfo
modifier|*
name|pi
parameter_list|)
function_decl|;
name|QString
name|errorMessage
parameter_list|()
function_decl|;
name|private
label|:
name|bool
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
function_decl|;
name|bool
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
function_decl|;
name|bool
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
function_decl|;
name|void
name|sysSleep
parameter_list|(
name|int
name|ms
parameter_list|)
function_decl|;
name|QString
name|errMsg
decl_stmt|;
name|QTcpSocket
name|socket
decl_stmt|;
name|friend
name|class
name|BaselineThread
decl_stmt|;
name|friend
name|class
name|BaselineHandler
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BASELINEPROTOCOL_H
end_comment
end_unit
