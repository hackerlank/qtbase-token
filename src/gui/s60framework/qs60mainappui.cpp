begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Symbian application wrapper of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// INCLUDE FILES
end_comment
begin_include
include|#
directive|include
file|<exception>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_S60
end_ifdef
begin_include
include|#
directive|include
file|<avkon.hrh>
end_include
begin_include
include|#
directive|include
file|<eikmenub.h>
end_include
begin_include
include|#
directive|include
file|<eikmenup.h>
end_include
begin_include
include|#
directive|include
file|<avkon.rsg>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<barsread.h>
end_include
begin_include
include|#
directive|include
file|<coeutils.h>
end_include
begin_include
include|#
directive|include
file|<qconfig.h>
end_include
begin_include
include|#
directive|include
file|"qs60mainappui.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsymbianevent.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmenu.h>
end_include
begin_include
include|#
directive|include
file|<private/qmenu_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_s60_p.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_comment
comment|//Animated wallpapers in Qt applications are not supported.
end_comment
begin_decl_stmt
DECL|variable|KAknDisableAnimationBackground
specifier|const
name|TInt
name|KAknDisableAnimationBackground
init|=
literal|0x02000000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|KAknSingleClickCompatible
specifier|const
name|TInt
name|KAknSingleClickCompatible
init|=
literal|0x01000000
decl_stmt|;
end_decl_stmt
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QS60MainAppUi   \since 4.6   \brief The QS60MainAppUi class is a helper class for S60 migration.    \warning This class is provided only to get access to S60 specific   functionality in the application framework classes. It is not   portable. We strongly recommend against using it in new applications.    The QS60MainAppUi provides a helper class for use in migrating from   existing S60 based applications to Qt based applications. It is used   in the exact same way as the \c CAknAppUi class from Symbian, but   internally provides extensions used by Qt.    When modifying old S60 applications that rely on implementing   functions in \c CAknAppUi, the class should be modified to inherit   from this class instead of \c CAknAppUi. Then the application can   choose to override only certain functions.    For more information on \c CAknAppUi, please see the S60   documentation.    Unlike other Qt classes, QS60MainAppUi behaves like an S60 class,   and can throw Symbian leaves.    \sa QS60MainDocument, QS60MainApplication  */
comment|/*!  * \brief Second phase Symbian constructor.  *  * Constructs all the elements of the class that can cause a leave to happen.  *  * If you override this function, you should call the base class implementation as well.  */
DECL|function|ConstructL
name|void
name|QS60MainAppUi
operator|::
name|ConstructL
parameter_list|()
block|{
comment|// Cone's heap and handle checks on app destruction are not suitable for Qt apps, as many
comment|// objects can still exist in static data at that point. Instead we will print relevant information
comment|// so that comparative checks may be made for memory leaks, using ~SPrintExitInfo in corelib.
name|iEikonEnv
operator|->
name|DisableExitChecks
argument_list|(
name|ETrue
argument_list|)
expr_stmt|;
comment|// Initialise app UI with standard value.
comment|// ENoAppResourceFile and ENonStandardResourceFile makes UI to work without
comment|// resource files in most SDKs. S60 3rd FP1 public seems to require resource file
comment|// even these flags are defined
name|TInt
name|flags
init|=
name|CEikAppUi
operator|::
name|ENoScreenFurniture
operator||
name|CEikAppUi
operator|::
name|ENonStandardResourceFile
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_S60
name|flags
operator||=
name|CAknAppUi
operator|::
name|EAknEnableSkin
expr_stmt|;
comment|// After 5th Edition S60, native side supports animated wallpapers.
comment|// However, there is no support for that feature on Qt side, so indicate to
comment|// native UI framework that this application will not support background animations.
comment|// Also, add support for single touch for post 5th edition platforms.
comment|// This has only impact when launching native dialogs/menus from inside QApplication.
if|if
condition|(
name|QSysInfo
operator|::
name|s60Version
argument_list|()
operator|>
name|QSysInfo
operator|::
name|SV_S60_5_0
condition|)
block|{
name|flags
operator||=
operator|(
name|KAknDisableAnimationBackground
operator||
name|KAknSingleClickCompatible
operator|)
expr_stmt|;
block|}
endif|#
directive|endif
name|BaseConstructL
argument_list|(
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \brief Contructs an instance of QS60MainAppUi.  */
end_comment
begin_constructor
DECL|function|QS60MainAppUi
name|QS60MainAppUi
operator|::
name|QS60MainAppUi
parameter_list|()
block|{
comment|// No implementation required
block|}
end_constructor
begin_comment
comment|/*!  * \brief Destroys the QS60MainAppUi.  */
end_comment
begin_destructor
DECL|function|~QS60MainAppUi
name|QS60MainAppUi
operator|::
name|~
name|QS60MainAppUi
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!  * \brief Handles commands produced by the S60 framework.  *  * \a command holds the ID of the command to handle, and is S60 specific.  *  * If you override this function, you should call the base class implementation if you do not  * handle the command.  */
end_comment
begin_function
DECL|function|HandleCommandL
name|void
name|QS60MainAppUi
operator|::
name|HandleCommandL
parameter_list|(
name|TInt
name|command
parameter_list|)
block|{
if|if
condition|(
name|qApp
condition|)
block|{
name|QSymbianEvent
name|event
argument_list|(
name|QSymbianEvent
operator|::
name|CommandEvent
argument_list|,
name|command
argument_list|)
decl_stmt|;
name|QT_TRYCATCH_LEAVING
argument_list|(
name|qApp
operator|->
name|symbianProcessEvent
argument_list|(
operator|&
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!  * \brief Handles a resource change in the S60 framework.  *  * Resource changes include layout switches. \a type holds the type of resource change that  * occurred.  *  * If you override this function, you should call the base class implementation if you do not  * handle the resource change.  */
end_comment
begin_function
DECL|function|HandleResourceChangeL
name|void
name|QS60MainAppUi
operator|::
name|HandleResourceChangeL
parameter_list|(
name|TInt
name|type
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|HandleResourceChangeL
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|qApp
condition|)
block|{
name|QSymbianEvent
name|event
argument_list|(
name|QSymbianEvent
operator|::
name|ResourceChangeEvent
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QT_TRYCATCH_LEAVING
argument_list|(
name|qApp
operator|->
name|symbianProcessEvent
argument_list|(
operator|&
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!  * \brief Handles raw window server events.  *  * The event type and information is passed in \a wsEvent, while the receiving control is passed in  * \a destination.  *  * If you override this function, you should call the base class implementation if you do not  * handle the event.  */
end_comment
begin_function
DECL|function|HandleWsEventL
name|void
name|QS60MainAppUi
operator|::
name|HandleWsEventL
parameter_list|(
specifier|const
name|TWsEvent
modifier|&
name|wsEvent
parameter_list|,
name|CCoeControl
modifier|*
name|destination
parameter_list|)
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|qApp
condition|)
block|{
name|QSymbianEvent
name|event
argument_list|(
operator|&
name|wsEvent
argument_list|)
decl_stmt|;
name|QT_TRYCATCH_LEAVING
argument_list|(
name|result
operator|=
name|qApp
operator|->
name|symbianProcessEvent
argument_list|(
operator|&
name|event
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|result
operator|<=
literal|0
condition|)
name|QS60MainAppUiBase
operator|::
name|HandleWsEventL
argument_list|(
name|wsEvent
argument_list|,
name|destination
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \brief Handles changes to the status pane size.  *  * Called by the framework when the application status pane size is changed.  *  * If you override this function, you should call the base class implementation if you do not  * handle the size change.  */
end_comment
begin_function
DECL|function|HandleStatusPaneSizeChange
name|void
name|QS60MainAppUi
operator|::
name|HandleStatusPaneSizeChange
parameter_list|()
block|{
name|TRAP_IGNORE
argument_list|(
name|HandleResourceChangeL
argument_list|(
name|KInternalStatusPaneChange
argument_list|)
argument_list|)
expr_stmt|;
name|HandleStackedControlsResourceChange
argument_list|(
name|KInternalStatusPaneChange
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!  * \brief Dynamically initializes a menu bar.  *  * The resource associated with the menu is given in \a resourceId, and the actual menu bar is  * passed in \a menuBar.  *  * If you override this function, you should call the base class implementation as well.  */
end_comment
begin_function
DECL|function|DynInitMenuBarL
name|void
name|QS60MainAppUi
operator|::
name|DynInitMenuBarL
parameter_list|(
name|TInt
comment|/* resourceId */
parameter_list|,
name|CEikMenuBar
modifier|*
comment|/* menuBar */
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!  * \brief Dynamically initializes a menu pane.  *  * The resource associated with the menu is given in \a resourceId, and the actual menu pane is  * passed in \a menuPane.  *  * If you override this function, you should call the base class implementation as well.  */
end_comment
begin_function
DECL|function|DynInitMenuPaneL
name|void
name|QS60MainAppUi
operator|::
name|DynInitMenuPaneL
parameter_list|(
name|TInt
name|resourceId
parameter_list|,
name|CEikMenuPane
modifier|*
name|menuPane
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_S60
if|if
condition|(
name|resourceId
operator|==
name|R_AVKON_MENUPANE_EMPTY
condition|)
block|{
if|if
condition|(
name|menuPane
operator|->
name|NumberOfItemsInPane
argument_list|()
operator|<=
literal|1
condition|)
name|QT_TRYCATCH_LEAVING
argument_list|(
name|qt_symbian_show_toplevel
argument_list|(
name|menuPane
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|resourceId
operator|!=
name|R_AVKON_MENUPANE_FEP_DEFAULT
operator|&&
name|resourceId
operator|!=
name|R_AVKON_MENUPANE_EDITTEXT_DEFAULT
operator|&&
name|resourceId
operator|!=
name|R_AVKON_MENUPANE_LANGUAGE_DEFAULT
condition|)
block|{
name|QT_TRYCATCH_LEAVING
argument_list|(
name|qt_symbian_show_submenu
argument_list|(
name|menuPane
argument_list|,
name|resourceId
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|QS60MainAppUiBase
operator|::
name|DynInitMenuPaneL
argument_list|(
name|resourceId
argument_list|,
name|menuPane
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!  * \brief Restores a menu window.  *  * The menu window to restore is given in \a menuWindow. The resource ID and type of menu is given  * in \a resourceId and \a menuType, respectively.  *  * If you override this function, you should call the base class implementation as well.  */
end_comment
begin_function
DECL|function|RestoreMenuL
name|void
name|QS60MainAppUi
operator|::
name|RestoreMenuL
parameter_list|(
name|CCoeControl
modifier|*
name|menuWindow
parameter_list|,
name|TInt
name|resourceId
parameter_list|,
name|TMenuType
name|menuType
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_S60
if|if
condition|(
name|resourceId
operator|>=
name|QT_SYMBIAN_FIRST_MENU_ITEM
operator|&&
name|resourceId
operator|<=
name|QT_SYMBIAN_LAST_MENU_ITEM
condition|)
block|{
if|if
condition|(
name|menuType
operator|==
name|EMenuPane
condition|)
name|DynInitMenuPaneL
argument_list|(
name|resourceId
argument_list|,
operator|(
name|CEikMenuPane
operator|*
operator|)
name|menuWindow
argument_list|)
expr_stmt|;
else|else
name|DynInitMenuBarL
argument_list|(
name|resourceId
argument_list|,
operator|(
name|CEikMenuBar
operator|*
operator|)
name|menuWindow
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|resourceId
operator|==
name|R_AVKON_MENUPANE_EMPTY
condition|)
block|{
name|CEikMenuBarTitle
modifier|*
name|title
init|=
operator|new
operator|(
name|ELeave
operator|)
name|CEikMenuBarTitle
decl_stmt|;
name|CleanupStack
operator|::
name|PushL
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|title
operator|->
name|iData
operator|.
name|iMenuPaneResourceId
operator|=
name|R_AVKON_MENUPANE_EMPTY
expr_stmt|;
name|title
operator|->
name|iTitleFlags
operator|=
literal|0
expr_stmt|;
name|S60
operator|->
name|menuBar
argument_list|()
operator|->
name|TitleArray
argument_list|()
operator|->
name|AddTitleL
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|CleanupStack
operator|::
name|Pop
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|QS60MainAppUiBase
operator|::
name|RestoreMenuL
argument_list|(
name|menuWindow
argument_list|,
name|resourceId
argument_list|,
name|menuType
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|Exit
name|void
name|QS60MainAppUi
operator|::
name|Exit
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|Exit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|SetFadedL
name|void
name|QS60MainAppUi
operator|::
name|SetFadedL
parameter_list|(
name|TBool
name|aFaded
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|SetFadedL
argument_list|(
name|aFaded
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|ApplicationRect
name|TRect
name|QS60MainAppUi
operator|::
name|ApplicationRect
parameter_list|()
specifier|const
block|{
return|return
name|QS60MainAppUiBase
operator|::
name|ApplicationRect
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleScreenDeviceChangedL
name|void
name|QS60MainAppUi
operator|::
name|HandleScreenDeviceChangedL
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|HandleScreenDeviceChangedL
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleApplicationSpecificEventL
name|void
name|QS60MainAppUi
operator|::
name|HandleApplicationSpecificEventL
parameter_list|(
name|TInt
name|aType
parameter_list|,
specifier|const
name|TWsEvent
modifier|&
name|aEvent
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|HandleApplicationSpecificEventL
argument_list|(
name|aType
argument_list|,
name|aEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|MopSupplyObject
name|TTypeUid
operator|::
name|Ptr
name|QS60MainAppUi
operator|::
name|MopSupplyObject
parameter_list|(
name|TTypeUid
name|aId
parameter_list|)
block|{
return|return
name|QS60MainAppUiBase
operator|::
name|MopSupplyObject
argument_list|(
name|aId
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|ProcessCommandL
name|void
name|QS60MainAppUi
operator|::
name|ProcessCommandL
parameter_list|(
name|TInt
name|aCommand
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|ProcessCommandL
argument_list|(
name|aCommand
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleError
name|TErrorHandlerResponse
name|QS60MainAppUi
operator|::
name|HandleError
parameter_list|(
name|TInt
name|aError
parameter_list|,
specifier|const
name|SExtendedError
modifier|&
name|aExtErr
parameter_list|,
name|TDes
modifier|&
name|aErrorText
parameter_list|,
name|TDes
modifier|&
name|aContextText
parameter_list|)
block|{
return|return
name|QS60MainAppUiBase
operator|::
name|HandleError
argument_list|(
name|aError
argument_list|,
name|aExtErr
argument_list|,
name|aErrorText
argument_list|,
name|aContextText
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleViewDeactivation
name|void
name|QS60MainAppUi
operator|::
name|HandleViewDeactivation
parameter_list|(
specifier|const
name|TVwsViewId
modifier|&
name|aViewIdToBeDeactivated
parameter_list|,
specifier|const
name|TVwsViewId
modifier|&
name|aNewlyActivatedViewId
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|HandleViewDeactivation
argument_list|(
name|aViewIdToBeDeactivated
argument_list|,
name|aNewlyActivatedViewId
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|PrepareToExit
name|void
name|QS60MainAppUi
operator|::
name|PrepareToExit
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|PrepareToExit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleTouchPaneSizeChange
name|void
name|QS60MainAppUi
operator|::
name|HandleTouchPaneSizeChange
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|HandleTouchPaneSizeChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleSystemEventL
name|void
name|QS60MainAppUi
operator|::
name|HandleSystemEventL
parameter_list|(
specifier|const
name|TWsEvent
modifier|&
name|aEvent
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|HandleSystemEventL
argument_list|(
name|aEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|Reserved_MtsmPosition
name|void
name|QS60MainAppUi
operator|::
name|Reserved_MtsmPosition
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|Reserved_MtsmPosition
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|Reserved_MtsmObject
name|void
name|QS60MainAppUi
operator|::
name|Reserved_MtsmObject
parameter_list|()
block|{
name|QS60MainAppUiBase
operator|::
name|Reserved_MtsmObject
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|HandleForegroundEventL
name|void
name|QS60MainAppUi
operator|::
name|HandleForegroundEventL
parameter_list|(
name|TBool
name|aForeground
parameter_list|)
block|{
name|QS60MainAppUiBase
operator|::
name|HandleForegroundEventL
argument_list|(
name|aForeground
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|ProcessCommandParametersL
name|TBool
name|QS60MainAppUi
operator|::
name|ProcessCommandParametersL
parameter_list|(
name|TApaCommand
comment|/*aCommand*/
parameter_list|,
name|TFileName
modifier|&
comment|/*aDocumentName*/
parameter_list|,
specifier|const
name|TDesC8
modifier|&
comment|/*aTail*/
parameter_list|)
block|{
comment|// bypass CEikAppUi::ProcessCommandParametersL(..) which modifies aDocumentName, preventing apparc document opening from working.
comment|// The return value is effectively unused in Qt apps (see QS60MainDocument::OpenFileL)
return|return
name|EFalse
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_WS_S60
end_ifndef
begin_function
DECL|function|HandleViewDeactivation
name|void
name|QS60StubAknAppUi
operator|::
name|HandleViewDeactivation
parameter_list|(
specifier|const
name|TVwsViewId
modifier|&
parameter_list|,
specifier|const
name|TVwsViewId
modifier|&
parameter_list|)
block|{}
end_function
begin_function
DECL|function|HandleTouchPaneSizeChange
name|void
name|QS60StubAknAppUi
operator|::
name|HandleTouchPaneSizeChange
parameter_list|()
block|{}
end_function
begin_function
DECL|function|HandleStatusPaneSizeChange
name|void
name|QS60StubAknAppUi
operator|::
name|HandleStatusPaneSizeChange
parameter_list|()
block|{}
end_function
begin_function
DECL|function|Reserved_MtsmPosition
name|void
name|QS60StubAknAppUi
operator|::
name|Reserved_MtsmPosition
parameter_list|()
block|{}
end_function
begin_function
DECL|function|Reserved_MtsmObject
name|void
name|QS60StubAknAppUi
operator|::
name|Reserved_MtsmObject
parameter_list|()
block|{}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
