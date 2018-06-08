#ifndef CHANNELITEM_H
#define CHANNELITEM_H

#include <QObject>

class ChannelItem : public QObject
{
Q_OBJECT
private:
    Q_PROPERTY(QString titre READ titre WRITE setTitre NOTIFY titreChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

    QString m_titre;
    QString m_description;

public:
ChannelItem();

QString titre() const;
QString description() const;

public slots:
void setTitre(QString titre);
void setDescription(QString description);

signals:
void titreChanged(QString titre);
void descriptionChanged(QString description);
};

#endif // CHANNELITEM_H
