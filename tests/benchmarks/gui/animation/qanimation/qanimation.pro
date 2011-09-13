load(qttest_p4)
QT += widgets

# do not run benchmarks by default in 'make check'
CONFIG -= testcase

TEMPLATE = app
TARGET = tst_bench_qanimation
DEPENDPATH += .
INCLUDEPATH += .

CONFIG += release
#CONFIG += debug


SOURCES += main.cpp \
           dummyobject.cpp \
           dummyanimation.cpp \
           rectanimation.cpp

HEADERS += dummyobject.h \
           dummyanimation.h \
           rectanimation.h
