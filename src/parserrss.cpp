#include "parserrss.h"
#include <QDomComment>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QXmlStreamReader>

ParserRSS::ParserRSS(QObject *parent) : QObject(parent)
{

}

Rss* ParserRSS::parse(QString lien)
{
    QString url = "https://www.lemonde.fr/football/rss_full.xml";

}
