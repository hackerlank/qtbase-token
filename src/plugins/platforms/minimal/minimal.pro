TARGET = qminimal
load(qt_plugin)

QT += core-private gui-private platformsupport-private
DESTDIR = $$QT.gui.plugins/platforms

SOURCES =   main.cpp \
            qminimalintegration.cpp \
            qminimalbackingstore.cpp
HEADERS =   qminimalintegration.h \
            qminimalbackingstore.h

OTHER_FILES += minimal.json

target.path += $$[QT_INSTALL_PLUGINS]/platforms
INSTALLS += target
