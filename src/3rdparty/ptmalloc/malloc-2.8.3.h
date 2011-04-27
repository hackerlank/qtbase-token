begin_unit
begin_comment
comment|/*   Default header file for malloc-2.8.x, written by Doug Lea   and released to the public domain, as explained at   http://creativecommons.org/licenses/publicdomain.      last update: Mon Aug 15 08:55:52 2005  Doug Lea  (dl at gee)    This header is for ANSI C/C++ only.  You can set any of   the following #defines before including:    * If USE_DL_PREFIX is defined, it is assumed that malloc.c      was also compiled with this option, so all routines     have names starting with "dl".    * If HAVE_USR_INCLUDE_MALLOC_H is defined, it is assumed that this     file will be #included AFTER<malloc.h>. This is needed only if     your system defines a struct mallinfo that is incompatible with the     standard one declared here.  Otherwise, you can include this file     INSTEAD of your system system<malloc.h>.  At least on ANSI, all     declarations should be compatible with system versions    * If MSPACES is defined, declarations for mspace versions are included. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MALLOC_280_H
end_ifndef
begin_define
DECL|macro|MALLOC_280_H
define|#
directive|define
name|MALLOC_280_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<stddef.h>
comment|/* for size_t */
if|#
directive|if
operator|!
name|ONLY_MSPACES
ifndef|#
directive|ifndef
name|USE_DL_PREFIX
DECL|macro|dlcalloc
define|#
directive|define
name|dlcalloc
value|calloc
DECL|macro|dlfree
define|#
directive|define
name|dlfree
value|free
DECL|macro|dlmalloc
define|#
directive|define
name|dlmalloc
value|malloc
DECL|macro|dlmemalign
define|#
directive|define
name|dlmemalign
value|memalign
DECL|macro|dlrealloc
define|#
directive|define
name|dlrealloc
value|realloc
DECL|macro|dlvalloc
define|#
directive|define
name|dlvalloc
value|valloc
DECL|macro|dlpvalloc
define|#
directive|define
name|dlpvalloc
value|pvalloc
DECL|macro|dlmallinfo
define|#
directive|define
name|dlmallinfo
value|mallinfo
DECL|macro|dlmallopt
define|#
directive|define
name|dlmallopt
value|mallopt
DECL|macro|dlmalloc_trim
define|#
directive|define
name|dlmalloc_trim
value|malloc_trim
DECL|macro|dlmalloc_stats
define|#
directive|define
name|dlmalloc_stats
value|malloc_stats
DECL|macro|dlmalloc_usable_size
define|#
directive|define
name|dlmalloc_usable_size
value|malloc_usable_size
DECL|macro|dlmalloc_footprint
define|#
directive|define
name|dlmalloc_footprint
value|malloc_footprint
DECL|macro|dlindependent_calloc
define|#
directive|define
name|dlindependent_calloc
value|independent_calloc
DECL|macro|dlindependent_comalloc
define|#
directive|define
name|dlindependent_comalloc
value|independent_comalloc
endif|#
directive|endif
comment|/* USE_DL_PREFIX */
comment|/*   malloc(size_t n)   Returns a pointer to a newly allocated chunk of at least n bytes, or   null if no space is available, in which case errno is set to ENOMEM   on ANSI C systems.    If n is zero, malloc returns a minimum-sized chunk. (The minimum   size is 16 bytes on most 32bit systems, and 32 bytes on 64bit   systems.)  Note that size_t is an unsigned type, so calls with   arguments that would be negative if signed are interpreted as   requests for huge amounts of space, which will often fail. The   maximum supported value of n differs across systems, but is in all   cases less than the maximum representable value of a size_t. */
name|void
modifier|*
name|dlmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
comment|/*   free(void* p)   Releases the chunk of memory pointed to by p, that had been previously   allocated using malloc or a related routine such as realloc.   It has no effect if p is null. If p was not malloced or already   freed, free(p) will by default cuase the current program to abort. */
name|void
name|dlfree
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*   calloc(size_t n_elements, size_t element_size);   Returns a pointer to n_elements * element_size bytes, with all locations   set to zero. */
name|void
modifier|*
name|dlcalloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/*   realloc(void* p, size_t n)   Returns a pointer to a chunk of size n that contains the same data   as does chunk p up to the minimum of (n, p's size) bytes, or null   if no space is available.    The returned pointer may or may not be the same as p. The algorithm   prefers extending p in most cases when possible, otherwise it   employs the equivalent of a malloc-copy-free sequence.    If p is null, realloc is equivalent to malloc.    If space is not available, realloc returns null, errno is set (if on   ANSI) and p is NOT freed.    if n is for fewer bytes than already held by p, the newly unused   space is lopped off and freed if possible.  realloc with a size   argument of zero (re)allocates a minimum-sized chunk.    The old unix realloc convention of allowing the last-free'd chunk   to be used as an argument to realloc is not supported. */
name|void
modifier|*
name|dlrealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/*   memalign(size_t alignment, size_t n);   Returns a pointer to a newly allocated chunk of n bytes, aligned   in accord with the alignment argument.    The alignment argument should be a power of two. If the argument is   not a power of two, the nearest greater power is used.   8-byte alignment is guaranteed by normal malloc calls, so don't   bother calling memalign with an argument of 8 or less.    Overreliance on memalign is a sure way to fragment space. */
name|void
modifier|*
name|dlmemalign
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/*   valloc(size_t n);   Equivalent to memalign(pagesize, n), where pagesize is the page   size of the system. If the pagesize is unknown, 4096 is used. */
name|void
modifier|*
name|dlvalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
comment|/*   mallopt(int parameter_number, int parameter_value)   Sets tunable parameters The format is to provide a   (parameter-number, parameter-value) pair.  mallopt then sets the   corresponding parameter to the argument value if it can (i.e., so   long as the value is meaningful), and returns 1 if successful else   0.  SVID/XPG/ANSI defines four standard param numbers for mallopt,   normally defined in malloc.h.  None of these are use in this malloc,   so setting them has no effect. But this malloc also supports other   options in mallopt:    Symbol            param #  default    allowed param values   M_TRIM_THRESHOLD     -1   2*1024*1024   any   (-1U disables trimming)   M_GRANULARITY        -2     page size   any power of 2>= page size   M_MMAP_THRESHOLD     -3      256*1024   any   (or 0 if no MMAP support) */
name|int
name|dlmallopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
DECL|macro|M_TRIM_THRESHOLD
define|#
directive|define
name|M_TRIM_THRESHOLD
value|(-1)
DECL|macro|M_GRANULARITY
define|#
directive|define
name|M_GRANULARITY
value|(-2)
DECL|macro|M_MMAP_THRESHOLD
define|#
directive|define
name|M_MMAP_THRESHOLD
value|(-3)
comment|/*   malloc_footprint();   Returns the number of bytes obtained from the system.  The total   number of bytes allocated by malloc, realloc etc., is less than this   value. Unlike mallinfo, this function returns only a precomputed   result, so can be called frequently to monitor memory consumption.   Even if locks are otherwise defined, this function does not use them,   so results might not be up to date. */
name|size_t
name|dlmalloc_footprint
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|NO_MALLINFO
comment|/*   mallinfo()   Returns (by copy) a struct containing various summary statistics:    arena:     current total non-mmapped bytes allocated from system   ordblks:   the number of free chunks   smblks:    always zero.   hblks:     current number of mmapped regions   hblkhd:    total bytes held in mmapped regions   usmblks:   the maximum total allocated space. This will be greater                 than current total if trimming has occurred.   fsmblks:   always zero   uordblks:  current total allocated space (normal or mmapped)   fordblks:  total free space   keepcost:  the maximum number of bytes that could ideally be released                back to system via malloc_trim. ("ideally" means that                it ignores page restrictions etc.)    Because these fields are ints, but internal bookkeeping may   be kept as longs, the reported values may wrap around zero and   thus be inaccurate. */
ifndef|#
directive|ifndef
name|HAVE_USR_INCLUDE_MALLOC_H
ifndef|#
directive|ifndef
name|_MALLOC_H
ifndef|#
directive|ifndef
name|MALLINFO_FIELD_TYPE
DECL|macro|MALLINFO_FIELD_TYPE
define|#
directive|define
name|MALLINFO_FIELD_TYPE
value|size_t
endif|#
directive|endif
comment|/* MALLINFO_FIELD_TYPE */
DECL|struct|mallinfo
struct|struct
name|mallinfo
block|{
DECL|member|arena
name|MALLINFO_FIELD_TYPE
name|arena
decl_stmt|;
comment|/* non-mmapped space allocated from system */
DECL|member|ordblks
name|MALLINFO_FIELD_TYPE
name|ordblks
decl_stmt|;
comment|/* number of free chunks */
DECL|member|smblks
name|MALLINFO_FIELD_TYPE
name|smblks
decl_stmt|;
comment|/* always 0 */
DECL|member|hblks
name|MALLINFO_FIELD_TYPE
name|hblks
decl_stmt|;
comment|/* always 0 */
DECL|member|hblkhd
name|MALLINFO_FIELD_TYPE
name|hblkhd
decl_stmt|;
comment|/* space in mmapped regions */
DECL|member|usmblks
name|MALLINFO_FIELD_TYPE
name|usmblks
decl_stmt|;
comment|/* maximum total allocated space */
DECL|member|fsmblks
name|MALLINFO_FIELD_TYPE
name|fsmblks
decl_stmt|;
comment|/* always 0 */
DECL|member|uordblks
name|MALLINFO_FIELD_TYPE
name|uordblks
decl_stmt|;
comment|/* total allocated space */
DECL|member|fordblks
name|MALLINFO_FIELD_TYPE
name|fordblks
decl_stmt|;
comment|/* total free space */
DECL|member|keepcost
name|MALLINFO_FIELD_TYPE
name|keepcost
decl_stmt|;
comment|/* releasable (via malloc_trim) space */
block|}
struct|;
endif|#
directive|endif
comment|/* _MALLOC_H */
endif|#
directive|endif
comment|/* HAVE_USR_INCLUDE_MALLOC_H */
name|struct
name|mallinfo
name|dlmallinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* NO_MALLINFO */
comment|/*   independent_calloc(size_t n_elements, size_t element_size, void* chunks[]);    independent_calloc is similar to calloc, but instead of returning a   single cleared space, it returns an array of pointers to n_elements   independent elements that can hold contents of size elem_size, each   of which starts out cleared, and can be independently freed,   realloc'ed etc. The elements are guaranteed to be adjacently   allocated (this is not guaranteed to occur with multiple callocs or   mallocs), which may also improve cache locality in some   applications.    The "chunks" argument is optional (i.e., may be null, which is   probably the most typical usage). If it is null, the returned array   is itself dynamically allocated and should also be freed when it is   no longer needed. Otherwise, the chunks array must be of at least   n_elements in length. It is filled in with the pointers to the   chunks.    In either case, independent_calloc returns this pointer array, or   null if the allocation failed.  If n_elements is zero and "chunks"   is null, it returns a chunk representing an array with zero elements   (which should be freed if not wanted).    Each element must be individually freed when it is no longer   needed. If you'd like to instead be able to free all at once, you   should instead use regular calloc and assign pointers into this   space to represent elements.  (In this case though, you cannot   independently free elements.)    independent_calloc simplifies and speeds up implementations of many   kinds of pools.  It may also be useful when constructing large data   structures that initially have a fixed number of fixed-sized nodes,   but the number is not known at compile time, and some of the nodes   may later need to be freed. For example:    struct Node { int item; struct Node* next; };    struct Node* build_list() {     struct Node** pool;     int n = read_number_of_nodes_needed();     if (n<= 0) return 0;     pool = (struct Node**)(independent_calloc(n, sizeof(struct Node), 0);     if (pool == 0) die();     // organize into a linked list...     struct Node* first = pool[0];     for (i = 0; i< n-1; ++i)       pool[i]->next = pool[i+1];     free(pool);     // Can now free the array (or not, if it is needed later)     return first;   } */
name|void
modifier|*
modifier|*
name|dlindependent_calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/*   independent_comalloc(size_t n_elements, size_t sizes[], void* chunks[]);    independent_comalloc allocates, all at once, a set of n_elements   chunks with sizes indicated in the "sizes" array.    It returns   an array of pointers to these elements, each of which can be   independently freed, realloc'ed etc. The elements are guaranteed to   be adjacently allocated (this is not guaranteed to occur with   multiple callocs or mallocs), which may also improve cache locality   in some applications.    The "chunks" argument is optional (i.e., may be null). If it is null   the returned array is itself dynamically allocated and should also   be freed when it is no longer needed. Otherwise, the chunks array   must be of at least n_elements in length. It is filled in with the   pointers to the chunks.    In either case, independent_comalloc returns this pointer array, or   null if the allocation failed.  If n_elements is zero and chunks is   null, it returns a chunk representing an array with zero elements   (which should be freed if not wanted).    Each element must be individually freed when it is no longer   needed. If you'd like to instead be able to free all at once, you   should instead use a single regular malloc, and assign pointers at   particular offsets in the aggregate space. (In this case though, you   cannot independently free elements.)    independent_comallac differs from independent_calloc in that each   element may have a different size, and also that it does not   automatically clear elements.    independent_comalloc can be used to speed up allocation in cases   where several structs or objects must always be allocated at the   same time.  For example:    struct Head { ... }   struct Foot { ... }    void send_message(char* msg) {     int msglen = strlen(msg);     size_t sizes[3] = { sizeof(struct Head), msglen, sizeof(struct Foot) };     void* chunks[3];     if (independent_comalloc(3, sizes, chunks) == 0)       die();     struct Head* head = (struct Head*)(chunks[0]);     char*        body = (char*)(chunks[1]);     struct Foot* foot = (struct Foot*)(chunks[2]);     // ...   }    In general though, independent_comalloc is worth using only for   larger values of n_elements. For small values, you probably won't   detect enough difference from series of malloc calls to bother.    Overuse of independent_comalloc can increase overall memory usage,   since it cannot reuse existing noncontiguous small chunks that   might be available for some of the elements. */
name|void
modifier|*
modifier|*
name|dlindependent_comalloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/*   pvalloc(size_t n);   Equivalent to valloc(minimum-page-that-holds(n)), that is,   round up n to nearest pagesize.  */
name|void
modifier|*
name|dlpvalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
comment|/*   malloc_trim(size_t pad);    If possible, gives memory back to the system (via negative arguments   to sbrk) if there is unused memory at the `high' end of the malloc   pool or in unused MMAP segments. You can call this after freeing   large blocks of memory to potentially reduce the system-level memory   requirements of a program. However, it cannot guarantee to reduce   memory. Under some allocation patterns, some large free blocks of   memory will be locked between two used chunks, so they cannot be   given back to the system.    The `pad' argument to malloc_trim represents the amount of free   trailing space to leave untrimmed. If this argument is zero, only   the minimum amount of memory to maintain internal data structures   will be left. Non-zero arguments can be supplied to maintain enough   trailing space to service future expected allocations without having   to re-obtain memory from the system.    Malloc_trim returns 1 if it actually released any memory, else 0. */
name|int
name|dlmalloc_trim
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
comment|/*   malloc_usable_size(void* p);    Returns the number of bytes you can actually use in   an allocated chunk, which may be more than you requested (although   often not) due to alignment and minimum size constraints.   You can use this many bytes without worrying about   overwriting other allocated objects. This is not a particularly great   programming practice. malloc_usable_size can be more useful in   debugging and assertions, for example:    p = malloc(n);   assert(malloc_usable_size(p)>= 256); */
name|size_t
name|dlmalloc_usable_size
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*   malloc_stats();   Prints on stderr the amount of space obtained from the system (both   via sbrk and mmap), the maximum amount (which may be more than   current if malloc_trim and/or munmap got called), and the current   number of bytes allocated via malloc (or realloc, etc) but not yet   freed. Note that this is the number of bytes allocated, not the   number requested. It will be larger than the number requested   because of alignment and bookkeeping overhead. Because it includes   alignment wastage as being in use, this figure may be greater than   zero even when no user-level chunks are allocated.    The reported current and maximum system memory can be inaccurate if   a program makes other calls to system memory allocation functions   (normally sbrk) outside of malloc.    malloc_stats prints only the most commonly interesting statistics.   More information can be obtained by calling mallinfo. */
name|void
name|dlmalloc_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !ONLY_MSPACES */
if|#
directive|if
name|MSPACES
comment|/*   mspace is an opaque type representing an independent   region of space that supports mspace_malloc, etc. */
DECL|typedef|mspace
typedef|typedef
name|void
modifier|*
name|mspace
typedef|;
comment|/*   create_mspace creates and returns a new independent space with the   given initial capacity, or, if 0, the default granularity size.  It   returns null if there is no system memory available to create the   space.  If argument locked is non-zero, the space uses a separate   lock to control access. The capacity of the space will grow   dynamically as needed to service mspace_malloc requests.  You can   control the sizes of incremental increases of this space by   compiling with a different DEFAULT_GRANULARITY or dynamically   setting with mallopt(M_GRANULARITY, value). */
name|mspace
name|create_mspace
parameter_list|(
name|size_t
name|capacity
parameter_list|,
name|int
name|locked
parameter_list|)
function_decl|;
comment|/*   destroy_mspace destroys the given space, and attempts to return all   of its memory back to the system, returning the total number of   bytes freed. After destruction, the results of access to all memory   used by the space become undefined. */
name|size_t
name|destroy_mspace
parameter_list|(
name|mspace
name|msp
parameter_list|)
function_decl|;
comment|/*   create_mspace_with_base uses the memory supplied as the initial base   of a new mspace. Part (less than 128*sizeof(size_t) bytes) of this   space is used for bookkeeping, so the capacity must be at least this   large. (Otherwise 0 is returned.) When this initial space is   exhausted, additional memory will be obtained from the system.   Destroying this space will deallocate all additionally allocated   space (if possible) but not the initial base. */
name|mspace
name|create_mspace_with_base
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|capacity
parameter_list|,
name|int
name|locked
parameter_list|)
function_decl|;
comment|/*   mspace_malloc behaves as malloc, but operates within   the given space. */
name|void
modifier|*
name|mspace_malloc
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|bytes
parameter_list|)
function_decl|;
comment|/*   mspace_free behaves as free, but operates within   the given space.    If compiled with FOOTERS==1, mspace_free is not actually needed.   free may be called instead of mspace_free because freed chunks from   any space are handled by their originating spaces. */
name|void
name|mspace_free
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|)
function_decl|;
comment|/*   mspace_realloc behaves as realloc, but operates within   the given space.    If compiled with FOOTERS==1, mspace_realloc is not actually   needed.  realloc may be called instead of mspace_realloc because   realloced chunks from any space are handled by their originating   spaces. */
name|void
modifier|*
name|mspace_realloc
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|newsize
parameter_list|)
function_decl|;
comment|/*   mspace_calloc behaves as calloc, but operates within   the given space. */
name|void
modifier|*
name|mspace_calloc
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|n_elements
parameter_list|,
name|size_t
name|elem_size
parameter_list|)
function_decl|;
comment|/*   mspace_memalign behaves as memalign, but operates within   the given space. */
name|void
modifier|*
name|mspace_memalign
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|size_t
name|bytes
parameter_list|)
function_decl|;
comment|/*   mspace_independent_calloc behaves as independent_calloc, but   operates within the given space. */
name|void
modifier|*
modifier|*
name|mspace_independent_calloc
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|n_elements
parameter_list|,
name|size_t
name|elem_size
parameter_list|,
name|void
modifier|*
name|chunks
index|[]
parameter_list|)
function_decl|;
comment|/*   mspace_independent_comalloc behaves as independent_comalloc, but   operates within the given space. */
name|void
modifier|*
modifier|*
name|mspace_independent_comalloc
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|n_elements
parameter_list|,
name|size_t
name|sizes
index|[]
parameter_list|,
name|void
modifier|*
name|chunks
index|[]
parameter_list|)
function_decl|;
comment|/*   mspace_footprint() returns the number of bytes obtained from the   system for this space. */
name|size_t
name|mspace_footprint
parameter_list|(
name|mspace
name|msp
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|NO_MALLINFO
comment|/*   mspace_mallinfo behaves as mallinfo, but reports properties of   the given space. */
name|struct
name|mallinfo
name|mspace_mallinfo
parameter_list|(
name|mspace
name|msp
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* NO_MALLINFO */
comment|/*   mspace_malloc_stats behaves as malloc_stats, but reports   properties of the given space. */
name|void
name|mspace_malloc_stats
parameter_list|(
name|mspace
name|msp
parameter_list|)
function_decl|;
comment|/*   mspace_trim behaves as malloc_trim, but   operates within the given space. */
name|int
name|mspace_trim
parameter_list|(
name|mspace
name|msp
parameter_list|,
name|size_t
name|pad
parameter_list|)
function_decl|;
comment|/*   An alias for malloc_usable_size. */
name|size_t
name|mspace_usable_size
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|)
function_decl|;
comment|/*   An alias for mallopt. */
name|int
name|mspace_mallopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* MSPACES */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* end of extern "C" */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* MALLOC_280_H */
end_comment
end_unit
