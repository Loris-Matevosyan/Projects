import QtQuick
import QtQuick.Controls


Item
{
    id: inputText

    property string shownText: ""
    property int addYAxis: 0

    TextField
    {
        id: filedLastName

        x: 50
        y: 140 + addYAxis
        width: 190
        height: 25

        font.pixelSize: 15
        placeholderText: qsTr(shownText)
    }
}
