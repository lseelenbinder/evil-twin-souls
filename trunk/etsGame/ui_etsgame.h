/********************************************************************************
** Form generated from reading UI file 'etsgame.ui'
**
** Created: Fri Apr 1 16:42:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETSGAME_H
#define UI_ETSGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_etsGame
{
public:
    QAction *actionChange_Level;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionNew_Game;
    QAction *action800_x_600;
    QAction *action1024_x_768;
    QAction *action1152_x_824;
    QAction *action1280_x_700;
    QAction *action1280_x_720;
    QAction *action1280_x_768;
    QAction *action1280_x_800;
    QAction *action1360_x_768;
    QAction *action1440_x_900;
    QAction *action1600_x_900;
    QAction *actionPause;
    QAction *actionFullscreen;
    QAction *actionCheat_Mode;
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuChange_Resolution;
    QMenu *menuGasme;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *etsGame)
    {
        if (etsGame->objectName().isEmpty())
            etsGame->setObjectName(QString::fromUtf8("etsGame"));
        etsGame->resize(707, 462);
        actionChange_Level = new QAction(etsGame);
        actionChange_Level->setObjectName(QString::fromUtf8("actionChange_Level"));
        actionSave = new QAction(etsGame);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(etsGame);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionNew_Game = new QAction(etsGame);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        action800_x_600 = new QAction(etsGame);
        action800_x_600->setObjectName(QString::fromUtf8("action800_x_600"));
        action1024_x_768 = new QAction(etsGame);
        action1024_x_768->setObjectName(QString::fromUtf8("action1024_x_768"));
        action1152_x_824 = new QAction(etsGame);
        action1152_x_824->setObjectName(QString::fromUtf8("action1152_x_824"));
        action1280_x_700 = new QAction(etsGame);
        action1280_x_700->setObjectName(QString::fromUtf8("action1280_x_700"));
        action1280_x_720 = new QAction(etsGame);
        action1280_x_720->setObjectName(QString::fromUtf8("action1280_x_720"));
        action1280_x_768 = new QAction(etsGame);
        action1280_x_768->setObjectName(QString::fromUtf8("action1280_x_768"));
        action1280_x_800 = new QAction(etsGame);
        action1280_x_800->setObjectName(QString::fromUtf8("action1280_x_800"));
        action1360_x_768 = new QAction(etsGame);
        action1360_x_768->setObjectName(QString::fromUtf8("action1360_x_768"));
        action1440_x_900 = new QAction(etsGame);
        action1440_x_900->setObjectName(QString::fromUtf8("action1440_x_900"));
        action1600_x_900 = new QAction(etsGame);
        action1600_x_900->setObjectName(QString::fromUtf8("action1600_x_900"));
        actionPause = new QAction(etsGame);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setCheckable(true);
        actionFullscreen = new QAction(etsGame);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        actionFullscreen->setCheckable(true);
        actionCheat_Mode = new QAction(etsGame);
        actionCheat_Mode->setObjectName(QString::fromUtf8("actionCheat_Mode"));
        actionCheat_Mode->setCheckable(true);
        actionExit = new QAction(etsGame);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(etsGame);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        etsGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(etsGame);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuChange_Resolution = new QMenu(menuFile);
        menuChange_Resolution->setObjectName(QString::fromUtf8("menuChange_Resolution"));
        menuGasme = new QMenu(menuBar);
        menuGasme->setObjectName(QString::fromUtf8("menuGasme"));
        etsGame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(etsGame);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        etsGame->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(etsGame);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        etsGame->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuGasme->menuAction());
        menuFile->addAction(actionChange_Level);
        menuFile->addAction(menuChange_Resolution->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExit);
        menuChange_Resolution->addAction(action800_x_600);
        menuChange_Resolution->addAction(action1024_x_768);
        menuChange_Resolution->addAction(action1152_x_824);
        menuChange_Resolution->addAction(action1280_x_700);
        menuChange_Resolution->addAction(action1280_x_720);
        menuChange_Resolution->addAction(action1280_x_768);
        menuChange_Resolution->addAction(action1280_x_800);
        menuChange_Resolution->addAction(action1360_x_768);
        menuChange_Resolution->addAction(action1440_x_900);
        menuChange_Resolution->addAction(action1600_x_900);
        menuChange_Resolution->addAction(actionFullscreen);
        menuGasme->addAction(actionNew_Game);
        menuGasme->addAction(actionPause);
        menuGasme->addAction(actionCheat_Mode);

        retranslateUi(etsGame);

        QMetaObject::connectSlotsByName(etsGame);
    } // setupUi

    void retranslateUi(QMainWindow *etsGame)
    {
        etsGame->setWindowTitle(QApplication::translate("etsGame", "Best Game ever!!", 0, QApplication::UnicodeUTF8));
        actionChange_Level->setText(QApplication::translate("etsGame", "Change Level", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("etsGame", "Save", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("etsGame", "Load", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("etsGame", "New Game", 0, QApplication::UnicodeUTF8));
        action800_x_600->setText(QApplication::translate("etsGame", "800 x 600", 0, QApplication::UnicodeUTF8));
        action1024_x_768->setText(QApplication::translate("etsGame", "1024 x 768", 0, QApplication::UnicodeUTF8));
        action1152_x_824->setText(QApplication::translate("etsGame", "1152 x 864", 0, QApplication::UnicodeUTF8));
        action1280_x_700->setText(QApplication::translate("etsGame", "1280 x 600", 0, QApplication::UnicodeUTF8));
        action1280_x_720->setText(QApplication::translate("etsGame", "1280 x 720", 0, QApplication::UnicodeUTF8));
        action1280_x_768->setText(QApplication::translate("etsGame", "1280 x 768", 0, QApplication::UnicodeUTF8));
        action1280_x_800->setText(QApplication::translate("etsGame", "1280 x 800", 0, QApplication::UnicodeUTF8));
        action1360_x_768->setText(QApplication::translate("etsGame", "1360 x 768", 0, QApplication::UnicodeUTF8));
        action1440_x_900->setText(QApplication::translate("etsGame", "1440 x 900", 0, QApplication::UnicodeUTF8));
        action1600_x_900->setText(QApplication::translate("etsGame", "1600 x 900", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("etsGame", "Pause", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("etsGame", "Fullscreen", 0, QApplication::UnicodeUTF8));
        actionCheat_Mode->setText(QApplication::translate("etsGame", "Cheat Mode", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("etsGame", "Exit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("etsGame", "File", 0, QApplication::UnicodeUTF8));
        menuChange_Resolution->setTitle(QApplication::translate("etsGame", "Change Resolution", 0, QApplication::UnicodeUTF8));
        menuGasme->setTitle(QApplication::translate("etsGame", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class etsGame: public Ui_etsGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETSGAME_H
