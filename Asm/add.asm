%define CALL_KERNEL 0x80
%define STDOUT 1
%define SYS_WRITE 4
%define SYS_EXIT 1

segment	.data
a dd 3
b dd 6
c dd 0
x dd 4
y dd 1

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

    ;add 2 numbers and output them
    mov eax, x
    mov ebx, y

    push x
    push y
    call add_f

    pop ebx
    pop ebx

    mov ecx, c
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
add_f:
    ;mov eax, [esp + 3]
    ;mov ebx, [esp + 4]
    ;add eax, ebx

    mov eax, [esp + 12]

    add eax, '0' ;ascii rep
    mov [c], eax   
    ret