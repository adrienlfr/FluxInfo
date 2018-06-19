#include "channelitem.h"

ChannelItem::ChannelItem(QString titre, QString description)
{
    setTitre(titre);
    setDescription(description);
}

QString ChannelItem::titre() const
{
    return m_titre;
}

QString ChannelItem::description() const
{
    return m_description;
}

void ChannelItem::setTitre(QString titre)
{
    if (m_titre == titre)
        return;

    m_titre = titre;
    emit titreChanged(m_titre);
}

void ChannelItem::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}
