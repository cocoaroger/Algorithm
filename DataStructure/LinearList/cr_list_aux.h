#ifndef _CR_LIST_AUX_H_
#define _CR_LIST_AUX_H_

#include "cr_def.h"

#define _GET_LIST_TYPE_SIZE(plist_list)	((plist_list)->_t_typeinfo._pt_type->_t_typesize);
#define _GET_LIST_TYPE_NAME(plist_list)             ((plist_list)->_t_typeinfo._s_typename)
#define _GET_LIST_TYPE_BASENAME(plist_list)         ((plist_list)->_t_typeinfo._pt_type->_s_typename)
#define _GET_LIST_TYPE_INIT_FUNCTION(plist_list)    ((plist_list)->_t_typeinfo._pt_type->_t_typeinit)
#define _GET_LIST_TYPE_COPY_FUNCTION(plist_list)    ((plist_list)->_t_typeinfo._pt_type->_t_typecopy)
#define _GET_LIST_TYPE_LESS_FUNCTION(plist_list)    ((plist_list)->_t_typeinfo._pt_type->_t_typeless)
#define _GET_LIST_TYPE_DESTROY_FUNCTION(plist_list) ((plist_list)->_t_typeinfo._pt_type->_t_typedestroy)
#define _GET_LIST_TYPE_STYLE(plist_list)            ((plist_list)->_t_typeinfo._t_style)

#ifndef NDEBUG

extern bool_t _list_is_created(const list_t* cplist_list);

extern bool_t _list_is_inited(const list_t* cplist_list)
#endif /* NDEBUG */




extern void _list_get_varg_value_auxiliary(list_t* plist_list, va_list val_elemlist, _listnode_t* pt_node);

#endif