; torvalds / linux 64-bit system call numbers :
; https://githut.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl

; The .text section is for the code
section .text
; global tell the kernel where the program execution begins
    global      ft_strlen
; size_t strlen(const char *s);
ft_strlen:
        xor     rax, rax ; set index to 0 - clear register
        ; This is the fastest possible way to set register to 0
        ; https://stackoverflow.com/questions/4749585/what-is-the-meaning-of-xor-in-x86-assembly
        ; A B | A xor B       * let's say rax := 42
        ; 0 0 | 0             *     101010
        ; 1 0 | 1             * xor 101010
        ; 0 1 | 1             *     000000
        ; 1 1 | 0             *
loop:
        ; You can access an individual byte from memory with the syntax BYTE[address]
        cmp     BYTE [rdi + rax], 0
        je      return
        inc     rax
        jmp     loop
return:
        ret ; return the value contained in rax
   