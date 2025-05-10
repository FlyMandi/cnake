param(
    [switch]$debug = $false
)

if(-Not (Test-Path ".\build\")){
    &mkdir ".\build\"
}
if(-Not (Test-Path ".\bin\")){
    &mkdir ".\bin\"
}
Push-Location ".\build\"
$masmargs = '..\src\snek.asm', '/Fo .\snek.obj', '/Fe ..\bin\snek.exe', '/link /entry:MainEntry'
if($debug){
    $masmargs = '..\src\snek.asm', '/Fo .\snek.obj', '/Fe ..\bin\snek.exe', '/link /entry:MainEntry /DEBUG'
}

Invoke-Expression "ml64 $masmargs" -ErrorAction Break
Pop-Location
