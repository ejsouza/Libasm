section         .text

        global  ft_strdup
        extern  malloc

; char *strdup(const char *s);
; char *strdup(rdi);
ft_strdup:
    xor     rcx, rcx
    cmp     rdi, 0x0 ; check for NULL
    je      null_param

str_len:
    cmp     BYTE[rdi + rcx], 0
    je      malloc_str
    inc     rcx
    jmp     str_len

malloc_str:
    push    rdi ; save parameter
    inc     rcx ; for the null terminating
    mov     rdi, rcx ; put rcx (len of string) in the parameter for malloc
    call    malloc wrt ..plt ; help found in stackoverflow
                             ; https://stackoverflow.com/questions/28699032/assembly-coding-strdup-malloc-calling-in-shared-library
    pop     rdi
    cmp     rax, 0x0 ; rax pointes to the new momory returned by malloc, check for NULL
    je      null_param ; mallo failed
    xor     rcx, rcx ; set index to 0

str_cpy:
   mov     dl, BYTE[rdi + rcx]
   mov     BYTE[rax + rcx], dl
   cmp     dl, 0
   je      return
   inc     rcx
   jmp     str_cpy

return:
    ret

null_param:
    mov     rax, 0x0
    ret


