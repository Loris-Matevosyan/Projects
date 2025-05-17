import QtQuick
import QtQuick.Controls


Button
{
    id: mainbutton

    x: (parent.width / 2) - (width / 2)
    width: 200
    height: 40

    text: qsTr("Enter as a customer")
    font.pixelSize: 15
    font.italic: true

    background: Rectangle
    {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "greenyellow" }
            GradientStop { position: 1.0; color: "springgreen" }
        }
        border.color: "green"
        radius: 4
    }


}
