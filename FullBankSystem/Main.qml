import QtQuick
import BankSystem.GUI.MainMenu

Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Loader
    {
        id: loaderOne

        anchors.fill: parent
        sourceComponent: mainMenu
    }

    MainMenu
    {
        id: mainMenu
    }

}

