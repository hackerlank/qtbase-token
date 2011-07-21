############################################################
# Project file for autotest for file qgl.h
############################################################

load(qttest_p4)
requires(contains(QT_CONFIG,opengl))
QT += widgets widgets-private opengl-private gui-private core-private

contains(QT_CONFIG,egl):DEFINES += QGL_EGL
win32:!wince*: DEFINES += QT_NO_EGL

SOURCES   += tst_qgl.cpp
RESOURCES  = qgl.qrc

CONFIG+=insignificant_test
