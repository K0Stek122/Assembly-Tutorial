section .data ;We are moving more and more into Assembly alone, so we are starting to define the variables in assembly as well.
    global var_shl ;global will allow us to use this with extern "C" in C++.
    var_shl dq 0
    global var_shr
    var_shr dq 0

section .text
    global ShiftU32_asm

ShiftU32_asm:
    cmp DWORD [esp+0x3c], 32 ;is count >= 32
    jae BadCnt

    mov eax, DWORD [esp+0xc] ;eax = a
    mov ecx, DWORD [esp+0x3c] ; ecx = count

    shl eax, cl ;shift eax by ecx, WE USE CL because we only can use the bottom 8 bits of the ECX register. We canno shift by more than 32. This makes sure that we won't get vulnerable code.
    mov [var_shl], eax ;think of rdi like the output.

    mov eax, DWORD [esp+0xc] ;Reset the eax register so that eax = a 

    shr eax, cl ;Right shift
    mov [var_shr], eax

    mov eax, 1 ;Valid shift count return code. This line ensures that the return will not throw an exception.
    ret

BadCnt:
    xor eax, eax
    ret

; DWORD [esp+0xc] = a
; DWORD [esp+0x3c] = count