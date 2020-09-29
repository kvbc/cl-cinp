

#include "char.h"


bool cl_char_isnum(char c) {
	return c == '-'
		|| c >= '0' && c <= '9';
}


bool cl_char_isws(char c) {
	return c == '\n' || c == '\r'
		|| c == '\t' || c == '\f' || c == '\v' || c == ' ';
}


bool cl_char_islb(char c) {
	return c == '\n'
		|| c == '\r';
}


bool cl_char_isident(char c) {
	return c == '_'
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z');
}
