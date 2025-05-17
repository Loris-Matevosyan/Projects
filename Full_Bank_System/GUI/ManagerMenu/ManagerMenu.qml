import QtQuick


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

            onAddCustomerClicked: loader.sourceComponent = addCustomerMenuComponent
            onAllCustomersClicked: loader.sourceComponent = allCustomersMenuComponent
            onVipCustomersClicked: loader.sourceComponent = vipCustomersMenuComponent
            onStandardCustomersClicked: loader.sourceComponent = standardCustomersMenuComponent
            onExitClicked: exitManagerMenu()
        }
    }

    Component
    {
        id: allCustomersMenuComponent

        CustomersListTemplate
        {
            id: allCustomersListMenu

            listType: "All customers"

            onExitClicked: loader.sourceComponent = mainManagerMenuComponent
        }
    }

    Component
    {
        id: vipCustomersMenuComponent

        CustomersListTemplate
        {
            id: vipCustomersListMenu

            listType: "Vip customers"

            onExitClicked: loader.sourceComponent = mainManagerMenuComponent
        }
    }

    Component
    {
        id: standardCustomersMenuComponent

        CustomersListTemplate
        {
            id: standardCustomersListMenu

            listType: "Standard customers"

            onExitClicked: loader.sourceComponent = mainManagerMenuComponent
        }
    }

    Component
    {
        id: addCustomerMenuComponent

        AddCustomer
        {
            id: addCustomerMenu

            onExitClicked: loader.sourceComponent = mainManagerMenuComponent
        }
    }

}





























