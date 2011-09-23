begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpdfwriter.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|"private/qpdf_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPdfWriterPrivate
class|class
name|QPdfWriterPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QPdfWriterPrivate
name|QPdfWriterPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
block|{
name|engine
operator|=
operator|new
name|QPdfEngine
argument_list|()
expr_stmt|;
name|output
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|~QPdfWriterPrivate
name|~
name|QPdfWriterPrivate
parameter_list|()
block|{
operator|delete
name|engine
expr_stmt|;
operator|delete
name|output
expr_stmt|;
block|}
DECL|member|engine
name|QPdfEngine
modifier|*
name|engine
decl_stmt|;
DECL|member|output
name|QFile
modifier|*
name|output
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*! \class QPdfWriter      \brief The QPdfWriter class is a class to generate PDFs     that can be used as a paint device.      \ingroup painting      QPdfWriter generates PDF out of a series of drawing commands using QPainter.     The newPage() method can be used to create several pages.   */
end_comment
begin_comment
comment|/*!   Constructs a PDF writer that will write the pdf to \a filename.   */
end_comment
begin_constructor
DECL|function|QPdfWriter
name|QPdfWriter
operator|::
name|QPdfWriter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QPdfWriterPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|setOutputFilename
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Constructs a PDF writer that will write the pdf to \a device.   */
end_comment
begin_constructor
DECL|function|QPdfWriter
name|QPdfWriter
operator|::
name|QPdfWriter
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QPdfWriterPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|outDevice
operator|=
name|device
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys the pdf writer.   */
end_comment
begin_destructor
DECL|function|~QPdfWriter
name|QPdfWriter
operator|::
name|~
name|QPdfWriter
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!   Returns the title of the document.   */
end_comment
begin_function
DECL|function|title
name|QString
name|QPdfWriter
operator|::
name|title
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|title
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the title of the document being created.   */
end_comment
begin_function
DECL|function|setTitle
name|void
name|QPdfWriter
operator|::
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|title
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the creator of the document.   */
end_comment
begin_function
DECL|function|creator
name|QString
name|QPdfWriter
operator|::
name|creator
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|creator
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the creator of the document.   */
end_comment
begin_function
DECL|function|setCreator
name|void
name|QPdfWriter
operator|::
name|setCreator
parameter_list|(
specifier|const
name|QString
modifier|&
name|creator
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|creator
operator|=
name|creator
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp   */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QPdfWriter
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp   */
end_comment
begin_function
DECL|function|setPageSize
name|void
name|QPdfWriter
operator|::
name|setPageSize
parameter_list|(
name|PageSize
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
name|QPagedPaintDevice
operator|::
name|setPageSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|paperSize
operator|=
name|pageSizeMM
argument_list|()
operator|*
literal|25.4
operator|/
literal|72.
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp   */
end_comment
begin_function
DECL|function|setPageSizeMM
name|void
name|QPdfWriter
operator|::
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
name|QPagedPaintDevice
operator|::
name|setPageSizeMM
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|paperSize
operator|=
name|pageSizeMM
argument_list|()
operator|*
literal|25.4
operator|/
literal|72.
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the metric for the given \a id. */
end_comment
begin_function
DECL|function|metric
name|int
name|QPdfWriter
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|id
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|metric
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|newPage
name|bool
name|QPdfWriter
operator|::
name|newPage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|newPage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp   */
end_comment
begin_function
DECL|function|setMargins
name|void
name|QPdfWriter
operator|::
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|m
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|multiplier
init|=
literal|72.
operator|/
literal|25.4
decl_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|leftMargin
operator|=
name|m
operator|.
name|left
operator|*
name|multiplier
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|rightMargin
operator|=
name|m
operator|.
name|right
operator|*
name|multiplier
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|topMargin
operator|=
name|m
operator|.
name|top
operator|*
name|multiplier
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|bottomMargin
operator|=
name|m
operator|.
name|bottom
operator|*
name|multiplier
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
