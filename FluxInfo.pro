# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = FluxInfo

CONFIG += sailfishapp

QT += xml
QT += network

SOURCES += src/FluxInfo.cpp \
    src/channel.cpp \
    src/rss.cpp \
    src/channelitem.cpp \
    src/channelmodel.cpp \
    src/channellist.cpp \
    src/parserrss.cpp \
<<<<<<< HEAD
    src/fluxmanager.cpp
=======
    src/channelitemlist.cpp \
    src/channelitemmodel.cpp
>>>>>>> Master detail ChannelItem & vue DetailChannelItem

DISTFILES += qml/FluxInfo.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/FluxInfo.changes.in \
    rpm/FluxInfo.changes.run.in \
    rpm/FluxInfo.spec \
    rpm/FluxInfo.yaml \
    translations/*.ts \
    FluxInfo.desktop \
    qml/pages/FluxRSSPage.qml \
    qml/pages/DetailRss.qml \
    qml/pages/DetailChannelItem.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/FluxInfo-de.ts

HEADERS += \
    src/channel.h \
    src/rss.h \
    src/channelitem.h \
    src/channelmodel.h \
    src/channellist.h \
    src/parserrss.h \
<<<<<<< HEAD
    src/fluxmanager.h
=======
    src/channelitemlist.h \
    src/channelitemmodel.h
>>>>>>> Master detail ChannelItem & vue DetailChannelItem
