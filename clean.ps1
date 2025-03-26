if(Test-Path ".\build\"){
    &Remove-Item ".\build\" -Recurse
}

if(Test-Path ".\bin\"){
    &Remove-Item ".\bin\" -Recurse
}
