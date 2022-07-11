global load_idt
load_idt:
    mov eax, [esp + 4]
    lidt [eax]
    ret

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

    iret