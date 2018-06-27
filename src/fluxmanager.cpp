#include "fluxmanager.h"
#include "parserrss.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QDir>

FluxManager::FluxManager(QObject *parent) : QObject(parent)
  , m_channels(new ChannelList)
{

}

void FluxManager::parseRss(QString lien)
{
    ParserRSS parser;
    auto rss = parser.parse("https://www.lemonde.fr/football/rss_full.xml");
}

bool FluxManager::loadData()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    path += "/save.json";
    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadWrite)) {
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
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    QDir dir(path);
    dir.mkdir(path);
    path += "/save.json";
    QFile saveFile(path);


    if (!saveFile.open(QIODevice::ReadWrite)) {
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
