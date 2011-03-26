/********************************************************************************
** Form generated from reading UI file 'etsgame.ui'
**
** Created: Sat Mar 26 19:02:48 2011
**      by: Qt User Interface Compiler version 4.7.2
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
    QAction *actionChange_Resolution;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *etsGame)
    {
        if (etsGame->objectName().isEmpty())
            etsGame->setObjectName(QString::fromUtf8("etsGame"));
        etsGame->resize(400, 300);
        actionChange_Level = new QAction(etsGame);
        actionChange_Level->setObjectName(QString::fromUtf8("actionChange_Level"));
        actionSave = new QAction(etsGame);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(etsGame);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionChange_Resolution = new QAction(etsGame);
        actionChange_Resolution->setObjectName(QString::fromUtf8("actionChange_Resolution"));
        centralWidget = new QWidget(etsGame);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        etsGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(etsGame);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        etsGame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(etsGame);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        etsGame->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(etsGame);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        etsGame->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionChange_Level);
        menuFile->addAction(actionChange_Resolution);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);

        retranslateUi(etsGame);

        QMetaObject::connectSlotsByName(etsGame);
    } // setupUi

    void retranslateUi(QMainWindow *etsGame)
    {
        etsGame->setWindowTitle(QApplication::translate("etsGame", "Best Game ever!!", 0, QApplication::UnicodeUTF8));
        actionChange_Level->setText(QApplication::translate("etsGame", "Change Level", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("etsGame", "Save", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("etsGame", "Load", 0, QApplication::UnicodeUTF8));
        actionChange_Resolution->setText(QApplication::translate("etsGame", "Change Resolution", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("etsGame", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class etsGame: public Ui_etsGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETSGAME_H
