begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2013 BlackBerry Limited. All rights reserved.  ** Contact: http://www.qt-project.org/legal  **  ** This file is part of the QtCore module of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL21$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and Digia. For licensing terms and  ** conditions see http://qt.digia.com/licensing. For further information  ** use the contact form at http://qt.digia.com/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 2.1 or version 3 as published by the Free  ** Software Foundation and appearing in the file LICENSE.LGPLv21 and  ** LICENSE.LGPLv3 included in the packaging of this file. Please review the  ** following information to ensure the GNU Lesser General Public License  ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** In addition, as a special exception, Digia gives you certain additional  ** rights. These rights are described in the Digia Qt LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPPSATTRIBUTE_P_H
end_ifndef
begin_define
DECL|macro|QPPSATTRIBUTE_P_H
define|#
directive|define
name|QPPSATTRIBUTE_P_H
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
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPpsAttributePrivate
name|class
name|QPpsAttributePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPpsAttribute
name|class
name|QPpsAttribute
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QPpsAttributeList
typedef|typedef
name|QList
operator|<
name|QPpsAttribute
operator|>
name|QPpsAttributeList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QPpsAttributeMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QPpsAttribute
operator|>
name|QPpsAttributeMap
expr_stmt|;
end_typedef
begin_macro
DECL|function|Q_DECLARE_METATYPE
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPpsAttributeList
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPpsAttributeMap
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QPpsAttribute
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|None
init|=
literal|0
block|,
name|Number
init|=
literal|1
block|,
name|Bool
init|=
literal|2
block|,
name|String
init|=
literal|3
block|,
name|Array
init|=
literal|4
block|,
name|Object
init|=
literal|5
block|}
enum|;
enum|enum
name|Flag
block|{
name|Incomplete
init|=
literal|0x01
block|,
name|Deleted
init|=
literal|0x02
block|,
name|Created
init|=
literal|0x04
block|,
name|Truncated
init|=
literal|0x08
block|,
name|Purged
init|=
literal|0x10
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Flags
argument_list|,
argument|Flag
argument_list|)
name|QPpsAttribute
argument_list|()
expr_stmt|;
name|QPpsAttribute
argument_list|(
specifier|const
name|QPpsAttribute
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QPpsAttribute
argument_list|()
expr_stmt|;
name|QPpsAttribute
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPpsAttribute
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPpsAttribute
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPpsAttribute
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QPpsAttribute
argument_list|(
name|QPpsAttribute
operator|&&
name|other
argument_list|)
expr_stmt|;
name|QPpsAttribute
modifier|&
name|operator
init|=
operator|(
name|QPpsAttribute
operator|&&
name|other
operator|)
decl_stmt|;
endif|#
directive|endif
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QPpsAttribute
operator|::
name|Flags
name|flags
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNumber
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBool
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isArray
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isObject
argument_list|()
specifier|const
expr_stmt|;
name|double
name|toDouble
argument_list|()
specifier|const
expr_stmt|;
name|qlonglong
name|toLongLong
argument_list|()
specifier|const
expr_stmt|;
name|int
name|toInt
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|toBool
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|QPpsAttributeList
name|toList
argument_list|()
specifier|const
expr_stmt|;
name|QPpsAttributeMap
name|toMap
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|toVariant
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QPpsAttributePrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QPpsAttributePrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|QPpsAttribute
operator|::
name|operator
operator|!=
operator|(
specifier|const
name|QPpsAttribute
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QPpsAttribute
operator|&
name|attribute
operator|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPPSATTRIBUTE_P_H
end_comment
end_unit
