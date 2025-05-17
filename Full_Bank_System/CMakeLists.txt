cmake_minimum_required(VERSION 3.16)

project(BankSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Sql Test)

qt_standard_project_setup(REQUIRES 6.5)


if(Qt6_VERSION VERSION_GREATER_EQUAL "6.8")
    qt_policy(SET QTP0004 NEW)
else()
    message(WARNING "QTP0004 policy is not available in this Qt version")
endif()


set(TESTING OFF)
set(TESTS_DIR)
set(TESTS_CMAKE)


if(TESTING)

    add_subdirectory(Tests)

    set(EXECUTABLE testBankSystem)
    set(MAIN test.cpp ${TESTS_SOURCES})
    set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Tests)
    set(TESTS_CMAKE Tests/CMakeLists.txt)

else()

    set(EXECUTABLE appBankSystem)
    set(MAIN main.cpp)

endif()


add_subdirectory(Database)
add_subdirectory(Exceptions)
add_subdirectory(GUI)


qt_add_executable(${EXECUTABLE}
    ${MAIN}
    ${DATABASE_SOURCES}
    ${EXCEPTION_SOURCES}
)

target_include_directories(${EXECUTABLE} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Database ${CMAKE_CURRENT_SOURCE_DIR}/Exceptions ${TESTS_DIR}
)


qt_add_qml_module(${EXECUTABLE}
    URI BankSystem
    VERSION 1.0
    RESOURCES Database/CMakeLists.txt
              Exceptions/CMakeLists.txt
              GUI/CMakeLists.txt
              ${TESTS_CMAKE}
              Resources.qrc
              README.md
    QML_FILES
        Main.qml
)



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(${EXECUTABLE} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBankSystem
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${EXECUTABLE}
    PRIVATE Qt6::Quick Qt6::Core Qt6::Sql Qt6::Test
)


include(GNUInstallDirs)
install(TARGETS ${EXECUTABLE}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
