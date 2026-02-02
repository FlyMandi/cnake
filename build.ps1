param( 
    [Parameter(position=0,Mandatory=$false)]
    $build = "debug",
    [Parameter(position=1,Mandatory=$false)]
    [switch] $nAMD = $false 
)

&premake5 vs2022

$VS = Join-Path $env:PROGRAMFILES "\Microsoft Visual Studio\2022\Community\"

if($nAMD){ $MSBuild = Join-Path $VS "\MSBuild\Current\bin\" }
else{ $MSBuild = Join-Path $VS "\MSBuild\Current\bin\amd64\" }

if(-Not(Test-Path ".\river\bin")){ &mkdir ".\river\bin" }

&"$MSBuild\MSBuild.exe" .\build\Cnake.sln -p:Configuration=$build
.\river\shader_comp.ps1
