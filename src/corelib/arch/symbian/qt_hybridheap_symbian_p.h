begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_HYBRIDHEAP_SYMBIAN_H
end_ifndef
begin_define
DECL|macro|QT_HYBRIDHEAP_SYMBIAN_H
define|#
directive|define
name|QT_HYBRIDHEAP_SYMBIAN_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<e32cmn.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SYMBIAN_KERNEL_HYBRID_HEAP__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__WINS__
argument_list|)
end_if
begin_comment
comment|//Enable the (backported) new allocator. When it is available in OS,
end_comment
begin_comment
comment|//this flag should be disabled for that OS version onward
end_comment
begin_define
DECL|macro|QT_USE_NEW_SYMBIAN_ALLOCATOR
define|#
directive|define
name|QT_USE_NEW_SYMBIAN_ALLOCATOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_NEW_SYMBIAN_ALLOCATOR
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_RVCT
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|push
end_pragma
begin_pragma
pragma|#
directive|pragma
name|arm
end_pragma
begin_pragma
pragma|#
directive|pragma
name|Otime
end_pragma
begin_pragma
pragma|#
directive|pragma
name|O2
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"common_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_SYMBIAN_HAVE_U32STD_H
end_ifdef
begin_include
include|#
directive|include
file|<u32std.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_SYMBIAN_HAVE_E32BTRACE_H
end_ifdef
begin_include
include|#
directive|include
file|<e32btrace.h>
end_include
begin_comment
comment|// enables btrace code compiling into
end_comment
begin_define
DECL|macro|ENABLE_BTRACE
define|#
directive|define
name|ENABLE_BTRACE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL_MODE__
end_ifdef
begin_include
include|#
directive|include
file|<kernel/kern_priv.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"dla_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL_MODE__
end_ifndef
begin_include
include|#
directive|include
file|"slab_p.h"
end_include
begin_include
include|#
directive|include
file|"page_alloc_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"heap_hybrid_p.h"
end_include
begin_comment
comment|// disabling Symbian import/export macros to prevent heap_hybrid.cpp, copied from Symbian^4, from exporting symbols in arm builds
end_comment
begin_comment
comment|// this minimises the code changes to heap_hybrid.cpp to ease future integration
end_comment
begin_undef
DECL|macro|UEXPORT_C
undef|#
directive|undef
name|UEXPORT_C
end_undef
begin_define
DECL|macro|UEXPORT_C
define|#
directive|define
name|UEXPORT_C
end_define
begin_undef
DECL|macro|EXPORT_C
undef|#
directive|undef
name|EXPORT_C
end_undef
begin_define
DECL|macro|EXPORT_C
define|#
directive|define
name|EXPORT_C
end_define
begin_undef
DECL|macro|IMPORT_D
undef|#
directive|undef
name|IMPORT_D
end_undef
begin_define
DECL|macro|IMPORT_D
define|#
directive|define
name|IMPORT_D
end_define
begin_comment
comment|// disabling code ported from Symbian^4 that we don't want/can't have in earlier platforms
end_comment
begin_define
DECL|macro|QT_SYMBIAN4_ALLOCATOR_UNWANTED_CODE
define|#
directive|define
name|QT_SYMBIAN4_ALLOCATOR_UNWANTED_CODE
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYMBIAN_VERSION_9_1
argument_list|)
operator|||
name|defined
argument_list|(
name|SYMBIAN_VERSION_9_2
argument_list|)
operator|||
name|defined
argument_list|(
name|SYMBIAN_VERSION_9_3
argument_list|)
operator|||
name|defined
argument_list|(
name|SYMBIAN_VERSION_9_4
argument_list|)
operator|||
name|defined
argument_list|(
name|SYMBIAN_VERSION_SYMBIAN2
argument_list|)
end_if
begin_define
DECL|macro|NO_NAMED_LOCAL_CHUNKS
define|#
directive|define
name|NO_NAMED_LOCAL_CHUNKS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// disabling the BTrace components of heap checking macros
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ENABLE_BTRACE
end_ifndef
begin_function
DECL|function|noBTrace
specifier|inline
name|int
name|noBTrace
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_define
DECL|macro|BTraceContext12
define|#
directive|define
name|BTraceContext12
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|noBTrace()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// declare ETHeapBadDebugFailParameter, where missing
end_comment
begin_define
DECL|macro|ETHeapBadDebugFailParameter
define|#
directive|define
name|ETHeapBadDebugFailParameter
value|((TCdtPanic)213)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_SYMBIAN_HAVE_U32STD_H
end_ifndef
begin_struct
DECL|struct|SThreadCreateInfo
struct|struct
name|SThreadCreateInfo
block|{
DECL|member|iHandle
name|TAny
modifier|*
name|iHandle
decl_stmt|;
DECL|member|iType
name|TInt
name|iType
decl_stmt|;
DECL|member|iFunction
name|TThreadFunction
name|iFunction
decl_stmt|;
DECL|member|iPtr
name|TAny
modifier|*
name|iPtr
decl_stmt|;
DECL|member|iSupervisorStack
name|TAny
modifier|*
name|iSupervisorStack
decl_stmt|;
DECL|member|iSupervisorStackSize
name|TInt
name|iSupervisorStackSize
decl_stmt|;
DECL|member|iUserStack
name|TAny
modifier|*
name|iUserStack
decl_stmt|;
DECL|member|iUserStackSize
name|TInt
name|iUserStackSize
decl_stmt|;
DECL|member|iInitialThreadPriority
name|TInt
name|iInitialThreadPriority
decl_stmt|;
DECL|member|iName
name|TPtrC
name|iName
decl_stmt|;
DECL|member|iTotalSize
name|TInt
name|iTotalSize
decl_stmt|;
comment|// Size including any extras (must be a multiple of 8 bytes)
block|}
struct|;
end_struct
begin_decl_stmt
DECL|struct|SThreadCreateInfo
name|struct
name|SStdEpocThreadCreateInfo
range|:
name|public
name|SThreadCreateInfo
block|{
DECL|member|iAllocator
name|RAllocator
operator|*
name|iAllocator
block|;
DECL|member|iHeapInitialSize
name|TInt
name|iHeapInitialSize
block|;
DECL|member|iHeapMaxSize
name|TInt
name|iHeapMaxSize
block|;
DECL|member|iPadding
name|TInt
name|iPadding
block|;
comment|// Make structure size a multiple of 8 bytes
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TChunkCreate
block|{
name|public
label|:
comment|// Attributes for chunk creation that are used by both euser and the kernel
comment|// by classes TChunkCreateInfo and SChunkCreateInfo, respectively.
enum|enum
name|TChunkCreateAtt
block|{
name|ENormal
init|=
literal|0x00000000
block|,
name|EDoubleEnded
init|=
literal|0x00000001
block|,
name|EDisconnected
init|=
literal|0x00000002
block|,
name|ECache
init|=
literal|0x00000003
block|,
name|EMappingMask
init|=
literal|0x0000000f
block|,
name|ELocal
init|=
literal|0x00000000
block|,
name|EGlobal
init|=
literal|0x00000010
block|,
name|EData
init|=
literal|0x00000000
block|,
name|ECode
init|=
literal|0x00000020
block|,
name|EMemoryNotOwned
init|=
literal|0x00000040
block|,
comment|// Force local chunk to be named.  Only required for thread heap
comment|// chunks, all other local chunks should be nameless.
name|ELocalNamed
init|=
literal|0x000000080
block|,
comment|// Make global chunk read only to all processes but the controlling owner
name|EReadOnly
init|=
literal|0x000000100
block|,
comment|// Paging attributes for chunks.
name|EPagingUnspec
init|=
literal|0x00000000
block|,
name|EPaged
init|=
literal|0x80000000
block|,
name|EUnpaged
init|=
literal|0x40000000
block|,
name|EPagingMask
init|=
name|EPaged
operator||
name|EUnpaged
block|,
name|EChunkCreateAttMask
init|=
name|EMappingMask
operator||
name|EGlobal
operator||
name|ECode
operator||
name|ELocalNamed
operator||
name|EReadOnly
operator||
name|EPagingMask
block|, 		}
enum|;
name|public
label|:
name|TUint
name|iAtt
decl_stmt|;
name|TBool
name|iForceFixed
decl_stmt|;
name|TInt
name|iInitialBottom
decl_stmt|;
name|TInt
name|iInitialTop
decl_stmt|;
name|TInt
name|iMaxSize
decl_stmt|;
name|TUint8
name|iClearByte
decl_stmt|;
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
comment|// QT_SYMBIAN_HAVE_U32STD_H
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* QT_USE_NEW_SYMBIAN_ALLOCATOR */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* QT_HYBRIDHEAP_SYMBIAN_H */
end_comment
end_unit
