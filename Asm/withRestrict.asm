%define CALL_KERNEL 0x80
%define STDOUT 1
%define SYS_WRITE 4
%define SYS_EXIT 1

segment	.data
x dd 1
y dd 2
z dd 3

newL db " ", 0xA, 0xD   ;db is define byte. 

msg1 db "Addition: "
len1 equ $- msg1        ; equ creates a constant

segment	.text
   global _start        ;must be declared for linker (ld)
	
_start:	                ;tells linker entry point
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int	CALL_KERNEL     ;call kernel    


    ;Add 2 to a number
        ;put the value of the variable on the stack
        push z
        push y
        push z
        call add_to_2
        pop ebx
        pop ebx
        pop ebx

        ;mov [x], eax
    ;ascii
    mov eax, 48
    add [x], eax
    add [y], eax
    add [z], eax

    ;print x,y,z
    mov ecx, x
    mov	edx, 1           ;message length
    mov	eax, SYS_WRITE   ;system call number (sys_write)
    mov	ebx, STDOUT      ;file descriptor (stdout)
    int	CALL_KERNEL     ;call kernel

    mov ecx, y
    mov	edx, 1           ;message length
    mov	eax, SYS_WRITE   ;system call number (sys_write)
    mov	ebx, STDOUT      ;file descriptor (stdout)
    int	CALL_KERNEL     ;call kernel

    mov ecx, z
    mov	edx, 1           ;message length
    mov	eax, SYS_WRITE   ;system call number (sys_write)
    mov	ebx, STDOUT      ;file descriptor (stdout)
    int	CALL_KERNEL     ;call kernel

;exit
    ; print new line
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, newL
    mov edx, 2
    int CALL_KERNEL

    mov	eax, SYS_EXIT    ;system call number (sys_exit)
    int	CALL_KERNEL     ;call kernel

;functions
;add function
; return value is always in eax
; it has 2 parameters: a, b
; returns a + b
add_f:
    mov ebx, [esp + 4]  ;get pointer to a
    mov eax, [ebx]      ;get value of a
    mov ebx, [esp + 8]  ;get pointer to b
    add eax, [ebx]

    ;ascii
    add eax, 48

    ret
;3 parameters: *a, *b, *c
; *a += *c
; *b += *c
;  no return 
add_to_2:
    mov eax, [esp + 4]  ;get a
    mov ebx, [esp + 8]  ;get b
    mov ecx, [esp + 12] ;get c
    mov ecx, [ecx]      ;get c

    add [eax], ecx      ; *a += *c
    add [ebx], ecx      ; *b += *c

    ret

;nasm -f elf add.asm
;ld -m elf_i386 -s -o add add.