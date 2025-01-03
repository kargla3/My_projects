# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_serialRviz_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED serialRviz_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(serialRviz_FOUND FALSE)
  elseif(NOT serialRviz_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(serialRviz_FOUND FALSE)
  endif()
  return()
endif()
set(_serialRviz_CONFIG_INCLUDED TRUE)

# output package information
if(NOT serialRviz_FIND_QUIETLY)
  message(STATUS "Found serialRviz: 0.0.0 (${serialRviz_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'serialRviz' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${serialRviz_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(serialRviz_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${serialRviz_DIR}/${_extra}")
endforeach()
