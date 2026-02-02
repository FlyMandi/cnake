option casemap :none

include ..\include\snek.inc 
    
includelib kernel32.lib
includelib gdi32.lib    
includelib user32.lib

WinMain proto :QWORD, :QWORD, :QWORD, :QWORD

WindowWidth     equ 1920
WindowHeight    equ 1080

public MainEntry
    
.data   
    ClassName       byte "SnekWinClass", 0
    AppName         byte "Snek", 0

.data?
    hInstance       QWORD       ?
    CommandLine     QWORD       ?

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

    ;TODO: check for minimized, maximized flags?

WinMain proc hInst:QWORD, hPrevInst:QWORD, CmdLine:QWORD, CmdShow:QWORD

    LOCAL   wc:WNDCLASSEX
    LOCAL   msg:WNDMESSAGE
    LOCAL   hwnd:QWORD

    ;rest of WinMain

MessageLoop:

    ;loop

DoneMessages:

    mov     rax, msg.wParam

WinMainRet:

    ret

WinMain endp
    
;WndProc would go here

END
