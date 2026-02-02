if(Test-Path ".\build\"){
    &Remove-Item ".\build\" -Recurse
}

if(Test-Path ".\bin\"){
    &Remove-Item ".\bin\" -Recurse
}

foreach($item in (Get-ChildItem . -File -Recurse | Where-Object{$_ -match ".exe"})){
    Remove-Item $item
}

foreach($item in (Get-ChildItem . -File -Recurse | Where-Object{$_ -match ".obj"})){
    Remove-Item $item
}

foreach($item in (Get-ChildItem . -File -Recurse | Where-Object{$_ -match ".lnk"})){
    Remove-Item $item
}
