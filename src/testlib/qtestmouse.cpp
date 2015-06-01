begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|member|lastMouseButton
name|Q_TESTLIB_EXPORT
name|Qt
operator|::
name|MouseButton
name|lastMouseButton
init|=
name|Qt
operator|::
name|NoButton
decl_stmt|;
DECL|member|lastMouseTimestamp
name|Q_TESTLIB_EXPORT
name|int
name|lastMouseTimestamp
init|=
literal|0
decl_stmt|;
block|}
end_namespace
begin_comment
comment|// namespace QTest
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
