;   Valeria Fonseca Rodriguez B93061
;   Marco Antonio Piedra Venegas A64397
;   José Andrey Pereira Zúñiga C05869
;   Diciembre, 2021

section .data
    align 16
    mascara: dd 0xFF, 0xFF, 0xFF, 0x0

section .text
;   rdi --> valores RGB del pixel
;   rsi <-- valores en negativo

global negativo
negativo:
    vxorps xmm0, xmm0   ;   inicializa los registros en 0
    vxorps xmm1, xmm1

    vmovaps xmm0, [rdi] ;   valor RGB
    vmovaps xmm1, [mascara] ;   mascara de valores negativos

    vxorps xmm0, xmm1   ;   aplica mascara
    movaps [rsi], xmm0 

    ret