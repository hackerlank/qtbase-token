begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWSKEYBOARD_P_H
end_ifndef
begin_define
DECL|macro|QWSKEYBOARD_P_H
define|#
directive|define
name|QWSKEYBOARD_P_H
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
file|<QDataStream>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QWSKeyboard
block|{
specifier|const
name|quint32
name|FileMagic
init|=
literal|0x514d4150
decl_stmt|;
comment|// 'QMAP'
struct|struct
name|Mapping
block|{
name|quint16
name|keycode
decl_stmt|;
name|quint16
name|unicode
decl_stmt|;
name|quint32
name|qtcode
decl_stmt|;
name|quint8
name|modifiers
decl_stmt|;
name|quint8
name|flags
decl_stmt|;
name|quint16
name|special
decl_stmt|;
block|}
struct|;
enum|enum
name|Flags
block|{
name|IsDead
init|=
literal|0x01
block|,
name|IsLetter
init|=
literal|0x02
block|,
name|IsModifier
init|=
literal|0x04
block|,
name|IsSystem
init|=
literal|0x08
block|,     }
enum|;
enum|enum
name|System
block|{
name|SystemConsoleFirst
init|=
literal|0x0100
block|,
name|SystemConsoleMask
init|=
literal|0x007f
block|,
name|SystemConsoleLast
init|=
literal|0x017f
block|,
name|SystemConsolePrevious
init|=
literal|0x0180
block|,
name|SystemConsoleNext
init|=
literal|0x0181
block|,
name|SystemReboot
init|=
literal|0x0200
block|,
name|SystemZap
init|=
literal|0x0300
block|,     }
enum|;
struct|struct
name|Composing
block|{
name|quint16
name|first
decl_stmt|;
name|quint16
name|second
decl_stmt|;
name|quint16
name|result
decl_stmt|;
block|}
struct|;
enum|enum
name|Modifiers
block|{
name|ModPlain
init|=
literal|0x00
block|,
name|ModShift
init|=
literal|0x01
block|,
name|ModAltGr
init|=
literal|0x02
block|,
name|ModControl
init|=
literal|0x04
block|,
name|ModAlt
init|=
literal|0x08
block|,
name|ModShiftL
init|=
literal|0x10
block|,
name|ModShiftR
init|=
literal|0x20
block|,
name|ModCtrlL
init|=
literal|0x40
block|,
name|ModCtrlR
init|=
literal|0x80
block|,
comment|// ModCapsShift = 0x100, // not supported!
block|}
enum|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QWSKeyboard
operator|::
name|Mapping
operator|&
name|m
operator|)
block|{
return|return
name|ds
operator|>>
name|m
operator|.
name|keycode
operator|>>
name|m
operator|.
name|unicode
operator|>>
name|m
operator|.
name|qtcode
operator|>>
name|m
operator|.
name|modifiers
operator|>>
name|m
operator|.
name|flags
operator|>>
name|m
operator|.
name|special
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QWSKeyboard
operator|::
name|Mapping
operator|&
name|m
operator|)
block|{
return|return
name|ds
operator|<<
name|m
operator|.
name|keycode
operator|<<
name|m
operator|.
name|unicode
operator|<<
name|m
operator|.
name|qtcode
operator|<<
name|m
operator|.
name|modifiers
operator|<<
name|m
operator|.
name|flags
operator|<<
name|m
operator|.
name|special
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QWSKeyboard
operator|::
name|Composing
operator|&
name|c
operator|)
block|{
return|return
name|ds
operator|>>
name|c
operator|.
name|first
operator|>>
name|c
operator|.
name|second
operator|>>
name|c
operator|.
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QWSKeyboard
operator|::
name|Composing
operator|&
name|c
operator|)
block|{
return|return
name|ds
operator|<<
name|c
operator|.
name|first
operator|<<
name|c
operator|.
name|second
operator|<<
name|c
operator|.
name|result
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWSKEYBOARD_H
end_comment
end_unit
