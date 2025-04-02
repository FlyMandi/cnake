    extern printf: PROC

    include ..\include\snek.inc 
        
    includelib kernel32.lib
    includelib gdi32.lib    
    includelib user32.lib

    WinMain proto :DWORD, :DWORD, :DWORD                    ;

    WindowWidth     equ 1920
    WindowHeight    equ 1080
    
.data   
    ClassName       byte "SnekWinClass", 0
    AppName         byte "Snek", 0

.data?
    hInstance       HINSTANCE ?
    CommandLine     LPSTR ?

.code

MainEntry:
    mov     rcx, NULL
    call    GetModuleHandle
    mov     hInstance, rax

    call    GetCommandLine
    mov     CommandLine, rax    

    push    SW_SHOWDEFAULT
    lea     rax, CommandLine
    push    rax
    push    NULL
    push    hInstance
    call    WinMain

    push    rax
    call    ExitProcess

    ret

end
