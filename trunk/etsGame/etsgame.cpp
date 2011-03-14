#include "etsgame.h"
#include "ui_etsgame.h"

etsGame::etsGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::etsGame)
{
    ui->setupUi(this);
}

etsGame::~etsGame()
{
    delete ui;
}
