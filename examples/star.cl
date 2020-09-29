# star.cl
# Creates a star for you ^_^
# An useless but interesting example of a "function"


jump 24      # skip the func



# 11: func print_chars(char, count != 0)
push -1
add
swap
dup
print
swap
dup
ifeq 11
pop
pop



ifeq 30
push 1
push 32
push 1
jump 10      # print_chars(' ', 1)

ifeq 38
push 1		 dup
push 42
push 1
jump 10      # print_chars('*', 1)



ifeq 46
push 1		 dup dup
push 10
push 1
jump 10      # print_chars('\n', 1)



ifeq 54
push 1		 dup dup dup
push 42
push 3
jump 10      # print_chars('*', 3)



ifeq 62
push 1		 dup dup dup dup
push 10
push 1
jump 10      # print_chars('\n', 1)



ifeq 68
push 1		 dup dup dup dup dup
push 32
push 1
jump 10      # print_chars(' ', 1)

ifeq 73
push 1		 dup dup dup dup dup dup
push 42
push 1
jump 10      # print_chars('*', 1)
