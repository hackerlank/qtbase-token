HEADERS     = draglabel.h \
              dragwidget.h
RESOURCES   = fridgemagnets.qrc
SOURCES     = draglabel.cpp \
              dragwidget.cpp \
              main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/draganddrop/fridgemagnets
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.txt
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/draganddrop/fridgemagnets
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000C610
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}


