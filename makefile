all:
	gcc main.c src/char.c src/lex.c src/prepr.c src/reader.c \
	src/str.c src/vector.c src/vm.c -o cl
