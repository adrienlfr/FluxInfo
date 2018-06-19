#ifndef CHANNELITEMMODEL_H
#define CHANNELITEMMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "channelitemlist.h"

class ChannelItemModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ChannelItemList* listChannelItem READ listChannelItem WRITE setList)
public:
    enum ChannelItemRoles {
        TitreRole = Qt::UserRole + 1,
        DescriptionRole,
        ChannelItemRole,
    };

    ChannelItemModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    ChannelItemList *listChannelItem() const;

    void setList(ChannelItemList *list);

    bool setdata(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    ChannelItemList *m_channelItemList;
};

#endif // CHANNELITEMMODEL_H
