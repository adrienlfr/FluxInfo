#include "channelitemmodel.h"

ChannelItemModel::ChannelItemModel(QObject *parent) : QAbstractListModel(parent), m_channelItemList(nullptr)
{}

int ChannelItemModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid() )
        return 0;
    return m_channelItemList->count();
}

QVariant ChannelItemModel::data(const QModelIndex &index, int role) const
{
    auto channelItem = m_channelItemList->at(index.row());

    switch (role) {
    case TitreRole:
        return channelItem->titre();
    case ChannelItemRole:
        return QVariant(QVariant::fromValue(channelItem));
    default:
        break;
    }
    return QVariant();
}

ChannelItemList *ChannelItemModel::listChannelItem() const
{
    return m_channelItemList;
}

void ChannelItemModel::setList(ChannelItemList *list)
{
    beginResetModel();

    if(m_channelItemList)
        m_channelItemList->disconnect(this);

    m_channelItemList = list;

    if (m_channelItemList) {
        connect(m_channelItemList, &ChannelItemList::preItemAppended, this, [=](){
            const int index = m_channelItemList->count();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(m_channelItemList, &ChannelItemList::postItemAppended, this, [=](){
            endInsertRows();
        });

        connect(m_channelItemList, &ChannelItemList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(m_channelItemList, &ChannelItemList::postItemRemoved, this, [=](){
            endRemoveRows();
        });

        connect(m_channelItemList, &ChannelItemList::itemChanged, this, [=](int row) {
            emit ChannelItemModel::dataChanged(this->index(row), this->index(row));
        });
    }

    endResetModel();
}

bool ChannelItemModel::setdata(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto channelitem = m_channelItemList->at(index.row());

        switch (role) {
        case TitreRole:
            channelitem->setTitre(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        case DescriptionRole:
            channelitem->setDescription(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

QHash<int, QByteArray> ChannelItemModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitreRole] = "titre";
    roles[DescriptionRole] = "description";
    roles[ChannelItemRole] = "channelItem";
    return roles;
}
