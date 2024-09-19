#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QRandomGenerator>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QProgressBar>
#include <QWheelEvent>
#include <QStatusBar>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QWidget>
#include <QVector>
#include <QMap>
#include <iostream>
#include <algorithm> // For std::clamp
#include <fstream>  // For checking if the file exists
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QAudioOutput *audioOutput;
    static QString MusicFile;
    QString statusMsg, errorMessage, statusMessage, stateMessage, statusPosition, outputText;
    QVector<QMap<QString, QString>> MusicMap;
    QMap<QString, QString> Music;
    int MusicIndex, deltaVolume;
    float trackVolume;
    void populateMusic();
    void InitializeVolumeBar();
    void updateVolume();

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void MediaStatus(QMediaPlayer::MediaStatus status); // Get Media Status
    void StateChanged(QMediaPlayer::PlaybackState state);
    void MediaError(QMediaPlayer::Error error, const QString &errorString);
    void Track(bool direction);
    void Quit();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    void updateStatusBar();
    void MetaDataChanged();
    void updatePosition();
    void Player();
    void Play();
    void Stop();
    void Shuffle();
    void SwapTracks(int x, int y);



};

#endif // MAINWINDOW_H
