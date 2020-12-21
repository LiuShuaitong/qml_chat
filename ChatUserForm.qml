import QtQuick 2.7
import QtQuick.Controls 2.2
import QtPositioning 5.5
import QtLocation 5.6

Rectangle {
    id: id_chat_user_form
    border.width: 1;
    border.color: "#E7E7E7"
    radius:  2;
    Column {
        Rectangle {
            id: id_top_view
            width: id_chat_user_form.width - 2
            height: 50
            x:1
            Row
            {
                topPadding: 10
                leftPadding: 10
                Rectangle{
                    width: 200
                    height: 30
                    color: "#E6E6E6"
                    radius: 4;
                    //这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
                    clip:true

                    Row{

                        leftPadding: 5

                        Button{
                            property alias name_edit: id_name_edit.text;
                            y: 5
                            width: 20
                            height: 20
                            Image {
                                sourceSize.width: 20
                                sourceSize.height: 20
                                source: "image/image/search.png"
                            }

                            background: Rectangle{
                                color: "transparent"
                            }

                            onClicked: {
                                $chat_list_manager.search(name_edit)
                            }
                        }

                        TextField{
                            id: id_name_edit;
                            width: 175
                            height: 30
                            // 宽度不够显示时的，滚动
                            autoScroll: true;
                            clip:true;
                            font.pixelSize: 12
                            font.family: "微软雅黑"
                            verticalAlignment: Text.AlignVCenter;
                            selectByMouse:true;
                            placeholderText:qsTr("搜索");

                            background: Rectangle{
                                border.width: 0;
                                color: "transparent"
                                implicitHeight: 25;
                                implicitWidth: 175
                            }
                            onTextChanged: {
                                $chat_list_manager.search(text)
                            }
                        }

                    }

                }
            }

            color: "#FBFBFB"
        }

        Rectangle {
            x: 1
            width: id_chat_user_form.width - 2
            height: id_chat_user_form.height - id_top_view.height
            ListView{
                anchors.fill: parent
                model: $chat_model
                // 切换 item 的时候将 currentIndex 也跟随着变化
                highlightRangeMode: ListView.ApplyRange
                // 禁止首尾滑动
//                boundsBehavior:Flickable.StopAtBounds
                onCurrentIndexChanged: {
                    $chat_list_manager.clickChatList(currentIndex)
                }
                delegate: ChatUserDelegate{}

                ScrollBar.vertical: ScrollBar {
                    id: verScrollBar
                }
            }

        }

    }
}
