# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.20 )

if(NOT DEFINED PROJECT_NAME)
  set(NOT_SUBPROJECT ON)
else()
  set(NOT_SUBPROJECT OFF)
endif()

project( AER::Base
    VERSION 0.1.0
    LANGUAGES CXX
)

# FetchContent -----------------------------------------------------------------------------------
include(FetchContent)
set( FETCHCONTENT_QUIET FALSE )

set( DOWNLOADS_DIR ${PROJECT_BINARY_DIR}/downloads )
set( COMPONENTS_DIR ${PROJECT_BINARY_DIR}/components )
set( FETCHCONTENT_BASE_DIR ${COMPONENTS_DIR} )

if(NOT TARGET aer::base)
    OPTION( BUILD_base "Build aer::base" ON )
    if( ${BUILD_base} )
        FetchContent_Declare( base
            GIT_REPOSITORY https://github.com/AERwaevs/base.git
            GIT_TAG main
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable( base )
        set( base_DEPENDENCY base )
    endif()
endif()

if(NOT TARGET aer::input)
    OPTION( BUILD_input "Build aer::input" ON )
    if( ${BUILD_base} )
        FetchContent_Declare( input
            GIT_REPOSITORY https://github.com/AERwaevs/input.git
            GIT_TAG main
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable( input ${base_DEPENDENCY}  )
        set( input_DEPENDENCY input )
    endif()
endif()

if(NOT TARGET aer::graphics)
    OPTION( BUILD_graphics "Build aer::graphics" ON )
    if( ${BUILD_base} )
        FetchContent_Declare( graphics
            GIT_REPOSITORY https://github.com/AERwaevs/graphics.git
            GIT_TAG main
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable( graphics ${base_DEPENDENCY} )
        set( graphics_DEPENDENCY graphics )
    endif()
endif()
# AER::Core ---------------------------------------------------------------------------------------
set( CORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CORE_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

SET( SOURCES 
    ${CORE_SRC}/Application.cpp
)

option( BUILD_SHARED_LIBS "Build Core as a shared library" ON )

add_library( core ${SOURCES} )

add_library( aer::core ALIAS core )
set( core_FOUND TRUE CACHE INTERNAL "core module found." )
set( CMAKE_DISABLE_FIND_PACKAGE_core TRUE CACHE INTERNAL "Disable find_package(aer::core) as it's not necessary." )

set_target_properties( core PROPERTIES
    CXX_STANDARD                    23
    CXX_STANDARD_REQUIRED           ON
    CXX_EXTENSIONS                  OFF
    CMAKE_POSITION_INDEPENDENT_CODE ON
)

target_include_directories( core PUBLIC $<BUILD_INTERFACE:${CORE_INC}> )
target_link_libraries(      core PUBLIC aer::base aer::input aer::graphics )