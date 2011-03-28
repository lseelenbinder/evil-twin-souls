#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QLabel>
#include <QObject>
#include <QTimer>
#include <QPixmap>

enum gameObjectType {FISH, BUBBLE, BULLET};

class gameObject : public QObject
{
    Q_OBJECT

public:
    explicit gameObject(QObject *parent = 0, int myCount = 0);
    void setSprite(QPixmap p);
    int getDirection();
    void setDirection(int);
    void setType(gameObjectType);
    gameObjectType getType();
    QLabel* label;

private:
    QPixmap sprite;
    gameObjectType type;
    QTimer* t;
    int direction;

signals:

};

#endif // GAMEOBJECT_H
