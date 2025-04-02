TRUE                equ 1 
FALSE               equ 0 
NULL                equ 0

SW_SHOWDEFAULT      equ 10

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

