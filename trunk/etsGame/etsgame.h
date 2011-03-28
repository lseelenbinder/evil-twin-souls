#ifndef ETSGAME_H
#define ETSGAME_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QPushButton>

namespace Ui {
    class etsGame;
}

class etsGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit etsGame(QWidget *parent = 0);
    ~etsGame();

private:
    Ui::etsGame *ui;
    QLabel *player;
    QPushButton *air;
    QLabel *scoreDisplay;
    QLabel *timeDisplay;
    QTime *time;
    void movePlayer(int);
    int score;
    int life;
    int level;
    int ticks;
    int direction;
    int myCount;

private slots:
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
    void on_actionChange_Level_triggered();
    void on_actionNew_Game_triggered();
    void keyPressEvent(QKeyEvent*);
    void tick(); // This is called every "tick" of the game.
    void changeResolution(int, int);
    void save();
    void load();
    void updateAir();

};

#endif // ETSGAME_H
