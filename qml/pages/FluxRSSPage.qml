import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        model: mesChannel
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: qsTr("Ajouter un Flux Rss")
                onClicked: listView.model.addChannel("Apple c'est le top!")
            }
        }

        header: PageHeader {
            title: qsTr("Mes Flux RSS")
        }
        delegate: BackgroundItem {
            id: delegate

            Label {
                x: Theme.horizontalPageMargin
                text: titre
                anchors.verticalCenter: parent.verticalCenter
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
            onClicked: console.log("Clicked " + index)
        }
        VerticalScrollDecorator {}
    }
}
