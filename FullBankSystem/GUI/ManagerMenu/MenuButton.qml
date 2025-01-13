import QtQuick 2.15
import QtQuick.Controls


Button
{
    id: mainButton

    width: 200
    height: 40

    font.pixelSize: 15
    font.italic: true

    background: Rectangle
    {
        gradient: Gradient {
            GradientStop { position: 0.0; color: "darkslateblue" }
            GradientStop { position: 1.0; color: "skyblue" }
        }

        border.color: "darkblue"
        radius: 4
    }

}
