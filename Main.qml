import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import TicTacToe

ApplicationWindow {
    id: window
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Tic Tac Toe")

    ColumnLayout{
        anchors.fill: parent
        Layout.fillHeight: true
        anchors.centerIn: parent

        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: tileM.win;
                color: "white"
                font.pixelSize: 34
            }
        }

        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
            RowLayout{
                Tile {
                    id: tile1
                    gridNum: 1;
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile1.Symbol;
                    onClicked: tileM.tileClicked(1);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile2
                    gridNum: 2
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile2.Symbol;
                    onClicked: tileM.tileClicked(2);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile3
                    gridNum: 3
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile3.Symbol;
                    onClicked: tileM.tileClicked(3);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }

            }
            RowLayout{
                Tile {
                    id: tile4
                    gridNum: 4;
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile4.Symbol;
                    onClicked: tileM.tileClicked(4);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile5
                    gridNum: 5
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile5.Symbol;
                    onClicked: tileM.tileClicked(5);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile6
                    gridNum: 6
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile6.Symbol;
                    onClicked: tileM.tileClicked(6);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }

            }
            RowLayout{
                Tile {
                    id: tile7
                    gridNum: 7;
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile7.Symbol;
                    onClicked: tileM.tileClicked(7);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile8
                    gridNum: 8
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile8.Symbol;
                    onClicked: tileM.tileClicked(8);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
                Tile {
                    id: tile9
                    gridNum: 9
                }
                Button {
                    spacing: 10
                    width: 100
                    height: 100
                    text: tile9.Symbol;
                    onClicked: tileM.tileClicked(9);
                    font.pixelSize: 40

                    Layout.preferredHeight: 80
                    Layout.preferredWidth: 80
                }
        }

        }

        RowLayout{
            Layout.alignment: Qt.AlignBottom
            Button {
                anchors.centerIn: parent
                text: "restart"
                onClicked: tileM.restart()
            }
        }
    }

    TileManager {
        id: tileM
    }

    Component.onCompleted: {
        tileM.addTiles(tile1)
        tileM.addTiles(tile2)
        tileM.addTiles(tile3)
        tileM.addTiles(tile4)
        tileM.addTiles(tile5)
        tileM.addTiles(tile6)
        tileM.addTiles(tile7)
        tileM.addTiles(tile8)
        tileM.addTiles(tile9)
    }
}

