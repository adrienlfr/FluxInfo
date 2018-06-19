#ifndef CHANNELITEMLIST_H
#define CHANNELITEMLIST_H

#include <QObject>
#include "channelitem.h"

class ChannelItemList : public QObject
{
    Q_OBJECT
    QList<ChannelItem*> m_channelItems;
public:
    explicit ChannelItemList(QObject *parent = nullptr);

    void append(ChannelItem* channelItem);
    ChannelItem *at(int place) const;
    int count() const;
    void createChannelItem(QString titre, QString description);
    void removeChannelItem(int position);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);

public slots:
};

#endif // CHANNELITEMLIST_H
