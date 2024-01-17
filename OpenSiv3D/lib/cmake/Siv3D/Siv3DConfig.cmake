# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget Siv3D::Siv3D Siv3D::Siv3DInterface Siv3D::Siv3DPrivateInterface Siv3D::Siv3DBrowserImageEncodeDecode Siv3D::Siv3DScript Siv3D::Siv3DWebGPU)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target Siv3D::Siv3D
add_library(Siv3D::Siv3D STATIC IMPORTED)

set_target_properties(Siv3D::Siv3D PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/Siv3D/ThirdParty;${_IMPORT_PREFIX}/include/Siv3D"
  INTERFACE_LINK_LIBRARIES "Siv3D::Siv3DInterface;\$<LINK_ONLY:Siv3D::Siv3DPrivateInterface>;-Wl,--no-whole-archive;${_IMPORT_PREFIX}/lib/Siv3D/opencv/libopencv_objdetect.a;${_IMPORT_PREFIX}/lib/Siv3D/opencv/libopencv_photo.a;${_IMPORT_PREFIX}/lib/Siv3D/opencv/libopencv_imgproc.a;${_IMPORT_PREFIX}/lib/Siv3D/opencv/libopencv_core.a;${_IMPORT_PREFIX}/lib/Siv3D/harfbuzz/libharfbuzz.a;${_IMPORT_PREFIX}/lib/Siv3D/freetype/libfreetype.a;${_IMPORT_PREFIX}/lib/Siv3D/turbojpeg/libturbojpeg.a;${_IMPORT_PREFIX}/lib/Siv3D/giflib/libgif.a;${_IMPORT_PREFIX}/lib/Siv3D/webp/libwebp.a;${_IMPORT_PREFIX}/lib/Siv3D/opus/libopusfile.a;${_IMPORT_PREFIX}/lib/Siv3D/opus/libopus.a;${_IMPORT_PREFIX}/lib/Siv3D/tiff/libtiff.a;${_IMPORT_PREFIX}/lib/Siv3D/png/libpng.a;${_IMPORT_PREFIX}/lib/Siv3D/zlib/libz.a;${_IMPORT_PREFIX}/lib/Siv3D/SDL2/libSDL2.a"
)

# Create imported target Siv3D::Siv3DInterface
add_library(Siv3D::Siv3DInterface INTERFACE IMPORTED)

set_target_properties(Siv3D::Siv3DInterface PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "\$<\$<COMPILE_LANGUAGE:CXX>:;AS_USE_NAMESPACE;MUPARSER_STATIC;_UNICODE;WITH_SDL2_STATIC;WITH_NOSOUND;BOOST_ASIO_HAS_STD_INVOKE_RESULT;ASIO_HAS_STD_INVOKE_RESULT;_XM_NO_INTRINSICS_>;\$<\$<COMPILE_LANGUAGE:C>:;WITH_SDL2_STATIC;WITH_NOSOUND;_XM_NO_INTRINSICS_>"
  INTERFACE_COMPILE_FEATURES "cxx_std_20;c_std_11"
  INTERFACE_COMPILE_OPTIONS "\$<\$<COMPILE_LANGUAGE:CXX>:;-Wall;-Wextra;-Wno-unknown-pragmas;-Wno-enum-constexpr-conversion;-sEXCEPTION_CATCHING_ALLOWED=[\"main\",\"_ZN3s3d7TryMainEv\"];-fcolor-diagnostics;\$<\$<CONFIG:Debug>:;-g3;-O0;-pg;-DDEBUG>;\$<\$<CONFIG:Release>:;-O2;-DNDEBUG>;\$<\$<CONFIG:RelWithDebInfo>:;-g3;-Og;-pg>;\$<\$<CONFIG:MinSizeRel>:;-Os;-DNDEBUG>;>;\$<\$<COMPILE_LANGUAGE:C>:;-Wall;-Wextra;-Wno-missing-field-initializers;-sEXCEPTION_CATCHING_ALLOWED=[\"main\",\"_ZN3s3d7TryMainEv\"];-fcolor-diagnostics;\$<\$<CONFIG:Debug>:;-g3;-O0;-pg;-DDEBUG>;\$<\$<CONFIG:Release>:;-O2;-DNDEBUG>;\$<\$<CONFIG:RelWithDebInfo>:;-g3;-Og;-pg>;\$<\$<CONFIG:MinSizeRel>:;-Os;-DNDEBUG>;>"
  INTERFACE_LINK_OPTIONS "--js-library=${_IMPORT_PREFIX}/lib/Siv3D/Siv3D.js;--pre-js=${_IMPORT_PREFIX}/lib/Siv3D/Siv3D.pre.js;--post-js=${_IMPORT_PREFIX}/lib/Siv3D/Siv3D.post.js"
)

# Create imported target Siv3D::Siv3DPrivateInterface
add_library(Siv3D::Siv3DPrivateInterface INTERFACE IMPORTED)

set_target_properties(Siv3D::Siv3DPrivateInterface PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/__w/OpenSiv3D/OpenSiv3D/Web/"
)

# Create imported target Siv3D::Siv3DBrowserImageEncodeDecode
add_library(Siv3D::Siv3DBrowserImageEncodeDecode STATIC IMPORTED)

set_target_properties(Siv3D::Siv3DBrowserImageEncodeDecode PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:Siv3D::Siv3DInterface>;\$<LINK_ONLY:Siv3D::Siv3DPrivateInterface>"
)

# Create imported target Siv3D::Siv3DScript
add_library(Siv3D::Siv3DScript STATIC IMPORTED)

set_target_properties(Siv3D::Siv3DScript PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:Siv3D::Siv3DInterface>;\$<LINK_ONLY:Siv3D::Siv3DPrivateInterface>"
)

# Create imported target Siv3D::Siv3DWebGPU
add_library(Siv3D::Siv3DWebGPU STATIC IMPORTED)

set_target_properties(Siv3D::Siv3DWebGPU PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:Siv3D::Siv3DInterface>;\$<LINK_ONLY:Siv3D::Siv3DPrivateInterface>"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/Siv3DConfig-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)