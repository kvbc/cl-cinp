# push-cmd tests


push1		# positive integer just after the command
push-1		# negative integer just after the command

push 2		# whitespace ignored
push -2		# whitespace ignored

push






3			# whitespace ignored
push






-3			# whitespace ignored

push-		# it is a bug, but it's a very nice typedef for 0
push -
push

-


push 48 add print
push 48 add print
push 48 add print

dup
ifeq 41
jump 55		# end
push 48
add
print
jump 38


# Expected output: 000-3.2/1
# 000 => the 3 zeros
# -   => 48 + (-3) = 45 = '-'
# 3   => 48 + 3    = 51 = '3'
# .   => 48 + (-2) = 46 = '.'
# 2   => 48 + 2    = 50 = '2'
# /   => 48 + (-1) = 47 = '/'
# 1   => 48 + 1    = 49 = '1'
