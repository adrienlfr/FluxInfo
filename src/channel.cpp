#include "channel.h"

Channel::Channel(QString titre)
{
    setTitre(titre);
}

QString Channel::titre() const
{
    return m_titre;
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

void Channel::setArticles(QList<ChannelItem*> articles)
{
    if (m_articles == articles)
        return;

    m_articles = articles;
    emit articlesChanged(m_articles);
}
