# Install script for directory: /Users/timbax/Documents/active_dendrite/target

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s/nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s" TYPE MODULE FILES "/Users/timbax/Documents/active_dendrite/target/nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module.so")
  if(EXISTS "$ENV{DESTDIR}/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s/nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s/nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" -x "$ENV{DESTDIR}/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s/nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/timbax/Documents/active_dendrite/target/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
