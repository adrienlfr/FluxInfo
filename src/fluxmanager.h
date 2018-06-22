#ifndef FLUXMANAGER_H
#define FLUXMANAGER_H

#include <QObject>
#include "channellist.h"
#include "rss.h"

class FluxManager : public QObject
{
    Q_OBJECT
public:


    explicit FluxManager(QObject *parent = nullptr);



    Q_INVOKABLE ChannelList* channels();

    Q_INVOKABLE void parseRss(QString lien);

signals:

public slots:

private:
    ChannelList *m_channels;

};

#endif // FLUXMANAGER_H
