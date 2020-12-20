import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle {

    id: id_chatview

    ColumnLayout {
        id:page
        anchors.fill: parent

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins:14
            Layout.rightMargin: 0
            displayMarginBeginning: 40
            displayMarginEnd: 40
            verticalLayoutDirection: ListView.BottomToTop
            spacing:14
            model:10
            delegate: Column {

                anchors.left: parent.left
                spacing: 14
                width: parent.width

                property bool sendmessage: send
                property bool sameTime: same

                property bool same: false
                property string msgTime: "2012/12/12"
                property bool send: true
                property string content: qsTr("峡谷之巅，王者如你,峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你峡谷之巅，王者如你")
                //时间
                Rectangle {
                    width: id_time.implicitWidth + 10
                    height: id_time.implicitHeight + 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    visible: !same
                    Label {
                        id: id_time
                        text: msgTime
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "#B2B3B3"
                        font.pointSize: 10
                        anchors.fill: parent
                        anchors.margins:0
                    }
                }

                //消息内容
                Row {
                    id: id_leftRow
                    spacing: 6
                    anchors.left: parent.left
                    visible: !send
                    //头像
                    Image {
                        id: avatarLeft
                        height: 36
                        width: height
                        source: "image/image/head1.png"
                    }

                    //消息框
                    Rectangle {
                        width: Math.min(id_msgtext_left.implicitWidth +14, listView.width -98)
                        height: id_msgtext_left.implicitHeight + 16
                        color:  send ? "#9dea6a" : "#eeeeee"
                        radius: 3

                        TextEdit {
                            id: id_msgtext_left
                            text: content
                            font.family: "华文细黑"
                            font.pointSize: 11
                            anchors.fill: parent
                            anchors.topMargin: 9
                            anchors.bottomMargin: 7
                            anchors.rightMargin: 7
                            anchors.leftMargin: 7
                            wrapMode: TextEdit.Wrap
                            enabled: true
                            readOnly: true
                            selectByKeyboard: true
                            selectByMouse: true
                            selectedTextColor: "white"
                            persistentSelection:true
                            selectionColor: "#3396FF"
                        }
                    }
                }

                Row {
                    id: id_rightRow
                    spacing: 6
                    anchors.left: parent.left
                    visible: send

                    //消息框
                    Rectangle {
                        width: Math.min(id_msgtext_right.implicitWidth +14, listView.width -98)
                        height: id_msgtext_right.implicitHeight + 16
                        color:  send ? "#9dea6a" : "#eeeeee"
                        radius: 3

                        TextEdit {
                            id: id_msgtext_right
                            text: content
                            font.family: "华文细黑"
                            font.pointSize: 11
                            anchors.fill: parent
                            anchors.topMargin: 9
                            anchors.bottomMargin: 7
                            anchors.rightMargin: 7
                            anchors.leftMargin: 7
                            wrapMode: TextEdit.Wrap
                            enabled: true
                            readOnly: true
                            selectByKeyboard: true
                            selectByMouse: true
                            selectedTextColor: "white"
                            persistentSelection:true
                            selectionColor: "#3396FF"
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
}
