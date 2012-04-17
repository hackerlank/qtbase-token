begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_GLOBAL_H
end_ifndef
begin_define
DECL|macro|QTEST_GLOBAL_H
define|#
directive|define
name|QTEST_GLOBAL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_SHARED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_DLL
argument_list|)
DECL|macro|Q_TESTLIB_EXPORT
define|#
directive|define
name|Q_TESTLIB_EXPORT
else|#
directive|else
ifdef|#
directive|ifdef
name|QTESTLIB_MAKEDLL
define|#
directive|define
name|Q_TESTLIB_EXPORT
value|Q_DECL_EXPORT
else|#
directive|else
define|#
directive|define
name|Q_TESTLIB_EXPORT
value|Q_DECL_IMPORT
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
name|Q_CC_HPACC
operator|)
operator|&&
operator|(
name|defined
name|__ia64
operator|)
ifdef|#
directive|ifdef
name|Q_TESTLIB_EXPORT
DECL|macro|Q_TESTLIB_EXPORT
undef|#
directive|undef
name|Q_TESTLIB_EXPORT
endif|#
directive|endif
DECL|macro|Q_TESTLIB_EXPORT
define|#
directive|define
name|Q_TESTLIB_EXPORT
endif|#
directive|endif
DECL|macro|QTEST_VERSION
define|#
directive|define
name|QTEST_VERSION
value|QT_VERSION
DECL|macro|QTEST_VERSION_STR
define|#
directive|define
name|QTEST_VERSION_STR
value|QT_VERSION_STR
name|namespace
name|QTest
block|{
enum|enum
name|TestFailMode
block|{
name|Abort
init|=
literal|1
block|,
name|Continue
init|=
literal|2
block|}
enum|;
block|}
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
