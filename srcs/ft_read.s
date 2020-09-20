section         .text

    global      ft_read
; ssize_t read(int fd, void *buf, size_t count);
; ssize_t read(rdi, rsi, rdx);
ft_read:
    mov     rax, 0 ; syscall number
check_negative:
    test        rdx, rdx
    js          negative ; The js (or jne) jumps if the previous instructions sets the Sign Flag (SF)
    bt          rdi, 31  ;  check if last bit is set, what means is negative
    jc          negative ; jc is a jump if confidtion is met  
    cmp         rsi, 0x0 ; check for NULL pointer
    je          negative
    syscall
    
exit:
    ret
negative:
    mov         rax, -1
    ret