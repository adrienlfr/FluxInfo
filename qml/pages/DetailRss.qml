import QtQuick 2.0
import Sailfish.Silica 1.0
import ChannelModel 1.0

Page {
    property var channel
    property var index

    property var channelModel

    property var rss

    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Supprimer le flux")
                onClicked: {
                    channelModel.removeRow(index);
                    pageStack.pop();
                }
            }
        }

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
                }
                onFocusChanged: text = Qt.binding( function() { return channel.lien } )
            }

            TextField {
                id: titre
                text: channel.titre
                label: "Titre"
                width: parent.width

                EnterKey.onClicked: {
                    channel.titre = text
                }
                onFocusChanged:  text = Qt.binding( function() { return channel.titre} )
            }

        }
    }

}
