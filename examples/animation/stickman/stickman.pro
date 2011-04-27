HEADERS += stickman.h \
           animation.h \
           node.h \
           lifecycle.h \
           graphicsview.h
SOURCES += main.cpp \
           stickman.cpp \
           animation.cpp \
           node.cpp \
           lifecycle.cpp \
           graphicsview.cpp

RESOURCES += stickman.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/animation/stickman
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS stickman.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/animation/stickman
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000E3F9
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
