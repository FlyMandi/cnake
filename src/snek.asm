option casemap :none

include ..\include\snek.inc 
    
includelib kernel32.lib
includelib gdi32.lib    
includelib user32.lib

WinMain PROTO :QWORD, :QWORD, :QWORD, :QWORD
WndProc PROTO :QWORD, :QWORD, :QWORD, :QWORD

WindowWidth     equ 1920
WindowHeight    equ 1080

public MainEntry
    
.data   
    ClassName       byte "SnekWindowClass", 0
    AppName         byte "Snek in ASM!", 0

.data?
    ;TODO: see if you can't mask these and just keep them as DWORDs
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

    ;TODO: rest of WinMain

    mov     wc.cbSize, SIZEOF WNDCLASSEX
    mov     wc.style, CS_HREDRAW or CS_VREDRAW
    mov     wc.lpfnWndProc, OFFSET WndProc
    mov     wc.cbClsExtra, 0
    mov     wc.cbWndExtra, 0

    mov     rax, hInstance
    mov     wc.hInstance, rax
    mov     wc.hbrBackground, COLOR_3DSHADOW+1
    mov     wc.lpszMenuName, NULL
    mov     wc.lpszClassName, OFFSET ClassName

    push    IDI_APPLICATION
    push    NULL
    call    LoadIcon
    mov     wc.hIcon, rax
    mov     wc.hIconSm, rax

    push    IDC_ARROW
    push    NULL
    call    LoadCursor
    mov     wc.hCursor, rax

    push    NULL
    push    hInstance
    push    NULL
    push    NULL
    push    WindowHeight
    push    WindowWidth
    push    CW_USEDEFAULT
    push    CW_USEDEFAULT
    push    WS_OVERLAPPEDWINDOW + WS_VISIBLE
    push    OFFSET AppName
    push    OFFSET ClassName
    push    0
    call    CreateWindowEx
    cmp     rax, NULL
    je      WinMainRet
    mov     hwnd, rax

MessageLoop:
    ;TODO: loop

DoneMessages:
    mov     rax, msg.wParam

WinMainRet:
    ret

WinMain endp
    
;TODO: WndProc would go here

END
