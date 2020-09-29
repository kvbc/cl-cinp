/*
*
* vector.c
* Vector
*
*/


#include "vector.h"

#include <stdlib.h>


cl_vector_t* cl_vector_new(size_t cap) {
	cl_vector_t* v = malloc(sizeof(cl_vector_t));
	v->raw = malloc(cap * sizeof(int));
	v->cap = cap;
	v->top = 0;
	return v;
}


void cl_vector_push(cl_vector_t* v, int val) {
	if(v->top == v->cap)
		realloc(v->raw, (v->cap += 25) * sizeof(int));
	v->raw[v->top++] = val;
}


int cl_vector_pop(cl_vector_t* v) {
	if(v->top == 0)
		return 0;
	return v->raw[--v->top];
}


void cl_vector_free(cl_vector_t* v) {
	free(v->raw);
	free(v);
}
