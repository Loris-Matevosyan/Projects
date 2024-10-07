file(GLOB SOURCES "*.cpp")
add_library(${BankLibrary} STATIC ${SOURCES})

target_include_directories(${BankLibrary} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries( ${BankLibrary} PUBLIC 
                       ${MainMenuLibrary} 
                       ${DatabaseLibrary} ${ManagerLibrary} ${CustomerLibrary} 
                       ${TextOutputLibrary} )

add_subdirectory(MainMenu)