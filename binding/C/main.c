#include <windows.h>
#include <stdio.h>
#include "capi.h"

int main() {
    GraphitiHandle* graphiti = graphiti_create();

    if(!graphiti) {
        printf("Failed to connect");
        return 1;
    }
    
    graphiti_startUpVCP(graphiti, "COM4", false, false);

    Sleep(2000);

    graphiti_updateSinglePixel(graphiti, 10, 20, 2, 0);

    Sleep(2000);

    graphiti_updateSinglePixel(graphiti, 10, 20, 0, 0);

    Sleep(2000);

    graphiti_shutDownVCP(graphiti, false, false);

    Sleep(2000);

    graphiti_destroy(graphiti);

    return 0;
}