begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTERINFO_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QPRINTERINFO_UNIX_P_H
define|#
directive|define
name|QPRINTERINFO_UNIX_P_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NIS
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|BOOL_DEFINED
end_ifndef
begin_define
DECL|macro|BOOL_DEFINED
define|#
directive|define
name|BOOL_DEFINED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include
begin_include
include|#
directive|include
file|<rpcsvc/ypclnt.h>
end_include
begin_include
include|#
directive|include
file|<rpcsvc/yp_prot.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NIS
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Success
end_ifdef
begin_undef
DECL|macro|Success
undef|#
directive|undef
name|Success
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_struct
DECL|struct|QPrinterDescription
struct|struct
name|QPrinterDescription
block|{
DECL|function|QPrinterDescription
name|QPrinterDescription
argument_list|(
specifier|const
name|QString
operator|&
name|n
argument_list|,
specifier|const
name|QString
operator|&
name|h
argument_list|,
specifier|const
name|QString
operator|&
name|c
argument_list|,
specifier|const
name|QStringList
operator|&
name|a
argument_list|)
operator|:
name|name
argument_list|(
name|n
argument_list|)
operator|,
name|host
argument_list|(
name|h
argument_list|)
operator|,
name|comment
argument_list|(
name|c
argument_list|)
operator|,
name|aliases
argument_list|(
argument|a
argument_list|)
block|{}
DECL|member|name
name|QString
name|name
expr_stmt|;
DECL|member|host
name|QString
name|host
decl_stmt|;
DECL|member|comment
name|QString
name|comment
decl_stmt|;
DECL|member|aliases
name|QStringList
name|aliases
decl_stmt|;
DECL|function|samePrinter
name|bool
name|samePrinter
argument_list|(
specifier|const
name|QString
operator|&
name|printer
argument_list|)
decl|const
block|{
return|return
name|name
operator|==
name|printer
operator|||
name|aliases
operator|.
name|contains
argument_list|(
name|printer
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_enum
DECL|enumerator|Success
DECL|enumerator|Unavail
DECL|enumerator|NotFound
DECL|enumerator|TryAgain
enum|enum
block|{
name|Success
init|=
literal|'s'
block|,
name|Unavail
init|=
literal|'u'
block|,
name|NotFound
init|=
literal|'n'
block|,
name|TryAgain
init|=
literal|'t'
block|}
enum|;
end_enum
begin_enum
DECL|enumerator|Continue
DECL|enumerator|Return
enum|enum
block|{
name|Continue
init|=
literal|'c'
block|,
name|Return
init|=
literal|'r'
block|}
enum|;
end_enum
begin_decl_stmt
name|void
name|qt_perhapsAddPrinter
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QString
name|host
argument_list|,
name|QString
name|comment
argument_list|,
name|QStringList
name|aliases
operator|=
name|QStringList
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|qt_parsePrinterDesc
argument_list|(
name|QString
name|printerDesc
argument_list|,
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|qt_parsePrintcap
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QString
name|qt_getDefaultFromHomePrinters
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|qt_parseEtcLpPrinters
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|char
modifier|*
name|qt_parsePrintersConf
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|,
name|bool
operator|*
name|found
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NIS
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_C_CALLBACKS
argument_list|)
end_if
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|int
name|qt_pd_foreach
parameter_list|(
name|int
comment|/*status */
parameter_list|,
name|char
modifier|*
comment|/*key */
parameter_list|,
name|int
comment|/*keyLen */
parameter_list|,
name|char
modifier|*
name|val
parameter_list|,
name|int
name|valLen
parameter_list|,
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_C_CALLBACKS
argument_list|)
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|int
name|qt_retrieveNisPrinters
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NIS
end_comment
begin_decl_stmt
name|char
modifier|*
name|qt_parseNsswitchPrintersEntry
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|,
name|char
operator|*
name|line
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|char
modifier|*
name|qt_parseNsswitchConf
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|qt_parseEtcLpMember
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|qt_parseSpoolInterface
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|qt_parseQconfig
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|*
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|qt_getLprPrinters
argument_list|(
name|QList
operator|<
name|QPrinterDescription
operator|>
operator|&
name|printers
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTERINFO_UNIX_P_H
end_comment
end_unit
