begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPE_P_H
end_ifndef
begin_define
DECL|macro|QMETATYPE_P_H
define|#
directive|define
name|QMETATYPE_P_H
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
file|"qmetatype.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QModulesPrivate
block|{
enum|enum
name|Names
block|{
name|Core
block|,
name|Gui
block|,
name|Widgets
block|,
name|Unknown
block|,
name|ModulesCount
comment|/* ModulesCount has to be at the end */
block|}
enum|;
specifier|static
specifier|inline
name|int
name|moduleForType
parameter_list|(
specifier|const
name|uint
name|typeId
parameter_list|)
block|{
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastCoreType
condition|)
return|return
name|Core
return|;
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastGuiType
condition|)
return|return
name|Gui
return|;
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastWidgetsType
condition|)
return|return
name|Widgets
return|;
return|return
name|Unknown
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QTypeModuleInfo
block|{
name|public
operator|:
expr|enum
name|Module
block|{
name|IsCore
operator|=
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
block|,
comment|// Primitive types are in Core
name|IsWidget
operator|=
name|false
block|,
name|IsGui
operator|=
name|false
block|,
name|IsUnknown
operator|=
operator|!
name|IsCore
block|}
block|; }
expr_stmt|;
DECL|macro|QT_ASSIGN_TYPE_TO_MODULE
define|#
directive|define
name|QT_ASSIGN_TYPE_TO_MODULE
parameter_list|(
name|TYPE
parameter_list|,
name|MODULE
parameter_list|)
define|\
value|template<> \ class QTypeModuleInfo<TYPE> \ { \ public: \     enum Module { \         IsCore = (((MODULE) == (QModulesPrivate::Core))), \         IsWidget = (((MODULE) == (QModulesPrivate::Widgets))), \         IsGui = (((MODULE) == (QModulesPrivate::Gui))), \         IsUnknown = !(IsCore || IsWidget || IsGui) \     }; \     static inline int module() { return MODULE; } \     Q_STATIC_ASSERT((IsUnknown&& !(IsCore || IsWidget || IsGui)) \                  || (IsCore&& !(IsUnknown || IsWidget || IsGui)) \                  || (IsWidget&& !(IsUnknown || IsCore || IsGui)) \                  || (IsGui&& !(IsUnknown || IsCore || IsWidget))); \ };
DECL|macro|QT_DECLARE_CORE_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_CORE_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Core);
DECL|macro|QT_DECLARE_GUI_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_GUI_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Gui);
DECL|macro|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Widgets);
name|QT_FOR_EACH_STATIC_CORE_CLASS
argument_list|(
argument|QT_DECLARE_CORE_MODULE_TYPES_ITER
argument_list|)
name|QT_FOR_EACH_STATIC_CORE_TEMPLATE
argument_list|(
argument|QT_DECLARE_CORE_MODULE_TYPES_ITER
argument_list|)
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|QT_DECLARE_GUI_MODULE_TYPES_ITER
argument_list|)
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
argument_list|)
block|}
end_decl_stmt
begin_comment
comment|// namespace QModulesPrivate
end_comment
begin_undef
DECL|macro|QT_DECLARE_CORE_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_CORE_MODULE_TYPES_ITER
end_undef
begin_undef
DECL|macro|QT_DECLARE_GUI_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_GUI_MODULE_TYPES_ITER
end_undef
begin_undef
DECL|macro|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
end_undef
begin_decl_stmt
name|class
name|QMetaTypeInterface
block|{
name|public
label|:
name|QMetaType
operator|::
name|Creator
name|creator
expr_stmt|;
name|QMetaType
operator|::
name|Deleter
name|deleter
expr_stmt|;
name|QMetaType
operator|::
name|SaveOperator
name|saveOp
expr_stmt|;
name|QMetaType
operator|::
name|LoadOperator
name|loadOp
expr_stmt|;
name|QMetaType
operator|::
name|Constructor
name|constructor
expr_stmt|;
name|QMetaType
operator|::
name|Destructor
name|destructor
expr_stmt|;
name|int
name|size
decl_stmt|;
name|quint32
name|flags
decl_stmt|;
comment|// same as QMetaType::TypeFlags
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
define|\
comment|/*saveOp*/
value|(qMetaTypeSaveHelper<Type>), \
comment|/*loadOp*/
value|(qMetaTypeLoadHelper<Type>),
end_define
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
define|\
comment|/*saveOp*/
value|0, \
comment|/*loadOp*/
value|0,
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
define|\
comment|/*saveOp*/
value|0, \
comment|/*loadOp*/
value|0,
end_define
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
define|\
value|QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL(Type)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_IMPL
parameter_list|(
name|Type
parameter_list|,
name|DATASTREAM_DELEGATE
parameter_list|)
define|\
value|{ \
comment|/*creator*/
value|(qMetaTypeCreateHelper<Type>), \
comment|/*deleter*/
value|(qMetaTypeDeleteHelper<Type>), \     DATASTREAM_DELEGATE(Type) \
comment|/*constructor*/
value|(qMetaTypeConstructHelper<Type>), \
comment|/*destructor*/
value|(qMetaTypeDestructHelper<Type>), \
comment|/*size*/
value|(QTypeInfo<Type>::sizeOf), \
comment|/*flags*/
value|QtPrivate::QMetaTypeTypeFlags<Type>::Flags \ }
end_define
begin_comment
comment|/* These  QT_METATYPE_INTERFACE_INIT* macros are used to initialize QMetaTypeInterface instance.   - QT_METATYPE_INTERFACE_INIT(Type) -> It takes Type argument and creates all necessary wrapper functions for the Type,    it detects if QT_NO_DATASTREAM was defined. Probably it is the macro that you want to use.   - QT_METATYPE_INTERFACE_INIT_EMPTY() -> It initializes an empty QMetaTypeInterface instance.   - QT_METATYPE_INTERFACE_INIT_NO_DATASTREAM(Type) -> Temporary workaround for missing auto-detection of data stream    operators. It creates same instance as QT_METATYPE_INTERFACE_INIT(Type) but with null stream operators callbacks.  */
end_comment
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT
parameter_list|(
name|Type
parameter_list|)
value|QT_METATYPE_INTERFACE_INIT_IMPL(Type, QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL)
end_define
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_NO_DATASTREAM
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_NO_DATASTREAM
parameter_list|(
name|Type
parameter_list|)
value|QT_METATYPE_INTERFACE_INIT_IMPL(Type, QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL)
end_define
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_EMPTY
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_EMPTY
parameter_list|()
define|\
value|{ \
comment|/*creator*/
value|0, \
comment|/*deleter*/
value|0, \     QT_METATYPE_INTERFACE_INIT_EMPTY_DATASTREAM_IMPL() \
comment|/*constructor*/
value|0, \
comment|/*destructor*/
value|0, \
comment|/*size*/
value|0, \
comment|/*flags*/
value|0 \ }
end_define
begin_decl_stmt
name|namespace
name|QtMetaTypePrivate
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TypeDefinition
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|true
block|; }
expr_stmt|;
comment|// Ignore these types, as incomplete
ifdef|#
directive|ifdef
name|QT_BOOTSTRAPPED
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QBitArray
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QEasingCurve
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QJsonArray
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QJsonDocument
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QJsonObject
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QJsonValue
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QModelIndex
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QUrl
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_GEOM_VARIANT
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QRect
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QRectF
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QSize
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QSizeF
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QLine
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QLineF
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QPoint
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QPointF
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_REGEXP
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QRegExp
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_NO_REGEXP
argument_list|)
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QRegularExpression
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_SHORTCUT
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QKeySequence
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_CURSOR
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QCursor
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_MATRIX4X4
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QMatrix4x4
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_VECTOR2D
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QVector2D
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_VECTOR3D
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QVector3D
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_VECTOR4D
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QVector4D
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_NO_QUATERNION
name|template
operator|<
operator|>
expr|struct
name|TypeDefinition
operator|<
name|QQuaternion
operator|>
block|{
specifier|static
specifier|const
name|bool
name|IsAvailable
operator|=
name|false
block|; }
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_comment
comment|//namespace QtMetaTypePrivate
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPE_P_H
end_comment
end_unit
