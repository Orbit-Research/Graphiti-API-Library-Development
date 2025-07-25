# Commands for building library with library CMakeLists.txt
Remove-Item -Recurse -Force .\build\

cmake -S . -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release

cmake --build build

# Install build at user graphiti folder
cmake --install build --prefix "$env:USERPROFILE\graphiti"

#Add graphiti to PATH

$graphitiPath = "$env:USERPROFILE\graphiti"
$envPath = [Environment]::GetEnvironmentVariable("PATH", "User")

if (-not $envPath.Contains($graphitiPath)) {
    [Environment]::SetEnvironmentVariable("PATH", "$envPath;$graphitiPath", "User")
    Write-Host "`nGraphiti path added to user PATH. You may need to restart your terminal."
} else {
    Write-Host "`nGraphiti is already in user PATH."
}