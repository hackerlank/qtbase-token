begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformbackingstore.h"
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<private/qwindow_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPlatformBackingStorePrivate
class|class
name|QPlatformBackingStorePrivate
block|{
public|public:
DECL|function|QPlatformBackingStorePrivate
name|QPlatformBackingStorePrivate
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|window
argument_list|(
name|w
argument_list|)
block|{     }
DECL|member|window
name|QWindow
modifier|*
name|window
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QPlatformBackingStore     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformBackingStore class provides the drawing area for top-level     windows. */
end_comment
begin_comment
comment|/*!     \fn void QPlatformBackingStore::flush(QWindow *window, const QRegion&region,                                   const QPoint&offset)      Flushes the given \a region from the specified \a window onto the     screen.      Note that the \a offset parameter is currently unused. */
end_comment
begin_comment
comment|/*!     \fn QPaintDevice* QPlatformBackingStore::paintDevice()      Implement this function to return the appropriate paint device. */
end_comment
begin_comment
comment|/*!     Constructs an empty surface for the given top-level \a window. */
end_comment
begin_constructor
DECL|function|QPlatformBackingStore
name|QPlatformBackingStore
operator|::
name|QPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformBackingStorePrivate
argument_list|(
name|window
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this surface. */
end_comment
begin_destructor
DECL|function|~QPlatformBackingStore
name|QPlatformBackingStore
operator|::
name|~
name|QPlatformBackingStore
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns a pointer to the top-level window associated with this     surface. */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QPlatformBackingStore
operator|::
name|window
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|window
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called before painting onto the surface begins,     with the \a region in which the painting will occur.      \sa endPaint(), paintDevice() */
end_comment
begin_function
DECL|function|beginPaint
name|void
name|QPlatformBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!     This function is called after painting onto the surface has ended.      \sa beginPaint(), paintDevice() */
end_comment
begin_function
DECL|function|endPaint
name|void
name|QPlatformBackingStore
operator|::
name|endPaint
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Scrolls the given \a area \a dx pixels to the right and \a dy     downward; both \a dx and \a dy may be negative.      Returns true if the area was scrolled successfully; false otherwise. */
end_comment
begin_function
DECL|function|scroll
name|bool
name|QPlatformBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|area
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dy
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
