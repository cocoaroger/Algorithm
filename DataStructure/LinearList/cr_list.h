#ifndef _CR_LIST_H_
#define _CR_LIST_H_
#include "cr_list_private.h"

#define create_list(...) _create_list(#__VA_ARGS__)

#define list_init_elem(plist_list, t_count, elem) _list_init_elem((plist_list), (t_count), (elem))



#endif