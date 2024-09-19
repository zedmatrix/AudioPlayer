#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controls.cpp"
#include "MediaStatus.cpp"
#include "MediaError.cpp"
#include "populateMusic.cpp"
#include "mousevolume.cpp"

QString MainWindow::MusicFile = {};  // Define the static member variable

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
{

    // Setup Ui
    ui->setupUi(this);
    this->setWindowTitle("MP3 Music Player");

    // connect the buttons to routines
    connect(ui->Quit, &QPushButton::clicked, this, &MainWindow::Quit);
    connect(ui->Play, &QPushButton::clicked, this, &MainWindow::Play);
    connect(ui->Stop, &QPushButton::clicked, this, &MainWindow::Stop);
    connect(ui->Shuffle, &QPushButton::clicked, this, &MainWindow::Shuffle);
    connect(ui->prevTrack, &QPushButton::clicked, this, [this]() { Track(false); });
    connect(ui->nextTrack, &QPushButton::clicked, this, [this]() { Track(true); });
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::MediaStatus);
    connect(player, &QMediaPlayer::playbackStateChanged, this, &MainWindow::StateChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updatePosition);
    connect(player, &QMediaPlayer::errorOccurred, this, &MainWindow::MediaError);

    InitializeVolumeBar();
    // Populate Music Map and start playing
    populateMusic();
    MusicIndex = 0;
    Player();
}

MainWindow::~MainWindow()
{

    if (player->isPlaying()) {
        player->stop();
    }

    delete player;
    delete ui;
}

