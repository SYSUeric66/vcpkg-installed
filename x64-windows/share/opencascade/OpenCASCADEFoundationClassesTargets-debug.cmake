#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "TKernel" for configuration "Debug"
set_property(TARGET TKernel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKernel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/TKernel.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/TKernel.dll"
  )

list(APPEND _cmake_import_check_targets TKernel )
list(APPEND _cmake_import_check_files_for_TKernel "${_IMPORT_PREFIX}/debug/lib/TKernel.lib" "${_IMPORT_PREFIX}/debug/bin/TKernel.dll" )

# Import target "TKMath" for configuration "Debug"
set_property(TARGET TKMath APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKMath PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/TKMath.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/TKMath.dll"
  )

list(APPEND _cmake_import_check_targets TKMath )
list(APPEND _cmake_import_check_files_for_TKMath "${_IMPORT_PREFIX}/debug/lib/TKMath.lib" "${_IMPORT_PREFIX}/debug/bin/TKMath.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
