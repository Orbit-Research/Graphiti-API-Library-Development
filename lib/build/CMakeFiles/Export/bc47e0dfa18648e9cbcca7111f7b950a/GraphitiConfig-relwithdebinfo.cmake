#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Graphiti::Graphiti" for configuration "RelWithDebInfo"
set_property(TARGET Graphiti::Graphiti APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Graphiti::Graphiti PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Graphiti.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Graphiti.dll"
  )

list(APPEND _cmake_import_check_targets Graphiti::Graphiti )
list(APPEND _cmake_import_check_files_for_Graphiti::Graphiti "${_IMPORT_PREFIX}/lib/Graphiti.lib" "${_IMPORT_PREFIX}/bin/Graphiti.dll" )

# Import target "Graphiti::Graphiti_C" for configuration "RelWithDebInfo"
set_property(TARGET Graphiti::Graphiti_C APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Graphiti::Graphiti_C PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/Graphiti_C.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "Graphiti::Graphiti"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Graphiti_C.dll"
  )

list(APPEND _cmake_import_check_targets Graphiti::Graphiti_C )
list(APPEND _cmake_import_check_files_for_Graphiti::Graphiti_C "${_IMPORT_PREFIX}/lib/Graphiti_C.lib" "${_IMPORT_PREFIX}/bin/Graphiti_C.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
