import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
Item {
    id:root
    property string receipt_no: "Fiş Numarası"
    property string name: "Ürün Adı"
    property string unit : "Satış birimi"
    property string unit_price: "Satış Birim Fiyatı"
    property string liter: "Satılan Litre"
    property string matrah: "Vergisiz Fiyat"
    property string amount: "Ürün Fiyatı"
    property string rate_value:"Vergi Oranı %"
    property string vat_amount : "Veri fiyatı"
    property string date: "Satış Tarihi"
    property string explanation : "Durum"
    property string fic : "Fic No"
    property string iic : "iic"

    property string bgColortitle : "#5AB2FF"
    property string bgColor : "#C6E7FF"
    property string title : "title";
    visible: true
    width: parent.width
    height: parent.height
    z:1
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#000000"
        opacity: 0.4
        MouseArea{
            anchors.fill:parent
            onClicked: {
//                console.log("tıklandı")
//                root.visible=false
            }
        }
    }

    Rectangle{
        z:3
        anchors.centerIn: parent
        width: parent.width*0.5
        height: parent.height*0.7
        color: bgColor
        radius:10
        clip:true
        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
            horizontalOffset: 2
            verticalOffset: 2
            radius: 8.0
            samples: 17
            color: "#5AB2FF"
        }
        Rectangle{
            id:titleRect
            width: parent.width
            height: parent.width*0.1
            border.width: 2
            border.color:"lightgray"
            color: bgColortitle
            Text {
                id:titleText
                anchors.centerIn: parent
                text: title
                font.pixelSize: 28
                font.bold:true
                color:"black"
            }
            Rectangle{
                id:cancelButtonRect
                width: 50
                height: width
                color: cancelButton.pressed ? "#A31D1D" : "#D84040"
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.top:parent.top
                radius: 10
                Text {
                    anchors.centerIn: parent
                    id: cancelButtonText
                    text: "X"
                    color: "white"
                    font.bold: true
                    font.pixelSize: 30
                }
                MouseArea{
                    id:cancelButton
                    anchors.fill:parent
                    onClicked: {
                        root.visible=false;
                    }
                }
            }
        }
        Rectangle{
            width: parent.width
            height: parent.height-titleRect.height
            anchors.top: titleRect.bottom
            color: bgColor
            Rectangle{
                id:block
                width: parent.width
                height: parent.height
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.margins: 20
                color: "white"
                radius: 10
                z:1

                Column{
                    spacing: 10
                    anchors.fill: parent
                    anchors.margins: 10
                    Text {
                        id: receiptNoText
                        text: "Receipt No : "+receipt_no
                    }
                    Text {
                        id: nameText
                        text: "Ürün Adı : "+name
                    }
                    Text {
                        id: unitText
                        text: "Ürün Birimi : "+unit
                    }
                    Text {
                        id: unitPriceText
                        text: "Birim Fiyatı : "+unit_price
                    }

                    Text {
                        id: literTtext
                        text: "Ürün Birimi : "+liter
                    }
                    Text {
                        id: matrahText
                        text: "Matrah : "+matrah
                    }
                    Text {
                        id: amountText
                        text: "Fiyat : "+amount
                    }
                    Text {
                        id: vatRateText
                        text: "Vergi Oranı(%) : "+rate_value
                    }
                    Text {
                        id: vatAmountText
                        text: "Vergi Fiyatı : "+vat_amount
                    }
                    Text {
                        id: dateText
                        text: "Tarih : "+date
                    }
                    Text {
                        id: explanationTtext
                        text: "Durum : "+explanation
                    }
                    Text {
                        id: ficText
                        text: "FIC No : "+fic
                    }
                    Text {
                        id: iicText
                        text: "IIC NO : "+iic
                    }
                }
            }
        }
    }
}
