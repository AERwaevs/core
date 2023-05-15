# cmake -------------------------------------------------------------------------------------------
cmake_minimum_required( VERSION 3.2.0 )
# AEON::Core --------------------------------------------------------------------------------------
set( CORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib )
set( CORE_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc )
set( CORE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src )

option( BUILD_SHARED_LIBS "Build Core as a shared library" ON )

add_library( aeon-core
    ${CORE_SRC}/Application.cpp
)
set_target_properties( aeon-core
    PROPERTIES 
    CXX_STANDARD    20
    LINKER_LANGUAGE CXX
)

#target_precompile_headers(  aeon-core PRIVATE ${HEADERS} ${STD_HEADERS} )
target_include_directories( aeon-core 
    PUBLIC
        $<BUILD_INTERFACE:${CORE_INC}>
	    $<INSTALL_INTERFACE:inc>
)
target_link_libraries(      aeon-core PRIVATE aeon-base aeon-input aeon-graphics )