# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.2.0 )

set( CMAKE_CXX_STANDARD          20  )
set( CMAKE_CXX_STANDARD_REQUIRED ON  )
set( CMAKE_CXX_EXTENSIONS        OFF )
# AEON::Core ------------------------------------------------------------------------------------------
set( CORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CORE_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

add_library( aeon-core SHARED
    ${CORE_SRC}/Application.cpp
    ${CORE_SRC}/EntryPoint.h
)
add_dependencies( aeon-core
    aeon-base
    aeon-graphics
)
target_include_directories( aeon-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_precompile_headers(  aeon-core  PRIVATE ${HEADERS} ${STD_HEADERS} )
target_link_libraries(      aeon-core   PUBLIC      aeon-base
                                                    aeon-graphics                       )