add_library(                aeon-core   SHARED      Application.cpp EntryPoint.h )
add_dependencies( aeon-core
    loguru
    aeon-base
    aeon-graphics
)
set_target_properties(      aeon-core   PROPERTIES  PROJECT_NAME                AEON
                                                    POSITION_INDEPENDENT_CODE   TRUE    )
target_include_directories( aeon-core   PRIVATE     ${AEON_DIR}
                                        PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}         )

target_precompile_headers(  aeon-core   REUSE_FROM  aeon-base                     )
target_link_libraries(      aeon-core   PUBLIC      loguru
                                                    aeon-base
                                                    aeon-graphics                       )