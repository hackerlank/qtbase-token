begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKEYMAPPER_P_H
end_ifndef
begin_define
DECL|macro|QKEYMAPPER_P_H
define|#
directive|define
name|QKEYMAPPER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qkeysequence.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qlocale.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKeyMapperPrivate
name|class
name|QKeyMapperPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QKeyMapper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QKeyMapper
argument_list|()
block|;
operator|~
name|QKeyMapper
argument_list|()
block|;
specifier|static
name|QKeyMapper
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|void
name|changeKeyboard
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|friend
name|QKeyMapperPrivate
operator|*
name|qt_keymapper_private
argument_list|()
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QKeyMapper
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QKeyMapper
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|KeyboardLayoutItem
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKeyMapperPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QKeyMapper
argument_list|)
name|public
operator|:
name|QKeyMapperPrivate
argument_list|()
block|;
operator|~
name|QKeyMapperPrivate
argument_list|()
block|;
name|void
name|clearMappings
argument_list|()
block|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|QLocale
name|keyboardInputLocale
block|;
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QKeyMapperPrivate
modifier|*
name|qt_keymapper_private
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// from qkeymapper.cpp
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKEYMAPPER_P_H
end_comment
end_unit
