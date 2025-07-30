# Path to source DLLs
$sourceDir = Join-Path $env:USERPROFILE "graphiti\bin"

# Path to destination (current directory)
$destDir = Get-Location

# Ensure source exists
if (!(Test-Path $sourceDir)) {
    Write-Error "Source directory '$sourceDir' does not exist."
    exit 1
}

# Get DLL files and copy
Get-ChildItem -Path $sourceDir -Filter *.dll | ForEach-Object {
    $sourcePath = $_.FullName
    $destPath = Join-Path $destDir $_.Name
    Write-Host "Copying $sourcePath -> $destPath"
    Copy-Item -Path $sourcePath -Destination $destPath -Force
}

Write-Host "Done copying DLLs."
