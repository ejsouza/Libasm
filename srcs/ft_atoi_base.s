section         .text

    global      ft_atoi_base
; ft_atoi_base(char *str, int base);
; ft_atoi_base(rdi, rsi);
ft_atoi_base:
    cmp     rdi, 0
    je      return_zero
    xor     rcx, rcx

trim:
    cmp     BYTE[rdi + rcx], 0x20 ; space
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0A ; newline
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0D ; carriage return
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x08 ; backspace
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x09 ; horizontal tab
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0C ; form feed
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0B ; vertical tab
    je      increment_trim
    ;jmp    check_sign
    ;jmp     return

check_sign:
    cmp     BYTE[rdi + rcx], 0x2d ; - sign
    je      negative
    cmp     BYTE[rdi + rcx], 0x2b ; + sign
    je      positive
    jmp     return

negative:
    inc     rcx
    mov     rcx, -42 ; to delete, only here for debug
    ; save number as negative
    jmp     return

positive:
    inc     rcx;
    mov     rcx, 42 ; to delete, only here for debug
    ; start parsing number
    jmp     return


increment_trim:
    inc     rcx
    jmp     trim

return:
    mov     rax, rcx
    ret

return_zero:
    xor     rax, rax
    ret