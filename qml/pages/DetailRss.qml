import QtQuick 2.0
import Sailfish.Silica 1.0
import ChannelModel 1.0

Page {
    property var channel

    PageHeader {
        title: "Modifier un flux Rss"
        id: header
    }

    Column {
        anchors.top: header.bottom
        width: parent.width

        TextField {
            text: channel.lien
            label: "lien"

            width: parent.width
            EnterKey.onClicked: {
                channel.lien= text
                sizeField.focus = true
            }
            onFocusChanged: text = Qt.binding( function() { return channel.lien} )
        }

        TextField {
            id: titre
            text: channel.titre
            label: "Titre"
            width: parent.width

            inputMethodHints: Qt.ImhDigitsOnly
            EnterKey.onClicked: {
                channel.titre = text
                focus = false
            }
            onFocusChanged:  text = Qt.binding( function() { return channel.titre} )
        }

    }
}
