#! [0]
TEMPLATE      = lib
CONFIG       += plugin
INCLUDEPATH  += ../..
HEADERS       = extrafiltersplugin.h
SOURCES       = extrafiltersplugin.cpp
TARGET        = $$qtLibraryTarget(pnp_extrafilters)
DESTDIR       = ../../plugandpaint/plugins

#! [0]
# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/tools/plugandpaint/plugins
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS extrafilters.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/tools/plugandpaintplugins/extrafilters
INSTALLS += target sources

symbian: CONFIG += qt_example

symbian:TARGET.EPOCALLOWDLLDATA = 1
QT += widgets
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)
