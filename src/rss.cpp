#include "rss.h"

Rss::Rss(Channel * channel)
{

}

Channel* Rss::channel() const
{
    return m_channel;
}

void Rss::setChannel(Channel* channel)
{
    if (m_channel == channel)
        return;

    m_channel = channel;
    emit channelChanged(m_channel);
}
