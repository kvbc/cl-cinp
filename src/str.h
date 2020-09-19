/*
*
* str.h
* String Helpers
*
*/


#pragma once
#include <stddef.h>


typedef struct {
	char* src;
	size_t len;
} cl_str_t;


cl_str_t* cl_str_new(void);
void cl_str_substr(cl_str_t* buff, char* src, size_t len);
void cl_str_free(cl_str_t* str);