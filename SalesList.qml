import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item {
    id:root
    width: 1024
    height: 600
    property int listWidth:title.width/5
    Component.onCompleted:
    {
        updatePageCount()
    }
    function updatePageCount(){
        pageNumberShow.text = calendarController.getCurrentPage()+"/"+Math.round(calendarController.getTotalQueryCount()/calendarController.getLimitSize())
    }
    Dialog{
        id:dialog
        visible:false
    }

    Rectangle{
        id:listRect
        width: parent.width*0.9
        height: parent.height*0.7
        anchors.centerIn: parent
        Rectangle{
            id:title
            height: 50
            anchors.top:parent.top
            anchors.left:parent.left
            anchors.right:parent.right
            border.width:2
            border.color:"black"
            z:1
            Grid {
                rows:1
                columns:5
                Rectangle {
                    width: listWidth
                    height: 50
                    border.width: 2
                    border.color:"lightgray"
                    color: "white"
                    Text {
                        text: qsTr("Fatura No")
                        font.bold:true
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    width: listWidth
                    height: 50
                    border.width: 2
                    border.color:"lightgray"
                    Text {
                        text: qsTr("İsim")
                        font.bold:true
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    width: listWidth
                    height: 50
                    border.width: 2
                    border.color:"lightgray"
                    Text {
                        id:priceText
                        text: qsTr("Fiyat")
                        font.bold:true
                        anchors.centerIn: parent
                    }
                    Image {
                        id: priceSortImage
                        anchors.left:priceText.right
                        anchors.top:parent.top
                        anchors.bottom:parent.bottom
                        source: "qrc:/assets/image/click.png"
                        width: priceText.height
                        fillMode:Image.PreserveAspectFit
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            if(calendarController.getSortQueryReceipt() === ""){
                                calendarController.setSortQueryReceipt("ASC");
                                priceSortImage.source = "qrc:/assets/image/down.png";
                            }else if(calendarController.getSortQueryReceipt() === "ASC"){
                                calendarController.setSortQueryReceipt("DESC");
                                priceSortImage.source = "qrc:/assets/image/up.png";
                            }else{
                                calendarController.setSortQueryReceipt("");
                                priceSortImage.source = "qrc:/assets/image/click.png";
                            }
                            calendarController.setCurrentPage(1);
                            nextPage.visible = true;
                            previousPage.visible = false;
                            updatePageCount()
                            calendarModel.modelReset();
                        }
                    }
                }
                Rectangle {
                    width: listWidth
                    height: 50
                    border.width: 2
                    border.color:"lightgray"
                    Text {
                        text: qsTr("Tarih")
                        font.bold:true
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    width: listWidth
                    height: 50
                    border.width: 2
                    border.color:"lightgray"
                    Text {
                        text: qsTr("Detay Görüntüle")
                        font.bold:true
                        anchors.centerIn: parent
                    }
                }
            }
        }
        ListView {
            id:listView
            anchors.top: title.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            model: calendarModel
            delegate: Item {
                width: parent.width
                height: 50
                Grid {
                    rows:1
                    columns:5
                    Rectangle {
                        width: listWidth
                        height: 50
                        border.width: 2
                        border.color:"lightgray"
                        color: index % 2 == 0 ? '#ccc' : 'transparent'
                        Text {
                            text: receipt_no
                            anchors.centerIn: parent
                        }
                    }

                    Rectangle {
                        width: listWidth
                        height: 50
                        border.width: 2
                        border.color:"lightgray"
                        color: index % 2 == 0 ? '#ccc' : 'transparent'
                        Text {
                            text: name
                            anchors.centerIn: parent
                        }
                    }

                    Rectangle {
                        width: listWidth
                        height: 50
                        border.width: 2
                        border.color:"lightgray"
                        color: index % 2 == 0 ? '#ccc' : 'transparent'
                        Text {
                            text: paid_amount
                            anchors.centerIn: parent
                        }
                    }
                    Rectangle {
                        width: listWidth
                        height: 50
                        border.width: 2
                        border.color:"lightgray"
                        color: index % 2 == 0 ? '#ccc' : 'transparent'
                        Text {
                            text: date_
                            anchors.centerIn: parent
                        }
                    }
                    Rectangle {
                        width: listWidth
                        height: 50
                        border.width: 2
                        border.color:"lightgray"
                        color: index % 2 == 0 ? '#ccc' : 'transparent'
                        Image {
                            source: "qrc:/assets/image/click.png"
                            width: 20
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn: parent
                        }
                        MouseArea{
                            anchors.fill:parent
                            onClicked: {
                                var receipt = calendarController.getOneReceipt(receipt_no)
                                dialog.title = receipt[1]+" Numaralı Fatura"
                                dialog.name=receipt[0]
                                dialog.receipt_no=receipt[1]
                                dialog.matrah=receipt[2]
                                dialog.date=receipt[3]
                                dialog.unit=receipt[4]
                                dialog.unit_price=receipt[5]
                                dialog.liter=receipt[6]
                                dialog.amount=receipt[7]
                                dialog.rate_value=receipt[8]
                                dialog.vat_amount=receipt[9]
                                dialog.explanation=receipt[10]
                                dialog.fic=receipt[11]
                                dialog.iic=receipt[12]
                                dialog.visible = true;
                            }
                        }
                    }
                }
            }
        }
    }
    Rectangle{
        width:parent.width
        anchors.top: listRect.bottom
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        Row{
            anchors.centerIn: parent
            height: parent.height*0.4
            spacing: 20
            Rectangle{
                id:previousPage
                visible:false
                width: 150
                height: parent.height
                color: previousPageButton.pressed ? "#89A8B2" : "#B3C8CF"
                Text {
                    anchors.centerIn: parent
                    text: "Previous Page"
                }
                MouseArea{
                    id:previousPageButton
                    anchors.fill: parent
                    onClicked: {
                        calendarController.setCurrentPage(calendarController.getCurrentPage()-1);
                        if(calendarController.getCurrentPage() === 1)
                            parent.visible = false;
                        else{
                            nextPage.visible = true
                        }
                        calendarModel.modelReset();
                        updatePageCount()
                    }
                }
            }
            Rectangle{
                width: 100
                height: parent.height
                Text {
                    id:pageNumberShow
                    anchors.centerIn: parent
                    text: qsTr("Current Page/Page Count")
                }
            }
            Rectangle{
                id:nextPage
                width: 150
                height: parent.height
                color: nextPageButton.pressed ? "#89A8B2" : "#B3C8CF"
                Text {
                    anchors.centerIn: parent
                    text: "Next Page"
                }
                MouseArea{
                    id:nextPageButton
                    anchors.fill: parent
                    onClicked: {

                        calendarController.setCurrentPage(calendarController.getCurrentPage()+1);
                        if(calendarController.getCurrentPage() !== 1 )
                            previousPage.visible = true

                        calendarModel.modelReset();
                        if(Math.round(calendarController.getTotalQueryCount()/calendarController.getLimitSize()) === calendarController.getCurrentPage())
                        {
                            parent.visible = false;
                        }
                        updatePageCount()
                    }
                }
            }
        }
    }
    Rectangle{
        width: 100
        height: 50
        border.width: 2
        border.color:"lightgray"
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        color: cancelButton.pressed ? "#A31D1D" : "#D84040"
        Text {
            id:cancelText
            text: "Cancel"
            anchors.centerIn: parent
            color:"white"
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
