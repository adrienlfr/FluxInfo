#ifndef PARSERRSS_H
#define PARSERRSS_H

#include <QObject>
#include "rss.h"

class ParserRSS : public QObject
{
    Q_OBJECT
public:
    explicit ParserRSS(QObject *parent = nullptr);

    void parse(QString lien);

signals:
    void rssChanged();

public slots:

};

#endif // PARSERRSS_H
