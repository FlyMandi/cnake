TRUE                equ 1 
FALSE               equ 0 
NULL                equ 0

SW_SHOWDEFAULT      equ 10
CS_HREDRAW          equ 2h
CS_VREDRAW          equ 1h
CW_USEDEFAULT       equ 80000000h

COLOR_BTNSHADOW     equ 16
COLOR_3DSHADOW      equ COLOR_BTNSHADOW

IDI_APPLICATION     equ 32512
IDC_ARROW           equ 32512

WS_OVERLAPPED       equ 0h
WS_CAPTION          equ 0C00000h
WS_SYSMENU          equ 80000h
WS_THICKFRAME       equ 40000h
WS_MINIMIZEBOX      equ 20000h
WS_MAXIMIZEBOX      equ 10000h
WS_OVERLAPPEDWINDOW equ WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX
WS_VISIBLE          equ 10000000h

POINT STRUCT
  x  QWORD ?
  y  QWORD ?
POINT ENDS

WNDMESSAGE STRUCT
    hwnd        QWORD      ?
    message     QWORD      ?
    wParam      QWORD      ?
    lParam      QWORD      ?
    time        QWORD      ?
    pt          POINT      <>
WNDMESSAGE ENDS

WNDCLASSEXA STRUCT
    cbSize          QWORD      ?
    style           QWORD      ?
    lpfnWndProc     QWORD      ?
    cbClsExtra      QWORD      ?
    cbWndExtra      QWORD      ?
    hInstance       QWORD      ?
    hIcon           QWORD      ?
    hCursor         QWORD      ?
    hbrBackground   QWORD      ?
    lpszMenuName    QWORD      ?
    lpszClassName   QWORD      ?
    hIconSm         QWORD      ?
WNDCLASSEXA ENDS

WNDCLASSEXW STRUCT
    cbSize          QWORD      ?
    style           QWORD      ?
    lpfnWndProc     QWORD      ?
    cbClsExtra      QWORD      ?
    cbWndExtra      QWORD      ?
    hInstance       QWORD      ?
    hIcon           QWORD      ?
    hCursor         QWORD      ?
    hbrBackground   QWORD      ?
    lpszMenuName    QWORD      ?
    lpszClassName   QWORD      ?
    hIconSm         QWORD      ?
WNDCLASSEXW ENDS

RECT STRUCT
  left    dd      ?
  top     dd      ?
  right   dd      ?
  bottom  dd      ?
RECT ENDS

PAINTSTRUCT STRUCT
  hdc           QWORD      ?
  fErase        QWORD      ?
  rcPaint       RECT       <>
  fRestore      QWORD      ?
  fIncUpdate    QWORD      ?
  rgbReserved   BYTE 32 dup(?)
PAINTSTRUCT ENDS

IFDEF __UNICODE__
    WNDCLASSEX  equ  <WNDCLASSEXW>
ELSE
    WNDCLASSEX  equ  <WNDCLASSEXA>
ENDIF

ExitProcess PROTO STDCALL :QWORD

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
    GetCommandLine equ <GetCommandLineA>
ENDIF

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
    GetCommandLine equ <GetCommandLineW>
ENDIF

GetModuleHandleA PROTO STDCALL :QWORD
IFNDEF __UNICODE__
    GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetModuleHandleW PROTO STDCALL :QWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

LoadIconA PROTO STDCALL :QWORD,:QWORD
IFNDEF __UNICODE__
  LoadIcon equ <LoadIconA>
ENDIF

LoadIconW PROTO STDCALL :QWORD,:QWORD
IFDEF __UNICODE__
  LoadIcon equ <LoadIconW>
ENDIF

LoadCursorA PROTO STDCALL :QWORD,:QWORD
IFNDEF __UNICODE__
  LoadCursor equ <LoadCursorA>
ENDIF

LoadCursorW PROTO STDCALL :QWORD,:QWORD
IFDEF __UNICODE__
  LoadCursor equ <LoadCursorW>
ENDIF

CreateWindowExA PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IFNDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExA>
ENDIF

CreateWindowExW PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IFDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExW>
ENDIF

GetMessageA PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD
IFNDEF __UNICODE__
  GetMessage equ <GetMessageA>
ENDIF

GetMessageW PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD
IFDEF __UNICODE__
  GetMessage equ <GetMessageW>
ENDIF

TranslateMessage PROTO STDCALL :QWORD

DispatchMessageA PROTO STDCALL :QWORD
IFNDEF __UNICODE__
  DispatchMessage equ <DispatchMessageA>
ENDIF

DispatchMessageW PROTO STDCALL :QWORD
IFDEF __UNICODE__
  DispatchMessage equ <DispatchMessageW>
ENDIF
