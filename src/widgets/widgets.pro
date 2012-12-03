TARGET     = QtWidgets
QT = core-private gui-private
MODULE_CONFIG = uic

DEFINES   += QT_NO_USING_NAMESPACE
win32-msvc*|win32-icc:QMAKE_LFLAGS += /BASE:0x65000000
irix-cc*:QMAKE_CXXFLAGS += -no_prelink -ptused

QMAKE_DOCS = $$PWD/doc/qtwidgets.qdocconf

load(qt_module)

#platforms
mac:include(kernel/mac.pri)
win32:include(kernel/win.pri)

#modules
include(kernel/kernel.pri)
include(styles/styles.pri)
include(widgets/widgets.pri)
include(dialogs/dialogs.pri)
include(accessible/accessible.pri)
include(itemviews/itemviews.pri)
include(graphicsview/graphicsview.pri)
include(util/util.pri)
include(statemachine/statemachine.pri)
include(effects/effects.pri)


QMAKE_LIBS += $$QMAKE_LIBS_GUI

contains(DEFINES,QT_EVAL):include($$QT_SOURCE_TREE/src/corelib/eval.pri)

QMAKE_DYNAMIC_LIST_FILE = $$PWD/QtGui.dynlist

# Code coverage with TestCocoon
# The following is required as extra compilers use $$QMAKE_CXX instead of $(CXX).
# Without this, testcocoon.prf is read only after $$QMAKE_CXX is used by the
# extra compilers.
testcocoon {
    load(testcocoon)
}

win32:!contains(QT_CONFIG, directwrite) {
    DEFINES += QT_NO_DIRECTWRITE
}

load(uic)

uic_dir.name = uic_location
uic_dir.variable = QMAKE_UIC

QMAKE_PKGCONFIG_VARIABLES += uic_dir
