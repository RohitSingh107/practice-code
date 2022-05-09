
;<Program title>

jmp start

;data


;code
start: nop

MVI A, 38H;

MVI B, 45H;

ADD B;

DAA;

hlt