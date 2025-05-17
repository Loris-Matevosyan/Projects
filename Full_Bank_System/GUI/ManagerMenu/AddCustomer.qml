import QtQuick
import QtQuick.Controls

Item
{
    id: addCustomer

    anchors.fill: parent

    signal acceptClicked
    signal exitClicked

    Rectangle
    {
        id: rectColor

        anchors.fill: parent

        gradient: Gradient {
            GradientStop { position: 0.0; color: "darkslateblue" }
            GradientStop { position: 1.0; color: "skyblue" }
        }

        Text
        {
            id: suggestionText

            x: 50
            y: 90
            width: 190
            height: 30

            text: qsTr("Enter information below")
            font.pixelSize: 16
            font.bold: true
            font.italic: true
            color: "darkBlue"
        }

        CustomTextInput
        {
            id: fieldFirstName

            addYAxis: 0

            shownText: "First name"
        }

        CustomTextInput
        {
            id: fieldLastName

            addYAxis: 40

            shownText: "Last name"
        }

        MenuButton
        {
            id: exitButton

            x: parent.width - 240
            y: parent.height - 60

            text: qsTr("Exit")

            onClicked: exitClicked()
        }

        MenuButton
        {
            id: acceptButton

            x: 40
            y: parent.height - 60

            text: qsTr("Accept")

            onClicked: acceptClicked()
        }
    }
}




