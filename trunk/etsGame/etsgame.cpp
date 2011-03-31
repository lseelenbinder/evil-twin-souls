#include "etsgame.h"
#include "ui_etsgame.h"
#include "gameobject.h"
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QInputDialog>
#include <QKeyEvent>
#include <sstream>

using namespace std;

etsGame::etsGame(QWidget *parent) : // CONSTRUCTOR, QLabels, etc. are created (but kept hidden)
    QMainWindow(parent),
    ui(new Ui::etsGame),
    life(1000),
    level(1),
    changeDirection(0),
    isActive(false),
    isRunning(false),
    isFullscreen(false)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    // Create Pause-Label
    pauseDisplay = new QLabel(this);
    pauseDisplay->setFont(QFont("Tempus Sans ITC",25));
    pauseDisplay->hide();

    // Create Player!
    player = new QLabel(this);
    player->setObjectName("Player");
    QPixmap image("images\\sub.png");
    player->setPixmap(image);
    player->setGeometry(QRect(0,this->height()/2-image.height()/2,image.width(),image.height()));
    player->hide();

    // Create a game QTimer
    gameTimer = new QTimer(this);
    gameTimer->setObjectName("GameTimer");
    gameTimer->setInterval(10); // game's ticks...
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(tick()));

    // Create air meter
    air = new QPushButton(this);
    air->setObjectName("Air");
    updateAir();
    air->hide();

    // Create score counter
    scoreDisplay = new QLabel(this);
    scoreDisplay->setObjectName("ScoreDisplay");
    scoreDisplay->setText("Score:\n00000");
    scoreDisplay->hide();

    // IMPORTANT: sets also the objects positions!
    changeResolution(800,600);
}

etsGame::~etsGame()
{
    delete ui;
}

void etsGame::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()) {
        if (event->key() == Qt::Key_Up && life > 0) {
            direction = -1;
            changeDirection = -1;
            if (cheatMode==false)
            {
               life = life - 7;
            }
        } else if (event->key() == Qt::Key_Down) {
            changeDirection = 1;
            direction = 1;
            if (cheatMode==false)
            {
               life = life - 7;
            }
        } else if (event->key() == Qt::Key_Shift) {
            changeDirection = 0;
            direction = 0;
        }
    }
}
void etsGame::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        if (event->key() == Qt::Key_Up) {
            changeDirection = 1;
        } else if (event->key() == Qt::Key_Down) {
            changeDirection = -1;
        }
    }
}

void etsGame::movePlayer(int y) {
    if (player->y() + y < 20) y = 20 - player->y();
    player->setGeometry(player->x(),player->y() + y,player->width(),player->height());
    player->show();
    if (player->y() > this->height()-player->height()&&cheatMode==false) {
        gameOver();
    }
}

void etsGame::changeResolution(int w, int h) // changes window and background size and adjusts objects' positions
{
    this->setFixedSize(w,h);
    QPalette palette;
    QImage *img = new QImage("images/underWaterBackground.jpg");
    *img = img->scaled(w,h);
    palette.setBrush(this->backgroundRole(), QBrush(QImage(*img)));
    this->setPalette(palette);

    // set the positions of the objects
    pauseDisplay->setGeometry(this->width()/2-100,this->height()/2-pauseDisplay->height()/2,200,pauseDisplay->height());
    scoreDisplay->setGeometry(this->width()-50,280,40,30);
    air->setGeometry(this->width()-50,50,30,200);

    player->setGeometry(QRect(0,this->height()/2-player->height()/2,player->width(),player->height())); // careful!!! what if out of bounds?
}

void etsGame::clearAll() { // clears all the objects
    QList<gameObject*> objs = this->findChildren<gameObject*>();
    for (int i = 0; i < objs.length(); ++i) {
        gameObject *obj = dynamic_cast<gameObject*>(objs[i]);
        obj->label->deleteLater();
        obj->deleteLater();
    }
    if (isActive) {
        player->hide();
        scoreDisplay->hide();
        air->hide();
        gameTimer->stop();
    }
    pauseDisplay->hide();
    ui->actionPause->setText("Pause");
    isActive = false;
    isRunning = false;
}

void etsGame::save()
{
    
}
void etsGame::load()
{
    clearAll();
    
    // Code Loading here...
    
    changeResolution(this->width(), this->height()); // sets the interface objects' positions
}

void etsGame::gameOver() {
    isRunning = false;
    isActive = false;
    ticks = 0;
    pauseDisplay->setText("GAME OVER");
    pauseDisplay->show();
    QSound::play("audio/sadTrombone.wav");
    // ...
}

void etsGame::tick() // contains most of the game logic and collision
{
    ++ticks;
    if (isRunning) {
        if (ticks % (25-level) == 0&&cheatMode==false) { // decrease life!
            --life;
        }
        if (ticks % 8 == 0) { // change PlayerMovement direction
            if (direction > 0 && changeDirection < 0) {
                direction += changeDirection;
                if (direction <= 0) {
                    direction = 0;
                    changeDirection = 0;
                }
            } else if (direction < 0 && changeDirection > 0) {
                direction += changeDirection;
                if (direction >= 0) {
                    direction = 0;
                    changeDirection = 0;
                }
            } else {
                direction += changeDirection;
                if (direction < -12) direction = -12;
                if (direction > 12) direction = 12;
            }
        }
        if (ticks % 5 == 0) {
            movePlayer(direction); // move player!
            QList<gameObject*> objs = this->findChildren<gameObject*>();
            for (int i = 0; i < objs.length(); ++i) {
                gameObject *obj = dynamic_cast<gameObject*>(objs[i]);
                QLabel *l = obj->label;
                l->setGeometry(l->x() + obj->getDirection(), l->y(), l->width(), l->height()); // move objects!
                if (abs(l->x() - player->x()) <= l->width()/2 + player->width()/2
                    && abs(l->y() - player->y()) <= l->height()/2 + player->height()/2) { // collision!
                    l->deleteLater();
                    obj->deleteLater();
                    if (obj->getType() == FISH&&cheatMode==false) { // collision with fish!
                        life = life - 150 - level*50;
                        QSound::play("audio/chomp.wav");
                    } else if (obj->getType() == BUBBLE) { // collision with bubble!
                        life += 100;
                        score += 15;
                        QSound::play("audio/pop.wav");
                    }
                }
                if (l->x() < -l->width()) { // fish/bubble out of view
                    if (obj->getType() == FISH) {
                        score += 15;
                    }
                    l->deleteLater();
                    obj->deleteLater();
                }
            }
        }
        if (rand() % (440-level*80) == 0) { // create new fish!
            gameObject *fish = new gameObject(this, myCount++);
            fish->setType(FISH);
            fish->setDirection(rand() % 4 - 4 - level);
            QPixmap image("images\\shark.png");
            fish->setSprite(image);
            int objX = this->width();
            int objY = rand() % (this->height()-15) + 15;
            fish->label->setGeometry(objX, objY, image.width(),image.height());
            fish->label->show();
        }
        if (rand() % (350+level*50) == 0) { // create new bubble!
            gameObject *bubble = new gameObject(this, myCount++);
            bubble->setType(BUBBLE);
            bubble->setDirection(rand() % 4 - 4 - level);
            QPixmap image("images\\bubble.png");
            bubble->setSprite(image);
            int objX = this->width();
            int objY = rand() % (this->height()-15) + 15;
            bubble->label->setGeometry(objX, objY, image.width(),image.height());
            bubble->label->show();
        }

        if (ticks % 100 == 0) score += 10; // increase score every second
        QString scoreText = QString::number(score); // update score
        while (scoreText.length() < 5)
            scoreText = '0' + scoreText;
        scoreDisplay->setText("Score:\n" + scoreText);

        updateAir(); // update air level!
    } else {
        if (ticks % 80 == 0) { // make the "PAUSE" label blink
            if (pauseDisplay->isHidden()) {
                pauseDisplay->show();
            } else {
                pauseDisplay->hide();
            }
        }
    }
}

void etsGame::on_actionNew_Game_triggered() // Starts a completely new game
{
    // First clear all the previous stuff...
    isRunning = true;
    clearAll();

    // (Re)set all the variables
    life = 1000;
    ticks = 0;
    direction = 0;
    myCount = 0;
    score = 0;
    changeDirection = 0;

    // shows all the game interface objects
    player->setGeometry(QRect(0,this->height()/2-player->height()/2,player->width(),player->height()));
    player->show();

    air->show();

    scoreDisplay->setText("Score:\n00000");
    scoreDisplay->show();

    gameTimer->start();

    pauseDisplay->setText("     PAUSE");

    isRunning = true;
    isActive = true;
}

void etsGame::updateAir() {
    if (life > 1000) life = 1000;
    if (life < 50) life = 50; // gameOver
    stringstream ss;
    ss << "border-radius: 10px; border: ";
    ss << "0px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: " << (double)(100-life/10)/100 << " rgba(" << (220 - life/10) << ", " << (life/10) << ", " << (10 + life/10) << ", 150), stop: " << (double)(100-life/10)/100 + 0.05 << " rgba(50,160,180,140), stop: 1 rgba(20,120,140,160)); ";
    air->setStyleSheet(QString::fromStdString(ss.str()));
    if (life == 50) gameOver();
}

void etsGame::on_actionChange_Level_triggered()
{
    // HARDER LEVELS mean:
        // life decreases faster
        // more fish
        // less bubbles
        // faster fish and bubbles
        // deadlier fish
    level = QInputDialog::getInteger(this, tr("Integer"), tr("Enter the level (between 1 and 5):"), level, 1, 5, 1);
}

void etsGame::on_actionPause_triggered()
{
    if (isActive) {
        if (ui->actionPause->text() == "Pause") {
            ticks = 0;
            isRunning = false;
            ui->actionPause->setText("Restart");
            pauseDisplay->show();
        } else {
            isRunning = true;
            ui->actionPause->setText("Pause");
            pauseDisplay->hide();
        }
    }
}

void etsGame::on_action800_x_600_triggered()
{
    changeResolution(800,600);
}

void etsGame::on_action1024_x_768_triggered()
{
    changeResolution(1024,768);
}

void etsGame::on_action1152_x_824_triggered()
{
    changeResolution(1152,864);
}

void etsGame::on_action1280_x_700_triggered()
{
    changeResolution(1280,600);
}

void etsGame::on_action1280_x_720_triggered()
{
    changeResolution(1280,720);
}

void etsGame::on_action1280_x_768_triggered()
{
    changeResolution(1280,768);
}

void etsGame::on_action1280_x_800_triggered()
{
    changeResolution(1280,800);
}

void etsGame::on_action1360_x_768_triggered()
{
    changeResolution(1360,768);
}

void etsGame::on_action1440_x_900_triggered()
{
    changeResolution(1440,900);
}

void etsGame::on_action1600_x_900_triggered()
{
    changeResolution(1600,900);
}
void etsGame::on_actionFullscreen_triggered()
{
    if (isFullScreen())
    {
        ui->actionFullscreen->setText("Fullscreen");
        showNormal();
        changeResolution(lastResX, lastResY);
    } else {
        lastResX = this->width();
        lastResY = this->height();
        showFullScreen();
        changeResolution(this->width(), this->height());
        ui->actionFullscreen->setText("Windowed");
    }
}

void etsGame::on_actionCheat_Mode_toggled(bool onOff)
{
    cheatMode=onOff;
}
