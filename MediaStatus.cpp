void MainWindow::updateStatusBar() {
    statusMsg = QString("Media %1 | %2 | %3 | %4 | %5 |")
                    .arg(errorMessage)
                    .arg(stateMessage)
                    .arg(statusMessage)
                    .arg(statusPosition)
                    .arg(trackVolume);

    ui->statusbar->showMessage(statusMsg);
}

void MainWindow::MetaDataChanged() {
    QMediaMetaData metaData = player->metaData();
    outputText.clear();
    outputText = QString("%1\n").arg(MusicMap[MusicIndex]["Filename"]);

    if (!metaData.isEmpty()) {
        QMediaMetaData metaData = player->metaData();
        QList<QMediaMetaData::Key> metadataKeys = metaData.keys();

        for (const auto &key : metadataKeys) {
            QString keyName = QMediaMetaData::metaDataKeyToString(key);
            QVariant value = metaData.value(key);
            outputText += QString("Key: %1 => %2 \n").arg(keyName).arg(value.toString());
        }
    } else {
        outputText += "\nNo Metadata\n";
    }
    ui->rawText->setText(outputText);
}

void MainWindow::updatePosition() {
    qint64 currentPosition = player->position();
    qint64 duration = player->duration();

    // Format the position and duration for display (e.g., mm:ss)
    // Minutes and Seconds
    QString positionText = QString("%1:%2")
            .arg(currentPosition / 60000)
            .arg((currentPosition % 60000) / 1000, 2, 10, QChar('0'));


    QString durationText = QString("%1:%2")
            .arg(duration / 60000)
            .arg((duration % 60000) / 1000, 2, 10, QChar('0'));

    ui->positionBar->setRange(0, duration);
    ui->positionBar->setFormat(positionText);
    ui->positionBar->setValue(currentPosition);

    statusPosition = QString("Position: %1 / %2").arg(positionText).arg(durationText);
    updateStatusBar();
}

void MainWindow::StateChanged(QMediaPlayer::PlaybackState state) {
    switch (state) {
        case QMediaPlayer::PlayingState:
            stateMessage = "is playing";
            break;
        case QMediaPlayer::PausedState:
            stateMessage = "is paused";
            break;
        case QMediaPlayer::StoppedState:
            stateMessage = "is stopped";
            break;
    }
    updateStatusBar();
}

void MainWindow::MediaStatus(QMediaPlayer::MediaStatus status) {
    switch (status) {
        case QMediaPlayer::NoMedia:
            statusMessage = "No Media";
            break;
        case QMediaPlayer::LoadingMedia:
            statusMessage = "Loading..";
            break;
        case QMediaPlayer::LoadedMedia:
            statusMessage = "Loaded =>" + QString::number(MusicIndex);
            MetaDataChanged();
            break;
        case QMediaPlayer::StalledMedia:
            statusMessage = "Stalled...";
            break;
        case QMediaPlayer::BufferingMedia:
            statusMessage = "Buffering...";
            break;
        case QMediaPlayer::BufferedMedia:
            statusMessage = "Buffered =>" + QString::number(MusicIndex);
            break;
        case QMediaPlayer::EndOfMedia:
            MusicIndex += 1;
            statusMessage = "End of Media.";
            Player();
            break;
        case QMediaPlayer::InvalidMedia:
            statusMessage = "Invalid media.";
            break;
        default:
            statusMessage = "";
            break;
    }
    updateStatusBar();
}
