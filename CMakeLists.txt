cmake_minimum_required(VERSION 3.10)

# set the project name
project(big_nos)
include( CTest )

add_executable(atan2_generator generator/atan2_generator.cc)
add_executable(atan2 
    atan2.cc
    ${CMAKE_CURRENT_BINARY_DIR}/Debug/atan2_table.cc
)

find_path(GETOPT_INCLUDE_DIR getopt.h)
find_library(GETOPT_LIB getopt)
find_program(GETOPT_DLL getopt.dll)

include_directories(atan2_generator ${GETOPT_INCLUDE_DIR})
target_link_libraries(atan2_generator PUBLIC ${GETOPT_LIB} )

# Copy getopt dll to build folder						  
add_custom_command(TARGET atan2_generator POST_BUILD       	# Adds a post-build event to cmdtool
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  	# which executes "cmake - E copy_if_different..."
        ${GETOPT_DLL}                       # <--this is in-file
        $<TARGET_FILE_DIR:atan2_generator>)                 # <--this is out-file path


add_custom_target(build-time-make-directory ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}\\autogen)

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}\\Debug\\atan2_table.cc"
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}\\Debug\\atan2_generator.exe" --verbose -p 128
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}\\autogen\\"
    DEPENDS atan2_generator build-time-make-directory)
