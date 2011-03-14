#ifndef ETSGAME_H
#define ETSGAME_H

#include <QMainWindow>

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
};

#endif // ETSGAME_H
