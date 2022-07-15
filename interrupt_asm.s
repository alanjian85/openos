%macro no_error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
    push dword 0
    push dword %1
    jmp common_interrupt_handler
%endmacro

%macro error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
    push dword %1
    jmp common_interrupt_handler
%endmacro

extern interrupt_handler

common_interrupt_handler:
    cli

    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi
    push ebp

    call interrupt_handler

    pop ebp
    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    pop eax

    add esp, 8
    sti

    iret

no_error_code_interrupt_handler 33

global enable_interrupt
enable_interrupt:
    sti
    ret