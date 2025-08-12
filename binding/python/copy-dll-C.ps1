function Copy-ToCurrentDirectory {
    param (
        [string]$FileName,
        [string]$SourcePath
    )

    Write-Host "Deleting existing $FileName (if any)..."
    Remove-Item $FileName -ErrorAction SilentlyContinue

    if (!(Test-Path $SourcePath)) {
        Write-Error "$FileName not found at: $SourcePath"
        return $false
    }

    Copy-Item -Path $SourcePath -Destination $FileName -Force
    Write-Host "Copied $FileName to current directory."
    return $true
}

# Copy DLL
$dllSuccess = Copy-ToCurrentDirectory -FileName "libGraphiti_C.dll" -SourcePath "$env:USERPROFILE\graphiti\bin\libGraphiti_C.dll"

# Copy Mult-Config DLL
$dllSuccessMC = Copy-ToCurrentDirectory -FileName "Graphiti_C.dll" -SourcePath "$env:USERPROFILE\graphiti\bin\Graphiti_C.dll"

# Copy hidapi
$headerSuccess = Copy-ToCurrentDirectory -FileName "hidapi.dll" -SourcePath "$env:USERPROFILE\vcpkg\installed\x64-windows\bin\hidapi.dll"

if (-not $dllSuccess -or -not $dllSuccessMC -or -not $headerSuccess -or -not $headerSuccess) {
    Write-Host "One or more copying failed"
    Write-Host "Single config creates libGraphiti.dll"
    Write-Host "Multi config creates Graphiti_C.dll"
    Write-Host "One or the other is fine"
    exit 1
}