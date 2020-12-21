import QtQuick 2.2
import QtQuick.Controls 2.2

Rectangle {
    id: id_chat_form
    objectName: "id_chat_form"
    function chatName(name){
        console.log(name);
    }

    ChatListView{
        y: id_chat_top.height
        width: parent.width
        height: parent.height - id_chat_top.height - id_message_view.height - id_send_btn.height
        color: "#F3F3F3"
    }

    // 顶部
    Rectangle{
        id: id_chat_top
        width: parent.width
        height: 50
        color: "#FBFBFB"
        Label{
            x:15
            y:15
            width: 300
            height: 20
            color: "#000000"
            font.pixelSize: 20
            font.bold:true
            text: $chat_list_manager.name;
            verticalAlignment: Text.AlignVCenter;
        }
        // 分割线
        Rectangle {
            width: parent.width;
            height: 1
            anchors {
                top: parent.bottom;
                bottomMargin: 1
            }
            color: "#ACB2C2"
        }
    }

    Rectangle{
        id: id_message_view
        y: parent.height - height -id_send_btn.height
        width: parent.width
        height: 150

        Rectangle {
            width: parent.width;
            height: 1
            anchors {
                top: parent.top;
                bottomMargin: 1
            }
            color: "#ACB2C2"
        }

        Flickable{
            id : flick
            clip: true
            anchors.fill: parent
            contentHeight: id_message_eidt.implicitHeight

            function ensureVisible(r){
                if (contentX >= r.x)
                    contentX = r.x;
                else if (contentX+width <= r.x+r.width)
                    contentX = r.x+r.width-width;
                if (contentY >= r.y)
                    contentY = r.y;
                else if (contentY+height <= r.y+r.height)
                    contentY = r.y+r.height-height;
            }

            TextEdit{
                id: id_message_eidt
                x:2
                width: parent.width
                selectByKeyboard: true
                selectByMouse: true
                wrapMode: TextEdit.Wrap
                textFormat: TextEdit.AutoText
                font.family: qsTr("微软雅黑")
                font.pointSize: 18
                focus: true
                onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
            }
            ScrollBar.vertical: ScrollBar {
                id: verScrollBar
            }
        }
    }

    Button{
        property alias msg_edit: id_message_eidt.text;
        id:id_send_btn
        text:"发送"
        background: Rectangle{
            color: "#57BD6B"
        }
        width:70
        height:30
        x:parent.width - width
        y:parent.height - height
        onClicked: {
            $chat_record_manager.send(msg_edit)
            id_message_eidt.clear()
            id_message_eidt.forceActiveFocus()
        }
    }
}
