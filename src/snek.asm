    extern printf: PROC
        
    includelib msvcrt.lib
    includelib legacy_stdio_definitions.lib
    
.data   
    message db "now entering... snek!!", 0
        
.code
main proc
    sub rsp, 40
    lea rcx, message
    call printf



    add rsp, 40
    ret
main endp

end
