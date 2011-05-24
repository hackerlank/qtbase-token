begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|MAINWINDOW_H
end_ifndef
begin_define
DECL|macro|MAINWINDOW_H
define|#
directive|define
name|MAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QMainWindow>
end_include
begin_decl_stmt
DECL|variable|XQVibra
name|class
name|XQVibra
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|MainWindow
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|MainWindow
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|vibrate
argument_list|()
block|;
name|private
operator|:
name|XQVibra
operator|*
name|vibra
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MAINWINDOW_H
end_comment
end_unit
