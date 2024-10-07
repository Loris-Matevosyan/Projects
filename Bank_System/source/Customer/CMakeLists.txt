file(GLOB SOURCES "*.cpp")
add_library(${CustomerLibrary} STATIC ${SOURCES})

target_include_directories(${CustomerLibrary} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries(${CustomerLibrary} PRIVATE ${TextOutputLibrary})