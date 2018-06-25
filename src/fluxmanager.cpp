#include "fluxmanager.h"
#include "parserrss.h"

FluxManager::FluxManager(QObject *parent) : QObject(parent)
  , m_channels(new ChannelList)
{

}

void FluxManager::parseRss(QString lien)
{
    ParserRSS parser;
    auto rss = parser.parse("https://www.lemonde.fr/football/rss_full.xml");
}

ChannelList* FluxManager::channels()
{
    return m_channels;
}
