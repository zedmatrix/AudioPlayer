#ifndef MOUSEVOLUME_H
#define MOUSEVOLUME_H

#include <QWidget>
#include <QProgressBar>
#include <QWheelEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class MainWindow; //Forward declare

class MouseVolume : public QWidget
{
    Q_OBJECT

public:
    explicit MouseVolume(Ui::MainWindow *ui, MainWindow *mainWindow, QWidget *parent = nullptr);
    void InitializeVolumeBar(QProgressBar *volumeBar);
    void updateVolume();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    MainWindow *mainWindow;  // Pointer to MainWindow
    Ui::MainWindow *ui;
    QProgressBar *volumeBar;
    double trackVolume;

};

#endif // MOUSEVOLUME_H
