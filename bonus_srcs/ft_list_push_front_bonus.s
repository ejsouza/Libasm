section        .text
    global      ft_list_push_front
    extern      malloc

ft_list_push_front:
    push        rdi
    push        rsi
    mov         rdi, 16 ; we know it's sexteen because the struct has only two pointers
    call        malloc wrt ..plt
    cmp         rax, 0 ; check if malloc failed
    je          return
    pop         rsi
    pop         rdi
    mov         qword[rax],  rsi ; put data in node
    mov         rdx, qword[rdi] ; head points to new node
    mov         qword[rax + 8], rdx ; new_node->next points to head next
    mov         qword[rdi], rax

return:
    ret