# dup-cmd tests


push 8
dup
push 7
dup


dup
ifeq 13
jump 17
push 97
add
print
jump 10


# Expected output: hhii
