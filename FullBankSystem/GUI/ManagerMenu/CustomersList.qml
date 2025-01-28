import QtQuick
import QtQuick.Controls


Item {

    property var customersList: []

    anchors.fill: parent

    ScrollView
    {
        id: scrollView

        anchors.left: parent.horizontalCenter
        anchors.leftMargin: -100
        y: 40
        width: 350
        height: 400

        contentHeight: 600
        clip: true

        ScrollBar.vertical.policy: ScrollBar.AsNeeded

        ScrollBar.vertical.background: Rectangle
        {
            anchors.fill: parent
            color: "lightblue"
        }

        ListView
        {
            anchors.fill: parent

            spacing: 4

            model: customersList
            delegate: ItemDelegate
            {
                width: parent.width

                background: Rectangle
                {
                    color: "transparent"
                }

                Text
                {
                    id: textList

                    text: qsTr(modelData)
                    font.family: "Consolas"
                    color: "white"
                }
            }
        }
    }

}
