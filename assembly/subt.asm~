
;<Program title>

jmp start

;data


;code
start: nop

mvi b, 000Ah
mvi c, 0003h

mov a, b

mvi d, 0000h

back: inr d
sub c
jm end
jz end
jmp back

end: hlt
hlt