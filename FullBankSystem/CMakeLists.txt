cmake_minimum_required(VERSION 3.16)

project(BankSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Sql Test)

qt_standard_project_setup(REQUIRES 6.5)

set(TESTING OFF)


if(TESTING)
    set(EXECUTABLE testBankSystem)
    set(TESTING_CMAKE Tests/CMakeLists.txt)

    add_subdirectory(Tests)

    qt_add_executable(${EXECUTABLE}
        test.cpp
        ${TESTS_SOURCES}
    )

    target_include_directories(${EXECUTABLE} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Tests
    )

else()
    set(EXECUTABLE appBankSystem)
    set(TESTING_CMAKE)

    qt_add_executable(${EXECUTABLE}
        main.cpp
    )

endif()


target_include_directories(${EXECUTABLE} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Database ${CMAKE_CURRENT_SOURCE_DIR}/Exceptions
)

add_subdirectory(Database)

qt_add_qml_module(${EXECUTABLE}
    URI BankSystem
    VERSION 1.0
    RESOURCES BankSystem.md
    SOURCES Exceptions/databaseConnectionError.h
    SOURCES Exceptions/queryError.h
    SOURCES ${DATABASE_SOURCES}
    RESOURCES Database/CMakeLists.txt
    RESOURCES ${TESTING_CMAKE}
    QML_FILES Main.qml
    QML_FILES MainMenu.qml
    QML_FILES MainButton.qml
    RESOURCES Resources.qrc
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
