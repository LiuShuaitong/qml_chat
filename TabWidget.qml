import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    id: tabWidget
    default property alias content: stack.children
    property int current: 0
    onCurrentChanged: setOpacities()
    Component.onCompleted: setOpacities()

    function setOpacities() {
        for (var i = 0; i < stack.children.length; ++i) {
            stack.children[i].opacity = (i == current ? 1 : 0)
        }
    }

    function headericon(index)
    {
        switch(index)
        {
        case 0:
            return "image/image/icon_chat_check.png"
        case 1:
            return "image/image/icon_address_check.png"
        case 2:
            return "image/image/icon_file_check.png"
        }
    }

    Column {
        id: header
        topPadding: 50

        Image {
            id: id_selficon
            x: 13
            width: 44
            height: 44
            source: "image/image/head1.png"
            sourceSize: Qt.size(44,44)

            MouseArea{
                anchors.fill: parent;
                onClicked: {
                    console.log(qsTr("点击头像了"))
                }
            }
        }

        Repeater {
            model: stack.children.length
            delegate: Rectangle {
                color: "#4F4A4D"
                width: 70;
                height: 60

                Button{
                    anchors.fill: parent
                    onCheckedChanged: {
                        console.log(checked == true)
                    }
                    Image {
                        id: id_chat_icon
                        width: 35
                        height: 35
                        x: (parent.width - width) / 2
                        y: (parent.height - height) / 2
                        sourceSize: Qt.size(35,35)
                        source:headericon(index)
                    }
                    onClicked: {
                        tabWidget.current = index
                    }
                    background: Rectangle{
                        border.width: 0;
                        color: "transparent"
                    }
                }
            }
        }
    }

    Item {
        id: stack
        width: tabWidget.width
        anchors.top: tabWidget.top
        anchors.left: header.right
        anchors.bottom: tabWidget.bottom
    }
}
