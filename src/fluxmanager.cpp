#include "fluxmanager.h"
#include "parserrss.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

FluxManager::FluxManager(QObject *parent) : QObject(parent)
  , m_channels(new ChannelList)
{

}

void FluxManager::parseRss(QString lien)
{
    ParserRSS parser;
    auto rss = parser.parse("https://www.lemonde.fr/football/rss_full.xml");
    ParserRSS::parse(lien);
}

bool FluxManager::loadData()
{
    QFile loadFile(QStringLiteral("save.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    read(loadDoc.object());

    return true;
}

bool FluxManager::saveData() const
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject mesChannels;
    write(mesChannels);
    QJsonDocument saveDoc(mesChannels);
    saveFile.write(saveDoc.toJson());

    return true;
}

void FluxManager::read(const QJsonObject &json)
{
    m_channels->read(json["mesChannels"].toObject());
}

void FluxManager::write(QJsonObject &json) const
{
    QJsonObject mesChannels;
    m_channels->write(mesChannels);
    json["mesChannels"] = mesChannels;
}

ChannelList* FluxManager::channels()
{
    return m_channels;
}
