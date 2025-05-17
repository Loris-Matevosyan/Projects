import QtQuick
import BankSystem.GUI.MainMenu
import BankSystem.GUI.ManagerMenu


Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Loader
    {
        id: loader

        anchors.fill: parent
        sourceComponent: mainComponent
    }

    Component
    {
        id: mainComponent

        MainMenu
        {
            id: mainMenu

            onManagerClicked: loader.sourceComponent = managerComponent
        }
    }

    Component
    {
        id: managerComponent

        ManagerMenu
        {
            id: managerMenu

            onExitManagerMenu: loader.sourceComponent = mainComponent
        }
    }
}

