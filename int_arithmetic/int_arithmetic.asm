section .text
    global AddSubI32_a
AddSubI32_a:
    add eax, ecx ; eax = a + b
    add edx, DWORD [esp+0x34] ; edx = c + d
    sub eax, edx ; (a + b) - (c + d)
    add eax, 7   ; + 7

    ret

; eax = a
; ecx = b
; edx = c