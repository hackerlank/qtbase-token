begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QT_BEGIN_HEADER
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
name|Q_ENUMS
argument_list|(
argument|ColorDialogOption
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
literal|0
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
literal|0
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
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
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
block|;
specifier|static
name|QColor
name|getColor
argument_list|(
argument|const QColor&initial = Qt::white
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|const QString&title = QString()
argument_list|,
argument|ColorDialogOptions options =
literal|0
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
argument|bool *ok =
literal|0
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
comment|// ### Qt 5: use QColor in signatures
specifier|static
name|int
name|customCount
argument_list|()
block|;
specifier|static
name|QRgb
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
argument|QRgb color
argument_list|)
block|;
specifier|static
name|void
name|setStandardColor
argument_list|(
argument|int index
argument_list|,
argument|QRgb color
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
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|done
argument_list|(
argument|int result
argument_list|)
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
argument|void _q_platformRunNativeAppModalPanel()
argument_list|)
name|friend
name|class
name|QColorShower
block|; }
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLORDIALOG_H
end_comment
end_unit
