add_library(${MainMenuLibrary} INTERFACE)

target_include_directories(${MainMenuLibrary} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${MainMenuLibrary} INTERFACE ${TextOutputLibrary})