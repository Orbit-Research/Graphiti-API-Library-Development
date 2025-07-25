#include <windows.h>
#include <stdio.h>
#include "capi.h"

int main() {
    HMODULE hDll = LoadLibrary("libGraphiti_C.dll");
    if (hDll == NULL) {
        printf("Could not load DLL.\n");
        return 1;
    }
}