file(GLOB SOURCES "*.cpp")
add_library(${ManagerLibrary} STATIC ${SOURCES})

target_include_directories(${ManagerLibrary} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries( ${DatabaseLibrary} PRIVATE ${CustomerLibrary} ${TextOutputLibrary} )