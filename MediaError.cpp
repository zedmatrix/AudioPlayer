void MainWindow::MediaError(QMediaPlayer::Error error, const QString &errorString) {
    errorMessage.clear();
    switch (error) {
        case QMediaPlayer::NoError:
            errorMessage = "OK";
            break;
        case QMediaPlayer::ResourceError:
            errorMessage = "Resource Error:";
            break;
        case QMediaPlayer::FormatError:
            errorMessage = "Format Error:";
            break;
        case QMediaPlayer::NetworkError:
            errorMessage = "Network Error:";
            break;
        case QMediaPlayer::AccessDeniedError:
            errorMessage = "Access Denied:";
            break;
        default:
            errorMessage = "Unknown Error:";
            break;
    }
    errorMessage += errorString;
    updateStatusBar();
}
