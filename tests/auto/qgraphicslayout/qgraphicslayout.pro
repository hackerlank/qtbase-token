############################################################
# Project file for autotest for file qlayout.h
############################################################

load(qttest_p4)
QT += widgets
SOURCES += tst_qgraphicslayout.cpp
DEFINES += QT_USE_USING_NAMESPACE
CONFIG += parallel_test
