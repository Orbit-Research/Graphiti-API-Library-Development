cmake_minimum_required(VERSION 3.12)
project(GraphitiJNI)

# Find Java and JNI
find_package(Java REQUIRED)
find_package(JNI REQUIRED)

# Add your JNI library
add_library(GraphitiJNI SHARED 
    Graphiti-JNI.cpp
    # Add other source files here
)

# Include directories
target_include_directories(GraphitiJNI PRIVATE
    ${JNI_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}  # For local headers
    # Add other include paths here
)

# Link against your existing lib_Graphiti
target_link_libraries(GraphitiJNI PRIVATE 
    Graphiti  # Links against libGraphiti.dll/.so
)

# Copy the DLL to build directory (Windows)
if(WIN32)
    add_custom_command(TARGET GraphitiJNI POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/lib_Graphiti.dll
            ${CMAKE_BINARY_DIR}/lib_Graphiti.dll
    )
endif()