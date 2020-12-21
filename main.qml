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

        Rectangle {
            anchors.fill: parent;
            Text {
                width: parent.width - 20
                anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                text: qsTr("通讯录")
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }

        Rectangle {
            anchors.fill: parent;

            Text {
                width: parent.width - 20
                anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                text: qsTr("文件库")
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }
    }
}


