begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   doc.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOC_H
end_ifndef
begin_define
DECL|macro|DOC_H
define|#
directive|define
name|DOC_H
end_define
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Atom
name|class
name|Atom
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CodeMarker
name|class
name|CodeMarker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Config
name|class
name|Config
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DocPrivate
name|class
name|DocPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Quoter
name|class
name|Quoter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Text
name|class
name|Text
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DitaRef
name|class
name|DitaRef
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|ArgLocPair
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
name|Location
operator|>
name|ArgLocPair
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|ArgList
typedef|typedef
name|QList
operator|<
name|ArgLocPair
operator|>
name|ArgList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|QStringMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringMultiMap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|QStringMultiMap
expr_stmt|;
end_typedef
begin_struct
DECL|struct|Topic
struct|struct
name|Topic
block|{
DECL|member|topic
name|QString
name|topic
decl_stmt|;
DECL|member|args
name|QString
name|args
decl_stmt|;
DECL|function|Topic
name|Topic
argument_list|()
block|{ }
DECL|function|Topic
name|Topic
argument_list|(
name|QString
operator|&
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|a
argument_list|)
operator|:
name|topic
argument_list|(
name|t
argument_list|)
operator|,
name|args
argument_list|(
argument|a
argument_list|)
block|{ }
DECL|function|isEmpty
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|topic
operator|.
name|isEmpty
argument_list|()
return|;
block|}
DECL|function|clear
name|void
name|clear
parameter_list|()
block|{
name|topic
operator|.
name|clear
argument_list|()
expr_stmt|;
name|args
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|TopicList
typedef|typedef
name|QList
operator|<
name|Topic
operator|>
name|TopicList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|DitaRefList
typedef|typedef
name|QList
operator|<
name|DitaRef
operator|*
operator|>
name|DitaRefList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|DitaRef
block|{
name|public
label|:
name|DitaRef
argument_list|()
block|{ }
name|virtual
operator|~
name|DitaRef
argument_list|()
block|{ }
specifier|const
name|QString
operator|&
name|navtitle
argument_list|()
specifier|const
block|{
return|return
name|navtitle_
return|;
block|}
specifier|const
name|QString
operator|&
name|href
argument_list|()
specifier|const
block|{
return|return
name|href_
return|;
block|}
name|void
name|setNavtitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
name|navtitle_
operator|=
name|t
expr_stmt|;
block|}
name|void
name|setHref
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
name|href_
operator|=
name|t
expr_stmt|;
block|}
name|virtual
name|bool
name|isMapRef
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|DitaRefList
operator|*
name|subrefs
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|appendSubref
parameter_list|(
name|DitaRef
modifier|*
parameter_list|)
block|{ }
name|private
label|:
name|QString
name|navtitle_
decl_stmt|;
name|QString
name|href_
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|TopicRef
range|:
name|public
name|DitaRef
block|{
name|public
operator|:
name|TopicRef
argument_list|()
block|{ }
operator|~
name|TopicRef
argument_list|()
block|;
name|virtual
name|bool
name|isMapRef
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|false
return|;
block|}
name|virtual
specifier|const
name|DitaRefList
operator|*
name|subrefs
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
operator|&
name|subrefs_
return|;
block|}
name|virtual
name|void
name|appendSubref
argument_list|(
argument|DitaRef* t
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|subrefs_
operator|.
name|append
argument_list|(
name|t
argument_list|)
block|; }
name|private
operator|:
name|DitaRefList
name|subrefs_
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MapRef
range|:
name|public
name|DitaRef
block|{
name|public
operator|:
name|MapRef
argument_list|()
block|{ }
operator|~
name|MapRef
argument_list|()
block|{ }
name|virtual
name|bool
name|isMapRef
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|Doc
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::Doc
argument_list|)
name|public
operator|:
comment|// the order is important
expr|enum
name|Sections
block|{
name|NoSection
operator|=
operator|-
literal|2
block|,
name|Part
operator|=
operator|-
literal|1
block|,
name|Chapter
operator|=
literal|1
block|,
name|Section1
operator|=
literal|1
block|,
name|Section2
operator|=
literal|2
block|,
name|Section3
operator|=
literal|3
block|,
name|Section4
operator|=
literal|4
block|}
block|;
name|Doc
argument_list|()
operator|:
name|priv
argument_list|(
literal|0
argument_list|)
block|{}
name|Doc
argument_list|(
specifier|const
name|Location
operator|&
name|start_loc
argument_list|,
specifier|const
name|Location
operator|&
name|end_loc
argument_list|,
specifier|const
name|QString
operator|&
name|source
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|metaCommandSet
argument_list|,
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|topics
argument_list|)
block|;
name|Doc
argument_list|(
specifier|const
name|Doc
operator|&
name|doc
argument_list|)
block|;
operator|~
name|Doc
argument_list|()
block|;
name|Doc
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Doc
operator|&
name|doc
operator|)
block|;
name|void
name|renameParameters
argument_list|(
specifier|const
name|QStringList
operator|&
name|oldNames
argument_list|,
specifier|const
name|QStringList
operator|&
name|newNames
argument_list|)
block|;
name|void
name|simplifyEnumDoc
argument_list|()
block|;
name|void
name|setBody
argument_list|(
specifier|const
name|Text
operator|&
name|body
argument_list|)
block|;
specifier|const
name|DitaRefList
operator|&
name|ditamap
argument_list|()
specifier|const
block|;
specifier|const
name|Location
operator|&
name|location
argument_list|()
specifier|const
block|;
specifier|const
name|Location
operator|&
name|startLocation
argument_list|()
specifier|const
block|;
specifier|const
name|Location
operator|&
name|endLocation
argument_list|()
specifier|const
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
specifier|const
name|QString
operator|&
name|source
argument_list|()
specifier|const
block|;
specifier|const
name|Text
operator|&
name|body
argument_list|()
specifier|const
block|;
name|Text
name|briefText
argument_list|(
argument|bool inclusive = false
argument_list|)
specifier|const
block|;
name|Text
name|trimmedBriefText
argument_list|(
argument|const QString&className
argument_list|)
specifier|const
block|;
name|Text
name|legaleseText
argument_list|()
specifier|const
block|;
name|Sections
name|granularity
argument_list|()
specifier|const
block|;
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|parameterNames
argument_list|()
specifier|const
block|;
specifier|const
name|QStringList
operator|&
name|enumItemNames
argument_list|()
specifier|const
block|;
specifier|const
name|QStringList
operator|&
name|omitEnumItemNames
argument_list|()
specifier|const
block|;
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|metaCommandsUsed
argument_list|()
specifier|const
block|;
specifier|const
name|TopicList
operator|&
name|topicsUsed
argument_list|()
specifier|const
block|;
name|ArgList
name|metaCommandArgs
argument_list|(
argument|const QString& metaCommand
argument_list|)
specifier|const
block|;
specifier|const
name|QList
operator|<
name|Text
operator|>
operator|&
name|alsoList
argument_list|()
specifier|const
block|;
name|bool
name|hasTableOfContents
argument_list|()
specifier|const
block|;
name|bool
name|hasKeywords
argument_list|()
specifier|const
block|;
name|bool
name|hasTargets
argument_list|()
specifier|const
block|;
specifier|const
name|QList
operator|<
name|Atom
operator|*
operator|>
operator|&
name|tableOfContents
argument_list|()
specifier|const
block|;
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|tableOfContentsLevels
argument_list|()
specifier|const
block|;
specifier|const
name|QList
operator|<
name|Atom
operator|*
operator|>
operator|&
name|keywords
argument_list|()
specifier|const
block|;
specifier|const
name|QList
operator|<
name|Atom
operator|*
operator|>
operator|&
name|targets
argument_list|()
specifier|const
block|;
specifier|const
name|QStringMultiMap
operator|&
name|metaTagMap
argument_list|()
specifier|const
block|;
specifier|static
name|void
name|initialize
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|)
block|;
specifier|static
name|void
name|terminate
argument_list|()
block|;
specifier|static
name|QString
name|alias
argument_list|(
specifier|const
name|QString
operator|&
name|english
argument_list|)
block|;
specifier|static
name|void
name|trimCStyleComment
argument_list|(
name|Location
operator|&
name|location
argument_list|,
name|QString
operator|&
name|str
argument_list|)
block|;
specifier|static
name|CodeMarker
operator|*
name|quoteFromFile
argument_list|(
specifier|const
name|Location
operator|&
name|location
argument_list|,
name|Quoter
operator|&
name|quoter
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
specifier|static
name|QString
name|canonicalTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
specifier|static
specifier|const
name|Config
operator|*
name|config
argument_list|()
block|{
return|return
name|config_
return|;
block|}
name|private
operator|:
name|void
name|detach
argument_list|()
block|;
name|DocPrivate
operator|*
name|priv
block|;
specifier|static
specifier|const
name|Config
operator|*
name|config_
block|; }
block|;
name|Q_DECLARE_TYPEINFO
argument_list|(
name|Doc
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
block|;
DECL|typedef|DocList
typedef|typedef
name|QList
operator|<
name|Doc
operator|>
name|DocList
expr_stmt|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
