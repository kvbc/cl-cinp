# cl-cinp

Custom language interpreter written in C. The language was inspired by a [reddit comment](https://stackoverflow.com/questions/6887471/how-would-i-go-about-writing-an-interpreter-in-c). In the future I might add some extra commands and features, like REPL.

&nbsp;
# Syntax

| Command | Parameter | Meaning                               |
| :-----: | :-------: | :-----------------------------------: |
| push    | Number    | Push the number onto the stack        |
| pop     | -         | Pop off the top number on the stack   |
| add     | -         | Pop `a` and `b`. Push `a + b`         |
| ifeq    | Number    | Pop `a`. If `a != 0` jump to line `n` |
| jump    | Number    | Jump to line `n`                      |
| print   | -         | Pop `a` and output it as a character  |
| dup     | -         | Duplicate the top value on the stack  |
| swap    | -         | Swap the top two numbers on the stack |

Comments in this language start with an `#` and go all the way to the end of the line.

&nbsp;
# Examples

Examples can be found in the `examples` directory.
