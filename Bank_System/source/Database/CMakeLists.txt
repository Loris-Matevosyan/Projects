file(GLOB SOURCES "*.cpp")
add_library(${DatabaseLibrary} STATIC ${SOURCES})

target_include_directories(${DatabaseLibrary} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries( ${DatabaseLibrary} PRIVATE ${CustomerLibrary} ${TextOutputLibrary} )