import QtQuick
import QtQuick.Controls
import main.Database


Item
{
    anchors.fill: parent

    signal exitClicked

    Rectangle
    {
        id: rectColor

        anchors.fill: parent

        gradient: Gradient {
            GradientStop { position: 0.0; color: "darkslateblue" }
            GradientStop { position: 1.0; color: "skyblue" }
        }

        CustomersList
        {
            customersList: Database.allCustomers()
        }

        Button
        {
            id: backButton

            background: Rectangle
            {
                id: backRect

                anchors.fill: parent

                color: "skyblue"
                border.color: "darkblue"
                radius: 10
            }

            x: 40
            y: parent.height - 40

            width: 80
            height: 20

            font.pixelSize: 15
            font.italic: true

            text: qsTr("Back")

            onClicked: exitClicked()
        }
    }

}
