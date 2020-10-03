# pop/print-cmd tests
# The PRINT command is actually the POP command
# The only difference is that PRINT actually prints the popped value, where POP just discards it


push 108	#l
push 108	#l
push 101	#e
push 72		#H


print		#H
print		#e
print		#l
print		#l


# If the stack is empty then it just assumes that there's an 0
push 48
add
print


# Expected output: Hell0
# Hell
# 48 + 0 => 48 => '0'