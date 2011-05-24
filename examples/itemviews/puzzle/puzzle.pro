HEADERS     = mainwindow.h \
              piecesmodel.h \
              puzzlewidget.h
RESOURCES   = puzzle.qrc
SOURCES     = main.cpp \
              mainwindow.cpp \
              piecesmodel.cpp \
              puzzlewidget.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/itemviews/puzzle
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.jpg
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/itemviews/puzzle
INSTALLS += target sources

symbian: CONFIG += qt_example

wince* {
   DEPLOYMENT_PLUGIN += qjpeg qgif qtiff
}

QT += widgets
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)

