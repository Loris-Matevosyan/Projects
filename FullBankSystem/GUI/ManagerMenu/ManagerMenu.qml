import QtQuick 2.15


Item
{
    id: managerMenu

    anchors.fill: parent

    signal exitManagerMenu

    Loader
    {
        id: loader

        anchors.fill: parent
        sourceComponent: mainManagerMenuComponent
    }

    Component
    {
        id: mainManagerMenuComponent

        ManagerMainMenu
        {
            id: managerMainMenu

            onAllCustomersClicked: loader.sourceComponent = allCustomersMenuComponent
            onExitClicked: exitManagerMenu()
        }
    }

    Component
    {
        id: allCustomersMenuComponent

        AllCustomersList
        {
            id: allCustomersListMenu

            onExitClicked: loader.sourceComponent = mainManagerMenuComponent
        }
    }
}

