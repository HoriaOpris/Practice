%define CALL_KERNEL 0x80
%define STDOUT 1
%define SYS_WRITE 4
%define SYS_EXIT 1

segment	.data
ten db 48
newL db " ", 0xA, 0xD   ;db is define byte. 

msg1 db "My result: "
len1 equ $- msg1        ; equ creates a constant

segment	.text
   global _start        ;must be declared for linker (ld)
	
_start:	                ;tells linker entry point
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int	CALL_KERNEL      ;call kernel    

    mov	eax, SYS_WRITE   ;system call number (sys_write)
    mov	ebx, STDOUT      ;file descriptor (stdout)

    mov ecx, [ten]
    add ecx, 2
    mov [ten], ecx

    mov	ecx, ten         ;message to write
    mov	edx, 1           ;message length
    int	CALL_KERNEL      ;call kernel

;exit
    ; print new line
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, newL
    mov edx, 2
    int CALL_KERNEL

    mov	eax, SYS_EXIT    ;system call number (sys_exit)
    int	CALL_KERNEL      ;call kernel