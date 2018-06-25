#include "channellist.h"
#include <QJsonArray>

ChannelList::ChannelList(QObject *parent) : QObject(parent)
{
    //append(new Channel("Rss football", "https://foot.com/rss"));
}

void ChannelList::append(Channel *channel)
{
    emit preItemAppended();
    int position = count();
    connect(channel, &Channel::channelChanged, this, [=](){ emit ChannelList::itemChanged( position ); } );
    m_channels.append(channel);
    emit postItemAppended();
}

Channel *ChannelList::at(int place) const
{
    return m_channels.at(place);
}

int ChannelList::count() const
{
    return m_channels.count();
}

void ChannelList::createChannel(QString lien, QString titre)
{
    append(new Channel(lien, titre));
}

void ChannelList::removeChannel(int position)
{
    emit preItemRemoved(position);

    disconnect ( m_channels[position], &Channel::channelChanged, this, 0);

    m_channels.removeAt(position);

    for ( ; position < count() ; ++position ) {
        disconnect ( m_channels[position], &Channel::channelChanged, this, 0);
        connect( m_channels[position], &Channel::channelChanged, this, [=](){ emit ChannelList::itemChanged( position ); } );
    }
    emit postItemRemoved();
}

void ChannelList::read(const QJsonObject &json)
{
   m_channels.clear();
   QJsonArray channelArray = json["channels"].toArray();
   for (int channelIndex = 0; channelIndex < channelArray.size(); ++channelIndex) {
       QJsonObject channelObject = channelArray[channelIndex].toObject();
       Channel *channel;
       channel->read(channelObject);
       m_channels.append(channel);
   }
}

void ChannelList::write(QJsonObject &json) const
{
    QJsonArray channelArray;
    foreach (const Channel *channel, m_channels) {
        QJsonObject channelObject;
        channel->write(channelObject);
        channelArray.append(channelObject);
    }
    json["channels"] = channelArray;
}
