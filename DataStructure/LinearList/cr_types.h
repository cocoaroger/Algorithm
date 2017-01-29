#ifndef _CR_TYPE_H_
#define _CR_TYPE_H_
#include <stdio.h>
#include <stddef.h>

#define _TYPE_NAME_SIZE 255

/*
 * Type definition of unary function and binary function.
 * Note: The last parameter is for output
 */
typedef void (*unary_function_t)(const void*, void*);
typedef void (*binary_function_t)(const void*, const void*, void*);
typedef unary_function_t ufun_t;
typedef binary_function_t bfun_t;

typedef enum _tagtypestyle
{
	_TYPE_INVALID = 0, _TYPE_C_BUILTIN, _TYPE_USER_DEFINE, _TYPE_CR_BUILTIN
}_typestyle_t;

typedef struct _tagtype
{
	size_t	_t_typesize;
	char	_s_typename[_TYPE_NAME_SIZE + 1];
	_typestyle_t	_t_style;
	bfun_t	_t_typecopy;
	bfun_t	_t_typeless;
	ufun_t	_t_typeinit;
	ufun_t  _t_typedestroy;
}_type_t;

typedef struct _tagtypeinfo
{
	char	_s_typename[_TYPE_NAME_SIZE + 1];
	_type_t*	_pt_type;
	_typestyle_t	_t_style;
}_typeinfo_t;

extern void _type_get_type(_typeinfo_t* pt_typeinfo, const char* _s_typename);
#endif