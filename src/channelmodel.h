#ifndef CHANNELMODEL_H
#define CHANNELMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "channel.h"
#include "channellist.h"

class ChannelModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ChannelList* listChannel READ listChannel WRITE setList)
public:
    enum ChannelRoles {
        TitreRole = Qt::UserRole + 1,
        LienRole,
        ChannelRole,
    };

    ChannelModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    ChannelList *listChannel() const;

    void setList(ChannelList *list);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    Q_INVOKABLE void removeRow(int index);
    Q_INVOKABLE void newChannel();

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    ChannelList *m_channelList;
};

#endif // CHANNELMODEL_H
