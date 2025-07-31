// graphiti_handle.hpp
#pragma once
#include <Graphiti/Extension.hpp>

// Forward declarations to avoid full dependencies
class GraphitiExtension;

struct GraphitiHandle {
    GraphitiExtension api;
};

// Core creation/destruction functions
GraphitiHandle* graphiti_create();
GraphitiHandle* graphiti_createWithConnection(void* connection);
void graphiti_destroy(GraphitiHandle* handle);