load(qttest_p4)
SOURCES += tst_qnetworkaccessmanager_and_qprogressdialog.cpp
QT += network widgets

symbian: TARGET.CAPABILITY = NetworkServices

