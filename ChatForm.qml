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
//            color: "#FF0000"
            color: "#ACB2C2"
        }
    }

    /*
    ListView{
        add: Transition {
            //设置增加Item时的动画 from 100,100  to不设置 就是默认在ListView
            NumberAnimation { properties: "x,y"; from: 100; duration: 1000 }
        }
        id: id_chat_view
        anchors.top: parent.top
        anchors.bottom: bottomrect.top
        anchors.left:parent.left
        anchors.right:parent.right
        //anchors的对象要么是兄弟结点（提供id）
        //要么就是子节点（parent）
        delegate:Component{ //这里delegate:后面必须是Component
           Rectangle{
                    width:window.width
                    height:label1.height+20
               BorderImage{
                       //聊天气泡
                       id:qipao
                       source:"/image/image/head1.png"
                       width:label1.width+20
                       height:label1.height<=30?30:label1.height+5
                     //  width:20
                       border.left: 10
                       border.right: 10
                       border.top:10
                       border.bottom:10
                       x:parent.width-width
                       Text{
                           id:label1
                           width:label1.text.length<=10?label1.text.length*12:120
                           font.pixelSize: 12
                           anchors.centerIn:parent
                           anchors.leftMargin:10
                           wrapMode: Text.Wrap //多行文本 超过width就自动换行
                           text:detail
                           color: "#000000"
                       }
                   }
           }
       }
       model:ListModel{
           id:listmodel
           ListElement{
                detail:"你好这是内容哈哈"
           }
       }
    }
*/

    Rectangle{
        y: parent.height - 180
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
