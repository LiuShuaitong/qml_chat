import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle {
    id: id_chatview
    objectName: "id_chatview"

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
            delegate:ChatRecordDelegate{}
            ScrollBar.vertical: ScrollBar {
                id: verScrollBar
            }
        }
    }

    function position(){
        listView.positionViewAtEnd()
    }

    Component.onCompleted: {
        listView.positionViewAtEnd()
    }
}
