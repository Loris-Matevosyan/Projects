qt_add_qml_module(ManagerMenu
    URI BankSystem.GUI.ManagerMenu
    VERSION 1.0
    QML_FILES
        ManagerMenu.qml
        ManagerMainMenu.qml
        MenuButton.qml
        CustomersList.qml
        CustomersListTemplate.qml
        AddCustomer.qml
        CustomTextInput.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/BankSystem/GUI/ManagerMenu
)

set(ManagerMenu ${ManagerMenu} PARENT_SCOPE)
