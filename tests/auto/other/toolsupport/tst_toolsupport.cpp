begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of Qt Creator. ** ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_comment
comment|// Don't do this at home. This is test code, not production.
end_comment
begin_define
DECL|macro|protected
define|#
directive|define
name|protected
value|public
end_define
begin_define
DECL|macro|private
define|#
directive|define
name|private
value|public
end_define
begin_include
include|#
directive|include
file|<private/qdatetime_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfile_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfileinfo_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_if
begin_define
DECL|macro|RUN_MEMBER_OFFSET_TEST
define|#
directive|define
name|RUN_MEMBER_OFFSET_TEST
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|RUN_MEMBER_OFFSET_TEST
define|#
directive|define
name|RUN_MEMBER_OFFSET_TEST
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|RUN_MEMBER_OFFSET_TEST
end_if
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|,
name|typename
name|K
parameter_list|>
DECL|function|pmm_to_offsetof
name|size_t
name|pmm_to_offsetof
parameter_list|(
name|T
name|K
operator|::
modifier|*
name|pmm
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_MSVC
comment|// Even on 64 bit MSVC uses 4 byte offsets.
name|quint32
name|ret
decl_stmt|;
else|#
directive|else
name|size_t
name|ret
decl_stmt|;
endif|#
directive|endif
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|ret
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|pmm
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|ret
argument_list|,
operator|&
name|pmm
argument_list|,
sizeof|sizeof
argument_list|(
name|ret
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_toolsupport
class|class
name|tst_toolsupport
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|offsets
parameter_list|()
function_decl|;
name|void
name|offsets_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|offsets
name|void
name|tst_toolsupport
operator|::
name|offsets
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|size_t
argument_list|,
name|actual
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expected32
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expected64
argument_list|)
expr_stmt|;
name|size_t
name|expect
init|=
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|4
condition|?
name|expected32
else|:
name|expected64
decl_stmt|;
name|QCOMPARE
argument_list|(
name|actual
argument_list|,
name|expect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|offsets_data
name|void
name|tst_toolsupport
operator|::
name|offsets_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|size_t
argument_list|>
argument_list|(
literal|"actual"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expected32"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expected64"
argument_list|)
expr_stmt|;
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sizeof(QObjectData)"
argument_list|)
operator|<<
sizeof|sizeof
argument_list|(
name|QObjectData
argument_list|)
decl_stmt|;
name|data
operator|<<
literal|28
operator|<<
literal|48
expr_stmt|;
comment|// vptr + 3 ptr + 2 int + ptr
block|}
if|#
directive|if
name|RUN_MEMBER_OFFSET_TEST
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QObjectPrivate::extraData"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QObjectPrivate
operator|::
name|extraData
argument_list|)
decl_stmt|;
name|data
operator|<<
literal|28
operator|<<
literal|48
expr_stmt|;
comment|// sizeof(QObjectData)
block|}
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QFileInfoPrivate::fileEntry"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QFileInfoPrivate
operator|::
name|fileEntry
argument_list|)
decl_stmt|;
name|data
operator|<<
literal|4
operator|<<
literal|8
expr_stmt|;
block|}
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QFileSystemEntry::filePath"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QFileSystemEntry
operator|::
name|m_filePath
argument_list|)
decl_stmt|;
name|data
operator|<<
literal|0
operator|<<
literal|0
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_LINUX
if|if
condition|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
condition|)
block|{
name|QTestData
modifier|&
name|data
init|=
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QFilePrivate::fileName"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QFilePrivate
operator|::
name|fileName
argument_list|)
decl_stmt|;
name|data
operator|<<
literal|168
operator|<<
literal|248
expr_stmt|;
block|}
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_msecs"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_msecs
argument_list|)
operator|<<
literal|8
operator|<<
literal|8
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_spec"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_spec
argument_list|)
operator|<<
literal|16
operator|<<
literal|16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_offsetFromUtc"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_offsetFromUtc
argument_list|)
operator|<<
literal|20
operator|<<
literal|20
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_timeZone"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_timeZone
argument_list|)
operator|<<
literal|24
operator|<<
literal|24
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_status"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_status
argument_list|)
operator|<<
literal|28
operator|<<
literal|32
expr_stmt|;
else|#
directive|else
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_msecs"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_msecs
argument_list|)
operator|<<
literal|4
operator|<<
literal|8
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_spec"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_spec
argument_list|)
operator|<<
literal|12
operator|<<
literal|16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_offsetFromUtc"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_offsetFromUtc
argument_list|)
operator|<<
literal|16
operator|<<
literal|20
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_timeZone"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_timeZone
argument_list|)
operator|<<
literal|20
operator|<<
literal|24
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QDateTimePrivate::m_status"
argument_list|)
operator|<<
name|pmm_to_offsetof
argument_list|(
operator|&
name|QDateTimePrivate
operator|::
name|m_status
argument_list|)
operator|<<
literal|24
operator|<<
literal|32
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
comment|// RUN_MEMBER_OFFSET_TEST
block|}
end_function
begin_expr_stmt
DECL|variable|tst_toolsupport
name|QTEST_APPLESS_MAIN
argument_list|(
name|tst_toolsupport
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_toolsupport.moc"
end_include
end_unit
