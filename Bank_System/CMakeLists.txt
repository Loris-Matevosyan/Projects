cmake_minimum_required(VERSION 3.22)

project(
    Bank 
    VERSION 1.0.0 
    LANGUAGES CXX )

set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED  20)
set(CMAKE_CXX_EXTENSIONS         OFF)


set(MainMenuLibrary mainMenuLibrary)
set(BankLibrary bankLibrary)
set(DatabaseLibrary databaseLibrary)
set(ManagerLibrary managerLibrary)
set(CustomerLibrary customerLibrary)
set(TextOutputLibrary textOutputLibrary)


add_subdirectory(source)
add_subdirectory(application)


