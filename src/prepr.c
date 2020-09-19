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


cl_prepr_t* cl_prepr_new(char* data) {
	cl_prepr_t* prepr = malloc(sizeof(cl_prepr_t));
	prepr->data = data;
	prepr->lines = 1;
	prepr->v_lines = cl_vector_new(50);
	return prepr;
}


void cl_prepr_run(cl_prepr_t* prepr) {
	cl_vector_push(prepr->v_lines, 0);
	size_t len = strlen(prepr->data);

	for(size_t i = 0; i < len; i++)
		if(prepr->data[i] == '\n') {
			++prepr->lines;
			cl_vector_push(prepr->v_lines, i);
		}
}


void cl_prepr_close(cl_prepr_t* prepr) {
	cl_vector_free(prepr->v_lines);
	free(prepr);
}