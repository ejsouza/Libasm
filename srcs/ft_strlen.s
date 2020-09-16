; torvalds / linux 64-bit system call numbers :
; https://githut.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl

; The .text section is for the code
section     .text
; global tell the kernel where the program executino begins
global      _ft_strlen

_ft_strlen:
