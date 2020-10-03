section             .text
    global          ft_list_remove_if
    extern          free

ft_list_remove_if:
    push        rbp
    mov         rbp, rsp
    sub         rsp,0x40
    cmp         rdi, 0x0
    je          return
    cmp         rsi, 0x0
    je          return
    cmp         rdx, 0x0
    je          return 
    mov         qword[rbp-0x8],rdi ; first parameter (**begin)
    mov         qword[rbp-0x10],rsi ; second parameter (*data)
    mov         qword[rbp-0x18],rdx ; third parameter (strcmp())
    mov         rax,qword[rbp-0x8] ; set rax to point to (*begin)
    mov         rax,qword[rax] ; next
    mov         qword[rbp-0x20],rax ; save next to [rbp-0x20]
    mov         rax,qword[rbp-0x18] ; put address of strcmp() in rax
    mov         rdi,qword[rbp-0x10] ; set  rdi = (*data), rdi will be first parameter to strcmp()
    mov         rcx,qword[rbp-0x20] ; put curr->next->data in rcx
    mov         rsi,qword[rcx] ; move rcx to the second parameter passed to strcmp()
    mov         qword[rbp-0x38],rax ; put addres strcmp to [rbp-0x30]
    mov         al,0x0 ; align memorey - set last bit of rax to 0
    mov         rcx,qword[rbp-0x38] ; put function address to be called in rcx
    call        rcx
    cmp         eax,0x0 ; eax contains return of strcmp
    jne         increment_outer_loop ; first node in list is no the target, proceed
    mov         rax,qword[rbp-0x20] ; set rax to curr->next
    cmp         qword[rax+0x8],0x0 ; check if there's only one node in the list
    je          free_unique_node ; free the only node in the linked list and return
    mov         rax,qword[rbp-0x20] ; curr
    mov         rax,qword[rax+0x8] ; curr->next
    mov         rcx,qword[rbp-0x8]
    mov         qword[rcx],rax

free_unique_node:
    mov         rax,qword[rbp-0x20]
    mov         rdi,qword[rax]
    call        free wrt ..plt ; free data
    mov         rax,qword[rbp-0x20]
    mov         rdi,rax
    call        free wrt ..plt
    jmp         return

increment_outer_loop:
    mov         rax,qword[rbp-0x20] ; curr = curr-next
    cmp         qword[rax+0x8],0x0 ; check if after incrementing curr curr->next not null
    je          return
    mov         rax,qword[rbp-0x18]
    mov         rdi,qword[rbp-0x10]
    mov         rcx,qword[rbp-0x20]
    mov         rcx,qword[rcx+0x8]
    mov         rsi,qword[rcx]
    mov         qword[rbp-0x40],rax
    mov         al,0x0
    mov         rcx,qword[rbp-0x40]
    call        rcx
    cmp         eax,0x0
    jne         curr_to_next_node
    mov         rax,qword[rbp-0x20]
    mov         rax,qword[rax+0x8]
    mov         qword[rbp-0x30],rax
    mov         rax,qword[rbp-0x30]
    mov         rax,qword[rax+0x8]
    mov         qword[rbp-0x28],rax
    cmp         qword[rbp-0x28],0x0
    jne         free_node_in_between
    mov         rax,qword[rbp-0x20] ; free last node in the list
    mov         qword[rax+0x8],0x0
    mov         rax,qword[rbp-0x30]
    mov         rdi,qword[rax]
    call        free wrt ..plt
    mov         rax,qword[rbp-0x30]
    mov         rdi,rax
    call        free wrt ..plt
    jmp         return

free_node_in_between:
    mov         rax,qword[rbp-0x28]
    mov         rcx,qword[rbp-0x20]
    mov         qword[rcx+0x8],rax
    mov         rax,qword[rbp-0x30]
    mov         rdi,qword[rax]
    call        free wrt ..plt
    mov         rax,qword[rbp-0x30]
    mov         rdi,rax
    call        free wrt ..plt
    jmp         return

curr_to_next_node:
    mov         rax,qword[rbp-0x20]
    mov         rax,qword[rax+0x8]
    mov         qword[rbp-0x20],rax
    jmp         increment_outer_loop 

return:
    add         rsp, 0x40
    pop         rbp
    ret