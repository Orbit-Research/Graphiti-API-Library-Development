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

# Copy Header
$headerSuccess = Copy-ToCurrentDirectory -FileName "capi.h" -SourcePath "$env:USERPROFILE\graphiti\include\Graphiti\CWrapper\capi.h"

if (-not $dllSuccess -or -not $headerSuccess) {
    exit 1
}