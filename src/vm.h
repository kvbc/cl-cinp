  
/*
*
* vm.h
* Virtual Machine
*
*/


#pragma once

#include "lex.h"
#include "prepr.h"
#include "vector.h"

#define CL_VM_STATE   int
#define CL_VM_ERROR   0
#define CL_VM_SUCCESS 1


typedef struct {
	cl_vector_t* st;
	cl_prepr_t* prepr;
	cl_lex_state_t* ls;
	char* err;
} cl_vm_t;


cl_vm_t* cl_vm_new(void);
void cl_vm_run(cl_vm_t* vm, char* src);
void cl_vm_close(cl_vm_t* vm);
