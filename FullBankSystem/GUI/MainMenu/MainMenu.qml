import QtQuick
import QtQuick.Controls


Item
{
    id: mainItem

    anchors.fill: parent

    signal managerClicked
    signal customerClicked

    Rectangle
    {
        id: rectColor

        anchors.fill: parent

        z: 0

        gradient: Gradient {
            GradientStop { position: 0.0; color: "greenyellow" }
            GradientStop { position: 1.0; color: "springgreen" }
        }
    }


    Text
    {
        id: bankText

        x: (parent.width / 2) - (width / 2)
        y: 50
        z: 1
        width: 530
        height: 70

        text: qsTr("BANK OF THE WORLD")
        color: "darkgreen"

        font.pixelSize: 50
        font.italic: true
        font.bold: true
    }


    Text
    {
        id: welcomeText

        x: (parent.width / 2) - (width / 2)
        y: bankText.y + bankText.height + 5
        z: 1
        width: 200
        height: 70

        text: qsTr("WELCOME")
        color: "mediumseagreen"


        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        font.italic: true
        font.bold: true

        ParallelAnimation
        {
            id: zoomingAnim

            NumberAnimation { target: welcomeText; property: "font.pixelSize"; from: 0; to: 50; duration: 1000 }
        }

    }

    MainButton
    {
        id: managerButton

        y: welcomeText.y + welcomeText.height + 40
        text: qsTr("Enter as a manager")

        onClicked: managerClicked()
    }

    MainButton
    {
        id: customerButton

        y: managerButton.y + managerButton.height + 20
        text: qsTr("Enter as a customer")

        onClicked: customerClicked()
    }

    Component.onCompleted: zoomingAnim.start()

}
