begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   htmlgenerator.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HTMLGENERATOR_H
end_ifndef
begin_define
DECL|macro|HTMLGENERATOR_H
define|#
directive|define
name|HTMLGENERATOR_H
end_define
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qxmlstream.h>
end_include
begin_include
include|#
directive|include
file|"codemarker.h"
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"generator.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|HelpProjectWriter
name|class
name|HelpProjectWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|HtmlGenerator
range|:
name|public
name|Generator
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::HtmlGenerator
argument_list|)
name|public
operator|:
expr|enum
name|SinceType
block|{
name|Namespace
block|,
name|Class
block|,
name|MemberFunction
block|,
name|NamespaceFunction
block|,
name|GlobalFunction
block|,
name|Macro
block|,
name|Enum
block|,
name|Typedef
block|,
name|Property
block|,
name|Variable
block|,
name|QmlClass
block|,
name|QmlProperty
block|,
name|QmlSignal
block|,
name|QmlSignalHandler
block|,
name|QmlMethod
block|,
name|LastSinceType
block|}
block|;
name|public
operator|:
name|HtmlGenerator
argument_list|()
block|;
operator|~
name|HtmlGenerator
argument_list|()
block|;
name|virtual
name|void
name|initializeGenerator
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|)
block|;
name|virtual
name|void
name|terminateGenerator
argument_list|()
block|;
name|virtual
name|QString
name|format
argument_list|()
block|;
name|virtual
name|void
name|generateDocs
argument_list|()
block|;
name|void
name|generateManifestFiles
argument_list|()
block|;
name|QString
name|protectEnc
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
specifier|static
name|QString
name|protect
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|,
specifier|const
name|QString
operator|&
name|encoding
operator|=
literal|"ISO-8859-1"
argument_list|)
block|;
specifier|static
name|QString
name|cleanRef
argument_list|(
specifier|const
name|QString
operator|&
name|ref
argument_list|)
block|;
specifier|static
name|QString
name|sinceTitle
argument_list|(
argument|int i
argument_list|)
block|{
return|return
name|sinceTitles
index|[
name|i
index|]
return|;
block|}
name|protected
operator|:
name|virtual
name|void
name|generateQAPage
argument_list|()
block|;
name|QString
name|generateLinksToLinksPage
argument_list|(
specifier|const
name|QString
operator|&
name|module
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|QString
name|generateLinksToBrokenLinksPage
argument_list|(
name|CodeMarker
operator|*
name|marker
argument_list|,
name|int
operator|&
name|count
argument_list|)
block|;
name|virtual
name|int
name|generateAtom
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|void
name|generateClassLikeNode
argument_list|(
name|InnerNode
operator|*
name|inner
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|void
name|generateQmlTypePage
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|void
name|generateQmlBasicTypePage
argument_list|(
name|QmlBasicTypeNode
operator|*
name|qbtn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|void
name|generateDocNode
argument_list|(
name|DocNode
operator|*
name|dn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|void
name|generateCollectionNode
argument_list|(
name|CollectionNode
operator|*
name|cn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|virtual
name|QString
name|fileExtension
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|refForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|virtual
name|QString
name|linkForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|generateManifestFile
argument_list|(
argument|QString manifest
argument_list|,
argument|QString element
argument_list|)
block|;
name|void
name|readManifestMetaContent
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|)
block|;
name|void
name|generateKeywordAnchors
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|private
operator|:
expr|enum
name|SubTitleSize
block|{
name|SmallSubTitle
block|,
name|LargeSubTitle
block|}
block|;     enum
name|ExtractionMarkType
block|{
name|BriefMark
block|,
name|DetailedDescriptionMark
block|,
name|MemberMark
block|,
name|EndMark
block|}
block|;      struct
name|ManifestMetaFilter
block|{
name|QSet
operator|<
name|QString
operator|>
name|names
block|;
name|QSet
operator|<
name|QString
operator|>
name|attributes
block|;
name|QSet
operator|<
name|QString
operator|>
name|tags
block|;     }
block|;
specifier|const
name|QPair
operator|<
name|QString
block|,
name|QString
operator|>
name|anchorForNode
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
name|void
name|generateNavigationBar
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateHeader
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|Node
operator|*
name|node
operator|=
literal|0
argument_list|,
name|CodeMarker
operator|*
name|marker
operator|=
literal|0
argument_list|)
block|;
name|void
name|generateTitle
argument_list|(
argument|const QString& title
argument_list|,
argument|const Text&subTitle
argument_list|,
argument|SubTitleSize subTitleSize
argument_list|,
argument|const Node *relative
argument_list|,
argument|CodeMarker *marker
argument_list|)
block|;
name|void
name|generateFooter
argument_list|(
specifier|const
name|Node
operator|*
name|node
operator|=
literal|0
argument_list|)
block|;
name|void
name|generateRequisites
argument_list|(
name|InnerNode
operator|*
name|inner
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlRequisites
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateBrief
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|Node
operator|*
name|relative
operator|=
literal|0
argument_list|)
block|;
name|void
name|generateIncludes
argument_list|(
specifier|const
name|InnerNode
operator|*
name|inner
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateTableOfContents
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
name|QList
operator|<
name|Section
operator|>
operator|*
name|sections
operator|=
literal|0
argument_list|)
block|;
name|QString
name|generateListOfAllMemberFile
argument_list|(
specifier|const
name|InnerNode
operator|*
name|inner
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|QString
name|generateAllQmlMembersFile
argument_list|(
name|QmlClassNode
operator|*
name|qml_cn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|QString
name|generateLowStatusMemberFile
argument_list|(
argument|InnerNode *inner
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|CodeMarker::Status status
argument_list|)
block|;
name|QString
name|generateQmlMemberFile
argument_list|(
argument|QmlClassNode* qcn
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|CodeMarker::Status status
argument_list|)
block|;
name|void
name|generateClassHierarchy
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|NodeMap
operator|&
name|classMap
argument_list|)
block|;
name|void
name|generateAnnotatedList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|NodeMap
operator|&
name|nodeMap
argument_list|)
block|;
name|void
name|generateAnnotatedList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|NodeList
operator|&
name|nodes
argument_list|)
block|;
name|void
name|generateCompactList
argument_list|(
argument|ListType listType
argument_list|,
argument|const Node *relative
argument_list|,
argument|const NodeMap&classMap
argument_list|,
argument|bool includeAlphabet
argument_list|,
argument|QString commonPrefix
argument_list|)
block|;
name|void
name|generateFunctionIndex
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|generateLegaleseList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateList
argument_list|(
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|,
specifier|const
name|QString
operator|&
name|selector
argument_list|)
block|;
name|void
name|generateSectionList
argument_list|(
argument|const Section& section
argument_list|,
argument|const Node *relative
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|CodeMarker::SynopsisStyle style
argument_list|)
block|;
name|void
name|generateQmlSummary
argument_list|(
specifier|const
name|Section
operator|&
name|section
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlItem
argument_list|(
argument|const Node *node
argument_list|,
argument|const Node *relative
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|bool summary
argument_list|)
block|;
name|void
name|generateDetailedQmlMember
argument_list|(
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|InnerNode
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlInherits
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateQmlInstantiates
argument_list|(
name|QmlClassNode
operator|*
name|qcn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateInstantiatedBy
argument_list|(
name|ClassNode
operator|*
name|cn
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateRequisitesTable
argument_list|(
specifier|const
name|QStringList
operator|&
name|requisitesOrder
argument_list|,
name|QMap
operator|<
name|QString
argument_list|,
name|Text
operator|>
operator|&
name|requisites
argument_list|)
block|;
name|void
name|generateSection
argument_list|(
argument|const NodeList& nl
argument_list|,
argument|const Node *relative
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|CodeMarker::SynopsisStyle style
argument_list|)
block|;
name|void
name|generateSynopsis
argument_list|(
argument|const Node *node
argument_list|,
argument|const Node *relative
argument_list|,
argument|CodeMarker *marker
argument_list|,
argument|CodeMarker::SynopsisStyle style
argument_list|,
argument|bool alignNames = false
argument_list|,
argument|const QString* prefix =
literal|0
argument_list|)
block|;
name|void
name|generateSectionInheritedList
argument_list|(
specifier|const
name|Section
operator|&
name|section
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|QString
name|highlightedCode
argument_list|(
argument|const QString& markedCode
argument_list|,
argument|const Node* relative
argument_list|,
argument|bool alignNames = false
argument_list|)
block|;
name|void
name|generateFullName
argument_list|(
specifier|const
name|Node
operator|*
name|apparentNode
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
name|actualNode
operator|=
literal|0
argument_list|)
block|;
name|void
name|generateDetailedMember
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|InnerNode
operator|*
name|relative
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|void
name|generateStatus
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
name|QString
name|getLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
operator|*
name|node
argument_list|)
block|;
name|QString
name|getAutoLink
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Node
operator|*
operator|*
name|node
argument_list|)
block|;
name|QString
name|registerRef
argument_list|(
specifier|const
name|QString
operator|&
name|ref
argument_list|)
block|;
name|virtual
name|QString
name|fileBase
argument_list|(
argument|const Node *node
argument_list|)
specifier|const
block|;
name|QString
name|fileName
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
specifier|static
name|int
name|hOffset
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
block|;
specifier|static
name|bool
name|isThreeColumnEnumValueTable
argument_list|(
specifier|const
name|Atom
operator|*
name|atom
argument_list|)
block|;
ifdef|#
directive|ifdef
name|GENERATE_MAC_REFS
name|void
name|generateMacRef
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|,
name|CodeMarker
operator|*
name|marker
argument_list|)
block|;
endif|#
directive|endif
name|void
name|beginLink
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
block|;
name|void
name|endLink
argument_list|()
block|;
name|void
name|generateExtractionMark
argument_list|(
argument|const Node *node
argument_list|,
argument|ExtractionMarkType markType
argument_list|)
block|;
name|void
name|reportOrphans
argument_list|(
specifier|const
name|InnerNode
operator|*
name|parent
argument_list|)
block|;
name|void
name|beginDitamapPage
argument_list|(
specifier|const
name|InnerNode
operator|*
name|node
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|endDitamapPage
argument_list|()
block|;
name|void
name|writeDitaMap
argument_list|(
specifier|const
name|DitaMapNode
operator|*
name|node
argument_list|)
block|;
name|void
name|writeDitaRefs
argument_list|(
specifier|const
name|DitaRefList
operator|&
name|ditarefs
argument_list|)
block|;
name|QXmlStreamWriter
operator|&
name|xmlWriter
argument_list|()
block|;
name|QMap
operator|<
name|QString
block|,
name|QString
operator|>
name|refMap
block|;
name|int
name|codeIndent
block|;
name|HelpProjectWriter
operator|*
name|helpProjectWriter
block|;
name|bool
name|inObsoleteLink
block|;
name|QRegExp
name|funcLeftParen
block|;
name|QString
name|style
block|;
name|QString
name|headerScripts
block|;
name|QString
name|headerStyles
block|;
name|QString
name|endHeader
block|;
name|QString
name|postHeader
block|;
name|QString
name|postPostHeader
block|;
name|QString
name|footer
block|;
name|QString
name|address
block|;
name|bool
name|pleaseGenerateMacRef
block|;
name|bool
name|noNavigationBar
block|;
name|QString
name|project
block|;
name|QString
name|projectDescription
block|;
name|QString
name|projectUrl
block|;
name|QString
name|navigationLinks
block|;
name|QString
name|manifestDir
block|;
name|QString
name|examplesPath
block|;
name|QStringList
name|stylesheets
block|;
name|QStringList
name|customHeadElements
block|;
name|bool
name|obsoleteLinks
block|;
name|QStack
operator|<
name|QXmlStreamWriter
operator|*
operator|>
name|xmlWriterStack
block|;
specifier|static
name|int
name|id
block|;
name|QList
operator|<
name|ManifestMetaFilter
operator|>
name|manifestMetaContent
block|;
name|QString
name|homepage
block|;
name|QString
name|landingpage
block|;
name|QString
name|cppclassespage
block|;
name|QString
name|qmltypespage
block|;
name|QString
name|buildversion
block|;
name|QString
name|qflagsHref_
block|;
name|int
name|tocDepth
block|;
name|public
operator|:
specifier|static
name|bool
name|debugging_on
block|;
specifier|static
name|QString
name|divNavTop
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|HTMLGENERATOR_ADDRESS
define|#
directive|define
name|HTMLGENERATOR_ADDRESS
value|"address"
end_define
begin_define
DECL|macro|HTMLGENERATOR_FOOTER
define|#
directive|define
name|HTMLGENERATOR_FOOTER
value|"footer"
end_define
begin_define
DECL|macro|HTMLGENERATOR_GENERATEMACREFS
define|#
directive|define
name|HTMLGENERATOR_GENERATEMACREFS
value|"generatemacrefs"
end_define
begin_comment
DECL|macro|HTMLGENERATOR_GENERATEMACREFS
comment|// ### document me
end_comment
begin_define
DECL|macro|HTMLGENERATOR_POSTHEADER
define|#
directive|define
name|HTMLGENERATOR_POSTHEADER
value|"postheader"
end_define
begin_define
DECL|macro|HTMLGENERATOR_POSTPOSTHEADER
define|#
directive|define
name|HTMLGENERATOR_POSTPOSTHEADER
value|"postpostheader"
end_define
begin_define
DECL|macro|HTMLGENERATOR_NONAVIGATIONBAR
define|#
directive|define
name|HTMLGENERATOR_NONAVIGATIONBAR
value|"nonavigationbar"
end_define
begin_define
DECL|macro|HTMLGENERATOR_NOSUBDIRS
define|#
directive|define
name|HTMLGENERATOR_NOSUBDIRS
value|"nosubdirs"
end_define
begin_define
DECL|macro|HTMLGENERATOR_TOCDEPTH
define|#
directive|define
name|HTMLGENERATOR_TOCDEPTH
value|"tocdepth"
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
