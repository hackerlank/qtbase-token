load(qttest_p4)

# do not run benchmarks by default in 'make check'
CONFIG -= testcase

TEMPLATE = app
TARGET = tst_bench_qmatrix4x4

SOURCES += tst_qmatrix4x4.cpp

