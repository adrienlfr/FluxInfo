#ifdef QT_QML_DEBUG
#include <QtQuick>
#include "rss.h"
#include "channel.h"
#endif

#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/FluxInfo.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QList<QObject*> mesRss;
    mesRss.append(new Rss(new Channel("Mes couilles sur ton front ca fait une licorne!")));

    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view -> rootContext() -> setContextProperty("mesRss", QVariant::fromValue(mesRss));

    view -> setSource(SailfishApp::pathToMainQml());
    view -> show();

    return app -> exec();
}
