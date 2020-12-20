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
        height: 40
        anchors.bottom: parent.bottom
        id:bottomrect
            Row{
            TextField{
                id:textfield
                placeholderText: "输入内容"
                height:bottomrect.height
                width:id_chat_form.width*0.8
            }
            Button{
                text:"发送"
                background: Rectangle{
                    color: "#FFA07A"
                }

                height:bottomrect.height
                width:id_chat_form.width*0.2
                onClicked: {
                    listmodel.append({"detail":textfield.text})
                }
            }
        }
    }
}
