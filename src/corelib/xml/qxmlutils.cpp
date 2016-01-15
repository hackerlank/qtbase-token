begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|"qxmlutils_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/* TODO:  * - isNameChar() doesn't have to be public, it's only needed in  *   qdom.cpp -- refactor fixedXmlName() to use isNCName()  * - A lot of functions can be inlined.  */
end_comment
begin_class
DECL|class|QXmlCharRange
class|class
name|QXmlCharRange
block|{
public|public:
DECL|member|min
name|ushort
name|min
decl_stmt|;
DECL|member|max
name|ushort
name|max
decl_stmt|;
block|}
class|;
end_class
begin_typedef
DECL|typedef|RangeIter
typedef|typedef
specifier|const
name|QXmlCharRange
modifier|*
name|RangeIter
typedef|;
end_typedef
begin_comment
comment|/*!   Performs a binary search between \a begin and \a end inclusive, to check whether \a   c is contained. Remember that the QXmlCharRange instances must be in numeric order.  */
end_comment
begin_function
DECL|function|rangeContains
name|bool
name|QXmlUtils
operator|::
name|rangeContains
parameter_list|(
name|RangeIter
name|begin
parameter_list|,
name|RangeIter
name|end
parameter_list|,
specifier|const
name|QChar
name|c
parameter_list|)
block|{
specifier|const
name|ushort
name|cp
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|)
decl_stmt|;
comment|// check the first two ranges "manually" as characters in that
comment|// range are checked very often and we avoid the binary search below.
if|if
condition|(
name|cp
operator|<=
name|begin
operator|->
name|max
condition|)
return|return
name|cp
operator|>=
name|begin
operator|->
name|min
return|;
operator|++
name|begin
expr_stmt|;
if|if
condition|(
name|begin
operator|==
name|end
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|cp
operator|<=
name|begin
operator|->
name|max
condition|)
return|return
name|cp
operator|>=
name|begin
operator|->
name|min
return|;
while|while
condition|(
name|begin
operator|!=
name|end
condition|)
block|{
name|int
name|delta
init|=
operator|(
name|end
operator|-
name|begin
operator|)
operator|/
literal|2
decl_stmt|;
name|RangeIter
name|mid
init|=
name|begin
operator|+
name|delta
decl_stmt|;
if|if
condition|(
name|mid
operator|->
name|min
operator|>
name|cp
condition|)
name|end
operator|=
name|mid
expr_stmt|;
elseif|else
if|if
condition|(
name|mid
operator|->
name|max
operator|<
name|cp
condition|)
name|begin
operator|=
name|mid
expr_stmt|;
else|else
return|return
literal|true
return|;
if|if
condition|(
name|delta
operator|==
literal|0
condition|)
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// [85] BaseChar ::= ...
end_comment
begin_decl_stmt
DECL|variable|g_base_begin
specifier|static
specifier|const
name|QXmlCharRange
name|g_base_begin
index|[]
init|=
block|{
block|{
literal|0x0041
block|,
literal|0x005A
block|}
block|,
block|{
literal|0x0061
block|,
literal|0x007A
block|}
block|,
block|{
literal|0x00C0
block|,
literal|0x00D6
block|}
block|,
block|{
literal|0x00D8
block|,
literal|0x00F6
block|}
block|,
block|{
literal|0x00F8
block|,
literal|0x00FF
block|}
block|,
block|{
literal|0x0100
block|,
literal|0x0131
block|}
block|,
block|{
literal|0x0134
block|,
literal|0x013E
block|}
block|,
block|{
literal|0x0141
block|,
literal|0x0148
block|}
block|,
block|{
literal|0x014A
block|,
literal|0x017E
block|}
block|,
block|{
literal|0x0180
block|,
literal|0x01C3
block|}
block|,
block|{
literal|0x01CD
block|,
literal|0x01F0
block|}
block|,
block|{
literal|0x01F4
block|,
literal|0x01F5
block|}
block|,
block|{
literal|0x01FA
block|,
literal|0x0217
block|}
block|,
block|{
literal|0x0250
block|,
literal|0x02A8
block|}
block|,
block|{
literal|0x02BB
block|,
literal|0x02C1
block|}
block|,
block|{
literal|0x0386
block|,
literal|0x0386
block|}
block|,
block|{
literal|0x0388
block|,
literal|0x038A
block|}
block|,
block|{
literal|0x038C
block|,
literal|0x038C
block|}
block|,
block|{
literal|0x038E
block|,
literal|0x03A1
block|}
block|,
block|{
literal|0x03A3
block|,
literal|0x03CE
block|}
block|,
block|{
literal|0x03D0
block|,
literal|0x03D6
block|}
block|,
block|{
literal|0x03DA
block|,
literal|0x03DA
block|}
block|,
block|{
literal|0x03DC
block|,
literal|0x03DC
block|}
block|,
block|{
literal|0x03DE
block|,
literal|0x03DE
block|}
block|,
block|{
literal|0x03E0
block|,
literal|0x03E0
block|}
block|,
block|{
literal|0x03E2
block|,
literal|0x03F3
block|}
block|,
block|{
literal|0x0401
block|,
literal|0x040C
block|}
block|,
block|{
literal|0x040E
block|,
literal|0x044F
block|}
block|,
block|{
literal|0x0451
block|,
literal|0x045C
block|}
block|,
block|{
literal|0x045E
block|,
literal|0x0481
block|}
block|,
block|{
literal|0x0490
block|,
literal|0x04C4
block|}
block|,
block|{
literal|0x04C7
block|,
literal|0x04C8
block|}
block|,
block|{
literal|0x04CB
block|,
literal|0x04CC
block|}
block|,
block|{
literal|0x04D0
block|,
literal|0x04EB
block|}
block|,
block|{
literal|0x04EE
block|,
literal|0x04F5
block|}
block|,
block|{
literal|0x04F8
block|,
literal|0x04F9
block|}
block|,
block|{
literal|0x0531
block|,
literal|0x0556
block|}
block|,
block|{
literal|0x0559
block|,
literal|0x0559
block|}
block|,
block|{
literal|0x0561
block|,
literal|0x0586
block|}
block|,
block|{
literal|0x05D0
block|,
literal|0x05EA
block|}
block|,
block|{
literal|0x05F0
block|,
literal|0x05F2
block|}
block|,
block|{
literal|0x0621
block|,
literal|0x063A
block|}
block|,
block|{
literal|0x0641
block|,
literal|0x064A
block|}
block|,
block|{
literal|0x0671
block|,
literal|0x06B7
block|}
block|,
block|{
literal|0x06BA
block|,
literal|0x06BE
block|}
block|,
block|{
literal|0x06C0
block|,
literal|0x06CE
block|}
block|,
block|{
literal|0x06D0
block|,
literal|0x06D3
block|}
block|,
block|{
literal|0x06D5
block|,
literal|0x06D5
block|}
block|,
block|{
literal|0x06E5
block|,
literal|0x06E6
block|}
block|,
block|{
literal|0x0905
block|,
literal|0x0939
block|}
block|,
block|{
literal|0x093D
block|,
literal|0x093D
block|}
block|,
block|{
literal|0x0958
block|,
literal|0x0961
block|}
block|,
block|{
literal|0x0985
block|,
literal|0x098C
block|}
block|,
block|{
literal|0x098F
block|,
literal|0x0990
block|}
block|,
block|{
literal|0x0993
block|,
literal|0x09A8
block|}
block|,
block|{
literal|0x09AA
block|,
literal|0x09B0
block|}
block|,
block|{
literal|0x09B2
block|,
literal|0x09B2
block|}
block|,
block|{
literal|0x09B6
block|,
literal|0x09B9
block|}
block|,
block|{
literal|0x09DC
block|,
literal|0x09DD
block|}
block|,
block|{
literal|0x09DF
block|,
literal|0x09E1
block|}
block|,
block|{
literal|0x09F0
block|,
literal|0x09F1
block|}
block|,
block|{
literal|0x0A05
block|,
literal|0x0A0A
block|}
block|,
block|{
literal|0x0A0F
block|,
literal|0x0A10
block|}
block|,
block|{
literal|0x0A13
block|,
literal|0x0A28
block|}
block|,
block|{
literal|0x0A2A
block|,
literal|0x0A30
block|}
block|,
block|{
literal|0x0A32
block|,
literal|0x0A33
block|}
block|,
block|{
literal|0x0A35
block|,
literal|0x0A36
block|}
block|,
block|{
literal|0x0A38
block|,
literal|0x0A39
block|}
block|,
block|{
literal|0x0A59
block|,
literal|0x0A5C
block|}
block|,
block|{
literal|0x0A5E
block|,
literal|0x0A5E
block|}
block|,
block|{
literal|0x0A72
block|,
literal|0x0A74
block|}
block|,
block|{
literal|0x0A85
block|,
literal|0x0A8B
block|}
block|,
block|{
literal|0x0A8D
block|,
literal|0x0A8D
block|}
block|,
block|{
literal|0x0A8F
block|,
literal|0x0A91
block|}
block|,
block|{
literal|0x0A93
block|,
literal|0x0AA8
block|}
block|,
block|{
literal|0x0AAA
block|,
literal|0x0AB0
block|}
block|,
block|{
literal|0x0AB2
block|,
literal|0x0AB3
block|}
block|,
block|{
literal|0x0AB5
block|,
literal|0x0AB9
block|}
block|,
block|{
literal|0x0ABD
block|,
literal|0x0ABD
block|}
block|,
block|{
literal|0x0AE0
block|,
literal|0x0AE0
block|}
block|,
block|{
literal|0x0B05
block|,
literal|0x0B0C
block|}
block|,
block|{
literal|0x0B0F
block|,
literal|0x0B10
block|}
block|,
block|{
literal|0x0B13
block|,
literal|0x0B28
block|}
block|,
block|{
literal|0x0B2A
block|,
literal|0x0B30
block|}
block|,
block|{
literal|0x0B32
block|,
literal|0x0B33
block|}
block|,
block|{
literal|0x0B36
block|,
literal|0x0B39
block|}
block|,
block|{
literal|0x0B3D
block|,
literal|0x0B3D
block|}
block|,
block|{
literal|0x0B5C
block|,
literal|0x0B5D
block|}
block|,
block|{
literal|0x0B5F
block|,
literal|0x0B61
block|}
block|,
block|{
literal|0x0B85
block|,
literal|0x0B8A
block|}
block|,
block|{
literal|0x0B8E
block|,
literal|0x0B90
block|}
block|,
block|{
literal|0x0B92
block|,
literal|0x0B95
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0B9A
block|}
block|,
block|{
literal|0x0B9C
block|,
literal|0x0B9C
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0B9F
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0BA4
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0BAA
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0BB5
block|}
block|,
block|{
literal|0x0BB7
block|,
literal|0x0BB9
block|}
block|,
block|{
literal|0x0C05
block|,
literal|0x0C0C
block|}
block|,
block|{
literal|0x0C0E
block|,
literal|0x0C10
block|}
block|,
block|{
literal|0x0C12
block|,
literal|0x0C28
block|}
block|,
block|{
literal|0x0C2A
block|,
literal|0x0C33
block|}
block|,
block|{
literal|0x0C35
block|,
literal|0x0C39
block|}
block|,
block|{
literal|0x0C60
block|,
literal|0x0C61
block|}
block|,
block|{
literal|0x0C85
block|,
literal|0x0C8C
block|}
block|,
block|{
literal|0x0C8E
block|,
literal|0x0C90
block|}
block|,
block|{
literal|0x0C92
block|,
literal|0x0CA8
block|}
block|,
block|{
literal|0x0CAA
block|,
literal|0x0CB3
block|}
block|,
block|{
literal|0x0CB5
block|,
literal|0x0CB9
block|}
block|,
block|{
literal|0x0CDE
block|,
literal|0x0CDE
block|}
block|,
block|{
literal|0x0CE0
block|,
literal|0x0CE1
block|}
block|,
block|{
literal|0x0D05
block|,
literal|0x0D0C
block|}
block|,
block|{
literal|0x0D0E
block|,
literal|0x0D10
block|}
block|,
block|{
literal|0x0D12
block|,
literal|0x0D28
block|}
block|,
block|{
literal|0x0D2A
block|,
literal|0x0D39
block|}
block|,
block|{
literal|0x0D60
block|,
literal|0x0D61
block|}
block|,
block|{
literal|0x0E01
block|,
literal|0x0E2E
block|}
block|,
block|{
literal|0x0E30
block|,
literal|0x0E30
block|}
block|,
block|{
literal|0x0E32
block|,
literal|0x0E33
block|}
block|,
block|{
literal|0x0E40
block|,
literal|0x0E45
block|}
block|,
block|{
literal|0x0E81
block|,
literal|0x0E82
block|}
block|,
block|{
literal|0x0E84
block|,
literal|0x0E84
block|}
block|,
block|{
literal|0x0E87
block|,
literal|0x0E88
block|}
block|,
block|{
literal|0x0E8A
block|,
literal|0x0E8A
block|}
block|,
block|{
literal|0x0E8D
block|,
literal|0x0E8D
block|}
block|,
block|{
literal|0x0E94
block|,
literal|0x0E97
block|}
block|,
block|{
literal|0x0E99
block|,
literal|0x0E9F
block|}
block|,
block|{
literal|0x0EA1
block|,
literal|0x0EA3
block|}
block|,
block|{
literal|0x0EA5
block|,
literal|0x0EA5
block|}
block|,
block|{
literal|0x0EA7
block|,
literal|0x0EA7
block|}
block|,
block|{
literal|0x0EAA
block|,
literal|0x0EAB
block|}
block|,
block|{
literal|0x0EAD
block|,
literal|0x0EAE
block|}
block|,
block|{
literal|0x0EB0
block|,
literal|0x0EB0
block|}
block|,
block|{
literal|0x0EB2
block|,
literal|0x0EB3
block|}
block|,
block|{
literal|0x0EBD
block|,
literal|0x0EBD
block|}
block|,
block|{
literal|0x0EC0
block|,
literal|0x0EC4
block|}
block|,
block|{
literal|0x0F40
block|,
literal|0x0F47
block|}
block|,
block|{
literal|0x0F49
block|,
literal|0x0F69
block|}
block|,
block|{
literal|0x10A0
block|,
literal|0x10C5
block|}
block|,
block|{
literal|0x10D0
block|,
literal|0x10F6
block|}
block|,
block|{
literal|0x1100
block|,
literal|0x1100
block|}
block|,
block|{
literal|0x1102
block|,
literal|0x1103
block|}
block|,
block|{
literal|0x1105
block|,
literal|0x1107
block|}
block|,
block|{
literal|0x1109
block|,
literal|0x1109
block|}
block|,
block|{
literal|0x110B
block|,
literal|0x110C
block|}
block|,
block|{
literal|0x110E
block|,
literal|0x1112
block|}
block|,
block|{
literal|0x113C
block|,
literal|0x113C
block|}
block|,
block|{
literal|0x113E
block|,
literal|0x113E
block|}
block|,
block|{
literal|0x1140
block|,
literal|0x1140
block|}
block|,
block|{
literal|0x114C
block|,
literal|0x114C
block|}
block|,
block|{
literal|0x114E
block|,
literal|0x114E
block|}
block|,
block|{
literal|0x1150
block|,
literal|0x1150
block|}
block|,
block|{
literal|0x1154
block|,
literal|0x1155
block|}
block|,
block|{
literal|0x1159
block|,
literal|0x1159
block|}
block|,
block|{
literal|0x115F
block|,
literal|0x1161
block|}
block|,
block|{
literal|0x1163
block|,
literal|0x1163
block|}
block|,
block|{
literal|0x1165
block|,
literal|0x1165
block|}
block|,
block|{
literal|0x1167
block|,
literal|0x1167
block|}
block|,
block|{
literal|0x1169
block|,
literal|0x1169
block|}
block|,
block|{
literal|0x116D
block|,
literal|0x116E
block|}
block|,
block|{
literal|0x1172
block|,
literal|0x1173
block|}
block|,
block|{
literal|0x1175
block|,
literal|0x1175
block|}
block|,
block|{
literal|0x119E
block|,
literal|0x119E
block|}
block|,
block|{
literal|0x11A8
block|,
literal|0x11A8
block|}
block|,
block|{
literal|0x11AB
block|,
literal|0x11AB
block|}
block|,
block|{
literal|0x11AE
block|,
literal|0x11AF
block|}
block|,
block|{
literal|0x11B7
block|,
literal|0x11B8
block|}
block|,
block|{
literal|0x11BA
block|,
literal|0x11BA
block|}
block|,
block|{
literal|0x11BC
block|,
literal|0x11C2
block|}
block|,
block|{
literal|0x11EB
block|,
literal|0x11EB
block|}
block|,
block|{
literal|0x11F0
block|,
literal|0x11F0
block|}
block|,
block|{
literal|0x11F9
block|,
literal|0x11F9
block|}
block|,
block|{
literal|0x1E00
block|,
literal|0x1E9B
block|}
block|,
block|{
literal|0x1EA0
block|,
literal|0x1EF9
block|}
block|,
block|{
literal|0x1F00
block|,
literal|0x1F15
block|}
block|,
block|{
literal|0x1F18
block|,
literal|0x1F1D
block|}
block|,
block|{
literal|0x1F20
block|,
literal|0x1F45
block|}
block|,
block|{
literal|0x1F48
block|,
literal|0x1F4D
block|}
block|,
block|{
literal|0x1F50
block|,
literal|0x1F57
block|}
block|,
block|{
literal|0x1F59
block|,
literal|0x1F59
block|}
block|,
block|{
literal|0x1F5B
block|,
literal|0x1F5B
block|}
block|,
block|{
literal|0x1F5D
block|,
literal|0x1F5D
block|}
block|,
block|{
literal|0x1F5F
block|,
literal|0x1F7D
block|}
block|,
block|{
literal|0x1F80
block|,
literal|0x1FB4
block|}
block|,
block|{
literal|0x1FB6
block|,
literal|0x1FBC
block|}
block|,
block|{
literal|0x1FBE
block|,
literal|0x1FBE
block|}
block|,
block|{
literal|0x1FC2
block|,
literal|0x1FC4
block|}
block|,
block|{
literal|0x1FC6
block|,
literal|0x1FCC
block|}
block|,
block|{
literal|0x1FD0
block|,
literal|0x1FD3
block|}
block|,
block|{
literal|0x1FD6
block|,
literal|0x1FDB
block|}
block|,
block|{
literal|0x1FE0
block|,
literal|0x1FEC
block|}
block|,
block|{
literal|0x1FF2
block|,
literal|0x1FF4
block|}
block|,
block|{
literal|0x1FF6
block|,
literal|0x1FFC
block|}
block|,
block|{
literal|0x2126
block|,
literal|0x2126
block|}
block|,
block|{
literal|0x212A
block|,
literal|0x212B
block|}
block|,
block|{
literal|0x212E
block|,
literal|0x212E
block|}
block|,
block|{
literal|0x2180
block|,
literal|0x2182
block|}
block|,
block|{
literal|0x3041
block|,
literal|0x3094
block|}
block|,
block|{
literal|0x30A1
block|,
literal|0x30FA
block|}
block|,
block|{
literal|0x3105
block|,
literal|0x312C
block|}
block|,
block|{
literal|0xAC00
block|,
literal|0xD7A3
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_base_end
specifier|static
specifier|const
name|RangeIter
name|g_base_end
init|=
name|g_base_begin
operator|+
sizeof|sizeof
argument_list|(
name|g_base_begin
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QXmlCharRange
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_ideographic_begin
specifier|static
specifier|const
name|QXmlCharRange
name|g_ideographic_begin
index|[]
init|=
block|{
block|{
literal|0x3007
block|,
literal|0x3007
block|}
block|,
block|{
literal|0x3021
block|,
literal|0x3029
block|}
block|,
block|{
literal|0x4E00
block|,
literal|0x9FA5
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_ideographic_end
specifier|static
specifier|const
name|RangeIter
name|g_ideographic_end
init|=
name|g_ideographic_begin
operator|+
sizeof|sizeof
argument_list|(
name|g_ideographic_begin
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QXmlCharRange
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isIdeographic
name|bool
name|QXmlUtils
operator|::
name|isIdeographic
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|rangeContains
argument_list|(
name|g_ideographic_begin
argument_list|,
name|g_ideographic_end
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|g_combining_begin
specifier|static
specifier|const
name|QXmlCharRange
name|g_combining_begin
index|[]
init|=
block|{
block|{
literal|0x0300
block|,
literal|0x0345
block|}
block|,
block|{
literal|0x0360
block|,
literal|0x0361
block|}
block|,
block|{
literal|0x0483
block|,
literal|0x0486
block|}
block|,
block|{
literal|0x0591
block|,
literal|0x05A1
block|}
block|,
block|{
literal|0x05A3
block|,
literal|0x05B9
block|}
block|,
block|{
literal|0x05BB
block|,
literal|0x05BD
block|}
block|,
block|{
literal|0x05BF
block|,
literal|0x05BF
block|}
block|,
block|{
literal|0x05C1
block|,
literal|0x05C2
block|}
block|,
block|{
literal|0x05C4
block|,
literal|0x05C4
block|}
block|,
block|{
literal|0x064B
block|,
literal|0x0652
block|}
block|,
block|{
literal|0x0670
block|,
literal|0x0670
block|}
block|,
block|{
literal|0x06D6
block|,
literal|0x06DC
block|}
block|,
block|{
literal|0x06DD
block|,
literal|0x06DF
block|}
block|,
block|{
literal|0x06E0
block|,
literal|0x06E4
block|}
block|,
block|{
literal|0x06E7
block|,
literal|0x06E8
block|}
block|,
block|{
literal|0x06EA
block|,
literal|0x06ED
block|}
block|,
block|{
literal|0x0901
block|,
literal|0x0903
block|}
block|,
block|{
literal|0x093C
block|,
literal|0x093C
block|}
block|,
block|{
literal|0x093E
block|,
literal|0x094C
block|}
block|,
block|{
literal|0x094D
block|,
literal|0x094D
block|}
block|,
block|{
literal|0x0951
block|,
literal|0x0954
block|}
block|,
block|{
literal|0x0962
block|,
literal|0x0963
block|}
block|,
block|{
literal|0x0981
block|,
literal|0x0983
block|}
block|,
block|{
literal|0x09BC
block|,
literal|0x09BC
block|}
block|,
block|{
literal|0x09BE
block|,
literal|0x09BE
block|}
block|,
block|{
literal|0x09BF
block|,
literal|0x09BF
block|}
block|,
block|{
literal|0x09C0
block|,
literal|0x09C4
block|}
block|,
block|{
literal|0x09C7
block|,
literal|0x09C8
block|}
block|,
block|{
literal|0x09CB
block|,
literal|0x09CD
block|}
block|,
block|{
literal|0x09D7
block|,
literal|0x09D7
block|}
block|,
block|{
literal|0x09E2
block|,
literal|0x09E3
block|}
block|,
block|{
literal|0x0A02
block|,
literal|0x0A02
block|}
block|,
block|{
literal|0x0A3C
block|,
literal|0x0A3C
block|}
block|,
block|{
literal|0x0A3E
block|,
literal|0x0A3E
block|}
block|,
block|{
literal|0x0A3F
block|,
literal|0x0A3F
block|}
block|,
block|{
literal|0x0A40
block|,
literal|0x0A42
block|}
block|,
block|{
literal|0x0A47
block|,
literal|0x0A48
block|}
block|,
block|{
literal|0x0A4B
block|,
literal|0x0A4D
block|}
block|,
block|{
literal|0x0A70
block|,
literal|0x0A71
block|}
block|,
block|{
literal|0x0A81
block|,
literal|0x0A83
block|}
block|,
block|{
literal|0x0ABC
block|,
literal|0x0ABC
block|}
block|,
block|{
literal|0x0ABE
block|,
literal|0x0AC5
block|}
block|,
block|{
literal|0x0AC7
block|,
literal|0x0AC9
block|}
block|,
block|{
literal|0x0ACB
block|,
literal|0x0ACD
block|}
block|,
block|{
literal|0x0B01
block|,
literal|0x0B03
block|}
block|,
block|{
literal|0x0B3C
block|,
literal|0x0B3C
block|}
block|,
block|{
literal|0x0B3E
block|,
literal|0x0B43
block|}
block|,
block|{
literal|0x0B47
block|,
literal|0x0B48
block|}
block|,
block|{
literal|0x0B4B
block|,
literal|0x0B4D
block|}
block|,
block|{
literal|0x0B56
block|,
literal|0x0B57
block|}
block|,
block|{
literal|0x0B82
block|,
literal|0x0B83
block|}
block|,
block|{
literal|0x0BBE
block|,
literal|0x0BC2
block|}
block|,
block|{
literal|0x0BC6
block|,
literal|0x0BC8
block|}
block|,
block|{
literal|0x0BCA
block|,
literal|0x0BCD
block|}
block|,
block|{
literal|0x0BD7
block|,
literal|0x0BD7
block|}
block|,
block|{
literal|0x0C01
block|,
literal|0x0C03
block|}
block|,
block|{
literal|0x0C3E
block|,
literal|0x0C44
block|}
block|,
block|{
literal|0x0C46
block|,
literal|0x0C48
block|}
block|,
block|{
literal|0x0C4A
block|,
literal|0x0C4D
block|}
block|,
block|{
literal|0x0C55
block|,
literal|0x0C56
block|}
block|,
block|{
literal|0x0C82
block|,
literal|0x0C83
block|}
block|,
block|{
literal|0x0CBE
block|,
literal|0x0CC4
block|}
block|,
block|{
literal|0x0CC6
block|,
literal|0x0CC8
block|}
block|,
block|{
literal|0x0CCA
block|,
literal|0x0CCD
block|}
block|,
block|{
literal|0x0CD5
block|,
literal|0x0CD6
block|}
block|,
block|{
literal|0x0D02
block|,
literal|0x0D03
block|}
block|,
block|{
literal|0x0D3E
block|,
literal|0x0D43
block|}
block|,
block|{
literal|0x0D46
block|,
literal|0x0D48
block|}
block|,
block|{
literal|0x0D4A
block|,
literal|0x0D4D
block|}
block|,
block|{
literal|0x0D57
block|,
literal|0x0D57
block|}
block|,
block|{
literal|0x0E31
block|,
literal|0x0E31
block|}
block|,
block|{
literal|0x0E34
block|,
literal|0x0E3A
block|}
block|,
block|{
literal|0x0E47
block|,
literal|0x0E4E
block|}
block|,
block|{
literal|0x0EB1
block|,
literal|0x0EB1
block|}
block|,
block|{
literal|0x0EB4
block|,
literal|0x0EB9
block|}
block|,
block|{
literal|0x0EBB
block|,
literal|0x0EBC
block|}
block|,
block|{
literal|0x0EC8
block|,
literal|0x0ECD
block|}
block|,
block|{
literal|0x0F18
block|,
literal|0x0F19
block|}
block|,
block|{
literal|0x0F35
block|,
literal|0x0F35
block|}
block|,
block|{
literal|0x0F37
block|,
literal|0x0F37
block|}
block|,
block|{
literal|0x0F39
block|,
literal|0x0F39
block|}
block|,
block|{
literal|0x0F3E
block|,
literal|0x0F3E
block|}
block|,
block|{
literal|0x0F3F
block|,
literal|0x0F3F
block|}
block|,
block|{
literal|0x0F71
block|,
literal|0x0F84
block|}
block|,
block|{
literal|0x0F86
block|,
literal|0x0F8B
block|}
block|,
block|{
literal|0x0F90
block|,
literal|0x0F95
block|}
block|,
block|{
literal|0x0F97
block|,
literal|0x0F97
block|}
block|,
block|{
literal|0x0F99
block|,
literal|0x0FAD
block|}
block|,
block|{
literal|0x0FB1
block|,
literal|0x0FB7
block|}
block|,
block|{
literal|0x0FB9
block|,
literal|0x0FB9
block|}
block|,
block|{
literal|0x20D0
block|,
literal|0x20DC
block|}
block|,
block|{
literal|0x20E1
block|,
literal|0x20E1
block|}
block|,
block|{
literal|0x302A
block|,
literal|0x302F
block|}
block|,
block|{
literal|0x3099
block|,
literal|0x3099
block|}
block|,
block|{
literal|0x309A
block|,
literal|0x309A
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_combining_end
specifier|static
specifier|const
name|RangeIter
name|g_combining_end
init|=
name|g_combining_begin
operator|+
sizeof|sizeof
argument_list|(
name|g_combining_begin
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QXmlCharRange
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isCombiningChar
name|bool
name|QXmlUtils
operator|::
name|isCombiningChar
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|rangeContains
argument_list|(
name|g_combining_begin
argument_list|,
name|g_combining_end
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// [88] Digit ::= ...
end_comment
begin_decl_stmt
DECL|variable|g_digit_begin
specifier|static
specifier|const
name|QXmlCharRange
name|g_digit_begin
index|[]
init|=
block|{
block|{
literal|0x0030
block|,
literal|0x0039
block|}
block|,
block|{
literal|0x0660
block|,
literal|0x0669
block|}
block|,
block|{
literal|0x06F0
block|,
literal|0x06F9
block|}
block|,
block|{
literal|0x0966
block|,
literal|0x096F
block|}
block|,
block|{
literal|0x09E6
block|,
literal|0x09EF
block|}
block|,
block|{
literal|0x0A66
block|,
literal|0x0A6F
block|}
block|,
block|{
literal|0x0AE6
block|,
literal|0x0AEF
block|}
block|,
block|{
literal|0x0B66
block|,
literal|0x0B6F
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0BEF
block|}
block|,
block|{
literal|0x0C66
block|,
literal|0x0C6F
block|}
block|,
block|{
literal|0x0CE6
block|,
literal|0x0CEF
block|}
block|,
block|{
literal|0x0D66
block|,
literal|0x0D6F
block|}
block|,
block|{
literal|0x0E50
block|,
literal|0x0E59
block|}
block|,
block|{
literal|0x0ED0
block|,
literal|0x0ED9
block|}
block|,
block|{
literal|0x0F20
block|,
literal|0x0F29
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_digit_end
specifier|static
specifier|const
name|RangeIter
name|g_digit_end
init|=
name|g_digit_begin
operator|+
sizeof|sizeof
argument_list|(
name|g_digit_begin
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QXmlCharRange
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isDigit
name|bool
name|QXmlUtils
operator|::
name|isDigit
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|rangeContains
argument_list|(
name|g_digit_begin
argument_list|,
name|g_digit_end
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// [89] Extender ::= ...
end_comment
begin_decl_stmt
DECL|variable|g_extender_begin
specifier|static
specifier|const
name|QXmlCharRange
name|g_extender_begin
index|[]
init|=
block|{
block|{
literal|0x00B7
block|,
literal|0x00B7
block|}
block|,
block|{
literal|0x02D0
block|,
literal|0x02D0
block|}
block|,
block|{
literal|0x02D1
block|,
literal|0x02D1
block|}
block|,
block|{
literal|0x0387
block|,
literal|0x0387
block|}
block|,
block|{
literal|0x0640
block|,
literal|0x0640
block|}
block|,
block|{
literal|0x0E46
block|,
literal|0x0E46
block|}
block|,
block|{
literal|0x0EC6
block|,
literal|0x0EC6
block|}
block|,
block|{
literal|0x3005
block|,
literal|0x3005
block|}
block|,
block|{
literal|0x3031
block|,
literal|0x3035
block|}
block|,
block|{
literal|0x309D
block|,
literal|0x309E
block|}
block|,
block|{
literal|0x30FC
block|,
literal|0x30FE
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_extender_end
specifier|static
specifier|const
name|RangeIter
name|g_extender_end
init|=
name|g_extender_begin
operator|+
sizeof|sizeof
argument_list|(
name|g_extender_begin
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QXmlCharRange
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|isExtender
name|bool
name|QXmlUtils
operator|::
name|isExtender
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|rangeContains
argument_list|(
name|g_extender_begin
argument_list|,
name|g_extender_end
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isBaseChar
name|bool
name|QXmlUtils
operator|::
name|isBaseChar
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|rangeContains
argument_list|(
name|g_base_begin
argument_list|,
name|g_base_end
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    \internal     Determines whether \a encName is a valid instance of production [81]EncName in the XML 1.0    specification. If it is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml/#NT-EncName},            {Extensible Markup Language (XML) 1.0 (Fourth Edition), [81] EncName}  */
end_comment
begin_function
DECL|function|isEncName
name|bool
name|QXmlUtils
operator|::
name|isEncName
parameter_list|(
specifier|const
name|QString
modifier|&
name|encName
parameter_list|)
block|{
comment|/* Right, we here have a dependency on QRegExp. Writing a manual parser to      * replace that regexp is probably a 70 lines so I prioritize this to when      * the dependency is considered alarming, or when the rest of the bugs      * are fixed. */
name|QRegExp
name|encNameRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"[A-Za-z][A-Za-z0-9._\\-]*"
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|encNameRegExp
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|encNameRegExp
operator|.
name|exactMatch
argument_list|(
name|encName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!  \internal     Determines whether \a c is a valid instance of production [84]Letter in the XML 1.0    specification. If it is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml/#NT-Letter},            {Extensible Markup Language (XML) 1.0 (Fourth Edition), [84] Letter}  */
end_comment
begin_function
DECL|function|isLetter
name|bool
name|QXmlUtils
operator|::
name|isLetter
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|isBaseChar
argument_list|(
name|c
argument_list|)
operator|||
name|isIdeographic
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    \internal     Determines whether \a c is a valid instance of production [2]Char in the XML 1.0    specification. If it is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml/#NT-Char},            {Extensible Markup Language (XML) 1.0 (Fourth Edition), [2] Char}  */
end_comment
begin_function
DECL|function|isChar
name|bool
name|QXmlUtils
operator|::
name|isChar
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
operator|(
name|c
operator|.
name|unicode
argument_list|()
operator|>=
literal|0x0020
operator|&&
name|c
operator|.
name|unicode
argument_list|()
operator|<=
literal|0xD7FF
operator|)
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|0x0009
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|0x000A
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|0x000D
operator|||
operator|(
name|c
operator|.
name|unicode
argument_list|()
operator|>=
literal|0xE000
operator|&&
name|c
operator|.
name|unicode
argument_list|()
operator|<=
literal|0xFFFD
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!    \internal     Determines whether \a c is a valid instance of    production [4]NameChar in the XML 1.0 specification. If it    is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml/#NT-NameChar},            {Extensible Markup Language (XML) 1.0 (Fourth Edition), [4] NameChar}  */
end_comment
begin_function
DECL|function|isNameChar
name|bool
name|QXmlUtils
operator|::
name|isNameChar
parameter_list|(
specifier|const
name|QChar
name|c
parameter_list|)
block|{
return|return
name|isBaseChar
argument_list|(
name|c
argument_list|)
operator|||
name|isDigit
argument_list|(
name|c
argument_list|)
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|'.'
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|'-'
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|'_'
operator|||
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|':'
operator|||
name|isCombiningChar
argument_list|(
name|c
argument_list|)
operator|||
name|isIdeographic
argument_list|(
name|c
argument_list|)
operator|||
name|isExtender
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    \internal     Determines whether \a c is a valid instance of    production [12] PubidLiteral in the XML 1.0 specification. If it    is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml/#NT-PubidLiteral},            {Extensible Markup Language (XML) 1.0 (Fourth Edition), [12] PubidLiteral}  */
end_comment
begin_function
DECL|function|isPublicID
name|bool
name|QXmlUtils
operator|::
name|isPublicID
parameter_list|(
specifier|const
name|QString
modifier|&
name|candidate
parameter_list|)
block|{
specifier|const
name|int
name|len
init|=
name|candidate
operator|.
name|length
argument_list|()
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
name|len
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|ushort
name|cp
init|=
name|candidate
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|unicode
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|cp
operator|>=
literal|'a'
operator|&&
name|cp
operator|<=
literal|'z'
operator|)
operator|||
operator|(
name|cp
operator|>=
literal|'A'
operator|&&
name|cp
operator|<=
literal|'Z'
operator|)
operator|||
operator|(
name|cp
operator|>=
literal|'0'
operator|&&
name|cp
operator|<=
literal|'9'
operator|)
condition|)
block|{
continue|continue;
block|}
switch|switch
condition|(
name|cp
condition|)
block|{
comment|/* Fallthrough all these. */
case|case
literal|0x20
case|:
case|case
literal|0x0D
case|:
case|case
literal|0x0A
case|:
case|case
literal|'-'
case|:
case|case
literal|'\''
case|:
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'+'
case|:
case|case
literal|','
case|:
case|case
literal|'.'
case|:
case|case
literal|'/'
case|:
case|case
literal|':'
case|:
case|case
literal|'='
case|:
case|case
literal|'?'
case|:
case|case
literal|';'
case|:
case|case
literal|'!'
case|:
case|case
literal|'*'
case|:
case|case
literal|'#'
case|:
case|case
literal|'@'
case|:
case|case
literal|'$'
case|:
case|case
literal|'_'
case|:
case|case
literal|'%'
case|:
continue|continue;
default|default:
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!    \internal     Determines whether \a c is a valid instance of    production [4]NCName in the XML 1.0 Namespaces specification. If it    is, true is returned, otherwise false.      \sa {http://www.w3.org/TR/REC-xml-names/#NT-NCName},            {W3CNamespaces in XML 1.0 (Second Edition), [4] NCName}  */
end_comment
begin_function
DECL|function|isNCName
name|bool
name|QXmlUtils
operator|::
name|isNCName
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|ncName
parameter_list|)
block|{
if|if
condition|(
name|ncName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|const
name|QChar
name|first
argument_list|(
name|ncName
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QXmlUtils
operator|::
name|isLetter
argument_list|(
name|first
argument_list|)
operator|&&
name|first
operator|.
name|unicode
argument_list|()
operator|!=
literal|'_'
operator|&&
name|first
operator|.
name|unicode
argument_list|()
operator|!=
literal|':'
condition|)
return|return
literal|false
return|;
specifier|const
name|int
name|len
init|=
name|ncName
operator|.
name|size
argument_list|()
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
name|len
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
name|at
init|=
name|ncName
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QXmlUtils
operator|::
name|isNameChar
argument_list|(
name|at
argument_list|)
operator|||
name|at
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
