#ifndef _CR_LIST_PRIVATE_H_
#define _CR_LIST_PRIVATE_H_

#include "stdio.h"
#include "cr_types.h"
#include "cr_def.h"
#include "cr_alloc.h"

#define _LIST_NODE_SIZE(typesize) ((typesize) + sizeof(_listnode_t) - sizeof(_byte_t))

/** data type declaration and struct, union, enum section **/
/*
 * +----------------+
 * | previous node  |
 * +----------------+
 * | next node      |
 * +----------------+
 * | data  ...      |
 * |     . . .      |
 * +----------------+
 */
typedef struct _taglistnode
{
	struct _taglistnode* _pt_prev;
	struct _taglistnode* _pt_next;
	_byte_t _pby_data[1]; /* the element value */
}_listnode_t;

typedef struct _taglist
{
	_typeinfo_t	_t_typeinfo;
	_alloc_t	_t_allocator;
	_listnode_t*	_pt_node;
}list_t;

extern list_t* _create_list(const char* s_typename);

extern bool_t _create_list_auxiliary(list_t* plist_list, const char* s_typename);

extern void _list_init_elem(list_t* plist_list, size_t t_count, ...);

extern void _list_init_elem_varg(list_t* plist_list, size_t t_count, va_list val_elemlist);

extern void _list_destroy_auxiliary(list_t* plist_list);

extern void _list_assign_elem(list_t* plist_list, size_t t_count, ...);

extern void _list_assign_elem_varg(list_t *plist_list, size_t t_count, va_list val_elemlist);

extern void _list_push_back(list_t* plist_list, ...);

extern void _list_push_back_varg(list_t* plist_list, va_list val_elemlist);

extern void _list_push_front(list_t* plist_list, ...);

extern void _list_push_front_varg(list_t* plist_list, va_list val_elemlist);

#endif