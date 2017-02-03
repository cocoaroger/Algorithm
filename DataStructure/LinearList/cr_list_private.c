#ifndef _CR_LIST_PRIVATE_H_
#define _CR_LIST_PRIVATE_H_

#include <assert.h>
#include <stdarg.h>
#include "cr_def.h"
#include "cr_types.h"
#include "cr_alloc.h"
#include "cr_list_aux.h"

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
	assert(_list_is_created(plist_list));

	va_start(val_elemlist, t_count);
	_list_init_elem_varg(plist_list, t_count, val_elemlist);
	va_end(val_elemlist);
}

void _list_init_elem_varg(list_t* plist_list, size_t t_count, va_list val_elemlist)
{
	_listnode_t* pt_varg = NULL;

	assert(plist_list != NULL);
	assert(_list_is_created(plist_list));

	plist_list->_pt_node = _alloc_allocate(&plist_list->_t_allocator, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
	assert(plist_list->_pt_node != NULL);
	plist_list->_pt_node->_pt_next = plist_list->_pt_node;
	plist_list->_pt_node->_pt_prev = plist_list->_pt_node;

	if (t_count > 0)
	{
		size_t i = 0;
		_listnode_t* pt_node = NULL;
		bool_t b_result = false;

		pt_varg = _alloc_allocate(*plist_list->_t_allocator, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
		assert(pt_varg != NULL);
		_list_get_varg_value_auxiliary(plist_list, val_elemlist, pt_varg);

		for (i = 0; i < count; ++i)
		{
			pt_node = _alloc_allocate(&plist_list->_t_allocator, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
			assert(pt_node != NULL);
			_list_init_node_auxiliary(plist_list, pt_node);

			b_result = _GET_LIST_TYPE_SIZE(plist_list);
			_GET_LIST_TYPE_COPY_FUNCTION(plist_list)(pt_node->_pby_data, pt_varg->_pby_data, &b_result);
			assert(b_result != NULL);

			pt_node->_pt_next = plist_list->_pt_node;
			pt_node->_pt_prev = plist_list->_pt_node->_pt_prev;
			plist_list->_pt_node->_pt_prev->_pt_next = pt_node;
			plist_list->_pt_node->_pt_prev = pt_node;
			pt_node = NULL;
		}

		_list_destroy_varg_value_auxiliary(plist_list, pt_varg);
		_alloc_allocate(&plist_list->_t_allocator, pt_varg, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
	}
}

void _list_push_back(list_t* plist_list, ...)
{
	va_list val_elemlist;

	assert(plist_list != NULL);
	assert(_list_is_inited(plist_list));

	va_start(val_elemlist, plist_list);
	
	_list_push_back_varg(plist_list, val_elemlist);
	
	va_end(val_elemlist);
}

void _list_push_back_varg(list_t* plist_list, va_list val_elemlist)
{
	_listnode_t* pt_node = NULL;

	assert(plist_list != NULL);
	assert(_list_is_inited(plist_list));

	pt_node = _alloc_allocate(&plist_list->_t_allocator, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
	assert(pt_node != NULL);
	_list_get_varg_value_auxiliary(plist_list, val_elemlist, pt_node);

	pt_node->_pt_next = plist_list->_pt_node;
	pt_node->_pt_prev = plist_list->_pt_node->_pt_prev;

	plist_list->_pt_node->_pt_prev->_pt_next = pt_node;
	plist_list->_pt_node->_pt_prev = pt_node;
}

void _list_push_front(list_t* plist_list, ...)
{
    va_list val_elemlist;

    assert(plist_list != NULL);
    assert(_list_is_inited(plist_list));

    va_start(val_elemlist, plist_list);
    _list_push_front_varg(plist_list, val_elemlist);
    va_end(val_elemlist);
}

void _list_push_front_varg(list_t* plist_list, va_list val_elemlist)
{
    _listnode_t* pt_node = NULL;    /* the allocate node */

    assert(plist_list != NULL);
    assert(_list_is_inited(plist_list));

    /* allocate the node */
    pt_node = _alloc_allocate(&plist_list->_t_allocator, _LIST_NODE_SIZE(_GET_LIST_TYPE_SIZE(plist_list)), 1);
    assert(pt_node != NULL);
    _list_get_varg_value_auxiliary(plist_list, val_elemlist, pt_node);
    /* insert the node into the first position */
    pt_node->_pt_next = plist_list->_pt_node->_pt_next;
    pt_node->_pt_prev = plist_list->_pt_node;
    plist_list->_pt_node->_pt_next->_pt_prev = pt_node;
    plist_list->_pt_node->_pt_next = pt_node;
}


#endif