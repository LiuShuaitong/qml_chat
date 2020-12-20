import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {

    id: window
    visible: true
    width: 1000
    height: 730
    title: qsTr("Stack")
    background: Rectangle{
        color: "#4F4A4D"
    }

    TabWidget {
        id: tabs
        width: parent.width
        height: parent.height

        Rectangle {
            property string title: "Red"
            anchors.fill: parent
            color: "#e3e3e3"
            Rectangle {
                anchors.fill: parent;
                color: "#ff7f7f"
                ChatListForm{
                    id: chatlistform
                    width: 260
                    height: window.height
                }
                ChatForm{
                    id:id_chat_form
                    x: chatlistform.width
                    width: parent.width - chatlistform.width - 70;
                    height: window.height
                    color: "#FFFFFF"
                }
            }
        }

        Rectangle {
            property string title: "Green"
            anchors.fill: parent
            color: "#e3e3e3"

            Rectangle {
                anchors.fill: parent; anchors.margins: 20
                color: "#7fff7f"
                Text {
                    width: parent.width - 20
                    anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                    text: "Flower stems are green"
                    font.pixelSize: 20
                    wrapMode: Text.WordWrap
                }
            }
        }

        Rectangle {
            property string title: "Blue"
            anchors.fill: parent; color: "#e3e3e3"

            Rectangle {
                anchors.fill: parent; anchors.margins: 20
                color: "#7f7fff"
                Text {
                    width: parent.width - 20
                    anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                    text: "Violets are blue"
                    font.pixelSize: 20
                    wrapMode: Text.WordWrap
                }
            }
        }
    }
}


