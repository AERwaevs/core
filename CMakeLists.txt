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

set( CMAKE_CXX_STANDARD          23  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

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
            GIT_TAG nodes
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable( base )
        set( base_DEPENDENCY base )
    endif()
endif()
# AER::Core ---------------------------------------------------------------------------------------
set( CORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CORE_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

option( BUILD_SHARED_LIBS "Build Core as a shared library" ON )

add_library( core
    ${CORE_SRC}/Application.cpp
)
set_target_properties( core
    PROPERTIES 
    CXX_STANDARD    20
    LINKER_LANGUAGE CXX
)

#target_precompile_headers(  core PRIVATE ${HEADERS} ${STD_HEADERS} )
target_include_directories( core 
    PUBLIC
        $<BUILD_INTERFACE:${CORE_INC}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries( core
    PUBLIC
        base
        input
        graphics
)
add_library( aer::core ALIAS core )