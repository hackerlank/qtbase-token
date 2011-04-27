begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__NT__
argument_list|)
operator|)
end_if
begin_define
DECL|macro|QT_UNDEF_MACROS_IN_PCH
define|#
directive|define
name|QT_UNDEF_MACROS_IN_PCH
end_define
begin_define
DECL|macro|_WINSCARD_H_
define|#
directive|define
name|_WINSCARD_H_
end_define
begin_define
DECL|macro|_POSIX_
define|#
directive|define
name|_POSIX_
end_define
begin_comment
DECL|macro|_POSIX_
comment|/* Make sure PATH_MAX et al. are defined    */
end_comment
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_undef
DECL|macro|_POSIX_
undef|#
directive|undef
name|_POSIX_
end_undef
begin_comment
DECL|macro|_POSIX_
comment|/* Don't polute                             */
end_comment
begin_comment
comment|/* Make sure IP v6 is defined first of all, before windows.h     */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IPV6
end_ifndef
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
name|__cplusplus
end_if
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_comment
comment|// All moc genereated code has this include
end_comment
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qtextcodec.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
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
name|QT_UNDEF_MACROS_IN_PCH
argument_list|)
end_if
begin_undef
DECL|macro|max
undef|#
directive|undef
name|max
end_undef
begin_comment
DECL|macro|max
comment|/*  These are defined in windef.h, but                   */
end_comment
begin_undef
DECL|macro|min
undef|#
directive|undef
name|min
end_undef
begin_comment
DECL|macro|min
comment|/*  we don't want them when building Qt                  */
end_comment
begin_undef
DECL|macro|_WINSCARD_H_
undef|#
directive|undef
name|_WINSCARD_H_
end_undef
begin_endif
endif|#
directive|endif
end_endif
end_unit
