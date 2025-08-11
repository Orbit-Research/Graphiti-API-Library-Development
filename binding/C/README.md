Build the code in this directory with:

.\build.ps1

Run with:

.\test.exe

## Dependencies ##
- hidapi.dll
- libGraphiti_C.dll
- capi.h

## File Structure ##
- .vscode
    - Folder with preset use of Ninja gcc for python
- build.ps1
    - compiles main.c with the graphiti library into test.exe
- capi.h
    - header file from the C wrapper of the Graphiti library
    - dependency of libGraphiti_C.dll when compiling in C
- copy-files.ps1
    - Copyies libGraphiti_C.dll from graphiti folder under user
- hidapi.dll
    - hid dll for hid support which is a dependency of libGraphiti_C.dll
- libGraphiti_C.dll
    - Compiled library for Graphiti C wrapper
- main.c
    - Progam to showcase use of Graphiti library with VCP and HID
- test.exe
    - Compiled code for execcution of main.c and library