section .text
    global BitOpsU32_asm
BitOpsU32_asm:
    and eax, DWORD [esp+0x3c]
    or eax, DWORD [esp+0x38]
    xor eax, DWORD [esp+0x34]
    not eax
    ret

; eax = a
; DWORD [esp+0x3c] = b
; DWORD [esp+0x38] = c
; DWORD [esp+0x34] = d