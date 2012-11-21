SOURCES   = addressbook.cpp \
            finddialog.cpp \
            main.cpp
HEADERS   = addressbook.h \
            finddialog.h

QMAKE_PROJECT_NAME = ab_part5

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/widgets/tutorials/addressbook/part5
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS part5.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/widgets/tutorials/addressbook/part5
INSTALLS += target sources

QT += widgets

simulator: warning(This example might not fully work on Simulator platform)
