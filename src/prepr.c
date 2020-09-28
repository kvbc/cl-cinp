/*
*
* prepr.c
* Preprocessor
*
*/


#include "prepr.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


cl_prepr_t* cl_prepr_new(char* src) {
	cl_prepr_t* prepr = malloc(sizeof(cl_prepr_t));
	size_t len = strlen(src);

	prepr->data = cl_str_substr(cl_str_new(), src, len);
	prepr->lines = 1;
	prepr->v_lines = cl_vector_new(50);
	cl_vector_push(prepr->v_lines, 1);

	for(size_t i = 0; i < len; ++i)
		if(src[i] == '\n' ||
		  (src[i] == '\r' && src[i + 1] == '\n')) {
			++prepr->lines;
			cl_vector_push(prepr->v_lines, i);
		}

	return prepr;
}


void cl_prepr_close(cl_prepr_t* prepr) {
	cl_str_free(prepr->data);
	cl_vector_free(prepr->v_lines);
	free(prepr);
}
