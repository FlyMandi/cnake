HINSTANCE       typedef DWORD
LPSTR           typedef DWORD



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
