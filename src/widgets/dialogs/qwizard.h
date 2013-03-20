begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIZARD_H
end_ifndef
begin_define
DECL|macro|QWIZARD_H
define|#
directive|define
name|QWIZARD_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_WIZARD
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWizardPage
name|class
name|QWizardPage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWizardPrivate
name|class
name|QWizardPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWizard
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|WizardStyle WizardOption
argument_list|)
name|Q_FLAGS
argument_list|(
argument|WizardOptions
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|WizardStyle wizardStyle READ wizardStyle WRITE setWizardStyle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|WizardOptions options READ options WRITE setOptions
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextFormat titleFormat READ titleFormat WRITE setTitleFormat
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextFormat subTitleFormat READ subTitleFormat WRITE setSubTitleFormat
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startId READ startId WRITE setStartId
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentId READ currentId NOTIFY currentIdChanged
argument_list|)
name|public
operator|:
expr|enum
name|WizardButton
block|{
name|BackButton
block|,
name|NextButton
block|,
name|CommitButton
block|,
name|FinishButton
block|,
name|CancelButton
block|,
name|HelpButton
block|,
name|CustomButton1
block|,
name|CustomButton2
block|,
name|CustomButton3
block|,
name|Stretch
block|,
name|NoButton
operator|=
operator|-
literal|1
block|,
name|NStandardButtons
operator|=
literal|6
block|,
name|NButtons
operator|=
literal|9
block|}
block|;      enum
name|WizardPixmap
block|{
name|WatermarkPixmap
block|,
name|LogoPixmap
block|,
name|BannerPixmap
block|,
name|BackgroundPixmap
block|,
name|NPixmaps
block|}
block|;      enum
name|WizardStyle
block|{
name|ClassicStyle
block|,
name|ModernStyle
block|,
name|MacStyle
block|,
name|AeroStyle
block|,
name|NStyles
block|}
block|;      enum
name|WizardOption
block|{
name|IndependentPages
operator|=
literal|0x00000001
block|,
name|IgnoreSubTitles
operator|=
literal|0x00000002
block|,
name|ExtendedWatermarkPixmap
operator|=
literal|0x00000004
block|,
name|NoDefaultButton
operator|=
literal|0x00000008
block|,
name|NoBackButtonOnStartPage
operator|=
literal|0x00000010
block|,
name|NoBackButtonOnLastPage
operator|=
literal|0x00000020
block|,
name|DisabledBackButtonOnLastPage
operator|=
literal|0x00000040
block|,
name|HaveNextButtonOnLastPage
operator|=
literal|0x00000080
block|,
name|HaveFinishButtonOnEarlyPages
operator|=
literal|0x00000100
block|,
name|NoCancelButton
operator|=
literal|0x00000200
block|,
name|CancelButtonOnLeft
operator|=
literal|0x00000400
block|,
name|HaveHelpButton
operator|=
literal|0x00000800
block|,
name|HelpButtonOnRight
operator|=
literal|0x00001000
block|,
name|HaveCustomButton1
operator|=
literal|0x00002000
block|,
name|HaveCustomButton2
operator|=
literal|0x00004000
block|,
name|HaveCustomButton3
operator|=
literal|0x00008000
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|WizardOptions
argument_list|,
argument|WizardOption
argument_list|)
name|explicit
name|QWizard
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QWizard
argument_list|()
block|;
name|int
name|addPage
argument_list|(
name|QWizardPage
operator|*
name|page
argument_list|)
block|;
name|void
name|setPage
argument_list|(
argument|int id
argument_list|,
argument|QWizardPage *page
argument_list|)
block|;
name|void
name|removePage
argument_list|(
argument|int id
argument_list|)
block|;
name|QWizardPage
operator|*
name|page
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|bool
name|hasVisitedPage
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|int
operator|>
name|visitedPages
argument_list|()
specifier|const
block|;
comment|// ### Qt 6: visitedIds()?
name|QList
operator|<
name|int
operator|>
name|pageIds
argument_list|()
specifier|const
block|;
name|void
name|setStartId
argument_list|(
argument|int id
argument_list|)
block|;
name|int
name|startId
argument_list|()
specifier|const
block|;
name|QWizardPage
operator|*
name|currentPage
argument_list|()
specifier|const
block|;
name|int
name|currentId
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|validateCurrentPage
argument_list|()
block|;
name|virtual
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|void
name|setField
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
name|QVariant
name|field
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|void
name|setWizardStyle
argument_list|(
argument|WizardStyle style
argument_list|)
block|;
name|WizardStyle
name|wizardStyle
argument_list|()
specifier|const
block|;
name|void
name|setOption
argument_list|(
argument|WizardOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|WizardOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|WizardOptions options
argument_list|)
block|;
name|WizardOptions
name|options
argument_list|()
specifier|const
block|;
name|void
name|setButtonText
argument_list|(
argument|WizardButton which
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|buttonText
argument_list|(
argument|WizardButton which
argument_list|)
specifier|const
block|;
name|void
name|setButtonLayout
argument_list|(
specifier|const
name|QList
operator|<
name|WizardButton
operator|>
operator|&
name|layout
argument_list|)
block|;
name|void
name|setButton
argument_list|(
argument|WizardButton which
argument_list|,
argument|QAbstractButton *button
argument_list|)
block|;
name|QAbstractButton
operator|*
name|button
argument_list|(
argument|WizardButton which
argument_list|)
specifier|const
block|;
name|void
name|setTitleFormat
argument_list|(
argument|Qt::TextFormat format
argument_list|)
block|;
name|Qt
operator|::
name|TextFormat
name|titleFormat
argument_list|()
specifier|const
block|;
name|void
name|setSubTitleFormat
argument_list|(
argument|Qt::TextFormat format
argument_list|)
block|;
name|Qt
operator|::
name|TextFormat
name|subTitleFormat
argument_list|()
specifier|const
block|;
name|void
name|setPixmap
argument_list|(
argument|WizardPixmap which
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
block|;
name|QPixmap
name|pixmap
argument_list|(
argument|WizardPixmap which
argument_list|)
specifier|const
block|;
name|void
name|setSideWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|sideWidget
argument_list|()
specifier|const
block|;
name|void
name|setDefaultProperty
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|property
argument_list|,
specifier|const
name|char
operator|*
name|changedSignal
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentIdChanged
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|helpRequested
argument_list|()
block|;
name|void
name|customButtonClicked
argument_list|(
argument|int which
argument_list|)
block|;
name|void
name|pageAdded
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|pageRemoved
argument_list|(
argument|int id
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|back
argument_list|()
block|;
name|void
name|next
argument_list|()
block|;
name|void
name|restart
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|bool
name|nativeEvent
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
endif|#
directive|endif
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|;
name|virtual
name|void
name|initializePage
argument_list|(
argument|int id
argument_list|)
block|;
name|virtual
name|void
name|cleanupPage
argument_list|(
argument|int id
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWizard
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWizard
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitCustomButtonClicked()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateButtonStates()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_handleFieldObjectDestroyed(QObject *)
argument_list|)
name|friend
name|class
name|QWizardPage
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QWizard::WizardOptions
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QWizardPagePrivate
name|class
name|QWizardPagePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWizardPage
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString title READ title WRITE setTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString subTitle READ subTitle WRITE setSubTitle
argument_list|)
name|public
operator|:
name|explicit
name|QWizardPage
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWizardPage
argument_list|()
block|;
name|void
name|setTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QString
name|title
argument_list|()
specifier|const
block|;
name|void
name|setSubTitle
argument_list|(
specifier|const
name|QString
operator|&
name|subTitle
argument_list|)
block|;
name|QString
name|subTitle
argument_list|()
specifier|const
block|;
name|void
name|setPixmap
argument_list|(
argument|QWizard::WizardPixmap which
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
block|;
name|QPixmap
name|pixmap
argument_list|(
argument|QWizard::WizardPixmap which
argument_list|)
specifier|const
block|;
name|void
name|setFinalPage
argument_list|(
argument|bool finalPage
argument_list|)
block|;
name|bool
name|isFinalPage
argument_list|()
specifier|const
block|;
name|void
name|setCommitPage
argument_list|(
argument|bool commitPage
argument_list|)
block|;
name|bool
name|isCommitPage
argument_list|()
specifier|const
block|;
name|void
name|setButtonText
argument_list|(
argument|QWizard::WizardButton which
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|buttonText
argument_list|(
argument|QWizard::WizardButton which
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|initializePage
argument_list|()
block|;
name|virtual
name|void
name|cleanupPage
argument_list|()
block|;
name|virtual
name|bool
name|validatePage
argument_list|()
block|;
name|virtual
name|bool
name|isComplete
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|nextId
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|completeChanged
argument_list|()
block|;
name|protected
operator|:
name|void
name|setField
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
name|QVariant
name|field
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|void
name|registerField
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|char
operator|*
name|property
operator|=
literal|0
argument_list|,
specifier|const
name|char
operator|*
name|changedSignal
operator|=
literal|0
argument_list|)
block|;
name|QWizard
operator|*
name|wizard
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWizardPage
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWizardPage
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_maybeEmitCompleteChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateCachedCompleteState()
argument_list|)
name|friend
name|class
name|QWizard
block|;
name|friend
name|class
name|QWizardPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_WIZARD
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWIZARD_H
end_comment
end_unit
