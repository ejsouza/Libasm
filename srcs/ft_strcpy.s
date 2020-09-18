; https://en.wikibooks.org/wiki/X86_Assembly/X86_Archictecture
section .text
    global      ft_strcpy
;char *strcpy(char *dest, const char *src);    
ft_strcpy:
    mov         rcx, 0 ; rcx 64-bit counter register
; Parameter in order:     rdi, rsi, rdx, rcx, r8, r9
; Return values in order: rax, rdx
; strcpy(rdi, rsi) return (rax);
loop:
    mov     dh, BYTE[rsi + rcx] ; dh or dl 8-bit data register (enough here to hold one char)
    mov     BYTE[rdi + rcx], dh
    cmp     BYTE[rsi + rcx], 0
    je      return
    inc     rcx
    jmp     loop

return:
    mov     rax, rdi ; set return to point to the start of first parameter
    ret     