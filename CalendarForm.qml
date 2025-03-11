import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Item {
    id:calendarForm

    property string dateType : "";

    Rectangle{
        id:body
        width:componenWidth
        height: parent.height*0.76
        anchors.top:parent.top
        anchors.centerIn: parent

        Column{
            id:selectDateColumn
            spacing:5
            TextField{
                id:beginDateText
                width: componenWidth
                height: componenHeight
                placeholderText: "Enter Begin Date!"
                font.pixelSize: 32
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                style: TextFieldStyle {
                    textColor: "black"
                    background: Rectangle {
                        radius: 5
                        border.color: "#5AB2FF"
                        border.width: 1

                    }
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 2
                    verticalOffset: 2
                    radius: 8.0
                    samples: 17
                    color: "#5AB2FF"
                }
                MouseArea{
                    id:beginDateButton
                    anchors.fill:parent
                    onClicked: {
                        stackView.push(
                                    calendarWidget,
                                    {
                                        "dateType":"begin",
                                        "popHandler": handleStackViewPop
                                    })
                    }
                }
            }
            TextField{
                id:lastDateText
                width: componenWidth
                height: componenHeight
                placeholderText: "Enter Last Date!"
                font.pixelSize: 32
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                style: TextFieldStyle {
                    textColor: "black"
                    background: Rectangle {
                        radius: 5
                        border.color: "#5AB2FF"
                        border.width: 1

                    }
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 2
                    verticalOffset: 2
                    radius: 8.0
                    samples: 17
                    color: "#5AB2FF"
                }
                MouseArea{
                    id:endDateButton
                    anchors.fill:parent
                    onClicked: {
                        stackView.push(
                                    calendarWidget,
                                    {
                                        "dateType":"end",
                                        "popHandler": handleStackViewPop
                                    })
                    }
                }
            }
            Rectangle{
                id:searchButtonRect
                width: componenWidth
                height: componenHeight
                border.color:"#ccc"
                Image {
                    id: searchButtonImage
                    width: 50
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/assets/image/search.png"
                    anchors.centerIn: parent
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 2
                    verticalOffset: 2
                    radius: 8.0
                    samples: 17
                    color: "#5AB2FF"
                }
                MouseArea{
                    id:searchButton
                    anchors.fill:parent
                    onClicked: {
                        if(isNaN(calendarController.getBeginDate())){
                            console.log("Başlangıç Tarihi Seçmediniz!")
                        }else if(isNaN(calendarController.getEndDate())){
                            console.log("Bitiş Tarihi Seçmediniz")
                        }else if(calendarController.getBeginDate() > calendarController.getEndDate()){
                            console.log("Başlangıç Tarihi Bitiş Tarihinden Sonra Olamaz");
                        }else{
                            stackView.push(salesList)
                        }

                    }
                }
            }
        }
    }
    function handleStackViewPop(properties) {
        if (properties && properties.dateType) {
            if (properties.dateType === "begin") {
                calendarController.setBeginDate(Qt.formatDate(properties.selectedDate,"yyyy-MM-dd"))
                beginDateText.text = Qt.formatDate(properties.selectedDate,"yyyy-MM-dd") || ""
            } else if (properties.dateType === "end") {
                calendarController.setEndDate(Qt.formatDate(properties.selectedDate,"yyyy-MM-dd"))
                lastDateText.text = Qt.formatDate(properties.selectedDate,"yyyy-MM-dd") || ""
            }
        }
    }
}
