import QtQuick


Item
{
    id: managerItem

    anchors.fill: parent

    signal addCustomerClicked
    signal deleteCustomerClicked
    signal blockCustomerClicked
    signal allCustomersClicked
    signal vipCustomersClicked
    signal standardCustomersClicked
    signal blockedCustomersClicked
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

                MenuButton{ text: qsTr("Add customer"); onClicked: addCustomerClicked() }
                MenuButton{ text: qsTr("Delete customer"); onClicked: deleteCustomerClicked() }
                MenuButton{ text: qsTr("Block customer"); onClicked: blockCustomerClicked() }
                MenuButton{ text: qsTr("List all customers"); onClicked: allCustomersClicked() }
                MenuButton{ text: qsTr("List VIP customers"); onClicked: vipCustomersClicked() }
            }

            Column
            {
                spacing: 20

                MenuButton{ text: qsTr("List standard customers"); onClicked: standardCustomersClicked() }
                MenuButton{ text: qsTr("List blocked customers"); onClicked: blockedCustomersClicked() }
                MenuButton{ text: qsTr("Bank revenue"); onClicked: bankRevenueClicked() }
                MenuButton{ text: qsTr("Exit menu"); onClicked: exitClicked() }
            }
        }
    }
}

