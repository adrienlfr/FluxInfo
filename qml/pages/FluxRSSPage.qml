import QtQuick 2.0
import Sailfish.Silica 1.0
import ChannelModel 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        model: ChannelModel { listChannel: mesChannels }
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: qsTr("Ajouter un Flux Rss")
                onClicked: listView.model.newChannel()
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
            onClicked: {
                console.log(channel);
                pageStack.push( detailRss, { channel: channel }  )}
            Component {
                id: detailRss
                DetailRss {}
            }
        }
        VerticalScrollDecorator {}
    }
}
