#ifndef _CR_LIST_PRIVATE_H_
#define _CR_LIST_PRIVATE_H_

#include "cr_def.h"
#include "cr_types.h"
#include "cr_alloc.h"
#include "cr_list.h"
#include "cr_list_aux.h"

#include <assert.h>

list_t* _create_list(const char* s_typename)
{
	list_t* plist_new = NULL;
	assert(s_typename != NULL);

	plist_new = (list_t*)malloc(sizeof(list_t));
	if (plist_new == NULL)
	{
		return NULL;
	}

	if (!_create_list_auxiliary(plist_new, s_typename))
	{
		free(plist_new);
		return NULL;
	}

	return plist_new;
}

bool_t _create_list_auxiliary(list_t* plist_list, const char* s_typename)
{
	assert(plist_list != NULL);
	assert(s_typename != NULL);

	_type_get_type(&plist_list->_t_typeinfo, s_typename);
	if (plist_list->_t_typeinfo._t_style == _TYPE_INVALID)
	{
		return false;
	}

	plist_list->_pt_node = NULL;

	_alloc_init(&plist_list->_t_allocator);
	return true;
}

void _list_init_elem(list_t* plist_list, size_t t_count, ...)
{
	va_list val_elemlist;

	assert(plist_list != NULL);

}

void _list_init_elem_varg(list_t* plist_list, size_t t_count, va_list val_elemlist)
{
	_listnode_t* pt_varg = NULL;

	assert(plist_list != NULL);


}

#endif