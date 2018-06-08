#ifndef RSS_H
#define RSS_H

#include <QObject>
#include "channel.h"

class Rss : public QObject
{
Q_OBJECT
private:
    Q_PROPERTY(Channel* channel READ channel WRITE setChannel NOTIFY channelChanged)
    Channel *m_channel;

public:
    Rss(Channel *channel);

    Channel* channel() const;
public slots:
    void setChannel(Channel *channel);
signals:
    void channelChanged(Channel *channel);
};

#endif // RSS_H
