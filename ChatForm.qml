import QtQuick 2.2
import QtQuick.Controls 2.2

Rectangle {
    id: id_chat_form
    objectName: "id_chat_form"

    function chatName(name){
        console.log(name);
    }

    // 顶部
    Rectangle{
        id: id_chat_top
        width: id_chat_form.width
        height: 50
        color: "#FBFBFB"
        Label{
            id: id_chat_name
            x:10
            y:15
            width: 300
            height: 20
            color: "#000000"
            font.pixelSize: 20
            font.bold:true
            text: $chatmanager.name;
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

    ChatListView{
        id: id_chatview
        y: id_chat_top.height
        width: parent.width
        height: parent.height - id_chat_top.height - id_textview.height
        color: "#FFFFFF"
    }

    Rectangle{
        id: id_textview
        y: parent.height - height -id_sendbtn.height
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
            contentHeight: textInputId.implicitHeight

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
                id: textInputId
                x:2
//                y: -vbar.position * textInputId.height
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
        }

//        ScrollBar {
//        id: vbar
//        hoverEnabled: true
//        active: hovered || pressed
//        orientation: Qt.Vertical
//        size: parent.height / textInputId.height
//        width: 10
//        anchors.top: parent.top
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        stepSize: 0.01
//        }
    }


    Button{
        id:id_sendbtn
        text:"发送"
        background: Rectangle{
            color: "#57BD6B"
        }
        x:parent.width - width
        y:parent.height - height
        height:30
        width:70
        onClicked: {
            textInputId.clear()
            textInputId.forceActiveFocus()
        }
    }
}
