global update_registers
global get_fpu_sw
global get_fpu_cw
extern handle_registers_request

update_registers:
    push ss
    push 0 ; esp
    pushfd
    push cs
    push 0 ; eip

    ; int_no, err_code
    push dword 0
    push dword 0

    ; Store general purpose
    pushad

    ; Store segments
    push ds
    push es
    push fs
    push gs

    ; Push stack pointer
    push esp
    ; Call handler
    call handle_registers_request
    ; Set stack pointer to returned value
    mov esp, eax
    ; Restore esp
    add esp, 76

    ret

get_fpu_sw:
    xor eax, eax
    fnstsw ax
    ret

get_fpu_cw:
    sub esp, 4
    fnstcw [esp]
    mov eax, [esp]
    add esp, 4

    ret
