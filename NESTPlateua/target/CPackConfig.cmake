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


set(CPACK_BUILD_SOURCE_DIRS "/home/nest/NESTTrials/NESTTrials/NESTPlateua/target;/home/nest/NESTTrials/NESTTrials/NESTPlateua/target")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/home/nest/enter/envs/nesttrials/lib/python3.11/site-packages/cmake/data/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "nestml_9bf4625be77440b6b997e9b367d49a09_module built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/nest/NESTTrials/NESTTrials/NESTPlateua/target;nestml_9bf4625be77440b6b997e9b367d49a09_module;ALL;/")
set(CPACK_INSTALL_PREFIX "/tmp/nestml_target_1_n5137t")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "nestml_9bf4625be77440b6b997e9b367d49a09_module 1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "nestml_9bf4625be77440b6b997e9b367d49a09_module 1.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/home/nest/enter/envs/nesttrials/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/home/nest/enter/envs/nesttrials/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/home/nest/NESTTrials/NESTTrials/NESTPlateua/target/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/home/nest/enter/envs/nesttrials/lib/python3.11/site-packages/cmake/data/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "NEST Module nestml_9bf4625be77440b6b997e9b367d49a09_module")
set(CPACK_PACKAGE_FILE_NAME "nestml_9bf4625be77440b6b997e9b367d49a09_module-1.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "nestml_9bf4625be77440b6b997e9b367d49a09_module 1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "nestml_9bf4625be77440b6b997e9b367d49a09_module 1.0")
set(CPACK_PACKAGE_NAME "nestml_9bf4625be77440b6b997e9b367d49a09_module")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "NEST Initiative (http://www.nest-initiative.org/)")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_READELF_EXECUTABLE "/home/nest/enter/envs/nesttrials/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/home/nest/enter/envs/nesttrials/lib/python3.11/site-packages/cmake/data/share/cmake-3.27/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/home/nest/enter/envs/nesttrials/lib/python3.11/site-packages/cmake/data/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/home/nest/enter/envs/nesttrials/lib/python3.11/site-packages/cmake/data/share/cmake-3.27/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "\\.gitignore;\\.git/;\\.travis\\.yml;/build/;/_CPack_Packages/;CMakeFiles/;cmake_install\\.cmake;Makefile.*;CMakeCache\\.txt;CPackConfig\\.cmake;CPackSourceConfig\\.cmake")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/nest/NESTTrials/NESTTrials/NESTPlateua/target/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "nestml_9bf4625be77440b6b997e9b367d49a09_module")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/nest/NESTTrials/NESTTrials/NESTPlateua/target/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
