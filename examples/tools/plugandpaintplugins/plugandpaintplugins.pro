TEMPLATE      = subdirs
SUBDIRS       = basictools \
                extrafilters

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/tools/plugandpaintplugins
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS plugandpaintplugins.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/tools/plugandpaintplugins
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
