/********************************************************************************
** Form generated from reading UI file 'mainwindowArCuQT.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWARCUQT_H
#define MAINWINDOWARCUQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Play;
    QPushButton *prevTrack;
    QPushButton *Stop;
    QPushButton *nextTrack;
    QPushButton *Shuffle;
    QPushButton *Quit;
    QTextEdit *rawText;
    QTextBrowser *playlist;
    QProgressBar *positionBar;
    QProgressBar *volumeBar;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(625, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 200, 601, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Play = new QPushButton(horizontalLayoutWidget);
        Play->setObjectName("Play");
        Play->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(10);
        font.setBold(true);
        Play->setFont(font);

        horizontalLayout->addWidget(Play);

        prevTrack = new QPushButton(horizontalLayoutWidget);
        prevTrack->setObjectName("prevTrack");
        prevTrack->setMaximumSize(QSize(30, 30));
        prevTrack->setFont(font);

        horizontalLayout->addWidget(prevTrack);

        Stop = new QPushButton(horizontalLayoutWidget);
        Stop->setObjectName("Stop");
        Stop->setMaximumSize(QSize(100, 30));
        Stop->setFont(font);

        horizontalLayout->addWidget(Stop);

        nextTrack = new QPushButton(horizontalLayoutWidget);
        nextTrack->setObjectName("nextTrack");
        nextTrack->setMaximumSize(QSize(30, 30));
        nextTrack->setFont(font);

        horizontalLayout->addWidget(nextTrack);

        Shuffle = new QPushButton(horizontalLayoutWidget);
        Shuffle->setObjectName("Shuffle");
        Shuffle->setMaximumSize(QSize(100, 30));
        Shuffle->setFont(font);

        horizontalLayout->addWidget(Shuffle);

        Quit = new QPushButton(horizontalLayoutWidget);
        Quit->setObjectName("Quit");
        Quit->setMaximumSize(QSize(100, 30));
        Quit->setFont(font);

        horizontalLayout->addWidget(Quit);

        rawText = new QTextEdit(centralwidget);
        rawText->setObjectName("rawText");
        rawText->setGeometry(QRect(10, 290, 601, 121));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(10);
        rawText->setFont(font1);
        playlist = new QTextBrowser(centralwidget);
        playlist->setObjectName("playlist");
        playlist->setGeometry(QRect(10, 10, 601, 181));
        positionBar = new QProgressBar(centralwidget);
        positionBar->setObjectName("positionBar");
        positionBar->setGeometry(QRect(417, 250, 191, 23));
        positionBar->setValue(30);
        volumeBar = new QProgressBar(centralwidget);
        volumeBar->setObjectName("volumeBar");
        volumeBar->setGeometry(QRect(90, 250, 118, 23));
        volumeBar->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        volumeBar->setValue(40);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 250, 58, 18));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        prevTrack->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        nextTrack->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        Shuffle->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        positionBar->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWARCUQT_H
