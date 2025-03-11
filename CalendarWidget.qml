import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item{
    id:calendarWidget
    width:1024
    height: 600

    property string dateType : ""
    property var popHandler: null

    Component.onCompleted: {
        if(!isNaN(calendarController.getBeginDate()) && dateType == "end"){
            calendar.minimumDate = calendarController.getBeginDate()
        }
        if(!isNaN(calendarController.getEndDate()) && dateType == "begin"){
            calendar.maximumDate = calendarController.getEndDate()
        }
    }

    Rectangle{
        id:calendarRect
        anchors.centerIn: parent
        width: parent.width*0.9
        height: parent.height*0.9

        Calendar{
            id:calendar
            width:parent.width
            height: parent.height*0.8
            locale:Qt.locale("tr-TR")
        }
        Rectangle{
            id:bottom
            width:parent.width/2
            height: parent.height*0.1
            anchors.bottom: calendarRect.bottom
            anchors.right: calendarRect.right
            Row{
                width: parent.width
                height: parent.height
                spacing:10
                Rectangle{
                    width: parent.width/2
                    height: parent.height
                    color: selectButton.pressed ? "#211C84" : "#3674B5"
                    Text {
                        id: nameSelect
                        text: "Select"
                        anchors.centerIn: parent
                        color:"white"
                        font.pixelSize: 18
                    }
                    MouseArea{
                        id:selectButton
                        anchors.fill:parent
                        onClicked: {
                            if (popHandler) {
                                popHandler({
                                               "dateType": dateType,
                                               "selectedDate": calendar.selectedDate
                                           })
                            }
                            stackView.pop({'dateType':dateType})
                        }
                    }
                }

                Rectangle{
                    width: parent.width/2
                    height: parent.height
                    color: cancelButton.pressed ? "#A31D1D" : "#D84040"
                    Text {
                        id: nameCancel
                        text: "Cancel"
                        anchors.centerIn: parent
                        color:"white"
                        font.pixelSize: 18
                    }
                    MouseArea{
                        id:cancelButton
                        anchors.fill:parent
                        onClicked: {
                            stackView.pop()
                        }
                    }
                }
            }
        }

    }
}
