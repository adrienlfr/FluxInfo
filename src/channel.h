#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "channelitem.h"

class Channel : public QObject
{
Q_OBJECT
private:
    Q_PROPERTY(QList<ChannelItem*> articles READ articles WRITE setArticles NOTIFY articlesChanged)
    Q_PROPERTY(QString titre READ titre WRITE setTitre NOTIFY titreChanged)

    QString m_titre;
    QList<ChannelItem*> m_articles;

public:
    Channel(QString titre);

    QString titre() const;
    QList<ChannelItem*> articles() const;

public slots:
    void setTitre(QString titre);
    void setArticles(QList<ChannelItem*> articles);

signals:
    void titreChanged(QString titre);
    void articlesChanged(QList<ChannelItem*> articles);
};

#endif // CHANNEL_H
