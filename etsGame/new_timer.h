#ifndef NEW_TIMER_H
#define NEW_TIMER_H

#include <QTimer>
#include <QPushButton>
#include <QtGui>
#include <QMimeData>
#include <QDrag>

class Timer : public QTimer
{
    Q_OBJECT
    public:
        Timer(QObject*, int count);
        QWidget *object;

        QMenu *menu;
        int width;
        int x;
        int y;
        int direction;

    private slots:
        void inc();
        void accelerate();
        void decelerate();

        void on_object_clicked(QMouseEvent *);

    private:
        void createActions();
        QAction *speedUp;
        QAction *slowDown;
        QAction *haltAction;
        QAction *goAction;
};

#endif // NEW_TIMER_H
