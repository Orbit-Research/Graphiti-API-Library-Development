# Define source and destination paths
$source = Join-Path $env:USERPROFILE "graphiti\bin\libGraphiti_C.dll"
$destination = Join-Path (Get-Location) "libGraphiti_C.dll"

# Check if the DLL exists
if (!(Test-Path $source)) {
    Write-Error "libGraphiti_C.dll not found at: $source"
    exit 1
}

# Copy the file
Copy-Item -Path $source -Destination $destination -Force
Write-Host "Copied libGraphiti_C.dll to current directory."