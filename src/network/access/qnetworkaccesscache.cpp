begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccesscache_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qqueue.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkaccessmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkreply_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkrequest.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|ExpiryTimeEnum
name|enum
name|ExpiryTimeEnum
argument_list|{
DECL|enumerator|ExpiryTime
name|ExpiryTime
operator|=
literal|120
argument_list|}
decl_stmt|;
end_decl_stmt
begin_namespace
namespace|namespace
block|{
DECL|struct|Receiver
struct|struct
name|Receiver
block|{
DECL|member|object
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|object
decl_stmt|;
DECL|member|member
specifier|const
name|char
modifier|*
name|member
decl_stmt|;
block|}
struct|;
block|}
end_namespace
begin_comment
comment|// idea copied from qcache.h
end_comment
begin_struct
DECL|struct|Node
struct|struct
name|QNetworkAccessCache
operator|::
name|Node
block|{
DECL|member|timestamp
name|QDateTime
name|timestamp
decl_stmt|;
DECL|member|receiverQueue
name|QQueue
argument_list|<
name|Receiver
argument_list|>
name|receiverQueue
decl_stmt|;
DECL|member|key
name|QByteArray
name|key
decl_stmt|;
DECL|member|older
DECL|member|newer
name|Node
modifier|*
name|older
decl_stmt|,
modifier|*
name|newer
decl_stmt|;
DECL|member|object
name|CacheableObject
modifier|*
name|object
decl_stmt|;
DECL|member|useCount
name|int
name|useCount
decl_stmt|;
DECL|function|Node
name|Node
parameter_list|()
member_init_list|:
name|older
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|newer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|object
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|useCount
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
struct|;
end_struct
begin_constructor
DECL|function|CacheableObject
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|::
name|CacheableObject
parameter_list|()
block|{
comment|// leave the members uninitialized
comment|// they must be initialized by the derived class's constructor
block|}
end_constructor
begin_destructor
DECL|function|~CacheableObject
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|::
name|~
name|CacheableObject
parameter_list|()
block|{
if|#
directive|if
literal|0
comment|//def QT_DEBUG
block|if (!key.isEmpty()&& Ptr()->hasEntry(key))         qWarning()<< "QNetworkAccessCache: object"<< (void*)this<< "key"<< key<< "destroyed without being removed from cache first!";
endif|#
directive|endif
block|}
end_destructor
begin_function
DECL|function|setExpires
name|void
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|::
name|setExpires
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|expires
operator|=
name|enable
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setShareable
name|void
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|::
name|setShareable
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|shareable
operator|=
name|enable
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QNetworkAccessCache
name|QNetworkAccessCache
operator|::
name|QNetworkAccessCache
parameter_list|()
member_init_list|:
name|oldest
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|newest
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkAccessCache
name|QNetworkAccessCache
operator|::
name|~
name|QNetworkAccessCache
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|clear
name|void
name|QNetworkAccessCache
operator|::
name|clear
parameter_list|()
block|{
name|NodeHash
name|hashCopy
init|=
name|hash
decl_stmt|;
name|hash
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// remove all entries
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hashCopy
operator|.
name|begin
argument_list|()
decl_stmt|;
name|NodeHash
operator|::
name|Iterator
name|end
init|=
name|hashCopy
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|it
operator|->
name|object
operator|->
name|key
operator|.
name|clear
argument_list|()
expr_stmt|;
name|it
operator|->
name|object
operator|->
name|dispose
argument_list|()
expr_stmt|;
block|}
comment|// now delete:
name|hashCopy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|oldest
operator|=
name|newest
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Appens the entry given by @p key to the end of the linked list.     (i.e., makes it the newest entry)  */
end_comment
begin_function
DECL|function|linkEntry
name|void
name|QNetworkAccessCache
operator|::
name|linkEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
return|return;
name|Node
modifier|*
specifier|const
name|node
init|=
operator|&
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|node
operator|!=
name|oldest
operator|&&
name|node
operator|!=
name|newest
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|node
operator|->
name|older
operator|==
literal|0
operator|&&
name|node
operator|->
name|newer
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|node
operator|->
name|useCount
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|newest
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|newest
operator|->
name|newer
operator|==
literal|0
argument_list|)
expr_stmt|;
name|newest
operator|->
name|newer
operator|=
name|node
expr_stmt|;
name|node
operator|->
name|older
operator|=
name|newest
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|oldest
condition|)
block|{
comment|// there are no entries, so this is the oldest one too
name|oldest
operator|=
name|node
expr_stmt|;
block|}
name|node
operator|->
name|timestamp
operator|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|addSecs
argument_list|(
name|ExpiryTime
argument_list|)
expr_stmt|;
name|newest
operator|=
name|node
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the entry pointed by @p key from the linked list.     Returns true if the entry removed was the oldest one.  */
end_comment
begin_function
DECL|function|unlinkEntry
name|bool
name|QNetworkAccessCache
operator|::
name|unlinkEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
return|return
literal|false
return|;
name|Node
modifier|*
specifier|const
name|node
init|=
operator|&
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|bool
name|wasOldest
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|node
operator|==
name|oldest
condition|)
block|{
name|oldest
operator|=
name|node
operator|->
name|newer
expr_stmt|;
name|wasOldest
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|node
operator|==
name|newest
condition|)
name|newest
operator|=
name|node
operator|->
name|older
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|older
condition|)
name|node
operator|->
name|older
operator|->
name|newer
operator|=
name|node
operator|->
name|newer
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|newer
condition|)
name|node
operator|->
name|newer
operator|->
name|older
operator|=
name|node
operator|->
name|older
expr_stmt|;
name|node
operator|->
name|newer
operator|=
name|node
operator|->
name|older
operator|=
literal|0
expr_stmt|;
return|return
name|wasOldest
return|;
block|}
end_function
begin_function
DECL|function|updateTimer
name|void
name|QNetworkAccessCache
operator|::
name|updateTimer
parameter_list|()
block|{
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|oldest
condition|)
return|return;
name|int
name|interval
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|secsTo
argument_list|(
name|oldest
operator|->
name|timestamp
argument_list|)
decl_stmt|;
if|if
condition|(
name|interval
operator|<=
literal|0
condition|)
block|{
name|interval
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|// round up the interval
name|interval
operator|=
operator|(
name|interval
operator|+
literal|15
operator|)
operator|&
operator|~
literal|16
expr_stmt|;
block|}
name|timer
operator|.
name|start
argument_list|(
name|interval
operator|*
literal|1000
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emitEntryReady
name|bool
name|QNetworkAccessCache
operator|::
name|emitEntryReady
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
if|if
condition|(
operator|!
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|entryReady
argument_list|(
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|target
argument_list|,
name|member
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
condition|)
return|return
literal|false
return|;
emit|emit
name|entryReady
argument_list|(
name|node
operator|->
name|object
argument_list|)
emit|;
name|disconnect
argument_list|(
name|SIGNAL
argument_list|(
name|entryReady
argument_list|(
name|QNetworkAccessCache
operator|::
name|CacheableObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|QNetworkAccessCache
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
comment|// expire old items
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
while|while
condition|(
name|oldest
operator|&&
name|oldest
operator|->
name|timestamp
operator|<
name|now
condition|)
block|{
name|Node
modifier|*
name|next
init|=
name|oldest
operator|->
name|newer
decl_stmt|;
name|oldest
operator|->
name|object
operator|->
name|dispose
argument_list|()
expr_stmt|;
name|hash
operator|.
name|remove
argument_list|(
name|oldest
operator|->
name|key
argument_list|)
expr_stmt|;
comment|// oldest gets deleted
name|oldest
operator|=
name|next
expr_stmt|;
block|}
comment|// fixup the list
if|if
condition|(
name|oldest
condition|)
name|oldest
operator|->
name|older
operator|=
literal|0
expr_stmt|;
else|else
name|newest
operator|=
literal|0
expr_stmt|;
name|updateTimer
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addEntry
name|void
name|QNetworkAccessCache
operator|::
name|addEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
name|CacheableObject
modifier|*
name|entry
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlinkEntry
argument_list|(
name|key
argument_list|)
condition|)
name|updateTimer
argument_list|()
expr_stmt|;
name|Node
modifier|&
name|node
init|=
name|hash
index|[
name|key
index|]
decl_stmt|;
comment|// create the entry in the hash if it didn't exist
if|if
condition|(
name|node
operator|.
name|useCount
condition|)
name|qWarning
argument_list|(
literal|"QNetworkAccessCache::addEntry: overriding active cache entry '%s'"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|.
name|object
condition|)
name|node
operator|.
name|object
operator|->
name|dispose
argument_list|()
expr_stmt|;
name|node
operator|.
name|object
operator|=
name|entry
expr_stmt|;
name|node
operator|.
name|object
operator|->
name|key
operator|=
name|key
expr_stmt|;
name|node
operator|.
name|key
operator|=
name|key
expr_stmt|;
name|node
operator|.
name|useCount
operator|=
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasEntry
name|bool
name|QNetworkAccessCache
operator|::
name|hasEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
specifier|const
block|{
return|return
name|hash
operator|.
name|contains
argument_list|(
name|key
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|requestEntry
name|bool
name|QNetworkAccessCache
operator|::
name|requestEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// no such entry
name|Node
modifier|*
name|node
init|=
operator|&
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|useCount
operator|>
literal|0
operator|&&
operator|!
name|node
operator|->
name|object
operator|->
name|shareable
condition|)
block|{
comment|// object is not shareable and is in use
comment|// queue for later use
name|Q_ASSERT
argument_list|(
name|node
operator|->
name|older
operator|==
literal|0
operator|&&
name|node
operator|->
name|newer
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Receiver
name|receiver
decl_stmt|;
name|receiver
operator|.
name|object
operator|=
name|target
expr_stmt|;
name|receiver
operator|.
name|member
operator|=
name|member
expr_stmt|;
name|node
operator|->
name|receiverQueue
operator|.
name|enqueue
argument_list|(
name|receiver
argument_list|)
expr_stmt|;
comment|// request queued
return|return
literal|true
return|;
block|}
else|else
block|{
comment|// node not in use or is shareable
if|if
condition|(
name|unlinkEntry
argument_list|(
name|key
argument_list|)
condition|)
name|updateTimer
argument_list|()
expr_stmt|;
operator|++
name|node
operator|->
name|useCount
expr_stmt|;
return|return
name|emitEntryReady
argument_list|(
name|node
argument_list|,
name|target
argument_list|,
name|member
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|requestEntryNow
name|QNetworkAccessCache
operator|::
name|CacheableObject
modifier|*
name|QNetworkAccessCache
operator|::
name|requestEntryNow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|it
operator|->
name|useCount
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|object
operator|->
name|shareable
condition|)
block|{
operator|++
name|it
operator|->
name|useCount
expr_stmt|;
return|return
name|it
operator|->
name|object
return|;
block|}
comment|// object in use and not shareable
return|return
literal|0
return|;
block|}
comment|// entry not in use, let the caller have it
name|bool
name|wasOldest
init|=
name|unlinkEntry
argument_list|(
name|key
argument_list|)
decl_stmt|;
operator|++
name|it
operator|->
name|useCount
expr_stmt|;
if|if
condition|(
name|wasOldest
condition|)
name|updateTimer
argument_list|()
expr_stmt|;
return|return
name|it
operator|->
name|object
return|;
block|}
end_function
begin_function
DECL|function|releaseEntry
name|void
name|QNetworkAccessCache
operator|::
name|releaseEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QNetworkAccessCache::releaseEntry: trying to release key '%s' that is not in cache"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|Node
modifier|*
name|node
init|=
operator|&
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|node
operator|->
name|useCount
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// are there other objects waiting?
if|if
condition|(
operator|!
name|node
operator|->
name|receiverQueue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// queue another activation
name|Receiver
name|receiver
decl_stmt|;
do|do
block|{
name|receiver
operator|=
name|node
operator|->
name|receiverQueue
operator|.
name|dequeue
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|receiver
operator|.
name|object
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|node
operator|->
name|receiverQueue
operator|.
name|isEmpty
argument_list|()
condition|)
do|;
if|if
condition|(
operator|!
name|receiver
operator|.
name|object
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|emitEntryReady
argument_list|(
name|node
argument_list|,
name|receiver
operator|.
name|object
argument_list|,
name|receiver
operator|.
name|member
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
operator|!
operator|--
name|node
operator|->
name|useCount
condition|)
block|{
comment|// no objects waiting; add it back to the expiry list
if|if
condition|(
name|node
operator|->
name|object
operator|->
name|expires
condition|)
name|linkEntry
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldest
operator|==
name|node
condition|)
name|updateTimer
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeEntry
name|void
name|QNetworkAccessCache
operator|::
name|removeEntry
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
name|NodeHash
operator|::
name|Iterator
name|it
init|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QNetworkAccessCache::removeEntry: trying to remove key '%s' that is not in cache"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|Node
modifier|*
name|node
init|=
operator|&
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|unlinkEntry
argument_list|(
name|key
argument_list|)
condition|)
name|updateTimer
argument_list|()
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|useCount
operator|>
literal|1
condition|)
name|qWarning
argument_list|(
literal|"QNetworkAccessCache::removeEntry: removing active cache entry '%s'"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|node
operator|->
name|object
operator|->
name|key
operator|.
name|clear
argument_list|()
expr_stmt|;
name|hash
operator|.
name|remove
argument_list|(
name|node
operator|->
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
