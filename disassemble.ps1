param(
    [Parameter(position = 0, mandatory = $false)]
    [switch]$all,
    [Parameter(position = 1, mandatory = $false)]
    [switch]$contents
)

if(-Not(Test-Path ".\build\snek.obj")){
    Write-Host "ERROR: no .obj file found."
    return;
}

if($all){
    Invoke-Expression "objdump .\build\snek.obj -D"
    return;
}elseIf($contents){
    Invoke-Expression "objdump .\build\snek.obj -s"
}

Invoke-Expression "objdump .\build\snek.obj -d"
