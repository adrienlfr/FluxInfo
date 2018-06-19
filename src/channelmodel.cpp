#include "channelmodel.h"
ChannelModel::ChannelModel(QObject *parent)
    : QAbstractListModel(parent), m_channelList(nullptr)
{

}

int ChannelModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid())
        return 0;
    return m_channelList->count();
}

QVariant ChannelModel::data(const QModelIndex &index, int role) const
{
    auto channel = m_channelList->at(index.row());

    switch (role) {
    case TitreRole:
        return channel->titre();
    case ChannelRole:
        return QVariant(QVariant::fromValue(channel));
    default:
        break;
    }
    return QVariant();
}

ChannelList *ChannelModel::listChannel() const
{
    return m_channelList;
}

void ChannelModel::setList(ChannelList *list)
{
    beginResetModel();

       if (m_channelList)
           m_channelList->disconnect(this);

       m_channelList = list;

       if (m_channelList) {
           connect(m_channelList, &ChannelList::preItemAppended, this, [=]() {
               const int index = m_channelList->count();
               beginInsertRows(QModelIndex(), index, index);
           });
           connect(m_channelList, &ChannelList::postItemAppended, this, [=]() {
               endInsertRows();
           });

           connect(m_channelList, &ChannelList::preItemRemoved, this, [=](int index) {
               beginRemoveRows(QModelIndex(), index, index);
           });
           connect(m_channelList, &ChannelList::postItemRemoved, this, [=]() {
               endRemoveRows();
           });
           connect(m_channelList, &ChannelList::itemChanged,
                   this, [=](int row){ emit ChannelModel::dataChanged(this->index(row), this->index(row)); });
       }

   endResetModel();
}

bool ChannelModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto channel = m_channelList->at(index.row());

        switch (role) {
        case TitreRole:
            channel->setTitre(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

void ChannelModel::removeRow(int index)
{
    m_channelList->removeChannel(index);
}

void ChannelModel::newChannel()
{
    QString lien(tr("Inserez le lien"));
    QString titre(tr("New Rss"));
    m_channelList->createChannel(lien, titre);
}

QHash<int, QByteArray> ChannelModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitreRole] = "titre";
    roles[ChannelRole] = "channel";
    return roles;
}
