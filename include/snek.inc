TRUE                equ 1 
FALSE               equ 0 
NULL                equ 0

SW_SHOWDEFAULT      equ 10

ExitProcess PROTO STDCALL :DWORD

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
    GetCommandLine equ <GetCommandLineA>
ENDIF

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
    GetCommandLine equ <GetCommandLineW>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
    GetModuleHandle equ <GetModuleHandleA>
ENDIF
