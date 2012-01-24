begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|"qitemeditorfactory.h"
end_include
begin_include
include|#
directive|include
file|"qitemeditorfactory_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qdatetimeedit.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_class
DECL|class|QBooleanComboBox
class|class
name|QBooleanComboBox
super|:
specifier|public
name|QComboBox
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
name|bool
name|value
name|READ
name|value
name|WRITE
name|setValue
name|USER
literal|true
argument_list|)
decl|public
range|:
name|QBooleanComboBox
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
decl_stmt|;
name|void
name|setValue
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|value
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
begin_comment
comment|/*!     \class QItemEditorFactory     \brief The QItemEditorFactory class provides widgets for editing item data     in views and delegates.     \since 4.2     \ingroup model-view     \inmodule QtWidgets      When editing data in an item view, editors are created and     displayed by a delegate. QItemDelegate, which is the delegate by     default installed on Qt's item views, uses a QItemEditorFactory to     create editors for it. A default unique instance provided by     QItemEditorFactory is used by all item delegates.  If you set a     new default factory with setDefaultFactory(), the new factory will     be used by existing and new delegates.      A factory keeps a collection of QItemEditorCreatorBase     instances, which are specialized editors that produce editors     for one particular QVariant data type (All Qt models store     their data in \l{QVariant}s).      \section1 Standard Editing Widgets      The standard factory implementation provides editors for a variety of data     types. These are created whenever a delegate needs to provide an editor for     data supplied by a model. The following table shows the relationship between     types and the standard editors provided.      \table     \header \o Type \o Editor Widget     \row    \o bool \o QComboBox     \row    \o double \o QDoubleSpinBox     \row    \o int \o{1,2} QSpinBox     \row    \o unsigned int     \row    \o QDate \o QDateEdit     \row    \o QDateTime \o QDateTimeEdit     \row    \o QPixmap \o QLabel     \row    \o QString \o QLineEdit     \row    \o QTime \o QTimeEdit     \endtable      Additional editors can be registered with the registerEditor() function.      \sa QItemDelegate, {Model/View Programming}, {Color Editor Factory Example} */
end_comment
begin_comment
comment|/*!     \fn QItemEditorFactory::QItemEditorFactory()      Constructs a new item editor factory. */
end_comment
begin_comment
comment|/*!     Creates an editor widget with the given \a parent for the specified \a type of data,     and returns it as a QWidget.      \sa registerEditor() */
end_comment
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|QItemEditorFactory
operator|::
name|createEditor
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
specifier|const
block|{
name|QItemEditorCreatorBase
modifier|*
name|creator
init|=
name|creatorMap
operator|.
name|value
argument_list|(
name|type
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|creator
condition|)
block|{
specifier|const
name|QItemEditorFactory
modifier|*
name|dfactory
init|=
name|defaultFactory
argument_list|()
decl_stmt|;
return|return
name|dfactory
operator|==
name|this
condition|?
literal|0
else|:
name|dfactory
operator|->
name|createEditor
argument_list|(
name|type
argument_list|,
name|parent
argument_list|)
return|;
block|}
return|return
name|creator
operator|->
name|createWidget
argument_list|(
name|parent
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the property name used to access data for the given \a type of data. */
end_comment
begin_function
DECL|function|valuePropertyName
name|QByteArray
name|QItemEditorFactory
operator|::
name|valuePropertyName
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
specifier|const
block|{
name|QItemEditorCreatorBase
modifier|*
name|creator
init|=
name|creatorMap
operator|.
name|value
argument_list|(
name|type
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|creator
condition|)
block|{
specifier|const
name|QItemEditorFactory
modifier|*
name|dfactory
init|=
name|defaultFactory
argument_list|()
decl_stmt|;
return|return
name|dfactory
operator|==
name|this
condition|?
name|QByteArray
argument_list|()
else|:
name|dfactory
operator|->
name|valuePropertyName
argument_list|(
name|type
argument_list|)
return|;
block|}
return|return
name|creator
operator|->
name|valuePropertyName
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the item editor factory. */
end_comment
begin_destructor
DECL|function|~QItemEditorFactory
name|QItemEditorFactory
operator|::
name|~
name|QItemEditorFactory
parameter_list|()
block|{
comment|//we make sure we delete all the QItemEditorCreatorBase
comment|//this has to be done only once, hence the QSet
name|QSet
argument_list|<
name|QItemEditorCreatorBase
modifier|*
argument_list|>
name|set
init|=
name|creatorMap
operator|.
name|values
argument_list|()
operator|.
name|toSet
argument_list|()
decl_stmt|;
name|qDeleteAll
argument_list|(
name|set
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Registers an item editor creator specified by \a creator for the given \a type of data.      \bold{Note:} The factory takes ownership of the item editor creator and will destroy     it if a new creator for the same type is registered later.      \sa createEditor() */
end_comment
begin_function
DECL|function|registerEditor
name|void
name|QItemEditorFactory
operator|::
name|registerEditor
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|,
name|QItemEditorCreatorBase
modifier|*
name|creator
parameter_list|)
block|{
name|QHash
argument_list|<
name|QVariant
operator|::
name|Type
argument_list|,
name|QItemEditorCreatorBase
modifier|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|creatorMap
operator|.
name|find
argument_list|(
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|creatorMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|QItemEditorCreatorBase
modifier|*
name|oldCreator
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|oldCreator
argument_list|)
expr_stmt|;
name|creatorMap
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|creatorMap
operator|.
name|values
argument_list|()
operator|.
name|contains
argument_list|(
name|oldCreator
argument_list|)
condition|)
operator|delete
name|oldCreator
expr_stmt|;
comment|// if it is no more in use we can delete it
block|}
name|creatorMap
index|[
name|type
index|]
operator|=
name|creator
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QDefaultItemEditorFactory
class|class
name|QDefaultItemEditorFactory
super|:
specifier|public
name|QItemEditorFactory
block|{
public|public:
DECL|function|QDefaultItemEditorFactory
specifier|inline
name|QDefaultItemEditorFactory
parameter_list|()
block|{}
name|QWidget
modifier|*
name|createEditor
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
specifier|const
function_decl|;
name|QByteArray
name|valuePropertyName
parameter_list|(
name|QVariant
operator|::
name|Type
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|QDefaultItemEditorFactory
operator|::
name|createEditor
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
case|case
name|QVariant
operator|::
name|Bool
case|:
block|{
name|QBooleanComboBox
modifier|*
name|cb
init|=
operator|new
name|QBooleanComboBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|cb
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|cb
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
case|case
name|QVariant
operator|::
name|UInt
case|:
block|{
name|QSpinBox
modifier|*
name|sb
init|=
operator|new
name|QSpinBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|sb
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sb
operator|->
name|setMaximum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
return|return
name|sb
return|;
block|}
case|case
name|QVariant
operator|::
name|Int
case|:
block|{
name|QSpinBox
modifier|*
name|sb
init|=
operator|new
name|QSpinBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|sb
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sb
operator|->
name|setMinimum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|sb
operator|->
name|setMaximum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
return|return
name|sb
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DATETIMEEDIT
case|case
name|QVariant
operator|::
name|Date
case|:
block|{
name|QDateTimeEdit
modifier|*
name|ed
init|=
operator|new
name|QDateEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|ed
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|ed
return|;
block|}
case|case
name|QVariant
operator|::
name|Time
case|:
block|{
name|QDateTimeEdit
modifier|*
name|ed
init|=
operator|new
name|QTimeEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|ed
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|ed
return|;
block|}
case|case
name|QVariant
operator|::
name|DateTime
case|:
block|{
name|QDateTimeEdit
modifier|*
name|ed
init|=
operator|new
name|QDateTimeEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|ed
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|ed
return|;
block|}
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|Pixmap
case|:
return|return
operator|new
name|QLabel
argument_list|(
name|parent
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
case|case
name|QVariant
operator|::
name|Double
case|:
block|{
name|QDoubleSpinBox
modifier|*
name|sb
init|=
operator|new
name|QDoubleSpinBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|sb
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sb
operator|->
name|setMinimum
argument_list|(
operator|-
name|DBL_MAX
argument_list|)
expr_stmt|;
name|sb
operator|->
name|setMaximum
argument_list|(
name|DBL_MAX
argument_list|)
expr_stmt|;
return|return
name|sb
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
case|case
name|QVariant
operator|::
name|String
case|:
default|default:
block|{
comment|// the default editor is a lineedit
name|QExpandingLineEdit
modifier|*
name|le
init|=
operator|new
name|QExpandingLineEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|le
operator|->
name|setFrame
argument_list|(
name|le
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_ItemView_DrawDelegateFrame
argument_list|,
literal|0
argument_list|,
name|le
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|le
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_ItemView_ShowDecorationSelected
argument_list|,
literal|0
argument_list|,
name|le
argument_list|)
condition|)
name|le
operator|->
name|setWidgetOwnsGeometry
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|le
return|;
block|}
else|#
directive|else
default|default:
break|break;
endif|#
directive|endif
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|valuePropertyName
name|QByteArray
name|QDefaultItemEditorFactory
operator|::
name|valuePropertyName
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
case|case
name|QVariant
operator|::
name|Bool
case|:
return|return
literal|"currentIndex"
return|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
case|case
name|QVariant
operator|::
name|UInt
case|:
case|case
name|QVariant
operator|::
name|Int
case|:
case|case
name|QVariant
operator|::
name|Double
case|:
return|return
literal|"value"
return|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DATETIMEEDIT
case|case
name|QVariant
operator|::
name|Date
case|:
return|return
literal|"date"
return|;
case|case
name|QVariant
operator|::
name|Time
case|:
return|return
literal|"time"
return|;
case|case
name|QVariant
operator|::
name|DateTime
case|:
return|return
literal|"dateTime"
return|;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|String
case|:
default|default:
comment|// the default editor is a lineedit
return|return
literal|"text"
return|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|q_default_factory
specifier|static
name|QItemEditorFactory
modifier|*
name|q_default_factory
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QDefaultFactoryCleaner
struct|struct
name|QDefaultFactoryCleaner
block|{
DECL|function|QDefaultFactoryCleaner
specifier|inline
name|QDefaultFactoryCleaner
parameter_list|()
block|{}
DECL|function|~QDefaultFactoryCleaner
name|~
name|QDefaultFactoryCleaner
parameter_list|()
block|{
operator|delete
name|q_default_factory
expr_stmt|;
name|q_default_factory
operator|=
literal|0
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_comment
comment|/*!     Returns the default item editor factory.      \sa setDefaultFactory() */
end_comment
begin_function
DECL|function|defaultFactory
specifier|const
name|QItemEditorFactory
modifier|*
name|QItemEditorFactory
operator|::
name|defaultFactory
parameter_list|()
block|{
specifier|static
specifier|const
name|QDefaultItemEditorFactory
name|factory
decl_stmt|;
if|if
condition|(
name|q_default_factory
condition|)
return|return
name|q_default_factory
return|;
return|return
operator|&
name|factory
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the default item editor factory to the given \a factory.     Both new and existing delegates will use the new factory.      \sa defaultFactory() */
end_comment
begin_function
DECL|function|setDefaultFactory
name|void
name|QItemEditorFactory
operator|::
name|setDefaultFactory
parameter_list|(
name|QItemEditorFactory
modifier|*
name|factory
parameter_list|)
block|{
specifier|static
specifier|const
name|QDefaultFactoryCleaner
name|cleaner
decl_stmt|;
operator|delete
name|q_default_factory
expr_stmt|;
name|q_default_factory
operator|=
name|factory
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QItemEditorCreatorBase     \brief The QItemEditorCreatorBase class provides an abstract base class that     must be subclassed when implementing new item editor creators.     \since 4.2     \ingroup model-view     \inmodule QtWidgets      QItemEditorCreatorBase objects are specialized widget factories that     provide editor widgets for one particular QVariant data type. They     are used by QItemEditorFactory to create editors for     \l{QItemDelegate}s. Creator bases must be registered with     QItemEditorFactory::registerEditor().      An editor should provide a user property for the data it edits.     QItemDelagates can then access the property using Qt's     \l{Meta-Object System}{meta-object system} to set and retrieve the     editing data. A property is set as the user property with the USER     keyword:      \snippet doc/src/snippets/code/src_gui_itemviews_qitemeditorfactory.cpp 0      If the editor does not provide a user property, it must return the     name of the property from valuePropertyName(); delegates will then     use the name to access the property. If a user property exists,     item delegates will not call valuePropertyName().      QStandardItemEditorCreator is a convenience template class that can be used     to register widgets without the need to subclass QItemEditorCreatorBase.      \sa QStandardItemEditorCreator, QItemEditorFactory,     {Model/View Programming}, {Color Editor Factory Example} */
end_comment
begin_comment
comment|/*!     \fn QItemEditorCreatorBase::~QItemEditorCreatorBase()      Destroys the editor creator object. */
end_comment
begin_comment
comment|/*!     \fn QWidget *QItemEditorCreatorBase::createWidget(QWidget *parent) const      Returns an editor widget with the given \a parent.      When implementing this function in subclasses of this class, you must     construct and return new editor widgets with the parent widget specified. */
end_comment
begin_comment
comment|/*!     \fn QByteArray QItemEditorCreatorBase::valuePropertyName() const      Returns the name of the property used to get and set values in the creator's     editor widgets.      When implementing this function in subclasses, you must ensure that the     editor widget's property specified by this function can accept the type     the creator is registered for. For example, a creator which constructs     QCheckBox widgets to edit boolean values would return the     \l{QCheckBox::checkable}{checkable} property name from this function,     and must be registered in the item editor factory for the QVariant::Bool     type.      Note: Since Qt 4.2 the item delegates query the user property of widgets,     and only call this function if the widget has no user property. You can     override this behavior by reimplementing QAbstractItemDelegate::setModelData()     and QAbstractItemDelegate::setEditorData().      \sa QMetaObject::userProperty(), QItemEditorFactory::registerEditor() */
end_comment
begin_comment
comment|/*!     \class QItemEditorCreator     \brief The QItemEditorCreator class makes it possible to create 	   item editor creator bases without subclassing 	   QItemEditorCreatorBase.      \since 4.2     \ingroup model-view     \inmodule QtWidgets      QItemEditorCreator is a convenience template class. It uses     the template class to create editors for QItemEditorFactory.     This way, it is not necessary to subclass     QItemEditorCreatorBase.      \snippet doc/src/snippets/code/src_gui_itemviews_qitemeditorfactory.cpp 1      The constructor takes the name of the property that contains the     editing data. QItemDelegate can then access the property by name     when it sets and retrieves editing data. Only use this class if     your editor does not define a user property (using the USER     keyword in the Q_PROPERTY macro).  If the widget has a user     property, you should use QStandardItemEditorCreator instead.      \sa QItemEditorCreatorBase, QStandardItemEditorCreator, 	QItemEditorFactory, {Color Editor Factory Example} */
end_comment
begin_comment
comment|/*!     \fn QItemEditorCreator::QItemEditorCreator(const QByteArray&valuePropertyName)      Constructs an editor creator object using \a valuePropertyName     as the name of the property to be used for editing. The     property name is used by QItemDelegate when setting and     getting editor data.      Note that the \a valuePropertyName is only used if the editor     widget does not have a user property defined. */
end_comment
begin_comment
comment|/*!     \fn QWidget *QItemEditorCreator::createWidget(QWidget *parent) const     \reimp */
end_comment
begin_comment
comment|/*!     \fn QByteArray QItemEditorCreator::valuePropertyName() const     \reimp */
end_comment
begin_comment
comment|/*!     \class QStandardItemEditorCreator      \brief The QStandardItemEditorCreator class provides the     possibility to register widgets without having to subclass     QItemEditorCreatorBase.      \since 4.2     \ingroup model-view     \inmodule QtWidgets      This convenience template class makes it possible to register widgets without     having to subclass QItemEditorCreatorBase.      Example:      \snippet doc/src/snippets/code/src_gui_itemviews_qitemeditorfactory.cpp 2      Setting the \c editorFactory created above in an item delegate via     QItemDelegate::setItemEditorFactory() makes sure that all values of type     QVariant::DateTime will be edited in \c{MyFancyDateTimeEdit}.      The editor must provide a user property that will contain the     editing data. The property is used by \l{QItemDelegate}s to set     and retrieve the data (using Qt's \l{Meta-Object     System}{meta-object system}). You set the user property with     the USER keyword:      \snippet doc/src/snippets/code/src_gui_itemviews_qitemeditorfactory.cpp 3      \sa QItemEditorCreatorBase, QItemEditorCreator, 	QItemEditorFactory, QItemDelegate, {Color Editor Factory Example} */
end_comment
begin_comment
comment|/*!     \fn QStandardItemEditorCreator::QStandardItemEditorCreator()      Constructs an editor creator object. */
end_comment
begin_comment
comment|/*!     \fn QWidget *QStandardItemEditorCreator::createWidget(QWidget *parent) const     \reimp */
end_comment
begin_comment
comment|/*!     \fn QByteArray QStandardItemEditorCreator::valuePropertyName() const     \reimp */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_constructor
DECL|function|QExpandingLineEdit
name|QExpandingLineEdit
operator|::
name|QExpandingLineEdit
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|originalWidth
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|widgetOwnsGeometry
argument_list|(
literal|false
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|resizeToContents
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|updateMinimumWidth
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|changeEvent
name|void
name|QExpandingLineEdit
operator|::
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|FontChange
case|:
case|case
name|QEvent
operator|::
name|StyleChange
case|:
case|case
name|QEvent
operator|::
name|ContentsRectChange
case|:
name|updateMinimumWidth
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|QLineEdit
operator|::
name|changeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMinimumWidth
name|void
name|QExpandingLineEdit
operator|::
name|updateMinimumWidth
parameter_list|()
block|{
name|int
name|left
decl_stmt|,
name|right
decl_stmt|;
name|getTextMargins
argument_list|(
operator|&
name|left
argument_list|,
literal|0
argument_list|,
operator|&
name|right
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|int
name|width
init|=
name|left
operator|+
name|right
operator|+
literal|4
comment|/*horizontalMargin in qlineedit.cpp*/
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
literal|0
argument_list|,
operator|&
name|right
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|width
operator|+=
name|left
operator|+
name|right
expr_stmt|;
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|int
name|minWidth
init|=
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_LineEdit
argument_list|,
operator|&
name|opt
argument_list|,
name|QSize
argument_list|(
name|width
argument_list|,
literal|0
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|)
operator|.
name|width
argument_list|()
decl_stmt|;
name|setMinimumWidth
argument_list|(
name|minWidth
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeToContents
name|void
name|QExpandingLineEdit
operator|::
name|resizeToContents
parameter_list|()
block|{
name|int
name|oldWidth
init|=
name|width
argument_list|()
decl_stmt|;
if|if
condition|(
name|originalWidth
operator|==
operator|-
literal|1
condition|)
name|originalWidth
operator|=
name|oldWidth
expr_stmt|;
if|if
condition|(
name|QWidget
modifier|*
name|parent
init|=
name|parentWidget
argument_list|()
condition|)
block|{
name|QPoint
name|position
init|=
name|pos
argument_list|()
decl_stmt|;
name|int
name|hintWidth
init|=
name|minimumWidth
argument_list|()
operator|+
name|fontMetrics
argument_list|()
operator|.
name|width
argument_list|(
name|displayText
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|parentWidth
init|=
name|parent
operator|->
name|width
argument_list|()
decl_stmt|;
name|int
name|maxWidth
init|=
name|isRightToLeft
argument_list|()
condition|?
name|position
operator|.
name|x
argument_list|()
operator|+
name|oldWidth
else|:
name|parentWidth
operator|-
name|position
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|newWidth
init|=
name|qBound
argument_list|(
name|originalWidth
argument_list|,
name|hintWidth
argument_list|,
name|maxWidth
argument_list|)
decl_stmt|;
if|if
condition|(
name|widgetOwnsGeometry
condition|)
name|setMaximumWidth
argument_list|(
name|newWidth
argument_list|)
expr_stmt|;
if|if
condition|(
name|isRightToLeft
argument_list|()
condition|)
name|move
argument_list|(
name|position
operator|.
name|x
argument_list|()
operator|-
name|newWidth
operator|+
name|oldWidth
argument_list|,
name|position
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|newWidth
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LINEEDIT
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_constructor
DECL|function|QBooleanComboBox
name|QBooleanComboBox
operator|::
name|QBooleanComboBox
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QComboBox
argument_list|(
name|parent
argument_list|)
block|{
name|addItem
argument_list|(
name|QComboBox
operator|::
name|tr
argument_list|(
literal|"False"
argument_list|)
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|QComboBox
operator|::
name|tr
argument_list|(
literal|"True"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setValue
name|void
name|QBooleanComboBox
operator|::
name|setValue
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|setCurrentIndex
argument_list|(
name|value
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|value
name|bool
name|QBooleanComboBox
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|currentIndex
argument_list|()
operator|==
literal|1
operator|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LINEEDIT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|QT_NO_COMBOBOX
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qitemeditorfactory.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
end_unit
