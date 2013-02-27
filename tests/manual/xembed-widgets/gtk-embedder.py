begin_unit
comment|'#!/usr/bin/python'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## Copyright (C) 2013 Canonical Ltd.'
nl|'\n'
comment|'## Contact: http://www.qt-project.org/legal'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## This file is part of the test suite of the Qt Toolkit.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_BEGIN_LICENSE:LGPL$'
nl|'\n'
comment|'## Commercial License Usage'
nl|'\n'
comment|'## Licensees holding valid commercial Qt licenses may use this file in'
nl|'\n'
comment|'## accordance with the commercial license agreement provided with the'
nl|'\n'
comment|'## Software or, alternatively, in accordance with the terms contained in'
nl|'\n'
comment|'## a written agreement between you and Digia.  For licensing terms and'
nl|'\n'
comment|'## conditions see http://qt.digia.com/licensing.  For further information'
nl|'\n'
comment|'## use the contact form at http://qt.digia.com/contact-us.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU Lesser General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU Lesser'
nl|'\n'
comment|'## General Public License version 2.1 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.LGPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU Lesser General Public License version 2.1 requirements'
nl|'\n'
comment|'## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## In addition, as a special exception, Digia gives you certain additional'
nl|'\n'
comment|'## rights.  These rights are described in the Digia Qt LGPL Exception'
nl|'\n'
comment|'## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU'
nl|'\n'
comment|'## General Public License version 3.0 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.GPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU General Public License version 3.0 requirements will be'
nl|'\n'
comment|'## met: http://www.gnu.org/copyleft/gpl.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_END_LICENSE$'
nl|'\n'
comment|'##'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
nl|'\n'
name|'from'
name|'gi'
op|'.'
name|'repository'
name|'import'
name|'Gtk'
newline|'\n'
name|'from'
name|'subprocess'
name|'import'
name|'Popen'
newline|'\n'
nl|'\n'
DECL|variable|window
name|'window'
op|'='
name|'Gtk'
op|'.'
name|'Window'
op|'('
op|')'
newline|'\n'
nl|'\n'
DECL|variable|box
name|'box'
op|'='
name|'Gtk'
op|'.'
name|'VBox'
op|'('
name|'False'
op|','
number|'0'
op|')'
newline|'\n'
name|'window'
op|'.'
name|'add'
op|'('
name|'box'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|child
name|'child'
op|'='
name|'None'
newline|'\n'
DECL|function|on_button_clicked
name|'def'
name|'on_button_clicked'
op|'('
name|'button'
op|','
name|'socket'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'global'
name|'child'
newline|'\n'
name|'child'
op|'='
name|'Popen'
op|'('
op|'['
string|"'./lineedits'"
op|','
name|'str'
op|'('
name|'socket'
op|'.'
name|'get_id'
op|'('
op|')'
op|')'
op|']'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|button
dedent|''
name|'button'
op|'='
name|'Gtk'
op|'.'
name|'Button'
op|'('
string|'"Press me to embed a Qt client"'
op|')'
newline|'\n'
name|'box'
op|'.'
name|'pack_start'
op|'('
name|'button'
op|','
name|'False'
op|','
name|'False'
op|','
number|'0'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|entry
name|'entry'
op|'='
name|'Gtk'
op|'.'
name|'Entry'
op|'('
op|')'
newline|'\n'
name|'box'
op|'.'
name|'pack_start'
op|'('
name|'entry'
op|','
name|'False'
op|','
name|'False'
op|','
number|'0'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|socket
name|'socket'
op|'='
name|'Gtk'
op|'.'
name|'Socket'
op|'('
op|')'
newline|'\n'
name|'socket'
op|'.'
name|'set_size_request'
op|'('
number|'200'
op|','
number|'200'
op|')'
newline|'\n'
name|'box'
op|'.'
name|'add'
op|'('
name|'socket'
op|')'
newline|'\n'
nl|'\n'
name|'button'
op|'.'
name|'connect'
op|'('
string|'"clicked"'
op|','
name|'on_button_clicked'
op|','
name|'socket'
op|')'
newline|'\n'
name|'window'
op|'.'
name|'connect'
op|'('
string|'"destroy"'
op|','
name|'Gtk'
op|'.'
name|'main_quit'
op|')'
newline|'\n'
nl|'\n'
DECL|function|plugged_event
name|'def'
name|'plugged_event'
op|'('
name|'widget'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
op|'('
string|'"A window was embedded!"'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'socket'
op|'.'
name|'connect'
op|'('
string|'"plug-added"'
op|','
name|'plugged_event'
op|')'
newline|'\n'
nl|'\n'
name|'window'
op|'.'
name|'show_all'
op|'('
op|')'
newline|'\n'
name|'Gtk'
op|'.'
name|'main'
op|'('
op|')'
newline|'\n'
name|'if'
name|'child'
op|':'
newline|'\n'
indent|'    '
name|'child'
op|'.'
name|'terminate'
op|'('
op|')'
newline|'\n'
dedent|''
endmarker|''
end_unit
