/*
*
* vector.h
* Vector
*
*/


#pragma once
#include <stddef.h>


typedef struct {
	int* raw;
	size_t top;
	size_t cap;
} cl_vector_t;


cl_vector_t* cl_vector_new(size_t cap);
void cl_vector_push(cl_vector_t* st, int val);
int cl_vector_pop(cl_vector_t* st);
void cl_vector_free(cl_vector_t* st);