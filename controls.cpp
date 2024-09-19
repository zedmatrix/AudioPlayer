void MainWindow::Track(bool direction) {
    MusicIndex += direction ? 1 : -1;
    MusicIndex = std::clamp(MusicIndex, 0, static_cast<int>(MusicMap.size()) - 1);
    if (player->isPlaying()) { player->stop(); }
    Player();
}

void MainWindow::Player()
{
    if (MusicIndex >= MusicMap.size()) {
        MusicIndex = 0;
        Shuffle();
    }

    QString filePath = MusicMap[MusicIndex]["FullPath"];
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    player->setSource(fileUrl);
    Play();
}

void MainWindow::Play () {
    if (player->isPlaying()) {
        player->pause();
    } else {
        player->setAudioOutput(audioOutput);
        player->play();
    }
}

void MainWindow::Stop () {
    if (player->isPlaying()) {
        player->stop();
    }
}

void MainWindow::Quit () {
    QCoreApplication::quit();
}
