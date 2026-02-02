    extern printf: PROC
        
    includelib msvcrt.lib
    includelib legacy_stdio_definitions.lib
    
.data   
    message byte "now entering... snek!!", 13, 10, 0
    message2 byte "t'is a cool game.", 13, 10, 0

.code
main proc
    sub rsp, 40

    lea rcx, message
    call printf

    lea rcx, message2
    call printf

    add rsp, 40
    ret
main endp

end
