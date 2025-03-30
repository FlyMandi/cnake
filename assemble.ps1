if(-Not (Test-Path ".\build\")){
    &mkdir ".\build\"
}
$nasmargs = '-f win64', '.\src\snek.asm', '-o .\build\snek.obj'

Invoke-Expression "nasm $nasmargs" -ErrorAction Break

if(-Not (Test-Path ".\bin\")){
    &mkdir ".\bin\"
}
$linkargs = '.\build\snek.obj', '-o .\bin\snek.exe'

Invoke-Expression "ld $linkargs" -ErrorAction Break
