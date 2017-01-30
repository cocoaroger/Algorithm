#ifndef _CR_ALLOC_H_
#define _CR_ALLOC_H_

#include <stdio.h>
#include "cr_def.h"

#ifdef CR_MEMORY_MANAGEMENT

#define _MEM_ALIGMENT	8 /* boundary for small memory block */
#define _MEM_SMALL_MEM_SIZE_MAX	128 /* the maxinum size of small memory */
#define _MEM_LINK_COUNT	_MEM_SMALL_MEM_SIZE_MAX/_MEM_ALIGMENT
#define _MEM_CHUNK_COUNT 16 /* default chunk count getted from pool */
#define _MEM_POOL_DEFAULT_COUNT 16 /* memory pool count */

typedef union _tagmemlink
{
	union	_tagmemlink* _pui_nextmen; /* point to next memory block */
	_byte_t	_pby_mem[1];
}_memlink_t;

typedef struct _tagalloc
{
	_memlink_t* _apt_memlink[_MEM_LINK_COUNT];
	_byte_t** _ppby_mempoolcontainer;
	_byte_t* _pby_mempool;
	size_t _t_mempoolsize;
	size_t _t_mempoolindex;
	size_t _t_mempoolcount;
}_alloc_t;

#else

typedef struct _tagalloc
{
	int n_avoid_vc_error_c2016;
}_alloc_t;

#endif /* CR_MEMORY_MANAGEMENT */

extern void _alloc_init(_alloc_t* pt_allocator);

extern void _alloc_destroy(_alloc_t* pt_allocator);

extern void* _alloc_allocate(_alloc_t* pt_allocator, size_t t_size, size_t t_count);

extern void _alloca_deallocate(_alloc_t* pt_allocator, void* pv_allocmem, size_t t_size, size_t t_count);


#ifndef NDEBUG
extern bool_t _alloc_is_inited(const _alloc_t* cpt_allocator);
#endif

extern void (*_alloc_set_malloc_handler(void (*pfun_newhandler)(void)))(void);

#endif