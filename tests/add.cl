# add-cmd tests


push 1
push 1
add			# (+a) + (+b)

push -8
push 9
add			# (+a) + (-b) => (+a) - (+b)

push 23
push -2
add			# (-a) + (+b)

push -17
push -5
add			# (-a) + (-b) => (-a) - (+b)


dup
ifeq 24
jump 30
push 97
add
print
jump 21


# If the stack is empty then it assumes that there's an 0
push 32 add print
push 60 add print
push 51 add print
