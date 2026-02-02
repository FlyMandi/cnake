if(Test-Path ".\build\"){
    &Remove-Item ".\build\" -Recurse
}

if(Test-Path ".\bin\"){
    &Remove-Item ".\bin\" -Recurse
}

foreach($item in (Get-ChildItem . | Where-Object{$_ -match ".exe"})){
    Remove-Item $item
}
