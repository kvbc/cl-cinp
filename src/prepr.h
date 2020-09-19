/*
*
* prepr.h
* Preprocessor
*
*/


#pragma once

#include "vector.h"


typedef struct {
	char* data;
	size_t lines;
	cl_vector_t* v_lines;
} cl_prepr_t;


cl_prepr_t* cl_prepr_new(char* data);
void cl_prepr_run(cl_prepr_t* prepr);
void cl_prepr_close(cl_prepr_t* prepr);