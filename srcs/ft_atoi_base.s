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
    xor     rax, rax
    cmp     BYTE[rdi + rcx], 0x2d ; - sign
    je      negative
    cmp     BYTE[rdi + rcx], 0x2b ; + sign
    je      positive
    ; jmp     return

extract_digit:
    ; get number
    cmp       BYTE[rdi + rcx], 0 ; end of number check if number is negative
    je        is_negative
    cmp       BYTE[rdi + rcx], 0x30 ; 0
    jl        is_negative
    movzx     r8, BYTE[rdi + rcx]
    sub       r8, 48 ; 0
    inc       rcx

multiply:
    imul    rax, rsi ; imul (signed interger multiply)
    add     rax, r8
    jmp     extract_digit

negative:
    inc     rcx
    mov     r9, 1 ; set flag to one if number is negative 
    jmp     extract_digit

positive:
    inc     rcx;
    mov     r9, 0 ; set flag to zero if number is positive
    jmp     extract_digit


increment_trim:
    inc     rcx
    jmp     trim

is_negative:
    cmp     r9, 1
    je     negate

return:
    ret

negate:
    neg   rax
    jmp   return

return_zero:
    xor     rax, rax
    ret