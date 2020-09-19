/*
*
* str.c
* String Helpers
*
*/


#include "str.h"
#include <string.h>
#include <stdlib.h>


cl_str_t* cl_str_new(void) {
	cl_str_t* str = malloc(sizeof(cl_str_t));
	str->src = NULL;
	str->len = 0;
	return str;
}


void cl_str_substr(cl_str_t* buff, char* src, size_t len) {
	if(len > buff->len) {
		if(buff->src != NULL)
			free(buff->src);
		buff->src = malloc(len + 1);
	}
	buff->len = len;
	memcpy(buff->src, src, len);
	buff->src[len] = '\0';
}


void cl_str_free(cl_str_t* str) {
	if(str->src != NULL)
		free(str->src);
	free(str);
}
