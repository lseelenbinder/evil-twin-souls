#ifndef ETSGAME_H
#define ETSGAME_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>

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
    QLabel player;
    QPixmap playerSprite;
    void movePlayer(int);
    int score;
    int life;

private slots:
    void onkeyPressEvent(QKeyEvent*);
    void tick(); // This is called every "tick" of the game.
    void changeLevels();
    void changeResolution();
    void save();
    void load();

};

#endif // ETSGAME_H
