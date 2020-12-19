import QtQuick 2.7
import QtQuick.Controls 2.2
import QtPositioning 5.5
import QtLocation 5.6

Rectangle {
    id: chatlistform
    border.width: 1;
    border.color: "#E7E7E7"
    radius:  2;

    Column {
        Rectangle
        {
            id: topRectangle
            width: chatlistform.width - 2
            height: 50
            x:1
            Row
            {
                topPadding: 10
                leftPadding: 10
                Rectangle{
                    id: searchRectangle
                    width: 200
                    height: 30
                    color: "#E6E6E6"
                    radius: 4;
                    //这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
                    clip:true

                    Row{

                        leftPadding: 5

                        Button{

                            property alias initTxt: txtinput.text;

                            id: seachbtn
                            y: 5
                            width: 20
                            height: 20
                            Image {
                                id: imgbtn
                                sourceSize.width: 20
                                sourceSize.height: 20
                                source: "image/image/search.png"
                            }

                            background: Rectangle{
                                color: "transparent"
                            }

                            onClicked: {
                                $chatmanager.search(initTxt)
                            }
                        }

                        TextField{
                            id: txtinput;
                            width: 175
                            height: 30
                            // 宽度不够显示时的，滚动
                            autoScroll: true;
                            clip:true;
                            font.pixelSize: 12
                            font.family: "微软雅黑"
                            verticalAlignment: Text.AlignVCenter;
                            selectByMouse:true;
                            focus: true;
                            placeholderText:qsTr("搜索");

                            background: Rectangle{
                                border.width: 0;
                                color: "transparent"
                                implicitHeight: 25;
                                implicitWidth: 175
                            }
                            onTextChanged: {
                                $chatmanager.search(text)
                            }
                        }

                    }

                }
            }

        }


        Rectangle {
            x: 1
            width: chatlistform.width - 2
            height: chatlistform.height - topRectangle.height
            ListView{
                id:listView
                anchors.fill: parent
                model: $Model
                onCurrentIndexChanged: {
                    console.log("current index = ",currentIndex)
                }
                delegate: ChatListDelegate{}
            }
        }

    }
}
