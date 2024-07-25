set(IS_MASTER_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(IS_MASTER_PROJECT ON)
endif()

if(IS_MASTER_PROJECT)
  cmake_minimum_required(VERSION 3.5.0)
  project(cnoid-sandbox)
  find_package(Choreonoid REQUIRED)

else()
  option(BUILD_CNOID_SANDBOX "Building some test models" OFF)
  if(NOT BUILD_CNOID_SANDBOX)
    return()
  endif()

  if(UNIX)
    add_custom_target(
      symlink_to_CNOID_SANDBOX ALL
      COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_CURRENT_SOURCE_DIR} ${CNOID_BINARY_SHARE_DIR}/Cnoid-Sandbox)
  endif()
endif()

install(DIRECTORY
  model
  project
  script
  DESTINATION ${CHOREONOID_SHARE_SUBDIR}/Cnoid-Sandbox)

add_subdirectory(controller)
