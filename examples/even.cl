# even.cl
# Determine if a given POSITIVE INTEGER is even
# Very unefficient way since there's no other one


push 1234	#positive integer
dup



dup
ifeq 15
jump 35		#yes

push -2
add

swap
push -1
add

dup
ifeq 31

push 111	#o
push 110	#n
print
print
jump 41		#end

swap
dup
ifeq 15

push 115	#s
push 101	#e
push 121	#y
print
print
print
