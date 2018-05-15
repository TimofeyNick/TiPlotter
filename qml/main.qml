import QtQuick 2.8
import QtQuick.Window 2.2
import TiPlotterItem 1.0

Window {
    readonly property real margin: 10

    visible: true
    width: 900
    height: 800

    Item {
        id: expressionItem

        width: label0.width + textEdit.width
        height: Math.max (label0.height, textEdit.height)
        anchors {
            top: parent.top
            left: parent.left
            margins: margin
        }

        Text {
            id: label0

            text: "y = "
            font.pixelSize: 16
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
            }
        }

        TextEdit {
            id: textEdit

            text: "5*sqrt(x)"
            font.pixelSize: 16
            anchors {
                left: label0.right
                verticalCenter: parent.verticalCenter
            }

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border {
                    color: "silver"
                    width: 1
                }
            }
        }
    }

    TiPlotterItem {
        id: plotterItem

        expression: textEdit.text
        anchors {
            top: expressionItem.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: margin
        }

        // Рамка
        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border {
                color: "silver"
                width: 1
            }
        }

        // Оси
        Rectangle {
            width: 1
            height: parent.height
            color: "silver"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Rectangle {
            height: 1
            width: parent.width
            color: "silver"
            anchors.verticalCenter: parent.verticalCenter
        }

        // Подписи к осям
        Text {
            text: "x"
            color: "silver"
            font.pixelSize: 16
            anchors {
                right: parent.right
                rightMargin: width
                verticalCenter: parent.verticalCenter
                verticalCenterOffset: height/2
            }
        }
        Text {
            text: "y"
            color: "silver"
            font.pixelSize: 16
            anchors {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
                horizontalCenterOffset: width
            }
        }

        // Центр координат
        Text {
            text: "(0, 0)"
            color: "silver"
            font.pixelSize: 16
            anchors {
                centerIn: parent
                horizontalCenterOffset: width/2
                verticalCenterOffset: height/2
            }
        }
    }
}
