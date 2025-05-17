qt_add_qml_module(MainMenu
    URI BankSystem.GUI.MainMenu
    VERSION 1.0
    QML_FILES
        MainMenu.qml
        MainButton.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/BankSystem/GUI/MainMenu
)

set(MainMenu ${MainMenu} PARENT_SCOPE)
