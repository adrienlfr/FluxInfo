import QtQuick 2.0
import Sailfish.Silica 1.0
import ChannelItemModel 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaListView {
        id: listView
        model: ChannelItemModel { listChannelItem: mesChannelItems }
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Flux RSS")
                onClicked: pageStack.push(Qt.resolvedUrl("FluxRSSPage.qml"))
            }
        }

        header: PageHeader {
            title: qsTr("Articles")
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
                console.log(channelItem);
                pageStack.push(detailChannelItem, { channelItem: channelItem })
            }
            Component {
                id: detailChannelItem
                DetailChannelItem {}
            }
        }

        VerticalScrollDecorator {}
    }
}
