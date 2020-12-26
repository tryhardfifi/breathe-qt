
#include "mainwindow.h"

#include <QApplication>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QWebEngineSettings>


#include <QVBoxLayout>

#include <QUrl>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWebEngineView webView;
    QWebEngineSettings *settings;
    webView.settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled,true);
    webView.settings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
    webView.load(QUrl("qrc:///index.html"));
    webView.show();

    Qt::WindowFlags flags = w.windowFlags();
    webView.setWindowFlags(flags | Qt::WindowStaysOnTopHint);
    webView.setGeometry(0,0,200,200);
    webView.show();
    return a.exec();
}

