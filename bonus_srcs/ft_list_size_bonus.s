section         .text
    global      ft_list_size
; int ft_list_size(rdi)
ft_list_size:
    xor         rax, rax ; initializate return
    mov         rsi, rdi
    cmp         rsi, 0 ; check for null
    je          return

loop:
    mov         rsi, qword[rsi + 8]
    inc         rax
    cmp         rsi, 0
    jne         loop

return:
    ret
