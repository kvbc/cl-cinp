all:
	gcc main.c src/lex.c src/prepr.c src/reader.c src/str.c \
		src/vector.c src/vm.c -o cl
