# Define user vcpkg path
$UserPath = "$env:USERPROFILE\vcpkg"

# Step 1: Clone vcpkg
git clone https://github.com/microsoft/vcpkg.git $UserPath

# Step 2: Bootstrap vcpkg
& "$UserPath\bootstrap-vcpkg.bat"

# Step 3: Integrate with MSBuild
& "$UserPath\vcpkg.exe" integrate install

# Step 4: Install ASIO
& "$UserPath\vcpkg.exe" install asio

# Step 5: Add vcpkg to the user's PATH
$envPath = [Environment]::GetEnvironmentVariable("PATH", "User")
if (-not $envPath.Contains($UserPath)) {
    [Environment]::SetEnvironmentVariable("PATH", "$envPath;$UserPath", "User")
    Write-Host "`nvcpkg path added to user PATH. You may need to restart your terminal."
} else {
    Write-Host "`nvcpkg is already in user PATH."
}
