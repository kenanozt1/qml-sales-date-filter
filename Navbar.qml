import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
Item {
    width: 1024
    height: 600
    Rectangle{
        id:navbar
        width:parent.width
        height: parent.height*0.1
        border.color:"#008DDA"
        border.width:2
        color:"transparent"

        Rectangle{
            id: homeImage
            width: 50
            height: parent.height
            color:"transparent"
            Image {
                source: "qrc:/assets/image/home.png"
                width: parent.width
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle{
            width: parent.width-homeImage.width
            height: parent.height
            anchors.left:homeImage.right
            color:"transparent"
            Text {
                id: navbarText
                text: "Satış Listeleme"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill:parent
                anchors.centerIn: parent
                color:"#000"
            }
        }
    }
}
