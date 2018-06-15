#include "channelmodel.h"
ChannelModel::ChannelModel(QObject *parent)
{

}

void ChannelModel::addChannel(QString titre)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_channel << new Channel(titre);

    endInsertRows();
}

int ChannelModel::rowCount(const QModelIndex &parent) const
{
    return m_channel.count();
}

QVariant ChannelModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_channel.count())
        return QVariant();
    Channel * channel = m_channel[index.row()];
    if (role == TitreRole)
        return channel->titre();
    return QVariant();
}

bool ChannelModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
        if (index.row() < 0 || index.row() >= m_channel.count())
        return false;
    if ( data(index, role) == value )
        return true;

    Channel * channel = m_channel[index.row()];
    if ( role == TitreRole )
        channel->setTitre(value.toString());

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft = index.sibling(0,0);
    QModelIndex bottomRight = index.sibling(m_channel.count()-1,0);
    emit dataChanged(topLeft, bottomRight, roles);

    return true;
}

bool ChannelModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row+count >= m_channel.count())
        return false;

    beginRemoveRows(parent, row, row+count-1);

    for (int nb = 0; nb < count; ++nb) {
        m_channel.removeAt(row);
    }

    endRemoveRows();
    return true;
}

bool ChannelModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);

    for (int nb = 0; nb < count; ++nb) {
        m_channel.insert(row, new Channel("Titre " + nb));
    }

    endInsertRows();
    return true;
}

QHash<int, QByteArray> ChannelModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitreRole] = "titre";
    return roles;
}
