section .text

    global      ft_strcmp
    ; int strcmp(rdi, rsi);
    ft_strcmp:
        xor     rcx, rcx
    loop:
        mov     dl, BYTE[rdi + rcx]
        cmp     dl, BYTE[rsi + rcx]
        je      increment_or_end ; jump if rdi = rsi
        jl      less
        jg      greater

    increment_or_end:
        cmp     dl, 0 ; as rdi is equal rsi, if equal to 0 end of string
        je      end   ; so they are equal, jump to end
        inc     rcx   ; otherwise increment counter (rcx)
        jmp     loop  ; start over again

    less:
        mov     rax, -1
        ret

    greater:
        mov     rax, 1
        ret

    end:
        xor     rax, rax
        ret
       
