import QtQuick 2.0
import QtQuick.Controls 2.2

ItemDelegate {
    checkable: true
    width: parent.width
    height: 75

    onClicked: {
        ListView.view.currentIndex = index
    }

    Rectangle {
        width: parent.width;
        height: 1
        anchors {
            top: parent.top;
            bottomMargin: 1
        }
        color: "#ACB2C2"
    }

    Image {
        x: 10
        y: 15
        sourceSize: Qt.size(45,45)
        source: "image/image/head1.png"
    }

    Label{
        x:65
        y:15
        width: 120
        height: 15
        text: mdName;
    }

    Label{
        x:200
        y:15
        width: 60
        height: 15
        text: mdTime
        font.pixelSize: 10
    }

    Label{
        x:65
        y:45
        color: "#888888"
        width: 150
        height: 15
        text: mdMsg;
        font.pixelSize: 12
    }

}
