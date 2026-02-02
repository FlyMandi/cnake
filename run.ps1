param(
    $config = "debug"
)

if(-Not (Test-Path ".\build\"))
{
    &mkdir ".\build\"
}
if(-Not (Test-Path ".\bin\"))
{
    &mkdir ".\bin\"
}

if($config -eq "release")
{
    $masmargs = '..\src\snek.asm',
                '/Fo .\snek.obj',
                '/Fe ..\bin\snek.exe',
                '/link /entry:MainEntry /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\um\x64"'
}
elseIf($config -eq "debug")
{
    $masmargs = '..\src\snek.asm',
                '/Fo .\snek.obj',
                '/Fe ..\bin\snek.exe',
                '/DEBUG',
                '/link /entry:MainEntry /DEBUG:full /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.26100.0\um\x64"'
}

Push-Location ".\build\"
Invoke-Expression "ml64 $masmargs" -ErrorAction Break
Pop-Location

if($LASTEXITCODE -eq 0)
{
    Invoke-Expression ".\bin\snek.exe"
}
