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

private slots:
    void onkeyPressEvent(QKeyEvent*);

};

#endif // ETSGAME_H
