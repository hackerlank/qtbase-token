load(qttest_p4)
SOURCES         += ../tst_qpluginloader.cpp
TARGET  = ../tst_qpluginloader
QT = core
HEADERS += ../theplugin/plugininterface.h

win32 {
  CONFIG(debug, debug|release) {
    TARGET = ../../debug/tst_qpluginloader
} else {
    TARGET = ../../release/tst_qpluginloader
  }
}


wince*: {
   addFiles.files = $$OUT_PWD/../bin/*.dll
   addFiles.path = bin
   DEPLOYMENT += addFiles
}

DEFINES += SRCDIR=\\\"$$PWD/../\\\"
mac*:CONFIG+=insignificant_test

CONFIG += insignificant_test # QTBUG-21402
