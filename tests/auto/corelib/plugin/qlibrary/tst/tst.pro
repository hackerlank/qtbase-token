CONFIG += testcase
TARGET = ../tst_qlibrary
QT = core testlib
SOURCES = ../tst_qlibrary.cpp

win32 {
    CONFIG(debug, debug|release) {
        TARGET = ../../debug/tst_qlibrary
    } else {
        TARGET = ../../release/tst_qlibrary
    }
}

TESTDATA += ../library_path/invalid.so

win32:CONFIG += insignificant_test # QTBUG-24151
