#include "parserrss.h"
#include <QDomComment>

ParserRSS::ParserRSS(QObject *parent) : QObject(parent)
{

}

Rss* ParserRSS::parse(QString lien)
{
    QDomDocument doc(lien);

}
