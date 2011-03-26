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
void etsGame::onkeyPressEvent(QKeyEvent *event)
{

}
void etsGame::changeLevels()
{

}
void etsGame::changeResolution()
{

}
void etsGame::save()
{

}
void etsGame::load()
{

}
void etsGame::tick() // contains most of the game logic and collision
{

}
