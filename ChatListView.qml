import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle {
    id: id_chatview

    ColumnLayout {
        id:id_page
        anchors.fill: parent
        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins:14
            Layout.rightMargin: 0
            displayMarginBeginning: 40
            displayMarginEnd: 40
            spacing:14
            model:$record_model

            delegate: Column {

                anchors.left: parent.left
                spacing: 14
                width: parent.width

                //时间
                Rectangle {
                    width: id_time.implicitWidth + 10
                    height: id_time.implicitHeight + 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    visible: index%6 ? false : true
                    color: "transparent"
                    Label {
                        id: id_time
                        text: mdTime
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "#B2B3B3"
                        font.pointSize: 11
                        anchors.fill: parent
                        anchors.margins:0
                    }
                }

                //消息内容
                Row {
                    id: id_leftRow
                    spacing: 6
                    anchors.left: parent.left
                    visible: !mdSender

                    //头像
                    Image {
                        id: avatarLeft
                        height: 35
                        width: height
                        source: "image/image/head1.png"
                    }

                    //消息框
                    Rectangle {
                        width: Math.min(id_msgtext_left.implicitWidth +14, listView.width - 200)
                        height: id_msgtext_left.implicitHeight + 16
                        color:  mdSender ? "#9dea6a" : "#ffffff"
                        radius: 3
                        TextEdit {
                            id: id_msgtext_left
                            text: mdMsg
                            font.family: qsTr("微软雅黑")
                            font.pointSize: 13
                            anchors.fill: parent
                            anchors.margins: 5
                            wrapMode: TextEdit.Wrap
                            readOnly: true
                            selectByKeyboard: true
                            selectByMouse: true
                            // 选择区域在失去焦点是否还保持
                            persistentSelection:true
                            selectionColor: "#BAD7FB"
                        }
                    }
                }

                Row {
                    id: id_rightRow
                    spacing: 6
                    anchors.right: parent.right
                    visible: mdSender
                    rightPadding: 15
                    //消息框
                    Rectangle {
                        width: Math.min(id_msgtext_right.implicitWidth +14, listView.width - 200)
                        height: id_msgtext_right.implicitHeight + 16
                        color:  mdSender ? "#9dea6a" : "#eeeeee"
                        radius: 3

                        TextEdit {
                            id: id_msgtext_right
                            text: mdMsg
                            font.family: qsTr("微软雅黑")
                            font.pointSize: 13
                            anchors.fill: parent
                            anchors.margins: 5
                            wrapMode: TextEdit.Wrap
                            readOnly: true
                            selectByKeyboard: true
                            selectByMouse: true
                            // 选择区域在失去焦点是否还保持
                            persistentSelection:true
                            selectionColor: "#BAD7FB"
                        }
                    }

                    //头像
                    Image {
                        id: id_avatar_right
                        height: 36
                        width: height
                        source: "image/image/head1.png"
                    }
                }

            }

            ScrollBar.vertical: ScrollBar {
                id: verScrollBar
            }
        }
    }

    Component.onCompleted: {
        listView.positionViewAtEnd()
    }
}
