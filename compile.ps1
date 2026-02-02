if(-Not (Test-Path ".\build\")){
    &mkdir ".\build\"
}
$nasmargs = '-f win64', '.\src\snek.asm', '-o .\build\snek.o'
Invoke-Expression "nasm $nasmargs" -ErrorAction Stop

if(-Not (Test-Path ".\bin\")){
    &mkdir ".\bin\"
}
$linkargs = '.\build\snek.o', '/subsystem:console', '/entry:main', '/out:ae.exe', 'kernel32.lib', 'ucrt.lib', 'legacy_stdio_definitions.lib'
Invoke-Expression "link $linkargs" -ErrorAction Stop
