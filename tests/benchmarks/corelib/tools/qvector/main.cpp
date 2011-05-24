begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|"qrawvector.h"
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_comment
comment|/*  Code generated by g++ 4.3.3.  The lines marked with '!' are the ones that get executed inside the loop. Using the external 's' causes some load making the loop resembling a 'simple inner loop' in 'real' applications.   qvector_mutable_read_access:  .L166: !       movl    -16(%ebp), %edx !       movl    (%edx), %eax !       subl    $1, %eax !       je      .L165             movl    4(%edx), %eax             movl    %eax, 8(%esp)             movl    8(%edx), %eax             movl    %esi, (%esp)             movl    %eax, 4(%esp)             call    _ZN4myns7QVectorIdE7reallocEii .L165: !       movl    -16(%ebp), %eax !       fldl    s !       faddl   16(%eax,%ebx,8) !       addl    $1, %ebx !       cmpl    $10000, %ebx !       fstpl   s !       jne     .L166   qvector_const_read_access:          movl    -16(%ebp), %edx         xorl    %eax, %eax .L183: !       fldl    s !       faddl   16(%edx,%eax,8)  !       addl    $1, %eax !       cmpl    $10000, %eax !       fstpl   s !       jne     .L183   stdvector_const_read_access and stdvector_mutable_read_access and qrawvector_const_read_access and qrawvector_mutable_read_access:          xorl    %eax, %eax .L64: !       fldl    s !       faddl   (%ebx,%eax,8) !       addl    $1, %eax !       cmpl    $10000, %eax !       fstpl   s !       jne     .L64    Behaviour varies with small modifications, but total is more or less stable:  qrawvector_mutable_read_access, using  size() instead of N:  .L145: !       faddl   (%edx,%eax,8) !       addl    $1, %eax !       cmpl    %ecx, %eax !       fstl    s !       jne     .L145 !       fstp    %st(0)   qrawvector_mutable_read_access, counting backward:  .L145: !       faddl   (%edx,%eax,8) !       subl    $1, %eax !       cmpl    $-1, %eax !       fstl    s !       jne     .L145   qrawvector_mutable_read_access, counting backward, using size():  .L146: !       faddl   (%edx) !       addl    $1, %eax !       subl    $8, %edx !       cmpl    %ecx, %eax !       fstl    s !       jne     .L146    */
end_comment
begin_comment
comment|/*  ////////////////////////////////////////////////////////////////////  time ./tst_vector qvector_const_read_access real    0m12.912s user    0m12.401s sys     0m0.016s  time ./tst_vector qvector_mutable_read_access real    0m38.566s user    0m36.754s sys     0m0.008s   time ./tst_vector stdvector_mutable_read_access real    0m12.736s user    0m12.665s sys     0m0.004s   ////////////////////////////////////////////////////////////////////  time ./tst_vector qvector_fill_and_return real    0m28.778s user    0m28.522s sys     0m0.012s  time ./tst_vector stdvector_fill_and_return real    0m26.675s user    0m26.558s sys     0m0.012s  time ./tst_vector qrawvector_fill_and_return real    0m23.370s user    0m23.269s sys     0m0.008s    */
end_comment
begin_define
DECL|macro|TEST_RETURN
define|#
directive|define
name|TEST_RETURN
value|1
end_define
begin_comment
comment|// For some reason, both 'plain' and '-callgrind' create strange results
end_comment
begin_comment
comment|// (like varying instruction count for the same assembly code)
end_comment
begin_comment
comment|// So replace it by a plain loop and measure wall clock time.
end_comment
begin_comment
comment|//#undef QBENCHMARK
end_comment
begin_comment
comment|//#define QBENCHMARK for (int j = 0; j != 10000; ++j)
end_comment
begin_class
DECL|class|tst_QVector
class|class
name|tst_QVector
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|calibration
parameter_list|()
function_decl|;
comment|// Pure Qt solution
DECL|function|qvector_separator
name|void
name|qvector_separator
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QVector results: "
expr_stmt|;
block|}
name|void
name|qvector_const_read_access
parameter_list|()
function_decl|;
name|void
name|qvector_mutable_read_access
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|TEST_RETURN
name|void
name|qvector_fill_and_return
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// Purre Standard solution
DECL|function|stdvector
name|void
name|stdvector
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"std::vector results: "
expr_stmt|;
block|}
name|void
name|stdvector_const_read_access
parameter_list|()
function_decl|;
name|void
name|stdvector_mutable_read_access
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|TEST_RETURN
name|void
name|stdvector_fill_and_return
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// Build using std, pass as QVector
DECL|function|mixedvector
name|void
name|mixedvector
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"mixed results: "
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|TEST_RETURN
name|void
name|mixedvector_fill_and_return
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|// Alternative implementation
DECL|function|qrawvector_separator
name|void
name|qrawvector_separator
parameter_list|()
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QRawVector results: "
expr_stmt|;
block|}
name|void
name|qrawvector_const_read_access
parameter_list|()
function_decl|;
name|void
name|qrawvector_mutable_read_access
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|TEST_RETURN
name|void
name|qrawvector_fill_and_return
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|N
specifier|const
name|int
name|N
init|=
literal|1000000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|double
name|s
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|calibration
name|void
name|tst_QVector
operator|::
name|calibration
parameter_list|()
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|i
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|///////////////////// QVector /////////////////////
end_comment
begin_function
DECL|function|qvector_const_read_access
name|void
name|tst_QVector
operator|::
name|qvector_const_read_access
parameter_list|()
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
specifier|const
name|QVector
argument_list|<
name|double
argument_list|>
modifier|&
name|vc
init|=
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|vc
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qvector_mutable_read_access
name|void
name|tst_QVector
operator|::
name|qvector_mutable_read_access
parameter_list|()
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|v
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|TEST_RETURN
end_ifdef
begin_function_decl
specifier|extern
name|QVector
argument_list|<
name|double
argument_list|>
name|qvector_fill_and_return_helper
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|qvector_fill_and_return
name|void
name|tst_QVector
operator|::
name|qvector_fill_and_return
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
init|=
name|qvector_fill_and_return_helper
argument_list|()
decl_stmt|;
name|s
operator|+=
name|v
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|///////////////////// QRawVector /////////////////////
end_comment
begin_function
DECL|function|qrawvector_const_read_access
name|void
name|tst_QVector
operator|::
name|qrawvector_const_read_access
parameter_list|()
block|{
name|QRawVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
specifier|const
name|QRawVector
argument_list|<
name|double
argument_list|>
modifier|&
name|vc
init|=
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
name|vc
operator|.
name|size
argument_list|()
init|;
operator|--
name|i
operator|>=
literal|0
condition|;
control|)
name|s
operator|+=
name|vc
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qrawvector_mutable_read_access
name|void
name|tst_QVector
operator|::
name|qrawvector_mutable_read_access
parameter_list|()
block|{
name|QRawVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|v
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|TEST_RETURN
end_ifdef
begin_function_decl
specifier|extern
name|QVector
argument_list|<
name|double
argument_list|>
name|qrawvector_fill_and_return_helper
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|qrawvector_fill_and_return
name|void
name|tst_QVector
operator|::
name|qrawvector_fill_and_return
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
init|=
name|qrawvector_fill_and_return_helper
argument_list|()
decl_stmt|;
name|s
operator|+=
name|v
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|///////////////////// std::vector /////////////////////
end_comment
begin_function
DECL|function|stdvector_const_read_access
name|void
name|tst_QVector
operator|::
name|stdvector_const_read_access
parameter_list|()
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
modifier|&
name|vc
init|=
name|v
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|vc
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|stdvector_mutable_read_access
name|void
name|tst_QVector
operator|::
name|stdvector_mutable_read_access
parameter_list|()
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|s
operator|+=
name|v
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|TEST_RETURN
end_ifdef
begin_function_decl
specifier|extern
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|stdvector_fill_and_return_helper
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|stdvector_fill_and_return
name|void
name|tst_QVector
operator|::
name|stdvector_fill_and_return
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
init|=
name|stdvector_fill_and_return_helper
argument_list|()
decl_stmt|;
name|s
operator|+=
name|v
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|///////////////////// mixed vector /////////////////////
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TEST_RETURN
end_ifdef
begin_function_decl
specifier|extern
name|QVector
argument_list|<
name|double
argument_list|>
name|mixedvector_fill_and_return_helper
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|mixedvector_fill_and_return
name|void
name|tst_QVector
operator|::
name|mixedvector_fill_and_return
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
init|=
name|stdvector_fill_and_return_helper
argument_list|()
decl_stmt|;
name|s
operator|+=
name|v
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QVector
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
