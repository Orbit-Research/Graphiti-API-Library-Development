param (
    [string]$Action = "buildrun"
)

# Store the original directory
$originalDir = Get-Location

# Switch to the project root (parent of the script's folder)
Set-Location (Join-Path $PSScriptRoot "..")

function clean {
    Write-Host "Running clean..."
    Remove-Item -Recurse -Force .\build\
}

function configure {
    param (
        [switch]$Debug
    )

    Write-Host "Running configure..."

    $version = @()

    if ($Debug) {
        $version += "-DCMAKE_BUILD_TYPE=Debug"
        Write-Host "-Debug enabled"
    }

    #cmake -B build -S . @version
    cmake -G Ninja -B build -S . @version
}

function build {
    Write-Host "Running build with changes..."
    ninja -C build
}

function run_ExtensionTest {
    Write-Host "Running current build"
    .\build\ExtensionTest.exe
}

function run_Testing {
    Write-Host "Running current build"
    .\build\Testing.exe
}

switch ($Action.ToLower()) {  # Makes comparison case-insensitive
    "clean" { clean }
    "configure" { configure }
    "configure_debug"{ configure -Debug }
    "build" { build }
    "run_Extension" { run_ExtensionTest }
    "run_Testing" { run_Testing }
    "full_build" {
        clean
        configure
        build
    }
    "standard" {
        clean
        configure
        build
        run_Testing
    }
    "standard_debug" {
        clean
        configure -Debug
        build
        run_Testing
    }
    "buildrun" {
        build
        run_Testing
    }
    "all" {
        clean
        configure -Debug
        build
        run_Testing
    }
    default {
        Write-Host "Error: Unknown action '$Action'. Valid options: 'clean', 
        'configure', 'configure_debug', 'build', 'run', 'cleanConfigureBuild', 
        'standard', 'standard_debug', 'standard_extension', 'all'"
        exit 1
    }
}

# Restore the original directory (optional)
Set-Location $originalDir