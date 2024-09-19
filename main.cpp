#include <QApplication>
#include <QFileInfo>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (argc > 1) {
        MainWindow::MusicFile = argv[1];
        qDebug() << "Filename is:" << MainWindow::MusicFile;
        //std::ifstream file(MainWindow::MusicFile.toStdString());

        QFileInfo file(MainWindow::MusicFile);
        if (!file.isReadable()) {
            qDebug() << "Can Not Read from File: " << file.fileName();
            exit(1);
        }

    } else {
        qDebug() << " Usage: " << argv[0] << " {Music Text File}";
        exit(1);
    }

    MainWindow window;
    window.show();
    return app.exec();
}
