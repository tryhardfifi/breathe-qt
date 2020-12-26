#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef Q_WS_X11 //only define on Qt 4.X
#include <QX11Info> //Only on Qt 4.X , return expected in Qt 5.1
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView webView;
    QVBoxLayout *vLayout;
    QPushButton *button;
    QWidget *mainWidget;
#ifdef Q_WS_X11 //only define on Qt 4.X
    unsigned long data = 0xFFFFFFFF;
    XChangeProperty (QX11Info::display(),
                     winId(),
                     XInternAtom(QX11Info::display(), "_NET_WM_DESKTOP", False),
                     XA_CARDINAL,
                     32,
                     PropModeReplace,
                     reinterpret_cast<unsigned char *>(&data), // all desktop
                     1);
#endif
}


MainWindow::~MainWindow()
{
    delete ui;

}

