#include "channelitemlist.h"

ChannelItemList::ChannelItemList(QObject *parent) : QObject(parent)
{
    // Article juste pour voir si ca fonctionne donc a supprimer :)
    append(new ChannelItem("Titre de mon article", "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                                                   "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                                                   "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."));
}

void ChannelItemList::append(ChannelItem *channelItem)
{
    emit preItemAppended();
    int position = count();
    connect(channelItem, &ChannelItem::channelItemChanged, this, [=](){ emit ChannelItemList::itemChanged( position ); });
    m_channelItems.append(channelItem);
    emit postItemAppended();
}

ChannelItem *ChannelItemList::at(int place) const
{
    return m_channelItems.at(place);
}

int ChannelItemList::count() const
{
    return m_channelItems.count();
}

void ChannelItemList::createChannelItem(QString titre, QString description)
{
    append(new ChannelItem(titre, description));
}

void ChannelItemList::removeChannelItem(int position)
{
    emit preItemRemoved(position);
    disconnect(m_channelItems[position], &ChannelItem::channelItemChanged, this, 0);
    m_channelItems.removeAt(position);
    for ( ; position < count() ; ++position) {
        disconnect(m_channelItems[position], &ChannelItem::channelItemChanged, this, 0);
        connect(m_channelItems[position], &ChannelItem::channelItemChanged, this, [=](){ emit ChannelItemList::itemChanged(position); });
    }
    emit postItemRemoved();
}
