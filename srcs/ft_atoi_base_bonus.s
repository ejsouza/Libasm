section         .text

    global      ft_atoi_base
; ft_atoi_base(char *str, int base);
; ft_atoi_base(rdi, rsi);
ft_atoi_base:
    cmp     rdi, 0 ; check if string is
    je      return_zero
    cmp     rsi, 0 ; base is equal to zero
    je      return_zero
    xor     rcx, rcx ; index for string
    xor     r10, r10 ; index for base
    xor     r12, r12 ; store base value
    xor     rax, rax




trim_base:
    cmp     BYTE[rsi + r10], 0x20 ; space
    je      increment_trim_base
    cmp     BYTE[rsi + r10], 0x0A ; newline
    je      increment_trim_base
    cmp     BYTE[rsi + r10], 0x0D ; carriage return
    je      increment_trim_base
    cmp     BYTE[rsi + r10], 0x09 ; horizontal tab
    je      increment_trim_base
    cmp     BYTE[rsi + r10], 0x0C ; form feed
    je      increment_trim_base
    cmp     BYTE[rsi + r10], 0x0B ; vertical tab
    je      increment_trim_base

bad_character:
    cmp     BYTE[rsi + r10], 0
    je      return_zero
    cmp     BYTE[rsi + r10], 48 ; - negative base, return 0
    jle     return_zero
    cmp     BYTE[rsi + r10], 58 ; - positive sign, return 0
    jge     return_zero

extract_base:
    cmp     BYTE[rsi + r10], 0
    je      trim
    movzx   r11, BYTE[rsi + r10]
    sub     r11, 48
    jmp     multiply_base

trim:
    cmp     BYTE[rdi + rcx], 0x20 ; space
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0A ; newline
    je      increment_trim
    cmp     BYTE[rdi + rcx], 0x0D ; carriage return
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
    ; jmp     return

extract_digit:
    ; get number
    cmp       BYTE[rdi + rcx], 0 ; end of number check if number is negative
    je        is_negative
    cmp       BYTE[rdi + rcx], 0x30 ; 0
    jl        is_negative ; here it will jump if unit is less than 0 in the ascii table
    movzx     r8, BYTE[rdi + rcx]
    ; sub       r8, 48 ; 0
    inc       rcx

is_char:
    cmp     r8, 96
    jg      lower
    cmp     r8, 64
    jg      upper
    cmp     r8, 47
    jg      numeric
    jmp     is_negative

lower:
    cmp     r8, 102
    jg      is_negative
    sub     r8, 97
    add     r8, 10
    cmp     r8, r12 ; if number extracted greater than base stop
    jge     is_negative
    jmp     multiply

upper:
    cmp     r8, 70
    jg      is_negative
    sub     r8, 65
    add     r8, 10
    cmp     r8, r12 ; if number extracted greater than base stop
    jge     is_negative
    jmp     multiply

numeric:
    cmp     r8, 57
    jg      is_negative
    sub     r8, 48
    cmp     r8, r12
    jge     is_negative

multiply:
    imul    rax, r12 ; r12 is the base imul (signed interger multiply)
    add     rax, r8
    jmp     extract_digit
    

multiply_base:
    imul   r12, 10 ; 10 because we are looking for 1 - 16
    add    r12, r11
    cmp    r12, 16
    jg     return_zero ; base cannot be greater than 16
    inc    r10
    jmp    extract_base

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

increment_trim_base:
    inc     r10
    jmp     trim_base

is_negative:
    cmp     r9, 1
    je     negate

return:
    ; cmp    rax, 0x7CE66C50E283FFFF
    ; jg     minus_one
    ret

minus_one:
    mov    rax, -1
    ret
    
negate:
    neg   rax
    jmp   return

return_zero:
    xor     rax, rax
    ret