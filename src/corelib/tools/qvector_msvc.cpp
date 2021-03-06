begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// ### Qt6: verify if we can remove this, somehow.
end_comment
begin_comment
comment|// First, try to see if the extern template from qvector.h is necessary.
end_comment
begin_comment
comment|// If it still is, check if removing the copy constructors in qarraydata.h
end_comment
begin_comment
comment|// make the calling convention of both sets of begin() and end() functions
end_comment
begin_comment
comment|// match, as it does for the IA-64 C++ ABI.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QVECTOR_H
end_ifdef
begin_error
error|#
directive|error
literal|"This file must be compiled with no precompiled headers"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// invert the setting of QT_STRICT_ITERATORS, whichever it was
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_STRICT_ITERATORS
end_ifdef
begin_undef
DECL|macro|QT_STRICT_ITERATORS
undef|#
directive|undef
name|QT_STRICT_ITERATORS
end_undef
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STRICT_ITERATORS
define|#
directive|define
name|QT_STRICT_ITERATORS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// the Q_TEMPLATE_EXTERN at the bottom of qvector.h will do the trick
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
end_unit
