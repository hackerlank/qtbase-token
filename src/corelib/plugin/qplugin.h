begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLUGIN_H
end_ifndef
begin_define
DECL|macro|QPLUGIN_H
define|#
directive|define
name|QPLUGIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|Q_EXTERN_C
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|Q_EXTERN_C
define|#
directive|define
name|Q_EXTERN_C
value|extern "C"
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|Q_EXTERN_C
value|extern
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QtPluginInstanceFunction
typedef|typedef
name|QObject
modifier|*
function_decl|(
modifier|*
name|QtPluginInstanceFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_typedef
DECL|typedef|QtPluginMetaDataFunction
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|QtPluginMetaDataFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_struct
DECL|struct|QStaticPlugin
struct|struct
name|QStaticPlugin
block|{
DECL|member|instance
name|QtPluginInstanceFunction
name|instance
decl_stmt|;
DECL|member|metaData
name|QtPluginMetaDataFunction
name|metaData
decl_stmt|;
block|}
struct|;
end_struct
begin_function_decl
name|void
name|Q_CORE_EXPORT
name|qRegisterStaticPluginFunction
parameter_list|(
name|QStaticPlugin
name|staticPlugin
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OF_ELF
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|)
end_if
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__attribute__ ((section (".qtmetadata"))) __attribute__((used))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_elif
begin_comment
comment|// TODO: Implement section parsing on Mac
end_comment
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__attribute__ ((section ("__TEXT,qtmetadata"))) __attribute__((used))
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_elif
begin_comment
comment|// TODO: Implement section parsing for MSVC
end_comment
begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".qtmetadata"
name|,
name|read
name|,
name|shared
name|)
end_pragma
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
define|\
value|__declspec(allocate(".qtmetadata"))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_PLUGIN_VERIFICATION_SECTION
define|#
directive|define
name|QT_PLUGIN_VERIFICATION_SECTION
end_define
begin_define
DECL|macro|QT_PLUGIN_METADATA_SECTION
define|#
directive|define
name|QT_PLUGIN_METADATA_SECTION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_IMPORT_PLUGIN
define|#
directive|define
name|Q_IMPORT_PLUGIN
parameter_list|(
name|PLUGIN
parameter_list|)
define|\
value|extern const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_##PLUGIN(); \         class Static##PLUGIN##PluginInstance{ \         public: \                 Static##PLUGIN##PluginInstance() { \                     qRegisterStaticPluginFunction(qt_static_plugin_##PLUGIN()); \                 } \         }; \        static Static##PLUGIN##PluginInstance static##PLUGIN##Instance;
end_define
begin_define
DECL|macro|Q_PLUGIN_INSTANCE
define|#
directive|define
name|Q_PLUGIN_INSTANCE
parameter_list|(
name|IMPLEMENTATION
parameter_list|)
define|\
value|{ \             static QT_PREPEND_NAMESPACE(QPointer)<QT_PREPEND_NAMESPACE(QObject)> _instance; \             if (!_instance)      \                 _instance = new IMPLEMENTATION; \             return _instance; \         }
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_STATICPLUGIN
argument_list|)
end_if
begin_define
DECL|macro|QT_MOC_EXPORT_PLUGIN
define|#
directive|define
name|QT_MOC_EXPORT_PLUGIN
parameter_list|(
name|PLUGINCLASS
parameter_list|,
name|PLUGINCLASSNAME
parameter_list|)
define|\
value|static QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance_##PLUGINCLASSNAME() \     Q_PLUGIN_INSTANCE(PLUGINCLASS) \     static const char *qt_plugin_query_metadata_##PLUGINCLASSNAME() { return (const char *)qt_pluginMetaData; } \     const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_##PLUGINCLASSNAME() { \         QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance_##PLUGINCLASSNAME, qt_plugin_query_metadata_##PLUGINCLASSNAME}; \         return plugin; \     }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_MOC_EXPORT_PLUGIN
define|#
directive|define
name|QT_MOC_EXPORT_PLUGIN
parameter_list|(
name|PLUGINCLASS
parameter_list|,
name|PLUGINCLASSNAME
parameter_list|)
define|\
value|Q_EXTERN_C Q_DECL_EXPORT \             const char *qt_plugin_query_metadata() \             { return (const char *)qt_pluginMetaData; } \             Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance() \             Q_PLUGIN_INSTANCE(PLUGINCLASS)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_EXPORT_PLUGIN
define|#
directive|define
name|Q_EXPORT_PLUGIN
parameter_list|(
name|PLUGIN
parameter_list|)
define|\
value|Q_EXPORT_PLUGIN2(PLUGIN, PLUGIN)
end_define
begin_define
DECL|macro|Q_EXPORT_PLUGIN2
define|#
directive|define
name|Q_EXPORT_PLUGIN2
parameter_list|(
name|PLUGIN
parameter_list|,
name|PLUGINCLASS
parameter_list|)
define|\
value|Q_STATIC_ASSERT_X(false, "Old plugin system used")
end_define
begin_define
DECL|macro|Q_EXPORT_STATIC_PLUGIN2
define|#
directive|define
name|Q_EXPORT_STATIC_PLUGIN2
parameter_list|(
name|PLUGIN
parameter_list|,
name|PLUGINCLASS
parameter_list|)
define|\
value|Q_STATIC_ASSERT_X(false, "Old plugin system used")
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_PLUGIN_H
end_comment
end_unit
