load(qttest_p4)
TEMPLATE = app
TARGET = tst_bench_qhostinfo
DEPENDPATH += .
INCLUDEPATH += .

QT -= gui
QT += core-private network network-private

CONFIG += release

# Input
SOURCES += main.cpp
