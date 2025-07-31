// graphiti_handle.cpp
#include "graphiti_handle.hpp"  // For full GraphitiExtension definition

// Implementations
GraphitiHandle* graphiti_create() {
    return new GraphitiHandle();
}

GraphitiHandle* graphiti_createWithConnection(void* connection) {
    return new GraphitiHandle{static_cast<GraphitiConnection*>(connection)};
}

void graphiti_destroy(GraphitiHandle* handle) {
    delete handle;
}