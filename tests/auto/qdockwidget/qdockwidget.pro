load(qttest_p4)
QT += widgets widgets-private
QT += core-private gui-private

SOURCES += tst_qdockwidget.cpp

CONFIG += insignificant_test # QTBUG-21402
