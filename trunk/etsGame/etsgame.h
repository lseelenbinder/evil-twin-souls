#ifndef ETSGAME_H
#define ETSGAME_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QPushButton>
#include <QSound>

namespace Ui {
    class etsGame;
}

class etsGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit etsGame(QWidget *parent = 0);
    QPixmap *fishImage, *bubbleImage;
    ~etsGame();

private:
    Ui::etsGame *ui;
    QLabel *player;
    QPixmap *playerImage;
    QPushButton *air;
    QPushButton *dimmer;
    QPushButton *newGameButton;
    QLabel *scoreDisplay, *pauseDisplay, *levelDisplay;
    QTimer *gameTimer;
    int score, life, level;
    int ticks;
    int direction, changeDirection; // direction and how it is changing (up or down) while the key is not released.
    int directionX, changeDirectionX;
    int myCount;
    bool isActive; // is a game loaded at the moment?
    bool isRunning; // is the game actually running?
    bool isFullscreen;
    int lastResX;
    int lastResY;
    double scX, scY; // scaling of images' sizes and positions
    //
    bool cheatMode;
    //
    void setScore(int);
    void updateScore();
    void setLife(int);
    void updateLevel();

private slots:
    void on_actionCheat_Mode_toggled(bool );
    void on_actionPause_triggered();
    void on_action1600_x_900_triggered();
    void on_action1440_x_900_triggered();
    void on_action1360_x_768_triggered();
    void on_action1280_x_800_triggered();
    void on_action1280_x_768_triggered();
    void on_action1280_x_720_triggered();
    void on_action1280_x_700_triggered();
    void on_action1152_x_824_triggered();
    void on_action1024_x_768_triggered();
    void on_action800_x_600_triggered();
    void on_actionFullscreen_triggered();
    void on_actionChange_Level_triggered();
    void on_actionNew_Game_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionExit_triggered();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent *);
    void tick(); // This is called every "tick" of the game.
    void changeResolution(int, int);
    void updateAir();

    void movePlayer(int, int);
    void changePlayerMovement(int&, int&);
    void movementAndCollision();

    void clearAll();
    void gameOver();
    void gameWon();
    void stopGame();
    void writeLog(QString);

};

#endif // ETSGAME_H
