import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
Window {
    visible: true
    width: 1024
    height: 600
    title: "Satış Listeleme"
//    visibility: "FullScreen"

    property int componenWidth : width*0.7
    property int componenHeight : height*0.26

    StackView{
        id:stackView
        anchors.fill:parent
        initialItem: calendarForm
    }
    Component{
        id:calendarForm
        CalendarForm{}
    }
    Component{
        id:calendarWidget
        CalendarWidget{}
    }
    Component{
        id:salesList
        SalesList{}
    }
}
