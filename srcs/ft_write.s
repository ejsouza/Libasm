section     .text

    global   ft_write
; ssize_t write(int fd, const void *buf, size_t count);
; ssize_t write(rdi, rsi, rdx);
ft_write:
    mov         rax, 1 ; 1 is the value for system call in linux
 
    ; jmp         check_negative ; could simply ret here but for negative it returns -14
                               ; while the c version from the main return -1
    
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
