;   Valeria Fonseca Rodriguez B93061
;   Marco Antonio Piedra Venegas A64397
;   José Andrey Pereira Zúñiga C05869
;   Diciembre, 2021

section .data
    align 16
    nueve: dd 9.0, 9.0, 9.0, 0.0

section .text
;   rdi --> vector de rgbx9 (36 float)
;   rsi <-- vector de salida con tres valores rgb (4 float)

global blur
blur:

    vxorps xmm0, xmm0   ;   inicializa los registros en 0
    vxorps xmm1, xmm1

    vmovaps xmm0, [rdi] 
    vmovaps xmm1, [rdi+16]
    vaddps xmm0, xmm1   ;   suma los valores RGB uno por uno

    vmovaps xmm1, [rdi+32]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+48]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+64]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+80]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+96]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+112]
    vaddps xmm0, xmm1

    vmovaps xmm1, [rdi+128]
    vaddps xmm0, xmm1

    vmovaps xmm1, [nueve]   ;   divide el resultado de las sumas entre 9
    vdivps xmm0, xmm1

    movaps [rsi], xmm0

    ret