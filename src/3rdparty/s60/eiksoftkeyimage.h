begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EIKSOFTKEYIMAGE_H
end_ifndef
begin_define
DECL|macro|EIKSOFTKEYIMAGE_H
define|#
directive|define
name|EIKSOFTKEYIMAGE_H
end_define
begin_comment
comment|// FORWARD DECLARATIONS
end_comment
begin_decl_stmt
DECL|variable|CEikButtonGroupContainer
name|class
name|CEikButtonGroupContainer
decl_stmt|;
end_decl_stmt
begin_comment
comment|// CLASS DECLARATION
end_comment
begin_comment
comment|/** *  Changes cba button's label to image. * *  @lib EIKCOCTL *  @since 2.0 */
end_comment
begin_decl_stmt
name|class
name|EikSoftkeyImage
block|{
name|public
label|:
comment|/**         * Set image to cba button by replacing label         * @since 2.0         * @param aButtonGroupContainer Button container         * @param aImage Image to button,         *               Takes Images ownership         * @param aLeft  Boolean: left or right button.         *                        If true, then change left,         *                        if false, change right         */
name|IMPORT_C
specifier|static
name|void
name|SetImage
parameter_list|(
name|CEikButtonGroupContainer
modifier|*
name|aButtonGroupContainer
parameter_list|,
name|CEikImage
modifier|&
name|aImage
parameter_list|,
name|TBool
name|aLeft
parameter_list|)
function_decl|;
comment|/**         * Change to cba button image back to label         * @since 2.0         * @param aButtonGroupContainer Button container         * @param aLeft Boolean: left or right button.         *                        If true, then change left,         *                        if false, change right         */
name|IMPORT_C
specifier|static
name|void
name|SetLabel
parameter_list|(
name|CEikButtonGroupContainer
modifier|*
name|aButtonGroupContainer
parameter_list|,
name|TBool
name|aLeft
parameter_list|)
function_decl|;
name|private
label|:
comment|/**         * C++ default constructor.         */
name|EikSoftkeyImage
argument_list|()
block|{}
empty_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// EIKSOFTKEYIMAGE_H
end_comment
begin_comment
comment|// End of File
end_comment
end_unit
