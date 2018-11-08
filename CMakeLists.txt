#
# requires minimum CMAKE version 2.8.12 and above
#
# Author: derriclyns@gmail.com
# 
#

cmake_minimum_required(VERSION 2.8.12.2)
set(PROJECT_NAME "csv-matrix")

message("\nForging project: ${PROJECT_NAME}")

project(${PROJECT_NAME})
enable_language(C)

set(CSVMATRIX_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/install)
set(CSVMATRIX_INSTALL_INCLUDE ${CSVMATRIX_INSTALL_DIR}/include)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

# find git
find_package(Git)
if (GIT_FOUND)
    message(STATUS "git found: ${GIT_EXECUTABLE}")
else (GIT_FOUND)
    set(GIT_EXECUTABLE "/usr/bin/git")
    set(GIT_FOUND true)
    message(STATUS "Forcing git executable path: ${GIT_EXECUTABLE}")
endif ()


include_directories(${CSVMATRIX_INSTALL_INCLUDE})


# Get the current working branch
execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

#config
configure_file(
        ${CMAKE_SOURCE_DIR}/version.h.in
        ${CSVMATRIX_INSTALL_INCLUDE}/csv-matrix_version.h
)

# set source files
set(CSVMATRIX_SOURCE_FILES src/${PROJECT_NAME}.c src/${PROJECT_NAME}_options.c src/${PROJECT_NAME}_logger.c)
add_executable(${PROJECT_NAME} ${CSVMATRIX_SOURCE_FILES})



# install
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
