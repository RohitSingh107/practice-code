
;<Program title>

jmp start

;data


;code
start: nop

MVI C, 00H;

LXI H, 0002H;

MOV A, M;

INX H;

MOV B, M;



hlt