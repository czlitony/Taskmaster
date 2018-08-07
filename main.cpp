#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>

static void initAppDir()
{
    auto appDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDir);
    if (!dir.exists())
    {
        dir.mkpath(appDir);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    initAppDir();

    return a.exec();
}
