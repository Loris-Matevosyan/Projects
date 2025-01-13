import QtQuick 2.15


Item
{
    id: managerItem

    anchors.fill: parent

    signal allCustomersClicked
    signal vipCustomersClicked
    signal standardCustomersClicked
    signal blockedCustomersClicked
    signal blockAccountClicked
    signal bankRevenueClicked
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
            id: textHello

            x: 80
            y: 40
            width: 480
            height: 70

            text: qsTr("Hello Dear Manager")
            color: "#222466"

            font.pixelSize: 50
            font.italic: true
            font.bold: true
        }

        Grid
        {
            anchors.top: textHello.bottom
            anchors.topMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter

            columnSpacing: 40

            columns: 2

            Column
            {
                spacing: 20

                MenuButton{ text: qsTr("List all customers"); onClicked: allCustomersClicked() }
                MenuButton{ text: qsTr("List VIP customers"); onClicked: vipCustomersClicked() }
                MenuButton{ text: qsTr("List standard customers"); onClicked: standardCustomersClicked() }
                MenuButton{ text: qsTr("List blocked customers"); onClicked: blockedCustomersClicked() }
            }

            Column
            {
                spacing: 20

                MenuButton{ text: qsTr("Block account"); onClicked: blockAccountClicked() }
                MenuButton{ text: qsTr("Bank revenue"); onClicked: bankRevenueClicked() }
                MenuButton{ text: qsTr("Exit menu"); onClicked: exitClicked() }
            }
        }
    }
}

