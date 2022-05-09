
;<Program title>

jmp start

;data


;code
start: nop

MVI C, 00H;

LDA 0005H;

MOV B, A;

LDA 0006H;

ADD B;

JNC skip
INR C;

skip: STA 0007H;

MOV A, C;

STA 0008H;

hlt