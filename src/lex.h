/*
*
* lex.h
* Lexical Analyzer
*
*/


#pragma once

#include "str.h"
#include "reader.h"
#include <stddef.h>


typedef enum {
	TK_UNX = -2,				   // Unexpected
	TK_EOF = CL_MEMREADER_EOS,	   // End of file

	TK_PUSH,
	TK_POP,
	TK_ADD,
	TK_IFEQ,
	TK_JUMP,
	TK_PRINT,
	TK_DUP,

	TK_NUM,
	TK_CMT
} cl_token_type;


typedef struct {
	cl_memreader_t* reader;
	cl_token_type tk_type;
	cl_str_t* tk_lexeme;
	size_t line;
	size_t col;
	char cur;
} cl_lex_state_t;


cl_lex_state_t* cl_lex_new(char* data);
void cl_lex_next(cl_lex_state_t* ls);
void cl_lex_close(cl_lex_state_t* ls);
