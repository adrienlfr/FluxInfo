#include "parserrss.h"
#include <QDomComment>

ParserRSS::ParserRSS(QObject *parent) : QObject(parent)
{

}

void ParserRSS::parse(QString lien)
{
    QDomDocument doc(lien);
}
