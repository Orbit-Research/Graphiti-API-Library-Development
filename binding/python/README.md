python wrapper
- Any python code can use the python wrapper by running with the libGraphiti_C.dll and graphiti.py

## Usage ##

Compile the library using install_library_vcpkg.ps1 
Copy files using using copy-dll-C.ps1
Run using run.ps1 or a similar command

## File Structure ##
- copy-dll-C.ps1
    - Script to copy the libGraphiti_C.dll and hidapi.dll files to the current directory from graphit folder under user
- graphiti.py
    - Wrapper for the Graphiti library using ctypes
- hidapi.dll
    - dll file for hidapi to enable HID
    - Dependency of libGraphiti_C.dll
- libGraphiti.dll
    - Compiled library for the Graphiti
- run.ps1
    - Run script for convience
- test.py
    - File for showing the use of the graphiti python library