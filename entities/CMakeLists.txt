add_library(entities)
add_library(pacman::entities ALIAS entities)

target_sources(entities PRIVATE
    BlueGhost.cpp
    PacMan.cpp
)

set(API_INCLUDES
    BlueGhost.hpp
    PacMan.hpp
)

target_include_directories(entities
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(entities
    PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

set_target_properties(entities PROPERTIES
    PUBLIC_HEADER "${API_INCLUDES}"
)

# Install the library and public headers
install(TARGETS entities
    EXPORT PacManTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/entities
)