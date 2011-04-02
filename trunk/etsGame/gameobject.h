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
    gameObject(QObject *parent, int myCount, gameObjectType, QWidget*, int, int, int);
    int getDirection();
    void setDirection(int);
    void setType(gameObjectType);
    gameObjectType getType();
    QLabel* label;
    void setSprite();

private:
    gameObjectType type;
    int direction;

signals:

};

#endif // GAMEOBJECT_H
