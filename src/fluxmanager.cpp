#include "fluxmanager.h"
#include "parserrss.h"

FluxManager::FluxManager(QObject *parent) : QObject(parent)
  , m_channels(new ChannelList)
{

}

void FluxManager::parseRss(QString lien)
{
    ParserRSS::parse(lien);
}

ChannelList* FluxManager::channels()
{
    return m_channels;
}
