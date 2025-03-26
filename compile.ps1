if(-Not (Test-Path ".\build\")){
    &mkdir ".\build\"
}
Push-Location ".\build\"
$masmargs = '..\src\snek.asm'

Invoke-Expression "ml64 $masmargs" -ErrorAction Break
Pop-Location
