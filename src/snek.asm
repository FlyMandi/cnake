    bits 64
    default rel

segment .data   
message: db "now entering... snek!!", 0
        
segment .text
    global main
    extern printf      
    extern ExitProcess  

main: 
    
    call printf
    xor rax, rax
    call ExitProcess
