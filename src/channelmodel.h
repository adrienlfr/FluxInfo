#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "channel.h"

class ChannelModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ChannelRoles {
        TitreRole = Qt::UserRole + 1
    };
    ChannelModel(QObject *parent = 0);
    Q_INVOKABLE void addChannel(QString titre);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Channel*> m_channel;
};

#endif // CHANNELMODEL_H
