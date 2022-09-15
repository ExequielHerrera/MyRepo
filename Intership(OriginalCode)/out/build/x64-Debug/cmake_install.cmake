# Install script for directory: C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/Action/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/AddContextAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/CheckReservedWordAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/ConcatenateDataAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/DataReadyAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/DictionaryData/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/ErrorTratementAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/JsonAnalizer/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/MoveAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/RemoveContextAction/cmake_install.cmake")
  include("C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/includes/StayAction/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/exequiel.herrera/Documents/C++Projects/CmakeMultiple/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
