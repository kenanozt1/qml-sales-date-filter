import QtQuick 2.0

Item {
    width: 1024
    height: 600
    Rectangle{
        id:bottom
        width:parent.width
        height: parent.height*0.1
        anchors.top:body.bottom
        x:width-backButton.width-5
        Image {
            visible:false
            id: backButton
            source: "qrc:/assets/image/back.png"
            width: 50
            fillMode: Image.PreserveAspectFit
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    stackView.push(calendarPage)
                }
            }
        }
    }
}
