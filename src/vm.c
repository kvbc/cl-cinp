/*
*
* vm.c
* Virtual Machine
*
*/


#include "vm.h"
#include <stdio.h>
#include <stdlib.h>


cl_vm_t* cl_vm_new(void) {
	cl_vm_t* vm = malloc(sizeof(cl_vm_t));
	vm->st = cl_vector_new(100);
	return vm;
}


static CL_VM_STATE cl_vm_expectn(cl_vm_t* vm, char* err) {
	cl_lex_next(vm->ls);
	if(vm->ls->tk_type != TK_NUM) {
		vm->err = err;
		return CL_VM_ERROR;
	}
	return CL_VM_SUCCESS;
}


static CL_VM_STATE cl_vm_jump(cl_vm_t* vm) {
	int line = strtoll(vm->ls->tk_lexeme->src, NULL, 10);
	if(line < 1 || line > vm->prepr->lines) {
		vm->err = "Invalid line number";
		return CL_VM_ERROR;
	}
	vm->ls->line = line;
	vm->ls->reader->cur = &vm->prepr->data[vm->prepr->v_lines->raw[line - 1] + 1];
	return CL_VM_SUCCESS;
}


static CL_VM_STATE cl_vm_runtk(cl_vm_t* vm) {
	cl_lex_next(vm->ls);

	switch(vm->ls->tk_type) {
		case TK_PUSH:
			if(!cl_vm_expectn(vm, "Expected an number for command 'push'"))
				return CL_VM_ERROR;
			cl_vector_push(vm->st, strtoll(vm->ls->tk_lexeme->src, NULL, 10));
			break;
		case TK_POP:
			cl_vector_pop(vm->st);
			break;
		case TK_ADD: {
			int a = cl_vector_pop(vm->st);
			int b = cl_vector_pop(vm->st);
			cl_vector_push(vm->st, a + b);
			break;
		}
		case TK_IFEQ:
			if(!cl_vm_expectn(vm, "Expected an number for command 'ifeq'"))
				return CL_VM_ERROR;
			if(cl_vector_pop(vm->st) && !cl_vm_jump(vm))
				return CL_VM_ERROR;
			break;
		case TK_JUMP:
			if(!cl_vm_expectn(vm, "Expected an number for command 'jump'"))
				return CL_VM_ERROR;
			if(!cl_vm_jump(vm))
				return CL_VM_ERROR;
			break;
		case TK_PRINT:
			printf("%c", cl_vector_pop(vm->st));
			break;
		case TK_DUP: {
			int top = cl_vector_pop(vm->st);
			cl_vector_push(vm->st, top);
			cl_vector_push(vm->st, top);
			break;
		}
		case TK_NUM:
			vm->err = NULL;
			printf("\nError %d:%d: Unexpected number '%s'\n", vm->ls->line,
				   vm->ls->col - vm->ls->tk_lexeme->len,
				   vm->ls->tk_lexeme->src);
			return CL_VM_ERROR;
		case TK_UNX:
			vm->err = NULL;
			printf("\nError %d:%d: Unexpected character '%c'\n", vm->ls->line,
				   vm->ls->col,
				   vm->ls->cur);
			return CL_VM_ERROR;
	}

	return CL_VM_SUCCESS;
}


void cl_vm_run(cl_vm_t* vm, char* src) {
	vm->ls = cl_lex_new(src);
	vm->prepr = cl_prepr_new(src);
	cl_prepr_run(vm->prepr);

	do {
		if(!cl_vm_runtk(vm) && vm->err) {
			printf("\nError %d:%d: %s\n", vm->ls->line,
				   vm->ls->col - (vm->ls->tk_lexeme->len * (vm->ls->tk_type == TK_NUM)),
				   vm->err);
		}
	} while(vm->ls->tk_type != TK_EOF);

	cl_lex_close(vm->ls);
	cl_prepr_close(vm->prepr);
}


void cl_vm_close(cl_vm_t* vm) {
	cl_vector_free(vm->st);
	free(vm);
}
