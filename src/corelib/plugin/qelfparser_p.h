begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QELFPARSER_P_H
end_ifndef
begin_define
DECL|macro|QELFPARSER_P_H
define|#
directive|define
name|QELFPARSER_P_H
end_define
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
begin_include
include|#
directive|include
file|<qendian.h>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OF_ELF
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLibraryPrivate
name|class
name|QLibraryPrivate
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|qelfhalf_t
typedef|typedef
name|quint16
name|qelfhalf_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|qelfword_t
typedef|typedef
name|quint32
name|qelfword_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|qelfoff_t
typedef|typedef
name|quintptr
name|qelfoff_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|qelfaddr_t
typedef|typedef
name|quintptr
name|qelfaddr_t
typedef|;
end_typedef
begin_decl_stmt
name|class
name|QElfParser
block|{
name|public
label|:
enum|enum
block|{
name|QtMetaDataSection
block|,
name|NoQtSection
block|,
name|NotElf
block|,
name|Corrupt
block|}
enum|;
enum|enum
block|{
name|ElfLittleEndian
init|=
literal|0
block|,
name|ElfBigEndian
init|=
literal|1
block|}
enum|;
struct|struct
name|ElfSectionHeader
block|{
name|qelfword_t
name|name
decl_stmt|;
name|qelfword_t
name|type
decl_stmt|;
name|qelfoff_t
name|offset
decl_stmt|;
name|qelfoff_t
name|size
decl_stmt|;
block|}
struct|;
name|int
name|m_endian
decl_stmt|;
name|int
name|m_bits
decl_stmt|;
name|int
name|m_stringTableFileOffset
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|read
argument_list|(
argument|const char *s
argument_list|)
block|{
if|if
condition|(
name|m_endian
operator|==
name|ElfBigEndian
condition|)
return|return
name|qFromBigEndian
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|s
operator|)
operator|)
return|;
else|else
return|return
name|qFromLittleEndian
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|s
operator|)
operator|)
return|;
block|}
specifier|const
name|char
modifier|*
name|parseSectionHeader
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ElfSectionHeader
modifier|*
name|sh
parameter_list|)
function_decl|;
name|int
name|parse
parameter_list|(
specifier|const
name|char
modifier|*
name|m_s
parameter_list|,
name|ulong
name|fdlen
parameter_list|,
specifier|const
name|QString
modifier|&
name|library
parameter_list|,
name|QLibraryPrivate
modifier|*
name|lib
parameter_list|,
name|long
modifier|*
name|pos
parameter_list|,
name|ulong
modifier|*
name|sectionlen
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// defined(Q_OF_ELF)&& defined(Q_CC_GNU)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QELFPARSER_P_H
end_comment
end_unit
