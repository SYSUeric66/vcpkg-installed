#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::libgit2::libgit2package" for configuration "Release"
set_property(TARGET unofficial::libgit2::libgit2package APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::libgit2::libgit2package PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/git2.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/git2.dll"
  )

list(APPEND _cmake_import_check_targets unofficial::libgit2::libgit2package )
list(APPEND _cmake_import_check_files_for_unofficial::libgit2::libgit2package "${_IMPORT_PREFIX}/lib/git2.lib" "${_IMPORT_PREFIX}/bin/git2.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
