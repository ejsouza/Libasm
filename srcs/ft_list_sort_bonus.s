section         .text
    global      ft_list_sort
	; ft_list_sort(t_list **begin_list, int (*cmp)());
	; ft_list_sort(rdi, rsi) return (eax)
	; parameter order: rdi, rsi, rdx, rcx, r8, r9

ft_list_sort:
	push	rbp					 ; function prologue
	mov		rbp, rsp			 ; set base pointer to stack pointer
	sub		rsp,0x30			 ; set zone to work with
	cmp		rdi, 0x0
	je		return
	cmp		rsi, 0x0
	je		return

	mov		qword[rbp-0x8], rdi  ; save (*node) address
	mov		qword[rbp-0x10], rsi ; save function address
	mov		rax, qword[rbp-0x8]  ; rax(curr) points to the head of the list (*node)
	mov		rax, qword[rax] 	 ; increment rax: curr = curr->next
	mov		qword[rbp-0x18], rax ; (rbp-0x18 = curr-next)

outer_loop:
	mov		rax, qword[rbp-0x18] ; next = curr->next
	cmp		qword[rax+0x8], 0x0  ; if curr = NULL return
	je		return
	mov		rax, qword[rbp-0x18] ; rax = next
	mov		rax, qword[rax+0x8]  ; rax = curr, next = next-next
	mov		qword[rbp-0x20], rax ; save curr to [rbp-0x20]

check_curr:
	cmp		qword[rbp-0x20], 0x0 ; check if at the end of inner loop
	je		increment_outer_loop

	mov		rax,qword[rbp-0x10]  ; rax contains address of function passed in argument
	mov	    	rcx,qword [rbp-0x18] ; put curr into rcx (rbp-0x18 contains curr)
	mov   	 	rdi,qword[rcx]       ; put rcx in rdi (rdi = first parameter for strcmp(rdi, rsi))
	mov    		rcx,qword[rbp-0x20]  ; put next in rcx (rbp-0x20 contains next)
	mov    		rsi,qword[rcx]
	mov    		qword [rbp-0x30],rax ; save strcmp() address to [rbp-0x30]
	mov		rcx, qword[rbp-0x30] ; load address of stcmp to rcx
	call		rcx 	             ; call strcmp
	cmp		eax, 0x0	     ; check if curr->data is less or equal to next->data, if currente is less or equal no need to swap
	jle		increment_inner_loop ; if curr less or equal do not swap
	mov		rax, qword[rbp-0x18] ; swap
	mov		rax, qword[rax]
	mov		qword[rbp-0x28], rax
	mov		rax, qword[rbp-0x20]
	mov		rax, qword[rax]
	mov		rcx, qword[rbp-0x18]
	mov		qword[rcx], rax
	mov		rax, qword[rbp-0x28]
	mov		rcx, qword[rbp-0x20]
	mov		qword[rcx], rax

increment_inner_loop:
	mov		rax, qword[rbp-0x20] ; rax = next
	mov		rax, qword[rax+0x8]  ; next = next->next
	mov		qword[rbp-0x20], rax ; set curr (curr is saved at [rbp-0x20]) to next-next
	jmp		check_curr

increment_outer_loop:
	mov		rax, qword[rbp-0x18] ; rax = curr
	mov		rax, qword[rax+0x8]  ; curr = curr->next
	mov		qword[rbp-0x18], rax ; update curr that is saved in [rbp-0x18]
	jmp		outer_loop 	     ; start over again

return:
	add		rsp, 0x30	     ; restore memoore
	pop		rbp
	ret
