/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qcocoatheme.h"

#include "qmenu_mac.h"
#include "qcocoafiledialoghelper.h"
#include <QtWidgets/QFileDialog>

QT_BEGIN_NAMESPACE

QCocoaTheme::QCocoaTheme()
{

}

QCocoaTheme::~QCocoaTheme()
{

}

QPlatformMenu *QCocoaTheme::createPlatformMenu(QMenu *menu) const
{
    return new QCocoaMenu(menu);
}

QPlatformMenuBar *QCocoaTheme::createPlatformMenuBar(QMenuBar *menuBar) const
{
    return new QCocoaMenuBar(menuBar);
}


bool QCocoaTheme::usePlatformNativeDialog(DialogType dialogType) const
{
    if (dialogType == QPlatformTheme::FileDialog)
        return true;
    return false;
}

QPlatformDialogHelper * QCocoaTheme::createPlatformDialogHelper(DialogType dialogType) const
{
    if (dialogType == QPlatformTheme::FileDialog) {
        return new QCocoaFileDialogHelper();
    }
    return 0;
}

QT_END_NAMESPACE
