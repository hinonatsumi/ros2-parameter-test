# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tutorial_parameter_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tutorial_parameter_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tutorial_parameter_FOUND FALSE)
  elseif(NOT tutorial_parameter_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tutorial_parameter_FOUND FALSE)
  endif()
  return()
endif()
set(_tutorial_parameter_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tutorial_parameter_FIND_QUIETLY)
  message(STATUS "Found tutorial_parameter: 0.0.0 (${tutorial_parameter_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tutorial_parameter' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tutorial_parameter_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tutorial_parameter_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tutorial_parameter_DIR}/${_extra}")
endforeach()
