# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.2.0 )

set( CMAKE_CXX_STANDARD          20  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )
# AEON::Core --------------------------------------------------------------------------------------
set( CORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CORE_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

add_library( aeon-core SHARED
    ${CORE_SRC}/Application.cpp
    ${CORE_SRC}/EntryPoint.h
)
add_dependencies( aeon-core
    aeon-base
    aeon-input
    aeon-graphics
)
target_precompile_headers(  aeon-core PRIVATE ${HEADERS} ${STD_HEADERS} )
target_include_directories( aeon-core PUBLIC  ${CORE_INC} PRIVATE ${BASE_INC} ${GRAPHICS_INC} ${INPUT_INC} )
target_link_libraries(      aeon-core PRIVATE aeon-base aeon-graphics aeon-input )