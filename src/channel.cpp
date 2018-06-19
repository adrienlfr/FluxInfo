#include "channel.h"

Channel::Channel(QString titre, QString lien)
{
    connect(this, &Channel::articlesChanged, this, &Channel::channelChanged);
    connect(this, &Channel::lienChanged, this, &Channel::channelChanged);
    connect(this, &Channel::titreChanged, this, &Channel::channelChanged);

    setTitre(titre);
    setLien(lien);
}

QString Channel::titre() const
{
    return m_titre;
}

QString Channel::lien() const
{
    return m_lien;
}

QList<ChannelItem *> Channel::articles() const
{
    return m_articles;
}

void Channel::setTitre(QString titre)
{
    if (m_titre == titre)
        return;

    m_titre = titre;
    emit titreChanged(m_titre);
}

void Channel::setLien(QString lien)
{
    if (m_lien == lien)
        return;

    m_lien = lien;
    emit lienChanged(m_lien);
}

void Channel::setArticles(QList<ChannelItem*> articles)
{
    if (m_articles == articles)
        return;

    m_articles = articles;
    emit articlesChanged(m_articles);
}
