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
