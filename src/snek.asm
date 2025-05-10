option casemap :none

include ..\include\OS.inc 
include ..\include\window.inc
    
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
    lea     rbx, WndProc
    mov     wc.lpfnWndProc, rbx
    mov     wc.cbClsExtra, 0
    mov     wc.cbWndExtra, 0

    mov     rax, hInstance
    mov     wc.hInstance, rax
    mov     wc.hbrBackground, COLOR_3DSHADOW+1
    mov     wc.lpszMenuName, NULL
    lea     rbx, ClassName
    mov     wc.lpszClassName, rbx

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
    lea     rbx, AppName                        
    push    rbx                                 
    lea     rbx, ClassName                      
    push    rbx
    push    0
    call    CreateWindowEx
    cmp     rax, NULL
    je      WinMainRet
    mov     hwnd, rax

MessageLoop:
    push    0
    push    0
    push    NULL
    lea     rax, msg
    push    rax
    call    GetMessage

    cmp     rax, 0
    je      DoneMessages

    lea     rax, msg
    push    rax
    call    TranslateMessage

    lea     rax, msg
    push    rax
    call    DispatchMessage
    
    jmp     MessageLoop

DoneMessages:
    mov     rax, msg.wParam

WinMainRet:
    ret

WinMain endp

WndProc proc hWnd:QWORD, uMsg:QWORD, wParam:QWORD, lParam:QWORD

    LOCAL   ps:PAINTSTRUCT
    LOCAL   rect:RECT
    LOCAL   hdc:QWORD

    cmp     uMsg, WM_DESTROY
    jne     NotWMDestroy 

    push    NULL
    call    PostQuitMessage
    xor     rax, rax
    ret

NotWMDestroy:
    cmp     uMsg, WM_PAINT
    jne     NotWMPaint
    
    lea     rax, ps
    push    rax
    push    hWnd
    call    BeginPaint
    mov     hdc, rax

    push    TRANSPARENT
    push    hdc
    call    SetBkMode

    lea     rax, rect
    push    rax
    push    hWnd
    call    GetClientRect

    ;text rendering example
    push    DT_SINGLELINE + DT_CENTER + DT_VCENTER
    lea     rax, rect
    push    rax
    push    -1
    lea     rbx, AppName
    push    rbx
    push    hdc
    call    DrawText

    lea     rax, ps 
    push    rax
    push    hWnd
    call    EndPaint

    xor     rax, rax
    ret

NotWMPaint:

;TODO:

WndProc endp

END
