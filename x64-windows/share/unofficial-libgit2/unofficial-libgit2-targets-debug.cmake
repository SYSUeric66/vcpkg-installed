#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::libgit2::libgit2package" for configuration "Debug"
set_property(TARGET unofficial::libgit2::libgit2package APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(unofficial::libgit2::libgit2package PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/git2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/git2.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::libgit2::libgit2package )
list(APPEND _cmake_import_check_files_for_unofficial::libgit2::libgit2package "${_IMPORT_PREFIX}/debug/lib/git2.lib" "${_IMPORT_PREFIX}/debug/bin/git2.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
