/********************************************************************************
** Form generated from reading UI file 'etsgame.ui'
**
** Created: Mon Mar 14 12:23:48 2011
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
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_etsGame
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *etsGame)
    {
        if (etsGame->objectName().isEmpty())
            etsGame->setObjectName(QString::fromUtf8("etsGame"));
        etsGame->resize(400, 300);
        centralWidget = new QWidget(etsGame);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 70, 75, 23));
        etsGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(etsGame);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        etsGame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(etsGame);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        etsGame->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(etsGame);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        etsGame->setStatusBar(statusBar);

        retranslateUi(etsGame);

        QMetaObject::connectSlotsByName(etsGame);
    } // setupUi

    void retranslateUi(QMainWindow *etsGame)
    {
        etsGame->setWindowTitle(QApplication::translate("etsGame", "Best Game ever!!", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("etsGame", "a button", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class etsGame: public Ui_etsGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETSGAME_H
