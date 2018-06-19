import QtQuick 2.0
import Sailfish.Silica 1.0
import ChannelItemModel 1.0

Page {
    property var channelItem

    SilicaFlickable {
        id: view
        anchors.fill: parent
        contentHeight: content.height + header.height
        VerticalScrollDecorator { flickable: view }

        PageHeader {
            title: channelItem.titre
            id: header
        }

        Column {
            id: content
            anchors.top: header.bottom
            width: parent.width

            Label {
                text: channelItem.description
                wrapMode: "Wrap"
                width: parent.width
            }
        }

    }
}
