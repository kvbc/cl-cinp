/*
*
* prepr.h
* Preprocessor
*
*/


#pragma once

#include "vector.h"


typedef struct {
	size_t lines;
	cl_vector_t* v_lines;
} cl_prepr_t;


cl_prepr_t* cl_prepr_new(char* src);
void cl_prepr_close(cl_prepr_t* prepr);
