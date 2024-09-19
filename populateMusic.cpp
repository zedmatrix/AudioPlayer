void MainWindow::populateMusic() {
    QFile file(MusicFile);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File opening failed";
        return;
    }
    outputText.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (!line.isEmpty()) {
            QFileInfo fileInfo(line);
            if (fileInfo.exists()) {
                Music["Filename"] = fileInfo.fileName();
                Music["FullPath"] = fileInfo.absoluteFilePath();
                MusicMap.push_back(Music);
            } else {
                qDebug() << "File doesn't exist: " << line;
            }
        }
    }
    for (int i = 0; i < MusicMap.size(); i++) {
        outputText += QString("%1\n").arg(MusicMap[i]["Filename"]);
    }
    ui->playlist->setText(outputText);
}

void MainWindow::Shuffle() {
    outputText.clear();
    for (int i = 0; i < MusicMap.size(); i++) {
        int x = QRandomGenerator::global()->bounded(0, MusicMap.size());
        int y = QRandomGenerator::global()->bounded(0, MusicMap.size());
        SwapTracks(x, y);
    }
    qDebug() << "** Shuffling PlayList **";
    for (int i = 0; i < MusicMap.size(); i++) {
        outputText += QString("%1\n").arg(MusicMap[i]["Filename"]);
    }
    ui->playlist->setText(outputText);
}

void MainWindow::SwapTracks(int x, int y) {
    std::swap(MusicMap[x], MusicMap[y]);
}
