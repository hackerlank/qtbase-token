begin_unit
begin_comment
comment|/*  * $Id: thread-st.h$  * pthread version  * by Wolfram Gloger 2004  */
end_comment
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
DECL|variable|finish_cond
name|pthread_cond_t
name|finish_cond
init|=
name|PTHREAD_COND_INITIALIZER
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|finish_mutex
name|pthread_mutex_t
name|finish_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|USE_PTHREADS_STACKS
end_ifndef
begin_define
DECL|macro|USE_PTHREADS_STACKS
define|#
directive|define
name|USE_PTHREADS_STACKS
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|STACKSIZE
end_ifndef
begin_define
DECL|macro|STACKSIZE
define|#
directive|define
name|STACKSIZE
value|32768
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|thread_st
struct|struct
name|thread_st
block|{
DECL|member|sp
name|char
modifier|*
name|sp
decl_stmt|;
comment|/* stack pointer, can be 0 */
DECL|member|func
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|thread_st
modifier|*
name|st
parameter_list|)
function_decl|;
comment|/* must be set by user */
DECL|member|id
name|pthread_t
name|id
decl_stmt|;
DECL|member|flags
name|int
name|flags
decl_stmt|;
DECL|member|u
name|struct
name|user_data
name|u
decl_stmt|;
block|}
struct|;
end_struct
begin_function
specifier|static
name|void
DECL|function|thread_init
name|thread_init
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Using posix threads.\n"
argument_list|)
expr_stmt|;
name|pthread_cond_init
argument_list|(
operator|&
name|finish_cond
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_mutex_init
argument_list|(
operator|&
name|finish_mutex
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
modifier|*
DECL|function|thread_wrapper
name|thread_wrapper
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|struct
name|thread_st
modifier|*
name|st
init|=
operator|(
expr|struct
name|thread_st
operator|*
operator|)
name|ptr
decl_stmt|;
comment|/*printf("begin %p\n", st->sp);*/
name|st
operator|->
name|func
argument_list|(
name|st
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|finish_mutex
argument_list|)
expr_stmt|;
name|st
operator|->
name|flags
operator|=
literal|1
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|finish_mutex
argument_list|)
expr_stmt|;
name|pthread_cond_signal
argument_list|(
operator|&
name|finish_cond
argument_list|)
expr_stmt|;
comment|/*printf("end %p\n", st->sp);*/
return|return
name|NULL
return|;
block|}
end_function
begin_comment
comment|/* Create a thread. */
end_comment
begin_function
specifier|static
name|int
DECL|function|thread_create
name|thread_create
parameter_list|(
name|struct
name|thread_st
modifier|*
name|st
parameter_list|)
block|{
name|st
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
block|{
name|pthread_attr_t
modifier|*
name|attr_p
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|USE_PTHREADS_STACKS
name|pthread_attr_t
name|attr
decl_stmt|;
name|pthread_attr_init
argument_list|(
operator|&
name|attr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|st
operator|->
name|sp
condition|)
name|st
operator|->
name|sp
operator|=
name|malloc
argument_list|(
name|STACKSIZE
operator|+
literal|16
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|st
operator|->
name|sp
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|pthread_attr_setstacksize
argument_list|(
operator|&
name|attr
argument_list|,
name|STACKSIZE
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error setting stacksize"
argument_list|)
expr_stmt|;
else|else
name|pthread_attr_setstackaddr
argument_list|(
operator|&
name|attr
argument_list|,
name|st
operator|->
name|sp
operator|+
name|STACKSIZE
argument_list|)
expr_stmt|;
comment|/*printf("create %p\n", st->sp);*/
name|attr_p
operator|=
operator|&
name|attr
expr_stmt|;
endif|#
directive|endif
return|return
name|pthread_create
argument_list|(
operator|&
name|st
operator|->
name|id
argument_list|,
name|attr_p
argument_list|,
name|thread_wrapper
argument_list|,
name|st
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* Wait for one of several subthreads to finish. */
end_comment
begin_function
specifier|static
name|void
DECL|function|wait_for_thread
name|wait_for_thread
parameter_list|(
name|struct
name|thread_st
name|st
index|[]
parameter_list|,
name|int
name|n_thr
parameter_list|,
name|int
function_decl|(
modifier|*
name|end_thr
function_decl|)
parameter_list|(
name|struct
name|thread_st
modifier|*
parameter_list|)
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|finish_mutex
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|term
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n_thr
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|st
index|[
name|i
index|]
operator|.
name|flags
condition|)
block|{
comment|/*printf("joining %p\n", st[i].sp);*/
if|if
condition|(
name|pthread_join
argument_list|(
name|st
index|[
name|i
index|]
operator|.
name|id
argument_list|,
name|NULL
argument_list|)
operator|==
literal|0
condition|)
block|{
name|st
index|[
name|i
index|]
operator|.
name|flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|end_thr
condition|)
name|end_thr
argument_list|(
operator|&
name|st
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't join\n"
argument_list|)
expr_stmt|;
operator|++
name|term
expr_stmt|;
block|}
if|if
condition|(
name|term
operator|>
literal|0
condition|)
break|break;
name|pthread_cond_wait
argument_list|(
operator|&
name|finish_cond
argument_list|,
operator|&
name|finish_mutex
argument_list|)
expr_stmt|;
block|}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|finish_mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * Local variables:  * tab-width: 4  * End:  */
end_comment
end_unit
