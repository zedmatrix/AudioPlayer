/*
    >> Add to mainwindow.cpp
    >> CMakeLists.txt >> mousevolume.{h,cpp}

    MouseVolume *volumeControl = new MouseVolume(ui, this, this);
    volumeControl->InitializeVolumeBar(ui->volumeBar);
    ui-> volumeBar->setFocusPolicy(Qt::FocusPolicy::NoFocus);
*/

void MainWindow::InitializeVolumeBar() {
    trackVolume = {0.5};
    ui->volumeBar->setRange(0, 100);
    ui->volumeBar->setValue(static_cast<int>(trackVolume * 100)); // Convert 0.0–1.0 to 0–100
    ui->volumeBar->setFocusPolicy(Qt::StrongFocus);
    connect(ui->volumeBar, &QProgressBar::valueChanged, this, &MainWindow::updateVolume);
}

void MainWindow::updateVolume() {
    ui->volumeBar->setValue(trackVolume);
    audioOutput->setVolume(trackVolume / 100.0);

}

void MainWindow::wheelEvent(QWheelEvent *event) {
    int numSteps = event->angleDelta().y() / 120;
    trackVolume = ui->volumeBar->value();

    if (numSteps > 0) {
        deltaVolume = -1;
    } else {
        deltaVolume = 1;
    }
    trackVolume += deltaVolume;
    event->accept();
    updateVolume();
}
