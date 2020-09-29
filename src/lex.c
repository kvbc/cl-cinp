/*
*
* lex.c
* Lexical Analyzer
*
*/


#include "lex.h"
#include "char.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



static const char* const CL_COMMANDS[] = {
	"push", "pop", "add", "ifeq",
	"jump", "print", "dup", "swap"
};
static const size_t CL_COMMAND_COUNT = sizeof(CL_COMMANDS) / sizeof(char*);



/*
*
* Static helper functions
*
*/



static void cl_lex_readn(cl_lex_state_t* ls) {
	char* beg = ls->rdr->cur - 1;
	char* end = beg + 1;
	while(cl_char_isnum(*end)) end++;
	size_t len = end - beg;

	cl_str_substr(ls->tk_lexeme, beg, len);
	cl_reader_skip(ls->rdr, len - 1);
	ls->tk_num = strtol(ls->tk_lexeme->src, NULL, 10);
}


static void cl_lex_readident(cl_lex_state_t* ls) {
	char* beg = ls->rdr->cur - 1;
	char* end = beg + 1;
	while(cl_char_isident(*end)) ++end;

	size_t len = end - beg;
	cl_str_substr(ls->tk_lexeme, beg, len);
	cl_reader_skip(ls->rdr, len - 1);
}


static void cl_lex_absorbcmt(cl_lex_state_t* ls) {
	char* beg = ls->rdr->cur - 1;
	char* end = beg + 1;
	while(*end != '\n') ++end;
	size_t len = end - beg;
	cl_reader_skip(ls->rdr, len);
}


static void cl_lex_absorbws(cl_lex_state_t* ls) {
	do ls->cur = cl_reader_readbyte(ls->rdr);
	while(cl_char_isws(ls->cur));
	cl_reader_skip(ls->rdr, -1);
	cl_lex_next(ls);
}



/*
*
* Lexical Analyzer
*
*/



cl_lex_state_t* cl_lex_new(char* data) {
	cl_lex_state_t* ls = malloc(sizeof(cl_lex_state_t));
	ls->rdr = cl_reader_new(data);
	ls->tk_lexeme = cl_str_new();
	return ls;
}


void cl_lex_next(cl_lex_state_t* ls) {
	ls->cur = cl_reader_readbyte(ls->rdr);

	switch(ls->cur) {
		case '#':
			ls->tk_type = TK_CMT;
			cl_lex_absorbcmt(ls);
			return;
		case '-':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ls->tk_type = TK_NUM;
			cl_lex_readn(ls);
			return;
		case TK_EOF:
			ls->tk_type = TK_EOF;
			return;
		default:
			if(cl_char_isident(ls->cur)) {
				cl_lex_readident(ls);
				for(size_t i = 0; i < CL_COMMAND_COUNT; ++i)
					if(strcmp(ls->tk_lexeme->src, CL_COMMANDS[i]) == 0) {
						ls->tk_type = TK_PUSH + i;
						return;
					}
				ls->tk_type = TK_IDENT;
				return;
			}
			else if(cl_char_isws(ls->cur)) {
				cl_lex_absorbws(ls);
				return;
			}
			break;
	}

	ls->tk_type = TK_UNX;
}


void cl_lex_close(cl_lex_state_t* ls) {
	cl_reader_close(ls->rdr);
	cl_str_free(ls->tk_lexeme);
	free(ls);
}
