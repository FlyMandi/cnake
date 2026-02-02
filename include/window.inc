WS_OVERLAPPED       equ 0h
WS_CAPTION          equ 0C00000h
WS_SYSMENU          equ 80000h
WS_THICKFRAME       equ 40000h
WS_MINIMIZEBOX      equ 20000h
WS_MAXIMIZEBOX      equ 10000h
WS_OVERLAPPEDWINDOW equ WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX
WS_VISIBLE          equ 10000000h

WM_NULL             equ 0h
WM_CREATE           equ 1h
WM_DESTROY          equ 2h
WM_MOVE             equ 3h
WM_SIZE             equ 5h
WM_ACTIVATE         equ 6h
WA_INACTIVE         equ 0
WA_ACTIVE           equ 1
WA_CLICKACTIVE      equ 2
WM_SETFOCUS         equ 7h
WM_KILLFOCUS        equ 08h
WM_ENABLE           equ 0Ah
WM_SETREDRAW        equ 0Bh
WM_SETTEXT          equ 0Ch
WM_GETTEXT          equ 0Dh
WM_PAINT            equ 0Fh
WM_CLOSE            equ 10h
WM_QUIT             equ 12h
WM_ERASEBKGND       equ 14h
WM_ENDSESSION       equ 16h
WM_SHOWWINDOW       equ 18h

TRANSPARENT         equ 1
DT_TOP              equ 0h
DT_LEFT             equ 0h
DT_CENTER           equ 1h
DT_RIGHT            equ 2h
DT_VCENTER          equ 4h
DT_BOTTOM           equ 8h
DT_SINGLELINE       equ 20h

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

STARTUPINFOA STRUCT
  cb              DWORD ?
  lpReserved      DWORD ?
  lpDesktop       DWORD ?
  lpTitle         DWORD ?
  dwX             DWORD ?
  dwY             DWORD ?
  dwXSize         DWORD ?
  dwYSize         DWORD ?
  dwXCountChars   DWORD ?
  dwYCountChars   DWORD ?
  dwFillAttribute DWORD ?
  dwFlags         DWORD ?
  wShowWindow     WORD ?
  cbReserved2     WORD ?
  lpReserved2     DWORD ?
  hStdInput       DWORD ?
  hStdOutput      DWORD ?
  hStdError       DWORD ?
STARTUPINFOA ENDS

STARTUPINFOW STRUCT
  cb              DWORD ?
  lpReserved      DWORD ?
  lpDesktop       DWORD ?
  lpTitle         DWORD ?
  dwX             DWORD ?
  dwY             DWORD ?
  dwXSize         DWORD ?
  dwYSize         DWORD ?
  dwXCountChars   DWORD ?
  dwYCountChars   DWORD ?
  dwFillAttribute DWORD ?
  dwFlags         DWORD ?
  wShowWindow     WORD ?
  cbReserved2     WORD ?
  lpReserved2     DWORD ?
  hStdInput       DWORD ?
  hStdOutput      DWORD ?
  hStdError       DWORD ?
STARTUPINFOW ENDS

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

PostQuitMessage PROTO STDCALL :QWORD
BeginPaint PROTO STDCALL :QWORD,:QWORD
SetBkMode PROTO STDCALL :QWORD,:QWORD
GetClientRect PROTO STDCALL :QWORD,:QWORD
EndPaint PROTO STDCALL :QWORD,:QWORD

DrawTextA PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IFNDEF __UNICODE__
  DrawText equ <DrawTextA>
ENDIF

DrawTextW PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
IFDEF __UNICODE__
  DrawText equ <DrawTextW>
ENDIF

DefWindowProcA PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD
IFNDEF __UNICODE__
  DefWindowProc equ <DefWindowProcA>
ENDIF

DefWindowProcW PROTO STDCALL :QWORD,:QWORD,:QWORD,:QWORD
IFDEF __UNICODE__
  DefWindowProc equ <DefWindowProcW>
ENDIF
