; torvalds / linux 64-bit system call numbers :
; https://githut.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl

; The .text section is for the code
section .text
; global tell the kernel where the program execution begins
    global      ft_strlen
; size_t strlen(const char *s);
ft_strlen:
        mov     rax, 0 ; set index to 0

loop:
        cmp     BYTE [rdi + rax], 0
        je      return
        inc     rax
        jmp     loop
return:
        ret ; return the value contained in rax
   