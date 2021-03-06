#include "etsgame.h"
#include "ui_etsgame.h"
#include "gameobject.h"
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QInputDialog>
#include <QKeyEvent>
#include <sstream>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>

using namespace std;

etsGame::etsGame(QWidget *parent) : // CONSTRUCTOR, QLabels, etc. are created (but kept hidden)
    QMainWindow(parent),
    ui(new Ui::etsGame),
    life(1000),
    level(1),
    changeDirection(0),
    changeDirectionX(0),
    isFullscreen(false),
    scX(0.8),
    scY(0.6)
{
    writeLog("Application Started");
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    // Assign Fish/Bubble pixmaps
    fishImage = new QPixmap(":/images/shark.png");
    bubbleImage = new QPixmap(":/images/bubble.png");
    sharkImage = new QPixmap(":/images/bigShark.png");

    // Create Pause-Label
    pauseDisplay = new QLabel(this);
    pauseDisplay->setFont(QFont("Tempus Sans ITC",25));
    pauseDisplay->hide();

    // Create Player!
    player = new QLabel(this);
    player->setObjectName("Player");
    playerImage = new QPixmap(":/images/sub.png");
    player->setPixmap(*playerImage);
    player->setGeometry(5,this->height()/2-playerImage->height()/2,playerImage->width(),playerImage->height());
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

    // Create dimmer
    dimmer = new QPushButton(this);
    dimmer->setObjectName("Dimmer");
    dimmer->setStyleSheet("border:0px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(0,30,100,150), stop: 1 rgba(0,10,40,130));");

    // Create New Game PushButton
    newGameButton = new QPushButton(this);
    newGameButton->setStyleSheet("border-radius:10px; border:0px; background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(20, 130, 200, 150), stop:0.5 rgba(10, 90, 170, 100), stop:1 rgba(0,0,0,0))");
    newGameButton->setText("New Game");
    newGameButton->setFont(QFont("Tempus Sans ITC",20));
    newGameButton->setCursor(Qt::PointingHandCursor);
    connect(newGameButton,SIGNAL(clicked()),this,SLOT(on_actionNew_Game_triggered()));

    // Create score counter
    scoreDisplay = new QLabel(this);
    scoreDisplay->setObjectName("ScoreDisplay");
    setScore(0);
    scoreDisplay->setFont(QFont("Tempus Sans ITC",8, QFont::Bold));
    scoreDisplay->setForegroundRole(QPalette::BrightText);
    scoreDisplay->hide();

    // Create level display
    levelDisplay = new QLabel(this);
    levelDisplay->setObjectName("LevelDisplay");
    updateLevel();
    levelDisplay->setFont(QFont("Tempus Sans ITC",8, QFont::Bold));
    levelDisplay->setForegroundRole(QPalette::BrightText);
    levelDisplay->hide();

    // IMPORTANT: sets also the objects positions!
    changeResolution(800,600);

    stopGame(); // prepares "welcome" screen
}

etsGame::~etsGame()
{
    delete ui;
}

void etsGame::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()) {
        if ((event->key() == Qt::Key_Up || event->key() == Qt::Key_W) && life > 50) {
            direction = -1;
            changeDirection = -1;
        } else if ((event->key() == Qt::Key_Down || event->key() == Qt::Key_S)) {
            changeDirection = 1;
            direction = 1;
        } else if ((event->key() == Qt::Key_Right || event->key() == Qt::Key_D)) {
            directionX = 1;
            changeDirectionX = 1;
        } else if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_A)) {
            directionX = -1;
            changeDirectionX = -1;
        } else if (event->key() == Qt::Key_P) {
            ui->actionPause->setChecked(!ui->actionPause->isChecked());
            on_actionPause_triggered();
        } else if (event->key() == Qt::Key_N) {
            on_actionNew_Game_triggered();
        } else if (event->key() == Qt::Key_F11) {
            ui->actionFullscreen->setChecked(!ui->actionFullscreen->isChecked());
            on_actionFullscreen_triggered();
        }
    }
}
void etsGame::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        if ((event->key() == Qt::Key_Up || event->key() == Qt::Key_W) && life > 100) {
            changeDirection = 1;
        } else if ((event->key() == Qt::Key_Down || event->key() == Qt::Key_S)) {
            changeDirection = -1;
        } else if ((event->key() == Qt::Key_Right || event->key() == Qt::Key_D)) {
            changeDirectionX = -1;
        } else if ((event->key() == Qt::Key_Left || event->key() == Qt::Key_A)) {
            changeDirectionX = 1;
        }
    }
}

void etsGame::movePlayer(int y, int x) {
    if (player->y() + y < 20) y = 20 - player->y();
    if (player->y() > this->height()) y = this->height() - player->y();
    if (player->x() + x < 5) x = 5 - player->x();
    if (player->x() + x > this->width()) x = this->width() - player->x();
    player->move(player->x() + x,player->y() + y);
    player->show();
    if (player->y() > this->height() - player->height() && !cheatMode) {
        gameOver();
    }
}

void etsGame::changeResolution(int w, int h) // changes window and background size and adjusts objects' positions
{
    double formerScX = scX;
    double formerScY = scY;
    scX = (double)w/1000;
    scY = (double)h/1000;
    this->setFixedSize(w,h);
    QPalette palette;
    QImage img(":/images/underWaterBackground.jpg");
    img = img.scaled(w,h);
    palette.setBrush(this->backgroundRole(), QBrush(img));
    this->setPalette(palette);

    delete playerImage; // resize player
    playerImage = new QPixmap(":/images/sub.png");
    *playerImage = playerImage->scaled(playerImage->width()/0.8*scX,playerImage->height()/0.6*scY);
    player->setPixmap(*playerImage);
    player->setGeometry((double)player->x()/formerScX*scX,(double)player->y()/formerScY*scY,playerImage->width(),playerImage->height());

    // set the positions of the objects
    player->stackUnder(pauseDisplay);
    pauseDisplay->setGeometry(w/2-100,h/2-pauseDisplay->height()/2,200,pauseDisplay->height());
    air->setGeometry(w-60,50,40,250);
    newGameButton->setGeometry(w/2-125,h/2+pauseDisplay->height()+50,250,100);
    dimmer->setGeometry(0,21,w,h);
    dimmer->stackUnder(pauseDisplay);
    scoreDisplay->setGeometry(w-60,340,50,30);
    levelDisplay->setGeometry(w-60,390,50,30);

    delete fishImage; // resize fish
    fishImage = new QPixmap(":/images/shark.png");
    *fishImage = fishImage->scaled(fishImage->width()/0.8*scX,fishImage->height()/0.6*scY);

    delete sharkImage; // resize shark
    sharkImage = new QPixmap(":/images/bigShark.png");
    *sharkImage = sharkImage->scaled(sharkImage->width()/0.8*scX,sharkImage->height()/0.6*scY);

    delete bubbleImage; // resize bubble
    bubbleImage = new QPixmap(":/images/bubble.png");
    *bubbleImage = bubbleImage->scaled(bubbleImage->width()/0.8*scX,bubbleImage->height()/0.6*scY);

    QList<gameObject*> objs = this->findChildren<gameObject*>();
    for (int i = 0; i < objs.length(); ++i) {
        gameObject *obj = dynamic_cast<gameObject*>(objs[i]);
        obj->setSprite();
        obj->label->move(obj->label->x()/formerScX*scX,obj->label->y()/formerScY*scY);
    }

    writeLog("Resolution changed to " + QString::number(w) + " x " + QString::number(h));
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
        levelDisplay->hide();
        air->hide();
        newGameButton->hide();
        gameTimer->stop();
    }
    pauseDisplay->hide();
    isActive = false;
    isRunning = false;
}

void etsGame::on_actionSave_triggered()
{
    ui->actionPause->setChecked(true);
    on_actionPause_triggered();
    QList<gameObject*> kids = this->findChildren<gameObject*>();
    QString filename = QFileDialog::getSaveFileName(this, "Save Form", "", "");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_6); // Change this based on current Qt version
    out << score << life << level;
    out << ticks;
    out << direction << changeDirection << directionX << changeDirectionX;
    out << isFullScreen();
    out << cheatMode;
    out << player->x() << player->y();

    out << kids.length();
    for (int i = 0; i < kids.length(); ++i)
    {
        gameObject *go = dynamic_cast<gameObject*>(kids[i]);
        out << go->getType();
        out << go->getDirection();
        out << go->label->pos();
    }

    file.close();

    writeLog("Game Saved: " + filename);
}
void etsGame::on_actionLoad_triggered()
{
    
    QString filename = QFileDialog::getOpenFileName(this, "Load Form", "", "");
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_6); // Change this based on current Qt version

    on_actionNew_Game_triggered();
    ui->actionPause->setChecked(true);
    on_actionPause_triggered();

    bool full, cheat;

    in >> score >> life >> level;
    in >> ticks;
    in >> direction >> changeDirection >> directionX >> changeDirectionX;
    in >> full;
    in >> cheat;
    int x, y;
    in >> x >> y;

    int len;
    in >> len;
    for (int k = 0; k < len; k++)
    {
        int t, dir;
        gameObjectType type;
        in >> t >> dir;
        type = (gameObjectType)t;
        QPoint pos;
        in >> pos;
        gameObject *go = new gameObject(this, myCount++, type, dimmer, dir, scX, scY);
        go->label->setGeometry(pos.x(), pos.y(), go->label->width(), go->label->height());
    }
    updateScore();
    updateAir();
    updateLevel();
    on_actionPause_triggered();
    tick();
    ui->actionPause->setChecked(true);
    on_actionPause_triggered();
    
    changeResolution(this->width(), this->height()); // sets the interface objects' positions
    player->setGeometry(x, y, player->width(), player->height());
    if (full) {
        ui->actionFullscreen->setChecked(true);
        on_actionFullscreen_triggered();
    }
    writeLog("Game Loaded: " + filename);

    file.close();
}

void etsGame::gameOver() {
    stopGame();
    pauseDisplay->setText("GAME OVER");
    pauseDisplay->show();
    QSound::play(":/audio/sadTrombone.wav");
    writeLog("Game Over");
}

void etsGame::gameWon() {
    stopGame();
    pauseDisplay->setText("YOU WON!");
    pauseDisplay->show();
    QSound::play(":/audio/victory.wav");
    writeLog("Game Won");
}

void etsGame::stopGame() {
    isRunning = false;
    isActive = false;
    ticks = 0;
    dimmer->show();
    newGameButton->show();
}

void etsGame::changePlayerMovement(int &dir, int &changeDir) {
    if (dir > 0 && changeDir < 0) {
        dir += changeDir;
        if (dir <= 0) {
            dir = 0;
            changeDir = 0;
        }
    } else if (dir < 0 && changeDir > 0) {
        dir += changeDir;
        if (dir >= 0) {
            dir = 0;
            changeDir = 0;
        }
    } else {
        dir += changeDir;
        if (dir < -12*scX) dir = -12*scX;
        else if (dir > 12*scX) dir = 12*scX;
        else if (!cheatMode && changeDir != 0) --life;
    }
}

void etsGame::tick() // contains most of the game logic and collision; is called every 10 milliseconds
{
    ++ticks; // increase number of ticks
    if (isRunning) { // if the game is actually running
        if (ticks % (25-level*2) == 0 && !cheatMode) { // decrease life!
            --life;
        }
        if (ticks % 8 == 0) { // change the direction the player is moving every 8 ticks if necessary
            changePlayerMovement(direction, changeDirection); // controls up and down movement
            changePlayerMovement(directionX, changeDirectionX); // controls left and right movement
        }
        if (ticks % 5 == 0) {
            movementAndCollision(); // player/bubble/fish movement and collision updating
        }
        if (rand() % (440-level*80) == 0) { // create new fish! The higher the level, the more.
            int dir = rand() % 4*scX - 4*scX - level; // random direction; speed depends on level
            new gameObject(this, myCount++, FISH,
                dimmer, dir, scX, scY); // calls the gameObject constructor for a fish
        }
        if (rand() % (350+level*50) == 0) { // create new bubble! The higher the level, the less.
            int dir = rand() % 4*scX - 4*scX - level; // random direction; speed depends on level
            new gameObject(this, myCount++, BUBBLE,
                dimmer, dir, scX, scY); // calls the gameObject constructor for a bubble
        }
        if (rand() % (2000-level*100) == 0) { // create deadly shark!
            int dir = rand() % 4*scX - 4*scX - level; // random direction; speed depends on level
            new gameObject(this,myCount++,SHARK,
                dimmer, dir, scX, scY); // calls the gameObject constructor for a deadly shark
        }

        if (ticks % 100 == 0) score += 10; // increase score every second

        updateScore(); // updates the score display
        updateAir(); // update air level!
    } else { // if the game is not running: 
        if (ticks % 80 == 0) { // make the "PAUSE" label blink every 80 ticks
            if (pauseDisplay->isHidden()) {
                pauseDisplay->show();
            } else {
                pauseDisplay->hide();
            }
        }
    }
}

void etsGame::movementAndCollision() { // player, bubble, and fish movement and collision updating
    movePlayer(direction, directionX); // move player!
    QList<gameObject*> objs = this->findChildren<gameObject*>(); // get all the children of the form of type <gameObject*>
    for (int i = 0; i < objs.length(); ++i) { // loop through all the gameObjects
        gameObject *obj = dynamic_cast<gameObject*>(objs[i]);
        QLabel *l = obj->label; // the objects label (just an abbreviation)
        l->setGeometry(l->x() + obj->getDirection(), l->y(), l->width(), l->height()); // move objects!
        if (((player->x() >= l->x() && abs(l->x()-player->x()) <= l->width()-3) ||
             (player->x() <= l->x() && abs(l->x()-player->x()) <= player->width()-3)) &&
            ((player->y() >= l->y() && abs(l->y()-player->y()) <= l->height()-3) ||
             (player->y() <= l->y() && abs(l->y()-player->y()) <= player->height()-3))) { // collision condition between the player and the current gameObject!
            l->deleteLater(); // delete the gameObject label
            obj->deleteLater(); // delete the gameObject object
            if (obj->getType() == FISH && !cheatMode) { // collision is with a fish!
                life = life - 150 - level*50; // decrease life (depending on level)
                QSound::play(":/audio/chomp.wav");
            } else if (obj->getType() == SHARK && !cheatMode) { // collision is with a shark!
                    life = 50; // kills you!
                    QSound::play(":/audio/chomp.wav");
            } else if (obj->getType() == BUBBLE) { // collision is with a bubble!
                life += 100; // increase life (air level)
                score += 15; // add to score
                QSound::play(":/audio/pop.wav");
            }
        }
        if (l->x() < -l->width()) { // fish/bubble out of view
            if (obj->getType() == FISH) {
                score += 15; // add 15 to score for every fish that escapes the screen on the left side
            } else if (obj->getType() == SHARK) {
                score +=50;
            }
            // delete the gameObject
            l->deleteLater();
            obj->deleteLater();
        }
    }
}

void etsGame::on_actionNew_Game_triggered() // Starts a completely new game
{
    // First clear all the previous stuff...
    isRunning = true;
    clearAll();
    ui->actionPause->setChecked(false);

    // (Re)set all the variables
    life = 1000;
    ticks = 0;
    myCount = 0;
    score = 0;
    direction = 0;
    directionX = 0;
    changeDirection = 0;
    changeDirectionX = 0;

    // shows all the game interface objects
    dimmer->hide();
    newGameButton->hide();

    player->setGeometry(5,this->height()/2-player->height()/2,player->width(),player->height());
    player->show();

    air->show();

    setScore(0);
    scoreDisplay->show();

    updateLevel();
    levelDisplay->show();

    gameTimer->start();

    pauseDisplay->setText("     PAUSE");

    isRunning = true;
    isActive = true;

    writeLog("New Game Created");
}

void etsGame::updateAir() {
    if (life > 1000) life = 1000;
    if (life < 50) life = 50; // gameOver
    stringstream ss;
    ss << "border-radius: 20px; border:  3px solid white;";
    ss << "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: " << (double)(100-life/10)/100 << " rgba(" << (220 - life/10) << ", " << (life/10) << ", " << (10 + life/10) << ", 150), stop: " << (double)(100-life/10)/100 + 0.05 << " rgba(30,130,150,140), stop: 1 rgba(10,100,120,160)); ";
    air->setStyleSheet(QString::fromStdString(ss.str()));
    if (life == 50) gameOver();
}

void etsGame::writeLog(QString text) {
    QDateTime dt = QDateTime::currentDateTime();

    if(!QFile("log.txt").exists())
    {
      QFile("log.txt");
    }

    QFile file("log.txt");
    file.open(QIODevice::Append);
    QTextStream out(&file);
    out << dt.date().toString("MM/dd/yyyy") << ", " << dt.time().toString("hh:mm:ss") << ": " << text << '\n';
    file.close();
}

void etsGame::on_actionChange_Level_triggered()
{
    // HARDER LEVELS mean:
        // life decreases faster
        // more fish
        // less bubbles
        // faster fish and bubbles
        // deadlier fish
    ui->actionPause->setChecked(true);
    on_actionPause_triggered();
    level = QInputDialog::getInteger(this, tr("Integer"), tr("Enter the level (between 1 and 5):"), level, 1, 5, 1);
    ui->actionPause->setChecked(false);
    on_actionPause_triggered();
    updateLevel();
}

void etsGame::on_actionPause_triggered()
{
    if (isActive) {
        if (ui->actionPause->isChecked()) {
            ticks = 0;
            isRunning = false;
            pauseDisplay->show();
        } else {
            isRunning = true;
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
    if (!ui->actionFullscreen->isChecked())
    {
        showNormal();
        changeResolution(lastResX, lastResY);
    } else {
        lastResX = this->width();
        lastResY = this->height();
        showFullScreen();
        changeResolution(this->width(), this->height());
    }
}

void etsGame::on_actionCheat_Mode_toggled(bool onOff)
{
    cheatMode=onOff;
    if (cheatMode) life = 1000;
}
void etsGame::setScore(int n) { score = n; updateScore();}
void etsGame::updateScore()
{
    QString scoreText = QString::number(score); // update score
    while (scoreText.length() < 5)
        scoreText = '0' + scoreText;
    scoreDisplay->setText("Score:\n" + scoreText);
    if (score>=5000) {
        gameWon();
    }
}
void etsGame::setLife(int n) { life = n; updateAir(); }
void etsGame::updateLevel() { levelDisplay->setText("Level " + QString::number(level)); }
void etsGame::on_actionExit_triggered() { QApplication::exit(0); }

void etsGame::on_actionHelp_triggered()
{
    QLabel *help = new QLabel();
    QPixmap *bgImage = new QPixmap(":/images/ibg.png");
    help->setPixmap(*bgImage);
    help->setFixedSize(bgImage->width(),bgImage->height());
    help->show();
}
void etsGame::focusOutEvent(QFocusEvent *)
{
    ui->actionPause->setChecked(true);
    on_actionPause_triggered();
}
