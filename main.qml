import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {

    id: id_application_window
    visible: true
    width: 1000
    height: 730
    title: qsTr("Stack")
    background: Rectangle{
        color: "#4F4A4D"
    }

    TabWidget {
        id: id_tabs
        width: parent.width
        height: parent.height

        Rectangle {
            property string title: "Red"
            anchors.fill: parent
            color: "#e3e3e3"
            Rectangle {
                anchors.fill: parent;
                color: "#ff7f7f"
                // 聊天用户form
                ChatUserForm{
                    id: id_chat_user_form
                    width: 260
                    height: parent.height
                }
                ChatListForm{
                    // 聊天历史记录
                    id:id_chat_list_form
                    x: id_chat_user_form.width
                    width: parent.width - id_chat_user_form.width - 70;
                    height: parent.height
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


