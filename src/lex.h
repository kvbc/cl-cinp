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
	TK_EOF = CL_READER_EOS,	           // End of file
	TK_UNX,                            // Unexpected
	TK_IDENT,

	TK_PUSH,
	TK_POP,
	TK_ADD,
	TK_IFEQ,
	TK_JUMP,
	TK_PRINT,
	TK_DUP,
	TK_SWAP,

	TK_NUM,
	TK_CMT
} cl_token_type;


typedef struct {
	cl_reader_t* rdr;
	cl_token_type tk_type;
	cl_str_t* tk_lexeme;
	int tk_num;
	char cur;
} cl_lex_state_t;


cl_lex_state_t* cl_lex_new(char* src);
void cl_lex_next(cl_lex_state_t* ls);
void cl_lex_close(cl_lex_state_t* ls);
