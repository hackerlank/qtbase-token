CONFIG += testcase
CONFIG += parallel_test
TARGET = tst_qfont
QT += testlib
!contains(QT_CONFIG, no-widgets): QT += widgets
SOURCES  += tst_qfont.cpp


