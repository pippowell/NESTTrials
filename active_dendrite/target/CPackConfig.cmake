# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/Users/timbax/Documents/active_dendrite/target;/Users/timbax/Documents/active_dendrite/target")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/Users/timbax/anaconda3/envs/wnest/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "/Users/timbax/Documents/active_dendrite/target;nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module;ALL;/")
set(CPACK_INSTALL_PREFIX "/var/folders/x0/5gxjqthx1_37frghhy7_rvvw0000gn/T/nestml_target_qoi8_n4s")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module 1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module 1.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/timbax/Documents/active_dendrite/target/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/Users/timbax/anaconda3/envs/wnest/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "NEST Module nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module")
set(CPACK_PACKAGE_FILE_NAME "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module-1.0-Darwin")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module 1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module 1.0")
set(CPACK_PACKAGE_NAME "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "NEST Initiative (http://www.nest-initiative.org/)")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/timbax/anaconda3/envs/wnest/share/cmake-3.26/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/Users/timbax/anaconda3/envs/wnest/share/cmake-3.26/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/Users/timbax/anaconda3/envs/wnest/share/cmake-3.26/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "\\.gitignore;\\.git/;\\.travis\\.yml;/build/;/_CPack_Packages/;CMakeFiles/;cmake_install\\.cmake;Makefile.*;CMakeCache\\.txt;CPackConfig\\.cmake;CPackSourceConfig\\.cmake")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/timbax/Documents/active_dendrite/target/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "nestml_1b83f5cccd9b4cd0a3e3207fd01eb033_module")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/timbax/Documents/active_dendrite/target/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
