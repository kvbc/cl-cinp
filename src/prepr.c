/*
*
* prepr.c
* Preprocessor
*
*/


#include "prepr.h"
#include "char.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


cl_prepr_t* cl_prepr_new(char* src) {
	cl_prepr_t* prepr = malloc(sizeof(cl_prepr_t));
	size_t len = strlen(src);

	prepr->lines = 1;
	prepr->v_lines = cl_vector_new(50);
	cl_vector_push(prepr->v_lines, 0);

	for(size_t i = 0; i < len; ++i) {
		if(cl_char_islb(src[i])) {
			if(cl_char_islb(src[i + 1]) && src[i + 1] != src[i]) ++i;
			++prepr->lines;
			cl_vector_push(prepr->v_lines, i + 1);
		}
	}

	return prepr;
}


void cl_prepr_close(cl_prepr_t* prepr) {
	cl_vector_free(prepr->v_lines);
	free(prepr);
}
