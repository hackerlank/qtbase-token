begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLORDIALOG_H
end_ifndef
begin_define
DECL|macro|QCOLORDIALOG_H
define|#
directive|define
name|QCOLORDIALOG_H
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
name|QT_NO_COLORDIALOG
DECL|variable|QColorDialogPrivate
name|class
name|QColorDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QColorDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QColorDialog
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QColor currentColor READ currentColor WRITE setCurrentColor                NOTIFY currentColorChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ColorDialogOptions options READ options WRITE setOptions
argument_list|)
name|public
operator|:
expr|enum
name|ColorDialogOption
block|{
name|ShowAlphaChannel
operator|=
literal|0x00000001
block|,
name|NoButtons
operator|=
literal|0x00000002
block|,
name|DontUseNativeDialog
operator|=
literal|0x00000004
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ColorDialogOption
argument_list|)
name|Q_DECLARE_FLAGS
argument_list|(
argument|ColorDialogOptions
argument_list|,
argument|ColorDialogOption
argument_list|)
name|explicit
name|QColorDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QColorDialog
argument_list|(
specifier|const
name|QColor
operator|&
name|initial
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QColorDialog
argument_list|()
block|;
name|void
name|setCurrentColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|QColor
name|currentColor
argument_list|()
specifier|const
block|;
name|QColor
name|selectedColor
argument_list|()
specifier|const
block|;
name|void
name|setOption
argument_list|(
argument|ColorDialogOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|ColorDialogOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|ColorDialogOptions options
argument_list|)
block|;
name|ColorDialogOptions
name|options
argument_list|()
specifier|const
block|;
name|using
name|QDialog
operator|::
name|open
block|;
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|QColor
name|getColor
argument_list|(
argument|const QColor&initial = Qt::white
argument_list|,
argument|QWidget *parent = Q_NULLPTR
argument_list|,
argument|const QString&title = QString()
argument_list|,
argument|ColorDialogOptions options = ColorDialogOptions()
argument_list|)
block|;
comment|// obsolete
specifier|static
name|QRgb
name|getRgba
argument_list|(
argument|QRgb rgba =
literal|0xffffffff
argument_list|,
argument|bool *ok = Q_NULLPTR
argument_list|,
argument|QWidget *parent = Q_NULLPTR
argument_list|)
block|;
specifier|static
name|int
name|customCount
argument_list|()
block|;
specifier|static
name|QColor
name|customColor
argument_list|(
argument|int index
argument_list|)
block|;
specifier|static
name|void
name|setCustomColor
argument_list|(
argument|int index
argument_list|,
argument|QColor color
argument_list|)
block|;
specifier|static
name|QColor
name|standardColor
argument_list|(
argument|int index
argument_list|)
block|;
specifier|static
name|void
name|setStandardColor
argument_list|(
argument|int index
argument_list|,
argument|QColor color
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentColorChanged
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|colorSelected
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|done
argument_list|(
argument|int result
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QColorDialog
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_addCustom()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_newHsv(int h, int s, int v)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_newColorTypedIn(QRgb rgb)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_nextCustom(int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_newCustom(int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_newStandard(int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_pickScreenColor()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateColorPicking()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QColorDialog::ColorDialogOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COLORDIALOG
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLORDIALOG_H
end_comment
end_unit
