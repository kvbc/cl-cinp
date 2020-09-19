/*
*
* lex.c
* Lexical Analyzer
*
*/


#include "lex.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/*
*
* Static helper functions
*
*/


static bool cl_lex_isnumc(char c) {
	return c == '-'
	    || c >= '0' && c <= '9';
}


static bool cl_lex_isws(char c) {
	return c == '\n' || c == '\r'
	    || c == '\t' || c == '\f' || c == '\v' || c == ' ';
}


static void cl_lex_nextc(cl_lex_state_t* ls) {
	ls->cur = cl_memreader_readbyte(ls->reader);
	ls->col++;
}


static void cl_lex_skip(cl_lex_state_t* ls, size_t bytes) {
	cl_memreader_skip(ls->reader, bytes);
	ls->col += bytes;
}


static void cl_lex_readn(cl_lex_state_t* ls) {
	++ls->col;
	char* beg = ls->reader->cur - 1;
	char* end = beg + 1;

	while(cl_lex_isnumc(*end)) end++;
	size_t len = end - beg;

	cl_str_substr(ls->tk_lexeme, beg, len);
	cl_lex_skip(ls, len - 1);
}


static void cl_lex_absorbcmt(cl_lex_state_t* ls) {
	char* beg = ls->reader->cur - 1;
	char* end = beg + 1;
	while(*end != '\n') end++;
	size_t len = end - beg;
	cl_lex_skip(ls, len - 1);
}


static bool cl_lex_matches(cl_lex_state_t* ls, char* str) {
	cl_str_t buff = {NULL};
	size_t len = strlen(str);
	cl_str_substr(&buff, ls->reader->cur, len);

	bool eq = strcmp(buff.src, str) == 0;
	if(eq) cl_lex_skip(ls, len);

	free(buff.src);
	return eq;
}


/*
*
* Lexical Analyzer
*
*/


cl_lex_state_t* cl_lex_new(char* data) {
	cl_lex_state_t* ls = malloc(sizeof(cl_lex_state_t));
	ls->reader = cl_memreader_new(data);
	ls->tk_lexeme = cl_str_new();
	ls->line = 1;
	ls->col = 0;
	return ls;
}


void cl_lex_next(cl_lex_state_t* ls) {
	cl_lex_nextc(ls);

	switch(ls->cur) {
		case '\n':
			++ls->line;
			ls->col = 0;
		case ' ': case '\t': case '\f': case '\v': case '\r':
			return cl_lex_next(ls);
		case 'p':
			if(cl_lex_matches(ls, "ush")) ls->tk_type = TK_PUSH;
			else if(cl_lex_matches(ls, "op")) ls->tk_type = TK_POP;
			else if(cl_lex_matches(ls, "rint")) ls->tk_type = TK_PRINT;
			else break;
			return;
		case 'a':
			if(cl_lex_matches(ls, "dd")) ls->tk_type = TK_ADD;
			else break;
			return;
		case 'i':
			if(cl_lex_matches(ls, "feq")) ls->tk_type = TK_IFEQ;
			else break;
			return;
		case 'j':
			if(cl_lex_matches(ls, "ump")) ls->tk_type = TK_JUMP;
			else break;
			return;
		case 'd':
			if(cl_lex_matches(ls, "up")) ls->tk_type = TK_DUP;
			else break;
			return;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ls->tk_type = TK_NUM;
			cl_lex_readn(ls);
			return;
		case TK_EOF:
			ls->tk_type = TK_EOF;
			return;
		case '#':
			ls->tk_type = TK_CMT;
			cl_lex_absorbcmt(ls);
			return;
	}

	ls->tk_type = TK_UNX;
}


void cl_lex_close(cl_lex_state_t* ls) {
	cl_memreader_close(ls->reader);
	cl_str_free(ls->tk_lexeme);
	free(ls);
}
