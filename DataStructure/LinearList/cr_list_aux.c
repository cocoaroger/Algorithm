#include <stdlib.h>

void _list_get_varg_value_auxiliary(list_t* plist_list, va_list val_elemlist, _listnode_t* pt_node)
{
	assert(plist_list != NULL);
    assert(pt_node != NULL);
    assert(_list_is_inited(plist_list) || _list_is_created(plist_list));

    _list_init_node_auxiliary(plist_list, pt_node);
    _type_get_varg_value(&plist_list->_t_typeinfo, val_elemlist, pt_node->_pby_data);
}