# jump/ifeq-cmd tests
# The IFEQ command is similiar the JUMP command
# The only difference is that IFEQ jumps to a line when the popped value is not 0, where JUMP just jumps to it


# Testing for non-zero positive integer
push 1
ifeq 11
push 48 print
jump 12
push 49 print


# Testing for zero
push 0
ifeq 19
push 48 print
jump 20
push 49 print


# If the stack is empty, should assume there's an zero
ifeq 26
push 48 print
jump 27
push 49 print


# Expected output: 100