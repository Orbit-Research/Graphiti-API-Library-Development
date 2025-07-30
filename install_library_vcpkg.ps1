# Installs Library dependencies and adds it to the path
.\vcpkg_Install_User.ps1

### Builds and installs library ###

# Get current directory path
$ScriptRoot = Split-Path -Parent $MyInvocation.MyCommand.Definition

# Enter lib folder
Push-Location "$ScriptRoot\lib"

# Execute from inside lib folder to use lib CMakeLists.txt
.\library.ps1 -Generator "Ninja" -Compiler "g++"

# Exit lib folder
Pop-Location
